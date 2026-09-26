
int _tcp_output(int param_1)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  int *piVar4;
  word wVar6;
  int *piVar5;
  undefined2 uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  byte bVar11;
  int iVar12;
  int iVar13;
  bool bVar14;
  undefined4 uStack_1c;
  undefined4 uStack_10;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x20) + 0x18);
  bVar14 = *(int *)(param_1 + 0x50) == *(int *)(param_1 + 0x24);
  if ((bVar14) && (*(sword *)(param_1 + 0x14) <= *(sword *)(param_1 + 0x58))) {
    *(undefined2 *)(param_1 + 0x54) = *(undefined2 *)(param_1 + 0x18);
  }
  while( true ) {
    iVar13 = *(int *)(param_1 + 0x28) - *(int *)(param_1 + 0x24);
    wVar6 = *(word *)(param_1 + 0x3c);
    if (*(word *)(param_1 + 0x54) < *(word *)(param_1 + 0x3c)) {
      wVar6 = *(word *)(param_1 + 0x54);
    }
    uVar9 = (uint)wVar6;
    if (*(char *)(param_1 + 0x1a) != '\0') {
      if (uVar9 == 0) {
        uVar9 = 1;
      }
      else {
        *(undefined2 *)(param_1 + 0xc) = 0;
        *(undefined2 *)(param_1 + 0x12) = 0;
      }
    }
    bVar11 = _tcp_outflags[*(sword *)(param_1 + 8)];
    uVar8 = (uint)*(word *)(iVar1 + 0x38);
    if (uVar9 < *(word *)(iVar1 + 0x38)) {
      uVar8 = uVar9;
    }
    uVar8 = uVar8 - iVar13;
    if (((int)uVar8 < 0) && (uVar8 = 0, uVar9 == 0)) {
      *(undefined2 *)(param_1 + 10) = 0;
      *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(param_1 + 0x24);
    }
    uStack_1c = (uint)*(word *)(param_1 + 0x18);
    bVar3 = (int)uStack_1c < (int)uVar8;
    if (bVar3) {
      uVar8 = (uint)*(word *)(param_1 + 0x18);
    }
    if ((int)((uVar8 + *(int *)(param_1 + 0x28)) -
             ((uint)*(word *)(iVar1 + 0x38) + *(int *)(param_1 + 0x24))) < 0) {
      bVar11 = bVar11 & 0xfe;
    }
    iVar12 = (uint)*(word *)(iVar1 + 0x28) - (uint)*(word *)(iVar1 + 0x26);
    iVar10 = (uint)*(word *)(iVar1 + 0x24) - (uint)*(word *)(iVar1 + 0x22);
    if (iVar12 < iVar10) {
      iVar10 = iVar12;
    }
    if ((((uVar8 == 0) ||
         ((uVar8 != uStack_1c &&
          (((((!bVar14 && ((*(byte *)(param_1 + 0x1b) & 4) == 0)) ||
             ((int)(iVar13 + uVar8) < (int)(uint)*(word *)(iVar1 + 0x38))) &&
            ((*(char *)(param_1 + 0x1a) == '\0' &&
             ((int)uVar8 < (int)(*(uint *)(param_1 + 0x66) >> 0x11))))) &&
           (-1 < *(int *)(param_1 + 0x28) - *(int *)(param_1 + 0x50))))))) &&
        ((iVar10 < 1 ||
         ((iVar12 = iVar10 - (*(int *)(param_1 + 0x4c) - *(int *)(param_1 + 0x40)),
          iVar12 < (int)((uint)*(word *)(param_1 + 0x18) * 2) &&
          (iVar12 * 2 < (int)(uint)*(word *)(iVar1 + 0x24))))))) &&
       ((((*(byte *)(param_1 + 0x1b) & 1) == 0 &&
         (((bVar11 & 6) == 0 &&
          (iVar12 = *(int *)(param_1 + 0x24),
          *(int *)(param_1 + 0x2c) == iVar12 || *(int *)(param_1 + 0x2c) - iVar12 < 0)))) &&
        (((bVar11 & 1) == 0 ||
         (((*(byte *)(param_1 + 0x1b) & 0x10) != 0 && (iVar12 != *(int *)(param_1 + 0x28))))))))) {
      if (*(sword *)(iVar1 + 0x38) == 0) {
        return 0;
      }
      if (*(sword *)(param_1 + 10) != 0) {
        return 0;
      }
      if (*(sword *)(param_1 + 0xc) != 0) {
        return 0;
      }
      *(undefined2 *)(param_1 + 0x12) = 0;
      _tcp_setpersist(param_1);
      return 0;
    }
    uStack_1c = 0;
    uStack_10 = 0x28;
    if (((bVar11 & 2) != 0) && ((*(byte *)(param_1 + 0x1b) & 8) == 0)) {
      uStack_1c = 4;
      uStack_10 = 0x2c;
      word_40AEB69 = _tcp_mss(param_1,0);
    }
    piVar5 = _mfree;
    if (_mfree == (int *)0x0) {
      piVar5 = (int *)_m_more(0,2);
    }
    else {
      if (*(sword *)((int)_mfree + 10) != 0) {
                    /* WARNING: Subroutine does not return */
        _panic(&aMget);
      }
      *(undefined2 *)((int)_mfree + 10) = 2;
      word_40B61CC = word_40B61CC + -1;
      word_40B61D0 = word_40B61D0 + 1;
      piVar4 = (int *)*_mfree;
      *_mfree = 0;
      _mfree = piVar4;
      piVar5[1] = 0xc;
    }
    if (piVar5 == (int *)0x0) break;
    piVar5[1] = 0x54 - uStack_1c;
    *(undefined2 *)(piVar5 + 2) = uStack_10._2_2_;
    if (uVar8 == 0) {
      if ((*(byte *)(param_1 + 0x1b) & 1) == 0) {
        if ((bVar11 & 7) == 0) {
          if (*(int *)(param_1 + 0x2c) == *(int *)(param_1 + 0x24) ||
              *(int *)(param_1 + 0x2c) - *(int *)(param_1 + 0x24) < 0) {
            dword_40BBD88 = dword_40BBD88 + 1;
          }
          else {
            dword_40BBD84 = dword_40BBD84 + 1;
          }
        }
        else {
          dword_40BBD8C = dword_40BBD8C + 1;
        }
      }
      else {
        dword_40BBD7C = dword_40BBD7C + 1;
      }
    }
    else {
      if ((*(char *)(param_1 + 0x1a) == '\0') || (uVar8 != 1)) {
        if (*(int *)(param_1 + 0x28) - *(int *)(param_1 + 0x50) < 0) {
          dword_40BBD74 = dword_40BBD74 + 1;
          dword_40BBD78 = uVar8 + dword_40BBD78;
        }
        else {
          dword_40BBD6C = dword_40BBD6C + 1;
          dword_40BBD70 = uVar8 + dword_40BBD70;
        }
      }
      else {
        dword_40BBD80 = dword_40BBD80 + 1;
      }
      iVar12 = _m_copy(*(undefined4 *)(iVar1 + 0x44),iVar13,uVar8);
      *piVar5 = iVar12;
      if (iVar12 == 0) {
        uVar8 = 0;
      }
      else if ((uint)*(word *)(iVar1 + 0x38) == uVar8 + iVar13) {
        bVar11 = bVar11 | 8;
      }
    }
    iVar13 = piVar5[1] + (int)piVar5;
    if (*(int *)(param_1 + 0x1c) == 0) {
                    /* WARNING: Subroutine does not return */
      _panic(aTcpOutput);
    }
    _bcopy(*(undefined4 *)(param_1 + 0x1c),iVar13,0x28);
    if ((((bVar11 & 1) != 0) && ((*(byte *)(param_1 + 0x1b) & 0x10) != 0)) &&
       (*(int *)(param_1 + 0x28) == *(int *)(param_1 + 0x50))) {
      *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + -1;
    }
    *(undefined4 *)(iVar13 + 0x18) = *(undefined4 *)(param_1 + 0x28);
    *(undefined4 *)(iVar13 + 0x1c) = *(undefined4 *)(param_1 + 0x40);
    if (uStack_1c != 0) {
      _bcopy(&_tcp_initopt,iVar13 + 0x28,uStack_1c);
      *(uint *)(iVar13 + 0x20) =
           *(uint *)(iVar13 + 0x20) & 0xfffffff | (uStack_1c + 0x14 >> 2) << 0x1c;
    }
    *(byte *)(iVar13 + 0x21) = bVar11;
    if ((iVar10 < (int)(*(uint *)(iVar1 + 0x24) >> 0x12)) &&
       (iVar10 < (int)(uint)*(word *)(param_1 + 0x18))) {
      iVar10 = 0;
    }
    if (0xffff < iVar10) {
      iVar10 = 0xffff;
    }
    iVar12 = *(int *)(param_1 + 0x4c) - *(int *)(param_1 + 0x40);
    if (iVar10 < iVar12) {
      iVar10 = iVar12;
    }
    *(sword *)(iVar13 + 0x22) = (sword)iVar10;
    iVar12 = *(int *)(param_1 + 0x2c);
    iVar2 = *(int *)(param_1 + 0x28);
    if (iVar12 == iVar2 || iVar12 - iVar2 < 0) {
      *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(param_1 + 0x24);
    }
    else {
      *(sword *)(iVar13 + 0x26) = (sword)iVar12 - (sword)iVar2;
      *(byte *)(iVar13 + 0x21) = *(byte *)(iVar13 + 0x21) | 0x20;
    }
    if (uVar8 + uStack_1c != 0) {
      *(sword *)(iVar13 + 10) = uStack_1c._2_2_ + (sword)uVar8 + 0x14;
    }
    uVar7 = _in_cksum(piVar5,uStack_10 + uVar8);
    *(undefined2 *)(iVar13 + 0x24) = uVar7;
    if ((*(char *)(param_1 + 0x1a) == '\0') || (*(sword *)(param_1 + 0xc) == 0)) {
      iVar12 = *(int *)(param_1 + 0x28);
      if ((bVar11 & 3) != 0) {
        if ((bVar11 & 2) != 0) {
          *(int *)(param_1 + 0x28) = iVar12 + 1;
        }
        if ((bVar11 & 1) != 0) {
          *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
          *(byte *)(param_1 + 0x1b) = *(byte *)(param_1 + 0x1b) | 0x10;
        }
      }
      iVar2 = uVar8 + *(int *)(param_1 + 0x28);
      *(int *)(param_1 + 0x28) = iVar2;
      if ((iVar2 != *(int *)(param_1 + 0x50) && -1 < iVar2 - *(int *)(param_1 + 0x50)) &&
         (*(int *)(param_1 + 0x50) = iVar2, *(sword *)(param_1 + 0x5a) == 0)) {
        *(undefined2 *)(param_1 + 0x5a) = 1;
        *(int *)(param_1 + 0x5c) = iVar12;
        dword_40BBD44 = dword_40BBD44 + 1;
      }
      if (((*(sword *)(param_1 + 10) == 0) && (*(int *)(param_1 + 0x28) != *(int *)(param_1 + 0x24))
          ) && (*(undefined2 *)(param_1 + 10) = *(undefined2 *)(param_1 + 0x14),
               *(sword *)(param_1 + 0xc) != 0)) {
        *(undefined2 *)(param_1 + 0xc) = 0;
        *(undefined2 *)(param_1 + 0x12) = 0;
      }
    }
    else {
      iVar12 = uVar8 + *(int *)(param_1 + 0x28);
      if (iVar12 != *(int *)(param_1 + 0x50) && -1 < iVar12 - *(int *)(param_1 + 0x50)) {
        *(int *)(param_1 + 0x50) = iVar12;
      }
    }
    if ((*(byte *)(iVar1 + 3) & 1) != 0) {
      _tcp_trace(1,(int)*(sword *)(param_1 + 8),param_1,iVar13,0);
    }
    *(sword *)(iVar13 + 2) = (sword)uVar8 + uStack_1c._2_2_ + 0x28;
    *(undefined *)(iVar13 + 8) = 0x3c;
    iVar13 = _ip_output(piVar5,*(undefined4 *)(*(int *)(param_1 + 0x20) + 0x34),
                        *(int *)(param_1 + 0x20) + 0x20,*(byte *)(iVar1 + 3) & 0x10,0);
    if (iVar13 != 0) {
      if (iVar13 == 0x37) {
        _tcp_quench(*(undefined4 *)(param_1 + 0x20));
        return 0;
      }
      if ((iVar13 != 0x41) && (iVar13 != 0x32)) {
        return iVar13;
      }
      if (2 < *(sword *)(param_1 + 8)) {
        *(sword *)(param_1 + 0x6a) = (sword)iVar13;
        return 0;
      }
      return iVar13;
    }
    dword_40BBD68 = dword_40BBD68 + 1;
    if ((0 < iVar10) &&
       (iVar10 = iVar10 + *(int *)(param_1 + 0x40),
       iVar10 != *(int *)(param_1 + 0x4c) && -1 < iVar10 - *(int *)(param_1 + 0x4c))) {
      *(int *)(param_1 + 0x4c) = iVar10;
    }
    *(byte *)(param_1 + 0x1b) = *(byte *)(param_1 + 0x1b) & 0xfc;
    if (!bVar3) {
      return 0;
    }
  }
  return 0x37;
}

