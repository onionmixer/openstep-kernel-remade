/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c0ddc */

void FUN_001c0ddc(undefined4 param_1,undefined4 param_2,int param_3)

{
  if ((*(byte *)(param_3 + 0x14) & 1) != 0) {
    _dma_xfer_abort(param_3);
  }
  _IOFree(param_3,0x18);
  return;
}

