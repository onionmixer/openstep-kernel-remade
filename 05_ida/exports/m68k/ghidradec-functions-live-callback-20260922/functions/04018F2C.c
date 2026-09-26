
int _vno_stat(int param_1,undefined2 *param_2)

{
  int iVar1;
  undefined auStack_3e [4];
  undefined2 uStack_3a;
  undefined2 uStack_38;
  undefined2 uStack_36;
  undefined2 uStack_32;
  undefined4 uStack_30;
  undefined2 uStack_2c;
  undefined4 uStack_2a;
  undefined4 uStack_26;
  undefined4 uStack_22;
  int iStack_1a;
  int iStack_16;
  undefined4 uStack_12;
  undefined2 uStack_a;
  undefined4 uStack_8;
  
  iVar1 = (**(code **)(*(int *)(param_1 + 0x1c) + 0x14))
                    (param_1,auStack_3e,*(undefined4 *)(_active_u + 0x1a));
  if (iVar1 == 0) {
    param_2[3] = uStack_3a;
    param_2[5] = uStack_38;
    param_2[6] = uStack_36;
    *param_2 = uStack_32;
    *(undefined4 *)(param_2 + 1) = uStack_30;
    param_2[4] = uStack_2c;
    *(undefined4 *)(param_2 + 8) = uStack_2a;
    *(undefined4 *)(param_2 + 0x16) = uStack_26;
    *(undefined4 *)(param_2 + 10) = uStack_22;
    *(undefined4 *)(param_2 + 0xc) = 0;
    iVar1 = *(int *)(param_1 + 0x14);
    if (((iVar1 == 0) && (*(int *)(param_1 + 0x18) == 0)) ||
       ((iVar1 <= iStack_1a && ((iStack_1a != iVar1 || (*(int *)(param_1 + 0x18) <= iStack_16))))))
    {
      *(int *)(param_2 + 0xe) = iStack_1a;
    }
    else {
      *(int *)(param_2 + 0xe) = iVar1;
    }
    *(undefined4 *)(param_2 + 0x10) = 0;
    *(undefined4 *)(param_2 + 0x12) = uStack_12;
    *(undefined4 *)(param_2 + 0x14) = 0;
    param_2[7] = uStack_a;
    *(undefined4 *)(param_2 + 0x18) = uStack_8;
    *(undefined4 *)(param_2 + 0x1c) = 0;
    *(undefined4 *)(param_2 + 0x1a) = 0;
    if (*(undefined **)(param_1 + 0x1c) == _ufs_vnodeops) {
      *(undefined4 *)(param_2 + 0x1a) = 0xfeedface;
      *(undefined4 *)(param_2 + 0x1c) = *(undefined4 *)(*(int *)(param_1 + 0x2e) + 0xce);
    }
    else if ((*(undefined **)(param_1 + 0x1c) == _nfs_vnodeops) &&
            (iVar1 = *(int *)(param_1 + 0x2e), *(int *)(iVar1 + 0x48) == *(int *)(param_2 + 1))) {
      *(undefined4 *)(param_2 + 0x1a) = 0xfeedface;
      *(undefined4 *)(param_2 + 0x1c) = *(undefined4 *)(iVar1 + 0x4c);
    }
    iVar1 = 0;
  }
  return iVar1;
}

