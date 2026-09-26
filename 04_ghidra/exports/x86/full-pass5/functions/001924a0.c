/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001924a0 */

undefined4 FUN_001924a0(int param_1)

{
  if (*(int *)(_active_threads + 0x74) == 0) {
    return 0;
  }
  *(int *)(param_1 + 4) = *(int *)(_active_threads + 0x74);
  *(undefined2 *)(param_1 + 8) = 8;
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) & 0xfffffbff;
  *(undefined4 *)(_active_threads + 0x74) = 0;
  return 1;
}

