/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012dfbc */

void FUN_0012dfbc(int param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int local_48;
  undefined1 local_44 [64];
  
  if ((*(char **)(param_1 + 0x20) == (char *)0x0) || (**(char **)(param_1 + 0x20) == '\0')) {
    *param_2 = 0xd;
  }
  else {
    iVar1 = FUN_0012dc2c(param_1,param_3);
    if (iVar1 == 0) {
      *param_2 = 0x46;
    }
    else {
      iVar2 = (**(code **)(*(int *)(iVar1 + 0x1c) + 0x20))
                        (iVar1,*(undefined4 *)(param_1 + 0x20),&local_48,
                         *(undefined4 *)(_active_u + 0x1c),0,0);
      if (iVar2 == 0) {
        iVar2 = (**(code **)(*(int *)(local_48 + 0x1c) + 0x14))
                          (local_48,local_44,*(undefined4 *)(_active_u + 0x1c));
        if (iVar2 == 0) {
          _vattr_to_nattr(local_44,param_2 + 9);
          iVar2 = _makefh(param_2 + 1,local_48,param_3);
        }
      }
      else {
        local_48 = 0;
      }
      *param_2 = iVar2;
      if (local_48 != 0) {
        _vn_rele(local_48);
      }
      _vn_rele(iVar1);
    }
  }
  return;
}

