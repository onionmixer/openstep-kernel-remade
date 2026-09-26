
/* WARNING: Removing unreachable block (ram,0xf00370d4) */
/* WARNING: Removing unreachable block (ram,0xf0036f74) */
/* WARNING: Removing unreachable block (ram,0xf0036e4c) */
/* WARNING: Removing unreachable block (ram,0xf0036d70) */
/* WARNING: Removing unreachable block (ram,0xf0036c60) */
/* WARNING: Removing unreachable block (ram,0xf0036c38) */
/* WARNING: Removing unreachable block (ram,0xf0036c2c) */
/* WARNING: Removing unreachable block (ram,0xf0036cac) */
/* WARNING: Removing unreachable block (ram,0xf0036cb8) */
/* WARNING: Removing unreachable block (ram,0xf0036e3c) */
/* WARNING: Removing unreachable block (ram,0xf0036eac) */
/* WARNING: Removing unreachable block (ram,0xf00370a0) */
/* WARNING: Removing unreachable block (ram,0xf00370f0) */
/* WARNING: Removing unreachable block (ram,0xf0036bec) */

undefined8 _tcp_output(uint param_1)

{
  byte bVar1;
  uint uVar2;
  undefined4 uVar3;
  int *piVar4;
  word wVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  undefined8 *in_o5;
  undefined4 unaff_l0;
  int iVar9;
  undefined4 unaff_l1;
  uint uVar10;
  uint uVar11;
  undefined4 unaff_l3;
  int iVar12;
  undefined4 unaff_l4;
  byte bVar13;
  undefined4 unaff_l5;
  int iVar14;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar15;
  undefined4 unaff_i1;
  int iVar16;
  undefined4 unaff_i2;
  int iVar17;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar18;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  bVar18 = *(int *)(param_1 + 0x50) != *(int *)(param_1 + 0x24);
  iVar14 = *(int *)(*(int *)(param_1 + 0x20) + 0x1c);
  if (bVar18) goto loc_F00369C4;
  if (*(sword *)(param_1 + 0x14) <= *(sword *)(param_1 + 0x58)) {
    *(undefined2 *)(param_1 + 0x54) = *(undefined2 *)(param_1 + 0x18);
    goto loc_F00369C4;
  }
  wVar5 = *(word *)(param_1 + 0x3c);
  do {
    iVar16 = *(int *)(param_1 + 0x28) - *(int *)(param_1 + 0x24);
    uVar11 = (uint)wVar5;
    if ((uint)*(word *)(param_1 + 0x54) < (uint)wVar5) {
      uVar11 = (uint)*(word *)(param_1 + 0x54);
    }
    if (*(char *)(param_1 + 0x1a) != '\0') {
      if (uVar11 == 0) {
        uVar11 = 1;
      }
      else {
        *(undefined2 *)(param_1 + 0xc) = 0;
        *(undefined2 *)(param_1 + 0x12) = 0;
      }
    }
    bVar13 = _tcp_outflags[*(sword *)(param_1 + 8)];
    uVar10 = (uint)*(word *)(iVar14 + 0x3c);
    if (uVar11 < *(word *)(iVar14 + 0x3c)) {
      uVar10 = uVar11;
    }
    uVar10 = uVar10 - iVar16;
    if ((int)uVar10 < 0) {
      uVar10 = 0;
      if (uVar11 == 0) {
        *(undefined2 *)(param_1 + 10) = 0;
        *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(param_1 + 0x24);
      }
      wVar5 = *(word *)(param_1 + 0x18);
    }
    else {
      wVar5 = *(word *)(param_1 + 0x18);
    }
    uVar8 = (uint)wVar5;
    uVar11 = uVar10;
    if ((int)uVar8 < (int)uVar10) {
      uVar11 = uVar8;
    }
    if ((int)((*(int *)(param_1 + 0x28) + uVar11) -
             (*(int *)(param_1 + 0x24) + (uint)*(word *)(iVar14 + 0x3c))) < 0) {
      bVar13 = bVar13 & 0xfe;
    }
    uVar2 = (uint)*(word *)(iVar14 + 0x24);
    iVar12 = *(word *)(iVar14 + 0x26) - uVar2;
    iVar7 = (uint)*(word *)(iVar14 + 0x2a) - (uint)*(word *)(iVar14 + 0x28);
    if (iVar7 < iVar12) {
      iVar12 = iVar7;
    }
    if (uVar11 == 0) {
loc_F0036B1C:
      if (iVar12 < 1) {
        bVar1 = *(byte *)(param_1 + 0x1b);
      }
      else {
        uVar2 = iVar12 - (*(int *)(param_1 + 0x4c) - *(int *)(param_1 + 0x40));
        if (((int)((uint)*(word *)(param_1 + 0x18) * 2) <= (int)uVar2) ||
           (uVar2 = uVar2 * 2, (int)(uint)*(word *)(iVar14 + 0x26) <= (int)uVar2))
        goto loc_F0036C04;
        bVar1 = *(byte *)(param_1 + 0x1b);
      }
      if (((bVar1 & 1) == 0) && ((bVar13 & 6) == 0)) {
        uVar2 = *(int *)(param_1 + 0x2c) - *(uint *)(param_1 + 0x24);
        if (((int)uVar2 < 1) &&
           (((bVar13 & 1) == 0 ||
            (((bVar1 & 0x10) != 0 &&
             (uVar2 = *(uint *)(param_1 + 0x28), uVar2 != *(uint *)(param_1 + 0x24))))))) {
          if (*(sword *)(iVar14 + 0x3c) == 0) {
            piVar15 = (int *)0x0;
          }
          else if (*(sword *)(param_1 + 10) == 0) {
            if (*(sword *)(param_1 + 0xc) == 0) {
              *(undefined2 *)(param_1 + 0x12) = 0;
              _tcp_setpersist(param_1);
              piVar15 = (int *)0x0;
            }
            else {
              piVar15 = (int *)0x0;
            }
          }
          else {
            piVar15 = (int *)0x0;
          }
          goto locret_F0037178;
        }
      }
    }
    else if (((uVar11 != uVar8) &&
             (((bVar18 && ((*(byte *)(param_1 + 0x1b) & 4) == 0)) ||
              (uVar2 = uVar11 + iVar16, (int)uVar2 < (int)(uint)*(word *)(iVar14 + 0x3c))))) &&
            ((uVar2 = (uint)*(char *)(param_1 + 0x1a), uVar2 == 0 &&
             (uVar2 = (uint)(*(word *)(param_1 + 0x66) >> 1), (int)uVar11 < (int)uVar2)))) {
      uVar2 = *(uint *)(param_1 + 0x50);
      goto loc_F0036B1C;
    }
loc_F0036C04:
    iVar7 = 0;
    iVar17 = 0x28;
    if (((bVar13 & 2) != 0) && (uVar2 = param_1, (*(byte *)(param_1 + 0x1b) & 8) == 0)) {
      iVar7 = 4;
      iVar17 = 0x2c;
      in_o5 = &_tcp_initopt;
      _tcp_mss(param_1,0);
      DAT_f010c8da._0_2_ = (undefined2)uVar2;
    }
    _spltty();
    piVar15 = _mfree;
    if (_mfree == (int *)0x0) {
      piVar15 = (int *)0x0;
      _m_more(0,2);
    }
    else {
      if (*(sword *)((int)_mfree + 10) != 0) {
        _panic(&aMget_11);
      }
      *(undefined2 *)((int)piVar15 + 10) = 2;
      word_F0134B0C = word_F0134B0C + -1;
      DAT_f0134b10._0_2_ = DAT_f0134b10._0_2_ + 1;
      _mfree = (int *)*piVar15;
      piVar15[1] = 0xc;
      *piVar15 = 0;
    }
    _splx(uVar2);
    if (piVar15 == (int *)0x0) {
      piVar15 = (int *)0x37;
      goto locret_F0037178;
    }
    piVar15[1] = 0x54 - iVar7;
    *(sword *)(piVar15 + 2) = (sword)iVar17;
    if (uVar11 == 0) {
      if ((*(byte *)(param_1 + 0x1b) & 1) == 0) {
        if ((bVar13 & 7) == 0) {
          if (*(int *)(param_1 + 0x2c) - *(int *)(param_1 + 0x24) < 1) {
            DAT_f013a7f4._8_4_ = DAT_f013a7f4._8_4_ + 1;
          }
          else {
            DAT_f013a7f4._4_4_ = DAT_f013a7f4._4_4_ + 1;
          }
        }
        else {
          DAT_f013a7f4._12_4_ = DAT_f013a7f4._12_4_ + 1;
        }
      }
      else {
        DAT_f013a7e8._8_4_ = DAT_f013a7e8._8_4_ + 1;
      }
loc_F0036E24:
      iVar6 = *(int *)(param_1 + 0x1c);
    }
    else {
      if (*(char *)(param_1 + 0x1a) == '\0') {
        iVar6 = *(int *)(param_1 + 0x28);
loc_F0036D1C:
        if (iVar6 - *(int *)(param_1 + 0x50) < 0) {
          DAT_f013a7e8._0_4_ = DAT_f013a7e8._0_4_ + 1;
          DAT_f013a7e8._4_4_ = DAT_f013a7e8._4_4_ + uVar11;
        }
        else {
          DAT_f013a7e0._0_4_ = DAT_f013a7e0._0_4_ + 1;
          DAT_f013a7e0._4_4_ = DAT_f013a7e0._4_4_ + uVar11;
        }
      }
      else {
        if (uVar11 != 1) {
          iVar6 = *(int *)(param_1 + 0x28);
          goto loc_F0036D1C;
        }
        DAT_f013a7f4._0_4_ = DAT_f013a7f4._0_4_ + 1;
      }
      iVar6 = *(int *)(iVar14 + 0x48);
      _m_copy(iVar6,iVar16,uVar11);
      *piVar15 = iVar6;
      if (iVar6 == 0) {
        uVar11 = 0;
        goto loc_F0036E24;
      }
      if (iVar16 + uVar11 == (uint)*(word *)(iVar14 + 0x3c)) {
        bVar13 = bVar13 | 8;
        goto loc_F0036E24;
      }
      iVar6 = *(int *)(param_1 + 0x1c);
    }
    iVar9 = (int)piVar15 + piVar15[1];
    if (iVar6 == 0) {
      _panic(aTcpOutput);
    }
    _bcopy(*(undefined4 *)(param_1 + 0x1c),iVar9,0x28);
    if ((bVar13 & 1) == 0) {
      uVar3 = *(undefined4 *)(param_1 + 0x28);
    }
    else if ((*(byte *)(param_1 + 0x1b) & 0x10) == 0) {
      uVar3 = *(undefined4 *)(param_1 + 0x28);
    }
    else if (*(int *)(param_1 + 0x28) == *(int *)(param_1 + 0x50)) {
      *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + -1;
      uVar3 = *(undefined4 *)(param_1 + 0x28);
    }
    else {
      uVar3 = *(undefined4 *)(param_1 + 0x28);
    }
    *(undefined4 *)(iVar9 + 0x18) = uVar3;
    *(undefined4 *)(iVar9 + 0x1c) = *(undefined4 *)(param_1 + 0x40);
    if (iVar7 != 0) {
      _bcopy(in_o5,iVar9 + 0x28,iVar7);
      *(uint *)(iVar9 + 0x20) = *(uint *)(iVar9 + 0x20) & 0xfffffff | (iVar7 + 0x14) * 0x4000000;
    }
    *(byte *)(iVar9 + 0x21) = bVar13;
    if ((iVar12 < (int)(uint)(*(word *)(iVar14 + 0x26) >> 2)) &&
       (iVar12 < (int)(uint)*(word *)(param_1 + 0x18))) {
      iVar12 = 0;
    }
    if (0xffff < iVar12) {
      iVar12 = 0xffff;
    }
    iVar6 = *(int *)(param_1 + 0x4c) - *(int *)(param_1 + 0x40);
    if (iVar12 < iVar6) {
      iVar12 = iVar6;
    }
    *(sword *)(iVar9 + 0x22) = (sword)iVar12;
    iVar6 = *(int *)(param_1 + 0x2c) - *(int *)(param_1 + 0x28);
    if (iVar6 < 1) {
      *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(param_1 + 0x24);
    }
    else {
      *(sword *)(iVar9 + 0x26) = (sword)iVar6;
      *(byte *)(iVar9 + 0x21) = *(byte *)(iVar9 + 0x21) | 0x20;
    }
    if (uVar11 + iVar7 != 0) {
      *(sword *)(iVar9 + 10) = (sword)iVar7 + (sword)uVar11 + 0x14;
    }
    piVar4 = piVar15;
    _in_cksum(piVar15,iVar17 + uVar11);
    *(sword *)(iVar9 + 0x24) = (sword)piVar4;
    if ((*(char *)(param_1 + 0x1a) == '\0') || (*(sword *)(param_1 + 0xc) == 0)) {
      iVar17 = *(int *)(param_1 + 0x28);
      if ((bVar13 & 3) == 0) {
loc_F0036FDC:
        iVar6 = *(int *)(param_1 + 0x28);
      }
      else {
        if ((bVar13 & 2) != 0) {
          *(int *)(param_1 + 0x28) = iVar17 + 1;
        }
        iVar6 = *(int *)(param_1 + 0x28);
        if ((bVar13 & 1) != 0) {
          *(int *)(param_1 + 0x28) = iVar6 + 1;
          *(byte *)(param_1 + 0x1b) = *(byte *)(param_1 + 0x1b) | 0x10;
          goto loc_F0036FDC;
        }
      }
      iVar6 = iVar6 + uVar11;
      *(int *)(param_1 + 0x28) = iVar6;
      if ((0 < iVar6 - *(int *)(param_1 + 0x50)) &&
         (*(int *)(param_1 + 0x50) = iVar6, *(sword *)(param_1 + 0x5a) == 0)) {
        *(undefined2 *)(param_1 + 0x5a) = 1;
        *(int *)(param_1 + 0x5c) = iVar17;
        DAT_f013a7b8._0_4_ = DAT_f013a7b8._0_4_ + 1;
      }
      if (*(sword *)(param_1 + 10) == 0) {
        if (*(int *)(param_1 + 0x28) != *(int *)(param_1 + 0x24)) {
          *(undefined2 *)(param_1 + 10) = *(undefined2 *)(param_1 + 0x14);
          if (*(sword *)(param_1 + 0xc) != 0) {
            *(undefined2 *)(param_1 + 0xc) = 0;
            *(undefined2 *)(param_1 + 0x12) = 0;
          }
          goto loc_F0037084;
        }
        wVar5 = *(word *)(iVar14 + 2);
      }
      else {
        wVar5 = *(word *)(iVar14 + 2);
      }
    }
    else {
      iVar17 = *(int *)(param_1 + 0x28) + uVar11;
      if (iVar17 != *(int *)(param_1 + 0x50) && -1 < iVar17 - *(int *)(param_1 + 0x50)) {
        *(int *)(param_1 + 0x50) = iVar17;
      }
loc_F0037084:
      wVar5 = *(word *)(iVar14 + 2);
    }
    if ((wVar5 & 1) != 0) {
      _tcp_trace(1,(int)*(sword *)(param_1 + 8),param_1,iVar9,0);
    }
    *(sword *)(iVar9 + 2) = (sword)iVar7 + 0x28 + (sword)uVar11;
    *(undefined *)(iVar9 + 8) = 0x3c;
    _ip_output(piVar15,*(undefined4 *)(*(int *)(param_1 + 0x20) + 0x38),
               *(int *)(param_1 + 0x20) + 0x24,*(word *)(iVar14 + 2) & 0x10,0);
    if (piVar15 != (int *)0x0) {
      if (piVar15 == (int *)0x37) {
        _tcp_quench(*(undefined4 *)(param_1 + 0x20));
        piVar15 = (int *)0x0;
        goto locret_F0037178;
      }
      if (((piVar15 != (int *)0x41) && (piVar15 != (int *)0x32)) || (*(sword *)(param_1 + 8) < 3))
      goto locret_F0037178;
      *(sword *)(param_1 + 0x6a) = (sword)piVar15;
      goto loc_F0037174;
    }
    DAT_f013a7b8._36_4_ = DAT_f013a7b8._36_4_ + 1;
    if ((0 < iVar12) &&
       (iVar12 = *(int *)(param_1 + 0x40) + iVar12,
       iVar12 != *(int *)(param_1 + 0x4c) && -1 < iVar12 - *(int *)(param_1 + 0x4c))) {
      *(int *)(param_1 + 0x4c) = iVar12;
    }
    *(byte *)(param_1 + 0x1b) = *(byte *)(param_1 + 0x1b) & 0xfc;
    if ((int)uVar10 <= (int)uVar8) {
loc_F0037174:
      piVar15 = (int *)0x0;
locret_F0037178:
      return CONCAT44(iVar16,piVar15);
    }
loc_F00369C4:
    wVar5 = *(word *)(param_1 + 0x3c);
  } while( true );
}
