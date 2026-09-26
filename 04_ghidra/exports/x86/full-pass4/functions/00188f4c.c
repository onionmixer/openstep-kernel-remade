/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00188f4c */

void _dma_xfer_done(undefined4 *param_1)

{
  byte bVar1;
  
  bVar1 = *(byte *)(param_1 + 5);
  if ((bVar1 & 1) != 0) {
    if ((bVar1 & 2) != 0) {
      if ((bVar1 & 8) != 0) {
        _bcopy((void *)param_1[3],(void *)*param_1,param_1[1]);
      }
      _dma_buf_free(param_1 + 3);
    }
    *(byte *)(param_1 + 5) = *(byte *)(param_1 + 5) & 0xfc;
  }
  return;
}

