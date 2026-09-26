/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012e200 */

void FUN_0012e200(int param_1,int *param_2,uint *param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 local_85;
  undefined1 local_84 [24];
  uint local_6c;
  undefined1 local_44 [24];
  uint local_2c;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  int local_18;
  
  iVar3 = 0;
  iVar1 = FUN_0012dc2c(param_1,param_3);
  if (iVar1 == 0) {
    *param_2 = 0x46;
    return;
  }
  if (((*param_3 & 1) == 0) &&
     (((*param_3 & 2) == 0 ||
      (iVar2 = FUN_0012dc70(*(int *)(param_4 + 0x1c) + 0x10,param_3 + 6), iVar2 != 0)))) {
    FUN_0012dbdc(param_1 + 0x20,local_44);
    if ((local_1c != -1) && (local_18 == 1000000)) {
      local_1c = 0;
      local_18 = -1;
      local_24 = 0xffffffff;
      local_20 = 0xffffffff;
    }
    if ((*(int *)(iVar1 + 0x28) == 1) && (local_2c != 0xffffffff)) {
      local_85 = 0;
      iVar3 = (**(code **)(*(int *)(iVar1 + 0x1c) + 0x14))
                        (iVar1,local_84,*(undefined4 *)(_active_u + 0x1c));
      if (iVar3 != 0) goto LAB_0012e364;
      if (local_6c < local_2c) {
        iVar3 = _vn_rdwr(1,iVar1,&local_85,1,local_2c - 1,1,4,0);
        (**(code **)(*(int *)(iVar1 + 0x1c) + 0x48))(iVar1,*(undefined4 *)(_active_u + 0x1c));
      }
    }
    if (iVar3 == 0) {
      iVar3 = (**(code **)(*(int *)(iVar1 + 0x1c) + 0x18))
                        (iVar1,local_44,*(undefined4 *)(_active_u + 0x1c));
      if ((iVar3 == 0) &&
         (iVar3 = (**(code **)(*(int *)(iVar1 + 0x1c) + 0x14))
                            (iVar1,local_44,*(undefined4 *)(_active_u + 0x1c)), iVar3 == 0)) {
        _vattr_to_nattr(local_44,param_2 + 1);
      }
    }
  }
  else {
    iVar3 = 0x1e;
  }
LAB_0012e364:
  *param_2 = iVar3;
  _vn_rele(iVar1);
  return;
}

