/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00115a7f */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

undefined4 __analysis_fragment_00115a7f(void)

{
  ushort uVar1;
  code *pcVar2;
  short sVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  int unaff_EDI;
  
  do {
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
LAB_00115b1f:
    if (*(short *)(unaff_EDI + 0x58) != 0) {
      if ((*(byte *)(unaff_EBP + 0x14) & 2) == 0) {
        sVar3 = *(short *)(unaff_EDI + 0x58) - (short)unaff_ESI;
        *(short *)(unaff_EDI + 0x58) = sVar3;
        if (sVar3 == 0) {
          *(byte *)(unaff_EDI + 6) = *(byte *)(unaff_EDI + 6) | 0x40;
          goto LAB_00115b5a;
        }
      }
      else {
        *(int *)(unaff_EBP + -0xc) = *(int *)(unaff_EBP + -0xc) + unaff_ESI;
      }
    }
    if (((unaff_EBX == (undefined4 *)0x0) || (*(int *)(*(int *)(unaff_EBP + 0x10) + 0x14) < 1)) ||
       (*(int *)(unaff_EBP + -4) != 0)) {
LAB_00115b5a:
      if ((*(uint *)(unaff_EBP + 0x14) & 2) == 0) {
        if (unaff_EBX == (undefined4 *)0x0) {
          *(undefined4 *)(unaff_EDI + 0x30) = *(undefined4 *)(unaff_EBP + -0x14);
        }
        else if ((*(byte *)(*(int *)(unaff_EBP + -0x10) + 10) & 1) != 0) {
          _sbdroprecord();
        }
        if (((*(byte *)(*(int *)(unaff_EBP + -0x10) + 10) & 8) != 0) &&
           (*(int *)(unaff_EDI + 8) != 0)) {
          (**(code **)(*(int *)(unaff_EBP + -0x10) + 0x1c))();
        }
        if ((((*(int *)(unaff_EBP + -4) == 0) && (*(int *)(unaff_EBP + 0x18) != 0)) &&
            (**(int **)(unaff_EBP + 0x18) != 0)) &&
           (pcVar2 = *(code **)(*(int *)(*(int *)(unaff_EBP + -0x10) + 4) + 0xc),
           pcVar2 != (code *)0x0)) {
          uVar5 = (*pcVar2)();
          *(undefined4 *)(unaff_EBP + -4) = uVar5;
        }
      }
      uVar1 = *(ushort *)(unaff_EDI + 0x38);
      *(ushort *)(unaff_EDI + 0x38) = uVar1 & 0xfffe;
      if ((uVar1 & 2) != 0) {
        *(ushort *)(unaff_EDI + 0x38) = uVar1 & 0xfffc;
        _wakeup();
      }
      _splx();
      return *(undefined4 *)(unaff_EBP + -4);
    }
    if (1 < (ushort)(*(short *)((int)unaff_EBX + 10) - 1U)) {
                    /* WARNING: Subroutine does not return */
      _panic(s_receive_3_001db33b);
    }
    unaff_ESI = *(int *)(*(int *)(unaff_EBP + 0x10) + 0x14);
    *(byte *)(unaff_EDI + 6) = *(byte *)(unaff_EDI + 6) & 0xbf;
    if ((*(ushort *)(unaff_EDI + 0x58) != 0) &&
       (iVar4 = (uint)*(ushort *)(unaff_EDI + 0x58) - *(int *)(unaff_EBP + -0xc), iVar4 < unaff_ESI)
       ) {
      unaff_ESI = iVar4;
    }
    iVar4 = (int)*(short *)(unaff_EBX + 2) - *(int *)(unaff_EBP + -0x18);
    if (iVar4 < unaff_ESI) {
      unaff_ESI = iVar4;
    }
    _splx();
    uVar5 = _uiomove((int)unaff_EBX + *(int *)(unaff_EBP + -0x18) + unaff_EBX[1],unaff_ESI,0,
                     *(undefined4 *)(unaff_EBP + 0x10));
    *(undefined4 *)(unaff_EBP + -4) = uVar5;
    uVar5 = _splnet();
    *(undefined4 *)(unaff_EBP + -8) = uVar5;
    sVar3 = *(short *)(unaff_EBX + 2);
    if (unaff_ESI != (int)sVar3 - *(int *)(unaff_EBP + -0x18)) {
      if ((*(byte *)(unaff_EBP + 0x14) & 2) == 0) {
        unaff_EBX[1] = unaff_EBX[1] + unaff_ESI;
        *(short *)(unaff_EBX + 2) = *(short *)(unaff_EBX + 2) - (short)unaff_ESI;
        *(short *)(unaff_EDI + 0x24) = *(short *)(unaff_EDI + 0x24) - (short)unaff_ESI;
      }
      else {
        *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + unaff_ESI;
      }
      goto LAB_00115b1f;
    }
    if ((*(byte *)(unaff_EBP + 0x14) & 2) != 0) {
      unaff_EBX = (undefined4 *)*unaff_EBX;
      *(undefined4 *)(unaff_EBP + -0x18) = 0;
      goto LAB_00115b1f;
    }
    *(undefined4 *)(unaff_EBP + -0x14) = unaff_EBX[0x1f];
    *(short *)(unaff_EDI + 0x24) = *(short *)(unaff_EDI + 0x24) - sVar3;
    sVar3 = *(short *)(unaff_EDI + 0x28);
    *(short *)(unaff_EDI + 0x28) = sVar3 + -0x80;
    if (0x7c < (uint)unaff_EBX[1]) {
      *(short *)(unaff_EDI + 0x28) = sVar3 + -0x480;
    }
    uVar5 = _splimp();
    *(undefined4 *)(unaff_EBP + -0x1c) = uVar5;
    if (*(short *)((int)unaff_EBX + 10) == 0) {
                    /* WARNING: Subroutine does not return */
      _panic(s_mfree_001db345);
    }
  } while( true );
}

