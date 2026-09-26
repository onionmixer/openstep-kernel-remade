
undefined4 _fsetown(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if (*(sword *)(param_1 + 0xc) == 2) {
    *(undefined2 *)(*(int *)(param_1 + 0x16) + 0x54) = param_2._2_2_;
    uVar1 = 0;
  }
  else {
    if (param_2 < 1) {
      param_2 = -param_2;
    }
    else {
      iVar2 = _pfind(param_2);
      if (iVar2 == 0) {
        return 3;
      }
      param_2 = (int)*(sword *)(iVar2 + 0x2e);
    }
    uVar1 = _fioctl(param_1,0x80047476,&param_2);
  }
  return uVar1;
}
