void m(void)
{
  puts(&DAT_080485d1);
  return;
}

void n(void)
{
  system("/bin/cat /home/user/level7/.pass");
  return;
}

int main(int ac,char **av)
{
  undefined4 uVar1;
  code **ppcVar2;
  
  uVar1 = malloc(0x40);
  ppcVar2 = (code **)malloc(4);
  *ppcVar2 = m;
  strcpy(uVar1, av[1]);
  (**ppcVar2)();
  return;
}
