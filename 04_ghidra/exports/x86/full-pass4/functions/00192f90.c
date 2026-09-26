/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00192f90 */

void _byte_swap_partition(uint *param_1)

{
  uint uVar1;
  
  uVar1 = *param_1;
  *param_1 = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
  uVar1 = param_1[1];
  param_1[1] = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
  *(ushort *)(param_1 + 2) = (ushort)param_1[2] >> 8 | (ushort)param_1[2] << 8;
  *(ushort *)((int)param_1 + 10) =
       *(ushort *)((int)param_1 + 10) >> 8 | *(ushort *)((int)param_1 + 10) << 8;
  *(ushort *)((int)param_1 + 0xe) =
       *(ushort *)((int)param_1 + 0xe) >> 8 | *(ushort *)((int)param_1 + 0xe) << 8;
  *(ushort *)(param_1 + 4) = (ushort)param_1[4] >> 8 | (ushort)param_1[4] << 8;
  return;
}

