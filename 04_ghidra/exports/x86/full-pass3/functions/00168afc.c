/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00168afc */

int _stack_usage(int param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  do {
    if (*(int *)(param_1 + uVar1 * 4) != -0x21524111) break;
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x3fd);
  return uVar1 * -4 + 0xff4;
}

