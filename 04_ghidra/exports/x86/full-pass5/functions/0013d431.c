/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0013d431 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_0013d431(void)

{
  int *piVar1;
  byte *pbVar2;
  char cVar3;
  int iVar4;
  byte bVar5;
  uint uVar6;
  int unaff_EBX;
  int unaff_EBP;
  uint unaff_EDI;
  int iStack00000008;
  uint uStack0000000c;
  byte *pbStack00000010;
  
  uVar6 = unaff_EDI / *(uint *)(unaff_EBX + 0xb8);
  *(uint *)(unaff_EBP + -0x10) = uVar6;
  pbStack00000010 = *(byte **)(unaff_EBX + 0xa0);
  *(uint *)(unaff_EBP + -0x20) = uVar6 * *(int *)(unaff_EBX + 0xbc);
  uStack0000000c =
       *(int *)(unaff_EBP + -0x20) +
       (~*(uint *)(unaff_EBX + 0x1c) & *(uint *)(unaff_EBP + -0x10)) * *(int *)(unaff_EBX + 0x18) +
       *(int *)(unaff_EBX + 0xc) << ((byte)*(undefined4 *)(unaff_EBX + 100) & 0x1f);
  iStack00000008 = *(undefined4 *)(*(int *)(unaff_EBP + 8) + 0x40);
  pbStack00000010 = (byte *)_bread();
  *(byte **)(unaff_EBP + -0xc) = pbStack00000010;
  iVar4 = *(int *)(pbStack00000010 + 0x20);
  if ((*pbStack00000010 & 4) == 0) {
    uStack0000000c = 0x13d4a2;
    pbStack00000010 = (byte *)iVar4;
    _byte_swap_cylgroup();
    if (*(int *)(iVar4 + 0x3d4) == 0x90255) {
      *(undefined4 *)(unaff_EBP + -0x24) = 1;
    }
    else {
      uStack0000000c = 0x13d4b7;
      pbStack00000010 = (byte *)iVar4;
      _byte_swap_cylgroup();
      uStack0000000c = *(undefined4 *)(unaff_EBP + -0xc);
      iStack00000008 = 0x13d4c0;
      _brelse();
      *(undefined4 *)(unaff_EBP + -0x24) = 0;
    }
  }
  else {
    uStack0000000c = 0x13d48e;
    _brelse();
    *(undefined4 *)(unaff_EBP + -0x24) = 0;
  }
  if (*(int *)(unaff_EBP + -0x24) != 0) {
    pbStack00000010 = (byte *)(unaff_EBP + -8);
    uStack0000000c = 0x13d4e6;
    _getthetime();
    *(undefined4 *)(iVar4 + 8) = *(undefined4 *)(unaff_EBP + -8);
    uStack0000000c = unaff_EDI % *(uint *)(unaff_EBX + 0xb8);
    *(uint *)(unaff_EBP + -0x14) = uStack0000000c >> 3;
    cVar3 = *(char *)(iVar4 + 0x2d4 + (uStack0000000c >> 3));
    *(uint *)(unaff_EBP + -0x18) = uStack0000000c & 7;
    if (((uint)(int)cVar3 >> (uStack0000000c & 7) & 1) == 0) {
      pbStack00000010 = (byte *)(unaff_EBX + 0xd4);
      iStack00000008 = (int)*(short *)(*(int *)(unaff_EBP + 8) + 0x46);
      _printf(s_dev___0x_x__ino____d__fs____s_001ddd54);
                    /* WARNING: Subroutine does not return */
      _panic(s_ifree__freeing_free_inode_001ddd73);
    }
    bVar5 = (byte)*(undefined4 *)(unaff_EBP + -0x18) & 0x1f;
    pbVar2 = (byte *)(iVar4 + 0x2d4 + *(int *)(unaff_EBP + -0x14));
    *pbVar2 = *pbVar2 & ((byte)(-2 << bVar5) | (byte)(0xfffffffe >> 0x20 - bVar5));
    if (uStack0000000c < *(uint *)(iVar4 + 0x30)) {
      *(uint *)(iVar4 + 0x30) = uStack0000000c;
    }
    *(int *)(iVar4 + 0x20) = *(int *)(iVar4 + 0x20) + 1;
    *(int *)(unaff_EBX + 200) = *(int *)(unaff_EBX + 200) + 1;
    piVar1 = (int *)(*(int *)(unaff_EBX + 0x2d8 +
                             (*(int *)(unaff_EBP + -0x10) >>
                             ((byte)*(undefined4 *)(unaff_EBX + 0x70) & 0x1f)) * 4) + 8 +
                    (~*(uint *)(unaff_EBX + 0x6c) & *(uint *)(unaff_EBP + -0x10)) * 0x10);
    *piVar1 = *piVar1 + 1;
    if ((*(uint *)(unaff_EBP + 0x10) & 0xf000) == 0x4000) {
      *(int *)(iVar4 + 0x18) = *(int *)(iVar4 + 0x18) + -1;
      *(int *)(unaff_EBX + 0xc0) = *(int *)(unaff_EBX + 0xc0) + -1;
      piVar1 = (int *)(*(int *)(unaff_EBX + 0x2d8 +
                               (*(int *)(unaff_EBP + -0x10) >>
                               ((byte)*(undefined4 *)(unaff_EBX + 0x70) & 0x1f)) * 4) +
                      (~*(uint *)(unaff_EBX + 0x6c) & *(uint *)(unaff_EBP + -0x10)) * 0x10);
      *piVar1 = *piVar1 + -1;
    }
    *(char *)(unaff_EBX + 0xd0) = *(char *)(unaff_EBX + 0xd0) + '\x01';
    uStack0000000c = 0x13d5c1;
    pbStack00000010 = (byte *)iVar4;
    _byte_swap_cylgroup();
    uStack0000000c = *(undefined4 *)(unaff_EBP + -0xc);
    iStack00000008 = 0x13d5ca;
    _bdwrite();
    if (((*(byte *)(unaff_EBX + 0xd3) & 2) != 0) &&
       (*(int *)(unaff_EBX + 0x90) < *(int *)(unaff_EBX + 200))) {
      pbStack00000010 = (byte *)(unaff_EBX + 200);
      uStack0000000c = 0x13d5f0;
      _wakeup();
      *(byte *)(unaff_EBX + 0xd3) = *(byte *)(unaff_EBX + 0xd3) & 0xfd;
    }
  }
  return;
}

