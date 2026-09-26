/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001386cc */

bool FUN_001386cc(int param_1,void *param_2,size_t param_3)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x14) - param_3;
  *(int *)(param_1 + 0x14) = iVar1;
  if (-1 < iVar1) {
    _bcopy(param_2,*(void **)(param_1 + 0xc),param_3);
    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + param_3;
  }
  return -1 < iVar1;
}

