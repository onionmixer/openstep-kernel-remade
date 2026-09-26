/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001cf6fc */

int FUN_001cf6fc(int param_1,int param_2)

{
  if (*(int *)(param_1 + 0xc) == 0) {
    if (*(int *)(param_2 + 0xc) == 0) goto LAB_001cf734;
  }
  else if (*(int *)(param_2 + 0xc) == 0) {
    return -1;
  }
  if (*(int *)(param_1 + 0xc) == 0) {
    return 1;
  }
LAB_001cf734:
  return *(int *)(param_2 + 0x14) - *(int *)(param_1 + 0x14);
}

