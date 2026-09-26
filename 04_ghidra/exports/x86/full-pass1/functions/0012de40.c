/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012de40 */

void FUN_0012de40(undefined4 param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined1 local_44 [64];
  
  iVar1 = FUN_0012dc2c(param_1,param_3);
  if (iVar1 == 0) {
    *param_2 = 0x46;
  }
  else {
    iVar2 = (**(code **)(*(int *)(iVar1 + 0x1c) + 0x14))
                      (iVar1,local_44,*(undefined4 *)(_active_u + 0x1c));
    if (iVar2 == 0) {
      _vattr_to_nattr(local_44,param_2 + 1);
    }
    *param_2 = iVar2;
    _vn_rele(iVar1);
  }
  return;
}

