
int sub_404C5D6(undefined4 param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,
               undefined4 *param_5)

{
  int iVar1;
  int *piStack_38;
  int iStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined auStack_18 [8];
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  iVar1 = _lookupname(param_1,1,1,0,&piStack_38);
  if (iVar1 != 0) {
    return 4;
  }
  iVar1 = _check_exec_access(piStack_38);
  if (iVar1 != 0) {
    iVar1 = 6;
    goto loc_404C742;
  }
  iVar1 = _vn_rdwr(0,piStack_38,&iStack_34,0x1c,0,1,1,0);
  if (iVar1 == 0) {
    if (iStack_34 == -0x1120532) {
      *param_2 = 0xfeedface;
      param_2[1] = uStack_30;
      param_2[2] = uStack_2c;
      param_2[3] = uStack_28;
      param_2[4] = uStack_24;
      param_2[5] = uStack_20;
      param_2[6] = uStack_1c;
      *param_3 = 0;
      *param_4 = *(undefined4 *)(*piStack_38 + 0x14);
loc_404C736:
      *param_5 = piStack_38;
      return 0;
    }
    if ((iStack_34 == -0x35014542) || (iStack_34 == -0x41450136)) {
      iVar1 = _fatfile_getarch(piStack_38,&iStack_34,auStack_18);
      if (iVar1 != 0) goto loc_404C742;
      iVar1 = _vn_rdwr(0,piStack_38,&iStack_34,0x1c,uStack_10,1,1,0);
      if (iVar1 != 0) goto loc_404C6D6;
      if (iStack_34 == -0x1120532) {
        *param_2 = 0xfeedface;
        param_2[1] = uStack_30;
        param_2[2] = uStack_2c;
        param_2[3] = uStack_28;
        param_2[4] = uStack_24;
        param_2[5] = uStack_20;
        param_2[6] = uStack_1c;
        *param_3 = uStack_10;
        *param_4 = uStack_c;
        goto loc_404C736;
      }
    }
    iVar1 = 2;
  }
  else {
loc_404C6D6:
    iVar1 = 4;
  }
loc_404C742:
  _vn_rele(piStack_38);
  return iVar1;
}

