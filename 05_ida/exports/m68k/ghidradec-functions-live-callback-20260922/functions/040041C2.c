
void _fset(int param_1,uint param_2,int param_3)

{
  undefined4 uVar1;
  
  if (param_3 == 0) {
    *(uint *)(param_1 + 8) = ~param_2 & *(uint *)(param_1 + 8);
  }
  else {
    *(uint *)(param_1 + 8) = param_2 | *(uint *)(param_1 + 8);
  }
  uVar1 = 0x8004667d;
  if (param_2 == 4) {
    uVar1 = 0x8004667e;
  }
  _fioctl(param_1,uVar1,&param_3);
  return;
}

