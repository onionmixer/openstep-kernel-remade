/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b72bc */

int FUN_001b72bc(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x148);
  if (iVar1 == 1) {
    return 0x25a;
  }
  if (iVar1 == 0) {
    return 600;
  }
  if (iVar1 == 2) {
    return 0x25b;
  }
  if (iVar1 != 3) {
    return iVar1;
  }
  return 0x259;
}

