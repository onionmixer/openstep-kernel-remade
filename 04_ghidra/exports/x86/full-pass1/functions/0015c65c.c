/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015c65c */

int _nextsect(int param_1,int param_2)

{
  int iVar1;
  
  if ((param_1 == 0) || (*(int *)(param_1 + 0x30) == 0)) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_1 + 0x38;
  }
  if ((uint)((param_2 - iVar1) * -0xf0f0f0f >> 2) < *(int *)(param_1 + 0x30) - 1U) {
    param_2 = param_2 + 0x44;
  }
  else {
    param_2 = 0;
  }
  return param_2;
}

