/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017eaa4 */

int FUN_0017eaa4(int param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  if (*(uint *)(param_1 + 8) != 0) {
    do {
      if (*(int *)(*(int *)(param_1 + 0x18) + uVar1 * 4) == 0) break;
      uVar1 = uVar1 + 1;
    } while (uVar1 < *(uint *)(param_1 + 8));
  }
  return uVar1 + *(int *)(param_1 + 0xc);
}

