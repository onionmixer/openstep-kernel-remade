/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001159ba */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

undefined4 __analysis_fragment_001159ba(void)

{
  short sVar1;
  ushort uVar2;
  code *pcVar3;
  short sVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 *unaff_EBX;
  int unaff_EBP;
  int iVar7;
  int unaff_EDI;
  
  while( true ) {
    iVar7 = *(int *)(*(int *)(unaff_EBP + 0x10) + 0x14);
    *(byte *)(unaff_EDI + 6) = *(byte *)(unaff_EDI + 6) & 0xbf;
    if ((*(ushort *)(unaff_EDI + 0x58) != 0) &&
       (iVar5 = (uint)*(ushort *)(unaff_EDI + 0x58) - *(int *)(unaff_EBP + -0xc), iVar5 < iVar7)) {
      iVar7 = iVar5;
    }
    iVar5 = (int)*(short *)(unaff_EBX + 2) - *(int *)(unaff_EBP + -0x18);
    if (iVar5 < iVar7) {
      iVar7 = iVar5;
    }
    _splx();
    uVar6 = _uiomove((int)unaff_EBX + *(int *)(unaff_EBP + -0x18) + unaff_EBX[1],iVar7,0,
                     *(undefined4 *)(unaff_EBP + 0x10));
    *(undefined4 *)(unaff_EBP + -4) = uVar6;
    uVar6 = _splnet();
    *(undefined4 *)(unaff_EBP + -8) = uVar6;
    sVar1 = *(short *)(unaff_EBX + 2);
    sVar4 = (short)iVar7;
    if (iVar7 == (int)sVar1 - *(int *)(unaff_EBP + -0x18)) {
      if ((*(byte *)(unaff_EBP + 0x14) & 2) == 0) {
        *(undefined4 *)(unaff_EBP + -0x14) = unaff_EBX[0x1f];
        *(short *)(unaff_EDI + 0x24) = *(short *)(unaff_EDI + 0x24) - sVar1;
        sVar1 = *(short *)(unaff_EDI + 0x28);
        *(short *)(unaff_EDI + 0x28) = sVar1 + -0x80;
        if (0x7c < (uint)unaff_EBX[1]) {
          *(short *)(unaff_EDI + 0x28) = sVar1 + -0x480;
        }
        uVar6 = _splimp();
        *(undefined4 *)(unaff_EBP + -0x1c) = uVar6;
        if (*(short *)((int)unaff_EBX + 10) == 0) {
                    /* WARNING: Subroutine does not return */
          _panic(s_mfree_001db345);
        }
        *(short *)(&DAT_001e917c + *(short *)((int)unaff_EBX + 10) * 2) =
             *(short *)(&DAT_001e917c + *(short *)((int)unaff_EBX + 10) * 2) + -1;
        _DAT_001e917c = _DAT_001e917c + 1;
        *(undefined2 *)((int)unaff_EBX + 10) = 0;
        if (0x7f < (uint)unaff_EBX[1]) {
          _mclput();
        }
        *(undefined4 *)(unaff_EDI + 0x30) = *unaff_EBX;
        *unaff_EBX = _mfree;
        unaff_EBX[1] = 0;
        unaff_EBX[0x1f] = 0;
        _mfree = unaff_EBX;
        _splx();
        if (_m_want != 0) {
          _m_want = 0;
          _wakeup();
        }
        unaff_EBX = *(undefined4 **)(unaff_EDI + 0x30);
        if (unaff_EBX != (undefined4 *)0x0) {
          unaff_EBX[0x1f] = *(undefined4 *)(unaff_EBP + -0x14);
        }
      }
      else {
        unaff_EBX = (undefined4 *)*unaff_EBX;
        *(undefined4 *)(unaff_EBP + -0x18) = 0;
      }
    }
    else if ((*(byte *)(unaff_EBP + 0x14) & 2) == 0) {
      unaff_EBX[1] = unaff_EBX[1] + iVar7;
      *(short *)(unaff_EBX + 2) = *(short *)(unaff_EBX + 2) - sVar4;
      *(short *)(unaff_EDI + 0x24) = *(short *)(unaff_EDI + 0x24) - sVar4;
    }
    else {
      *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + iVar7;
    }
    if (*(short *)(unaff_EDI + 0x58) != 0) {
      if ((*(byte *)(unaff_EBP + 0x14) & 2) == 0) {
        sVar4 = *(short *)(unaff_EDI + 0x58) - sVar4;
        *(short *)(unaff_EDI + 0x58) = sVar4;
        if (sVar4 == 0) {
          *(byte *)(unaff_EDI + 6) = *(byte *)(unaff_EDI + 6) | 0x40;
          break;
        }
      }
      else {
        *(int *)(unaff_EBP + -0xc) = *(int *)(unaff_EBP + -0xc) + iVar7;
      }
    }
    if (((unaff_EBX == (undefined4 *)0x0) || (*(int *)(*(int *)(unaff_EBP + 0x10) + 0x14) < 1)) ||
       (*(int *)(unaff_EBP + -4) != 0)) break;
    if (1 < (ushort)(*(short *)((int)unaff_EBX + 10) - 1U)) {
                    /* WARNING: Subroutine does not return */
      _panic(s_receive_3_001db33b);
    }
  }
  if ((*(uint *)(unaff_EBP + 0x14) & 2) == 0) {
    if (unaff_EBX == (undefined4 *)0x0) {
      *(undefined4 *)(unaff_EDI + 0x30) = *(undefined4 *)(unaff_EBP + -0x14);
    }
    else if ((*(byte *)(*(int *)(unaff_EBP + -0x10) + 10) & 1) != 0) {
      _sbdroprecord();
    }
    if (((*(byte *)(*(int *)(unaff_EBP + -0x10) + 10) & 8) != 0) && (*(int *)(unaff_EDI + 8) != 0))
    {
      (**(code **)(*(int *)(unaff_EBP + -0x10) + 0x1c))();
    }
    if (((*(int *)(unaff_EBP + -4) == 0) && (*(int *)(unaff_EBP + 0x18) != 0)) &&
       ((**(int **)(unaff_EBP + 0x18) != 0 &&
        (pcVar3 = *(code **)(*(int *)(*(int *)(unaff_EBP + -0x10) + 4) + 0xc), pcVar3 != (code *)0x0
        )))) {
      uVar6 = (*pcVar3)();
      *(undefined4 *)(unaff_EBP + -4) = uVar6;
    }
  }
  uVar2 = *(ushort *)(unaff_EDI + 0x38);
  *(ushort *)(unaff_EDI + 0x38) = uVar2 & 0xfffe;
  if ((uVar2 & 2) != 0) {
    *(ushort *)(unaff_EDI + 0x38) = uVar2 & 0xfffc;
    _wakeup();
  }
  _splx();
  return *(undefined4 *)(unaff_EBP + -4);
}

