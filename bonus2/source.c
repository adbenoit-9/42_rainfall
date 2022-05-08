
void greetuser(void)
{
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined2 local_3c;
  undefined local_3a;
  
  if (language == 1) {
    local_4c = 0xc3767948;
    local_48 = 0x20a4c3a4;
    local_44 = 0x69a4c370;
    local_40 = 0xc3a4c376;
    local_3c = 0x20a4;
    local_3a = 0;
  }
  else {
    if (language == 2) {
      local_4c = 0x64656f47;
      local_48 = 0x64696d65;
      local_44 = 0x21676164;
      local_40 = CONCAT22(local_40._2_2_,0x20);
    }
    else {
      if (language == 0) {
        local_4c = 0x6c6c6548; // Hello ?
        local_48 = CONCAT13(local_48._3_1_,0x206f);
      }
    }
  }
  strcat(&local_4c,&stack0x00000004);
  puts(&local_4c);
  return;
}

int main(int ac,int av)
{
  undefined4 ret;
  int i;
  char *tmp;
  undefined4 **env;
  byte bool1;
  undefined4 *local_b0;
  char *local_ac;
  undefined4 local_a8;
  char local_60[10];
  char auStack56[9];
  char *env0;
  
  bool1 = 0;
  if (ac == 3) {
    i = 19;
    tmp = local_60;
    while (i != 0) { // bzero local_60 & austack56
      --i;
      *tmp = 0;
      ++tmp;
    }
    local_ac = av[1];
    local_a8 = 32;
    local_b0 = local_60;
    strncpy();
    local_ac = av[2];
    local_a8 = 32;
    local_b0 = auStack56;
    strncpy();
    local_b0 = (undefined4 *)&DAT_08048738;
    env0 = *getenv();
    if (env0) {
      local_a8 = 2;
      local_ac = &DAT_0804873d;
      local_b0 = env0;
      i = memcmp();
      if (i == 0) {
        language = 1;
      }
      else {
        local_a8 = 2;
        local_ac = &DAT_08048740;
        local_b0 = env0;
        i = memcmp();
        if (i == 0) {
          language = 2;
        }
      }
    }
    i = 19;
    tmp = local_60;
    env = &local_b0;
    while (i != 0) { // del the environ ?
      --i;
      *env = tmp;
      tmp = tmp + (uint)bool1 * -2 + 1; // ++tmp
      env = env + (uint)bool1 * -2 + 1; // ++env
    }
    ret = greetuser();
  }
  else {
    ret = 1;
  }
  return ret;
}
