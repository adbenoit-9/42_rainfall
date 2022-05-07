void main(int ac, char **av)
{
  int ret;
  char *dest[40];
  int nb;
  
  nb = atoi(*(undefined4 *)(**av + 4));
  if (nb < 10) {
    memcpy(dest,*(undefined4 *)(**av + 8),nb * 4);
    if (nb == 0x574f4c46) {
      execl("/bin/sh",&DAT_08048580,0);
    }
    ret = 0;
  }
  else {
    ret = 1;
  }
  return ret;
}
