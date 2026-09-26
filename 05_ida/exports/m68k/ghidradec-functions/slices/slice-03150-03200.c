/* GHIDRADEC_FUNCTION index=3150 start=0x408a3bc */

void sub_408A3BC(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(_slot_id + 0x2200080);
  if (_dma_chip == 0x139) {
    *(undefined4 *)(_slot_id + 0x2000180) = 0x100000;
  }
  else {
    *puVar1 = 0x5000000;
  }
  if (dword_40B2286 != (code *)0x0) {
    (*dword_40B2286)(dword_40B5188);
  }
  if (_dma_chip != 0x139) {
    *puVar1 = 0x6000000;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=3151 start=0x408a41a */

void sub_408A41A(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = _mon_global;
  iVar2 = _curipl();
  if (iVar2 < 3) {
    *(byte *)(iVar1 + 4) = *(byte *)(iVar1 + 4) & 0xf7;
    byte_40B228B = 1;
    _delay(100000);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=3152 start=0x408a454 */

void sub_408A454(void)

{
  int iVar1;
  
  iVar1 = _mon_global;
  if (byte_40B228B != '\0') {
    byte_40B228B = '\0';
    *(byte *)(_mon_global + 4) = *(byte *)(_mon_global + 4) | 8;
    if (((((unk_40B6904 & 8) == 0) && (_console_o == 0)) && (0x17 < *(sword *)(iVar1 + 0x30c))) &&
       (iVar1 = *(int *)(iVar1 + 0x30e), iVar1 != 0)) {
      _callout_dispatch(2,iVar1,0);
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=3153 start=0x408aa58 */

void sub_408AA58(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined *puVar8;
  undefined *puVar9;
  undefined *puVar10;
  uint uStack_8;
  
  if (_dma_chip == 0x139) {
    puVar10 = (undefined *)(_slot_id_bmap + 0x2018100);
    puVar9 = (undefined *)(_slot_id_bmap + 0x2018101);
    puVar8 = (undefined *)(_slot_id_bmap + 0x2018103);
  }
  else {
    puVar10 = (undefined *)(_slot_id + 0x201c000);
    puVar9 = (undefined *)(_slot_id + 0x201c001);
    puVar8 = (undefined *)(_slot_id + 0x201c003);
  }
  uVar6 = (uint)(param_1 << 6) / 0x3d;
  iVar4 = 0;
  iVar7 = 0;
  do {
    uStack_8 = (uint)(byte)unk_40B2310[iVar7];
    uVar5 = uVar6 * uStack_8 >> 6;
    uVar3 = uVar6 * (byte)unk_40B2320[iVar7] >> 6;
    uVar2 = uVar6 * (byte)unk_40B2330[iVar7] >> 6;
    if (0xff < uVar5) {
      uVar5 = 0xff;
    }
    if (0xff < uVar3) {
      uVar3 = 0xff;
    }
    if (0xff < uVar2) {
      uVar2 = 0xff;
    }
    iVar1 = 0;
    do {
      *puVar10 = (char)iVar4;
      *puVar9 = (char)((uint)iVar4 >> 8);
      *puVar8 = (char)uVar5;
      *puVar8 = (char)uVar3;
      *puVar8 = (char)uVar2;
      iVar4 = iVar4 + 1;
      iVar1 = iVar1 + 1;
    } while (iVar1 < 0x10);
    iVar7 = iVar7 + 1;
  } while (iVar7 < 0x10);
  return;
}
/* GHIDRADEC_FUNCTION index=3154 start=0x408abca */

void sub_408ABCA(void)

{
  undefined4 *puVar1;
  undefined *puVar2;
  
  puVar2 = (undefined *)(_slot_id_bmap + 0x2018180);
  puVar1 = (undefined4 *)(_slot_id + 0x2200080);
  if (_dma_chip == 0x139) {
    *puVar2 = 5;
  }
  else {
    *puVar1 = 0x5000000;
  }
  if (dword_40B2286 != (code *)0x0) {
    (*dword_40B2286)(dword_40B5188);
  }
  if (_dma_chip == 0x139) {
    *puVar2 = 6;
  }
  else {
    *puVar1 = 0x6000000;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=3155 start=0x408b27a */

undefined4 sub_408B27A(void)

{
  int iVar1;
  undefined4 uVar2;
  int iStack_8;
  
  dword_40B5184 = _ev_register_screen(&iStack_8,0,&loc_408AFD0,&loc_408ACC2,&loc_408AD8A,&aHvO);
  if (dword_40B5184 < 0) {
    uVar2 = 6;
  }
  else {
    dword_40B518C = *(int *)(iStack_8 + 4);
    _bzero(dword_40B518C,*(undefined4 *)(iStack_8 + 8));
    *(undefined *)(dword_40B518C + 8) = 1;
    iVar1 = dword_40B518C;
    uVar2 = *(undefined4 *)(iStack_8 + 0x10);
    *(undefined4 *)(dword_40B518C + 0x30) = *(undefined4 *)(iStack_8 + 0xc);
    *(undefined4 *)(iVar1 + 0x34) = uVar2;
    uVar2 = 0;
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=3156 start=0x408bc84 */

undefined4 sub_408BC84(void)

{
  undefined4 uVar1;
  
  if ((_machine_type == '\0') && (_board_rev < 3)) {
    if (_board_rev == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  else {
    uVar1 = 2;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=3157 start=0x408bcb6 */

byte sub_408BCB6(int param_1)

{
  byte *pbVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  char cVar6;
  char cVar7;
  char cVar8;
  char cVar9;
  byte bVar10;
  
  iVar2 = param_1 * 0x164;
  piVar5 = (int *)(DAT_40b52d0 + iVar2);
  pbVar1 = *(byte **)(DAT_40b52d0 + iVar2 + 0xc);
  *(undefined4 *)(DAT_40b541c + iVar2) = 0xffffffff;
  *(undefined4 *)(DAT_40b541c + iVar2 + 8) = dword_40B2406;
  if (*piVar5 == 0) {
    if ((int)_scc_buffer < 0x20) {
      _scc_buffer = 1 << (_scc_buffer & 0x3f);
    }
    if (_scc_buffer - 0x20 < 0x3ffe1) {
      dword_40B51A8 = _scc_buffer;
    }
    else {
      dword_40B51A8 = 0x1000;
    }
    uVar3 = dword_40B51A8;
    if ((int)dword_40B51A8 < 0) {
      uVar3 = dword_40B51A8 + 1;
    }
    dword_40B51AC = (int)uVar3 >> 1;
    uVar3 = dword_40B51A8;
    if ((int)dword_40B51A8 < 0) {
      uVar3 = dword_40B51A8 + 3;
    }
    dword_40B51B0 = (int)uVar3 >> 2;
    uVar3 = dword_40B51A8;
    if ((int)dword_40B51A8 < 0) {
      uVar3 = dword_40B51A8 + 7;
    }
    dword_40B51B4 = (int)uVar3 >> 3;
    iVar4 = _kalloc(dword_40B51A8 * 2);
    *piVar5 = iVar4;
  }
  (&DAT_40b5400)[param_1 * 0x59] = (&DAT_40b5400)[param_1 * 0x59] & 0xfffffffe;
  bVar10 = 0x40;
  if (param_1 == 0) {
    bVar10 = 0x80;
  }
  cVar6 = '\0';
  _delay(1);
  *pbVar1 = 9;
  _delay(1);
  *pbVar1 = bVar10 | 2;
  _delay(10);
  _delay(1);
  *pbVar1 = 1;
  _delay(1);
  *pbVar1 = 0x13;
  _delay(1);
  *pbVar1 = 9;
  _delay(1);
  *pbVar1 = 10;
  _delay(1);
  *pbVar1 = 10;
  _delay(1);
  *pbVar1 = 0;
  _delay(1);
  *pbVar1 = 0xb;
  _delay(1);
  *pbVar1 = 0x50;
  bVar10 = 0x80;
  if (((int)dword_40B51B8 < 0) || (cVar6 = 1 < dword_40B51B8, 1 < (int)dword_40B51B8)) {
    if (((&DAT_40b5400)[param_1 * 0x59] & 0x40) != 0) {
      bVar10 = 0xa0;
    }
    if (((&DAT_40b5400)[param_1 * 0x59] & 4) != 0) {
      bVar10 = bVar10 | 8;
    }
  }
  else if ((*(byte *)((int)&DAT_40b5400 + iVar2 + 3) & 4) != 0) {
    bVar10 = 0xa0;
  }
  _delay(1);
  *pbVar1 = 0xf;
  _delay(1);
  *pbVar1 = bVar10;
  _delay(1);
  *pbVar1 = 0x30;
  _delay(1);
  *pbVar1 = 0x28;
  _delay(1);
  *pbVar1 = 0x10;
  *(uint *)(DAT_40b541c + iVar2 + 4) = *(uint *)(DAT_40b541c + iVar2 + 4) & 7;
  *(int *)(DAT_40b52d0 + iVar2 + 8) = *piVar5;
  *(int *)(DAT_40b52d0 + iVar2 + 4) = *piVar5;
  cVar7 = param_1 < 0;
  cVar8 = param_1 == 0;
  cVar9 = '\0';
  bVar10 = 0;
  sub_408CD86(param_1);
  return cVar6 << 4 | cVar7 << 3 | cVar8 << 2 | cVar9 << 1 | bVar10;
}
/* GHIDRADEC_FUNCTION index=3158 start=0x408be8e */

void sub_408BE8E(int param_1,int param_2)

{
  int iVar1;
  byte *pbVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  byte bVar8;
  undefined4 uVar7;
  int unaff_D2;
  byte bVar9;
  byte bVar10;
  byte bVar11;
  undefined8 uVar12;
  undefined4 uStack_c;
  byte bStack_5;
  
  iVar1 = param_1 * 0x86;
  iVar4 = _ttynty(unk_40B51BC + iVar1);
  iVar5 = param_1 * 0x164;
  pbVar2 = (byte *)(&DAT_40b52dc)[param_1 * 0x59];
  if (unk_40B51BC[iVar1 + 0x47] == 0) {
    sub_408CF32(param_1,0,0);
  }
  else {
    if (0x13 < (byte)unk_40B51BC[iVar1 + 0x47]) {
      unk_40B51BC[iVar1 + 0x47] = 0xd;
    }
    iVar6 = _zs_tc(*(undefined4 *)(unk_40B23D2 + (char)unk_40B51BC[iVar1 + 0x47] * 4),0x10);
    bVar10 = 0;
    bVar11 = 0x40;
    bVar9 = 0;
    if ((*(uint *)(unk_40B51BC + iVar1 + 0x3a) & 0xa200020) == 0) {
      uVar3 = *(uint *)(iVar4 + 0x10) & 0x300;
      if (uVar3 == 0x100) {
        unaff_D2 = 6;
        uStack_c = 0x3f;
      }
      else if (uVar3 < 0x101) {
        if (uVar3 == 0) {
          unaff_D2 = 5;
          uStack_c = 0x1f;
        }
      }
      else if (uVar3 == 0x200) {
        unaff_D2 = 7;
        uStack_c = 0x7f;
      }
      else if (uVar3 == 0x300) {
        unaff_D2 = 8;
        uStack_c = 0xff;
      }
      if ((*(byte *)(iVar4 + 0x12) & 0x10) != 0) {
        if ((*(uint *)(unk_40B51BC + iVar1 + 0x3a) & 0xc0) == 0) {
          unaff_D2 = unaff_D2 + 1;
        }
        else {
          bVar11 = 0x41;
          if ((char)*(uint *)(unk_40B51BC + iVar1 + 0x3a) < '\0') {
            bVar11 = 0x43;
          }
        }
      }
    }
    else {
      unaff_D2 = 8;
      uStack_c = 0xff;
    }
    switch(unaff_D2) {
    case :
      bVar10 = 0x80;
      bVar9 = 0x40;
      break;
    case :
      bVar10 = 0x40;
      bVar9 = 0x20;
      break;
    case :
    case :
      bVar10 = 0xc0;
      bVar9 = 0x60;
    }
    if (((*(uint *)(iVar4 + 0x10) & 0x400) == 0) &&
       (((*(uint *)(iVar4 + 0x10) & 0x10000) == 0 || (unk_40B51BC[iVar1 + 0x47] != '\x03')))) {
      bVar11 = bVar11 | 4;
    }
    else {
      bVar11 = bVar11 | 0xc;
    }
    if ((*(byte *)(iVar4 + 0x12) & 8) != 0) {
      bVar10 = bVar10 | 1;
    }
    if ((((bVar10 == DAT_40b541c[iVar5 + 0x14]) && (bVar11 == DAT_40b541c[iVar5 + 0x15])) &&
        (bVar9 == DAT_40b541c[iVar5 + 0x16])) && (iVar6 == *(int *)(DAT_40b541c + iVar5))) {
      *(undefined4 *)(DAT_40b53f4 + iVar5 + 8) = uStack_c;
    }
    else {
      _delay(1);
      *pbVar2 = 1;
      _delay(1);
      if ((param_2 != 0) && ((*pbVar2 & 1) == 0)) {
        uVar12 = __udivdi3(2,0xcb417800,(int)-(*(int *)(DAT_40b541c + iVar5 + 8) < 0),
                           *(int *)(DAT_40b541c + iVar5 + 8));
        _ns_sleep(uVar12);
      }
      _delay(1);
      *pbVar2 = 4;
      _delay(1);
      *pbVar2 = bVar11;
      _delay(1);
      *pbVar2 = 3;
      _delay(1);
      *pbVar2 = bVar10 & 0xfe;
      _delay(1);
      *pbVar2 = 5;
      _delay(1);
      bVar8 = sub_408CEE6(*(undefined4 *)(DAT_40b541c + iVar5 + 4));
      *pbVar2 = bVar9 | bVar8;
      DAT_40b541c[iVar5 + 0x16] = bVar9;
      if (iVar6 != *(int *)(DAT_40b541c + iVar5)) {
        if (-1 < (char)DAT_40b53f4[iVar5 + 0xf]) {
          *(undefined4 *)(DAT_40b53f4 + iVar5) = 0;
          uVar7 = sub_408C210(iVar4);
          *(undefined4 *)(DAT_40b53f4 + iVar5 + 4) = uVar7;
        }
        _delay(1);
        *pbVar2 = 0xe;
        _delay(1);
        *pbVar2 = 0;
        _delay(1);
        *pbVar2 = 0xc;
        _delay(1);
        bStack_5 = (byte)iVar6;
        *pbVar2 = bStack_5;
        _delay(1);
        *pbVar2 = 0xd;
        _delay(1);
        *pbVar2 = (byte)((uint)iVar6 >> 8);
        _delay(1);
        *pbVar2 = 0xe;
        _delay(1);
        bVar9 = (byte)((uint)iVar6 >> 0x10);
        *pbVar2 = bVar9;
        _delay(10);
        _delay(1);
        *pbVar2 = 0xe;
        _delay(1);
        *pbVar2 = bVar9 | 1;
      }
      _delay(1);
      *pbVar2 = 3;
      _delay(1);
      *pbVar2 = bVar10;
      sub_408CFC8(param_1);
      *(undefined4 *)(DAT_40b53f4 + iVar5 + 8) = uStack_c;
      DAT_40b541c[iVar5 + 0x14] = bVar10;
      DAT_40b541c[iVar5 + 0x15] = bVar11;
      *(int *)(DAT_40b541c + iVar5) = iVar6;
      *(undefined4 *)(DAT_40b541c + iVar5 + 8) =
           *(undefined4 *)(unk_40B23D2 + (char)unk_40B51BC[iVar1 + 0x47] * 4);
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=3159 start=0x408c210 */

int sub_408C210(int *param_1)

{
  int iVar1;
  
  if (((*(byte *)(*param_1 + 0x3d) & 0x20) == 0) && ((*(byte *)(param_1 + 4) & 4) != 0)) {
    iVar1 = (10000000 / *(int *)(unk_40B23D2 + *(char *)(*param_1 + 0x47) * 4)) * 5;
  }
  else {
    iVar1 = (10000000 / *(int *)(unk_40B23D2 + *(char *)(*param_1 + 0x47) * 4)) * 0x19;
  }
  iVar1 = iVar1 * 2;
  if (20000 < iVar1) {
    iVar1 = 20000;
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=3160 start=0x408c4d2 */

void sub_408C4D2(int param_1)

{
  *(undefined4 *)((int)&DAT_40b5410 + param_1 * 0x164) = 0;
  sub_408C552(param_1);
  return;
}
/* GHIDRADEC_FUNCTION index=3161 start=0x408c50e */

void sub_408C50E(int param_1)

{
  *(uint *)(unk_40B5404 + param_1 * 0x164) = *(uint *)(unk_40B5404 + param_1 * 0x164) & 0xfffffffb;
  sub_408C552(param_1);
  return;
}
/* GHIDRADEC_FUNCTION index=3162 start=0x408c552 */

uint sub_408C552(int param_1)

{
  int iVar1;
  undefined *puVar2;
  int *piVar3;
  word wVar4;
  int iVar5;
  uint uVar6;
  byte bVar7;
  uint uVar8;
  byte *pbVar9;
  char cVar11;
  char cVar12;
  char cVar13;
  char cVar14;
  byte bVar15;
  uint uVar16;
  byte bStack_86;
  byte bStack_85;
  byte abStack_84 [128];
  byte *pbVar10;
  
  iVar1 = param_1 * 0x86;
  puVar2 = unk_40B51BC + iVar1;
  iVar5 = _ttynty(puVar2);
  uVar6 = param_1 * 0x164;
  pbVar9 = abStack_84;
  if ((*(byte *)((int)&DAT_40b53fc + uVar6 + 6) & 1) != 0) {
    bVar15 = 0x40;
    if (((*(uint *)(iVar5 + 0x10) & 0x201000) == 0x201000) &&
       (((*(uint *)(unk_40B51BC + iVar1 + 0x3a) & 0xc0) == 0x80 ||
        ((*(uint *)(unk_40B51BC + iVar1 + 0x3a) & 0xc0) == 0x40)))) {
      bVar15 = 0x50;
    }
    uVar16 = *(uint *)(unk_40B51BC + iVar1 + 0x3e);
    *(uint *)(unk_40B51BC + iVar1 + 0x3e) = uVar16 & 0xfeffffff;
    if ((uVar16 & 0x800000) == 0) {
      do {
        if (*(word **)(DAT_40b52d0 + uVar6 + 8) == *(word **)(DAT_40b52d0 + uVar6 + 4)) break;
        wVar4 = **(word **)(DAT_40b52d0 + uVar6 + 8);
        uVar16 = *(uint *)(DAT_40b52d0 + uVar6);
        uVar8 = *(int *)(DAT_40b52d0 + uVar6 + 8) + 2U;
        if (uVar16 + dword_40B51A8 * 2 <= *(int *)(DAT_40b52d0 + uVar6 + 8) + 2U) {
          uVar8 = uVar16;
        }
        *(uint *)(DAT_40b52d0 + uVar6 + 8) = uVar8;
        bStack_86 = (byte)(wVar4 >> 8);
        bStack_85 = (byte)wVar4;
        if (bStack_86 == 0) {
          if (abStack_84 != pbVar9) {
            iVar5 = (int)pbVar9 - (int)abStack_84;
            piVar3 = (int *)((int)&_zschars + param_1 * 4);
            *piVar3 = iVar5 + *piVar3;
            pbVar9 = abStack_84;
            if ((unk_40B51BC[iVar1 + 0x41] & 4) != 0) {
              (**(code **)(DAT_40ae4c0 + (char)unk_40B51BC[iVar1 + 0x45] * 0x30 + 4))
                        (abStack_84,iVar5,puVar2);
            }
          }
          uVar16 = (int)(char)bStack_85 ^ *(uint *)(DAT_40b5420 + uVar6);
          *(uint *)(DAT_40b5420 + uVar6) = uVar16 & 0x38 ^ *(uint *)(DAT_40b5420 + uVar6);
          if ((((uVar16 & 0x10) != 0) && ((*(uint *)((int)&DAT_40b53fc + uVar6 + 4) & 0x14) == 4))
             && (*(int *)(DAT_40b5420 + uVar6 + 0xc) == 0)) {
            *(undefined4 *)(DAT_40b5420 + uVar6 + 0xc) = 1;
            _us_timeout(sub_408C984,param_1,&unk_40B23C2,0);
          }
          if (((uVar16 & 0x20) != 0) && ((DAT_40b5420[uVar6 + 3] & 0x20) == 0)) {
            iVar5 = dword_40B51A8 * 2;
            do {
              if (*(byte **)(DAT_40b52d0 + uVar6 + 8) != *(byte **)(DAT_40b52d0 + uVar6 + 4)) {
                bVar7 = **(byte **)(DAT_40b52d0 + uVar6 + 8) & 1;
                goto loc_408C702;
              }
              do {
                bVar7 = 2;
loc_408C702:
                if (bVar7 != 1) {
                  if (*(sword *)(unk_40B51BC + iVar1 + 0x38) == *(sword *)(_cons_tp + 0x38)) {
                    _mini_mon(aSerialNmi,&unk_40A62E7);
                  }
                  if ((unk_40B51BC[iVar1 + 0x41] & 4) == 0) goto loc_408C84E;
                  cVar12 = unk_40B51BC[iVar1 + 0x45];
                  uVar16 = 0x1000000;
                  goto loc_408C7FC;
                }
              } while (*(int *)(DAT_40b52d0 + uVar6 + 8) == *(int *)(DAT_40b52d0 + uVar6 + 4));
              uVar16 = *(uint *)(DAT_40b52d0 + uVar6);
              uVar8 = *(int *)(DAT_40b52d0 + uVar6 + 8) + 2U;
              if (iVar5 + uVar16 <= *(int *)(DAT_40b52d0 + uVar6 + 8) + 2U) {
                uVar8 = uVar16;
              }
              *(uint *)(DAT_40b52d0 + uVar6 + 8) = uVar8;
            } while( true );
          }
        }
        else if ((bVar15 & bStack_86) == 0) {
          bVar7 = *(byte *)((int)&DAT_40b53fc + uVar6 + 3);
          pbVar10 = pbVar9;
          if (&stack0xfffffffc <= pbVar9) {
            iVar5 = (int)pbVar9 - (int)abStack_84;
            piVar3 = (int *)((int)&_zschars + param_1 * 4);
            *piVar3 = iVar5 + *piVar3;
            pbVar10 = abStack_84;
            if ((unk_40B51BC[iVar1 + 0x41] & 4) != 0) {
              (**(code **)(DAT_40ae4c0 + (char)unk_40B51BC[iVar1 + 0x45] * 0x30 + 4))
                        (abStack_84,iVar5,puVar2);
            }
          }
          pbVar9 = pbVar10 + 1;
          *pbVar10 = bVar7 & bStack_85;
        }
        else {
          uVar16 = *(uint *)((int)&DAT_40b53fc + uVar6) & (int)(char)bStack_85;
          if (abStack_84 != pbVar9) {
            iVar5 = (int)pbVar9 - (int)abStack_84;
            piVar3 = (int *)((int)&_zschars + param_1 * 4);
            *piVar3 = iVar5 + *piVar3;
            pbVar9 = abStack_84;
            if ((unk_40B51BC[iVar1 + 0x41] & 4) != 0) {
              (**(code **)(DAT_40ae4c0 + (char)unk_40B51BC[iVar1 + 0x45] * 0x30 + 4))
                        (abStack_84,iVar5,puVar2);
            }
          }
          if ((wVar4 & 0x4000) != 0) {
            uVar16 = uVar16 | 0x1000000;
          }
          if ((wVar4 & 0x1000) != 0) {
            uVar16 = uVar16 | 0x2000000;
          }
          if ((unk_40B51BC[iVar1 + 0x41] & 4) != 0) {
            cVar12 = unk_40B51BC[iVar1 + 0x45];
loc_408C7FC:
            (**(code **)(DAT_40ae4c0 + cVar12 * 0x30))(uVar16,puVar2);
          }
        }
loc_408C84E:
      } while (-1 < (char)unk_40B51BC[iVar1 + 0x3f]);
    }
    if (abStack_84 != pbVar9) {
      iVar5 = (int)pbVar9 - (int)abStack_84;
      piVar3 = (int *)((int)&_zschars + param_1 * 4);
      *piVar3 = iVar5 + *piVar3;
      if ((unk_40B51BC[iVar1 + 0x41] & 4) != 0) {
        (**(code **)(DAT_40ae4c0 + (char)unk_40B51BC[iVar1 + 0x45] * 0x30 + 4))
                  (abStack_84,iVar5,puVar2);
      }
    }
    cVar11 = '\0';
    cVar14 = false;
    cVar12 = false;
    bVar15 = false;
    if ((char)unk_40B51BC[iVar1 + 0x3f] < '\0') {
      if (*(byte **)(DAT_40b52d0 + uVar6 + 8) == *(byte **)(DAT_40b52d0 + uVar6 + 4)) {
        uVar16 = 2;
      }
      else {
        uVar16 = (uint)(char)(**(byte **)(DAT_40b52d0 + uVar6 + 8) & 1);
      }
      cVar11 = 2 < uVar16;
      cVar14 = SBORROW4(2,uVar16);
      cVar12 = (int)(2 - uVar16) < 0;
      bVar15 = cVar11;
      if (uVar16 != 2) {
        if ((*(uint *)(unk_40B5404 + uVar6) & 4) == 0) {
          *(uint *)(unk_40B5404 + uVar6) = *(uint *)(unk_40B5404 + uVar6) | 4;
          _us_timeout(sub_408C50E,param_1,&unk_40B23CA,0);
        }
        cVar14 = false;
        cVar12 = false;
        bVar15 = false;
        if ((*(uint *)(unk_40B51BC + iVar1 + 0x3a) & 0x22) != 0) {
          uVar16 = *(uint *)(DAT_40b52d0 + uVar6 + 4);
          uVar8 = *(uint *)(DAT_40b52d0 + uVar6 + 8);
          if (uVar16 < uVar8) {
            uVar16 = dword_40B51A8 - ((int)(uVar8 - uVar16) >> 1);
          }
          else {
            uVar16 = (int)(uVar16 - uVar8) >> 1;
          }
          cVar11 = uVar16 < dword_40B51B4;
          cVar14 = SBORROW4(uVar16,dword_40B51B4);
          cVar12 = (int)(uVar16 - dword_40B51B4) < 0;
          bVar15 = cVar11;
          if ((int)dword_40B51B4 < (int)uVar16) {
            unk_40B51BC[iVar1 + 0x3e] = unk_40B51BC[iVar1 + 0x3e] | 1;
          }
        }
      }
    }
    cVar13 = (*(byte *)((int)&DAT_40b53fc + uVar6 + 7) & 0x40) == 0;
    if (!(bool)cVar13) {
      uVar16 = *(uint *)(DAT_40b5420 + uVar6) & 5;
      cVar11 = 4 < uVar16;
      cVar14 = SBORROW4(4,uVar16);
      cVar12 = (int)(4 - uVar16) < 0;
      cVar13 = '\0';
      bVar15 = cVar11;
      if (uVar16 == 4) {
        uVar16 = *(uint *)(DAT_40b52d0 + uVar6 + 4);
        uVar8 = *(uint *)(DAT_40b52d0 + uVar6 + 8);
        if (uVar16 < uVar8) {
          uVar16 = dword_40B51A8 - ((int)(uVar8 - uVar16) >> 1);
        }
        else {
          uVar16 = (int)(uVar16 - uVar8) >> 1;
        }
        cVar11 = uVar16 < dword_40B51B4;
        cVar14 = SBORROW4(uVar16,dword_40B51B4);
        cVar12 = (int)(uVar16 - dword_40B51B4) < 0;
        cVar13 = uVar16 == dword_40B51B4;
        bVar15 = cVar11;
        if ((int)uVar16 <= (int)dword_40B51B4) {
          *(uint *)(DAT_40b5420 + uVar6) = *(uint *)(DAT_40b5420 + uVar6) | 1;
          cVar12 = param_1 < 0;
          cVar13 = param_1 == 0;
          cVar14 = '\0';
          bVar15 = 0;
          sub_408CFC8(param_1);
        }
      }
    }
    uVar6 = (uint)(byte)(cVar11 << 4 | cVar12 << 3 | cVar13 << 2 | cVar14 << 1 | bVar15);
  }
  return uVar6;
}
/* GHIDRADEC_FUNCTION index=3163 start=0x408c984 */

undefined4 sub_408C984(int param_1)

{
  undefined2 uVar1;
  undefined2 extraout_D0u;
  int iVar2;
  int iVar3;
  char cVar4;
  
  iVar2 = param_1 * 0x164;
  cVar4 = ((uint)((char)unk_40B51BC[param_1 * 0x86 + 0x45] * 3) >> 0x1c & 1) != 0;
  iVar3 = (**(code **)(DAT_40ae4d0 + (char)unk_40B51BC[param_1 * 0x86 + 0x45] * 0x30))
                    (unk_40B51BC + param_1 * 0x86,*(uint *)(DAT_40b5420 + iVar2) & 0x10);
  if (iVar3 == 0) {
    iVar3 = sub_408CF32(param_1,0,0);
  }
  uVar1 = (undefined2)((uint)iVar3 >> 0x10);
  if ((DAT_40b5420[iVar2 + 3] & 0x10) != 0) {
    _wakeup(DAT_40b52d0 + iVar2);
    uVar1 = extraout_D0u;
  }
  *(undefined4 *)(DAT_40b5420 + iVar2 + 0xc) = 0;
  return CONCAT22(uVar1,(word)(byte)(cVar4 << 4 | 4));
}
/* GHIDRADEC_FUNCTION index=3164 start=0x408ca1e */

byte sub_408CA1E(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  word wVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  char cVar8;
  char cVar9;
  char cVar10;
  char cVar11;
  byte bVar12;
  undefined auStack_c [8];
  
  iVar5 = _ttynty(param_1);
  wVar3 = *(word *)(param_1 + 0x38);
  uVar4 = wVar3 & 0x1f;
  iVar6 = uVar4 * 0x164;
  cVar8 = '\0';
  uVar7 = *(uint *)(param_1 + 0x3e);
  cVar11 = '\0';
  bVar12 = 0;
  cVar9 = '\0';
  cVar10 = '\0';
  if ((uVar7 & 0x121) == 0) {
    cVar8 = (uint)(int)*(sword *)(_ttlowat + (*(byte *)(param_1 + 0x48) & 0x1f) * 2) <
            *(uint *)(param_1 + 0x18);
    if ((int)*(uint *)(param_1 + 0x18) <=
        (int)*(sword *)(_ttlowat + (*(byte *)(param_1 + 0x48) & 0x1f) * 2)) {
      if ((uVar7 & 0x40) != 0) {
        *(uint *)(param_1 + 0x3e) = uVar7 & 0xffffffbf;
        _wakeup(param_1 + 0x18);
      }
      if (*(int *)(param_1 + 0x2c) != 0) {
        _selwakeup(*(int *)(param_1 + 0x2c),*(uint *)(param_1 + 0x3e) & 0x1000);
        _thread_deallocate_interrupt(*(undefined4 *)(param_1 + 0x2c));
        *(undefined4 *)(param_1 + 0x2c) = 0;
        *(word *)(param_1 + 0x40) = *(word *)(param_1 + 0x40) & 0xefff;
      }
    }
    cVar11 = '\0';
    bVar12 = 0;
    cVar9 = *(int *)(param_1 + 0x18) < 0;
    cVar10 = *(int *)(param_1 + 0x18) == 0;
    if (!(bool)cVar10) {
      if ((((*(uint *)(param_1 + 0x3a) & 0x2200020) == 0) &&
          ((*(uint *)(iVar5 + 0x10) & 0x10000000) != 0)) &&
         (uVar7 = *(uint *)(iVar5 + 0x10) & 0x300, cVar8 = uVar7 < 0x300, uVar7 != 0x300)) {
        uVar7 = _ndqb(param_1 + 0x18,0x80);
        if (uVar7 == 0) {
          uVar7 = _getc(param_1 + 0x18);
          _ticks_to_timeval((uVar7 & 0x7f) + 6,auStack_c);
          _us_timeout(_ttrstrt,param_1,auStack_c,0);
          cVar11 = '\0';
          bVar12 = 0;
          uVar7 = *(uint *)(param_1 + 0x3e) | 1;
          *(uint *)(param_1 + 0x3e) = uVar7;
          cVar9 = (int)uVar7 < 0;
          cVar10 = uVar7 == 0;
          goto loc_408CB9E;
        }
      }
      else {
        uVar7 = _ndqb(param_1 + 0x18,0);
      }
      *(uint *)(param_1 + 0x3e) = *(uint *)(param_1 + 0x3e) | 0x20;
      uVar1 = *(undefined4 *)(param_1 + 0x1c);
      *(undefined4 *)(unk_40B52E0 + iVar6 + 0x100) = uVar1;
      *(undefined4 *)(unk_40B52E0 + iVar6 + 0x28) = uVar1;
      *(undefined4 *)(unk_40B52E0 + iVar6 + 0xfc) = *(undefined4 *)(unk_40B52E0 + iVar6 + 0x28);
      uVar2 = *(uint *)(unk_40B52E0 + iVar6 + 0x100);
      cVar8 = CARRY4(uVar7,uVar2);
      *(uint *)(unk_40B52E0 + iVar6 + 0x100) = uVar7 + uVar2;
      if ((unk_40B52E0[iVar6 + 0x123] & 1) == 0) {
        cVar8 = '\0';
        cVar9 = '\0';
        cVar10 = (wVar3 & 0x1f) == 0;
        cVar11 = '\0';
        bVar12 = 0;
        sub_408CBAC(uVar4);
      }
      else {
        cVar9 = '\0';
        cVar10 = '\x01';
        cVar11 = '\0';
        bVar12 = 0;
        _dma_start(unk_40B52E0 + iVar6,iVar6 + 0x40b53d8,0);
      }
    }
  }
loc_408CB9E:
  return cVar8 << 4 | cVar9 << 3 | cVar10 << 2 | cVar11 << 1 | bVar12;
}
/* GHIDRADEC_FUNCTION index=3165 start=0x408cbac */

void sub_408CBAC(int param_1)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  
  iVar3 = param_1 * 0x164;
  pbVar1 = (byte *)(&DAT_40b52dc)[param_1 * 0x59];
  _delay(1);
  while( true ) {
    if ((*pbVar1 & 4) == 0) {
      return;
    }
    if (*(uint *)(DAT_40b5308 + iVar3 + 0xd8) <= *(uint *)(DAT_40b5308 + iVar3)) break;
    _delay(1);
    pbVar2 = *(byte **)(DAT_40b5308 + iVar3);
    *(byte **)(DAT_40b5308 + iVar3) = pbVar2 + 1;
    pbVar1[2] = DAT_40b5308[iVar3 + 0xf7] & *pbVar2;
    _delay(1);
    *(int *)(DAT_40b5408 + iVar3) = (_hz / _hz) * 3;
  }
  *(undefined4 *)(DAT_40b5408 + iVar3) = 0;
  _delay(1);
  *pbVar1 = 0x28;
  if (*(int *)(DAT_40b5408 + iVar3 + 4) != 0) {
    return;
  }
  *(int *)(DAT_40b5408 + iVar3 + 4) = (_hz / _hz) * 3;
  _callout_dispatch(0,sub_408CC8C,param_1);
  return;
}
/* GHIDRADEC_FUNCTION index=3166 start=0x408cc8c */

undefined4 sub_408CC8C(uint param_1)

{
  int iVar1;
  undefined *puVar2;
  uint uVar3;
  char cVar4;
  undefined2 extraout_D0u;
  undefined2 extraout_D0u_00;
  undefined2 uVar5;
  undefined4 uVar6;
  int iVar7;
  char cVar8;
  bool bVar9;
  char cVar10;
  char cVar11;
  char cVar12;
  byte bVar13;
  
  cVar12 = param_1 * 0x44 < param_1;
  iVar1 = param_1 * 0x86;
  puVar2 = unk_40B51BC + iVar1;
  iVar7 = param_1 * 0x164;
  *(undefined4 *)(DAT_40b540c + iVar7) = 0;
  bVar9 = (DAT_40b5308[iVar7 + 0xfa] & 1) == 0;
  if (bVar9) {
    uVar6 = CONCAT22((sword)(param_1 * 0x43 >> 0x10),(word)(byte)(cVar12 << 4 | bVar9 << 2));
  }
  else {
    uVar3 = *(uint *)(unk_40B51BC + iVar1 + 0x3e);
    *(uint *)(unk_40B51BC + iVar1 + 0x3e) = uVar3 & 0xffffffdf;
    if ((uVar3 & 8) == 0) {
      cVar12 = *(uint *)(DAT_40b5308 + iVar7) < *(uint *)(unk_40B51BC + iVar1 + 0x1c);
      _ndflush(iVar1 + 0x40b51d4,
               *(uint *)(DAT_40b5308 + iVar7) - *(uint *)(unk_40B51BC + iVar1 + 0x1c));
    }
    else {
      *(uint *)(unk_40B51BC + iVar1 + 0x3e) = uVar3 & 0xffffffd7;
    }
    cVar4 = unk_40B51BC[iVar1 + 0x45];
    if (cVar4 == '\0') {
      cVar8 = (int)puVar2 < 0;
      cVar10 = puVar2 == (undefined *)0x0;
      cVar11 = '\0';
      bVar13 = 0;
      sub_408CA1E(puVar2);
      uVar5 = extraout_D0u_00;
    }
    else {
      cVar12 = ((uint)(cVar4 * 3) >> 0x1c & 1) != 0;
      cVar8 = (int)puVar2 < 0;
      cVar10 = puVar2 == (undefined *)0x0;
      cVar11 = '\0';
      bVar13 = 0;
      (**(code **)(DAT_40ae4cc + cVar4 * 0x30))(puVar2);
      uVar5 = extraout_D0u;
    }
    uVar6 = CONCAT22(uVar5,(word)(byte)(cVar12 << 4 | cVar8 << 3 | cVar10 << 2 | cVar11 << 1 |
                                       bVar13));
  }
  return uVar6;
}
/* GHIDRADEC_FUNCTION index=3167 start=0x408cd86 */

byte sub_408CD86(int param_1)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  word *pwVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  char cVar8;
  byte bVar9;
  word wStack_6;
  
  iVar2 = param_1 * 0x164;
  puVar1 = *(undefined **)(DAT_40b52d0 + iVar2 + 0xc);
  cVar5 = '\0';
  _delay(1);
  uVar3 = sub_408CE7E(*puVar1);
  wStack_6 = (word)(byte)uVar3;
  if (((*(uint *)(DAT_40b5420 + iVar2) ^ uVar3) & 8) != 0) {
    *(uint *)(DAT_40b5420 + iVar2) = *(uint *)(DAT_40b5420 + iVar2) ^ 8;
    if (((&DAT_40b5403)[iVar2] & 0x40) != 0) {
      sub_408CFC8(param_1);
    }
    if (((*(uint *)(DAT_40b5420 + iVar2) ^ uVar3 & 0xff) & 0x38) == 0) {
      return cVar5 << 4 | 4;
    }
  }
  pwVar4 = *(word **)(DAT_40b52d0 + iVar2 + 4) + 1;
  if (*(word **)(DAT_40b52d0 + iVar2) + dword_40B51A8 <= pwVar4) {
    pwVar4 = *(word **)(DAT_40b52d0 + iVar2);
  }
  cVar5 = pwVar4 < *(word **)(DAT_40b52d0 + iVar2 + 8);
  if (pwVar4 == *(word **)(DAT_40b52d0 + iVar2 + 8)) {
    *(uint *)(unk_40B5404 + iVar2) = *(uint *)(unk_40B5404 + iVar2) | 1;
  }
  else {
    **(word **)(DAT_40b52d0 + iVar2 + 4) = wStack_6;
    *(word **)(DAT_40b52d0 + iVar2 + 4) = pwVar4;
  }
  cVar8 = '\0';
  bVar9 = 0;
  cVar6 = *(int *)(unk_40B5404 + iVar2 + 0xc) < 0;
  cVar7 = '\0';
  if (*(int *)(unk_40B5404 + iVar2 + 0xc) == 0) {
    *(int *)(unk_40B5404 + iVar2 + 0xc) = (_hz / _hz) * 3;
    cVar6 = '\0';
    cVar7 = '\x01';
    cVar8 = '\0';
    bVar9 = 0;
    _callout_dispatch(0,sub_408C4D2,param_1);
  }
  return cVar5 << 4 | cVar6 << 3 | cVar7 << 2 | cVar8 << 1 | bVar9;
}
/* GHIDRADEC_FUNCTION index=3168 start=0x408ce7e */

uint sub_408CE7E(byte param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  if ((char)param_1 < '\0') {
    uVar1 = 0x20;
  }
  if (dword_40B51B8 == 1) {
    if ((param_1 & 0x20) != 0) {
      uVar1 = uVar1 | 0x10;
    }
  }
  else if (dword_40B51B8 < 2) {
    if (dword_40B51B8 != 0) {
      return uVar1;
    }
    if ((param_1 & 0x20) == 0) {
      uVar1 = uVar1 | 0x10;
    }
  }
  else {
    if (dword_40B51B8 != 2) {
      return uVar1;
    }
    if ((param_1 & 8) != 0) {
      uVar1 = uVar1 | 0x10;
    }
    if ((param_1 & 0x20) == 0) {
      return uVar1;
    }
  }
  return uVar1 | 8;
}
/* GHIDRADEC_FUNCTION index=3169 start=0x408cee6 */

uint sub_408CEE6(uint param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  if ((param_1 & 4) != 0) {
    uVar1 = 0x80;
  }
  if ((param_1 & 2) != 0) {
    uVar1 = uVar1 | 0x10;
  }
  if ((-1 < dword_40B51B8) &&
     ((dword_40B51B8 < 2 || ((dword_40B51B8 == 2 && ((param_1 & 1) != 0)))))) {
    uVar1 = uVar1 | 2;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=3170 start=0x408cf32 */

uint sub_408CF32(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  
  param_2 = param_2 & 7;
  _delay(1);
  uVar1 = *(uint *)(DAT_40b5420 + param_1 * 0x164);
  if (param_3 == 1) {
    uVar1 = param_2 | uVar1;
  }
  else if (param_3 < 2) {
    if (param_3 == 0) {
      uVar1 = uVar1 & 0x38 | param_2;
    }
  }
  else if (param_3 == 2) {
    uVar1 = ~param_2 & uVar1;
  }
  else if (param_3 == 3) {
    return uVar1;
  }
  *(uint *)(DAT_40b5420 + param_1 * 0x164) = uVar1;
  sub_408CFC8(param_1);
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=3171 start=0x408cfc8 */

byte sub_408CFC8(int param_1)

{
  byte *pbVar1;
  int iVar2;
  byte bVar3;
  char cVar4;
  
  iVar2 = param_1 * 0x164;
  pbVar1 = (byte *)(&DAT_40b52dc)[param_1 * 0x59];
  cVar4 = '\0';
  bVar3 = sub_408CEE6(*(undefined4 *)(DAT_40b5420 + iVar2));
  bVar3 = bVar3 | DAT_40b5420[iVar2 + 0x12];
  if (((DAT_40b5420[iVar2 + 3] & 8) != 0) || (((&DAT_40b5403)[iVar2] & 0x40) == 0)) {
    bVar3 = bVar3 | 8;
  }
  _delay(1);
  *pbVar1 = 5;
  _delay(1);
  *pbVar1 = bVar3;
  return cVar4 << 4 | ((char)bVar3 < '\0') << 3 | (bVar3 == 0) << 2;
}
/* GHIDRADEC_FUNCTION index=3172 start=0x408d042 */

void sub_408D042(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  undefined *puVar7;
  undefined *puVar8;
  int *piStack_10;
  undefined auStack_c [8];
  
  iVar2 = 0;
  puVar8 = unk_40B5418;
  puVar7 = unk_40B5404;
  piStack_10 = (int *)(unk_40B5404 + 0x10);
  piVar5 = (int *)(unk_40B5404 + 4);
  iVar6 = 0x40b5420;
  piVar4 = (int *)(unk_40B5404 + 8);
  piVar3 = (int *)(unk_40B5404 + 0xc);
  do {
    iVar1 = *piVar3;
    if ((iVar1 != 0) && (*piVar3 = iVar1 + -1, iVar1 == 1)) {
      _printf(aZsDLostRecvSwI,iVar2);
      sub_408C552(iVar2);
    }
    iVar1 = *piVar4;
    if ((iVar1 != 0) && (*piVar4 = iVar1 + -1, iVar1 == 1)) {
      _printf(aZsDLostXmitSwI,iVar2);
      sub_408CC8C(iVar2);
    }
    iVar1 = *piVar5;
    if (((iVar1 != 0) && ((*(byte *)(iVar6 + 3) & 8) != 0)) && (*piVar5 = iVar1 + -1, iVar1 == 1)) {
      _printf(aZsDLostXmitHwI,iVar2);
      sub_408CBAC(iVar2);
    }
    if (*piStack_10 == 0) {
      if ((*(uint *)puVar7 & 1) != 0) {
        _log(4,aZsDRecvBufferO,iVar2);
        *piStack_10 = (_hz / _hz) * 10;
      }
    }
    else {
      *piStack_10 = *piStack_10 + -1;
      *(uint *)puVar7 = *(uint *)puVar7 & 0xfffffffe;
    }
    if (*(int *)puVar8 == 0) {
      if ((*(uint *)puVar7 & 2) != 0) {
        _log(4,aZsDRecvUartOve,iVar2);
        *(int *)puVar8 = (_hz / _hz) * 10;
      }
    }
    else {
      *(int *)puVar8 = *(int *)puVar8 + -1;
      *(uint *)puVar7 = *(uint *)puVar7 & 0xfffffffd;
    }
    puVar8 = (undefined *)((int)puVar8 + 0x164);
    puVar7 = (undefined *)((int)puVar7 + 0x164);
    piStack_10 = piStack_10 + 0x59;
    piVar5 = piVar5 + 0x59;
    iVar6 = iVar6 + 0x164;
    piVar4 = piVar4 + 0x59;
    piVar3 = piVar3 + 0x59;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 2);
  _ticks_to_timeval(_hz,auStack_c);
  _us_timeout(sub_408D042,0,auStack_c,0);
  return;
}
/* GHIDRADEC_FUNCTION index=3173 start=0x408d24a */

uint sub_408D24A(uint param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  if ((param_1 & 0x40) != 0) {
    uVar1 = 0x10;
  }
  if ((param_1 & 2) != 0) {
    uVar1 = uVar1 | 4;
  }
  if ((param_1 & 4) != 0) {
    uVar1 = uVar1 | 1;
  }
  if ((param_1 & 0x20) != 0) {
    uVar1 = uVar1 | 8;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=3174 start=0x408d284 */

uint sub_408D284(uint param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  if ((param_1 & 0x10) != 0) {
    uVar1 = 0x40;
  }
  if ((param_1 & 4) != 0) {
    uVar1 = uVar1 | 2;
  }
  if ((param_1 & 1) != 0) {
    uVar1 = uVar1 | 4;
  }
  if ((param_1 & 8) != 0) {
    uVar1 = uVar1 | 0x20;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=3175 start=0x408d2be */

char sub_408D2BE(byte *param_1,undefined4 param_2)

{
  uint uVar1;
  undefined uVar2;
  byte bVar3;
  char cVar4;
  
  bVar3 = 0x40;
  if ((byte *)(_slot_id_bmap + 0x2018001) == param_1) {
    bVar3 = 0x80;
  }
  _delay(1);
  *param_1 = 9;
  _delay(1);
  *param_1 = bVar3 | 2;
  _delay(10);
  _delay(1);
  *param_1 = 1;
  _delay(1);
  *param_1 = 0;
  _delay(1);
  *param_1 = 9;
  _delay(1);
  *param_1 = 2;
  _delay(1);
  *param_1 = 10;
  _delay(1);
  *param_1 = 0;
  _delay(1);
  *param_1 = 0xb;
  _delay(1);
  *param_1 = 0x50;
  _delay(1);
  *param_1 = 0xf;
  _delay(1);
  *param_1 = 0;
  _delay(1);
  *param_1 = 4;
  _delay(1);
  *param_1 = 0x44;
  _delay(1);
  *param_1 = 3;
  _delay(1);
  *param_1 = 0xc0;
  _delay(1);
  *param_1 = 5;
  _delay(1);
  *param_1 = 0x60;
  _delay(1);
  *param_1 = 0xe;
  _delay(1);
  *param_1 = 0;
  uVar1 = _zs_tc(param_2,0x10);
  uVar2 = 0x30;
  if (_dma_chip == 0x139) {
    uVar2 = 10;
  }
  *(undefined *)(_slot_id_bmap + 0x2018004) = uVar2;
  _delay(1);
  *param_1 = 0xc;
  _delay(1);
  *param_1 = (byte)uVar1;
  _delay(1);
  *param_1 = 0xd;
  _delay(1);
  cVar4 = (uVar1 >> 7 & 1) != 0;
  *param_1 = (byte)(uVar1 >> 8);
  _delay(1);
  *param_1 = 0xe;
  _delay(1);
  bVar3 = (byte)(uVar1 >> 0x10);
  *param_1 = bVar3;
  _delay(10);
  _delay(1);
  *param_1 = 0xe;
  _delay(1);
  *param_1 = bVar3 | 1;
  _delay(1);
  *param_1 = 3;
  _delay(1);
  *param_1 = 0xc1;
  _delay(1);
  *param_1 = 5;
  _delay(1);
  *param_1 = 0xea;
  _delay(1);
  *param_1 = 0x30;
  _delay(1);
  *param_1 = 0x10;
  _delay(1);
  *param_1 = 0x28;
  return cVar4 << 4;
}
/* GHIDRADEC_FUNCTION index=3176 start=0x408d9aa */

byte sub_408D9AA(undefined4 *param_1)

{
  char in_XF;
  char in_NF;
  char in_ZF;
  char in_VF;
  byte in_CF;
  
  *param_1 = dword_40B244A;
  dword_40B244A = param_1;
  dword_40B2452 = dword_40B2452 + 1;
  return in_XF << 4 | in_NF << 3 | in_ZF << 2 | in_VF << 1 | in_CF;
}
/* GHIDRADEC_FUNCTION index=3177 start=0x408d9d4 */

undefined4 sub_408D9D4(void)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  
  iVar2 = _m_clalloc(1,2,0);
  if (iVar2 == 0) {
    uVar3 = 1;
  }
  else {
    uVar1 = _page_size + iVar2;
    uVar4 = iVar2 + 0xf;
    if ((int)uVar4 < 0) {
      uVar4 = iVar2 + 0x1e;
    }
    while (uVar5 = uVar4 & 0xfffffff0, uVar5 + 0x62e <= uVar1) {
      sub_408D9AA(uVar5);
      dword_40B244E = dword_40B244E + 1;
      uVar4 = uVar5 + 0x63d;
      if ((int)uVar4 < 0) {
        uVar4 = uVar5 + 0x64c;
      }
    }
    uVar3 = 0;
  }
  return uVar3;
}
/* GHIDRADEC_FUNCTION index=3178 start=0x408db8a */

undefined sub_408DB8A(undefined4 param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined uStack_5;
  
  iVar3 = 0;
  do {
    iVar2 = _copywithin(param_1,&uStack_5,1);
    if (iVar2 != 0xe) {
      return uStack_5;
    }
    bVar1 = iVar3 < 0x10;
    iVar3 = iVar3 + 1;
  } while (bVar1);
  return 0;
}
/* GHIDRADEC_FUNCTION index=3179 start=0x408dbd2 */

void sub_408DBD2(undefined4 param_1,undefined param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined uStack_5;
  
  uStack_5 = param_2;
  iVar3 = 0;
  do {
    iVar2 = _copywithin(&uStack_5,param_1,1);
    if (iVar2 != 0xe) {
      return;
    }
    bVar1 = iVar3 < 0x10;
    iVar3 = iVar3 + 1;
  } while (bVar1);
  return;
}
/* GHIDRADEC_FUNCTION index=3180 start=0x408dc16 */

bool sub_408DC16(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined uStack_5;
  
  iVar2 = 0;
  do {
    iVar1 = _copywithin(param_1,&uStack_5,1);
    if (iVar1 != 0xe) break;
    _delay(1000);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 10);
  return iVar2 != 10;
}
/* GHIDRADEC_FUNCTION index=3181 start=0x4090a50 */

void sub_4090A50(undefined4 *param_1,undefined4 param_2)

{
  char cVar1;
  undefined4 *in_A1;
  char *pcVar2;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  pcVar2 = (char *)&uStack_24;
  _strcpy(pcVar2,*param_1);
  cVar1 = uStack_24._0_1_;
  while (cVar1 != '\0') {
    pcVar2 = pcVar2 + 1;
    cVar1 = *pcVar2;
  }
  *pcVar2 = (char)*(undefined2 *)(param_1 + 2) + '0';
  pcVar2[1] = '\0';
  _bcopy(param_2,&uStack_14,0x10);
  *in_A1 = uStack_24;
  in_A1[1] = uStack_20;
  in_A1[2] = uStack_1c;
  in_A1[3] = uStack_18;
  in_A1[4] = uStack_14;
  in_A1[5] = uStack_10;
  in_A1[6] = uStack_c;
  in_A1[7] = uStack_8;
  return;
}
/* GHIDRADEC_FUNCTION index=3182 start=0x409100e */

uint sub_409100E(int param_1,uint param_2,int param_3,word param_4,int param_5)

{
  uint uVar1;
  uint uVar2;
  word wVar3;
  sword sVar4;
  word *pwVar5;
  word *pwVar6;
  
  if (param_2 == 0) {
    _bcopy(param_1,param_3,param_5 * 2);
    uVar2 = 0;
  }
  else {
    uVar2 = (uint)param_4;
    param_5 = param_5 + -1;
    if (-1 < param_5) {
      pwVar6 = (word *)(param_3 + param_5 * 2);
      pwVar5 = (word *)(param_1 + param_5 * 2);
      do {
        do {
          uVar1 = (uint)*pwVar5 << (param_2 & 0x3f);
          *pwVar6 = (word)uVar1 | (word)uVar2;
          uVar2 = uVar1 >> 0x10;
          pwVar6 = pwVar6 + -1;
          pwVar5 = pwVar5 + -1;
          wVar3 = (word)((uint)param_5 >> 0x10);
          sVar4 = (sword)param_5 + -1;
          param_5 = CONCAT22(wVar3,sVar4);
        } while (sVar4 != -1);
        param_5 = (uint)wVar3 * 0x10000 + -1;
      } while (wVar3 != 0);
    }
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=3183 start=0x4091e18 */

uint sub_4091E18(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  uint uVar2;
  
  uVar2 = *_event_middle;
  if (((uVar2 ^ (uint)*_eventc_h << 0x10) & 0x80000) != 0) {
    *_event_middle = *_event_middle + 0x80000;
    puVar1 = _event_high;
    uVar2 = *_event_middle & 0xfff80000;
    if (uVar2 == 0) {
      *_event_high = *_event_high + 1;
      uVar2 = *puVar1;
    }
  }
  if (dword_40B55BC != (code *)0x0) {
    uVar2 = (*dword_40B55BC)(param_1,param_2,param_3);
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=3184 start=0x4093792 */

void sub_4093792(undefined4 param_1)

{
  _kernel_thread(_kernel_task,param_1,0);
  return;
}
/* GHIDRADEC_FUNCTION index=3185 start=0x409630e */

void sub_409630E(void)

{
  int iVar1;
  
  iVar1 = _get_vbr();
  dword_40B5614 = *(undefined4 *)(iVar1 + 8);
  dword_40B5618 = *(undefined4 *)(iVar1 + 0xc);
  *(code **)(iVar1 + 8) = __dbg_trap;
  *(code **)(iVar1 + 0xc) = __dbg_trap;
  return;
}
/* GHIDRADEC_FUNCTION index=3186 start=0x4096358 */

void sub_4096358(void)

{
  int iVar1;
  
  iVar1 = _get_vbr();
  *(undefined4 *)(iVar1 + 8) = dword_40B5614;
  *(undefined4 *)(iVar1 + 0xc) = dword_40B5618;
  return;
}
/* GHIDRADEC_FUNCTION index=3187 start=0x40963bc */

int sub_40963BC(int param_1)

{
  bool bVar1;
  int iVar2;
  int aiStack_1c [2];
  int iStack_14;
  int *piStack_10;
  int iStack_c;
  int *piStack_8;
  
  piStack_8 = (int *)&_kdb_net;
  iStack_14 = 0;
loc_40963D0:
  iStack_c = _en_recv(aiStack_1c,0x242,piStack_8[2],_kdb_ipaddr);
  if (iStack_c == 0) {
    if ((param_1 == 0) ||
       (iVar2 = iStack_14 + 1, bVar1 = iStack_14 < param_1, iStack_14 = iVar2, bVar1))
    goto loc_40963D0;
  }
  if ((param_1 != 0) && (iStack_c == 0)) {
    return 0;
  }
  if (aiStack_1c[0] == 0x473) {
    piStack_10 = (int *)(iStack_c + 0x2a);
    if (*piStack_8 == *piStack_10) {
      return iStack_c;
    }
    if (*piStack_8 + -1 == *piStack_10) {
      _kdebug_send(0x473,*piStack_10);
    }
    else if ((*piStack_10 == 0) && (*(int *)(iStack_c + 0x2e) == 8)) {
      *piStack_8 = 0;
      return iStack_c;
    }
  }
  goto loc_40963D0;
}
/* GHIDRADEC_FUNCTION index=3188 start=0x40964c0 */

void sub_40964C0(void)

{
  _kdebug_send(0x473,_kdb_net._0_4_);
  _kdb_net._0_4_ = _kdb_net._0_4_ + 1;
  return;
}
/* GHIDRADEC_FUNCTION index=3189 start=0x4096f96 */

void sub_4096F96(int param_1,uint param_2)

{
  _bzero(param_1,0x1c);
  *(uint *)(param_1 + 8) = param_2;
  *(uint *)(param_1 + 0x18) = _page_size / param_2;
  return;
}
/* GHIDRADEC_FUNCTION index=3190 start=0x4096fd0 */

int sub_4096FD0(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puStack_8;
  
  while (iVar2 = _page_size, iVar1 = param_1[1], iVar1 == 0) {
    _page_table_alloc_size = _page_size + _page_table_alloc_size;
    param_1[4] = _page_size + param_1[4];
    _kmem_alloc_wired(_kernel_map,&puStack_8,iVar2);
    puStack_8 = (undefined4 *)_pmap_resident_extract(_kernel_pmap,puStack_8);
    for (; iVar2 != 0; iVar2 = iVar2 - param_1[2]) {
      *puStack_8 = 0x2a6a6b73;
      puStack_8[1] = *param_1;
      puStack_8[2] = 0;
      if (*param_1 == 0) {
        param_1[1] = (int)puStack_8;
      }
      else {
        *(undefined4 **)(*param_1 + 8) = puStack_8;
      }
      *param_1 = (int)puStack_8;
      puStack_8 = (undefined4 *)(param_1[2] + *param_1);
      param_1[5] = param_1[5] + 1;
    }
  }
  param_1[1] = *(int *)(iVar1 + 8);
  if (param_1[1] == 0) {
    *param_1 = 0;
  }
  else {
    *(undefined4 *)(param_1[1] + 4) = 0;
  }
  param_1[5] = param_1[5] + -1;
  _page_table_memory_size = param_1[2] + _page_table_memory_size;
  param_1[3] = param_1[2] + param_1[3];
  _bzero(iVar1,param_1[2]);
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=3191 start=0x40970c6 */

uint sub_40970C6(uint *param_1,undefined4 *param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int *unaff_D3;
  int iVar5;
  int *piVar6;
  
  iVar5 = 0;
  *param_2 = 0x2a6a6b73;
  uVar4 = 0;
  iVar3 = _pmap_phys_to_index(param_2);
  if ((iVar3 != -1) && ((int)param_1[6] < (int)param_1[5])) {
    unaff_D3 = (int *)(~_page_mask & (uint)param_2);
    for (piVar6 = unaff_D3;
        (piVar6 < (int *)(_page_size + (int)unaff_D3) && (*piVar6 == 0x2a6a6b73));
        piVar6 = (int *)(param_1[2] + (int)piVar6)) {
      uVar4 = uVar4 + 1;
    }
  }
  *param_2 = 0;
  if ((_pmap_gc == 0) || (uVar4 != param_1[6])) {
    if (*param_1 != 0) {
      *(undefined4 **)(*param_1 + 8) = param_2;
    }
    *param_2 = 0x2a6a6b73;
    param_2[1] = *param_1;
    param_2[2] = 0;
    if (*param_1 == 0) {
      param_1[1] = (uint)param_2;
    }
    else {
      *(undefined4 **)(*param_1 + 8) = param_2;
    }
    *param_1 = (uint)param_2;
    param_1[5] = param_1[5] + 1;
  }
  else {
    uVar4 = *param_1;
    if (uVar4 != 0) {
      uVar2 = ~_page_mask;
      do {
        if (unaff_D3 == (int *)(uVar2 & uVar4)) {
          if (*(int *)(uVar4 + 8) == 0) {
            *param_1 = *(uint *)(uVar4 + 4);
          }
          else {
            *(undefined4 *)(*(int *)(uVar4 + 8) + 4) = *(undefined4 *)(uVar4 + 4);
          }
          if (*(int *)(uVar4 + 4) == 0) {
            param_1[1] = *(uint *)(uVar4 + 8);
          }
          else {
            *(undefined4 *)(*(int *)(uVar4 + 4) + 8) = *(undefined4 *)(uVar4 + 8);
          }
        }
        uVar4 = *(uint *)(uVar4 + 4);
      } while (uVar4 != 0);
    }
    iVar3 = _pmap_phys_to_index(param_2);
    iVar5 = _pv_head_table;
    _page_table_alloc_size = _page_table_alloc_size - _page_size;
    param_1[4] = param_1[4] - _page_size;
    param_1[5] = param_1[5] - param_1[6];
    iVar5 = *(int *)(iVar5 + 8 + iVar3 * 0xc);
  }
  _page_table_memory_size = _page_table_memory_size - param_1[2];
  uVar4 = param_1[2];
  uVar2 = param_1[3];
  uVar1 = uVar2 - uVar4;
  param_1[3] = uVar1;
  uVar4 = (uint)(byte)((uVar2 < uVar4) << 4 | ((int)uVar1 < 0) << 3 | (uVar1 == 0) << 2 |
                       SBORROW4(uVar2,uVar4) << 1 | uVar2 < uVar4);
  if (iVar5 != 0) {
    uVar4 = _kmem_free(_kernel_map,iVar5,_page_size);
  }
  return uVar4;
}
/* GHIDRADEC_FUNCTION index=3192 start=0x409ba26 */

/* WARNING: Control flow encountered unimplemented instructions */

void sub_409BA26(void)

{
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
  halt_unimplemented();
}
/* GHIDRADEC_FUNCTION index=3193 start=0x409bd76 */

/* WARNING: Control flow encountered unimplemented instructions */

void sub_409BD76(void)

{
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
  halt_unimplemented();
}
/* GHIDRADEC_FUNCTION index=3194 start=0x409c614 */

void sub_409C614(void)

{
  word wVar1;
  int unaff_A6;
  
  wVar1 = *(word *)(unaff_A6 + -0xe4);
  if (((wVar1 & 0x20) != 0) && (((wVar1 & 0x10) == 0 || ((wVar1 & 0x7f) == 0x38)))) {
    *(undefined *)(unaff_A6 + -0x48) = 0xff;
    return;
  }
  *(undefined *)(unaff_A6 + -0x48) = 0;
  return;
}
/* GHIDRADEC_FUNCTION index=3195 start=0x409c646 */

void sub_409C646(void)

{
  byte bVar1;
  uint uVar2;
  byte *in_A0;
  byte *extraout_A0;
  byte *extraout_A0_00;
  byte *extraout_A0_01;
  byte *pbVar3;
  int unaff_A6;
  
  *(undefined4 *)(unaff_A6 + -0x54) = 0;
  bVar1 = *in_A0;
  *in_A0 = bVar1 & 0x7f;
  in_A0[2] = -((bVar1 & 0x80) != 0);
  if (*(char *)(unaff_A6 + 0xb) == ',') {
    sub_409C6F2();
    pbVar3 = extraout_A0;
  }
  else if ((*(byte *)(unaff_A6 + -0xe4) & 0x20) == 0) {
    sub_409C6D0();
    pbVar3 = extraout_A0_00;
  }
  else {
    sub_409C6B0();
    pbVar3 = extraout_A0_01;
  }
  if (*(sword *)pbVar3 < 0x4000) {
    *(byte *)(unaff_A6 + -0x54) = *(byte *)(unaff_A6 + -0x54) | 0x10;
  }
  uVar2 = *(uint *)(pbVar3 + 2) >> 0x18;
  *(uint *)(pbVar3 + 2) = uVar2;
  if (uVar2 != 0) {
    *pbVar3 = *pbVar3 | 0x80;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=3196 start=0x409c6b0 */

void sub_409C6B0(void)

{
  int extraout_A0;
  int unaff_A6;
  
  nrm_zero();
  if ((*(byte *)(extraout_A0 + 4) & 0x80) == 0) {
    *(word *)(unaff_A6 + -0x54) = *(word *)(unaff_A6 + -0x54) | 0x80;
    *(byte *)(unaff_A6 + -0x7a) = *(byte *)(unaff_A6 + -0x7a) | 8;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=3197 start=0x409c6d0 */

void sub_409C6D0(void)

{
  int extraout_A0;
  int unaff_A6;
  
  nrm_zero();
  if ((*(byte *)(extraout_A0 + 4) & 0x80) != 0) {
    *(undefined *)(unaff_A6 + -0x54) = *(undefined *)(unaff_A6 + -0x54);
    return;
  }
  *(byte *)(unaff_A6 + -0x54) = *(byte *)(unaff_A6 + -0x54) | 0x80;
  return;
}
/* GHIDRADEC_FUNCTION index=3198 start=0x409c6f2 */

void sub_409C6F2(void)

{
  int extraout_A0;
  int unaff_A6;
  
  nrm_zero();
  if ((*(byte *)(extraout_A0 + 4) & 0x80) != 0) {
    *(undefined *)(unaff_A6 + -0x54) = *(undefined *)(unaff_A6 + -0x54);
    return;
  }
  *(byte *)(unaff_A6 + -0x54) = *(byte *)(unaff_A6 + -0x54) | 0x80;
  return;
}
/* GHIDRADEC_FUNCTION index=3199 start=0x409c714 */

qword sub_409C714(void)

{
  word wVar1;
  undefined2 uVar2;
  undefined2 extraout_D1u;
  undefined2 extraout_D1u_00;
  uint uVar3;
  int iVar4;
  int unaff_A6;
  float10 fVar5;
  
  if ((*(word *)(unaff_A6 + -0xe4) & 0x3b) == 0) {
    if (((sword)(((uint)*(word *)(unaff_A6 + -0xcc) << 0x14) >> 0x10) == -0x10) &&
       (uVar2 = 0, (word)(((uint)*(word *)(unaff_A6 + -0xcc) << 0x11) >> 0x1d) == 7)) {
      if ((*(int *)(unaff_A6 + -200) == 0) && (*(int *)(unaff_A6 + -0xc4) == 0)) {
        *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x2000000;
        if (*(int *)(unaff_A6 + -0xcc) < 0) {
          *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x8000000;
        }
      }
      else {
        *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x1000000;
        *(undefined *)(unaff_A6 + -0xe8) = 0x60;
        if (((*(byte *)(unaff_A6 + -200) & 0x40) == 0) &&
           (*(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x1004080,
           (*(byte *)(unaff_A6 + -0x7e) & 0x40) == 0)) {
          *(byte *)(unaff_A6 + -200) = *(byte *)(unaff_A6 + -200) | 0x40;
        }
        if (*(int *)(unaff_A6 + -0xcc) < 0) {
          *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x8000000;
        }
      }
    }
    else {
      uVar2 = 0;
      if (((*(word *)(unaff_A6 + -0xca) & 0xf) == 0) &&
         ((*(int *)(unaff_A6 + -200) == 0 && (*(int *)(unaff_A6 + -0xc4) == 0)))) {
        if (*(int *)(unaff_A6 + -0xcc) < 0) {
          *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0xc000000;
          *(undefined4 *)(unaff_A6 + -0xcc) = 0x80000000;
          *(undefined4 *)(unaff_A6 + -200) = 0;
          *(undefined4 *)(unaff_A6 + -0xc4) = 0;
        }
        else {
          *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x4000000;
          *(undefined4 *)(unaff_A6 + -0xcc) = 0;
          *(undefined4 *)(unaff_A6 + -200) = 0;
          *(undefined4 *)(unaff_A6 + -0xc4) = 0;
        }
      }
      else {
        fVar5 = (float10)decbin();
        *(undefined (*) [12])(unaff_A6 + -0xcc) = (undefined  [12])fVar5;
        uVar2 = extraout_D1u_00;
      }
    }
  }
  else if (((sword)(((uint)*(word *)(unaff_A6 + -0xcc) << 0x14) >> 0x10) == -0x10) &&
          (uVar2 = 0, (word)(((uint)*(word *)(unaff_A6 + -0xcc) << 0x11) >> 0x1d) == 7)) {
    if (((*(int *)(unaff_A6 + -200) != 0) || (*(int *)(unaff_A6 + -0xc4) != 0)) &&
       ((*(byte *)(unaff_A6 + -200) & 0x40) == 0)) {
      *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x1004080;
    }
  }
  else {
    uVar2 = 0;
    if (((*(word *)(unaff_A6 + -0xca) & 0xf) == 0) &&
       ((*(int *)(unaff_A6 + -200) == 0 && (*(int *)(unaff_A6 + -0xc4) == 0)))) {
      if (*(int *)(unaff_A6 + -0xcc) < 0) {
        *(undefined4 *)(unaff_A6 + -0xcc) = 0x80000000;
        *(undefined4 *)(unaff_A6 + -200) = 0;
        *(undefined4 *)(unaff_A6 + -0xc4) = 0;
      }
      else {
        *(undefined4 *)(unaff_A6 + -0xcc) = 0;
        *(undefined4 *)(unaff_A6 + -200) = 0;
        *(undefined4 *)(unaff_A6 + -0xc4) = 0;
      }
    }
    else {
      fVar5 = (float10)decbin();
      *(undefined (*) [12])(unaff_A6 + -0xcc) = (undefined  [12])fVar5;
      uVar2 = extraout_D1u;
    }
  }
  *(word *)(unaff_A6 + -0xe4) = *(word *)(unaff_A6 + -0xe4) & 0xfbff;
  wVar1 = *(word *)(unaff_A6 + -0xcc) & 0x7fff;
  uVar3 = CONCAT22(uVar2,*(word *)(unaff_A6 + -0xcc)) & 0xffff7fff;
  if (wVar1 != 0x7fff) {
    if (wVar1 != 0) {
      if (wVar1 < 0x4000) {
        *(undefined *)(unaff_A6 + -0xe8) = 0x10;
      }
      else {
        *(undefined *)(unaff_A6 + -0xe8) = 0;
      }
      return (qword)uVar3;
    }
    *(undefined *)(unaff_A6 + -0xe8) = 0x30;
    return CONCAT44(0x20,uVar3);
  }
  iVar4 = *(int *)(unaff_A6 + -200);
  if ((iVar4 == 0) && (iVar4 = *(int *)(unaff_A6 + -0xc4), iVar4 == 0)) {
    *(undefined *)(unaff_A6 + -0xe8) = 0x40;
    return 0x4000000000;
  }
  *(undefined *)(unaff_A6 + -0xe8) = 0x60;
  return CONCAT44(0x60,iVar4);
}

