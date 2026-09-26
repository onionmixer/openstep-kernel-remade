/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016cd58 */

undefined4 _kern_serv_log_level(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *param_1;
  iVar2 = *(int *)(iVar1 + 0x30);
  *(int *)(iVar1 + 0x30) = param_2;
  if (iVar2 == 0) {
    if (param_2 != 0) {
      FUN_0016d004(iVar1 + 0x24,500);
      return 0;
    }
  }
  else if (param_2 != 0) {
    return 0;
  }
  if (iVar2 != 0) {
    FUN_0016d054(iVar1 + 0x24);
  }
  return 0;
}

