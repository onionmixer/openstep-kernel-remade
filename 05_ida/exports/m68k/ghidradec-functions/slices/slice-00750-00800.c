/* GHIDRADEC_FUNCTION index=750 start=0x4023dfc */

void _tcp_pulloutofband(int param_1,int param_2,int *param_3)

{
  int iVar1;
  byte *pbVar2;
  int iVar3;
  undefined *puVar4;
  
  iVar3 = *(word *)(param_2 + 0x26) - 1;
  do {
    if (iVar3 < 0) break;
    if (iVar3 < *(sword *)(param_3 + 2)) {
      puVar4 = (undefined *)((int)param_3 + iVar3 + param_3[1]);
      iVar1 = *(int *)(*(int *)(param_1 + 8) + 0x1c);
      *(undefined *)(iVar1 + 0x69) = *puVar4;
      pbVar2 = (byte *)(iVar1 + 0x68);
      *pbVar2 = *pbVar2 | 1;
      _bcopy(puVar4 + 1,puVar4,(*(sword *)(param_3 + 2) - iVar3) + -1);
      *(sword *)(param_3 + 2) = *(sword *)(param_3 + 2) + -1;
      return;
    }
    iVar3 = iVar3 - *(sword *)(param_3 + 2);
    param_3 = (int *)*param_3;
  } while (param_3 != (int *)0x0);
                    /* WARNING: Subroutine does not return */
  _panic(aTcpPulloutofba);
}
/* GHIDRADEC_FUNCTION index=751 start=0x4023e7c */

void _tcp_xmit_timer(int param_1)

{
  sword sVar1;
  sword sVar2;
  
  dword_40BBD48 = dword_40BBD48 + 1;
  sVar1 = *(sword *)(param_1 + 0x60);
  if (sVar1 == 0) {
    *(sword *)(param_1 + 0x60) = *(sword *)(param_1 + 0x5a) << 3;
    *(sword *)(param_1 + 0x62) = *(sword *)(param_1 + 0x5a) << 1;
  }
  else {
    sVar2 = *(sword *)(param_1 + 0x5a) - ((sVar1 >> 3) + 1);
    *(sword *)(param_1 + 0x60) = sVar2 + sVar1;
    if ((sword)(sVar2 + sVar1) < 1) {
      *(undefined2 *)(param_1 + 0x60) = 1;
    }
    if (sVar2 < 0) {
      sVar2 = -sVar2;
    }
    sVar1 = (sVar2 - (*(sword *)(param_1 + 0x62) >> 2)) + *(sword *)(param_1 + 0x62);
    *(sword *)(param_1 + 0x62) = sVar1;
    if (sVar1 < 1) {
      *(undefined2 *)(param_1 + 0x62) = 1;
    }
  }
  *(undefined2 *)(param_1 + 0x5a) = 0;
  *(undefined2 *)(param_1 + 0x12) = 0;
  sVar1 = *(sword *)(param_1 + 0x62) + (*(sword *)(param_1 + 0x60) >> 3);
  *(sword *)(param_1 + 0x14) = sVar1;
  if ((int)sVar1 < (int)(uint)*(word *)(param_1 + 100)) {
    *(word *)(param_1 + 0x14) = *(word *)(param_1 + 100);
  }
  else if (0x80 < sVar1) {
    *(undefined2 *)(param_1 + 0x14) = 0x80;
  }
  *(undefined2 *)(param_1 + 0x6a) = 0;
  return;
}
/* GHIDRADEC_FUNCTION index=752 start=0x4023f24 */

uint _tcp_mss(int param_1,word param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  iVar1 = *(int *)(param_1 + 0x20);
  piVar3 = (int *)(iVar1 + 0x20);
  iVar4 = *piVar3;
  if (iVar4 == 0) {
    if (*(int *)(iVar1 + 0xc) != 0) {
      *(undefined2 *)(iVar1 + 0x24) = 2;
      *(undefined4 *)(iVar1 + 0x28) = *(undefined4 *)(iVar1 + 0xc);
      _rtalloc(piVar3);
    }
    iVar4 = *piVar3;
    if (iVar4 == 0) {
      return _tcp_mssdflt;
    }
  }
  iVar2 = *(int *)(iVar1 + 0x18);
  uVar5 = (int)*(sword *)(*(int *)(iVar4 + 0x2c) + 10) - 0x28;
  if (0x400 < (int)uVar5) {
    uVar5 = uVar5 & 0xfffffc00;
  }
  iVar4 = _in_localaddr(*(undefined4 *)(iVar1 + 0xc));
  if (iVar4 == 0) {
    uVar5 = _min(uVar5,_tcp_mssdflt);
  }
  if ((param_2 != 0) && ((int)(uint)param_2 < (int)uVar5)) {
    uVar5 = (uint)param_2;
  }
  if ((int)uVar5 < 0x20) {
    uVar5 = 0x20;
  }
  if (((int)uVar5 < (int)(uint)*(word *)(param_1 + 0x18)) || (uVar6 = uVar5, param_2 != 0)) {
    uVar6 = (uint)*(word *)(iVar2 + 0x3a);
    if (uVar5 <= uVar6) {
      uVar6 = _min(uVar6,0xffff);
      _sbreserve(iVar2 + 0x38,uVar5 * (uVar6 / uVar5));
      uVar6 = uVar5;
    }
    *(sword *)(param_1 + 0x18) = (sword)uVar6;
    if (uVar6 < *(word *)(iVar2 + 0x24)) {
      uVar5 = _min((uint)*(word *)(iVar2 + 0x24),0xffff);
      _sbreserve(iVar2 + 0x22,uVar6 * (uVar5 / uVar6));
    }
  }
  *(sword *)(param_1 + 0x54) = (sword)uVar6;
  return uVar6;
}
/* GHIDRADEC_FUNCTION index=753 start=0x4024044 */

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
/* GHIDRADEC_FUNCTION index=754 start=0x40245ea */

void _tcp_setpersist(int param_1)

{
  sword sVar1;
  
  if (*(sword *)(param_1 + 10) != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aTcpOutputRexmt);
  }
  sVar1 = (sword)*(undefined4 *)(_tcp_backoff + *(sword *)(param_1 + 0x12) * 4) *
          (sword)((int)*(sword *)(param_1 + 0x62) +
                  ((int)((uint)*(word *)(param_1 + 0x60) << 0x10) >> 0x12) >> 1);
  *(sword *)(param_1 + 0xc) = sVar1;
  if (sVar1 < 10) {
    *(undefined2 *)(param_1 + 0xc) = 10;
  }
  else if (0x78 < sVar1) {
    *(undefined2 *)(param_1 + 0xc) = 0x78;
  }
  if (*(sword *)(param_1 + 0x12) < 0xc) {
    *(sword *)(param_1 + 0x12) = *(sword *)(param_1 + 0x12) + 1;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=755 start=0x402466a */

void _tcp_init(void)

{
  _tcp_iss = 1;
  dword_40B7DA4 = &_tcb;
  _tcb = &_tcb;
  return;
}
/* GHIDRADEC_FUNCTION index=756 start=0x4024688 */

undefined4 * _tcp_template(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  
  iVar1 = *(int *)(param_1 + 0x20);
  puVar3 = *(undefined4 **)(param_1 + 0x1c);
  if (puVar3 == (undefined4 *)0x0) {
    iVar2 = _m_get(0,2);
    if (iVar2 == 0) {
      return (undefined4 *)0x0;
    }
    *(undefined4 *)(iVar2 + 4) = 0x54;
    *(undefined2 *)(iVar2 + 8) = 0x28;
    puVar3 = (undefined4 *)(*(int *)(iVar2 + 4) + iVar2);
  }
  puVar3[1] = 0;
  *puVar3 = 0;
  *(undefined *)(puVar3 + 2) = 0;
  *(undefined *)((int)puVar3 + 9) = 6;
  *(undefined2 *)((int)puVar3 + 10) = 0x14;
  puVar3[3] = *(undefined4 *)(iVar1 + 0x12);
  puVar3[4] = *(undefined4 *)(iVar1 + 0xc);
  *(undefined2 *)(puVar3 + 5) = *(undefined2 *)(iVar1 + 0x16);
  *(undefined2 *)((int)puVar3 + 0x16) = *(undefined2 *)(iVar1 + 0x10);
  puVar3[6] = 0;
  puVar3[7] = 0;
  *(undefined *)(puVar3 + 8) = 0x50;
  *(undefined *)((int)puVar3 + 0x21) = 0;
  *(undefined2 *)((int)puVar3 + 0x22) = 0;
  *(undefined2 *)(puVar3 + 9) = 0;
  *(undefined2 *)((int)puVar3 + 0x26) = 0;
  return puVar3;
}
/* GHIDRADEC_FUNCTION index=757 start=0x402471a */

void _tcp_respond(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 param_4,
                 undefined4 param_5,undefined param_6)

{
  undefined4 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  
  uVar3 = 0;
  iVar6 = 0;
  if (param_1 != 0) {
    iVar6 = *(int *)(*(int *)(param_1 + 0x20) + 0x18);
    iVar4 = (uint)*(word *)(iVar6 + 0x28) - (uint)*(word *)(iVar6 + 0x26);
    iVar6 = (uint)*(word *)(iVar6 + 0x24) - (uint)*(word *)(iVar6 + 0x22);
    if (iVar4 < iVar6) {
      iVar6 = iVar4;
    }
    uVar3 = (undefined2)iVar6;
    iVar6 = *(int *)(param_1 + 0x20) + 0x20;
  }
  if (param_3 == (undefined4 *)0x0) {
    param_3 = (undefined4 *)_m_get(0,2);
    if (param_3 == (undefined4 *)0x0) {
      return;
    }
    *(undefined2 *)(param_3 + 2) = 0x28;
    puVar5 = (undefined4 *)(param_3[1] + (int)param_3);
    *puVar5 = *param_2;
    puVar5[1] = param_2[1];
    puVar5[2] = param_2[2];
    puVar5[3] = param_2[3];
    puVar5[4] = param_2[4];
    puVar5[5] = param_2[5];
    puVar5[6] = param_2[6];
    puVar5[7] = param_2[7];
    puVar5[8] = param_2[8];
    puVar5[9] = param_2[9];
    param_2 = (undefined4 *)(param_3[1] + (int)param_3);
    param_6 = 0x10;
  }
  else {
    _m_freem(*param_3);
    *param_3 = 0;
    param_3[1] = (int)param_2 - (int)param_3;
    *(undefined2 *)(param_3 + 2) = 0x28;
    uVar1 = param_2[4];
    param_2[4] = param_2[3];
    param_2[3] = uVar1;
    uVar2 = *(undefined2 *)((int)param_2 + 0x16);
    *(undefined2 *)((int)param_2 + 0x16) = *(undefined2 *)(param_2 + 5);
    *(undefined2 *)(param_2 + 5) = uVar2;
  }
  param_2[1] = 0;
  *param_2 = 0;
  *(undefined *)(param_2 + 2) = 0;
  *(undefined2 *)((int)param_2 + 10) = 0x14;
  param_2[6] = param_5;
  param_2[7] = param_4;
  *(undefined *)(param_2 + 8) = 0x50;
  *(undefined *)((int)param_2 + 0x21) = param_6;
  *(undefined2 *)((int)param_2 + 0x22) = uVar3;
  *(undefined2 *)((int)param_2 + 0x26) = 0;
  uVar3 = _in_cksum(param_3,0x28);
  *(undefined2 *)(param_2 + 9) = uVar3;
  *(undefined2 *)((int)param_2 + 2) = 0x28;
  *(undefined *)(param_2 + 2) = byte_40AEB6F;
  _ip_output(param_3,0,iVar6,0,0);
  return;
}
/* GHIDRADEC_FUNCTION index=758 start=0x4024858 */

int _tcp_newtcpcb(int param_1)

{
  int iVar1;
  
  iVar1 = _kalloc(0x6c);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    _bzero(iVar1,0x6c);
    *(int *)(iVar1 + 4) = iVar1;
    *(int *)iVar1 = iVar1;
    *(undefined2 *)(iVar1 + 0x18) = uRam040aeb72;
    *(undefined *)(iVar1 + 0x1b) = 0;
    *(int *)(iVar1 + 0x20) = param_1;
    *(undefined2 *)(iVar1 + 0x60) = 0;
    *(sword *)(iVar1 + 0x62) = (sword)_tcp_rttdflt << 3;
    *(undefined2 *)(iVar1 + 100) = 2;
    *(undefined2 *)(iVar1 + 0x14) = 0xc;
    *(undefined2 *)(iVar1 + 0x54) = 0xffff;
    *(undefined2 *)(iVar1 + 0x56) = 0xffff;
    *(int *)(param_1 + 0x1c) = iVar1;
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=759 start=0x40248d6 */

void _tcp_drop(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x20) + 0x18);
  if (*(sword *)(param_1 + 8) < 3) {
    dword_40BBD3C = dword_40BBD3C + 1;
  }
  else {
    *(undefined2 *)(param_1 + 8) = 0;
    _tcp_output(param_1);
    dword_40BBD38 = dword_40BBD38 + 1;
  }
  if ((param_2 == 0x3c) && (*(sword *)(param_1 + 0x6a) != 0)) {
    param_2 = (int)*(sword *)(param_1 + 0x6a);
  }
  *(sword *)(iVar1 + 0x50) = (sword)param_2;
  _tcp_close(param_1);
  return;
}
/* GHIDRADEC_FUNCTION index=760 start=0x4024936 */

undefined4 _tcp_close(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  
  puVar2 = (undefined4 *)param_1[8];
  uVar3 = puVar2[6];
  puVar1 = (undefined4 *)*param_1;
  while (param_1 != puVar1) {
    puVar1 = (undefined4 *)*puVar1;
    piVar4 = (int *)puVar1[1];
    iVar5 = piVar4[5];
    *(int *)(*piVar4 + 4) = piVar4[1];
    *(int *)piVar4[1] = *piVar4;
    _m_freem(iVar5);
  }
  if (param_1[7] != 0) {
    _m_free(param_1[7] & 0xffffff80);
  }
  _kfree(param_1,0x6c);
  puVar2[7] = 0;
  _soisdisconnected(uVar3);
  if (puVar2 == _tcp_last_inpcb) {
    _tcp_last_inpcb = &_tcb;
  }
  _in_pcbdetach(puVar2);
  dword_40BBD40 = dword_40BBD40 + 1;
  return 0;
}
/* GHIDRADEC_FUNCTION index=761 start=0x40249d2 */

void _tcp_drain(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=762 start=0x40249da */

void _tcp_notify(int param_1)

{
  sword sVar1;
  
  sVar1 = *(sword *)(*(int *)(param_1 + 0x18) + 0x50);
  if ((*(sword *)(*(int *)(param_1 + 0x18) + 6) == 4) ||
     (((sVar1 != 0x41 && (sVar1 != 0x33)) && (sVar1 != 0x40)))) {
    *(sword *)(*(int *)(param_1 + 0x1c) + 0x6a) = sVar1;
    _wakeup(*(int *)(param_1 + 0x18) + 0x4e);
    _sowakeup(*(int *)(param_1 + 0x18),*(int *)(param_1 + 0x18) + 0x22);
    _sowakeup(*(int *)(param_1 + 0x18),*(int *)(param_1 + 0x18) + 0x38);
  }
  else {
    *(undefined2 *)(*(int *)(param_1 + 0x18) + 0x50) = 0;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=763 start=0x4024a54 */

void _tcp_ctlinput(uint param_1,undefined4 param_2,byte *param_3)

{
  code *pcVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  undefined2 uVar4;
  
  pcVar1 = _tcp_notify;
  if (param_1 == 4) {
    pcVar1 = _tcp_quench;
  }
  else {
    if (0x15 < param_1) {
      return;
    }
    if (_inetctlerrmap[param_1] == '\0') {
      return;
    }
  }
  if (param_3 == (byte *)0x0) {
    uVar4 = 0;
    uVar2 = 0;
    uVar3 = _zeroin_addr;
  }
  else {
    uVar4 = *(undefined2 *)(param_3 + (*param_3 & 0xf) * 4);
    uVar2 = *(undefined2 *)(param_3 + (*param_3 & 0xf) * 4 + 2);
    uVar3 = *(undefined4 *)(param_3 + 0xc);
  }
  _in_pcbnotify(&_tcb,param_2,uVar2,uVar3,uVar4,param_1,pcVar1);
  return;
}
/* GHIDRADEC_FUNCTION index=764 start=0x4024ada */

void _tcp_quench(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x1c);
  if (iVar1 != 0) {
    *(undefined2 *)(iVar1 + 0x54) = *(undefined2 *)(iVar1 + 0x18);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=765 start=0x4024af4 */

undefined4 _tcp_fasttimo(void)

{
  undefined4 *puVar1;
  int iVar2;
  byte bVar3;
  undefined4 *puVar4;
  undefined2 uVar5;
  uint in_D0;
  uint uVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  
  uVar6 = in_D0 & 0xffff0000;
  uVar5 = (undefined2)(uVar6 >> 0x10);
  bVar8 = false;
  bVar9 = false;
  bVar7 = _tcb == (undefined4 *)0x0;
  puVar4 = (undefined4 *)0x0;
  if (!bVar7) {
    bVar9 = &_tcb < _tcb;
    bVar8 = SBORROW4(0x40b7da0,(int)_tcb);
    puVar4 = (undefined4 *)((int)&_tcb - (int)_tcb);
    bVar7 = (undefined4 **)_tcb == &_tcb;
    puVar1 = _tcb;
    while (!bVar7) {
      iVar2 = puVar1[7];
      if (iVar2 != 0) {
        bVar3 = *(byte *)(iVar2 + 0x1b);
        uVar6 = CONCAT31((int3)(uVar6 >> 8),bVar3);
        if ((bVar3 & 2) != 0) {
          *(byte *)(iVar2 + 0x1b) = bVar3 & 0xfd | 1;
          unk_40BBD4C = unk_40BBD4C + 1;
          uVar6 = _tcp_output(iVar2);
        }
      }
      uVar5 = (undefined2)(uVar6 >> 0x10);
      puVar1 = (undefined4 *)*puVar1;
      bVar9 = puVar1 < &_tcb;
      bVar8 = SBORROW4((int)puVar1,0x40b7da0);
      puVar4 = puVar1 + -0x102df68;
      bVar7 = (undefined4 **)puVar1 == &_tcb;
    }
  }
  return CONCAT22(uVar5,(word)(byte)(bVar9 << 4 | ((int)puVar4 < 0) << 3 | bVar7 << 2 | bVar8 << 1 |
                                    bVar9));
}
/* GHIDRADEC_FUNCTION index=766 start=0x4024b5e */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

byte _tcp_slowtimo(void)

{
  undefined4 *puVar1;
  int iVar2;
  sword sVar3;
  byte bVar4;
  undefined4 *puVar5;
  int iVar6;
  bool bVar7;
  bool bVar8;
  
  __tcp_maxidle = _tcp_keepintvl << 3;
  puVar1 = _tcb;
  if (_tcb == (undefined4 *)0x0) {
    bVar4 = ((_tcp_keepintvl >> 0x1d & 1) != 0) * '\x10' | 4;
  }
  else {
joined_r0x04024b92:
    puVar5 = puVar1;
    if ((undefined4 **)puVar5 != &_tcb) {
      puVar1 = (undefined4 *)*puVar5;
      iVar2 = puVar5[7];
      if (iVar2 != 0) {
        iVar6 = 0;
        do {
          sVar3 = *(sword *)(iVar2 + 10 + iVar6 * 2);
          if (((sVar3 != 0) && (*(sword *)(iVar2 + 10 + iVar6 * 2) = sVar3 + -1, sVar3 == 1)) &&
             (_tcp_usrreq(*(undefined4 *)(*(int *)(iVar2 + 0x20) + 0x18),0x13,0,iVar6,0),
             puVar5 != (undefined4 *)puVar1[1])) goto joined_r0x04024b92;
          iVar6 = iVar6 + 1;
        } while (iVar6 < 4);
        *(sword *)(iVar2 + 0x58) = *(sword *)(iVar2 + 0x58) + 1;
        if (*(sword *)(iVar2 + 0x5a) != 0) {
          *(sword *)(iVar2 + 0x5a) = *(sword *)(iVar2 + 0x5a) + 1;
        }
      }
      goto joined_r0x04024b92;
    }
    bVar8 = 0xffff05ff < _tcp_iss;
    bVar7 = SCARRY4(_tcp_iss,64000);
    _tcp_iss = _tcp_iss + 64000;
    bVar4 = bVar8 << 4 | ((int)_tcp_iss < 0) << 3 | (_tcp_iss == 0) << 2 | bVar7 << 1 | bVar8;
  }
  return bVar4;
}
/* GHIDRADEC_FUNCTION index=767 start=0x4024c10 */

void _tcp_canceltimers(int param_1)

{
  word wVar1;
  int iVar2;
  sword sVar3;
  
  iVar2 = 3;
  do {
    do {
      *(undefined2 *)(param_1 + 10 + iVar2 * 2) = 0;
      wVar1 = (word)((uint)iVar2 >> 0x10);
      sVar3 = (sword)iVar2 + -1;
      iVar2 = CONCAT22(wVar1,sVar3);
    } while (sVar3 != -1);
    iVar2 = (uint)wVar1 * 0x10000 + -1;
  } while (wVar1 != 0);
  return;
}
/* GHIDRADEC_FUNCTION index=768 start=0x4024c2c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int _tcp_timers(int param_1,int param_2)

{
  sword sVar2;
  word wVar3;
  int iVar1;
  uint uVar4;
  
  if (param_2 == 1) {
    dword_40BBD58 = dword_40BBD58 + 1;
    _tcp_setpersist(param_1);
    *(undefined *)(param_1 + 0x1a) = 1;
    _tcp_output(param_1);
    *(undefined *)(param_1 + 0x1a) = 0;
    return param_1;
  }
  if (param_2 < 2) {
    if (param_2 != 0) {
      return param_1;
    }
    sVar2 = *(sword *)(param_1 + 0x12);
    *(sword *)(param_1 + 0x12) = sVar2 + 1;
    if ((sword)(sVar2 + 1) < 0xd) {
      dword_40BBD54 = dword_40BBD54 + 1;
      sVar2 = (sword)*(undefined4 *)(_tcp_backoff + *(sword *)(param_1 + 0x12) * 4) *
              (*(sword *)(param_1 + 0x62) + (*(sword *)(param_1 + 0x60) >> 3));
      *(sword *)(param_1 + 0x14) = sVar2;
      if ((int)sVar2 < (int)(uint)*(word *)(param_1 + 100)) {
        *(word *)(param_1 + 0x14) = *(word *)(param_1 + 100);
      }
      else if (0x80 < sVar2) {
        *(undefined2 *)(param_1 + 0x14) = 0x80;
      }
      *(undefined2 *)(param_1 + 10) = *(undefined2 *)(param_1 + 0x14);
      if (3 < *(sword *)(param_1 + 0x12)) {
        _in_losing(*(undefined4 *)(param_1 + 0x20));
        *(sword *)(param_1 + 0x62) = (*(sword *)(param_1 + 0x60) >> 2) + *(sword *)(param_1 + 0x62);
        *(undefined2 *)(param_1 + 0x60) = 0;
      }
      *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(param_1 + 0x24);
      *(undefined2 *)(param_1 + 0x5a) = 0;
      wVar3 = *(word *)(param_1 + 0x3c);
      if (*(word *)(param_1 + 0x54) < *(word *)(param_1 + 0x3c)) {
        wVar3 = *(word *)(param_1 + 0x54);
      }
      uVar4 = (uint)(wVar3 >> 1) / (uint)*(word *)(param_1 + 0x18);
      sVar2 = (sword)uVar4;
      if (uVar4 < 2) {
        sVar2 = 2;
      }
      *(word *)(param_1 + 0x54) = *(word *)(param_1 + 0x18);
      *(sword *)(param_1 + 0x56) = *(sword *)(param_1 + 0x18) * sVar2;
      *(undefined2 *)(param_1 + 0x16) = 0;
      _tcp_output(param_1);
      return param_1;
    }
    *(undefined2 *)(param_1 + 0x12) = 0xc;
    dword_40BBD50 = dword_40BBD50 + 1;
  }
  else {
    if (param_2 != 2) {
      if (param_2 != 3) {
        return param_1;
      }
      if ((*(sword *)(param_1 + 8) != 10) && (*(sword *)(param_1 + 0x58) <= __tcp_maxidle)) {
        *(undefined2 *)(param_1 + 0x10) = uRam040aeb82;
        return param_1;
      }
      iVar1 = _tcp_close(param_1);
      return iVar1;
    }
    dword_40BBD5C = dword_40BBD5C + 1;
    if (3 < *(sword *)(param_1 + 8)) {
      if (((*(byte *)(*(int *)(*(int *)(param_1 + 0x20) + 0x18) + 3) & 8) == 0) ||
         (5 < *(sword *)(param_1 + 8))) {
        *(undefined2 *)(param_1 + 0xe) = word_40AEB7E;
        return param_1;
      }
      if ((int)*(sword *)(param_1 + 0x58) < __tcp_maxidle + __tcp_keepidle) {
        dword_40BBD60 = dword_40BBD60 + 1;
        _tcp_respond(param_1,*(undefined4 *)(param_1 + 0x1c),0,*(undefined4 *)(param_1 + 0x40),
                     *(int *)(param_1 + 0x24) + -1,0);
        *(undefined2 *)(param_1 + 0xe) = uRam040aeb82;
        return param_1;
      }
    }
    dword_40BBD64 = dword_40BBD64 + 1;
  }
  iVar1 = _tcp_drop(param_1,0x3c);
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=769 start=0x4024e2a */

int _tcp_usrreq(int param_1,uint param_2,int param_3,uint param_4,int param_5)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined2 *puVar5;
  int unaff_A3;
  
  iVar3 = 0;
  if (param_2 == 0xb) {
    iVar3 = _in_control(param_1,param_3,param_4,param_5);
  }
  else if ((param_5 == 0) || (*(sword *)(param_5 + 8) == 0)) {
    iVar2 = *(int *)(param_1 + 8);
    if (iVar2 == 0) {
      if (param_2 != 0) {
        return 0x16;
      }
      iVar4 = 0;
    }
    else {
      unaff_A3 = *(int *)(iVar2 + 0x1c);
      iVar4 = (int)*(sword *)(unaff_A3 + 8);
    }
    switch(param_2) {
    case :
      if (iVar2 == 0) {
        iVar3 = _tcp_attach(param_1);
        if (iVar3 == 0) {
          if ((*(char *)(param_1 + 3) < '\0') && (*(sword *)(param_1 + 4) == 0)) {
            *(undefined2 *)(param_1 + 4) = 0x78;
          }
          unaff_A3 = *(int *)(*(int *)(param_1 + 8) + 0x1c);
        }
      }
      else {
        iVar3 = 0x38;
      }
      break;
    case :
      if (*(sword *)(unaff_A3 + 8) < 2) {
        unaff_A3 = _tcp_close(unaff_A3);
      }
      else {
        unaff_A3 = _tcp_disconnect(unaff_A3);
      }
      break;
    case :
      iVar3 = _in_pcbbind(iVar2,param_4);
      break;
    case :
      if (*(sword *)(iVar2 + 0x16) == 0) {
        iVar3 = _in_pcbbind(iVar2,0);
      }
      if (iVar3 == 0) {
        *(undefined2 *)(unaff_A3 + 8) = 1;
      }
      break;
    case :
      if (((*(sword *)(iVar2 + 0x16) != 0) || (iVar3 = _in_pcbbind(iVar2,0), iVar3 == 0)) &&
         (iVar3 = _in_pcbconnect(iVar2,param_4), iVar3 == 0)) {
        iVar3 = _tcp_template(unaff_A3);
        *(int *)(unaff_A3 + 0x1c) = iVar3;
        if (iVar3 == 0) {
          _in_pcbdisconnect(iVar2);
          iVar3 = 0x37;
        }
        else {
          _soisconnecting(param_1);
          _tcpstat = _tcpstat + 1;
          *(undefined2 *)(unaff_A3 + 8) = 2;
          *(undefined2 *)(unaff_A3 + 0xe) = 0x96;
          *(int *)(unaff_A3 + 0x38) = _tcp_iss;
          _tcp_iss = _tcp_iss + 64000;
          uVar1 = *(undefined4 *)(unaff_A3 + 0x38);
          *(undefined4 *)(unaff_A3 + 0x2c) = uVar1;
          *(undefined4 *)(unaff_A3 + 0x50) = uVar1;
          *(undefined4 *)(unaff_A3 + 0x28) = uVar1;
          *(undefined4 *)(unaff_A3 + 0x24) = uVar1;
          iVar3 = _tcp_output(unaff_A3);
        }
      }
      break;
    case :
      puVar5 = (undefined2 *)(*(int *)(param_4 + 4) + param_4);
      *(undefined2 *)(param_4 + 8) = 0x10;
      *puVar5 = 2;
      puVar5[1] = *(undefined2 *)(iVar2 + 0x10);
      *(undefined4 *)(puVar5 + 2) = *(undefined4 *)(iVar2 + 0xc);
      break;
    case :
      unaff_A3 = _tcp_disconnect(unaff_A3);
      break;
    case :
      _socantsendmore(param_1);
      unaff_A3 = _tcp_usrclosed(unaff_A3);
      if (unaff_A3 == 0) {
        return 0;
      }
      iVar3 = _tcp_output(unaff_A3);
      break;
    case :
      _tcp_output(unaff_A3);
      break;
    case :
      _sbappend(param_1 + 0x38,param_3);
      iVar3 = _tcp_output(unaff_A3);
      break;
    case :
      unaff_A3 = _tcp_drop(unaff_A3,0x35);
      break;
    :
                    /* WARNING: Subroutine does not return */
      _panic(aTcpUsrreq);
    case :
      *(uint *)(param_3 + 0x2c) = (uint)*(word *)(param_1 + 0x3a);
      return 0;
    case :
      if ((((*(sword *)(param_1 + 0x52) == 0) && ((*(byte *)(param_1 + 7) & 0x40) == 0)) ||
          ((*(byte *)(param_1 + 2) & 1) != 0)) || ((*(byte *)(unaff_A3 + 0x68) & 2) != 0)) {
        iVar3 = 0x16;
      }
      else if ((*(byte *)(unaff_A3 + 0x68) & 1) == 0) {
        iVar3 = 0x23;
      }
      else {
        *(undefined2 *)(param_3 + 8) = 1;
        *(undefined *)(param_3 + *(int *)(param_3 + 4)) = *(undefined *)(unaff_A3 + 0x69);
        if ((param_4 & 2) == 0) {
          *(byte *)(unaff_A3 + 0x68) = *(byte *)(unaff_A3 + 0x68) ^ 3;
        }
      }
      break;
    case :
      iVar3 = (uint)*(word *)(param_1 + 0x3e) - (uint)*(word *)(param_1 + 0x3c);
      iVar2 = (uint)*(word *)(param_1 + 0x3a) - (uint)*(word *)(param_1 + 0x38);
      if (iVar3 < iVar2) {
        iVar2 = iVar3;
      }
      if (iVar2 < -0x200) {
        _m_freem(param_3);
        iVar3 = 0x37;
      }
      else {
        _sbappend((word *)(param_1 + 0x38),param_3);
        *(uint *)(unaff_A3 + 0x2c) = *(int *)(unaff_A3 + 0x24) + (uint)*(word *)(param_1 + 0x38);
        *(undefined *)(unaff_A3 + 0x1a) = 1;
        iVar3 = _tcp_output(unaff_A3);
        *(undefined *)(unaff_A3 + 0x1a) = 0;
      }
      break;
    case :
      _in_setsockaddr(iVar2,param_4);
      break;
    case :
      _in_setpeeraddr(iVar2,param_4);
      break;
    case :
      iVar3 = 0x2d;
      break;
    case :
      unaff_A3 = _tcp_timers(unaff_A3,param_4);
      param_2 = param_4 << 8 | param_2;
    }
    if ((unaff_A3 != 0) && ((*(byte *)(param_1 + 3) & 1) != 0)) {
      _tcp_trace(2,iVar4,unaff_A3,0,param_2);
    }
  }
  else {
    iVar3 = 0x16;
  }
  return iVar3;
}
/* GHIDRADEC_FUNCTION index=770 start=0x4025208 */

undefined4 _tcp_ctloutput(int param_1,int param_2,int param_3,int param_4,int *param_5)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  iVar1 = *(int *)(*(int *)(param_2 + 8) + 0x1c);
  if (param_3 == 6) {
    if (param_1 == 0) {
      iVar2 = _m_get(1,10);
      *param_5 = iVar2;
      *(undefined2 *)(iVar2 + 8) = 4;
      if (param_4 == 1) {
        *(uint *)(iVar2 + *(int *)(iVar2 + 4)) = *(byte *)(iVar1 + 0x1b) & 4;
      }
      else if (param_4 == 2) {
        *(uint *)(iVar2 + *(int *)(iVar2 + 4)) = (uint)*(word *)(iVar1 + 0x18);
      }
      else {
        uVar3 = 0x16;
      }
    }
    else if (param_1 == 1) {
      iVar2 = *param_5;
      if (((param_4 == 1) && (iVar2 != 0)) && (3 < *(word *)(iVar2 + 8))) {
        if (*(int *)(iVar2 + *(int *)(iVar2 + 4)) == 0) {
          *(byte *)(iVar1 + 0x1b) = *(byte *)(iVar1 + 0x1b) & 0xfb;
        }
        else {
          *(byte *)(iVar1 + 0x1b) = *(byte *)(iVar1 + 0x1b) | 4;
        }
      }
      else {
        uVar3 = 0x16;
      }
      if (iVar2 != 0) {
        _m_free(iVar2);
      }
    }
  }
  else {
    uVar3 = _ip_ctloutput(param_1,param_2,param_3,param_4,param_5);
  }
  return uVar3;
}
/* GHIDRADEC_FUNCTION index=771 start=0x40252e6 */

int _tcp_attach(int param_1)

{
  undefined4 uVar1;
  word wVar2;
  int iVar3;
  
  if (((*(sword *)(param_1 + 0x3a) == 0) || (*(sword *)(param_1 + 0x24) == 0)) &&
     (iVar3 = _soreserve(param_1,_tcp_sendspace,_tcp_recvspace), iVar3 != 0)) {
    return iVar3;
  }
  iVar3 = _in_pcballoc(param_1,&_tcb);
  if (iVar3 == 0) {
    uVar1 = *(undefined4 *)(param_1 + 8);
    iVar3 = _tcp_newtcpcb(uVar1);
    if (iVar3 == 0) {
      wVar2 = *(word *)(param_1 + 6);
      *(word *)(param_1 + 6) = wVar2 & 0xfffe;
      _in_pcbdetach(uVar1);
      *(word *)(param_1 + 6) = wVar2 & 1 | *(word *)(param_1 + 6);
      iVar3 = 0x37;
    }
    else {
      *(undefined2 *)(iVar3 + 8) = 0;
      iVar3 = 0;
    }
  }
  return iVar3;
}
/* GHIDRADEC_FUNCTION index=772 start=0x4025376 */

int _tcp_disconnect(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x20) + 0x18);
  if (*(sword *)(param_1 + 8) < 4) {
    iVar1 = _tcp_close(param_1);
  }
  else if ((*(char *)(iVar1 + 3) < '\0') && (*(sword *)(iVar1 + 4) == 0)) {
    iVar1 = _tcp_drop(param_1,0);
  }
  else {
    _soisdisconnecting(iVar1);
    _sbflush(iVar1 + 0x22);
    iVar1 = _tcp_usrclosed(param_1);
    if (iVar1 != 0) {
      _tcp_output(iVar1);
    }
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=773 start=0x40253f2 */

int _tcp_usrclosed(int param_1)

{
  switch(*(undefined2 *)(param_1 + 8)) {
  case :
  case :
  case :
    *(undefined2 *)(param_1 + 8) = 0;
    param_1 = _tcp_close(param_1);
    break;
  case :
  case :
    *(undefined2 *)(param_1 + 8) = 6;
    break;
  case :
    *(undefined2 *)(param_1 + 8) = 8;
  }
  if ((param_1 != 0) && (8 < *(sword *)(param_1 + 8))) {
    _soisdisconnected(*(undefined4 *)(*(int *)(param_1 + 0x20) + 0x18));
  }
  return param_1;
}
/* GHIDRADEC_FUNCTION index=774 start=0x402546e */

void _udp_init(void)

{
  dword_40B6A1C = &_udb;
  _udb = &_udb;
  return;
}
/* GHIDRADEC_FUNCTION index=775 start=0x4025484 */

void _udp_input(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  sword sVar10;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar11;
  uint uVar12;
  byte *pbVar13;
  
  if (((0x7c < *(uint *)(param_1 + 4)) || (*(word *)(param_1 + 8) < 0x1c)) &&
     (param_1 = _m_pullup(param_1,0x1c), param_1 == 0)) {
    _udpstat = _udpstat + 1;
    return;
  }
  pbVar13 = (byte *)(*(int *)(param_1 + 4) + param_1);
  if (5 < (*pbVar13 & 0xf)) {
    _ip_stripoptions(pbVar13,0);
  }
  uVar11 = (uint)*(word *)(pbVar13 + 0x18);
  uVar12 = (uint)*(sword *)(pbVar13 + 2);
  if (uVar11 != uVar12) {
    if ((int)uVar12 < (int)uVar11) {
      dword_40B6A5C = dword_40B6A5C + 1;
      goto loc_40257AA;
    }
    _m_adj(param_1,uVar11 - uVar12);
  }
  uVar3 = *(undefined4 *)pbVar13;
  uVar4 = *(undefined4 *)(pbVar13 + 4);
  uVar5 = *(undefined4 *)(pbVar13 + 8);
  uVar6 = *(undefined4 *)(pbVar13 + 0xc);
  uVar1 = *(undefined4 *)(pbVar13 + 0x10);
  if ((_udpcksum != 0) && (*(sword *)(pbVar13 + 0x1a) != 0)) {
    pbVar13[4] = 0;
    pbVar13[5] = 0;
    pbVar13[6] = 0;
    pbVar13[7] = 0;
    pbVar13[0] = 0;
    pbVar13[1] = 0;
    pbVar13[2] = 0;
    pbVar13[3] = 0;
    pbVar13[8] = 0;
    *(undefined2 *)(pbVar13 + 10) = *(undefined2 *)(pbVar13 + 0x18);
    sVar10 = _in_cksum(param_1,uVar11 + 0x14);
    *(sword *)(pbVar13 + 0x1a) = sVar10;
    if (sVar10 != 0) {
      dword_40B6A58 = dword_40B6A58 + 1;
      goto loc_40257AA;
    }
  }
  if (((*(uint *)(pbVar13 + 0x10) & 0xf0000000) == 0xe0000000) ||
     (iVar7 = _in_broadcast(*(uint *)(pbVar13 + 0x10)), iVar7 != 0)) {
    word_40AEBCA = *(undefined2 *)(pbVar13 + 0x14);
    dword_40AEBCC = *(undefined4 *)(pbVar13 + 0xc);
    *(sword *)(param_1 + 8) = *(sword *)(param_1 + 8) + -0x1c;
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 0x1c;
    iVar7 = 0;
    for (puVar2 = _udb; (undefined4 **)puVar2 != &_udb; puVar2 = (undefined4 *)*puVar2) {
      if (((*(sword *)(pbVar13 + 0x16) == *(sword *)((int)puVar2 + 0x16)) &&
          ((*(int *)((int)puVar2 + 0x12) == 0 ||
           (*(int *)((int)puVar2 + 0x12) == *(int *)(pbVar13 + 0x10))))) &&
         ((puVar2[3] == 0 ||
          ((puVar2[3] == *(int *)(pbVar13 + 0xc) &&
           (*(sword *)(pbVar13 + 0x14) == *(sword *)(puVar2 + 4))))))) {
        if ((iVar7 != 0) && (iVar8 = _m_copy(param_1,0,1000000000), iVar8 != 0)) {
          iVar9 = _sbappendaddr(iVar7 + 0x22,&_udp_in,iVar8,0);
          if (iVar9 == 0) {
            _m_freem(iVar8);
          }
          else {
            _sowakeup(iVar7,iVar7 + 0x22);
          }
        }
        iVar7 = puVar2[6];
        if ((*(byte *)(iVar7 + 3) & 4) == 0) break;
      }
    }
    if (iVar7 != 0) {
      iVar8 = _sbappendaddr(iVar7 + 0x22,&_udp_in,param_1,0);
      if (iVar8 != 0) {
        _sowakeup(iVar7,iVar7 + 0x22);
        return;
      }
    }
  }
  else {
    iVar7 = _in_pcblookup(&_udb,*(undefined4 *)(pbVar13 + 0xc),*(undefined2 *)(pbVar13 + 0x14),
                          *(undefined4 *)(pbVar13 + 0x10),*(undefined2 *)(pbVar13 + 0x16),1);
    if (iVar7 == 0) {
      for (iVar7 = _in_ifaddr; iVar7 != 0; iVar7 = *(int *)(iVar7 + 0x40)) {
        if (((*(byte *)(*(int *)(iVar7 + 0x20) + 0xd) & 2) != 0) &&
           ((((uVar11 = *(uint *)(pbVar13 + 0x10) ^ *(uint *)(iVar7 + 0x28),
              ~*(uint *)(iVar7 + 0x2c) == uVar11 || (uVar11 == 0)) ||
             (uVar11 = *(uint *)(pbVar13 + 0x10) ^ *(uint *)(iVar7 + 0x30),
             ~*(uint *)(iVar7 + 0x34) == uVar11)) || (uVar11 == 0)))) goto loc_40257AA;
      }
      iVar7 = *(int *)(pbVar13 + 0x10);
      if (((iVar7 != -1) && (iVar7 != 0)) && (iVar7 = _in_broadcast(iVar7), iVar7 == 0)) {
        *(undefined4 *)pbVar13 = uVar3;
        *(undefined4 *)(pbVar13 + 4) = uVar4;
        *(undefined4 *)(pbVar13 + 8) = uVar5;
        *(undefined4 *)(pbVar13 + 0xc) = uVar6;
        *(undefined4 *)(pbVar13 + 0x10) = uVar1;
        _icmp_error(pbVar13,3,3,param_2,0);
        return;
      }
    }
    else {
      word_40AEBCA = *(undefined2 *)(pbVar13 + 0x14);
      dword_40AEBCC = *(undefined4 *)(pbVar13 + 0xc);
      *(sword *)(param_1 + 8) = *(sword *)(param_1 + 8) + -0x1c;
      *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 0x1c;
      iVar8 = _sbappendaddr(*(int *)(iVar7 + 0x18) + 0x22,&_udp_in,param_1,0);
      if (iVar8 != 0) {
        _sowakeup(*(int *)(iVar7 + 0x18),*(int *)(iVar7 + 0x18) + 0x22);
        return;
      }
    }
  }
loc_40257AA:
  _m_freem(param_1);
  return;
}
/* GHIDRADEC_FUNCTION index=776 start=0x40257bc */

void _udp_notify(int param_1)

{
  _sowakeup(*(int *)(param_1 + 0x18),*(int *)(param_1 + 0x18) + 0x22);
  _sowakeup(*(int *)(param_1 + 0x18),*(int *)(param_1 + 0x18) + 0x38);
  return;
}
/* GHIDRADEC_FUNCTION index=777 start=0x40257f2 */

void _udp_ctlinput(uint param_1,undefined4 param_2,byte *param_3)

{
  undefined2 uVar1;
  undefined4 uVar2;
  undefined2 uVar3;
  
  if ((param_1 == 1) || ((param_1 < 0x16 && (_inetctlerrmap[param_1] != '\0')))) {
    if (param_3 == (byte *)0x0) {
      uVar3 = 0;
      uVar1 = 0;
      uVar2 = _zeroin_addr;
    }
    else {
      uVar3 = *(undefined2 *)(param_3 + (*param_3 & 0xf) * 4);
      uVar1 = *(undefined2 *)(param_3 + (*param_3 & 0xf) * 4 + 2);
      uVar2 = *(undefined4 *)(param_3 + 0xc);
    }
    _in_pcbnotify(&_udb,param_2,uVar1,uVar2,uVar3,param_1,_udp_notify);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=778 start=0x4025874 */

undefined4 _udp_output(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  sword sVar3;
  undefined4 *puVar4;
  int iVar5;
  
  puVar1 = _mfree;
  iVar5 = 0;
  for (puVar4 = param_2; puVar4 != (undefined4 *)0x0; puVar4 = (undefined4 *)*puVar4) {
    iVar5 = *(sword *)(puVar4 + 2) + iVar5;
  }
  if (_mfree == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)_m_more(0,2);
  }
  else {
    if (*(sword *)((int)_mfree + 10) != 0) {
                    /* WARNING: Subroutine does not return */
      _panic(&aMget);
    }
    *(undefined2 *)((int)_mfree + 10) = 2;
    word_40B61CC = word_40B61CC + -1;
    word_40B61D0 = word_40B61D0 + 1;
    puVar4 = (undefined4 *)*_mfree;
    *_mfree = 0;
    _mfree = puVar4;
    puVar1[1] = 0xc;
  }
  if (puVar1 == (undefined4 *)0x0) {
    _m_freem(param_2);
    uVar2 = 0x37;
  }
  else {
    puVar1[1] = 0x60;
    *(undefined2 *)(puVar1 + 2) = 0x1c;
    *puVar1 = param_2;
    puVar4 = (undefined4 *)(puVar1[1] + (int)puVar1);
    puVar4[1] = 0;
    *puVar4 = 0;
    *(undefined *)(puVar4 + 2) = 0;
    *(undefined *)((int)puVar4 + 9) = 0x11;
    *(sword *)((int)puVar4 + 10) = (sword)iVar5 + 8;
    puVar4[3] = *(undefined4 *)(param_1 + 0x12);
    puVar4[4] = *(undefined4 *)(param_1 + 0xc);
    *(undefined2 *)(puVar4 + 5) = *(undefined2 *)(param_1 + 0x16);
    *(undefined2 *)((int)puVar4 + 0x16) = *(undefined2 *)(param_1 + 0x10);
    *(undefined2 *)(puVar4 + 6) = *(undefined2 *)((int)puVar4 + 10);
    *(undefined2 *)((int)puVar4 + 0x1a) = 0;
    if (_udpcksum != 0) {
      sVar3 = _in_cksum(puVar1,iVar5 + 0x1c);
      *(sword *)((int)puVar4 + 0x1a) = sVar3;
      if (sVar3 == 0) {
        *(undefined2 *)((int)puVar4 + 0x1a) = 0xffff;
      }
    }
    *(sword *)((int)puVar4 + 2) = (sword)iVar5 + 0x1c;
    *(undefined *)(puVar4 + 2) = byte_40AEBC7;
    uVar2 = _ip_output(puVar1,*(undefined4 *)(param_1 + 0x34),param_1 + 0x20,
                       *(word *)(*(int *)(param_1 + 0x18) + 2) & 0x32 | 2,
                       *(undefined4 *)(param_1 + 0x38));
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=779 start=0x40259b8 */

int _udp_usrreq(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_D6;
  
  iVar1 = *(int *)(param_1 + 8);
  iVar2 = 0;
  if (param_2 == 0xb) {
    iVar1 = _in_control(param_1,param_3,param_4,param_5);
    return iVar1;
  }
  if (((param_5 != 0) && (*(sword *)(param_5 + 8) != 0)) || ((iVar1 == 0 && (param_2 != 0)))) {
loc_4025A7E:
    iVar2 = 0x16;
    goto loc_4025BC4;
  }
  switch(param_2) {
  case :
    if (iVar1 == 0) {
      iVar2 = _in_pcballoc(param_1,&_udb);
      if (iVar2 == 0) {
        iVar2 = _soreserve(param_1,_udp_sendspace,_udp_recvspace);
      }
      break;
    }
    goto loc_4025A7E;
  case :
    _in_pcbdetach(iVar1);
    break;
  case :
    iVar2 = _in_pcbbind(iVar1,param_4);
    break;
  case :
  case :
  case :
  case :
  case :
  case :
  case :
  case :
    iVar2 = 0x2d;
    break;
  case :
    if (*(int *)(iVar1 + 0xc) == 0) {
      iVar2 = _in_pcbconnect(iVar1,param_4);
      if (iVar2 == 0) {
        _soisconnected(param_1);
      }
      break;
    }
    goto loc_4025B2C;
  case :
    if (*(int *)(iVar1 + 0xc) != 0) {
      _in_pcbdisconnect(iVar1);
      *(word *)(param_1 + 6) = *(word *)(param_1 + 6) & 0xfffd;
      break;
    }
loc_4025B4C:
    iVar2 = 0x39;
    break;
  case :
    _socantsendmore(param_1);
    break;
  case :
  case :
    return 0x2d;
  case :
    if (param_4 == 0) {
      if (*(int *)(iVar1 + 0xc) != 0) goto loc_4025B50;
      goto loc_4025B4C;
    }
    unaff_D6 = *(undefined4 *)(iVar1 + 0x12);
    if (*(int *)(iVar1 + 0xc) == 0) {
      iVar2 = _in_pcbconnect(iVar1,param_4);
      if (iVar2 != 0) break;
loc_4025B50:
      iVar2 = _udp_output(iVar1,param_3);
      param_3 = 0;
      if (param_4 != 0) {
        _in_pcbdisconnect(iVar1);
        *(undefined4 *)(iVar1 + 0x12) = unaff_D6;
      }
      break;
    }
loc_4025B2C:
    iVar2 = 0x38;
    break;
  case :
    _soisdisconnected(param_1);
    _in_pcbdetach(iVar1);
    break;
  :
                    /* WARNING: Subroutine does not return */
    _panic(aUdpUsrreq);
  case :
    return 0;
  case :
    _in_setsockaddr(iVar1,param_4);
    break;
  case :
    _in_setpeeraddr(iVar1,param_4);
  }
loc_4025BC4:
  if (param_3 != 0) {
    _m_freem(param_3);
  }
  return iVar2;
}
/* GHIDRADEC_FUNCTION index=780 start=0x4025be0 */

void _igmp_init(void)

{
  dword_40B3528 = 0xe0000001;
  return;
}
/* GHIDRADEC_FUNCTION index=781 start=0x4025bf2 */

void _igmp_input(int param_1,int param_2)

{
  byte *pbVar1;
  undefined4 *puVar2;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  int *piVar11;
  int iVar12;
  
  _igmpstat = _igmpstat + 1;
  pbVar1 = (byte *)(param_1 + *(uint *)(param_1 + 4));
  uVar5 = *pbVar1 & 0xf;
  iVar9 = uVar5 * 4;
  iVar8 = (int)*(sword *)(pbVar1 + 2);
  if (iVar8 < 8) {
    dword_40BBE20 = dword_40BBE20 + 1;
  }
  else {
    if (((0x7c < *(uint *)(param_1 + 4)) || ((int)*(sword *)(param_1 + 8) < iVar9 + 8)) &&
       (param_1 = _m_pullup(param_1,iVar9 + 8), param_1 == 0)) {
      dword_40BBE20 = dword_40BBE20 + 1;
      return;
    }
    *(int *)(param_1 + 4) = iVar9 + *(int *)(param_1 + 4);
    *(sword *)(param_1 + 8) = *(sword *)(param_1 + 8) - (sword)iVar9;
    pcVar4 = (char *)(*(int *)(param_1 + 4) + param_1);
    iVar8 = _in_cksum(param_1,iVar8);
    if (iVar8 == 0) {
      *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + uVar5 * -4;
      *(sword *)(param_1 + 8) = (sword)iVar9 + *(sword *)(param_1 + 8);
      iVar8 = _in_ifaddr;
      iVar9 = dword_40B3528;
      iVar12 = *(int *)(param_1 + 4) + param_1;
      if (*pcVar4 == '\x11') {
        dword_40BBE28 = dword_40BBE28 + 1;
        if (param_2 != _loifp) {
          if (*(int *)(iVar12 + 0x10) != dword_40B3528) {
            dword_40BBE2C = dword_40BBE2C + 1;
            goto loc_4025DC8;
          }
          piVar11 = (int *)0x0;
          piVar10 = (int *)0x0;
          iVar3 = _in_ifaddr;
          do {
            iVar6 = 0;
            if (iVar3 == 0) goto joined_r0x04025d06;
            piVar10 = *(int **)(iVar3 + 0x44);
            iVar3 = *(int *)(iVar3 + 0x40);
          } while (piVar10 == (int *)0x0);
          piVar11 = (int *)piVar10[5];
          iVar6 = iVar3;
joined_r0x04025d06:
          if (piVar10 != (int *)0x0) {
            iVar3 = iVar6;
            piVar7 = piVar11;
            if (((param_2 == piVar10[1]) && (piVar10[4] == 0)) && (iVar9 != *piVar10)) {
              piVar10[4] = (uint)(*piVar10 + *(int *)(iVar8 + 4) + _ipstat) % 0x32 + 1;
              dword_40AEC04 = 1;
            }
            while (piVar10 = piVar7, piVar10 == (int *)0x0) {
              iVar6 = 0;
              if (iVar3 == 0) goto joined_r0x04025d06;
              puVar2 = (undefined4 *)(iVar3 + 0x44);
              iVar3 = *(int *)(iVar3 + 0x40);
              piVar7 = (int *)*puVar2;
            }
            piVar11 = (int *)piVar10[5];
            iVar6 = iVar3;
            goto joined_r0x04025d06;
          }
        }
      }
      else if ((*pcVar4 == '\x12') && (dword_40BBE30 = dword_40BBE30 + 1, param_2 != _loifp)) {
        if (((*(uint *)(pcVar4 + 4) & 0xf0000000) != 0xe0000000) ||
           (*(uint *)(pcVar4 + 4) != *(uint *)(iVar12 + 0x10))) {
          dword_40BBE34 = dword_40BBE34 + 1;
          goto loc_4025DC8;
        }
        if (((*(uint *)(iVar12 + 0xc) & 0xff000000) == 0) && (iVar9 = _in_ifaddr, _in_ifaddr != 0))
        {
          do {
            if (param_2 == *(int *)(iVar9 + 0x20)) break;
            iVar9 = *(int *)(iVar9 + 0x40);
          } while (iVar9 != 0);
          if (iVar9 != 0) {
            *(undefined4 *)(iVar12 + 0xc) = *(undefined4 *)(iVar9 + 0x30);
          }
        }
        iVar9 = _in_ifaddr;
        if (_in_ifaddr != 0) {
          do {
            if (param_2 == *(int *)(iVar9 + 0x20)) break;
            iVar9 = *(int *)(iVar9 + 0x40);
          } while (iVar9 != 0);
          if ((iVar9 != 0) && (piVar11 = *(int **)(iVar9 + 0x44), piVar11 != (int *)0x0)) {
            do {
              if (*(int *)(pcVar4 + 4) == *piVar11) break;
              piVar11 = (int *)piVar11[5];
            } while (piVar11 != (int *)0x0);
            if (piVar11 != (int *)0x0) {
              piVar11[4] = 0;
              dword_40BBE38 = dword_40BBE38 + 1;
            }
          }
        }
      }
      unk_40AEBE8._0_4_ = *(undefined4 *)(iVar12 + 0xc);
      unk_40AEBF8._0_4_ = *(undefined4 *)(iVar12 + 0x10);
      _raw_input(param_1,&unk_40AEBE0,0x40aebe4,0x40aebf4);
      return;
    }
    dword_40BBE24 = dword_40BBE24 + 1;
  }
loc_4025DC8:
  _m_freem(param_1);
  return;
}
/* GHIDRADEC_FUNCTION index=782 start=0x4025e86 */

undefined4 _igmp_joingroup(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  undefined2 uVar3;
  undefined4 in_D0;
  uint uVar4;
  char cVar5;
  bool bVar6;
  
  uVar3 = (undefined2)((uint)in_D0 >> 0x10);
  bVar6 = *param_1 < dword_40B3528;
  if ((*param_1 == dword_40B3528) || (bVar6 = param_1[1] < _loifp, param_1[1] == _loifp)) {
    param_1[4] = 0;
    cVar5 = '\x01';
  }
  else {
    _igmp_sendreport(param_1);
    uVar1 = *param_1 + *(int *)(_in_ifaddr + 4) + _ipstat;
    uVar4 = uVar1 / 0x32;
    uVar2 = uVar4 * 0x19;
    bVar6 = CARRY4(uVar2,uVar2);
    uVar3 = (undefined2)(uVar4 * 0x32 >> 0x10);
    param_1[4] = uVar1 % 0x32 + 1;
    dword_40AEC04 = 1;
    cVar5 = '\0';
  }
  return CONCAT22(uVar3,(word)(byte)(bVar6 << 4 | cVar5 << 2));
}
/* GHIDRADEC_FUNCTION index=783 start=0x4025f0e */

void _igmp_leavegroup(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=784 start=0x4025f6a */

void _igmp_fasttimo(void)

{
  int iVar1;
  int iVar2;
  undefined auStack_c [8];
  
  if (dword_40AEC04 != 0) {
    dword_40AEC04 = 0;
    iVar2 = sub_4025F4C(auStack_c);
    while (iVar2 != 0) {
      iVar1 = *(int *)(iVar2 + 0x10);
      if (iVar1 != 0) {
        *(int *)(iVar2 + 0x10) = iVar1 + -1;
        if (iVar1 == 1) {
          _igmp_sendreport(iVar2);
        }
        else {
          dword_40AEC04 = 1;
        }
      }
      iVar2 = sub_4025F16(auStack_c);
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=785 start=0x4025fe2 */

uint _igmp_sendreport(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined2 uVar5;
  undefined4 *puVar6;
  undefined *puVar7;
  char cVar8;
  char cVar9;
  char cVar10;
  char cVar11;
  byte bVar12;
  
  puVar2 = _mfree;
  cVar8 = '\0';
  if (_mfree == (undefined4 *)0x0) {
    cVar9 = '\0';
    cVar10 = '\x01';
    cVar11 = '\0';
    bVar12 = 0;
    puVar2 = (undefined4 *)_m_more(0,2);
  }
  else {
    if (*(sword *)((int)_mfree + 10) != 0) {
                    /* WARNING: Subroutine does not return */
      _panic(&aMget);
    }
    *(undefined2 *)((int)_mfree + 10) = 2;
    word_40B61CC = word_40B61CC + -1;
    cVar8 = 0xfffe < word_40B61D0;
    word_40B61D0 = word_40B61D0 + 1;
    puVar3 = (undefined4 *)*_mfree;
    *_mfree = 0;
    _mfree = puVar3;
    puVar2[1] = 0xc;
    cVar9 = '\0';
    cVar10 = '\0';
    cVar11 = '\0';
    bVar12 = 0;
  }
  puVar3 = _mfree;
  uVar4 = (uint)(byte)(cVar8 << 4 | cVar9 << 3 | cVar10 << 2 | cVar11 << 1 | bVar12);
  if (puVar2 != (undefined4 *)0x0) {
    if (_mfree == (undefined4 *)0x0) {
      puVar3 = (undefined4 *)_m_more(0,0xe);
    }
    else {
      if (*(sword *)((int)_mfree + 10) != 0) {
                    /* WARNING: Subroutine does not return */
        _panic(&aMget);
      }
      *(undefined2 *)((int)_mfree + 10) = 0xe;
      word_40B61CC = word_40B61CC + -1;
      word_40B61E8 = word_40B61E8 + 1;
      puVar6 = (undefined4 *)*_mfree;
      *_mfree = 0;
      _mfree = puVar6;
      puVar3[1] = 0xc;
    }
    if (puVar3 == (undefined4 *)0x0) {
      uVar4 = _m_free(puVar2);
    }
    else {
      puVar2[1] = 0x74;
      *(undefined2 *)(puVar2 + 2) = 8;
      puVar7 = (undefined *)(puVar2[1] + (int)puVar2);
      *puVar7 = 0x12;
      puVar7[1] = 0;
      *(undefined4 *)(puVar7 + 4) = *param_1;
      *(undefined2 *)(puVar7 + 2) = 0;
      uVar5 = _in_cksum(puVar2,8);
      *(undefined2 *)(puVar7 + 2) = uVar5;
      puVar2[1] = puVar2[1] + -0x14;
      *(sword *)(puVar2 + 2) = *(sword *)(puVar2 + 2) + 0x14;
      iVar1 = puVar2[1];
      *(undefined *)((int)puVar2 + iVar1 + 1) = 0;
      *(undefined2 *)((int)puVar2 + iVar1 + 2) = 0x1c;
      *(undefined2 *)((int)puVar2 + iVar1 + 6) = 0;
      *(undefined *)((int)puVar2 + iVar1 + 9) = 2;
      *(undefined4 *)((int)puVar2 + iVar1 + 0xc) = 0;
      *(undefined4 *)((int)puVar2 + iVar1 + 0x10) = *(undefined4 *)(puVar7 + 4);
      puVar6 = (undefined4 *)(puVar3[1] + (int)puVar3);
      *puVar6 = param_1[1];
      *(undefined *)(puVar6 + 1) = 1;
      *(bool *)((int)puVar6 + 5) = _ip_mrouter != 0;
      _ip_output(puVar2,0,0,2,puVar3);
      uVar4 = _m_free(puVar3);
      dword_40BBE3C = dword_40BBE3C + 1;
    }
  }
  return uVar4;
}
/* GHIDRADEC_FUNCTION index=786 start=0x402616c */

undefined4 _ip_mrouter_cmd(void)

{
  return 0x2d;
}
/* GHIDRADEC_FUNCTION index=787 start=0x4026176 */

undefined4 _ip_mrouter_done(void)

{
  return 0;
}
/* GHIDRADEC_FUNCTION index=788 start=0x4026180 */

undefined4 _ip_mforward(void)

{
  return 0;
}
/* GHIDRADEC_FUNCTION index=789 start=0x402618a */

void _nfs_validate_caches(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined auStack_3e [58];
  
  _nfsgetattr(param_1,auStack_3e,param_2,param_3);
  return;
}
/* GHIDRADEC_FUNCTION index=790 start=0x40261a8 */

void _nfs_invalidate_caches(int param_1)

{
  _vnode_uncache(param_1);
  _mfs_invalidate(param_1);
  *(undefined4 *)(*(int *)(param_1 + 0x2e) + 0xb6) = 0;
  _dnlc_purge_vp(param_1);
  _binvalfree(param_1);
  return;
}
/* GHIDRADEC_FUNCTION index=791 start=0x40261e2 */

void _nfs_purge_caches(int param_1,undefined4 param_2)

{
  _sync_vp_invalidate(param_1,param_2);
  _vnode_uncache(param_1);
  *(undefined4 *)(*(int *)(param_1 + 0x2e) + 0xb6) = 0;
  _dnlc_purge_vp(param_1);
  _binvalfree(param_1);
  return;
}
/* GHIDRADEC_FUNCTION index=792 start=0x4026220 */

void _nfs_cache_check(int param_1,int param_2,int param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x2e);
  if ((-1 < *(char *)(iVar1 + 0x11)) &&
     (((param_2 != *(int *)(iVar1 + 0xa0) || (param_3 != *(int *)(iVar1 + 0xa4))) ||
      (param_4 != *(int *)(iVar1 + 0x90))))) {
    _nfs_purge_caches(param_1,param_5);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=793 start=0x4026266 */

void _nfs_attrcache(int param_1,undefined4 param_2)

{
  if (((*(byte *)(param_1 + 5) & 0x40) == 0) &&
     ((*(byte *)(*(int *)(*(int *)(param_1 + 0x24) + 0x126) + 0x14) & 8) == 0)) {
    _nattr_to_vattr(param_1,param_2,*(int *)(param_1 + 0x2e) + 0x7c);
    sub_4026304(param_1);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=794 start=0x40262ac */

void _nfs_attrcache_va(int param_1,undefined4 *param_2)

{
  if (((*(byte *)(param_1 + 5) & 0x40) == 0) &&
     ((*(byte *)(*(int *)(*(int *)(param_1 + 0x24) + 0x126) + 0x14) & 8) == 0)) {
    _bcopy(param_2,*(int *)(param_1 + 0x2e) + 0x7c,0x3a);
    *(undefined4 *)(param_1 + 0x28) = *param_2;
    sub_4026304(param_1);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=795 start=0x402640a */

int _nfs_getattr_otw(int param_1,int param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)_kalloc(0x48);
  iVar2 = _rfscall(*(undefined4 *)(*(int *)(param_1 + 0x24) + 0x126),1,_xdr_fhandle,
                   *(int *)(param_1 + 0x2e) + 0x3e,_xdr_attrstat,piVar1,param_3);
  if (iVar2 == 0) {
    iVar2 = *piVar1;
    if (iVar2 == 0) {
      _nattr_to_vattr(param_1,piVar1 + 1,param_2);
      *(uint *)(param_2 + 10) =
           *(uint *)(*(int *)(*(int *)(param_1 + 0x24) + 0x126) + 0x26) | 0xff00;
    }
    else if (iVar2 == 0x46) {
      _btrash(param_1);
      _nfs_invalidate_caches(param_1);
    }
  }
  _kfree(piVar1,0x48);
  return iVar2;
}
/* GHIDRADEC_FUNCTION index=796 start=0x40264b8 */

int _nfsgetattr(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = sub_402637E(param_1,param_2);
  if (iVar1 == 0) {
    iVar1 = _nfs_getattr_otw(param_1,param_2,param_3);
    if (iVar1 == 0) {
      _nfs_cache_check(param_1,*(undefined4 *)(param_2 + 0x24),*(undefined4 *)(param_2 + 0x28),
                       *(undefined4 *)(param_2 + 0x14),param_4);
      _nfs_attrcache_va(param_1,param_2);
    }
  }
  else {
    iVar1 = 0;
  }
  *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(*(int *)(param_1 + 0x2e) + 0x90);
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=797 start=0x402652a */

void _nattr_to_vattr(int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  uint uVar2;
  undefined uVar3;
  
  iVar1 = *(int *)((int)param_1 + 0x2e);
  *param_3 = *param_2;
  *(undefined2 *)(param_3 + 1) = *(undefined2 *)((int)param_2 + 6);
  *(undefined2 *)((int)param_3 + 6) = *(undefined2 *)((int)param_2 + 0xe);
  *(undefined2 *)(param_3 + 2) = *(undefined2 *)((int)param_2 + 0x12);
  uVar3 = _vfs_fixedmajor(param_1[9]);
  *(uint *)((int)param_3 + 10) =
       (uint)CONCAT11(uVar3,*(undefined *)(*(int *)(param_1[9] + 0x126) + 0x29));
  *(int *)((int)param_3 + 0xe) = param_2[10];
  *(undefined2 *)((int)param_3 + 0x12) = *(undefined2 *)((int)param_2 + 10);
  uVar2 = *(uint *)(*param_1 + 0x14);
  if (((uint)param_2[5] < uVar2) &&
     (((*(byte *)(*param_1 + 0x34) & 0x40) != 0 || ((*(byte *)(iVar1 + 0x5f) & 0x10) != 0)))) {
    param_3[5] = uVar2;
  }
  else {
    param_3[5] = param_2[5];
  }
  if ((*(uint *)(iVar1 + 0x90) < (uint)param_3[5]) || ((*(byte *)(iVar1 + 0x5f) & 0x10) == 0)) {
    *(int *)(iVar1 + 0x90) = param_3[5];
  }
  param_3[7] = param_2[0xb];
  param_3[8] = param_2[0xc];
  param_3[9] = param_2[0xd];
  param_3[10] = param_2[0xe];
  param_3[0xb] = param_2[0xf];
  param_3[0xc] = param_2[0x10];
  *(undefined2 *)(param_3 + 0xd) = *(undefined2 *)((int)param_2 + 0x1e);
  *(int *)((int)param_3 + 0x36) = param_2[8];
  if (*param_2 == 3) {
    param_3[6] = 0x800;
  }
  else if (*param_2 == 4) {
    param_3[6] = 0x2000;
  }
  else {
    param_3[6] = param_2[6];
  }
  if ((*param_2 == 4) && (param_2[7] == -1)) {
    *param_3 = 8;
    *(word *)(param_3 + 1) = *(word *)(param_3 + 1) & 0xfff | 0x1000;
    *(undefined2 *)(param_3 + 0xd) = 0;
    param_3[6] = param_2[6];
  }
  return;
}
/* GHIDRADEC_FUNCTION index=798 start=0x4026652 */

undefined4 _nfstsize(void)

{
  return 0x2000;
}
/* GHIDRADEC_FUNCTION index=799 start=0x4026660 */

void _vattr_to_nattr(int *param_1,int *param_2)

{
  sword sVar1;
  
  *param_2 = *param_1;
  sVar1 = *(sword *)(param_1 + 1);
  if (sVar1 == -1) {
    param_2[1] = -1;
  }
  else {
    *(undefined2 *)(param_2 + 1) = 0;
    *(sword *)((int)param_2 + 6) = sVar1;
  }
  if (*(sword *)((int)param_1 + 6) == -1) {
    param_2[3] = -1;
  }
  else {
    param_2[3] = (int)*(sword *)((int)param_1 + 6);
  }
  if (*(sword *)(param_1 + 2) == -1) {
    param_2[4] = -1;
  }
  else {
    param_2[4] = (int)*(sword *)(param_1 + 2);
  }
  param_2[9] = *(int *)((int)param_1 + 10);
  param_2[10] = *(int *)((int)param_1 + 0xe);
  param_2[2] = (int)*(sword *)((int)param_1 + 0x12);
  param_2[5] = param_1[5];
  param_2[0xb] = param_1[7];
  param_2[0xc] = param_1[8];
  param_2[0xd] = param_1[9];
  param_2[0xe] = param_1[10];
  param_2[0xf] = param_1[0xb];
  param_2[0x10] = param_1[0xc];
  param_2[7] = (int)*(sword *)(param_1 + 0xd);
  param_2[8] = *(int *)((int)param_1 + 0x36);
  param_2[6] = param_1[6];
  if (*param_1 == 8) {
    *param_2 = 4;
    param_2[7] = -1;
    param_2[1] = param_2[1] & 0xffff0fffU | 0x2000;
  }
  return;
}

