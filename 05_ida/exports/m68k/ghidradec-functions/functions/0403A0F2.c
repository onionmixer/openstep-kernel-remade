
undefined4 sub_403A0F2(undefined4 *param_1,int param_2,int param_3,uint param_4)

{
  int iVar1;
  word wVar2;
  bool bVar3;
  undefined4 uVar4;
  
  if ((param_3 == 1) && (*(int *)*param_1 != 0)) {
    _vnode_uncache(param_1);
  }
  iVar1 = *(int *)((int)param_1 + 0x2e);
  if ((*(word *)(iVar1 + 0x62) & 0xf000) == 0x8000) {
    bVar3 = true;
    while ((*(word *)(iVar1 + 0x42) & 1) != 0) {
      *(word *)(iVar1 + 0x42) = *(word *)(iVar1 + 0x42) | 0x10;
      _sleep(iVar1,10);
    }
    *(word *)(iVar1 + 0x42) = *(word *)(iVar1 + 0x42) | 1;
    if (((param_4 & 2) != 0) && (param_3 == 1)) {
      *(undefined4 *)(param_2 + 8) = *(undefined4 *)(iVar1 + 0x6e);
    }
  }
  else {
    bVar3 = false;
  }
  uVar4 = sub_403A216(iVar1,param_2,param_3,param_4);
  if ((*(word *)(iVar1 + 0x42) & 0x46) != 0) {
    *(word *)(iVar1 + 0x42) = *(word *)(iVar1 + 0x42) | 8;
    _microtime(&_iuniqtime);
    if ((*(byte *)(iVar1 + 0x43) & 4) != 0) {
      *(undefined4 *)(iVar1 + 0x72) = _iuniqtime;
    }
    if ((*(byte *)(iVar1 + 0x43) & 2) != 0) {
      *(undefined4 *)(iVar1 + 0x7a) = _iuniqtime;
    }
    if ((*(byte *)(iVar1 + 0x43) & 0x40) != 0) {
      *(undefined4 *)(iVar1 + 0x4a) = 0;
      *(undefined4 *)(iVar1 + 0x82) = _iuniqtime;
    }
    *(word *)(iVar1 + 0x42) = *(word *)(iVar1 + 0x42) & 0xffb9;
  }
  if (bVar3) {
    wVar2 = *(word *)(iVar1 + 0x42);
    *(word *)(iVar1 + 0x42) = wVar2 & 0xfffe;
    if ((wVar2 & 0x10) != 0) {
      *(word *)(iVar1 + 0x42) = wVar2 & 0xffee;
      _wakeup(iVar1);
    }
  }
  return uVar4;
}
