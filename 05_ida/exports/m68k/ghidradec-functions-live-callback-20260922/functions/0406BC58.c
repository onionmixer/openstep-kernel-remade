
undefined4 _fdread(word param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar2 = (param_1 & 0xff) >> 3;
  iVar1 = *(int *)(_fd_volume_p + uVar2 * 4);
  if ((uVar2 < 8) && (iVar1 != 0)) {
    if ((param_1 & 7) == 1) {
      uVar3 = *(undefined4 *)(iVar1 + 0x186);
    }
    else {
      if ((*(byte *)(iVar1 + 0x179) & 2) == 0) goto loc_406BC96;
      uVar3 = *(undefined4 *)(*(int *)(iVar1 + 0x14) + 0x5c);
    }
    uVar3 = _physio(_fdstrategy,*(int *)(_fd_volume_p + uVar2 * 4) + 0xe0,(int)(sword)param_1,1,
                    sub_406BD66,param_2,uVar3);
  }
  else {
loc_406BC96:
    uVar3 = 6;
  }
  return uVar3;
}

