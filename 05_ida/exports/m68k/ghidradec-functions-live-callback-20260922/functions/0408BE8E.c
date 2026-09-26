
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

