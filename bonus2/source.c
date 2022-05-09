
void greetuser(void)
{
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined2 local_3c;
  undefined local_3a;
  
  if (language == 1) {
    local_4c = 0xc3767948; // "Hyvää päivää " ?
    local_48 = 0x20a4c3a4;
    local_44 = 0x69a4c370;
    local_40 = 0xc3a4c376;
    local_3c = 0x20a4;
    local_3a = 0;
  }
  else {
    if (language == 2) { // "Goedemiddag! "
      local_4c = 0x64656f47; // "Goedemiddag! "
      local_48 = 0x64696d65; // "emiddag! "
      local_44 = 0x21676164; // "dag !"
      local_40 = CONCAT22(local_40._2_2_,0x20);
    }
    else {
      if (language == 0) {
        local_4c = 0x6c6c6548; // "Hello ""
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
  char *lang;
  
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
    lang = getenv("LANG");
    if (lang) {
      i = memcmp(lang, "fi");
      if (i == 0) {
        language = 1;
      }
      else {
        i = memcmp(lang, "nl");
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

  //                      DAT_08048738                                    XREF[1]:     main:0804859f(*)  
  // 08048738 4c              ??         4Ch    L
  // 08048739 41              ??         41h    A
  // 0804873a 4e              ??         4Eh    N
  // 0804873b 47              ??         47h    G
  // 0804873c 00              ??         00h
  //                      DAT_0804873d                                    XREF[1]:     main:080485c4(*)  
  // 0804873d 66              ??         66h    f
  // 0804873e 69              ??         69h    i
  // 0804873f 00              ??         00h
  //                      DAT_08048740                                    XREF[1]:     main:080485f3(*)  
  // 08048740 6e              ??         6Eh    n
  // 08048741 6c              ??         6Ch    l
  // 08048742 00              ??         00h

  //                      LAB_080484e9                                    XREF[1]:     08048497(j)  
  // 080484e9 ba 2a 87        MOV        EDX,s_Goedemiddag!_0804872a                      = "Goedemiddag! "
  //          04 08
  // 080484ee 8d 45 b8        LEA        EAX=>local_4c,[EBP + -0x48]
  // 080484f1 8b 0a           MOV        ECX,dword ptr [EDX]=>s_Goedemiddag!_0804872a     = "Goedemiddag! "
  // 080484f3 89 08           MOV        dword ptr [EAX]=>local_4c,ECX
  // 080484f5 8b 4a 04        MOV        ECX,dword ptr [EDX + 0x4]=>s_emiddag!_0804872a+4 = "emiddag! "
  // 080484f8 89 48 04        MOV        dword ptr [EAX + local_48],ECX
  // 080484fb 8b 4a 08        MOV        ECX,dword ptr [EDX + 0x8]=>s_dag!_0804872a+8     = "dag! "
  // 080484fe 89 48 08        MOV        dword ptr [EAX + local_44],ECX
  // 08048501 0f b7 52 0c     MOVZX      EDX,word ptr [EDX + 0xc]=>s__0804872a+12         = " "
  // 08048505 66 89 50 0c     MOV        word ptr [EAX + local_40],DX


  // 0804849d ba 10 87        MOV        EDX,s_Hello_08048710                             = "Hello "
  //           04 08
  // 080484a2 8d 45 b8        LEA        EAX=>local_4c,[EBP + -0x48]
  // 080484a5 8b 0a           MOV        ECX,dword ptr [EDX]=>s_Hello_08048710            = "Hello "
  // 080484a7 89 08           MOV        dword ptr [EAX]=>local_4c,ECX
  // 080484a9 0f b7 4a 04     MOVZX      ECX,word ptr [EDX + 0x4]=>s_o_08048710+4         = "o "
  // 080484ad 66 89 48 04     MOV        word ptr [EAX + local_48],CX
  // 080484b1 0f b6 52 06     MOVZX      EDX,byte ptr [EDX + 0x6]=>s__08048710+6          = ""
  // 080484b5 88 50 06        MOV        byte ptr [EAX + local_48+0x2],DL
  // 080484b8 eb 50           JMP        LAB_0804850a
