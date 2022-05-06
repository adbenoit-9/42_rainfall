void m(void)
{
  undefined4 uVar1;
  
  uVar1 = time(0);
  printf("%s - %d\n",c,uVar1);
  return;
}

undefined4 main(undefined4 param_1,int param_2)
{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  puVar1 = (undefined4 *)malloc(8);
  *puVar1 = 1;
  uVar2 = malloc(8);
  puVar1[1] = uVar2;
  puVar3 = (undefined4 *)malloc(8);
  *puVar3 = 2;
  uVar2 = malloc(8);
  puVar3[1] = uVar2;
  strcpy(puVar1[1],*(undefined4 *)(param_2 + 4));
  strcpy(puVar3[1],*(undefined4 *)(param_2 + 8));
  uVar2 = fopen("/home/user/level8/.pass",&DAT_080486e9);
  fgets(c,0x44,uVar2);
  puts(&DAT_08048703);
  return 0;
}
