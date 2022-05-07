
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
        local_4c = 0x6c6c6548;
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
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 **ppuVar4;
  byte bool1;
  undefined4 *local_b0;
  undefined *local_ac;
  undefined4 local_a8;
  char local_60[10];
  char auStack56[9];
  char *local_14;
  
  bool1 = 0;
  if (ac == 3) {
    iVar2 = 0x13;
    puVar3 = local_60;
    while (iVar2 != 0) {
      iVar2 = iVar2 + -1;
      *puVar3 = 0;
      puVar3 = puVar3 + 1;
    }
    local_ac = *(undefined **)(av + 4);
    local_a8 = 0x28;
    local_b0 = local_60;
    strncpy();
    local_ac = *(undefined **)(av + 8);
    local_a8 = 0x20;
    local_b0 = auStack56;
    strncpy();
    local_b0 = (undefined4 *)&DAT_08048738;
    local_14 = (undefined4 *)getenv();
    if (local_14 != (undefined4 *)0x0) {
      local_a8 = 2;
      local_ac = &DAT_0804873d;
      local_b0 = local_14;
      iVar2 = memcmp();
      if (iVar2 == 0) {
        language = 1;
      }
      else {
        local_a8 = 2;
        local_ac = &DAT_08048740;
        local_b0 = local_14;
        iVar2 = memcmp();
        if (iVar2 == 0) {
          language = 2;
        }
      }
    }
    iVar2 = 0x13;
    puVar3 = local_60;
    ppuVar4 = &local_b0;
    while (iVar2 != 0) {
      iVar2 = iVar2 + -1;
      *ppuVar4 = (undefined4 *)*puVar3;
      puVar3 = puVar3 + (uint)bool1 * -2 + 1;
      ppuVar4 = ppuVar4 + (uint)bool1 * -2 + 1;
    }
    uVar1 = greetuser();
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}
