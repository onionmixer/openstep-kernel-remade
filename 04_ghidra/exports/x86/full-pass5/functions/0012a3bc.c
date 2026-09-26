/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012a3bc */

void _tcp_setpersist(int param_1)

{
  if (*(short *)(param_1 + 10) != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(s_tcp_output_REXMT_001dbe79);
  }
  *(short *)(param_1 + 0xc) =
       (short)((int)(*(short *)(param_1 + 0x60) >> 2) + (int)*(short *)(param_1 + 0x62) >> 1) *
       *(short *)(&_tcp_backoff + *(short *)(param_1 + 0x12) * 4);
  if (*(short *)(param_1 + 0xc) < 10) {
    *(undefined2 *)(param_1 + 0xc) = 10;
  }
  else if (0x78 < *(short *)(param_1 + 0xc)) {
    *(undefined2 *)(param_1 + 0xc) = 0x78;
  }
  if (*(short *)(param_1 + 0x12) < 0xc) {
    *(short *)(param_1 + 0x12) = *(short *)(param_1 + 0x12) + 1;
  }
  return;
}

