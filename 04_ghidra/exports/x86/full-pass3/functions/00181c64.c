/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00181c64 */

undefined4 FUN_00181c64(int param_1,undefined4 param_2,uint param_3)

{
  if (*(uint *)(param_1 + 8) <= param_3) {
    return 0;
  }
  return *(undefined4 *)(*(int *)(param_1 + 4) + param_3 * 4);
}

