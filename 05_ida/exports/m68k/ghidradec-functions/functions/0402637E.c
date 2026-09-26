
undefined4 sub_402637E(int *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int iStack_c;
  int iStack_8;
  
  iVar1 = *(int *)((int)param_1 + 0x2e);
  _getthetime(&iStack_c);
  if ((iStack_c < *(int *)(iVar1 + 0xb6)) ||
     ((*(int *)(iVar1 + 0xb6) == iStack_c && (iStack_8 < *(int *)(iVar1 + 0xba))))) {
    _bcopy(iVar1 + 0x7c,param_2,0x3a);
    *(uint *)(param_2 + 10) = *(uint *)(*(int *)(param_1[9] + 0x126) + 0x26) | 0xff00;
    uVar2 = *(uint *)(*param_1 + 0x14);
    if ((*(uint *)(param_2 + 0x14) < uVar2) &&
       (((*(byte *)(*param_1 + 0x34) & 0x40) != 0 || ((*(byte *)(iVar1 + 0x5f) & 0x10) != 0)))) {
      *(uint *)(param_2 + 0x14) = uVar2;
    }
    uVar3 = 1;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}
