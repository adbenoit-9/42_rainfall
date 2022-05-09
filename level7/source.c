void m(void)
{
  undefined4 uVar1;
  
  uVar1 = time(0);
  printf("%s - %d\n",c,uVar1);
  return;
}

int main(int ac,char **av)
{
  char *puVar1;
  undefined4 uVar2;
  char *puVar3;
  
  puVar1 = (char *)malloc(8);
  *puVar1 = 1;
  uVar2 = malloc(8);
  puVar1[1] = uVar2;
  puVar3 = (char *)malloc(8);
  *puVar3 = 2;
  uVar2 = malloc(8);
  puVar3[1] = uVar2;
  strcpy(puVar1[1], av[1]);
  strcpy(puVar3[1], av[2]);
  uVar2 = fopen("/home/user/level8/.pass",&DAT_080486e9);
  fgets(c,0x44,uVar2);
  puts(&DAT_08048703);
  
  return 0;
}
