void __thiscall N::N(N *this,int param_1)
{
  *(undefined ***)this = &PTR_operator+_08048848;
  *(int *)(this + 0x68) = param_1;
  return;
}

void __thiscall N::setAnnotation(N *this,char *str)
{
  undefined4 len;
  
  len = strlen(str);
  memcpy(this + 4, str, len);
  return;
}

int main(int ac,char **av)
{
  N *this;
  code **this_00;
  
  if (ac < 2) {
                    /* WARNING: Subroutine does not return */
    _exit(1);
  }
  this = (N *)operator.new(0x6c);
  N::N(this,5);
  this_00 = (code **)operator.new(0x6c);
  N::N((N *)this_00,6);
  N::setAnnotation(this, av[1]);
  (**(code **)*this_00)(this_00,this);
  return;
}

// class N {
//   char *annotation;
// }
