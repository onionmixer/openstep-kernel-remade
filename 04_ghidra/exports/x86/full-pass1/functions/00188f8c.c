/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00188f8c */

void _dma_xfer_abort(int param_1)

{
  if ((*(byte *)(param_1 + 0x14) & 1) != 0) {
    if ((*(byte *)(param_1 + 0x14) & 2) != 0) {
      _dma_buf_free(param_1 + 0xc);
    }
    *(byte *)(param_1 + 0x14) = *(byte *)(param_1 + 0x14) & 0xfc;
  }
  return;
}

