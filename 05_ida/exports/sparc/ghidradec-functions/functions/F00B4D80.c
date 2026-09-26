
/* WARNING: Removing unreachable block (ram,0xf00b4f1c) */
/* WARNING: Removing unreachable block (ram,0xf00b4eac) */
/* WARNING: Removing unreachable block (ram,0xf00b4f60) */
/* WARNING: Removing unreachable block (ram,0xf00b4e50) */

undefined8 _espsvc(int param_1,undefined4 param_2)

{
  byte bVar1;
  byte bVar2;
  uint *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint *puVar7;
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
  undefined auStackX_0 [92];
  
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
  *(code **)((int)register0x00000038 + -0x30) = _esp_finish_select;
  *(code **)((int)register0x00000038 + -0x2c) = _esp_reconnect;
  *(code **)((int)register0x00000038 + -0x28) = _esp_phasemanage;
  *(code **)((int)register0x00000038 + -0x24) = _esp_finish;
  *(code **)((int)register0x00000038 + -0x20) = _esp_reset_recovery;
  *(code **)((int)register0x00000038 + -0x1c) = _esp_istart;
  *(code **)((int)register0x00000038 + -0x18) = _esp_abort_curcmd;
  *(code **)((int)register0x00000038 + -0x14) = _esp_abort_allcmds;
  *(code **)((int)register0x00000038 + -0x10) = _esp_reset_bus;
  *(code **)((int)register0x00000038 + -0xc) = _esp_handle_selection;
  puVar7 = *(uint **)(param_1 + 0xa0);
  iVar5 = *(int *)(param_1 + 0x9c);
  if (*puVar7 >> 0x1c == 8) {
    *puVar7 = *puVar7 & 0xffffffef;
  }
  *(byte *)(param_1 + 0x45) = *(byte *)(iVar5 + 0x18) & 7;
  *(undefined *)(param_1 + 0x43) = *(undefined *)(iVar5 + 0x10);
  bVar1 = *(byte *)(iVar5 + 0x14);
  *(byte *)(param_1 + 0x44) = bVar1;
  if ((*(byte *)(param_1 + 0x43) & 0x40) == 0) {
loc_F00B4E90:
    puVar3 = *(uint **)(param_1 + 0xa0);
  }
  else {
    _esplog(param_1,3,aGrossErrorInEs);
    if (*(sword *)(param_1 + 0xb2) == -1) {
      iVar5 = 7;
      goto loc_F00B4F98;
    }
    iVar5 = *(int *)(*(sword *)(param_1 + 0xb2) * 4 + param_1 + 0xb8);
    if (*(char *)(iVar5 + 0x28) == '\0') {
      *(undefined *)(iVar5 + 0x28) = 3;
      goto loc_F00B4E90;
    }
    puVar3 = *(uint **)(param_1 + 0xa0);
  }
  if ((*puVar3 & 2) == 0) {
loc_F00B4EE8:
    if (*(char *)(param_1 + 0x31) != '\x02') {
      *(byte *)(param_1 + 0x43) = *(byte *)(param_1 + 0x43) & 0x7f;
    }
    iVar5 = 4;
    if ((bVar1 & 0x80) != 0) goto loc_F00B4F98;
    if ((bVar1 & 0x40) != 0) {
      _esp_printstate(param_1,aIllegalBitSet);
      iVar5 = 6;
      goto loc_F00B4F98;
    }
    iVar5 = 9;
    if ((bVar1 & 3) != 0) goto loc_F00B4F98;
    bVar2 = *(byte *)(param_1 + 0x41);
    if ((bVar1 & 4) == 0) {
      if ((bVar2 & 0xe0) == 0) {
        iVar5 = -1;
        if ((bVar2 & 0x1f) != 0) {
          iVar5 = 2;
        }
      }
      else {
        iVar5 = 0;
      }
      goto loc_F00B4F98;
    }
    if ((bVar2 & 0xe0) != 0) {
      iVar5 = 0;
      goto loc_F00B4F98;
    }
    if (bVar2 == 0) {
      iVar5 = 1;
      goto loc_F00B4F98;
    }
    _esp_printstate(param_1,aIllegalReselec);
  }
  else {
    _esplog(param_1,3,aUnrecoverableD);
    if (*(sword *)(param_1 + 0xb2) == -1) goto loc_F00B4EE8;
    iVar4 = *(int *)(*(sword *)(param_1 + 0xb2) * 4 + param_1 + 0xb8);
    iVar5 = 8;
    if (*(char *)(iVar4 + 0x28) != '\0') goto loc_F00B4F98;
    *(undefined *)(iVar4 + 0x28) = 3;
  }
  iVar5 = 8;
loc_F00B4F98:
  if (iVar5 == -1) {
    uVar6 = *puVar7;
  }
  else {
    do {
      iVar4 = iVar5 * 4;
      iVar5 = param_1;
      (**(code **)((int)register0x00000038 + iVar4 + -0x30))();
    } while (iVar5 != -1);
    uVar6 = *puVar7;
  }
  if (uVar6 >> 0x1c == 8) {
    *puVar7 = uVar6 | 0x10;
  }
  return CONCAT44(param_2,param_1);
}
