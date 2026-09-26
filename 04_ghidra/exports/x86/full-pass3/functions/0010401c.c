/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010401c */

void _dupit(int param_1,int param_2,byte param_3)

{
  _expand_fdlist(*(undefined4 *)(*(int *)(_active_threads + 0xc) + 0x38),param_1);
  *(int *)(*(int *)(_active_u + 0x150) + param_1 * 4) = param_2;
  *(byte *)(param_1 + *(int *)(_active_u + 0x154)) = param_3 & 0xfe;
  *(short *)(param_2 + 0xe) = *(short *)(param_2 + 0xe) + 1;
  if (*(int *)(_active_u + 0x158) < param_1) {
    *(int *)(_active_u + 0x158) = param_1;
  }
  return;
}

