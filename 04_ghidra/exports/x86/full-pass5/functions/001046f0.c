/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001046f0 */

int _ufalloc(int param_1)

{
  while( true ) {
    if (0xff < param_1) {
      *(undefined1 *)(DAT_001e875c + 0x68) = 0x18;
      return -1;
    }
    _expand_fdlist(*(undefined4 *)(*(int *)(_active_threads + 0xc) + 0x38),param_1);
    if (*(int *)(*(int *)(_active_u + 0x150) + param_1 * 4) == 0) break;
    param_1 = param_1 + 1;
  }
  *(int *)(DAT_001e875c + 0x60) = param_1;
  *(undefined1 *)(param_1 + *(int *)(_active_u + 0x154)) = 0;
  if (*(int *)(_active_u + 0x158) < param_1) {
    *(int *)(_active_u + 0x158) = param_1;
  }
  *(undefined4 *)(*(int *)(_active_u + 0x150) + param_1 * 4) = 0xffff0000;
  return param_1;
}

