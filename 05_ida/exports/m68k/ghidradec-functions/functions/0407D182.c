
undefined4 _sdwrite(word param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar2 = (param_1 & 0xff) >> 3;
  iVar1 = *(int *)(unk_40B4FDE + uVar2 * 4);
  if ((uVar2 < 0x10) && (iVar1 != 0)) {
    if (((param_1 & 7) == 7) || ((*(byte *)(iVar1 + 0xb) & 4) == 0)) {
      uVar3 = *(undefined4 *)(*(int *)(iVar1 + 0xca) + 4);
    }
    else {
      uVar3 = *(undefined4 *)(*(int *)(iVar1 + 0xd2) + 0x5c);
    }
    uVar3 = _physio(_sdstrategy,**(int **)(unk_40B4FDE + uVar2 * 4) + 0x1c,(int)(sword)param_1,0,
                    _scminphys,param_2,uVar3);
  }
  else {
    uVar3 = 6;
  }
  return uVar3;
}
