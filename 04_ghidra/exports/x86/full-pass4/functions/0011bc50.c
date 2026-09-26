/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011bc50 */

int _vno_stat(int param_1,undefined2 *param_2)

{
  int iVar1;
  undefined1 local_44 [4];
  undefined2 local_40;
  undefined2 local_3e;
  undefined2 local_3c;
  undefined2 local_38;
  undefined4 local_34;
  undefined2 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int local_1c;
  int local_18;
  undefined4 local_14;
  undefined2 local_c;
  undefined4 local_8;
  
  iVar1 = (**(code **)(*(int *)(param_1 + 0x1c) + 0x14))
                    (param_1,local_44,*(undefined4 *)(_active_u + 0x1c));
  if (iVar1 == 0) {
    param_2[4] = local_40;
    param_2[6] = local_3e;
    param_2[7] = local_3c;
    *param_2 = local_38;
    *(undefined4 *)(param_2 + 2) = local_34;
    param_2[5] = local_30;
    *(undefined4 *)(param_2 + 10) = local_2c;
    *(undefined4 *)(param_2 + 0x18) = local_28;
    *(undefined4 *)(param_2 + 0xc) = local_24;
    *(undefined4 *)(param_2 + 0xe) = 0;
    iVar1 = *(int *)(param_1 + 0x14);
    if (((iVar1 == 0) && (*(int *)(param_1 + 0x18) == 0)) ||
       ((iVar1 <= local_1c && ((iVar1 != local_1c || (*(int *)(param_1 + 0x18) <= local_18)))))) {
      *(int *)(param_2 + 0x10) = local_1c;
    }
    else {
      *(int *)(param_2 + 0x10) = iVar1;
    }
    *(undefined4 *)(param_2 + 0x12) = 0;
    *(undefined4 *)(param_2 + 0x14) = local_14;
    *(undefined4 *)(param_2 + 0x16) = 0;
    param_2[8] = local_c;
    *(undefined4 *)(param_2 + 0x1a) = local_8;
    *(undefined4 *)(param_2 + 0x1e) = 0;
    *(undefined4 *)(param_2 + 0x1c) = 0;
    if (*(undefined ***)(param_1 + 0x1c) == &_ufs_vnodeops) {
      *(undefined4 *)(param_2 + 0x1c) = 0xfeedface;
      *(undefined4 *)(param_2 + 0x1e) = *(undefined4 *)(*(int *)(param_1 + 0x30) + 0xd0);
    }
    else if ((*(undefined ***)(param_1 + 0x1c) == &_nfs_vnodeops) &&
            (iVar1 = *(int *)(param_1 + 0x30), *(int *)(iVar1 + 0x4c) == *(int *)(param_2 + 2))) {
      *(undefined4 *)(param_2 + 0x1c) = 0xfeedface;
      *(undefined4 *)(param_2 + 0x1e) = *(undefined4 *)(iVar1 + 0x50);
    }
    iVar1 = 0;
  }
  return iVar1;
}

