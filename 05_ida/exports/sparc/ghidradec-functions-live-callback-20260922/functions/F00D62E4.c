
/* WARNING: Removing unreachable block (ram,0xf00d648c) */
/* WARNING: Removing unreachable block (ram,0xf00d644c) */
/* WARNING: Removing unreachable block (ram,0xf00d64c8) */
/* WARNING: Removing unreachable block (ram,0xf00d6420) */
/* WARNING: Removing unreachable block (ram,0xf00d6468) */
/* WARNING: Removing unreachable block (ram,0xf00d64dc) */
/* WARNING: Removing unreachable block (ram,0xf00d62fc) */

undefined8 -[KeyMap _calcModBit:keyBits:](int param_1,undefined4 param_2,int param_3,int param_4)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined (*pauVar4) [18];
  byte *pbVar5;
  int iVar6;
  uint uVar7;
  undefined4 unaff_l0;
  uint uVar8;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar9;
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
  uVar1 = *(uint *)(param_1 + 0x4f8);
  uVar8 = 1 << ((char)param_3 + 0x10U & 0x1f);
  _objc_msgSend(uVar1,paDeviceflags);
  pbVar5 = *(byte **)(param_1 + param_3 * 4 + 0x8c);
  uVar1 = uVar1 & ~uVar8;
  if (pbVar5 == (byte *)0x0) {
loc_F00D63A8:
    bVar9 = false;
  }
  else {
    iVar6 = 0;
    if (*(sword *)(param_1 + 4) == 0) {
      uVar7 = (uint)*pbVar5;
      pbVar5 = pbVar5 + 1;
    }
    else {
      uVar7 = (uint)*(sword *)pbVar5;
      pbVar5 = pbVar5 + 2;
    }
    if (0 < (int)uVar7) {
      do {
        if (*(sword *)(param_1 + 4) == 0) {
          uVar3 = (uint)*pbVar5;
          pbVar5 = pbVar5 + 1;
        }
        else {
          uVar3 = (uint)*(sword *)pbVar5;
          pbVar5 = pbVar5 + 2;
        }
        iVar6 = iVar6 + 1;
        if ((*(uint *)(param_4 + (uVar3 >> 5) * 4) & 1 << ((byte)uVar3 & 0x1f)) != 0) {
          bVar9 = true;
          goto loc_F00D63AC;
        }
      } while (iVar6 < (int)uVar7);
      goto loc_F00D63A8;
    }
    bVar9 = false;
  }
loc_F00D63AC:
  if (bVar9) {
    uVar1 = uVar1 | uVar8;
  }
  if (param_3 == 1) {
    if ((((uVar1 & 0x100000) != 0) && (*(int *)(param_1 + 0x8c) == 0)) &&
       (*(sword *)(param_1 + 0x4e0) == -1)) {
      bVar9 = false;
      if ((uVar1 & 0x20000) == 0) {
        uVar8 = *(uint *)(param_1 + 0x4f8);
        _objc_msgSend(uVar8,paCharkeyactive,0);
        pauVar4 = (undefined (*) [18])paSetalphalock;
        if ((uVar8 & 0xff) != 0) goto loc_F00D6478;
        uVar7 = *(uint *)(param_1 + 0x4f8);
        uVar8 = uVar7;
        _objc_msgSend(uVar7,paAlphalock);
        bVar9 = (uVar8 & 0xff) == 0;
      }
      else {
        uVar7 = *(uint *)(param_1 + 0x4f8);
        pauVar4 = paSetcharkeyacti;
      }
      _objc_msgSend(uVar7,pauVar4,bVar9);
    }
loc_F00D6478:
    uVar8 = uVar1 & 0xfffeffff;
    uVar2 = *(undefined4 *)(param_1 + 0x4f8);
    _objc_msgSend(uVar2,paAlphalock,uVar1 & 0x20000);
    uVar1 = uVar8 | (uVar1 & 0x20000) >> 1;
    if ((char)uVar2 == '\x01') {
      uVar1 = uVar8 | 0x10000;
    }
  }
  else {
    uVar2 = *(undefined4 *)(param_1 + 0x4f8);
    if (param_3 != 0) goto loc_F00D64D4;
    _objc_msgSend(uVar2,paSetalphalock,uVar1 >> 0x10 & 1);
  }
  uVar2 = *(undefined4 *)(param_1 + 0x4f8);
loc_F00D64D4:
  _objc_msgSend(uVar2,paSetdeviceflags,uVar1);
  return CONCAT44(param_2,param_1);
}

