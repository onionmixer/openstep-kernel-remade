/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00193308 */

void _byte_swap_dir_block_in(int param_1,int param_2)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < param_2) {
    do {
      puVar1 = (uint *)(iVar3 + param_1);
      uVar2 = *puVar1;
      *puVar1 = uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
      *(ushort *)(puVar1 + 1) = (ushort)puVar1[1] >> 8 | (ushort)puVar1[1] << 8;
      *(ushort *)((int)puVar1 + 6) =
           *(ushort *)((int)puVar1 + 6) >> 8 | *(ushort *)((int)puVar1 + 6) << 8;
      iVar3 = iVar3 + (uint)(ushort)puVar1[1];
      if ((ushort)puVar1[1] < 0xc) {
        return;
      }
    } while (iVar3 < param_2);
  }
  return;
}

