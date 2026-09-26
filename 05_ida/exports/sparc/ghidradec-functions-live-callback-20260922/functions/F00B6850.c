
/* WARNING: Removing unreachable block (ram,0xf00b6a34) */
/* WARNING: Removing unreachable block (ram,0xf00b6a3c) */
/* WARNING: Removing unreachable block (ram,0xf00b6afc) */
/* WARNING: Removing unreachable block (ram,0xf00b691c) */
/* WARNING: Removing unreachable block (ram,0xf00b6898) */

undefined8 _esp_finish_select(int param_1,undefined4 param_2)

{
  char cVar1;
  char cVar2;
  char cVar3;
  byte bVar4;
  word wVar5;
  undefined uVar6;
  int iVar7;
  uint uVar8;
  uint *puVar9;
  int iVar10;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar11;
  byte bVar12;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar13;
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
  iVar10 = *(int *)(param_1 + 0x9c);
  puVar9 = *(uint **)(param_1 + 0xa0);
  cVar1 = *(char *)(param_1 + 0x44);
  cVar2 = *(char *)(param_1 + 0x45);
  cVar3 = *(char *)(param_1 + 0x41);
  iVar11 = *(int *)(*(sword *)(param_1 + 0xb2) * 4 + param_1 + 0xb8);
  uVar8 = *puVar9;
  wVar5 = *(word *)(iVar11 + 8);
  if ((uVar8 & 2) != 0) {
    _esplog(param_1,3,aUnrecoverableD_1);
    *(undefined *)(iVar11 + 0x28) = 3;
    uVar13 = 8;
    goto locret_F00B6BAC;
  }
  bVar4 = *(byte *)(iVar10 + 0x1c);
  iVar7 = puVar9[1] - *(int *)(param_1 + 0xa4);
  if (uVar8 >> 0x1c == 8) {
    uVar8 = uVar8 >> 0xb & 3;
    if (uVar8 != 0) {
      iVar7 = iVar7 + -4 + uVar8;
    }
  }
  uVar8 = iVar7 - (bVar4 & 0x1f);
  *puVar9 = *puVar9 & 0xffffdcff | 0x20;
  if (0x10 < uVar8) {
    uVar8 = 0;
  }
  bVar12 = (byte)wVar5;
  if (cVar1 == ' ') {
    _esp_chip_disconnect(param_1);
    if (((cVar2 != '\0') && (((int)(uint)*(byte *)(param_1 + 0x7b) >> (bVar12 & 0x1f) & 1U) != 0))
       && ((cVar3 == '`' || (cVar3 == '@')))) {
      if (cVar3 == '`') {
        if (*(char *)(param_1 + 0x4c) == '\x01') {
          *(byte *)(param_1 + 0x78) = *(byte *)(param_1 + 0x78) | '\x01' << (bVar12 & 0x1f);
          wVar5 = *(word *)(iVar11 + 0x5c);
        }
        else {
          wVar5 = *(word *)(iVar11 + 0x5c);
        }
      }
      else {
        wVar5 = *(word *)(iVar11 + 0x5c);
      }
      if ((wVar5 & 0x100) == 0) {
        uVar13 = 5;
        *(undefined *)(param_1 + 0x42) = *(undefined *)(param_1 + 0x41);
        *(undefined *)(param_1 + 0x41) = 0;
        goto locret_F00B6BAC;
      }
    }
    *(undefined *)(iVar11 + 0x28) = 1;
    uVar13 = 3;
    *(byte *)(iVar11 + 0x29) = *(byte *)(iVar11 + 0x29) | 1;
    goto locret_F00B6BAC;
  }
  if (cVar1 == '\f') {
    uVar13 = 1;
    if ((_scsi_options & 0x40) == 0) {
loc_F00B69F8:
      uVar6 = *(undefined *)(param_1 + 0x41);
    }
    else {
      if ((*(uint *)(iVar11 + 0x14) & 8) != 0) {
        *(undefined *)(iVar10 + 0x20) = *(undefined *)(param_1 + 0x32);
        goto loc_F00B69F8;
      }
      uVar6 = *(undefined *)(param_1 + 0x41);
    }
    *(undefined *)(param_1 + 0x42) = uVar6;
    *(undefined *)(param_1 + 0x41) = 0;
    *(undefined2 *)(param_1 + 0xb0) = *(undefined2 *)(param_1 + 0xb2);
    *(undefined2 *)(param_1 + 0xb2) = 0xffff;
    *(int *)(param_1 + 0x8c) = *(int *)(param_1 + 0x8c) + 1;
    goto locret_F00B6BAC;
  }
  if (cVar1 != '\x18') {
    _esplog(param_1,3,aUndeterminedSe);
    _esp_stat_int_print(param_1);
    uVar13 = 8;
    goto locret_F00B6BAC;
  }
  *(byte *)(param_1 + 0x7b) = *(byte *)(param_1 + 0x7b) | (byte)(1 << (bVar12 & 0x1f));
  switch(cVar2) {
  case :
  case :
  case :
    uVar8 = 0;
    break;
  case :
  case :
  case :
    if ((*(char *)(param_1 + 0x31) != '\x04') && (*(char *)(param_1 + 0x31) != '\x01'))
    goto loc_F00B6AF0;
    _esp_step567 = _esp_step567 + 1;
  case :
  case :
    if (cVar3 == ' ') {
      uVar8 = uVar8 - 1;
    }
    break;
  :
loc_F00B6AF0:
    _esplog(param_1,3,aBadSequenceSte,cVar2);
    uVar13 = 8;
    goto locret_F00B6BAC;
  }
  *(undefined *)(iVar10 + 0xc) = 0;
  if ((bVar4 & 0x1f) == 0) {
loc_F00B6B48:
    bVar4 = *(byte *)(iVar11 + 0x29);
  }
  else {
    if (((*(byte *)(param_1 + 0x43) & 7) != 1) || (*(char *)(param_1 + (uint)wVar5 + 0x5e) == '\0'))
    {
      *(undefined *)(iVar10 + 0xc) = 1;
      goto loc_F00B6B48;
    }
    bVar4 = *(byte *)(iVar11 + 0x29);
  }
  *(byte *)(iVar11 + 0x29) = bVar4 | 3;
  if (0 < (int)uVar8) {
    *(byte *)(iVar11 + 0x29) = bVar4 | 7;
    *(uint *)(iVar11 + 0x2c) = *(int *)(iVar11 + 0x2c) + uVar8;
  }
  if (*(int *)(iVar11 + 0x34) == *(int *)(iVar11 + 0x38)) {
    uVar6 = *(undefined *)(param_1 + 0x41);
  }
  else {
    *(int *)(iVar11 + 0x34) = *(int *)(iVar11 + 0x38);
    *(word *)(iVar11 + 0x5c) = *(word *)(iVar11 + 0x5c) | 0x1000;
    uVar6 = *(undefined *)(param_1 + 0x41);
  }
  uVar13 = 2;
  *(undefined *)(param_1 + 0x42) = uVar6;
  *(undefined *)(param_1 + 0x41) = 0x1a;
locret_F00B6BAC:
  return CONCAT44(param_2,uVar13);
}

