# Bonus 3
*password : 71d449df0f960b36e0055eb58c14d0f5d0ddc0b35328d657f91cf0df15910587*

## Analyze
```
$ scp -P 4242 bonus3@192.168.56.108:bonus3 binary/
```
- only one argument (=> else l.24)
- buffer must be equal to av[1]
```
i = atoi(av[1]);
*(buffer + i) = 0;
```
so i = 0 and buffer = ""

```
$ ./bonus3 ""
$ cat /home/user/end/.pass
3321b6f81659f9a71c76616f606e4b50189cecfea611393d5d649f75e157353c
```
