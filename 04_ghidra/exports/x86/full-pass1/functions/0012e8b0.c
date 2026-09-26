/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012e8b0 */

void FUN_0012e8b0(undefined4 param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined1 local_44 [4];
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  
  iVar1 = FUN_0012dc2c(param_1,param_3);
  if (iVar1 == 0) {
    *param_2 = 0x46;
  }
  else {
    iVar2 = (**(code **)(*(int *)(*(int *)(iVar1 + 0x24) + 4) + 0xc))
                      (*(int *)(iVar1 + 0x24),local_44);
    *param_2 = iVar2;
    if (iVar2 == 0) {
      iVar2 = _nfstsize();
      param_2[1] = iVar2;
      param_2[2] = local_40;
      param_2[3] = local_3c;
      param_2[4] = local_38;
      param_2[5] = local_34;
    }
    _vn_rele(iVar1);
  }
  return;
}

