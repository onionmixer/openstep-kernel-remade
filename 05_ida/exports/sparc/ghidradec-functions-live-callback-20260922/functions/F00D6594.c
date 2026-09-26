
/* WARNING: Removing unreachable block (ram,0xf00d6a38) */
/* WARNING: Removing unreachable block (ram,0xf00d69ec) */
/* WARNING: Removing unreachable block (ram,0xf00d69a8) */
/* WARNING: Removing unreachable block (ram,0xf00d68fc) */
/* WARNING: Removing unreachable block (ram,0xf00d6858) */
/* WARNING: Removing unreachable block (ram,0xf00d67d0) */
/* WARNING: Removing unreachable block (ram,0xf00d65cc) */
/* WARNING: Removing unreachable block (ram,0xf00d67e4) */
/* WARNING: Removing unreachable block (ram,0xf00d68d0) */
/* WARNING: Removing unreachable block (ram,0xf00d6950) */
/* WARNING: Removing unreachable block (ram,0xf00d69d8) */
/* WARNING: Removing unreachable block (ram,0xf00d6a0c) */
/* WARNING: Removing unreachable block (ram,0xf00d6a64) */
/* WARNING: Removing unreachable block (ram,0xf00d65a8) */

undefined8 -[KeyMap _doCharGen:direction:](int param_1,uint param_2,uint param_3,char param_4)

{
  sword sVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  uint uVar8;
  int iVar9;
  word wVar11;
  undefined4 uVar10;
  uint uVar12;
  undefined4 unaff_l0;
  word *pwVar13;
  byte *pbVar14;
  undefined4 unaff_l1;
  int iVar15;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 uVar16;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar17;
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
  uVar16 = 0xb;
  _objc_msgSend(*(undefined4 *)(param_1 + 0x4f8),paSetcharkeyacti,1);
  if (param_4 == '\x01') {
    uVar16 = 10;
  }
  uVar4 = *(uint *)(param_1 + 0x4f8);
  _objc_msgSend(uVar4,paEventflags);
  pwVar13 = *(word **)(param_3 * 4 + param_1 + 0xd0);
  sVar1 = *(sword *)(param_1 + 4);
  uVar5 = uVar4 >> 0x10;
  uVar8 = uVar4;
  if (pwVar13 == (word *)0x0) goto loc_F00D6958;
  if (sVar1 == 0) {
    wVar11 = (word)*(byte *)pwVar13;
    pwVar13 = (word *)((int)pwVar13 + 1);
  }
  else {
    wVar11 = *pwVar13;
    pwVar13 = pwVar13 + 1;
  }
  if ((wVar11 != 0) && (uVar5 != 0)) {
    iVar9 = 2;
    if (sVar1 != 0) {
      iVar9 = 4;
    }
    iVar15 = 0;
    if (*(uint *)(param_1 + 0x88) < 0x80000000) {
      do {
        if ((wVar11 & 1) != 0) {
          if ((uVar5 & 1) != 0) {
            pwVar13 = (word *)((int)pwVar13 + iVar9);
          }
          iVar9 = iVar9 << 1;
        }
        wVar11 = (sword)wVar11 >> 1;
        iVar15 = iVar15 + 1;
        uVar5 = (int)uVar5 >> 1;
      } while (iVar15 <= (int)*(uint *)(param_1 + 0x88));
    }
  }
  if (sVar1 == 0) {
    uVar5 = (uint)*(byte *)pwVar13;
    uVar12 = (uint)(byte)*pwVar13;
  }
  else {
    uVar5 = (uint)(sword)*pwVar13;
    uVar12 = (uint)(sword)pwVar13[1];
  }
  pwVar13 = *(word **)(param_3 * 4 + param_1 + 0xd0);
  uVar6 = uVar4 >> 0x10 & 3;
  if (sVar1 == 0) {
    wVar11 = (word)*(byte *)pwVar13;
    pwVar13 = (word *)((int)pwVar13 + 1);
  }
  else {
    wVar11 = *pwVar13;
    pwVar13 = pwVar13 + 1;
  }
  if ((wVar11 != 0) && (uVar6 != 0)) {
    iVar9 = 2;
    if (sVar1 != 0) {
      iVar9 = 4;
    }
    iVar15 = 0;
    if (*(uint *)(param_1 + 0x88) < 0x80000000) {
      do {
        if ((wVar11 & 1) != 0) {
          if ((uVar6 & 1) != 0) {
            pwVar13 = (word *)((int)pwVar13 + iVar9);
          }
          iVar9 = iVar9 << 1;
        }
        wVar11 = (sword)wVar11 >> 1;
        iVar15 = iVar15 + 1;
        uVar6 = (int)uVar6 >> 1;
      } while (iVar15 <= (int)*(uint *)(param_1 + 0x88));
    }
  }
  if (sVar1 == 0) {
    uVar3 = (uint)*(byte *)pwVar13;
    uVar6 = (uint)(byte)*pwVar13;
    if (uVar5 != 0xff) goto loc_F00D6930;
loc_F00D6788:
    pbVar14 = *(byte **)(uVar12 * 4 + param_1 + 0x2d4);
    iVar9 = 0;
    if (sVar1 == 0) {
      uVar5 = (uint)*pbVar14;
      pbVar14 = pbVar14 + 1;
    }
    else {
      uVar5 = (uint)*(sword *)pbVar14;
      pbVar14 = pbVar14 + 2;
    }
    iVar15 = 0;
    if (0 < (int)uVar5) {
      do {
        iVar15 = iVar9;
        rem(iVar9,10);
        if (iVar15 == 9) {
          _thread_block();
        }
        if (sVar1 == 0) {
          uVar12 = (uint)*pbVar14;
          pbVar14 = pbVar14 + 1;
        }
        else {
          uVar12 = (uint)*(sword *)pbVar14;
          pbVar14 = pbVar14 + 2;
        }
        if (uVar12 == 0xff) {
          if (param_4 == '\x01') {
            if (sVar1 != 0) {
              bVar2 = (byte)*(sword *)pbVar14;
              pbVar14 = pbVar14 + 2;
            }
            else {
              bVar2 = *pbVar14;
              pbVar14 = pbVar14 + 1;
            }
            uVar3 = uVar8 | 1 << (bVar2 + 0x10 & 0x1f);
            uVar8 = *(uint *)(param_1 + 0x4f8);
            _objc_msgSend(uVar8,paDeviceflags);
            uVar7 = *(undefined4 *)(param_1 + 0x4f8);
            uVar6 = 0;
            uVar12 = 0;
            uVar10 = 0xc;
            goto loc_F00D68D0;
          }
          if (sVar1 != 0) {
            pbVar14 = pbVar14 + 2;
          }
          else {
            pbVar14 = pbVar14 + 1;
          }
        }
        else {
          if (sVar1 == 0) {
            uVar6 = (uint)*pbVar14;
            pbVar14 = pbVar14 + 1;
          }
          else {
            uVar6 = (uint)*(sword *)pbVar14;
            pbVar14 = pbVar14 + 2;
          }
          uVar7 = *(undefined4 *)(param_1 + 0x4f8);
          uVar10 = uVar16;
          uVar3 = uVar8;
loc_F00D68D0:
          _objc_msgSend(uVar7,paKeyboardeventF,uVar10,uVar8,param_3,uVar6,uVar12,uVar6,uVar12);
          uVar8 = uVar3;
        }
        iVar9 = iVar9 + 1;
      } while (iVar9 < (int)uVar5);
      iVar15 = uVar8 - uVar4;
    }
    param_2 = uVar4;
    if (iVar15 == 0) goto loc_F00D6958;
    uVar8 = *(uint *)(param_1 + 0x4f8);
    _objc_msgSend(uVar8,paDeviceflags);
    uVar10 = 0xc;
    uVar12 = 0;
    uVar7 = *(undefined4 *)(param_1 + 0x4f8);
    uVar5 = 0;
    uVar6 = 0;
    uVar3 = 0;
  }
  else {
    uVar3 = (uint)(sword)*pwVar13;
    uVar6 = (uint)(sword)pwVar13[1];
    if (uVar5 == 0xffff) goto loc_F00D6788;
loc_F00D6930:
    uVar7 = *(undefined4 *)(param_1 + 0x4f8);
    uVar10 = uVar16;
  }
  _objc_msgSend(uVar7,paKeyboardeventF,uVar10,uVar8,param_3,uVar12,uVar5,uVar6,uVar3);
  uVar8 = uVar4;
loc_F00D6958:
  iVar15 = 0;
  iVar9 = param_1;
  if ((*(byte *)(param_1 + param_3 + 6) & 0x40) != 0) {
    do {
      if (param_3 == *(word *)(iVar9 + 0x4d8)) {
        _objc_msgSend(*(undefined4 *)(param_1 + 0x4f8),paKeyboardspecia,uVar16,uVar8,param_3,iVar15)
        ;
        if (((iVar15 == 4) && (*(int *)(param_1 + 0x8c) == 0)) && (param_4 == '\x01')) {
          uVar8 = *(uint *)(param_1 + 0x4f8);
          _objc_msgSend(uVar8,paDeviceflags);
          uVar4 = *(uint *)(param_1 + 0x4f8);
          _objc_msgSend(uVar4,paAlphalock);
          bVar17 = (uVar4 & 0xff) == 0;
          _objc_msgSend(*(undefined4 *)(param_1 + 0x4f8),paSetalphalock,bVar17);
          if (bVar17) {
            uVar8 = uVar8 | 0x10000;
          }
          else {
            uVar8 = uVar8 & 0xfffeffff;
          }
          _objc_msgSend(*(undefined4 *)(param_1 + 0x4f8),paSetdeviceflags,uVar8);
          _objc_msgSend(*(undefined4 *)(param_1 + 0x4f8),paKeyboardeventF,0xc,uVar8,param_3,0,0,0,0)
          ;
        }
        break;
      }
      iVar15 = iVar15 + 1;
      iVar9 = iVar9 + 2;
    } while (iVar15 < 7);
  }
  return CONCAT44(param_2,param_1);
}

