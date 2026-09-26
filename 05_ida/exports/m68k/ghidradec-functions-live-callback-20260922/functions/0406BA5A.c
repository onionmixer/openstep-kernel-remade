
undefined4 _fdsize(undefined8 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  param_1._3_4_ = param_1._3_4_ >> 0x1b;
  iVar1 = *(int *)(_fd_volume_p + param_1._3_4_ * 4);
  if (param_1._3_4_ == 8) {
    uVar2 = 0;
  }
  else if ((param_1._3_4_ < 9) && (iVar1 != 0)) {
    if ((*(byte *)(iVar1 + 0x179) & 2) == 0) {
      uVar2 = *(undefined4 *)(iVar1 + 0x186);
    }
    else {
      uVar2 = *(undefined4 *)(*(int *)(iVar1 + 0x14) + 0x5c);
    }
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

