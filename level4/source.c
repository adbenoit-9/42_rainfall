void p(undefined4 param_1)
{
  printf(param_1);
  return;
}

void n(void)
{
  undefined local_20c [520];
  
  fgets(local_20c,0x200,stdin);
  p(local_20c);
  if (m == 0x1025544) {
    system("/bin/cat /home/user/level5/.pass");
  }
  return;
}

int main(void)
{
  n();
  return;
}
