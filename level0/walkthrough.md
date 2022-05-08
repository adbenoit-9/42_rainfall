# Level 0
*password : level0*

```
$ ssh level0@192.168.56.108 -p 4242
$ ls
level0
```

## Analyze
```
$ scp -P 4242 level0@192.168.56.108:level0 binary/
```

```
undefined4 main(undefined4 param_1,int param_2)

{
  ...
  iVar1 = atoi(*(undefined4 *)(param_2 + 4));
  if (iVar1 == 0x1a7) {
    ...
    execv("/bin/sh",&local_20);
  }
  ...
}
```
0x1a7 = 423

## Exploit
```
$ level0 423
$ whoami
level1
$ cat /home/user/level1/.pass
1fe8a524fa4bec01ca4ea2a869af2a02260d4a7d5fe7e7c24d8617e6dca12d3a
```
