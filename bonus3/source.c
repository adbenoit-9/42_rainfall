int main(int ac,char **av)
{
  undefined4 uVar1;
  int i;
  undefined4 *tmp;
  byte bVar4;
  undefined4 buffer[16];
  undefined local_57;
  undefined buffer2[66];
  int fd;
  
  bVar4 = 0;
  fd = fopen("/home/user/end/.pass",&DAT_080486f0);
  i = 33;
  tmp = buffer;
  while (i != 0) {
    --i;
    *tmp = 0;
    tmp = tmp + (uint)bVar4 * -2 + 1; // ++tmp
  }
  if ((fd == 0) || (ac != 2)) {
    uVar1 = 0xffffffff;
  }
  else {
    fread(buffer, 1, 66 ,fd);
    local_57 = 0;
    i = atoi(av[1]);
    *(buffer + i) = 0;
    fread(buffer2, 1, 65, fd);
    fclose(fd);
    i = strcmp(buffer, av[1]);
    if (i == 0) {
      execl("/bin/sh", &DAT_08048707, 0);
    }
    else {
      puts(buffer2);
    }
    uVar1 = 0;
  }
  return uVar1;
}
