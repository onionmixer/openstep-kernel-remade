/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001932bc */

void _byte_swap_dir_block_out(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  
  iVar4 = 0;
  if (0 < *(int *)(param_1 + 0x14)) {
    do {
      puVar3 = (uint *)(*(int *)(param_1 + 0x20) + iVar4);
      uVar2 = puVar3[1];
      iVar4 = iVar4 + (uint)(ushort)uVar2;
      uVar1 = *puVar3;
      *puVar3 = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
      *(ushort *)(puVar3 + 1) = (ushort)puVar3[1] >> 8 | (ushort)puVar3[1] << 8;
      *(ushort *)((int)puVar3 + 6) =
           *(ushort *)((int)puVar3 + 6) >> 8 | *(ushort *)((int)puVar3 + 6) << 8;
      if ((ushort)uVar2 < 0xc) {
        return;
      }
    } while (iVar4 < *(int *)(param_1 + 0x14));
  }
  return;
}

