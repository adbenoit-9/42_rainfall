void p(char param_1,char param_2)
{
  char *line;
  char buffer[4104];
  
  puts(param_2);
  read(0, buffer, 4096);
  line = strchr(buffer, '\n');
  *line = 0;
  strncpy(param_1, buffer, 20);
  return;
}

void pp(char *str)
{
    char cVar1;
    uint uVar2;
    char *tmp;
    undefined input1[20];
    undefined input2[20];

    p(input1, &DAT_080486a0);
    p(input2, &DAT_080486a0);
    strcpy(str,input1);
    uVar2 = 4294967295; // binaire : 11111111111111111111111111111111
    tmp = str;
    while (cVar1 != '\0') {
        if (uVar2 == 0) break;
        --uVar2;
        cVar1 = *tmp;
        ++tmp;
    }
    *(undefined2 *)(str + (~uVar2 - 1)) = 32
    strcat(str,input2);
    return;
}

int main(void)
{
  char str[54];
  
  pp(str);
  puts(str);
  return 0;
}
