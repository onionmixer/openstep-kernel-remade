/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001930b8 */

void _byte_swap_inode_in(ushort *param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  *(ushort *)(param_2 + 100) = *param_1 >> 8 | *param_1 << 8;
  *(ushort *)(param_2 + 0x66) = param_1[1] >> 8 | param_1[1] << 8;
  *(ushort *)(param_2 + 0x68) = param_1[2] >> 8 | param_1[2] << 8;
  *(ushort *)(param_2 + 0x6a) = param_1[3] >> 8 | param_1[3] << 8;
  uVar3 = *(uint *)(param_1 + 6);
  *(uint *)(param_2 + 0x6c) =
       uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
  uVar3 = *(uint *)(param_1 + 4);
  *(uint *)(param_2 + 0x70) =
       uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
  uVar3 = *(uint *)(param_1 + 8);
  *(uint *)(param_2 + 0x74) =
       uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
  uVar3 = *(uint *)(param_1 + 0xc);
  *(uint *)(param_2 + 0x7c) =
       uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
  uVar3 = *(uint *)(param_1 + 0x10);
  *(uint *)(param_2 + 0x84) =
       uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
  uVar3 = *(uint *)(param_1 + 10);
  *(uint *)(param_2 + 0x78) =
       uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
  uVar3 = *(uint *)(param_1 + 0xe);
  *(uint *)(param_2 + 0x80) =
       uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
  uVar3 = *(uint *)(param_1 + 0x12);
  *(uint *)(param_2 + 0x88) =
       uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
  uVar3 = *(uint *)(param_1 + 0x32);
  *(uint *)(param_2 + 200) =
       uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
  if ((uVar3 >> 0x18 & 1) == 0) {
    iVar2 = 0;
    do {
      uVar3 = *(uint *)(param_1 + iVar2 * 2 + 0x14);
      *(uint *)(param_2 + 0x8c + iVar2 * 4) =
           uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
      iVar2 = iVar2 + 1;
    } while (iVar2 < 0xc);
    iVar2 = 0;
    do {
      uVar3 = *(uint *)(param_1 + iVar2 * 2 + 0x2c);
      *(uint *)(param_2 + 0xbc + iVar2 * 4) =
           uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
      iVar2 = iVar2 + 1;
    } while (iVar2 < 3);
  }
  else {
    _bcopy(param_1 + 0x14,(void *)(param_2 + 0x8c),0x3c);
  }
  uVar3 = *(uint *)(param_1 + 0x34);
  *(uint *)(param_2 + 0xcc) =
       uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
  uVar3 = *(uint *)(param_1 + 0x36);
  *(uint *)(param_2 + 0xd0) =
       uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
  uVar3 = 0;
  do {
    uVar1 = *(uint *)(param_1 + uVar3 * 2 + 0x38);
    *(uint *)(param_2 + 0xd4 + uVar3 * 4) =
         uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
    uVar3 = uVar3 + 1;
  } while (uVar3 < 4);
  return;
}

