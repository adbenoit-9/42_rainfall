int main(void)
{
  char cVar1;
  int fd;
  uint uVar3;
  byte *str_tmp;
  char *tmp_auth;
  byte *cmp;
  bool bool1;
  undefined bool3;
  undefined bool5;
  bool bool2;
  undefined bool4;
  byte str [5];
  char in_auth [2];
  undefined auStack137 [125];
  
  do {
    printf("%p, %p \n",auth,service);
    fd = fgets(str,0x80,stdin);
    bool1 = false;
    if (fd == 0) {
      return 0;
    }
    fd = 5;
    str_tmp = str;
    cmp = (byte *)"auth ";
    while (bool2) {
      --fd;
      bool1 = *str_tmp < *cmp;
      bool2 = *str_tmp == *cmp;
      ++str_tmp;
      ++cmp;
    }
    bool3 = 0;
    bool4 = (!bool1 && !bool2) == bool1;
    if (bool4) {
      auth = (undefined4 *)malloc(4);
      *auth = 0;
      uVar3 = 0xffffffff; // unsigned int max
      tmp_auth = in_auth;
      while (cVar1 != '\0') {
        if (uVar3 == 0) break;
        --uVar3;
        cVar1 = *tmp_auth;
        ++tmp_auth;
      }
      uVar3 = ~uVar3 - 1;
      bool3 = uVar3 < 0x1e;
      bool4 = uVar3 == 0x1e;
      if (uVar3 < 0x1f) {
        strcpy(auth, in_auth);
      }
    }
    fd = 5;
    str_tmp = str;
    cmp = (byte *)"reset";
    while (bool4) {
      if (fd == 0) break;
      --fd;
      bool3 = *str_tmp < *cmp;
      bool4 = *str_tmp == *cmp;
      ++str_tmp;
      ++cmp;
    }
    bool5 = 0;
    bool3 = (!(bool)bool3 && !(bool)bool4) == (bool)bool3;
    if ((bool)bool3) {
      free(auth);
    }
    fd = 6;
    str_tmp = str;
    cmp = (byte *)"service";
    while (bool3) {
      if (fd == 0) break;
      --fd;
      bool5 = *str_tmp < *cmp;
      bool3 = *str_tmp == *cmp;
      ++str_tmp;
      ++cmp;
    }
    bool4 = 0;
    bool3 = (!(bool)bool5 && !(bool)bool3) == (bool)bool5;
    if ((bool)bool3) {
      bool4 = (byte *)0xfffffff8 < str;
      bool3 = auStack137 == (undefined *)0x0;
      service = strdup(auStack137);
    }
    fd = 5;
    str_tmp = str;
    cmp = (byte *)"login";
    while ((bool)bool3) {
      if (fd == 0) break;
      --fd;
      bool4 = *str_tmp < *cmp;
      bool3 = *str_tmp == *cmp;
      ++str_tmp;
      ++cmp;
    }
    bool3 = 0
    if ((!(bool)bool4 && !(bool)bool3) == (bool)bool4) {
    if (bool4)
      if (auth[8] == 0) {
        fwrite("Password:\n",1,10,stdout);
      }
      else {
        system("/bin/sh");
      }
    }
  } while( true );
}
