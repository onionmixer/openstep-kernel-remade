
undefined4 _stclose(word param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = ((param_1 & 0xff) >> 3) * 0x166;
  uVar2 = 0;
  if ((_st_std[iVar1 + 0x67] & 8) != 0) {
    uVar2 = sub_4088840(_st_std + iVar1);
  }
  if ((param_1 & 1) == 0) {
    uVar2 = sub_4088898(_st_std + iVar1);
  }
  *(word *)(_st_std + iVar1 + 0x66) = *(word *)(_st_std + iVar1 + 0x66) & 0xffef;
  return uVar2;
}
