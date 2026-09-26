/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00129fe5 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

int __analysis_fragment_00129fe5(void)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  ushort uVar5;
  undefined2 uVar6;
  uint uVar7;
  undefined4 uVar8;
  int iVar9;
  int unaff_EBX;
  int unaff_EBP;
  int unaff_EDI;
  
  do {
    piVar2 = *(int **)(unaff_EBP + -0x14);
    *(undefined2 *)((int)piVar2 + 10) = 2;
    _DAT_001e917c = _DAT_001e917c + -1;
    _DAT_001e9180 = _DAT_001e9180 + 1;
    _mfree = *piVar2;
    *piVar2 = 0;
    piVar2[1] = 0xc;
    while( true ) {
      _splx();
      if (*(int *)(unaff_EBP + -0x14) == 0) {
        return 0x37;
      }
      iVar9 = *(int *)(unaff_EBP + -0x14);
      *(int *)(iVar9 + 4) = 0x54 - *(int *)(unaff_EBP + -0x18);
      *(undefined2 *)(iVar9 + 8) = *(undefined2 *)(unaff_EBP + -0x1c);
      if (unaff_EDI == 0) {
        if ((*(byte *)(unaff_EBX + 0x1b) & 1) == 0) {
          if ((*(uint *)(unaff_EBP + -0x10) & 7) == 0) {
            if (*(int *)(unaff_EBX + 0x2c) == *(int *)(unaff_EBX + 0x24) ||
                *(int *)(unaff_EBX + 0x2c) - *(int *)(unaff_EBX + 0x24) < 0) {
              _DAT_001eedcc = _DAT_001eedcc + 1;
            }
            else {
              _DAT_001eedc8 = _DAT_001eedc8 + 1;
            }
          }
          else {
            _DAT_001eedd0 = _DAT_001eedd0 + 1;
          }
        }
        else {
          _DAT_001eedc0 = _DAT_001eedc0 + 1;
        }
      }
      else {
        if ((*(char *)(unaff_EBX + 0x1a) == '\0') || (unaff_EDI != 1)) {
          if (*(int *)(unaff_EBX + 0x28) - *(int *)(unaff_EBX + 0x50) < 0) {
            _DAT_001eedb8 = _DAT_001eedb8 + 1;
            _DAT_001eedbc = _DAT_001eedbc + unaff_EDI;
          }
          else {
            _DAT_001eedb0 = _DAT_001eedb0 + 1;
            _DAT_001eedb4 = _DAT_001eedb4 + unaff_EDI;
          }
        }
        else {
          _DAT_001eedc4 = _DAT_001eedc4 + 1;
        }
        iVar9 = _m_copy(*(undefined4 *)(*(int *)(unaff_EBP + -4) + 0x48),
                        *(undefined4 *)(unaff_EBP + -0xc));
        **(int **)(unaff_EBP + -0x14) = iVar9;
        if (iVar9 == 0) {
          unaff_EDI = 0;
        }
        else if (*(int *)(unaff_EBP + -0xc) + unaff_EDI ==
                 (uint)*(ushort *)(*(int *)(unaff_EBP + -4) + 0x3c)) {
          *(byte *)(unaff_EBP + -0x10) = *(byte *)(unaff_EBP + -0x10) | 8;
        }
      }
      *(int *)(unaff_EBP + -0x30) =
           *(int *)(unaff_EBP + -0x14) + *(int *)(*(int *)(unaff_EBP + -0x14) + 4);
      if (*(int *)(unaff_EBX + 0x1c) == 0) {
                    /* WARNING: Subroutine does not return */
        _panic(s_tcp_output_001dbe6e);
      }
      _bcopy(*(void **)(unaff_EBX + 0x1c),*(void **)(unaff_EBP + -0x30),0x28);
      if ((((*(uint *)(unaff_EBP + -0x10) & 1) != 0) && ((*(byte *)(unaff_EBX + 0x1b) & 0x10) != 0))
         && (*(int *)(unaff_EBX + 0x50) == *(int *)(unaff_EBX + 0x28))) {
        *(int *)(unaff_EBX + 0x28) = *(int *)(unaff_EBX + 0x28) + -1;
      }
      uVar7 = *(uint *)(unaff_EBX + 0x28);
      iVar9 = *(int *)(unaff_EBP + -0x30);
      *(uint *)(iVar9 + 0x18) =
           uVar7 >> 0x18 | (uVar7 & 0xff0000) >> 8 | (uVar7 & 0xff00) << 8 | uVar7 << 0x18;
      uVar7 = *(uint *)(unaff_EBX + 0x40);
      *(uint *)(iVar9 + 0x1c) =
           uVar7 >> 0x18 | (uVar7 & 0xff0000) >> 8 | (uVar7 & 0xff00) << 8 | uVar7 << 0x18;
      if (*(int *)(unaff_EBP + -0x18) != 0) {
        _bcopy(&_tcp_initopt,(void *)(*(int *)(unaff_EBP + -0x30) + 0x28),
               *(size_t *)(unaff_EBP + -0x18));
        *(byte *)(iVar9 + 0x20) =
             *(byte *)(iVar9 + 0x20) & 0xf | (char)(*(int *)(unaff_EBP + -0x18) + 0x14U >> 2) << 4;
      }
      *(undefined1 *)(*(int *)(unaff_EBP + -0x30) + 0x21) = *(undefined1 *)(unaff_EBP + -0x10);
      if ((*(int *)(unaff_EBP + -8) < (int)(uint)(*(ushort *)(*(int *)(unaff_EBP + -4) + 0x26) >> 2)
          ) && (*(int *)(unaff_EBP + -8) < (int)(uint)*(ushort *)(unaff_EBX + 0x18))) {
        *(undefined4 *)(unaff_EBP + -8) = 0;
      }
      if (0xffff < *(int *)(unaff_EBP + -8)) {
        *(undefined4 *)(unaff_EBP + -8) = 0xffff;
      }
      iVar9 = *(int *)(unaff_EBX + 0x4c) - *(int *)(unaff_EBX + 0x40);
      if (*(int *)(unaff_EBP + -8) < iVar9) {
        *(int *)(unaff_EBP + -8) = iVar9;
      }
      iVar9 = *(int *)(unaff_EBP + -0x30);
      *(ushort *)(iVar9 + 0x22) =
           *(ushort *)(unaff_EBP + -8) >> 8 | *(ushort *)(unaff_EBP + -8) << 8;
      iVar3 = *(int *)(unaff_EBX + 0x2c);
      *(int *)(unaff_EBP + -0x2c) = iVar3;
      iVar4 = *(int *)(unaff_EBX + 0x28);
      if (iVar3 == iVar4 || iVar3 - iVar4 < 0) {
        *(undefined4 *)(unaff_EBX + 0x2c) = *(undefined4 *)(unaff_EBX + 0x24);
      }
      else {
        uVar5 = *(short *)(unaff_EBP + -0x2c) - (short)iVar4;
        *(ushort *)(iVar9 + 0x26) = uVar5 >> 8 | uVar5 * 0x100;
        *(byte *)(iVar9 + 0x21) = *(byte *)(iVar9 + 0x21) | 0x20;
      }
      if (*(int *)(unaff_EBP + -0x18) + unaff_EDI != 0) {
        uVar5 = *(short *)(unaff_EBP + -0x18) + 0x14 + (short)unaff_EDI;
        *(ushort *)(*(int *)(unaff_EBP + -0x30) + 10) = uVar5 >> 8 | uVar5 * 0x100;
      }
      uVar6 = _in_cksum(*(undefined4 *)(unaff_EBP + -0x14));
      *(undefined2 *)(*(int *)(unaff_EBP + -0x30) + 0x24) = uVar6;
      if ((*(char *)(unaff_EBX + 0x1a) == '\0') || (*(short *)(unaff_EBX + 0xc) == 0)) {
        iVar9 = *(int *)(unaff_EBX + 0x28);
        *(int *)(unaff_EBP + -0x2c) = iVar9;
        if ((*(uint *)(unaff_EBP + -0x10) & 3) != 0) {
          if ((*(uint *)(unaff_EBP + -0x10) & 2) != 0) {
            *(int *)(unaff_EBX + 0x28) = iVar9 + 1;
          }
          if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
            *(int *)(unaff_EBX + 0x28) = *(int *)(unaff_EBX + 0x28) + 1;
            *(byte *)(unaff_EBX + 0x1b) = *(byte *)(unaff_EBX + 0x1b) | 0x10;
          }
        }
        iVar9 = *(int *)(unaff_EBX + 0x28) + unaff_EDI;
        *(int *)(unaff_EBX + 0x28) = iVar9;
        if ((iVar9 != *(int *)(unaff_EBX + 0x50) && -1 < iVar9 - *(int *)(unaff_EBX + 0x50)) &&
           (*(int *)(unaff_EBX + 0x50) = iVar9, *(short *)(unaff_EBX + 0x5a) == 0)) {
          *(undefined2 *)(unaff_EBX + 0x5a) = 1;
          *(undefined4 *)(unaff_EBX + 0x5c) = *(undefined4 *)(unaff_EBP + -0x2c);
          _DAT_001eed88 = _DAT_001eed88 + 1;
        }
        if (((*(short *)(unaff_EBX + 10) == 0) &&
            (*(int *)(unaff_EBX + 0x28) != *(int *)(unaff_EBX + 0x24))) &&
           (*(undefined2 *)(unaff_EBX + 10) = *(undefined2 *)(unaff_EBX + 0x14),
           *(short *)(unaff_EBX + 0xc) != 0)) {
          *(undefined2 *)(unaff_EBX + 0xc) = 0;
          *(undefined2 *)(unaff_EBX + 0x12) = 0;
        }
      }
      else {
        iVar9 = *(int *)(unaff_EBX + 0x28) + unaff_EDI;
        if (iVar9 != *(int *)(unaff_EBX + 0x50) && -1 < iVar9 - *(int *)(unaff_EBX + 0x50)) {
          *(int *)(unaff_EBX + 0x50) = iVar9;
        }
      }
      if ((*(byte *)(*(int *)(unaff_EBP + -4) + 2) & 1) != 0) {
        _tcp_trace(1,(int)*(short *)(unaff_EBX + 8));
      }
      iVar9 = *(int *)(unaff_EBP + -0x30);
      *(short *)(iVar9 + 2) = *(short *)(unaff_EBP + -0x18) + 0x28 + (short)unaff_EDI;
      *(undefined1 *)(iVar9 + 8) = 0x3c;
      iVar9 = _ip_output(*(undefined4 *)(unaff_EBP + -0x14),
                         *(undefined4 *)(*(int *)(unaff_EBX + 0x20) + 0x38),
                         *(int *)(unaff_EBX + 0x20) + 0x24,
                         *(byte *)(*(int *)(unaff_EBP + -4) + 2) & 0x10);
      if (iVar9 != 0) {
        if (iVar9 == 0x37) {
          _tcp_quench();
          return 0;
        }
        if ((iVar9 != 0x41) && (iVar9 != 0x32)) {
          return iVar9;
        }
        if (2 < *(short *)(unaff_EBX + 8)) {
          *(short *)(unaff_EBX + 0x6a) = (short)iVar9;
          return 0;
        }
        return iVar9;
      }
      _DAT_001eedac = _DAT_001eedac + 1;
      if ((0 < *(int *)(unaff_EBP + -8)) &&
         (iVar9 = *(int *)(unaff_EBP + -8) + *(int *)(unaff_EBX + 0x40),
         0 < iVar9 - *(int *)(unaff_EBX + 0x4c))) {
        *(int *)(unaff_EBX + 0x4c) = iVar9;
      }
      *(byte *)(unaff_EBX + 0x1b) = *(byte *)(unaff_EBX + 0x1b) & 0xfc;
      if (*(int *)(unaff_EBP + -0x24) == 0) {
        return 0;
      }
      *(undefined4 *)(unaff_EBP + -0x24) = 0;
      *(int *)(unaff_EBP + -0xc) = *(int *)(unaff_EBX + 0x28) - *(int *)(unaff_EBX + 0x24);
      uVar5 = *(ushort *)(unaff_EBX + 0x3c);
      if (*(ushort *)(unaff_EBX + 0x54) < *(ushort *)(unaff_EBX + 0x3c)) {
        uVar5 = *(ushort *)(unaff_EBX + 0x54);
      }
      *(uint *)(unaff_EBP + -8) = (uint)uVar5;
      if (*(char *)(unaff_EBX + 0x1a) != '\0') {
        if (uVar5 == 0) {
          *(undefined4 *)(unaff_EBP + -8) = 1;
        }
        else {
          *(undefined2 *)(unaff_EBX + 0xc) = 0;
          *(undefined2 *)(unaff_EBX + 0x12) = 0;
        }
      }
      *(uint *)(unaff_EBP + -0x10) = (uint)(byte)(&_tcp_outflags)[*(short *)(unaff_EBX + 8)];
      uVar7 = (uint)*(ushort *)(*(int *)(unaff_EBP + -4) + 0x3c);
      if (*(int *)(unaff_EBP + -8) < (int)uVar7) {
        uVar7 = *(uint *)(unaff_EBP + -8);
      }
      unaff_EDI = uVar7 - *(int *)(unaff_EBP + -0xc);
      if ((unaff_EDI < 0) && (unaff_EDI = 0, *(int *)(unaff_EBP + -8) == 0)) {
        *(undefined2 *)(unaff_EBX + 10) = 0;
        *(undefined4 *)(unaff_EBX + 0x28) = *(undefined4 *)(unaff_EBX + 0x24);
      }
      uVar5 = *(ushort *)(unaff_EBX + 0x18);
      *(uint *)(unaff_EBP + -0x30) = (uint)uVar5;
      if ((int)(uint)uVar5 < unaff_EDI) {
        unaff_EDI = *(int *)(unaff_EBP + -0x30);
        *(undefined4 *)(unaff_EBP + -0x24) = 1;
      }
      iVar9 = *(int *)(unaff_EBX + 0x28);
      uVar7 = (uint)*(ushort *)(*(int *)(unaff_EBP + -4) + 0x3c);
      *(uint *)(unaff_EBP + -0x28) = uVar7;
      if ((int)((iVar9 + unaff_EDI) - (uVar7 + *(int *)(unaff_EBX + 0x24))) < 0) {
        *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
      }
      iVar9 = *(int *)(unaff_EBP + -4);
      *(uint *)(unaff_EBP + -0x2c) =
           (uint)*(ushort *)(iVar9 + 0x2a) - (uint)*(ushort *)(iVar9 + 0x28);
      iVar9 = (uint)*(ushort *)(iVar9 + 0x26) - (uint)*(ushort *)(iVar9 + 0x24);
      *(int *)(unaff_EBP + -8) = iVar9;
      if (*(int *)(unaff_EBP + -0x2c) < iVar9) {
        *(int *)(unaff_EBP + -8) = *(int *)(unaff_EBP + -0x2c);
      }
      if (((unaff_EDI == 0) ||
          (((*(int *)(unaff_EBP + -0x30) != unaff_EDI &&
            ((((*(int *)(unaff_EBP + -0x20) == 0 && ((*(byte *)(unaff_EBX + 0x1b) & 4) == 0)) ||
              (*(int *)(unaff_EBP + -0xc) + unaff_EDI < *(int *)(unaff_EBP + -0x28))) &&
             ((*(char *)(unaff_EBX + 0x1a) == '\0' &&
              (unaff_EDI < (int)(uint)(*(ushort *)(unaff_EBX + 0x66) >> 1))))))) &&
           (-1 < *(int *)(unaff_EBX + 0x28) - *(int *)(unaff_EBX + 0x50))))) &&
         ((((*(int *)(unaff_EBP + -8) < 1 ||
            ((iVar9 = *(int *)(unaff_EBP + -8) -
                      (*(int *)(unaff_EBX + 0x4c) - *(int *)(unaff_EBX + 0x40)),
             iVar9 < (int)((uint)*(ushort *)(unaff_EBX + 0x18) * 2) &&
             (iVar9 * 2 < (int)(uint)*(ushort *)(*(int *)(unaff_EBP + -4) + 0x26))))) &&
           (bVar1 = *(byte *)(unaff_EBX + 0x1b), *(byte *)(unaff_EBP + -0x2c) = bVar1,
           (bVar1 & 1) == 0)) &&
          ((((*(byte *)(unaff_EBP + -0x10) & 6) == 0 &&
            (iVar9 = *(int *)(unaff_EBX + 0x24),
            *(int *)(unaff_EBX + 0x2c) == iVar9 || *(int *)(unaff_EBX + 0x2c) - iVar9 < 0)) &&
           (((*(uint *)(unaff_EBP + -0x10) & 1) == 0 ||
            (((*(byte *)(unaff_EBP + -0x2c) & 0x10) != 0 && (*(int *)(unaff_EBX + 0x28) != iVar9))))
           )))))) {
        if (*(short *)(*(int *)(unaff_EBP + -4) + 0x3c) == 0) {
          return 0;
        }
        if (*(short *)(unaff_EBX + 10) != 0) {
          return 0;
        }
        if (*(short *)(unaff_EBX + 0xc) != 0) {
          return 0;
        }
        *(undefined2 *)(unaff_EBX + 0x12) = 0;
        _tcp_setpersist();
        return 0;
      }
      *(undefined4 *)(unaff_EBP + -0x18) = 0;
      *(undefined4 *)(unaff_EBP + -0x1c) = 0x28;
      if (((*(uint *)(unaff_EBP + -0x10) & 2) != 0) && ((*(byte *)(unaff_EBX + 0x1b) & 8) == 0)) {
        *(undefined4 *)(unaff_EBP + -0x18) = 4;
        *(undefined4 *)(unaff_EBP + -0x1c) = 0x2c;
        uVar5 = _tcp_mss();
        _DAT_001dbe67 = uVar5 >> 8 | uVar5 << 8;
      }
      uVar8 = _splimp();
      *(undefined4 *)(unaff_EBP + -0x30) = uVar8;
      iVar9 = _mfree;
      *(int *)(unaff_EBP + -0x14) = _mfree;
      if (iVar9 != 0) break;
      uVar8 = _m_more(0);
      *(undefined4 *)(unaff_EBP + -0x14) = uVar8;
    }
    if (*(short *)(iVar9 + 10) != 0) {
                    /* WARNING: Subroutine does not return */
      _panic(&DAT_001dbe69);
    }
  } while( true );
}

