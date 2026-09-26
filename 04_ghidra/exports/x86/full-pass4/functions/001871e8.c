/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001871e8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_001871e8(void)

{
  uint uVar1;
  int iVar2;
  undefined *puVar3;
  int iVar4;
  byte bVar5;
  byte bVar6;
  
  puVar3 = _gdt;
  iVar2 = _DAT_00011378;
  iVar4 = _DAT_0001136c + -0x40000000;
  *(short *)(_gdt + 0x7a) = (short)iVar4;
  puVar3[0x7c] = (char)((uint)iVar4 >> 0x10);
  puVar3[0x7f] = (char)((uint)iVar4 >> 0x18);
  puVar3[0x7d] = 0x9a;
  bVar5 = puVar3[0x7e];
  puVar3[0x7e] = bVar5 | 0x40;
  uVar1 = iVar2 - 1;
  if (uVar1 < 0x100000) {
    puVar3[0x7e] = bVar5 & 0x7f | 0x40;
    *(short *)(puVar3 + 0x78) = (short)uVar1;
    bVar5 = (byte)(uVar1 >> 0x10) & 0xf;
  }
  else {
    uVar1 = (iVar2 + 0xfffU & 0xfffff000) - 0x1000;
    puVar3[0x7e] = bVar5 | 0xc0;
    *(short *)(puVar3 + 0x78) = (short)(uVar1 >> 0xc);
    bVar5 = (byte)(uVar1 >> 0x1c);
  }
  puVar3[0x7e] = puVar3[0x7e] & 0xf0 | bVar5;
  puVar3 = _gdt;
  iVar2 = _DAT_00011378;
  iVar4 = _DAT_00011370 + -0x40000000;
  *(short *)(_gdt + 0x82) = (short)iVar4;
  puVar3[0x84] = (char)((uint)iVar4 >> 0x10);
  puVar3[0x87] = (char)((uint)iVar4 >> 0x18);
  puVar3[0x85] = 0x9a;
  bVar5 = puVar3[0x86];
  bVar6 = bVar5 & 0xbf;
  puVar3[0x86] = bVar6;
  uVar1 = iVar2 - 1;
  if (uVar1 < 0x100000) {
    puVar3[0x86] = bVar5 & 0x3f;
    *(short *)(puVar3 + 0x80) = (short)uVar1;
    bVar5 = (byte)(uVar1 >> 0x10) & 0xf;
  }
  else {
    uVar1 = (iVar2 + 0xfffU & 0xfffff000) - 0x1000;
    puVar3[0x86] = bVar6 | 0x80;
    *(short *)(puVar3 + 0x80) = (short)(uVar1 >> 0xc);
    bVar5 = (byte)(uVar1 >> 0x1c);
  }
  puVar3[0x86] = puVar3[0x86] & 0xf0 | bVar5;
  puVar3 = _gdt;
  iVar2 = _DAT_0001137c;
  iVar4 = _DAT_00011374 + -0x40000000;
  *(short *)(_gdt + 0x8a) = (short)iVar4;
  puVar3[0x8c] = (char)((uint)iVar4 >> 0x10);
  puVar3[0x8f] = (char)((uint)iVar4 >> 0x18);
  puVar3[0x8d] = 0x92;
  bVar5 = puVar3[0x8e];
  puVar3[0x8e] = bVar5 | 0x40;
  uVar1 = iVar2 - 1;
  if (uVar1 < 0x100000) {
    puVar3[0x8e] = bVar5 & 0x7f | 0x40;
    *(short *)(puVar3 + 0x88) = (short)uVar1;
    bVar5 = (byte)(uVar1 >> 0x10) & 0xf;
  }
  else {
    uVar1 = (iVar2 + 0xfffU & 0xfffff000) - 0x1000;
    puVar3[0x8e] = bVar5 | 0xc0;
    *(short *)(puVar3 + 0x88) = (short)(uVar1 >> 0xc);
    bVar5 = (byte)(uVar1 >> 0x1c);
  }
  puVar3[0x8e] = puVar3[0x8e] & 0xf0 | bVar5;
  DAT_001e75b4 = _DAT_00011380;
  return;
}

