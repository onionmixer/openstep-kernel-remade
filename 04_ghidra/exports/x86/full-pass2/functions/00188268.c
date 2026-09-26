/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00188268 */

void _dma_deassign_chan(undefined4 param_1)

{
  byte bVar1;
  
  _dma_mask_chan(param_1);
  bVar1 = (byte)param_1 & 0x1f;
  _dma_assigned_bits =
       _dma_assigned_bits & ((byte)(-2 << bVar1) | (byte)(0xfffffffe >> 0x20 - bVar1));
  return;
}

