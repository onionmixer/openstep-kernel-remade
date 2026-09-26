/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012dc2c */

int FUN_0012dc2c(int param_1,int param_2)

{
  int iVar1;
  int local_8;
  
  if ((((param_2 != 0) && (iVar1 = _getvfs(param_1), iVar1 != 0)) &&
      (iVar1 = (**(code **)(*(int *)(iVar1 + 4) + 0x14))(iVar1,&local_8,param_1 + 8), iVar1 == 0))
     && (local_8 != 0)) {
    return local_8;
  }
  return 0;
}

