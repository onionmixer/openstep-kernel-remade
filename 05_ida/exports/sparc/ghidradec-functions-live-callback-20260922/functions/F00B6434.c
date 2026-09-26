
/* WARNING: Removing unreachable block (ram,0xf00b6730) */
/* WARNING: Removing unreachable block (ram,0xf00b66ec) */
/* WARNING: Removing unreachable block (ram,0xf00b66d0) */
/* WARNING: Removing unreachable block (ram,0xf00b6624) */
/* WARNING: Removing unreachable block (ram,0xf00b65e0) */
/* WARNING: Removing unreachable block (ram,0xf00b64b4) */
/* WARNING: Removing unreachable block (ram,0xf00b682c) */
/* WARNING: Removing unreachable block (ram,0xf00b64d8) */
/* WARNING: Removing unreachable block (ram,0xf00b660c) */
/* WARNING: Removing unreachable block (ram,0xf00b66c8) */
/* WARNING: Removing unreachable block (ram,0xf00b66e0) */
/* WARNING: Removing unreachable block (ram,0xf00b66f4) */
/* WARNING: Removing unreachable block (ram,0xf00b6648) */
/* WARNING: Removing unreachable block (ram,0xf00b6810) */

undefined8 _esp_multibyte_msg(int param_1,undefined4 param_2)

{
  char cVar1;
  word wVar2;
  byte bVar3;
  undefined uVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  undefined4 unaff_l0;
  uint uVar9;
  undefined4 unaff_l1;
  byte bVar10;
  undefined4 unaff_l3;
  uint uVar11;
  byte bVar12;
  undefined4 unaff_l4;
  int iVar13;
  undefined4 unaff_l5;
  int iVar14;
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
  iVar14 = *(int *)(param_1 + 0x9c);
  cVar1 = *(char *)(param_1 + 0x56);
  iVar8 = *(int *)(*(sword *)(param_1 + 0xb2) * 4 + param_1 + 0xb8);
  iVar13 = 0;
  wVar2 = *(word *)(iVar8 + 8);
  uVar11 = (uint)wVar2;
  if (cVar1 == '\x01') {
    uVar9 = (uint)*(byte *)(param_1 + 0x57);
    bVar10 = *(byte *)(param_1 + 0x58);
    uVar5 = (uint)*(word *)(param_1 + 0x3e);
    if ((byte)(*(char *)(param_1 + 0x31) - 3U) < 2) {
      uVar6 = 0xfa;
    }
    else if ((*(byte *)(param_1 + 0x32) & 0x80) == 0) {
      uVar6 = 200;
    }
    else {
      uVar5 = uVar5 * 6;
      uVar6 = 1000;
    }
    div(uVar5,uVar6);
    uVar5 = (int)(uVar5 + 3) >> 2;
    iVar8 = (uint)*(word *)(param_1 + 0x3e) * 0x23;
    div(iVar8,1000);
    bVar3 = *(char *)(param_1 + 0x46) + 1;
    *(byte *)(param_1 + 0x46) = bVar3;
    bVar12 = (byte)wVar2;
    if (((bVar3 & 1) == 0) ||
       ((iVar13 = 1, ((int)(uint)*(byte *)(param_1 + 0x7a) >> (bVar12 & 0x1f) & 1U) == 0 &&
        ((_scsi_options & 0x20) != 0)))) {
      uVar7 = 0;
      if (0xf < bVar10) {
        bVar10 = 0xf;
      }
      if ((bVar10 == 0) || (uVar9 <= (uint)(iVar8 + 3 >> 2))) {
        if ((bVar10 == 0) || (uVar5 <= uVar9)) {
          uVar5 = uVar9;
          if (bVar10 != 0) {
            uVar5 = (uint)*(word *)(param_1 + 0x3e);
            udiv(uVar5,1000);
            if (*(char *)(param_1 + uVar11 + 0x6e) != '\0') {
              uVar9 = uVar9 * 0x78;
              udiv(uVar9,100);
            }
            uVar7 = (uVar9 * 4 + (uVar5 & 0xffff)) - 1;
            udiv(uVar7,uVar5 & 0xffff);
            uVar5 = uVar9;
            if (0x23 < uVar7) goto loc_F00B6644;
          }
        }
        else if ((byte)(*(char *)(param_1 + 0x31) - 3U) < 2) {
          uVar7 = 4;
        }
        else {
          uVar7 = 5;
          if ((*(byte *)(param_1 + 0x32) & 0x80) != 0) {
            uVar7 = 6;
          }
        }
        iVar8 = param_1 + uVar11;
        if (bVar10 == 0) {
          if (*(char *)(iVar8 + 0x5e) != '\0') {
            *(undefined *)(iVar8 + 0x66) = 0;
            *(undefined *)(iVar14 + 0x18) = 0;
            *(undefined *)(iVar8 + 0x5e) = 0;
            *(undefined *)(iVar14 + 0x1c) = 0;
          }
        }
        else {
          *(byte *)(iVar8 + 0x66) = (byte)uVar7;
          *(byte *)(iVar14 + 0x18) = (byte)uVar7 & 0x1f;
          bVar3 = *(byte *)(param_1 + 0x77) | bVar10;
          *(byte *)(iVar8 + 0x5e) = bVar3;
          *(byte *)(iVar14 + 0x1c) = bVar3;
          if ((byte)(*(char *)(param_1 + 0x31) - 3U) < 2) {
            if (uVar5 < 0x32) {
              if (*(char *)(param_1 + 0x31) == '\x03') {
                bVar3 = *(byte *)(iVar8 + 0x34) | 0x10;
              }
              else {
                bVar3 = *(byte *)(iVar8 + 0x34) | 2;
              }
              *(byte *)(iVar8 + 0x34) = bVar3;
            }
            *(undefined *)(iVar14 + 0x30) = *(undefined *)(param_1 + uVar11 + 0x34);
          }
          umul(uVar7,*(undefined2 *)(param_1 + 0x3e));
          udiv();
          iVar8 = 1000000000;
          udiv(1000000000,uVar7);
          udiv(iVar8 + 999,1000);
          urem();
        }
        if (iVar13 != 0) {
          _esp_make_sdtr(param_1,uVar5,bVar10);
        }
        *(byte *)(param_1 + 0x78) = *(byte *)(param_1 + 0x78) | (byte)(1 << (bVar12 & 0x1f));
        goto loc_F00B6838;
      }
    }
    else if ((byte)(*(char *)(param_1 + 0x31) - 3U) < 2) {
      if (uVar9 < 100) {
        uVar9 = 100;
      }
    }
    else if (uVar9 < 0xb4) {
      uVar9 = 0xb4;
    }
loc_F00B6644:
    iVar13 = 1;
    _esp_make_sdtr(param_1,uVar9,0);
    uVar4 = *(undefined *)(param_1 + 0x41);
    goto loc_F00B683C;
  }
  uVar6 = 1;
  if (cVar1 == '\0') {
    if ((*(word *)(iVar8 + 0x5c) & 1) == 0) {
      iVar13 = 7;
    }
    else {
      uVar5 = (uint)*(byte *)(param_1 + 0x57) << 0x18 | (uint)*(byte *)(param_1 + 0x58) << 0x10 |
              (uint)*(byte *)(param_1 + 0x59) << 8 | (uint)*(byte *)(param_1 + 0x5a);
      uVar11 = *(int *)(iVar8 + 0x34) + uVar5;
      *(uint *)(iVar8 + 0x34) = uVar11;
      if ((uVar11 < *(uint *)(iVar8 + 0x3c)) ||
         (*(uint *)(iVar8 + 0x3c) + *(int *)(iVar8 + 0x40) <= uVar11)) {
        *(uint *)(iVar8 + 0x34) = uVar11 - uVar5;
        goto loc_F00B6834;
      }
      uVar5 = (*(uint **)(iVar8 + 0x54))[1];
      if (uVar5 == 0) {
        uVar4 = *(undefined *)(param_1 + 0x41);
        goto loc_F00B683C;
      }
      uVar9 = **(uint **)(iVar8 + 0x54);
      if ((uVar9 <= uVar11) && (uVar11 < uVar9 + uVar5)) {
        uVar4 = *(undefined *)(param_1 + 0x41);
        goto loc_F00B683C;
      }
      *(word *)(iVar8 + 0x5c) = *(word *)(iVar8 + 0x5c) | 0x1000;
    }
  }
  else {
    _scsi_mname(1);
    _esplog(param_1,5,aRejectingMessa_0,uVar6,cVar1,uVar11);
loc_F00B6834:
    iVar13 = 7;
  }
loc_F00B6838:
  uVar4 = *(undefined *)(param_1 + 0x41);
loc_F00B683C:
  *(undefined *)(param_1 + 0x42) = uVar4;
  *(undefined *)(param_1 + 0x41) = 0x1a;
  return CONCAT44(param_2,iVar13);
}

