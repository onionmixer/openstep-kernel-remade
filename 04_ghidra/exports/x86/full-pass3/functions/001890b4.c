/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001890b4 */

uint _get_dma_xfer_width(uint param_1)

{
  if ((_dma_assigned_bits >> (param_1 & 0x1f) & 1) != 0) {
    return (byte)(&DAT_001f74f1)[param_1 * 2] >> 2 & 3;
  }
  return 0xffffffff;
}

