/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00133884 */

undefined4 FUN_00133884(int param_1,int param_2,int *param_3,int *param_4)

{
  int iVar1;
  
  if (param_3 != (int *)0x0) {
    *param_3 = param_1;
  }
  if (param_4 != (int *)0x0) {
    iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 0x24) + 0x128) + 0x24);
    if (iVar1 < 0) {
      iVar1 = iVar1 + 0x3ff;
    }
    *param_4 = (iVar1 >> 10) * param_2;
  }
  return 0;
}

