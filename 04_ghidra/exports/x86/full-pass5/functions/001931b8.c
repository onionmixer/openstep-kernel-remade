/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001931b8 */

void _byte_swap_inode_out(int param_1,ushort *param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  *param_2 = *(ushort *)(param_1 + 100) >> 8 | *(ushort *)(param_1 + 100) << 8;
  param_2[1] = *(ushort *)(param_1 + 0x66) >> 8 | *(ushort *)(param_1 + 0x66) << 8;
  param_2[2] = *(ushort *)(param_1 + 0x68) >> 8 | *(ushort *)(param_1 + 0x68) << 8;
  param_2[3] = *(ushort *)(param_1 + 0x6a) >> 8 | *(ushort *)(param_1 + 0x6a) << 8;
  uVar3 = *(uint *)(param_1 + 0x70);
  *(uint *)(param_2 + 4) =
       uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
  uVar3 = *(uint *)(param_1 + 0x6c);
  *(uint *)(param_2 + 6) =
       uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
  uVar3 = *(uint *)(param_1 + 0x74);
  *(uint *)(param_2 + 8) =
       uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
  uVar3 = *(uint *)(param_1 + 0x7c);
  *(uint *)(param_2 + 0xc) =
       uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
  uVar3 = *(uint *)(param_1 + 0x84);
  *(uint *)(param_2 + 0x10) =
       uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
  uVar3 = *(uint *)(param_1 + 0x78);
  *(uint *)(param_2 + 10) =
       uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
  uVar3 = *(uint *)(param_1 + 0x80);
  *(uint *)(param_2 + 0xe) =
       uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
  uVar3 = *(uint *)(param_1 + 0x88);
  *(uint *)(param_2 + 0x12) =
       uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
  uVar3 = *(uint *)(param_1 + 200);
  *(uint *)(param_2 + 0x32) =
       uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
  if ((*(byte *)(param_1 + 200) & 1) == 0) {
    iVar2 = 0;
    do {
      uVar3 = *(uint *)(param_1 + 0x8c + iVar2 * 4);
      *(uint *)(param_2 + iVar2 * 2 + 0x14) =
           uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
      iVar2 = iVar2 + 1;
    } while (iVar2 < 0xc);
    iVar2 = 0;
    do {
      uVar3 = *(uint *)(param_1 + 0xbc + iVar2 * 4);
      *(uint *)(param_2 + iVar2 * 2 + 0x2c) =
           uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
      iVar2 = iVar2 + 1;
    } while (iVar2 < 3);
  }
  else {
    _bcopy((void *)(param_1 + 0x8c),param_2 + 0x14,0x3c);
  }
  uVar3 = *(uint *)(param_1 + 0xcc);
  *(uint *)(param_2 + 0x34) =
       uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
  uVar3 = *(uint *)(param_1 + 0xd0);
  *(uint *)(param_2 + 0x36) =
       uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
  uVar3 = 0;
  do {
    uVar1 = *(uint *)(param_1 + 0xd4 + uVar3 * 4);
    *(uint *)(param_2 + uVar3 * 2 + 0x38) =
         uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
    uVar3 = uVar3 + 1;
  } while (uVar3 < 4);
  return;
}

