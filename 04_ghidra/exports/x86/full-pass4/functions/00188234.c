/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00188234 */

undefined4 _dma_assign_chan(uint param_1)

{
  if ((_dma_assigned_bits >> (param_1 & 0x1f) & 1) == 0) {
    _dma_assigned_bits = _dma_assigned_bits | (byte)(1 << ((byte)param_1 & 0x1f));
    return 1;
  }
  return 0;
}

