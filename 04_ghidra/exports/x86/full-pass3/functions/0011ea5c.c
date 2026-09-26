/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011ea5c */

undefined4 _isrofile(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (((1 < *(int *)(param_1 + 0x28) - 3U) && (*(int *)(param_1 + 0x28) != 8)) &&
     ((*(byte *)(*(int *)(param_1 + 0x24) + 0xc) & 1) != 0)) {
    uVar1 = 1;
  }
  return uVar1;
}

