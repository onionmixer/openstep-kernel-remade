/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012e37c */

void FUN_0012e37c(int param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_48;
  undefined1 local_44 [6];
  short local_3e;
  uint local_2c;
  
  param_2[0x13] = 0;
  param_2[0x12] = 0;
  iVar1 = FUN_0012dc2c(param_1,param_3);
  if (iVar1 == 0) {
    *param_2 = 0x46;
    return;
  }
  if (*(int *)(iVar1 + 0x28) == 1) {
    iVar3 = (**(code **)(*(int *)(iVar1 + 0x1c) + 0x14))
                      (iVar1,local_44,*(undefined4 *)(_active_u + 0x1c));
  }
  else {
    _printf(s_rfs_read__attempt_to_read_from_n_001dbf74);
    iVar3 = 0x15;
  }
  if (iVar3 == 0) {
    if (*(short *)(*(int *)(_active_u + 0x1c) + 2) != local_3e) {
      iVar2 = (**(code **)(*(int *)(iVar1 + 0x1c) + 0x1c))(iVar1,0x100,*(int *)(_active_u + 0x1c));
      iVar3 = 0;
      if ((iVar2 != 0) &&
         (iVar3 = (**(code **)(*(int *)(iVar1 + 0x1c) + 0x1c))
                            (iVar1,0x40,*(undefined4 *)(_active_u + 0x1c)), iVar3 != 0))
      goto LAB_0012e4f4;
    }
    if (local_2c <= *(uint *)(param_1 + 0x20)) {
      param_2[0x12] = 0;
      _vattr_to_nattr(local_44,param_2 + 1);
      goto LAB_0012e516;
    }
    iVar3 = _kalloc(*(undefined4 *)(param_1 + 0x24));
    param_2[0x13] = iVar3;
    param_2[-1] = *(int *)(param_1 + 0x24);
    iVar3 = _vn_rdwr(0,iVar1,param_2[0x13],*(undefined4 *)(param_1 + 0x24),
                     *(undefined4 *)(param_1 + 0x20),1,4,&local_48);
    if (iVar3 == 0) {
      iVar3 = (**(code **)(*(int *)(iVar1 + 0x1c) + 0x14))
                        (iVar1,local_44,*(undefined4 *)(_active_u + 0x1c));
      if (iVar3 == 0) {
        _vattr_to_nattr(local_44,param_2 + 1);
        param_2[0x12] = *(int *)(param_1 + 0x24) - local_48;
        goto LAB_0012e516;
      }
    }
  }
LAB_0012e4f4:
  if (param_2[0x13] != 0) {
    _kfree(param_2[0x13],param_2[-1]);
    param_2[0x13] = 0;
    param_2[0x12] = 0;
  }
LAB_0012e516:
  *param_2 = iVar3;
  _vn_rele(iVar1);
  return;
}

