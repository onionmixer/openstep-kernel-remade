
/* WARNING: Removing unreachable block (ram,0xf00b7ba0) */
/* WARNING: Removing unreachable block (ram,0xf00b7a28) */
/* WARNING: Removing unreachable block (ram,0xf00b7bdc) */
/* WARNING: Removing unreachable block (ram,0xf00b792c) */

undefined8 _esp_hw_reset(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  undefined uVar3;
  char cVar4;
  uint uVar5;
  undefined *puVar6;
  byte bVar7;
  undefined4 unaff_l0;
  uint *puVar8;
  undefined4 unaff_l1;
  int iVar9;
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
  iVar9 = *(int *)(param_1 + 0x9c);
  puVar8 = *(uint **)(param_1 + 0xa0);
  if ((param_2 & 2) == 0) goto loc_F00B7A10;
  if ((param_2 & 0x20) != 0) {
    _eprintf(param_1,aResettingDmaEn);
  }
  uVar1 = *puVar8;
  uVar5 = uVar1 & 0xffffff7f;
  uVar2 = uVar1 >> 0x1c;
  *puVar8 = uVar5;
  if (uVar2 == 9) {
    uVar1 = 0x400000;
    if (*(char *)(param_1 + 0x31) != '\0') {
loc_F00B79FC:
      *puVar8 = uVar5 | uVar1;
    }
loc_F00B7A04:
    uVar1 = *puVar8;
  }
  else if (uVar2 < 10) {
    if (uVar2 == 4) {
      if ((*(byte *)(param_1 + 0x7c) & 0x20) == 0) {
        *puVar8 = uVar5 | 0x800;
        uVar1 = *puVar8;
      }
      else {
        uVar1 = *puVar8;
      }
      uVar5 = 0x40000;
      goto loc_F00B79FC;
    }
    uVar1 = *puVar8;
  }
  else {
    if (uVar2 == 10) {
      if ((byte)(*(char *)(param_1 + 0x31) - 4U) < 2) {
        *puVar8 = uVar1 & 0xffbfff7f | 0x200000;
      }
      if ((*(byte *)(param_1 + 0x7c) & 0x20) != 0) {
        *puVar8 = *puVar8 & 0xfff3ffff | 0x40000;
      }
      goto loc_F00B7A04;
    }
    uVar1 = *puVar8;
  }
  *puVar8 = uVar1 | 0x10;
loc_F00B7A10:
  if ((param_2 & 1) != 0) {
    if ((param_2 & 0x20) != 0) {
      _eprintf(param_1,aResettingEspCh);
    }
    *(undefined *)(iVar9 + 0xc) = 0x80;
    *(byte *)(iVar9 + 0x24) = *(byte *)(param_1 + 0x3d) & 7;
    *(undefined *)(iVar9 + 0x14) = *(undefined *)(param_1 + 0x40);
    *(undefined *)(iVar9 + 0x18) = 0;
    *(undefined *)(iVar9 + 0x1c) = 0;
    *(undefined *)(iVar9 + 0x20) = *(undefined *)(param_1 + 0x32);
    cVar4 = *(char *)(param_1 + 0x31);
    if (cVar4 == '\x05') {
      uVar3 = 4;
      if (*(byte *)(iVar9 + 0x38) >> 3 == 2) {
        uVar3 = 3;
      }
      *(undefined *)(param_1 + 0x31) = uVar3;
      cVar4 = *(char *)(param_1 + 0x31);
    }
    switch(cVar4) {
    case :
      *(undefined *)(iVar9 + 0x2c) = *(undefined *)(param_1 + 0x33);
      break;
    case :
      *(undefined *)(iVar9 + 0x2c) = *(undefined *)(param_1 + 0x33);
      *(undefined *)(iVar9 + 0x30) = *(undefined *)(param_1 + 0x34);
      break;
    case :
      bVar7 = 0;
      do {
        uVar1 = (uint)bVar7;
        bVar7 = bVar7 + 1;
        *(byte *)(param_1 + uVar1 + 0x34) = *(byte *)(param_1 + uVar1 + 0x34) | 8;
      } while (bVar7 < 8);
      *(undefined *)(iVar9 + 0x2c) = *(undefined *)(param_1 + 0x33);
      if (*(char *)(param_1 + 0x3c) == '\0') {
        *(undefined *)(param_1 + 0x77) = 0x60;
      }
      else {
        *(undefined *)(param_1 + 0x77) = 0;
      }
      break;
    case :
      bVar7 = 0;
      do {
        uVar1 = (uint)bVar7;
        bVar7 = bVar7 + 1;
        *(byte *)(param_1 + uVar1 + 0x34) = *(byte *)(param_1 + uVar1 + 0x34) | 1;
      } while (bVar7 < 8);
      *(undefined *)(iVar9 + 0x2c) = *(undefined *)(param_1 + 0x33);
      *(undefined *)(param_1 + 0x77) = 0x20;
    }
  }
  if ((param_2 & 0xc) != 0) {
    if ((param_2 & 0x20) != 0) {
      if ((param_2 & 8) == 0) {
        puVar6 = aNotIgnored;
      }
      else {
        puVar6 = (undefined *)&aIgnored;
      }
      _eprintf(param_1,aResettingScsiB,puVar6);
    }
    if ((param_2 & 8) == 0) {
      *(undefined *)(iVar9 + 0xc) = 3;
    }
    else {
      *(byte *)(iVar9 + 0x20) = *(byte *)(param_1 + 0x32) | 0x40;
      *(undefined *)(iVar9 + 0xc) = 3;
      *(undefined *)(iVar9 + 0x20) = *(undefined *)(param_1 + 0x32);
    }
    _us_spin(_scsi_reset_delay);
  }
  return CONCAT44(param_2,param_1);
}
