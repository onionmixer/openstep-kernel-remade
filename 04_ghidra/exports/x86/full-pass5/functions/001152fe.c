/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001152fe */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

undefined4 __analysis_fragment_001152fe(void)

{
  byte *pbVar1;
  ushort uVar2;
  int iVar3;
  undefined4 *puVar4;
  ushort uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int unaff_EBP;
  undefined4 *unaff_ESI;
  int iVar8;
  int unaff_EDI;
  
LAB_00115301:
  *(undefined2 *)((int)unaff_ESI + 10) = 1;
  _DAT_001e917c = _DAT_001e917c + -1;
  _DAT_001e917e = _DAT_001e917e + 1;
  _mfree = (undefined4 *)*unaff_ESI;
  *unaff_ESI = 0;
  unaff_ESI[1] = 0xc;
  do {
    _splx();
    if ((*(int *)(*(int *)(unaff_EBP + 0x10) + 0x14) < 0x200) || (unaff_EDI < 0x400)) {
LAB_001153f8:
      iVar3 = *(int *)(*(int *)(unaff_EBP + 0x10) + 0x14);
      iVar8 = unaff_EDI;
      if (iVar3 < 0x71) {
        if (iVar3 < unaff_EDI) {
LAB_00115411:
          iVar3 = *(int *)(*(int *)(unaff_EBP + 0x10) + 0x14);
          iVar8 = 0x70;
          if (iVar3 < 0x71) {
            iVar8 = iVar3;
          }
        }
      }
      else if (0x70 < unaff_EDI) goto LAB_00115411;
      unaff_EDI = unaff_EDI - iVar8;
    }
    else {
      uVar6 = _splimp();
      *(undefined4 *)(unaff_EBP + -0x28) = uVar6;
      if (_mclfree == (undefined4 *)0x0) {
        _m_clalloc(1,1);
      }
      puVar4 = _mclfree;
      if (_mclfree != (undefined4 *)0x0) {
        (&_mclrefcnt)[(int)_mclfree - __mbutl >> 10] =
             (&_mclrefcnt)[(int)_mclfree - __mbutl >> 10] + '\x01';
        _DAT_001e916c = _DAT_001e916c + -1;
        _mclfree = (undefined4 *)*_mclfree;
      }
      _splx();
      if (puVar4 == (undefined4 *)0x0) {
        *(undefined2 *)(unaff_ESI + 2) = 0x70;
      }
      else {
        unaff_ESI[1] = (int)puVar4 - (int)unaff_ESI;
        *(undefined2 *)(unaff_ESI + 2) = 0x400;
        *(undefined2 *)(unaff_ESI + 3) = 1;
      }
      if (*(short *)(unaff_ESI + 2) != 0x400) goto LAB_001153f8;
      iVar3 = *(int *)(*(int *)(unaff_EBP + 0x10) + 0x14);
      iVar8 = 0x400;
      if (iVar3 < 0x401) {
        iVar8 = iVar3;
      }
      unaff_EDI = unaff_EDI + -0x400;
    }
    uVar6 = _uiomove((int)unaff_ESI + unaff_ESI[1],iVar8,1);
    *(undefined4 *)(unaff_EBP + -0x10) = uVar6;
    *(short *)(unaff_ESI + 2) = (short)iVar8;
    **(undefined4 **)(unaff_EBP + -8) = unaff_ESI;
    if (*(int *)(unaff_EBP + -0x10) != 0) {
LAB_001154f3:
      iVar3 = *(int *)(unaff_EBP + 8);
      uVar5 = *(ushort *)(iVar3 + 0x50);
      *(ushort *)(iVar3 + 0x50) = uVar5 & 0xfffe;
      if ((uVar5 & 2) != 0) {
        *(ushort *)(iVar3 + 0x50) = uVar5 & 0xfffc;
        _wakeup();
      }
      if (*(int *)(unaff_EBP + -4) != 0) {
        _m_freem();
      }
      if (*(int *)(unaff_EBP + -0x10) == 0x20) {
        _exception_from_kernel(5,0x10001);
      }
      return *(undefined4 *)(unaff_EBP + -0x10);
    }
    *(undefined4 **)(unaff_EBP + -8) = unaff_ESI;
    if (*(int *)(*(int *)(unaff_EBP + 0x10) + 0x14) < 1) goto LAB_0011546b;
    while (unaff_EDI < 1) {
LAB_0011546b:
      if (*(int *)(unaff_EBP + -0x14) != 0) {
        pbVar1 = (byte *)(*(int *)(unaff_EBP + 8) + 2);
        *pbVar1 = *pbVar1 | 0x10;
      }
      uVar6 = _splnet();
      uVar7 = 9;
      if ((*(byte *)(unaff_EBP + 0x14) & 1) != 0) {
        uVar7 = 0xe;
      }
      uVar7 = (**(code **)(*(int *)(*(int *)(unaff_EBP + 8) + 0xc) + 0x1c))
                        (*(undefined4 *)(unaff_EBP + 8),uVar7,*(undefined4 *)(unaff_EBP + -4),
                         *(undefined4 *)(unaff_EBP + 0xc));
      *(undefined4 *)(unaff_EBP + -0x10) = uVar7;
      _splx(uVar6);
      if (*(int *)(unaff_EBP + -0x14) != 0) {
        pbVar1 = (byte *)(*(int *)(unaff_EBP + 8) + 2);
        *pbVar1 = *pbVar1 & 0xef;
      }
      *(undefined4 *)(unaff_EBP + 0x18) = 0;
      *(undefined4 *)(unaff_EBP + -0xc) = 0;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      *(undefined4 *)(unaff_EBP + -0x18) = 0;
      if ((*(int *)(unaff_EBP + -0x10) != 0) || (*(int *)(*(int *)(unaff_EBP + 0x10) + 0x14) == 0))
      goto LAB_001154f3;
LAB_00115164:
      uVar6 = _splnet();
      uVar5 = *(ushort *)(*(int *)(unaff_EBP + 8) + 6);
      *(ushort *)(unaff_EBP + -0x1c) = uVar5;
      if ((uVar5 & 0x10) != 0) {
        *(undefined4 *)(unaff_EBP + -0x10) = 0x20;
LAB_0011526b:
        _splx();
        goto LAB_001154f3;
      }
      uVar2 = *(ushort *)(*(int *)(unaff_EBP + 8) + 0x56);
      if (uVar2 != 0) {
        *(uint *)(unaff_EBP + -0x10) = (uint)uVar2;
        *(undefined2 *)(*(int *)(unaff_EBP + 8) + 0x56) = 0;
        goto LAB_0011526b;
      }
      if ((uVar5 & 2) == 0) {
        if ((*(byte *)(*(int *)(*(int *)(unaff_EBP + 8) + 0xc) + 10) & 4) == 0) {
          if (*(int *)(unaff_EBP + 0xc) != 0) goto LAB_001151ab;
          *(undefined4 *)(unaff_EBP + -0x10) = 0x27;
        }
        else {
          *(undefined4 *)(unaff_EBP + -0x10) = 0x39;
        }
        goto LAB_0011526b;
      }
LAB_001151ab:
      if ((*(byte *)(unaff_EBP + 0x14) & 1) == 0) {
        iVar3 = *(int *)(unaff_EBP + 8);
        *(uint *)(unaff_EBP + -0x24) =
             (uint)*(ushort *)(*(int *)(unaff_EBP + 8) + 0x42) - (uint)*(ushort *)(iVar3 + 0x40);
        iVar8 = (uint)*(ushort *)(iVar3 + 0x3e) - (uint)*(ushort *)(iVar3 + 0x3c);
        if (*(int *)(unaff_EBP + -0x24) < iVar8) {
          iVar8 = *(int *)(unaff_EBP + -0x24);
        }
        if (((*(int *)(unaff_EBP + -0xc) < iVar8) &&
            (((*(byte *)(*(int *)(*(int *)(unaff_EBP + 8) + 0xc) + 10) & 1) == 0 ||
             (*(int *)(unaff_EBP + -0xc) + *(int *)(*(int *)(unaff_EBP + 0x10) + 0x14) <= iVar8))))
           && ((*(int *)(*(int *)(unaff_EBP + 0x10) + 0x14) < 0x400 ||
               (((0x3ff < iVar8 || (*(ushort *)(iVar3 + 0x3c) < 0x400)) ||
                ((*(ushort *)(unaff_EBP + -0x1c) & 0x100) != 0)))))) goto LAB_001152c0;
        if ((*(byte *)(*(int *)(unaff_EBP + 8) + 7) & 1) != 0) {
          if (((*(int *)(unaff_EBP + -0x18) != 0) &&
              (iVar3 = *_active_u, *(undefined4 *)(unaff_EBP + -0x10) = 0x23,
              (*(byte *)(iVar3 + 0x16) & 2) != 0)) &&
             ((*(byte *)(*(int *)(unaff_EBP + 0x10) + 0x11) & 0x20) != 0)) {
            *(undefined4 *)(unaff_EBP + -0x10) = 0xb;
          }
          goto LAB_0011526b;
        }
        iVar3 = *(int *)(unaff_EBP + 8);
        uVar5 = *(ushort *)(iVar3 + 0x50);
        *(ushort *)(iVar3 + 0x50) = uVar5 & 0xfffe;
        if ((uVar5 & 2) != 0) {
          *(ushort *)(iVar3 + 0x50) = uVar5 & 0xfffc;
          _wakeup();
        }
        _sbwait();
        _splx(uVar6);
        iVar3 = *(int *)(unaff_EBP + 8);
        uVar5 = *(ushort *)(iVar3 + 0x50);
        if ((uVar5 & 1) != 0) {
          do {
            *(ushort *)(*(int *)(unaff_EBP + 8) + 0x50) = uVar5 | 2;
            _sleep(iVar3 + 0x50);
            uVar5 = *(ushort *)(*(int *)(unaff_EBP + 8) + 0x50);
          } while ((uVar5 & 1) != 0);
        }
        pbVar1 = (byte *)(*(int *)(unaff_EBP + 8) + 0x50);
        *pbVar1 = *pbVar1 | 1;
        goto LAB_00115164;
      }
      iVar8 = 0x400;
LAB_001152c0:
      _splx();
      *(int *)(unaff_EBP + -8) = unaff_EBP + -4;
      unaff_EDI = iVar8 - *(int *)(unaff_EBP + -0xc);
    }
    _splimp();
    if (_mfree != (undefined4 *)0x0) break;
    unaff_ESI = (undefined4 *)_m_more(1);
  } while( true );
  unaff_ESI = _mfree;
  if (*(short *)((int)_mfree + 10) != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(&DAT_001db30b);
  }
  goto LAB_00115301;
}

