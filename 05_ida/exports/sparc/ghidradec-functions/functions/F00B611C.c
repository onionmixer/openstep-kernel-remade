
/* WARNING: Removing unreachable block (ram,0xf00b63d8) */
/* WARNING: Removing unreachable block (ram,0xf00b636c) */
/* WARNING: Removing unreachable block (ram,0xf00b63f0) */
/* WARNING: Removing unreachable block (ram,0xf00b6354) */
/* WARNING: Removing unreachable block (ram,0xf00b6184) */

undefined8 _esp_onebyte_msg(int param_1,undefined4 param_2)

{
  byte bVar1;
  word wVar2;
  undefined *puVar3;
  uint uVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar5;
  undefined4 unaff_l3;
  undefined uVar6;
  undefined4 unaff_l4;
  uint uVar7;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar8;
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
  bVar1 = *(byte *)(param_1 + 0x54);
  uVar4 = (uint)bVar1;
  iVar5 = *(int *)(*(sword *)(param_1 + 0xb2) * 4 + param_1 + 0xb8);
  iVar8 = 0;
  wVar2 = *(word *)(iVar5 + 8);
  uVar7 = (uint)wVar2;
  if ((bVar1 & 0x80) != 0) {
    bVar9 = (bVar1 & 0x58) != 0;
    if (bVar9) {
      puVar3 = (undefined *)&aGarbled;
    }
    else {
      puVar3 = aIdentify;
    }
    _esplog(param_1,3,aSMessage0xXFro,puVar3,uVar4,uVar7);
    if (bVar9) {
      iVar8 = 5;
    }
    else {
      *(undefined *)(param_1 + 0x42) = *(undefined *)(param_1 + 0x41);
      *(undefined *)(param_1 + 0x41) = 0x1a;
    }
    goto locret_F00B63F8;
  }
  if (((uVar4 & 0xf0) == 0x20) || (uVar4 == 1)) {
    *(undefined *)(param_1 + 0x5c) = 2;
    iVar8 = 0;
    *(undefined *)(param_1 + 0x42) = *(undefined *)(param_1 + 0x41);
    *(undefined *)(param_1 + 0x41) = 6;
    goto locret_F00B63F8;
  }
  *(undefined *)(param_1 + 0x42) = *(undefined *)(param_1 + 0x41);
  *(undefined *)(param_1 + 0x41) = 0x1a;
  switch(uVar4) {
  case :
  case :
  case :
    goto loc_F00B6264;
  :
    iVar8 = 7;
    _scsi_mname(uVar4);
    _esplog(param_1,5,aRejectingMessa,uVar4,uVar7);
    break;
  case :
    *(undefined4 *)(iVar5 + 0x38) = *(undefined4 *)(iVar5 + 0x34);
    break;
  case :
    *(undefined4 *)(iVar5 + 0x2c) = *(undefined4 *)(iVar5 + 0x20);
    *(undefined4 *)(iVar5 + 0x30) = *(undefined4 *)(iVar5 + 0x1c);
    if (*(int *)(iVar5 + 0x34) != *(int *)(iVar5 + 0x38)) {
      *(int *)(iVar5 + 0x34) = *(int *)(iVar5 + 0x38);
      *(word *)(iVar5 + 0x5c) = *(word *)(iVar5 + 0x5c) | 0x1000;
    }
    break;
  case :
    if ((*(uint *)(iVar5 + 0x14) & 2) != 0) {
      iVar8 = 7;
      break;
    }
loc_F00B6264:
    *(undefined *)(param_1 + 0x41) = 8;
    break;
  case :
    uVar6 = 0;
    uVar4 = (uint)*(byte *)(param_1 + 0x52);
    iVar8 = 6;
    switch(uVar4) {
    case :
      *(undefined *)(param_1 + 0x46) = 0;
      *(undefined *)(param_1 + uVar7 + 0x5e) = 0;
      iVar8 = 0;
      *(byte *)(param_1 + 0x78) = *(byte *)(param_1 + 0x78) | (byte)(1 << ((byte)wVar2 & 0x1f));
      break;
    :
      if ((uVar4 & 0x98) != 0x80) {
        if (uVar4 == 0xff) {
          if (*(char *)(param_1 + 0x53) == '\0') goto loc_F00B6338;
          uVar6 = 3;
        }
        else {
          uVar6 = 3;
        }
        goto loc_F00B6340;
      }
loc_F00B6338:
      iVar8 = 0;
      break;
    case :
      uVar6 = 0xd;
      break;
    case :
      uVar6 = 0xe;
loc_F00B6340:
      iVar8 = -6;
      break;
    case :
      uVar6 = 0xf;
      break;
    case :
      uVar6 = 0x10;
      break;
    case :
      uVar6 = 0x11;
    }
    if (iVar8 != 0) {
      _scsi_mname(uVar4);
      _esplog(param_1,4,aTargetDRejects,uVar7,uVar4);
      if (*(char *)(iVar5 + 0x28) == '\0') {
        *(undefined *)(iVar5 + 0x28) = uVar6;
      }
    }
    break;
  case :
    break;
  }
locret_F00B63F8:
  return CONCAT44(param_2,iVar8);
}
