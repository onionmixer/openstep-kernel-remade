/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00138598 */

undefined4 _xdrmbuf_setpos(int param_1,int param_2)

{
  int iVar1;
  
  param_2 = *(int *)(param_1 + 0x10) + *(int *)(*(int *)(param_1 + 0x10) + 4) + param_2;
  iVar1 = *(int *)(param_1 + 0xc) + *(int *)(param_1 + 0x14);
  if (param_2 <= iVar1) {
    *(int *)(param_1 + 0xc) = param_2;
    *(int *)(param_1 + 0x14) = iVar1 - param_2;
    return 1;
  }
  return 0;
}

