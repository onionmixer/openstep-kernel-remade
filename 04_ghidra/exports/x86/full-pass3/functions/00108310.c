/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00108310 */

undefined4 _suser(void)

{
  if (**(int **)(*(int *)(_active_threads + 0xc) + 0x38) == 0) {
    return 0;
  }
  if (*(short *)(*(int *)(_active_u + 0x1c) + 2) != 0) {
    *(undefined1 *)(DAT_001e875c + 0x68) = 1;
    return 0;
  }
  *(byte *)(_active_u + 0x244) = *(byte *)(_active_u + 0x244) | 2;
  return 1;
}

