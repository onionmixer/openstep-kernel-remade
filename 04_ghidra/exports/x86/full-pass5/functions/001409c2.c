/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001409c2 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_001409c2(void)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  byte *pbVar4;
  int *unaff_EBX;
  int unaff_EBP;
  int iVar5;
  int *unaff_EDI;
  
  *(int *)(*unaff_EBX + 4) = unaff_EBX[1];
  *(int *)unaff_EBX[1] = *unaff_EBX;
  *unaff_EBX = *unaff_EDI;
  unaff_EBX[1] = (int)unaff_EDI;
  *(int **)(*unaff_EDI + 4) = unaff_EBX;
  *unaff_EDI = (int)unaff_EBX;
  *(undefined2 *)((int)unaff_EBX + 0x46) = *(undefined2 *)(unaff_EBP + -4);
  unaff_EBX[0x10] = *(int *)(*(int *)(unaff_EBP + -8) + 8);
  unaff_EBX[0x12] = *(int *)(unaff_EBP + 0x10);
  unaff_EBX[0x13] = 0;
  unaff_EBX[0x14] = *(int *)(unaff_EBP + 0xc);
  unaff_EBX[0x16] = 0;
  iVar5 = *(int *)(unaff_EBP + 0xc);
  uVar2 = *(uint *)(iVar5 + 0xb8);
  uVar3 = *(uint *)(unaff_EBP + 0x10) / uVar2;
  *(uint *)(unaff_EBP + -0x10) = *(int *)(iVar5 + 0xbc) * uVar3;
  *(uint *)(unaff_EBP + -0x10) =
       *(int *)(unaff_EBP + -0x10) + (uVar3 & ~*(uint *)(iVar5 + 0x1c)) * *(int *)(iVar5 + 0x18) +
       *(int *)(iVar5 + 0x10);
  iVar5 = (int)(((ulonglong)*(uint *)(unaff_EBP + 0x10) % (ulonglong)uVar2) /
               (ulonglong)*(uint *)(iVar5 + 0x78)) << ((byte)*(undefined4 *)(iVar5 + 0x60) & 0x1f);
  *(int *)(unaff_EBP + -0xc) = iVar5;
  pbVar4 = (byte *)_bread(unaff_EBX[0x10],
                          *(int *)(unaff_EBP + -0x10) + iVar5 <<
                          ((byte)*(undefined4 *)(*(int *)(unaff_EBP + 0xc) + 100) & 0x1f));
  if ((*pbVar4 & 4) == 0) {
    _byte_swap_inode_in((*(uint *)(unaff_EBP + 0x10) % *(uint *)(*(int *)(unaff_EBP + 0xc) + 0x78))
                        * 0x80 + *(int *)(pbVar4 + 0x20));
    *(undefined2 *)(unaff_EBX + 4) = 0;
    *(undefined2 *)((int)unaff_EBX + 0x12) = 1;
    *(undefined2 *)((int)unaff_EBX + 0x16) = 0;
    *(undefined2 *)(unaff_EBX + 5) = 0;
    unaff_EBX[0xc] = **(int **)(unaff_EBP + -8);
    unaff_EBX[0xd] = *(int *)(&_iftovt_tab + (uint)(*(ushort *)(unaff_EBX + 0x19) >> 0xd) * 4);
    *(short *)(unaff_EBX + 0xe) = (short)unaff_EBX[0x23];
    unaff_EBX[0xb] = 0;
    unaff_EBX[9] = 0;
    unaff_EBX[8] = 0;
    if (*(int *)(unaff_EBP + 0x10) == 2) {
      *(byte *)(unaff_EBX + 4) = *(byte *)(unaff_EBX + 4) | 1;
    }
    if (*(short *)(unaff_EBX[0xc] + 0x124) != 0) {
      *(short *)(unaff_EBX + 0x39) = (short)unaff_EBX[0x1a];
      *(undefined2 *)((int)unaff_EBX + 0xe6) = *(undefined2 *)((int)unaff_EBX + 0x6a);
      *(undefined2 *)(unaff_EBX + 0x1a) = *(undefined2 *)(unaff_EBX[0xc] + 0x124);
      *(undefined2 *)((int)unaff_EBX + 0x6a) = _nogroup;
    }
    _brelse();
    *(undefined4 *)unaff_EBX[3] = 0;
    *(int *)(unaff_EBX[3] + 0x14) = unaff_EBX[0x1b];
  }
  else {
    _brelse();
    *(int *)(*unaff_EBX + 4) = unaff_EBX[1];
    *(int *)unaff_EBX[1] = *unaff_EBX;
    *unaff_EBX = (int)unaff_EBX;
    unaff_EBX[1] = (int)unaff_EBX;
    unaff_EBX[0x12] = 0;
    *(undefined2 *)((int)unaff_EBX + 0x12) = 0;
    uVar1 = *(ushort *)(unaff_EBX + 0x11);
    *(ushort *)(unaff_EBX + 0x11) = uVar1 & 0xfffe;
    if ((uVar1 & 0x10) != 0) {
      *(ushort *)(unaff_EBX + 0x11) = uVar1 & 0xffee;
      _wakeup();
    }
    *(undefined2 *)(unaff_EBX + 0x11) = 0;
    if (_ifreeh == (int *)0x0) {
      _ifreeh = unaff_EBX;
      unaff_EBX[0x18] = (int)&_ifreeh;
    }
    else {
      *_ifreet = (int)unaff_EBX;
      unaff_EBX[0x18] = (int)_ifreet;
    }
    unaff_EBX[0x17] = 0;
    _ifreet = unaff_EBX + 0x17;
  }
  return;
}

