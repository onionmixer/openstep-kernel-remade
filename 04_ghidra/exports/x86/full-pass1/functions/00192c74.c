/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00192c74 */

void _byte_swap_superblock(int param_1)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  ushort *puVar4;
  
  iVar2 = 0;
  puVar3 = (uint *)(param_1 + 8);
  do {
    uVar1 = *puVar3;
    *puVar3 = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
    puVar3 = puVar3 + 1;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x32);
  uVar1 = *(uint *)(param_1 + 0x2d4);
  *(uint *)(param_1 + 0x2d4) =
       uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
  uVar1 = *(uint *)(param_1 + 0x358);
  *(uint *)(param_1 + 0x358) =
       uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
  iVar2 = 0;
  puVar4 = (ushort *)(param_1 + 0x35c);
  do {
    *puVar4 = *puVar4 >> 8 | *puVar4 << 8;
    puVar4 = puVar4 + 1;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x100);
  uVar1 = *(uint *)(param_1 + 0x55c);
  *(uint *)(param_1 + 0x55c) =
       uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
  return;
}

