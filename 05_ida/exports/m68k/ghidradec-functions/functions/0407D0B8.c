
undefined4 _sdsize(undefined8 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(unk_40B4FDE + (param_1._3_4_ >> 0x1b) * 4);
  if ((param_1._3_4_ >> 0x1b < 0x10) && (iVar1 != 0)) {
    if ((*(byte *)(iVar1 + 0xb) & 4) == 0) {
      uVar2 = *(undefined4 *)(*(int *)(iVar1 + 0xca) + 4);
    }
    else {
      uVar2 = *(undefined4 *)(*(int *)(iVar1 + 0xd2) + 0x5c);
    }
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}
