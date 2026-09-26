/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00192e28 */

void FUN_00192e28(int param_1)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(param_1 + 0x30);
  *(uint *)(param_1 + 0x30) =
       uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
  uVar3 = *(uint *)(param_1 + 0x34);
  *(uint *)(param_1 + 0x34) =
       uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
  uVar3 = *(uint *)(param_1 + 0x38);
  *(uint *)(param_1 + 0x38) =
       uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
  uVar3 = *(uint *)(param_1 + 0x3c);
  *(uint *)(param_1 + 0x3c) =
       uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
  uVar3 = *(uint *)(param_1 + 0x40);
  *(uint *)(param_1 + 0x40) =
       uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
  *(ushort *)(param_1 + 0x44) = *(ushort *)(param_1 + 0x44) >> 8 | *(ushort *)(param_1 + 0x44) << 8;
  *(ushort *)(param_1 + 0x46) = *(ushort *)(param_1 + 0x46) >> 8 | *(ushort *)(param_1 + 0x46) << 8;
  *(ushort *)(param_1 + 0x48) = *(ushort *)(param_1 + 0x48) >> 8 | *(ushort *)(param_1 + 0x48) << 8;
  *(ushort *)(param_1 + 0x4a) = *(ushort *)(param_1 + 0x4a) >> 8 | *(ushort *)(param_1 + 0x4a) << 8;
  *(ushort *)(param_1 + 0x4c) = *(ushort *)(param_1 + 0x4c) >> 8 | *(ushort *)(param_1 + 0x4c) << 8;
  *(ushort *)(param_1 + 0x4e) = *(ushort *)(param_1 + 0x4e) >> 8 | *(ushort *)(param_1 + 0x4e) << 8;
  iVar1 = 0;
  puVar2 = (uint *)(param_1 + 0x50);
  do {
    uVar3 = *puVar2;
    *puVar2 = uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
    puVar2 = puVar2 + 1;
    iVar1 = iVar1 + 1;
  } while (iVar1 < 2);
  uVar3 = 0;
  iVar1 = 0x94;
  do {
    _byte_swap_partition(iVar1 + param_1);
    iVar1 = iVar1 + 0x30;
    uVar3 = uVar3 + 1;
  } while (uVar3 < 8);
  return;
}

