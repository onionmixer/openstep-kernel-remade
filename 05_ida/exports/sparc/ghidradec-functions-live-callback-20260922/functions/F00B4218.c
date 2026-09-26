
/* WARNING: Removing unreachable block (ram,0xf00b4268) */

undefined8 _esp_commoncap(int *param_1,int param_2,uint param_3,uint param_4,int param_5)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  byte bVar4;
  undefined4 unaff_l0;
  undefined8 **ppuVar5;
  undefined4 unaff_l1;
  int iVar6;
  int iVar7;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar8;
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
  uVar8 = 0;
  iVar7 = *param_1;
  uVar2 = 1 << ((byte)*(undefined2 *)(param_1 + 1) & 0x1f);
  bVar4 = (byte)uVar2;
  bVar1 = ~bVar4;
  if ((1 < param_4) || (param_2 == 0)) goto locret_F00B44A4;
  iVar6 = 0;
  if (_scsi_capstrings != (undefined8 *)0x0) {
    ppuVar5 = &_scsi_capstrings;
    do {
      iVar3 = param_2;
      _strcmp(param_2,*ppuVar5);
      if (iVar3 == 0) break;
      ppuVar5 = ppuVar5 + 1;
      iVar6 = iVar6 + 1;
    } while (*ppuVar5 != (undefined8 *)0x0);
  }
  if ((&_scsi_capstrings)[iVar6] == (undefined8 *)0x0) {
def_F00B43C8:
    uVar8 = 0xffffffff;
    goto locret_F00B44A4;
  }
  if ((param_5 != 0) && (param_3 < 2)) {
    switch(iVar6) {
    case :
    case :
    case :
    case :
      goto locret_F00B44A4;
    case :
      if ((_scsi_options & 8) == 0) goto locret_F00B44A4;
      if (param_4 == 0) {
        if (param_3 == 0) {
          *(undefined *)(iVar7 + 0x79) = 0xff;
        }
        else {
          *(undefined *)(iVar7 + 0x79) = 0;
        }
      }
      else if (param_3 == 0) {
        *(byte *)(iVar7 + 0x79) = *(byte *)(iVar7 + 0x79) | bVar4;
      }
      else {
        *(byte *)(iVar7 + 0x79) = *(byte *)(iVar7 + 0x79) & bVar1;
      }
      break;
    case :
      if ((_scsi_options & 0x20) == 0) goto locret_F00B44A4;
      if (param_4 == 0) {
        if (param_3 == 0) {
          *(undefined *)(iVar7 + 0x7a) = 0xff;
        }
        else {
          *(undefined *)(iVar7 + 0x7a) = 0;
        }
        *(undefined *)(iVar7 + 0x78) = 0;
      }
      else {
        if (param_3 == 0) {
          bVar4 = *(byte *)(iVar7 + 0x7a) | bVar4;
        }
        else {
          bVar4 = *(byte *)(iVar7 + 0x7a) & bVar1;
        }
        *(byte *)(iVar7 + 0x7a) = bVar4;
        *(byte *)(iVar7 + 0x78) = *(byte *)(iVar7 + 0x78) & bVar1;
      }
      break;
    :
      goto def_F00B43C8;
    }
    goto loc_F00B448C;
  }
  if (param_5 != 0) goto locret_F00B44A4;
  switch(iVar6) {
  case :
    uVar2 = **(uint **)(iVar7 + 0xa0) >> 0x1c;
    if ((uVar2 < 10) || (uVar8 = 0x40000000, uVar2 != 10)) {
      uVar8 = 0x1000000;
    }
    break;
  case :
    goto loc_F00B448C;
  case :
    if ((_scsi_options & 8) != 0) {
      if (param_4 == 0) {
        uVar8 = 1;
      }
      else if ((*(byte *)(iVar7 + 0x79) & uVar2) == 0) {
        uVar8 = 1;
      }
    }
    break;
  case :
    if ((_scsi_options & 0x20) == 0) break;
    if (param_4 == 0) {
      uVar8 = 1;
      break;
    }
    uVar2 = (uint)*(byte *)(iVar7 + (uint)*(word *)(param_1 + 1) + 0x5e);
    goto loc_F00B4484;
  :
    goto def_F00B43C8;
  case :
    uVar2 = _scsi_options & 0x40;
loc_F00B4484:
    if (uVar2 != 0) {
loc_F00B448C:
      uVar8 = 1;
    }
    break;
  case :
    uVar8 = *(byte *)(iVar7 + 0x32) & 7;
  }
locret_F00B44A4:
  return CONCAT44(param_2,uVar8);
}

