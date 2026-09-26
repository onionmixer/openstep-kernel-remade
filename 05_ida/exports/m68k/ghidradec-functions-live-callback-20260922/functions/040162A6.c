
int _unp_connect(sword *param_1,int param_2)

{
  int iVar1;
  sword *psVar2;
  int iStack_8;
  
  iVar1 = param_2 + *(int *)(param_2 + 4);
  if (*(int *)(param_2 + 4) + -0xc + (int)*(sword *)(param_2 + 8) == 0x70) {
    return 0x28;
  }
  *(undefined *)(*(sword *)(param_2 + 8) + iVar1) = 0;
  iVar1 = _lookupname(iVar1 + 2,1,1,0,&iStack_8);
  if (iVar1 != 0) {
    return iVar1;
  }
  if (*(int *)(iStack_8 + 0x28) != 6) {
    iVar1 = 0x26;
    goto loc_4016350;
  }
  psVar2 = *(sword **)(iStack_8 + 0x20);
  if (psVar2 != (sword *)0x0) {
    if (*psVar2 != *param_1) {
      iVar1 = 0x29;
      goto loc_4016350;
    }
    if (((*(byte *)(*(int *)(param_1 + 6) + 9) & 4) == 0) ||
       (((*(byte *)((int)psVar2 + 3) & 2) != 0 &&
        (psVar2 = (sword *)_sonewconn(psVar2), psVar2 != (sword *)0x0)))) {
      iVar1 = _unp_connect2(param_1,psVar2);
      goto loc_4016350;
    }
  }
  iVar1 = 0x3d;
loc_4016350:
  _vn_rele(iStack_8);
  return iVar1;
}

