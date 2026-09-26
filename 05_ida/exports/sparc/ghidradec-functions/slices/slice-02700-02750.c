/* GHIDRADEC_FUNCTION index=2700 start=0xf00b4218 */

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
/* GHIDRADEC_FUNCTION index=2701 start=0xf00b44ac */

/* WARNING: Removing unreachable block (ram,0xf00b44c0) */

undefined8 _esp_getcap(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 unaff_l0;
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
  _esp_commoncap(param_1,param_2,0,param_3,0);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2702 start=0xf00b44d0 */

/* WARNING: Removing unreachable block (ram,0xf00b44e4) */

undefined8 _esp_setcap(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 unaff_l0;
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
  _esp_commoncap(param_1,param_2,param_3,param_4,1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2703 start=0xf00b44f4 */

/* WARNING: Removing unreachable block (ram,0xf00b4618) */

undefined8 _esp_ustart(int param_1,uint param_2)

{
  byte bVar1;
  sword sVar2;
  sword sVar3;
  int iVar4;
  int iVar5;
  undefined4 unaff_l0;
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
  sVar3 = 0;
  if ((sword)param_2 == -1) {
    param_2 = 0;
  }
  if (*(uint *)(param_1 + 0x88) < *(uint *)(param_1 + 0x84)) {
    sVar2 = (sword)param_2;
    do {
      iVar4 = *(int *)(((int)(param_2 << 0x10) >> 0xe) + param_1 + 0xb8);
      if ((iVar4 == 0) || ((*(word *)(iVar4 + 0x5c) & 0x10) != 0)) {
        param_2 = param_2 + 1 & 0x3f;
      }
      else {
        sVar3 = sVar3 + 1;
      }
    } while ((sVar3 == 0) && ((sword)param_2 != sVar2));
    if (sVar3 != 0) {
      *(sword *)(param_1 + 0xb2) = (sword)param_2;
      bVar1 = *(byte *)(iVar4 + 0x2b);
      if (-1 < (char)bVar1) {
        iVar5 = (char)bVar1 * 4;
        *(int *)(_dk_xfer + iVar5) = *(int *)(_dk_xfer + iVar5) + 1;
        _dk_busy = _dk_busy | 1 << (bVar1 & 0x1f);
        if ((*(word *)(iVar4 + 0x5c) & 2) == 0) {
          *(int *)(_dk_read + iVar5) = *(int *)(_dk_read + iVar5) + 1;
        }
        *(uint *)(_dk_wds + iVar5) = *(int *)(_dk_wds + iVar5) + (*(uint *)(iVar4 + 0x40) >> 6);
      }
      _esp_startcmd(param_1);
      goto locret_F00B4624;
    }
  }
  param_1 = 0;
locret_F00B4624:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2704 start=0xf00b462c */

/* WARNING: Removing unreachable block (ram,0xf00b4970) */
/* WARNING: Removing unreachable block (ram,0xf00b47a4) */

undefined8 _esp_startcmd(int param_1,undefined4 param_2)

{
  char cVar1;
  byte bVar2;
  undefined uVar3;
  undefined uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  byte bVar9;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  byte *pbVar10;
  undefined *puVar11;
  undefined4 unaff_l3;
  uint *puVar12;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar13;
  undefined4 uVar14;
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
  pbVar10 = *(byte **)(param_1 + 0x48);
  puVar11 = *(undefined **)(param_1 + 0x9c);
  puVar12 = *(uint **)(param_1 + 0xa0);
  iVar13 = *(int *)(*(sword *)(param_1 + 0xb2) * 4 + param_1 + 0xb8);
  if ((*puVar12 & 3) == 0) {
    *(undefined *)(param_1 + 0x53) = 0;
    *(undefined *)(param_1 + 0x46) = 0;
    bVar2 = *(byte *)(iVar13 + 9);
    uVar8 = (uint)*(byte *)(iVar13 + 99);
    uVar5 = 1 << (bVar2 & 0x1f);
    if (uVar8 != 10) {
      iVar7 = uVar8 - 0xc;
      if (uVar8 < 0xb) {
        iVar7 = uVar8 - 6;
      }
      if (iVar7 != 0) {
        uVar8 = 0;
      }
    }
    bVar9 = 0x41;
    if ((*(byte *)(param_1 + 0x7b) & uVar5) == 0) {
loc_F00B46D8:
      bVar9 = 0x41;
      uVar4 = 0x80;
    }
    else {
      uVar4 = 0x80;
      if (((*(byte *)(param_1 + 0x79) & uVar5) == 0) && ((*(uint *)(iVar13 + 0x14) & 2) == 0)) {
        if ((_scsi_options & 8) == 0) goto loc_F00B46D8;
        *pbVar10 = *(byte *)(iVar13 + 10) | 0xc0;
        pbVar10 = pbVar10 + 1;
        if ((*(word *)(iVar13 + 0x5c) & 0x100) == 0) {
          if (((*(byte *)(param_1 + 0x78) & uVar5) == 0) && ((_scsi_options & 0x20) != 0)) {
            if ((*(byte *)(param_1 + 0x7a) & uVar5) == 0) {
              uVar4 = *(undefined *)(param_1 + 0x76);
              uVar14 = 0xf;
            }
            else {
              uVar4 = 0;
              uVar14 = 0;
            }
            _esp_make_sdtr(param_1,uVar4,uVar14);
            uVar8 = 0;
            bVar9 = 0x43;
            uVar4 = 0x60;
            *(byte *)(param_1 + 0x78) = *(byte *)(param_1 + 0x78) | (byte)(1 << (bVar2 & 0x1f));
          }
          else {
            bVar9 = 0x42;
            if (uVar8 == 0) {
              bVar9 = 0x43;
              uVar4 = 0x40;
            }
            else {
              uVar4 = 0x20;
            }
          }
        }
        else {
          cVar1 = *(char *)(iVar13 + 0x6c);
          iVar6 = 0;
          *(char *)(param_1 + 0x53) = cVar1;
          iVar7 = iVar13;
          if (cVar1 != '\0') {
            do {
              *(undefined *)(param_1 + iVar6 + 0x4c) = *(undefined *)(iVar7 + 0x6d);
              iVar6 = iVar6 + 1;
              iVar7 = iVar13 + iVar6;
            } while (iVar6 < (int)(uint)*(byte *)(param_1 + 0x53));
          }
          *(undefined *)(iVar13 + 0x6b) = 0;
          bVar9 = 0x43;
          uVar4 = 0x60;
          uVar8 = 0;
        }
      }
    }
    iVar7 = 0;
    if (uVar8 == 0) {
      iVar7 = *(int *)(param_1 + 0x48);
    }
    else {
      do {
        *pbVar10 = *(byte *)(*(int *)(iVar13 + 0x2c) + iVar7);
        iVar7 = iVar7 + 1;
        pbVar10 = pbVar10 + 1;
      } while (iVar7 < (int)uVar8);
      iVar7 = *(int *)(param_1 + 0x48);
    }
    iVar6 = (uint)bVar2 + param_1;
    *(int *)(param_1 + 0xa8) = (int)pbVar10 - iVar7;
    puVar11[0x10] = bVar2;
    puVar11[0x18] = *(byte *)(iVar6 + 0x66) & 0x1f;
    puVar11[0x1c] = *(byte *)(iVar6 + 0x5e) | *(byte *)(param_1 + 0x77);
    if ((byte)(*(char *)(param_1 + 0x31) - 3U) < 2) {
      puVar11[0x30] = *(undefined *)(iVar6 + 0x34);
    }
    if ((_scsi_options & 0x40) == 0) {
      bVar2 = *(byte *)(param_1 + 0x33);
    }
    else if ((*(uint *)(iVar13 + 0x14) & 8) == 0) {
      bVar2 = *(byte *)(param_1 + 0x33);
    }
    else {
      puVar11[0x20] = *(byte *)(param_1 + 0x32) & 0xef;
      bVar2 = *(byte *)(param_1 + 0x33);
    }
    uVar3 = (undefined)*(undefined4 *)(param_1 + 0xa8);
    if ((bVar2 & 0x40) == 0) {
      *puVar11 = uVar3;
      puVar11[4] = (char)((uint)*(undefined4 *)(param_1 + 0xa8) >> 8);
    }
    else {
      *puVar11 = uVar3;
      puVar11[4] = (char)((uint)*(undefined4 *)(param_1 + 0xa8) >> 8);
      puVar11[0x38] = (char)*(undefined2 *)(param_1 + 0xa8);
    }
    if (*puVar12 >> 0x1c == 4) {
      puVar12[2] = *(uint *)(param_1 + 0xa8);
    }
    uVar5 = *(int *)(param_1 + 0x48) + 0x100000U | *(uint *)(param_1 + 0xac);
    *(uint *)(param_1 + 0xa4) = uVar5;
    uVar8 = *puVar12;
    puVar12[1] = uVar5;
    if (uVar8 >> 0x1c == 4) {
      uVar5 = uVar8 | 0x210 | uVar8 & 0xfffffeff;
    }
    else {
      uVar5 = uVar8 & 0xfffffeff | 0x210;
    }
    *puVar12 = uVar5;
    if ((*puVar12 & 3) == 0) {
      puVar11[0xc] = bVar9 | 0x80;
      uVar14 = 1;
      *(undefined *)(param_1 + 0x42) = *(undefined *)(param_1 + 0x41);
      *(undefined *)(param_1 + 0x41) = uVar4;
      goto locret_F00B497C;
    }
    uVar4 = *(undefined *)(param_1 + 0x41);
  }
  else {
    uVar4 = *(undefined *)(param_1 + 0x41);
  }
  *(undefined *)(param_1 + 0x42) = uVar4;
  *(undefined *)(param_1 + 0x41) = 0;
  *(undefined2 *)(param_1 + 0xb0) = *(undefined2 *)(param_1 + 0xb2);
  *(undefined2 *)(param_1 + 0xb2) = 0xffff;
  *(int *)(param_1 + 0x8c) = *(int *)(param_1 + 0x8c) + 1;
  _esp_poll();
  uVar14 = 0;
locret_F00B497C:
  return CONCAT44(param_2,uVar14);
}
/* GHIDRADEC_FUNCTION index=2705 start=0xf00b4984 */

/* WARNING: Removing unreachable block (ram,0xf00b49e8) */

undefined8 _esp_link_start(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar1;
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
  *(int *)(param_1 + 0x94) = *(int *)(param_1 + 0x94) + 1;
  if ((*(byte *)(param_1 + 0x43) & 7) != 2) {
    *(byte *)(param_1 + 0x43) = *(byte *)(*(int *)(param_1 + 0x9c) + 0x10) & 0x7f;
  }
  if ((*(byte *)(param_1 + 0x43) & 7) == 2) {
    uVar1 = 2;
    *(undefined *)(param_1 + 0x42) = *(undefined *)(param_1 + 0x41);
    *(undefined *)(param_1 + 0x41) = 1;
  }
  else {
    _esp_printstate(param_1,aLinkedCommandN_0);
    uVar1 = 6;
  }
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=2706 start=0xf00b49fc */

/* WARNING: Removing unreachable block (ram,0xf00b4ba8) */
/* WARNING: Removing unreachable block (ram,0xf00b4bb8) */
/* WARNING: Removing unreachable block (ram,0xf00b4af0) */

undefined8 _esp_finish(int param_1,undefined4 param_2)

{
  int *piVar1;
  char cVar2;
  byte bVar3;
  word wVar4;
  undefined uVar5;
  int iVar6;
  undefined4 unaff_l0;
  int iVar7;
  undefined4 unaff_l1;
  int iVar8;
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
  iVar7 = *(int *)(*(sword *)(param_1 + 0xb2) * 4 + param_1 + 0xb8);
  if (-1 < (char)*(byte *)(iVar7 + 0x2b)) {
    _dk_busy = _dk_busy & ~(1 << (*(byte *)(iVar7 + 0x2b) & 0x1f));
  }
  wVar4 = *(word *)(param_1 + 0xb2);
  *(word *)(param_1 + 0xb0) = wVar4;
  *(undefined2 *)(param_1 + 0xb2) = 0xffff;
  *(int *)(param_1 + 0x84) = *(int *)(param_1 + 0x84) + -1;
  cVar2 = *(char *)(param_1 + 0x54);
  bVar3 = *(byte *)(iVar7 + 0x29);
  if ((bVar3 & 0x10) != 0) {
    if ((**(byte **)(iVar7 + 0x1c) & 2) == 0) {
      bVar3 = *(byte *)(iVar7 + 0x29);
    }
    else {
      if (*(char *)(param_1 + (uint)*(word *)(iVar7 + 8) + 0x5e) != '\0') {
        *(byte *)(param_1 + 0x78) =
             *(byte *)(param_1 + 0x78) & ~(byte)(1 << ((byte)*(word *)(iVar7 + 8) & 0x1f));
      }
      bVar3 = *(byte *)(iVar7 + 0x29);
    }
  }
  if ((bVar3 & 8) == 0) {
    uVar5 = *(undefined *)(param_1 + 0x41);
  }
  else {
    if ((*(int *)(iVar7 + 0x50) != 0) && (*(int *)(*(int *)(iVar7 + 0x50) + 4) != 0)) {
      _panic(aEspFinishMoreT);
    }
    iVar8 = iVar7 + 0x48;
    iVar6 = 0;
    if (iVar7 != -0x48) {
      do {
        piVar1 = (int *)(iVar8 + 4);
        iVar8 = *(int *)(iVar8 + 8);
        iVar6 = iVar6 + *piVar1;
      } while (iVar8 != 0);
    }
    *(int *)(iVar7 + 0x24) = *(int *)(iVar7 + 0x40) - iVar6;
    uVar5 = *(undefined *)(param_1 + 0x41);
  }
  *(undefined *)(param_1 + 0x42) = uVar5;
  *(undefined *)(param_1 + 0x41) = 0;
  iVar8 = ((int)((uint)wVar4 << 0x10) >> 0xe) + param_1;
  *(undefined4 *)(iVar8 + 0xb8) = 0;
  if ((*(uint *)(iVar7 + 0x14) & 1) == 0) {
    if ((byte)(cVar2 - 10U) < 2) {
      *(undefined *)(param_1 + 0x41) = 0x1e;
      (**(code **)(iVar7 + 0x10))(iVar7);
      *(undefined *)(param_1 + 0x41) = 0;
      if (*(int *)(iVar8 + 0xb8) == 0) {
        _esplog(param_1,3,aLinkedCommandN);
        param_1 = 8;
      }
      else {
        *(word *)(param_1 + 0xb2) = wVar4;
        _esp_link_start(param_1);
      }
    }
    else {
      (**(code **)(iVar7 + 0x10))(iVar7);
      param_1 = 5;
    }
  }
  else {
    *(int *)(param_1 + 0x80) = *(int *)(param_1 + 0x80) + -1;
    (**(code **)(iVar7 + 0x10))(iVar7);
    param_1 = -1;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2707 start=0xf00b4bdc */

/* WARNING: Removing unreachable block (ram,0xf00b4c14) */
/* WARNING: Removing unreachable block (ram,0xf00b4c58) */
/* WARNING: Removing unreachable block (ram,0xf00b4c00) */

undefined8 _esp_dopoll(uint param_1,int param_2)

{
  byte bVar1;
  uint uVar2;
  undefined4 unaff_l0;
  int iVar3;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar4;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar5;
  bool bVar6;
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
  iVar3 = 0;
  uVar2 = param_1;
  if (param_2 == 0) {
    uVar2 = 0xaba9400;
    param_2 = 180000000;
  }
  bVar6 = SBORROW4(0,param_2);
  bVar5 = -param_2 < 0;
  if (0 < param_2) {
    do {
      _esp_poll();
      if (uVar2 == 0) {
        _us_spin(100);
        bVar1 = *(byte *)(param_1 + 0x41);
      }
      else {
        bVar1 = *(byte *)(param_1 + 0x41);
      }
      uVar2 = (uint)bVar1;
      bVar6 = SBORROW4(iVar3,param_2);
      bVar5 = iVar3 - param_2 < 0;
      if (uVar2 == 0) break;
      iVar3 = iVar3 + 100;
      bVar6 = SBORROW4(iVar3,param_2);
      bVar5 = iVar3 - param_2 < 0;
    } while (iVar3 < param_2);
  }
  if (bVar5 == bVar6) {
    if (*(char *)(param_1 + 0x41) == '\0') {
      uVar4 = 0;
    }
    else {
      _esp_printstate(param_1,aPolledCommandT);
      uVar4 = 0xffffffff;
    }
  }
  else {
    uVar4 = 0;
  }
  return CONCAT44(param_2,uVar4);
}
/* GHIDRADEC_FUNCTION index=2708 start=0xf00b4c74 */

/* WARNING: Removing unreachable block (ram,0xf00b4d04) */
/* WARNING: Removing unreachable block (ram,0xf00b4d1c) */
/* WARNING: Removing unreachable block (ram,0xf00b4cb4) */

undefined8 _esp_poll(undefined4 param_1,undefined4 param_2)

{
  bool bVar1;
  int iVar2;
  uint *puVar3;
  undefined4 unaff_l0;
  int *piVar4;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar5;
  uint uVar6;
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
  uVar5 = 0;
  uVar6 = uVar5;
  if (_esp_softc != (int *)0x0) {
    do {
      bVar1 = false;
      if (_esp_softc != (int *)0x0) {
        iVar2 = _esp_softc[1];
        piVar4 = _esp_softc;
        do {
          if (iVar2 == 0) {
            piVar4 = (int *)piVar4[10];
          }
          else {
            iVar2 = *piVar4;
            _splr();
            if (*piVar4 < iVar2) {
              puVar3 = (uint *)piVar4[0x28];
loc_F00B4CF4:
              if ((*puVar3 & 3) != 0) {
                _espsvc(piVar4);
                bVar1 = true;
                uVar6 = uVar6 | 1 << (*(byte *)(piVar4 + 0xc) & 0x1f);
              }
            }
            else {
              if (piVar4[0x20] != 0) {
                puVar3 = (uint *)piVar4[0x28];
                goto loc_F00B4CF4;
              }
              if (iVar2 == piVar4[0x2d]) {
                puVar3 = (uint *)piVar4[0x28];
                goto loc_F00B4CF4;
              }
            }
            _splx(iVar2);
            piVar4 = (int *)piVar4[10];
          }
          if (piVar4 == (int *)0x0) break;
          iVar2 = piVar4[1];
        } while( true );
      }
    } while (bVar1);
    uVar5 = 0;
    if (uVar6 != 0) {
      if ((uVar6 & uVar6 - 1) != 0) {
        _esp_nmultsvc = _esp_nmultsvc + 1;
      }
      uVar5 = 1;
      _esp_nhardints = _esp_nhardints + 1;
    }
  }
  return CONCAT44(param_2,uVar5);
}
/* GHIDRADEC_FUNCTION index=2709 start=0xf00b4d80 */

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
/* GHIDRADEC_FUNCTION index=2710 start=0xf00b4fe8 */

/* WARNING: Removing unreachable block (ram,0xf00b5088) */
/* WARNING: Removing unreachable block (ram,0xf00b50b0) */

undefined8 _esp_phasemanage(int param_1,undefined4 param_2)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  undefined4 unaff_l0;
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
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  undefined4 auStack_3c [15];
  
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
  *(code **)((int)register0x00000038 + -0x38) = _esp_handle_cmd_start;
  *(code **)((int)register0x00000038 + -0x34) = _esp_handle_cmd_done;
  *(code **)((int)register0x00000038 + -0x30) = _esp_handle_msg_out;
  *(code **)((int)register0x00000038 + -0x2c) = _esp_handle_msg_out_done;
  *(code **)((int)register0x00000038 + -0x28) = _esp_handle_msg_in;
  *(code **)((int)register0x00000038 + -0x24) = _esp_handle_more_msgin;
  *(code **)((int)register0x00000038 + -0x20) = _esp_handle_msg_in_done;
  *(code **)((int)register0x00000038 + -0x1c) = _esp_handle_clearing;
  *(code **)((int)register0x00000038 + -0x18) = _esp_handle_data;
  *(code **)((int)register0x00000038 + -0x14) = _esp_handle_data_done;
  *(code **)((int)register0x00000038 + -0x10) = _esp_handle_c_cmplt;
  bVar1 = *(byte *)(param_1 + 0x41);
  while( true ) {
    uVar2 = (uint)bVar1;
    iVar3 = param_1;
    if (uVar2 == 0x1a) {
      _esp_handle_unknown();
    }
    else if ((uVar2 == 0) || (0xb < uVar2)) {
      _esplog(param_1,3,aLostStateInPha);
      iVar3 = 7;
    }
    else {
      (**(code **)((int)register0x00000038 + uVar2 * 4 + -0x3c))();
    }
    if (iVar3 != 2) break;
    bVar1 = *(byte *)(param_1 + 0x41);
  }
  return CONCAT44(param_2,iVar3);
}
/* GHIDRADEC_FUNCTION index=2711 start=0xf00b50e4 */

/* WARNING: Removing unreachable block (ram,0xf00b51b8) */
/* WARNING: Removing unreachable block (ram,0xf00b50fc) */

undefined8 _esp_handle_unknown(int param_1,undefined4 param_2)

{
  undefined uVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar2;
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
  if ((*(byte *)(param_1 + 0x44) & 0x20) != 0) {
    _esp_chip_disconnect(param_1);
    uVar2 = 3;
    *(undefined *)(*(int *)(*(sword *)(param_1 + 0xb2) * 4 + param_1 + 0xb8) + 0x28) = 0x14;
    goto locret_F00B51D0;
  }
  switch(*(byte *)(param_1 + 0x43) & 7) {
  case :
  case :
    uVar1 = 9;
    break;
  case :
    uVar1 = 1;
    break;
  case :
    uVar2 = 0xffffffff;
    *(undefined *)(*(int *)(param_1 + 0x9c) + 0xc) = 1;
    *(undefined *)(*(int *)(param_1 + 0x9c) + 0xc) = 0x11;
    *(undefined *)(param_1 + 0x41) = 0xb;
    goto locret_F00B51D0;
  :
    _esp_printstate(param_1,aUnknownBusPhas);
    uVar2 = 8;
    goto locret_F00B51D0;
  case :
    uVar1 = 3;
    break;
  case :
    uVar1 = 5;
  }
  *(undefined *)(param_1 + 0x41) = uVar1;
  uVar2 = 2;
locret_F00B51D0:
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=2712 start=0xf00b51d8 */

undefined8 _esp_handle_cmd_start(int param_1)

{
  byte bVar1;
  undefined *puVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar3;
  undefined4 unaff_i1;
  undefined *puVar4;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  int iVar5;
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
  iVar5 = *(int *)(*(sword *)(param_1 + 0xb2) * 4 + param_1 + 0xb8);
  puVar4 = *(undefined **)(param_1 + 0x9c);
  if ((uint)*(byte *)(iVar5 + 99) < (uint)(*(int *)(iVar5 + 0x2c) - *(int *)(iVar5 + 0x20))) {
    *(undefined *)(iVar5 + 0x28) = 8;
    uVar3 = 6;
  }
  else {
    puVar4[0xc] = 1;
    bVar1 = *(byte *)(param_1 + 0x33);
    *puVar4 = 1;
    if ((bVar1 & 0x40) == 0) {
      puVar4[4] = 0;
    }
    else {
      puVar4[4] = 0;
      puVar4[0x38] = 0;
    }
    puVar2 = *(undefined **)(iVar5 + 0x2c);
    *(undefined **)(iVar5 + 0x2c) = puVar2 + 1;
    puVar4[8] = *puVar2;
    puVar4[0xc] = 0x10;
    uVar3 = 0xffffffff;
    *(undefined *)(param_1 + 0x42) = *(undefined *)(param_1 + 0x41);
    *(undefined *)(param_1 + 0x41) = 2;
  }
  return CONCAT44(puVar4,uVar3);
}
/* GHIDRADEC_FUNCTION index=2713 start=0xf00b527c */

/* WARNING: Removing unreachable block (ram,0xf00b52bc) */

undefined8 _esp_handle_cmd_done(int param_1,undefined4 param_2)

{
  byte bVar1;
  undefined uVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar4;
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
  bVar1 = *(byte *)(param_1 + 0x44);
  iVar3 = *(int *)(*(sword *)(param_1 + 0xb2) * 4 + param_1 + 0xb8);
  *(undefined *)(*(int *)(param_1 + 0x9c) + 0xc) = 0;
  if ((bVar1 & 0x10) == 0) {
    if ((bVar1 & 0x20) == 0) {
      _esp_printstate(param_1,aCmdTransmissio);
      uVar4 = 6;
      goto locret_F00B52EC;
    }
    uVar2 = *(undefined *)(param_1 + 0x41);
  }
  else {
    *(byte *)(iVar3 + 0x29) = *(byte *)(iVar3 + 0x29) | 4;
    uVar2 = *(undefined *)(param_1 + 0x41);
  }
  uVar4 = 2;
  *(undefined *)(param_1 + 0x42) = uVar2;
  *(undefined *)(param_1 + 0x41) = 0x1a;
locret_F00B52EC:
  return CONCAT44(param_2,uVar4);
}
/* GHIDRADEC_FUNCTION index=2714 start=0xf00b52f4 */

/* WARNING: Removing unreachable block (ram,0xf00b5340) */

undefined8 _esp_handle_msg_out(int param_1,undefined4 param_2)

{
  undefined uVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar5;
  undefined4 uVar6;
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
  iVar4 = *(int *)(param_1 + 0x9c);
  iVar5 = *(int *)(*(sword *)(param_1 + 0xb2) * 4 + param_1 + 0xb8);
  if (((*(byte *)(param_1 + 0x43) & 7) == 6) || (*(char *)(param_1 + 0x42) != '\x04')) {
    *(undefined *)(iVar4 + 0xc) = 1;
    cVar2 = *(char *)(param_1 + 0x53);
    if (cVar2 == '\0') {
      *(undefined *)(param_1 + 0x4c) = 8;
      *(undefined *)(param_1 + 0x53) = 1;
      cVar2 = *(char *)(param_1 + 0x53);
    }
    iVar3 = 0;
    iVar5 = param_1;
    if (cVar2 != '\0') {
      do {
        *(undefined *)(iVar4 + 8) = *(undefined *)(iVar5 + 0x4c);
        iVar3 = iVar3 + 1;
        iVar5 = param_1 + iVar3;
      } while (iVar3 < (int)(uint)*(byte *)(param_1 + 0x53));
    }
    *(undefined *)(iVar4 + 0xc) = 0x10;
    uVar6 = 0xffffffff;
    *(undefined *)(param_1 + 0x42) = *(undefined *)(param_1 + 0x41);
    uVar1 = 4;
  }
  else {
    _esplog(param_1,4,aTargetDRefused,*(undefined2 *)(iVar5 + 8));
    *(undefined *)(iVar5 + 0x28) = 0xb;
    uVar6 = 2;
    *(undefined *)(param_1 + 0x42) = *(undefined *)(param_1 + 0x41);
    uVar1 = 0x1a;
  }
  *(undefined *)(param_1 + 0x41) = uVar1;
  return CONCAT44(param_2,uVar6);
}
/* GHIDRADEC_FUNCTION index=2715 start=0xf00b53e0 */

/* WARNING: Removing unreachable block (ram,0xf00b5428) */
/* WARNING: Removing unreachable block (ram,0xf00b54f0) */

undefined8 _esp_handle_msg_out_done(int param_1,undefined4 param_2)

{
  char cVar1;
  word wVar2;
  byte bVar3;
  undefined uVar4;
  int iVar5;
  byte bVar6;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar7;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar8;
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
  iVar5 = *(int *)(param_1 + 0x9c);
  cVar1 = *(char *)(param_1 + 0x4c);
  iVar7 = *(int *)(*(sword *)(param_1 + 0xb2) * 4 + param_1 + 0xb8);
  wVar2 = *(word *)(iVar7 + 8);
  if (*(char *)(param_1 + 0x44) == ' ') {
    if ((cVar1 == '\f') || (cVar1 == '\x06')) {
      _esp_chip_disconnect(param_1);
      if (cVar1 == '\f') {
        *(undefined *)(param_1 + (uint)wVar2 + 0x5e) = 0;
        *(byte *)(param_1 + 0x78) = *(byte *)(param_1 + 0x78) & ~(byte)(1 << ((byte)wVar2 & 0x1f));
        wVar2 = *(word *)(iVar7 + 0x5c);
      }
      else {
        wVar2 = *(word *)(iVar7 + 0x5c);
      }
      *(undefined *)(iVar7 + 0x28) = 0;
      if ((wVar2 & 0x100) != 0) {
        *(undefined *)(iVar7 + 0x6b) = 1;
      }
      uVar8 = 3;
      goto locret_F00B556C;
    }
    *(char *)(param_1 + 0x52) = cVar1;
loc_F00B5554:
    *(undefined *)(param_1 + 0x53) = 0;
    *(undefined *)(param_1 + 0x42) = *(undefined *)(param_1 + 0x41);
    uVar4 = 0x1a;
  }
  else {
    bVar6 = *(byte *)(param_1 + 0x43) & 7;
    *(undefined *)(iVar5 + 0xc) = 0;
    if ((*(byte *)(iVar5 + 0x1c) & 0x1f) == 0) {
loc_F00B54B8:
      bVar3 = *(byte *)(param_1 + 0x44);
    }
    else {
      if ((bVar6 != 1) || (*(char *)(param_1 + (uint)wVar2 + 0x5e) == '\0')) {
        *(undefined *)(iVar5 + 0xc) = 1;
        goto loc_F00B54B8;
      }
      bVar3 = *(byte *)(param_1 + 0x44);
    }
    if ((bVar3 & 0x10) == 0) {
      bVar3 = *(byte *)(param_1 + 0x53);
loc_F00B551C:
      if (bVar3 == 5) {
        if (cVar1 == '\x01') {
          if (*(char *)(param_1 + 0x4e) == '\x01') {
            *(char *)(param_1 + 0x46) = *(char *)(param_1 + 0x46) + '\x01';
            *(undefined *)(param_1 + 0x52) = 1;
          }
          else {
            *(undefined *)(param_1 + 0x52) = 1;
          }
        }
        else {
          *(char *)(param_1 + 0x52) = cVar1;
        }
      }
      else {
        *(char *)(param_1 + 0x52) = cVar1;
      }
      goto loc_F00B5554;
    }
    bVar3 = *(byte *)(param_1 + 0x53);
    if (bVar6 != 6) goto loc_F00B551C;
    if (1 < bVar3) {
      *(undefined *)(iVar5 + 0xc) = 0x1a;
    }
    _esplog(param_1,3,aScsiBusMessage);
    *(byte *)(iVar7 + 0x2a) = *(byte *)(iVar7 + 0x2a) | 4;
    *(undefined *)(param_1 + 0x42) = *(undefined *)(param_1 + 0x41);
    uVar4 = 3;
  }
  uVar8 = 2;
  *(undefined *)(param_1 + 0x41) = uVar4;
locret_F00B556C:
  return CONCAT44(param_2,uVar8);
}
/* GHIDRADEC_FUNCTION index=2716 start=0xf00b5574 */

/* WARNING: Removing unreachable block (ram,0xf00b55b4) */
/* WARNING: Removing unreachable block (ram,0xf00b55cc) */
/* WARNING: Removing unreachable block (ram,0xf00b55f8) */

undefined8 _esp_handle_clearing(int param_1,undefined4 param_2)

{
  undefined2 uVar1;
  undefined4 unaff_l0;
  uint uVar2;
  undefined4 unaff_l1;
  int iVar3;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar4;
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
  iVar3 = *(int *)(*(sword *)(param_1 + 0xb2) * 4 + param_1 + 0xb8);
  uVar2 = (uint)*(byte *)(param_1 + 0x54);
  if (*(char *)(param_1 + 0x44) == ' ') {
    _esp_chip_disconnect(param_1);
    uVar4 = 3;
    if (uVar2 == 4) {
      *(byte *)(iVar3 + 0x2a) = *(byte *)(iVar3 + 0x2a) | 1;
      *(word *)(iVar3 + 0x5c) = *(word *)(iVar3 + 0x5c) | 0x10;
      uVar4 = 5;
      *(int *)(param_1 + 0x90) = *(int *)(param_1 + 0x90) + 1;
      *(int *)(param_1 + 0x88) = *(int *)(param_1 + 0x88) + 1;
      *(undefined *)(param_1 + 0x42) = *(undefined *)(param_1 + 0x41);
      *(undefined *)(param_1 + 0x41) = 0;
      *(undefined2 *)(param_1 + 0xb0) = *(undefined2 *)(param_1 + 0xb2);
      *(undefined2 *)(param_1 + 0xb2) = 0xffff;
    }
    *(undefined *)(param_1 + 0x52) = 0xff;
    *(undefined *)(param_1 + 0x53) = 0;
  }
  else if ((uVar2 - 10 & 0xff) < 2) {
    *(undefined *)(param_1 + 0x52) = 0xff;
    *(undefined *)(param_1 + 0x53) = 0;
    uVar4 = 3;
  }
  else {
    uVar1 = *(undefined2 *)(iVar3 + 8);
    _scsi_mname(uVar2);
    _esplog(param_1,4,aTargetDDidnTDi,uVar1,uVar2);
    *(undefined *)(iVar3 + 0x28) = 3;
    uVar4 = 6;
  }
  return CONCAT44(param_2,uVar4);
}
/* GHIDRADEC_FUNCTION index=2717 start=0xf00b5674 */

/* WARNING: Removing unreachable block (ram,0xf00b5850) */
/* WARNING: Removing unreachable block (ram,0xf00b5748) */
/* WARNING: Removing unreachable block (ram,0xf00b572c) */
/* WARNING: Removing unreachable block (ram,0xf00b575c) */
/* WARNING: Removing unreachable block (ram,0xf00b56bc) */
/* WARNING: Removing unreachable block (ram,0xf00b5720) */

undefined8 _esp_handle_data(int param_1,undefined4 param_2)

{
  word wVar1;
  undefined2 uVar2;
  undefined uVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint *puVar7;
  undefined *puVar8;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar9;
  undefined4 uVar10;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar11;
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
  puVar8 = *(undefined **)(param_1 + 0x9c);
  puVar7 = *(uint **)(param_1 + 0xa0);
  uVar9 = *(uint *)(*(sword *)(param_1 + 0xb2) * 4 + param_1 + 0xb8);
  if (*(char *)(param_1 + 0x31) == '\0') {
    puVar8[0xc] = 0;
  }
  wVar1 = *(word *)(uVar9 + 0x5c);
  if ((wVar1 & 1) == 0) {
    _esp_printstate(param_1,aUnexpectedData);
    uVar3 = 3;
loc_F00B585C:
    *(undefined *)(uVar9 + 0x28) = uVar3;
    uVar10 = 6;
  }
  else {
    if ((wVar1 & 0x1000) != 0) {
      puVar6 = *(uint **)(uVar9 + 0x54);
      uVar5 = *(uint *)(uVar9 + 0x34);
      uVar4 = *puVar6;
      if ((uVar5 < uVar4) || (uVar4 + puVar6[1] <= uVar5)) {
        _panic(aNeedNewSegInEs);
      }
      else {
        puVar6[1] = uVar5 - uVar4;
        *(word *)(uVar9 + 0x5c) = *(word *)(uVar9 + 0x5c) ^ 0x1000;
      }
    }
    uVar4 = uVar9;
    _scsi_chkdma(uVar9,0x10000);
    if (uVar4 == 0) {
      _esp_printstate(param_1,aDataTransferOv);
      *(undefined *)(uVar9 + 0x28) = 7;
      _esp_sync_backoff(param_1,uVar9);
      uVar10 = 6;
      goto locret_F00B589C;
    }
    *(uint *)(param_1 + 0xa8) = uVar4;
    if ((*(word *)(uVar9 + 0x5c) & 4) == 0) {
      uVar5 = *(uint *)(uVar9 + 0x34);
      if (uVar5 >> 0xc < 0x600) {
        uVar5 = uVar5 | 0xff000000;
      }
      *(uint *)(param_1 + 0xa4) = uVar5;
      puVar7[1] = uVar5;
    }
    else {
      uVar5 = *(uint *)(uVar9 + 0x34);
      if (uVar5 >> 0xc < _dvmasize) {
        uVar5 = uVar5 | *(uint *)(param_1 + 0xac);
        *(uint *)(param_1 + 0xa4) = uVar5;
      }
      else {
        *(uint *)(param_1 + 0xa4) = uVar5;
      }
      puVar7[1] = uVar5;
    }
    uVar3 = (undefined)(uVar4 >> 8);
    if ((*(byte *)(param_1 + 0x33) & 0x40) == 0) {
      *puVar8 = (char)uVar4;
      puVar8[4] = uVar3;
    }
    else {
      *puVar8 = (char)uVar4;
      puVar8[4] = uVar3;
      puVar8[0x38] = (char)(uVar4 >> 0x10);
    }
    if (*puVar7 >> 0x1c == 4) {
      puVar7[2] = uVar4;
    }
    bVar11 = (wVar1 >> 1 & 1) == 0;
    if ((*(byte *)(param_1 + 0x43) & 7) == 0) {
      if (bVar11) {
        uVar2 = *(undefined2 *)(uVar9 + 8);
        puVar8 = aUnwantedDataOu;
loc_F00B5850:
        _esplog(param_1,3,puVar8,uVar2);
        uVar3 = 2;
        goto loc_F00B585C;
      }
      uVar9 = *puVar7;
    }
    else {
      if (!bVar11) {
        uVar2 = *(undefined2 *)(uVar9 + 8);
        puVar8 = aUnwantedDataIn;
        goto loc_F00B5850;
      }
      *puVar7 = *puVar7 | 0x100;
      uVar9 = *puVar7;
    }
    *puVar7 = uVar9 | 0x210;
    puVar8[0xc] = 0x90;
    uVar10 = 0xffffffff;
    *(undefined *)(param_1 + 0x42) = *(undefined *)(param_1 + 0x41);
    *(undefined *)(param_1 + 0x41) = 10;
  }
locret_F00B589C:
  return CONCAT44(param_2,uVar10);
}
/* GHIDRADEC_FUNCTION index=2718 start=0xf00b58a4 */

/* WARNING: Removing unreachable block (ram,0xf00b59e8) */
/* WARNING: Removing unreachable block (ram,0xf00b5918) */
/* WARNING: Removing unreachable block (ram,0xf00b59ac) */
/* WARNING: Removing unreachable block (ram,0xf00b5b68) */
/* WARNING: Removing unreachable block (ram,0xf00b5950) */

qword _esp_handle_data_done(int param_1)

{
  byte bVar1;
  word wVar2;
  int iVar3;
  uint uVar4;
  undefined8 *puVar5;
  undefined *puVar6;
  undefined4 unaff_l0;
  uint *puVar7;
  undefined4 unaff_l1;
  undefined *puVar8;
  undefined4 unaff_l3;
  int iVar9;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  byte bVar10;
  undefined4 unaff_l6;
  byte bVar11;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar12;
  uint uVar13;
  int iVar14;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar15;
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
  bVar10 = *(byte *)(param_1 + 0x43);
  puVar7 = *(uint **)(param_1 + 0xa0);
  puVar8 = *(undefined **)(param_1 + 0x9c);
  iVar9 = *(int *)(*(sword *)(param_1 + 0xb2) * 4 + param_1 + 0xb8);
  bVar11 = 0;
  bVar1 = *(byte *)(iVar9 + 9);
  wVar2 = *(word *)(iVar9 + 0x5c) >> 1;
  if ((*puVar7 & 2) != 0) {
    if ((wVar2 & 1) == 0) {
      puVar5 = &aReceive;
    }
    else {
      puVar5 = (undefined8 *)&aSend;
    }
    _esplog(param_1,3,aUnrecoverableD_0,puVar5);
    *(undefined *)(iVar9 + 0x28) = 3;
    uVar12 = 8;
    goto locret_F00B5C20;
  }
  if ((wVar2 & 1) == 0) {
    if ((bVar10 & 0x20) != 0) {
      _esplog(param_1,3,aScsiBusDataInP);
      *(undefined *)(param_1 + 0x4c) = 5;
      *(undefined *)(param_1 + 0x53) = 1;
      *(byte *)(iVar9 + 0x2a) = *(byte *)(iVar9 + 0x2a) | 4;
    }
    uVar4 = *puVar7;
    for (uVar13 = 0; ((uVar4 & 0xc) != 0 && (uVar13 < 100)); uVar13 = uVar13 + 1) {
      if (uVar4 >> 0x1c != 4) {
        *puVar7 = uVar4 | 0x40;
      }
      _us_spin(200);
      uVar4 = *puVar7;
    }
    if ((99 < uVar13) && ((*puVar7 & 0xc) != 0)) {
      _esplog(param_1,3,aDmaGateArrayWo);
      *(undefined *)(iVar9 + 0x28) = 3;
      uVar12 = 6;
      goto locret_F00B5C20;
    }
  }
  *puVar7 = *puVar7 & 0xffffdcff | 0x20;
  uVar12 = 2;
  if (*(char *)(param_1 + 0x44) != '\x10') {
    *(undefined *)(param_1 + 0x42) = *(undefined *)(param_1 + 0x41);
    *(undefined *)(param_1 + 0x41) = 0x1a;
    goto locret_F00B5C20;
  }
  if ((bVar10 & 0x10) == 0) {
    if ((*(byte *)(param_1 + 0x33) & 0x40) == 0) {
      uVar4 = (uint)CONCAT11(puVar8[4],*puVar8);
    }
    else {
      uVar4 = (uint)CONCAT12(puVar8[0x38],CONCAT11(puVar8[4],*puVar8));
    }
    iVar14 = *(int *)(param_1 + 0xa8) - uVar4;
  }
  else {
    iVar14 = *(int *)(param_1 + 0xa8);
  }
  if ((wVar2 & 1) != 0) {
    iVar14 = iVar14 - ((byte)puVar8[0x1c] & 0x1f);
  }
  if (*(char *)((uint)bVar1 + param_1 + 0x5e) == '\0') {
loc_F00B5BAC:
    bVar15 = false;
  }
  else {
    *(byte *)(iVar9 + 0x2a) = *(byte *)(iVar9 + 0x2a) | 2;
    *(int *)(param_1 + 0x98) = *(int *)(param_1 + 0x98) + 1;
    if (*(char *)(param_1 + 0x31) == '\0') {
      bVar10 = puVar8[0x10];
      *(byte *)(param_1 + 0x43) = bVar10;
      if ((bVar10 & 7) == 1) {
        if ((puVar8[0x1c] & 0x1f) == 0) {
          bVar11 = 1;
loc_F00B5B20:
          iVar3 = (uint)bVar11 << 0x18;
        }
        else {
          iVar3 = 0;
        }
      }
      else {
        iVar3 = 0;
        if ((bVar10 & 7) == 0) {
          if ((puVar8[0x1c] & 0x20) == 0) {
            bVar11 = 0xff;
          }
          goto loc_F00B5B20;
        }
      }
      if (iVar3 >> 0x18 != 0) {
        puVar8[0xc] = 0x12;
        if (iVar3 >> 0x18 < 0) {
          puVar6 = aDataOut;
        }
        else {
          puVar6 = (undefined *)&aDataIn;
        }
        _esplog(param_1,3,off_F011E724,puVar6,(uint)bVar1);
        *(byte *)(param_1 + 0x78) = *(byte *)(param_1 + 0x78) & ~(byte)(1 << (bVar1 & 0x1f));
      }
      bVar15 = true;
      if (bVar11 == 0) goto loc_F00B5BA0;
    }
    else {
loc_F00B5BA0:
      bVar15 = true;
      if ((wVar2 & 1) != 0) goto loc_F00B5BAC;
    }
  }
  if (!bVar15) {
    puVar8[0xc] = 1;
  }
  *(int *)(iVar9 + 0x34) = *(int *)(iVar9 + 0x34) + iVar14;
  *(int *)(*(int *)(iVar9 + 0x54) + 4) = *(int *)(*(int *)(iVar9 + 0x54) + 4) + iVar14;
  *(byte *)(iVar9 + 0x29) = *(byte *)(iVar9 + 0x29) | 8;
  *(undefined *)(param_1 + 0x42) = *(undefined *)(param_1 + 0x41);
  *(undefined *)(param_1 + 0x41) = 0x1a;
  if (bVar11 == 0) {
    if ((bVar10 & 7) < 2) {
      *(undefined *)(param_1 + 0x41) = 9;
    }
    uVar12 = 2;
  }
  else {
    uVar12 = 0xffffffff;
  }
locret_F00B5C20:
  return (qword)CONCAT14(bVar1,uVar12);
}
/* GHIDRADEC_FUNCTION index=2719 start=0xf00b5c28 */

/* WARNING: Removing unreachable block (ram,0xf00b5cb8) */
/* WARNING: Removing unreachable block (ram,0xf00b5d08) */
/* WARNING: Removing unreachable block (ram,0xf00b5d88) */
/* WARNING: Removing unreachable block (ram,0xf00b5ce0) */

undefined8 _esp_handle_c_cmplt(int param_1,undefined4 param_2)

{
  char cVar1;
  byte bVar2;
  undefined uVar3;
  char *pcVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  char cVar5;
  char cVar6;
  undefined4 unaff_l3;
  int iVar7;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  int iVar8;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  char cVar9;
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
  cVar1 = *(char *)(param_1 + 0x44);
  iVar8 = *(int *)(param_1 + 0x9c);
  iVar7 = *(int *)(*(sword *)(param_1 + 0xb2) * 4 + param_1 + 0xb8);
  if (cVar1 == ' ') {
    *(undefined *)(param_1 + 0x42) = *(undefined *)(param_1 + 0x41);
    *(undefined *)(param_1 + 0x41) = 0x1a;
    param_1 = 2;
  }
  else {
    bVar2 = *(byte *)(param_1 + 0x43);
    if ((bVar2 & 0x20) != 0) {
      *(byte *)(iVar7 + 0x2a) = *(byte *)(iVar7 + 0x2a) | 4;
    }
    cVar6 = '\0';
    cVar9 = -1;
    if (cVar1 == '\x10') {
      cVar5 = *(char *)(iVar8 + 8);
      if ((bVar2 & 0x20) != 0) {
        cVar5 = '\x02';
        _esplog(param_1,3,aScsiBusStatusP);
        cVar6 = '\x05';
      }
    }
    else {
      cVar5 = *(char *)(iVar8 + 8);
      *(char *)(param_1 + 0x54) = cVar5;
      *(undefined *)(param_1 + 0x54) = *(undefined *)(iVar8 + 8);
      _printf(&unk_F011E768);
      cVar9 = '\0';
      *(undefined *)(param_1 + 0x54) = 0;
      if ((bVar2 & 0x20) != 0) {
        cVar6 = '\t';
        _esplog(param_1,3,_msginperr);
      }
    }
    if (cVar5 != -1) {
      pcVar4 = *(char **)(iVar7 + 0x30);
      *(byte *)(iVar7 + 0x29) = *(byte *)(iVar7 + 0x29) | 0x10;
      *(char **)(iVar7 + 0x30) = pcVar4 + 1;
      *pcVar4 = cVar5;
    }
    if (cVar6 == '\0') {
      if (cVar9 == '\0') {
        uVar3 = *(undefined *)(param_1 + 0x41);
      }
      else {
        if (1 < (byte)(cVar9 - 10U)) {
          *(undefined *)(param_1 + 0x5c) = 1;
          *(undefined *)(param_1 + 0x5d) = 1;
          *(undefined *)(param_1 + 0x42) = *(undefined *)(param_1 + 0x41);
          *(undefined *)(param_1 + 0x41) = 7;
          _esp_handle_msg_in_done();
          goto locret_F00B5DCC;
        }
        uVar3 = *(undefined *)(param_1 + 0x41);
      }
      *(undefined *)(param_1 + 0x42) = uVar3;
      uVar3 = 8;
    }
    else {
      *(char *)(param_1 + 0x4c) = cVar6;
      *(undefined *)(param_1 + 0x53) = 1;
      uVar3 = 0x1a;
      *(undefined *)(param_1 + 0x42) = *(undefined *)(param_1 + 0x41);
    }
    *(undefined *)(param_1 + 0x41) = uVar3;
    if (cVar1 == '\x10') {
      param_1 = 2;
    }
    else {
      *(undefined *)(iVar8 + 0xc) = 0x12;
      param_1 = -1;
    }
  }
locret_F00B5DCC:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2720 start=0xf00b5dd4 */

undefined8 _esp_handle_msg_in(int param_1)

{
  int iVar1;
  undefined4 unaff_l0;
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
  iVar1 = *(int *)(param_1 + 0x9c);
  *(undefined *)(iVar1 + 0xc) = 1;
  if (*(char *)(param_1 + 0x31) == '\0') {
    *(undefined *)(iVar1 + 0xc) = 0;
  }
  *(undefined *)(iVar1 + 0xc) = 0x10;
  *(undefined *)(param_1 + 0x5c) = 1;
  *(undefined *)(param_1 + 0x5d) = 0;
  *(undefined *)(param_1 + 0x42) = *(undefined *)(param_1 + 0x41);
  *(undefined *)(param_1 + 0x41) = 7;
  return 0x1ffffffff;
}
/* GHIDRADEC_FUNCTION index=2721 start=0xf00b5e1c */

/* WARNING: Removing unreachable block (ram,0xf00b5e7c) */

undefined8 _esp_handle_more_msgin(int param_1,undefined4 param_2)

{
  undefined uVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar2;
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
  if ((*(byte *)(param_1 + 0x44) & 0x10) == 0) {
    uVar1 = *(undefined *)(param_1 + 0x41);
  }
  else {
    if ((*(byte *)(param_1 + 0x43) & 7) == 7) {
      *(undefined *)(*(int *)(param_1 + 0x9c) + 0xc) = 0x10;
      uVar2 = 0xffffffff;
      *(undefined *)(param_1 + 0x42) = *(undefined *)(param_1 + 0x41);
      uVar1 = 7;
      goto loc_F00B5E94;
    }
    if (*(char *)(param_1 + 0x5c) != '\0') {
      _esplog(param_1,4,aPrematureEndOf);
    }
    uVar1 = *(undefined *)(param_1 + 0x41);
  }
  uVar2 = 2;
  *(undefined *)(param_1 + 0x42) = uVar1;
  uVar1 = 0x1a;
loc_F00B5E94:
  *(undefined *)(param_1 + 0x41) = uVar1;
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=2722 start=0xf00b5ea0 */

/* WARNING: Removing unreachable block (ram,0xf00b6060) */
/* WARNING: Removing unreachable block (ram,0xf00b609c) */
/* WARNING: Removing unreachable block (ram,0xf00b5f7c) */
/* WARNING: Removing unreachable block (ram,0xf00b608c) */
/* WARNING: Removing unreachable block (ram,0xf00b6018) */
/* WARNING: Removing unreachable block (ram,0xf00b5f2c) */
/* WARNING: Removing unreachable block (ram,0xf00b5ee4) */

undefined8 _esp_handle_msg_in_done(uint param_1,undefined4 param_2)

{
  byte bVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar2;
  int iVar3;
  undefined4 unaff_l3;
  int iVar4;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar5;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar6;
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
  uVar2 = 0;
  iVar4 = *(int *)(*(sword *)(param_1 + 0xb2) * 4 + param_1 + 0xb8);
  uVar5 = 0;
  iVar3 = *(int *)(param_1 + 0x9c);
  if (*(char *)(param_1 + 0x42) == '\v') {
    uVar2 = (uint)*(byte *)(param_1 + 0x54);
  }
  else {
    if ((*(byte *)(param_1 + 0x44) & 0x20) != 0) {
      _esplog(param_1,3,aPrematureEndOf_0);
      iVar3 = 2;
      *(undefined *)(param_1 + 0x42) = *(undefined *)(param_1 + 0x41);
      *(undefined *)(param_1 + 0x41) = 0x1a;
      goto locret_F00B6114;
    }
    if (*(char *)(param_1 + 0x5c) == '\0') {
      bVar1 = *(byte *)(iVar3 + 0x1c);
    }
    else {
      if ((*(byte *)(param_1 + 0x43) & 0x20) != 0) {
        _esplog(param_1,3,_msginperr);
        uVar5 = 9;
        *(byte *)(iVar4 + 0x2a) = *(byte *)(iVar4 + 0x2a) | 4;
        *(undefined *)(iVar3 + 0xc) = 1;
        goto loc_F00B5FD4;
      }
      bVar1 = *(byte *)(iVar3 + 0x1c);
    }
    uVar2 = bVar1 & 0x1f;
    if (uVar2 == 1) {
      if (*(char *)(param_1 + 0x5c) == '\0') {
        uVar2 = (uint)*(byte *)(iVar3 + 8);
        *(undefined *)(param_1 + 0x42) = *(undefined *)(param_1 + 0x41);
        *(undefined *)(param_1 + 0x41) = 6;
      }
      else {
        bVar1 = *(byte *)(param_1 + 0x5d);
        *(byte *)(param_1 + 0x5d) = bVar1 + 1;
        uVar2 = (uint)*(byte *)(iVar3 + 8);
        *(byte *)(bVar1 + param_1 + 0x54) = *(byte *)(iVar3 + 8);
      }
    }
    else {
      uVar5 = 5;
      *(undefined *)(iVar3 + 0xc) = 1;
      _esplog(param_1,3,aInputMessageBo);
    }
  }
loc_F00B5FD4:
  bVar6 = false;
  if (uVar5 == 0) {
    bVar1 = *(byte *)(param_1 + 0x5c);
    bVar6 = false;
    if (bVar1 != 0) {
      if (*(byte *)(param_1 + 0x5d) < bVar1) {
        *(undefined *)(param_1 + 0x42) = *(undefined *)(param_1 + 0x41);
        *(undefined *)(param_1 + 0x41) = 6;
      }
      else if (bVar1 == 1) {
        uVar5 = param_1;
        _esp_onebyte_msg();
      }
      else if (bVar1 == 2) {
        if (*(char *)(param_1 + 0x54) == '\x01') {
          if (8 < uVar2 + 2) {
            uVar5 = 7;
            _esplog(param_1,3,off_F011E7F4,1);
            bVar6 = false;
            goto loc_F00B60AC;
          }
          *(char *)(param_1 + 0x5c) = (char)uVar2 + '\x02';
          *(undefined *)(param_1 + 0x42) = *(undefined *)(param_1 + 0x41);
          *(undefined *)(param_1 + 0x41) = 6;
        }
        else {
          uVar5 = param_1;
          _esp_twobyte_msg();
        }
      }
      else {
        uVar5 = param_1;
        _esp_multibyte_msg();
      }
      bVar6 = (int)uVar5 < 0;
    }
  }
loc_F00B60AC:
  if (bVar6) {
    iVar3 = -uVar5;
    goto locret_F00B6114;
  }
  if (0 < (int)uVar5) {
    if (uVar5 == 1) {
loc_F00B60E8:
      *(char *)(param_1 + 0x4c) = (char)uVar5;
    }
    else {
      if (((uVar5 & 0xf0) == 0) || ((uVar5 & 0x98) == 0x80)) {
        *(undefined *)(param_1 + 0x53) = 1;
        goto loc_F00B60E8;
      }
      *(char *)(param_1 + 0x4c) = (char)uVar5;
    }
    *(undefined *)(iVar3 + 0xc) = 0x1a;
    *(undefined *)(param_1 + 0x5c) = 0;
    *(undefined *)(param_1 + 0x42) = *(undefined *)(param_1 + 0x41);
    *(undefined *)(param_1 + 0x41) = 6;
  }
  *(undefined *)(iVar3 + 0xc) = 0x12;
  iVar3 = -1;
locret_F00B6114:
  return CONCAT44(param_2,iVar3);
}
/* GHIDRADEC_FUNCTION index=2723 start=0xf00b611c */

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
/* GHIDRADEC_FUNCTION index=2724 start=0xf00b6400 */

/* WARNING: Removing unreachable block (ram,0xf00b6424) */
/* WARNING: Removing unreachable block (ram,0xf00b640c) */

undefined8 _esp_twobyte_msg(int param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 unaff_l0;
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
  uVar1 = (uint)*(byte *)(param_1 + 0x54);
  _scsi_mname(uVar1);
  _esplog(param_1,4,aTwoByteMessage,uVar1,*(undefined *)(param_1 + 0x55));
  return CONCAT44(param_2,7);
}
/* GHIDRADEC_FUNCTION index=2725 start=0xf00b6434 */

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
    .div(uVar5,uVar6);
    uVar5 = (int)(uVar5 + 3) >> 2;
    iVar8 = (uint)*(word *)(param_1 + 0x3e) * 0x23;
    .div(iVar8,1000);
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
            .udiv(uVar5,1000);
            if (*(char *)(param_1 + uVar11 + 0x6e) != '\0') {
              uVar9 = uVar9 * 0x78;
              .udiv(uVar9,100);
            }
            uVar7 = (uVar9 * 4 + (uVar5 & 0xffff)) - 1;
            .udiv(uVar7,uVar5 & 0xffff);
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
          .umul(uVar7,*(undefined2 *)(param_1 + 0x3e));
          .udiv();
          iVar8 = 1000000000;
          .udiv(1000000000,uVar7);
          .udiv(iVar8 + 999,1000);
          .urem();
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
/* GHIDRADEC_FUNCTION index=2726 start=0xf00b6850 */

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
/* GHIDRADEC_FUNCTION index=2727 start=0xf00b6bb4 */

/* WARNING: Removing unreachable block (ram,0xf00b6eec) */
/* WARNING: Removing unreachable block (ram,0xf00b6e20) */
/* WARNING: Removing unreachable block (ram,0xf00b6de4) */
/* WARNING: Removing unreachable block (ram,0xf00b6dc4) */
/* WARNING: Removing unreachable block (ram,0xf00b6dec) */
/* WARNING: Removing unreachable block (ram,0xf00b6e80) */
/* WARNING: Removing unreachable block (ram,0xf00b706c) */
/* WARNING: Removing unreachable block (ram,0xf00b6d78) */

undefined8 _esp_reconnect(int param_1,undefined4 param_2)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  byte bVar8;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined *puVar9;
  undefined4 unaff_l3;
  int iVar10;
  undefined4 unaff_l4;
  int iVar11;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar12;
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
  iVar10 = *(int *)(param_1 + 0x9c);
  *(undefined *)(param_1 + 0x42) = *(undefined *)(param_1 + 0x41);
  *(undefined *)(param_1 + 0x41) = 0x1b;
  uVar2 = 1 << (*(byte *)(param_1 + 0x32) & 7);
  if (((*(byte *)(iVar10 + 0x1c) & 0x1f) == 2) &&
     (uVar6 = *(byte *)(iVar10 + 8) ^ uVar2, (*(byte *)(iVar10 + 8) & uVar2) != 0)) {
    uVar3 = uVar6 & 0xff;
    iVar11 = 0;
    uVar2 = uVar3;
    if (uVar3 != 0) {
      do {
        if ((uVar2 & 1) != 0) {
          uVar6 = uVar6 ^ 1 << ((byte)iVar11 & 0x1f);
          break;
        }
        iVar11 = iVar11 + 1;
        uVar2 = (int)uVar3 >> ((byte)iVar11 & 0x1f);
      } while (iVar11 < 8);
      if (((uVar6 & 0xff) == 0) && ((*(byte *)(param_1 + 0x43) & 7) == 7)) {
        uVar2 = (uint)*(byte *)(iVar10 + 8);
        *(byte *)(param_1 + 0x54) = *(byte *)(iVar10 + 8);
        if ((*(byte *)(param_1 + 0x43) & 0x20) != 0) {
          uVar2 = 0x80;
        }
        if ((uVar2 & 0xd8) == 0x80) {
          uVar2 = uVar2 & 7;
          if ((*(byte *)(iVar10 + 0x1c) & 0x1f) != 0) {
            do {
            } while ((*(byte *)(iVar10 + 0x1c) & 0x1f) != 0);
          }
          *(undefined *)(iVar10 + 0xc) = 0;
          iVar7 = param_1 + iVar11;
          *(byte *)(iVar10 + 0x18) = *(byte *)(iVar7 + 0x66) & 0x1f;
          *(byte *)(iVar10 + 0x1c) = *(byte *)(iVar7 + 0x5e) | *(byte *)(param_1 + 0x77);
          if ((byte)(*(char *)(param_1 + 0x31) - 3U) < 2) {
            *(undefined *)(iVar10 + 0x30) = *(undefined *)(iVar7 + 0x34);
          }
          uVar3 = iVar11 << 3 | uVar2;
          iVar7 = (int)(sword)uVar3;
          uVar6 = *(uint *)(iVar7 * 4 + param_1 + 0xb8);
          if ((*(byte *)(param_1 + 0x43) & 0x20) != 0) {
            bVar8 = 0;
            uVar2 = 0;
            iVar5 = iVar7;
            do {
              uVar4 = *(uint *)(iVar5 * 4 + param_1 + 0xb8);
              if ((uVar4 != 0) && (bVar8 = bVar8 + 1, uVar6 == 0)) {
                uVar6 = uVar4;
              }
              uVar2 = uVar2 + 1;
              iVar5 = iVar7 + uVar2;
            } while ((int)uVar2 < 8);
            if (bVar8 == 1) {
              uVar2 = (uint)*(byte *)(uVar6 + 10);
              uVar3 = uVar3 + uVar2;
            }
            else if (1 < bVar8) {
              _esplog(param_1,3,off_F011EA4C);
              goto loc_F00B7068;
            }
          }
          if ((uVar6 == 0) || ((*(word *)(uVar6 + 0x5c) & 0x110) == 0)) {
            uVar6 = uVar6 & -(uint)(uVar6 != 0);
            puVar9 = (undefined *)((int)register0x00000038 + -0x80);
            iVar7 = param_1;
            _scsi_cookie();
            *(int *)((int)register0x00000038 + -0x10) = iVar7;
            *(sword *)((int)register0x00000038 + -0xc) = (sword)iVar11;
            *(char *)((int)register0x00000038 + -10) = (char)uVar2;
            *(undefined *)((int)register0x00000038 + -9) = 0;
            _esp_makeproxy_cmd(puVar9,(undefined *)((int)register0x00000038 + -0x10),6);
            _esp_init_cmd(puVar9);
            *(int *)(param_1 + 0x80) = *(int *)(param_1 + 0x80) + 1;
            *(int *)(param_1 + 0x84) = *(int *)(param_1 + 0x84) + 1;
            _esplog(param_1,4,aNoCommandForRe,iVar11,uVar2);
            *(undefined *)(param_1 + 0x4c) = 6;
            *(undefined *)(param_1 + 0x53) = 1;
            *(undefined *)(iVar10 + 0xc) = 0x12;
            *(sword *)(param_1 + 0xb2) = (sword)uVar3;
            iVar7 = ((int)(uVar3 << 0x10) >> 0xe) + param_1;
            *(undefined **)(iVar7 + 0xb8) = puVar9;
            iVar10 = *(int *)(param_1 + 0x80);
            *(undefined *)(param_1 + 0x42) = *(undefined *)(param_1 + 0x41);
            *(undefined *)(param_1 + 0x41) = 0x1a;
            while (iVar10 != 0) {
              iVar10 = param_1;
              _esp_dopoll(param_1,180000000);
              if (iVar10 != 0) {
                if (*(undefined **)(iVar7 + 0xb8) != puVar9) {
                  uVar12 = 8;
                  goto locret_F00B7078;
                }
                *(undefined4 *)(iVar7 + 0xb8) = 0;
                goto loc_F00B7074;
              }
              iVar10 = *(int *)(param_1 + 0x80);
            }
            if (*(char *)((int)register0x00000038 + -0x58) == '\0') {
              puVar9 = aSucceeded;
            }
            else {
              puVar9 = (undefined *)&aFailed;
            }
            _esplog(param_1,6,aProxyAbortSFor,puVar9,iVar11,uVar2);
            iVar10 = (int)(uVar3 << 0x10) >> 0xe;
            if (uVar6 == 0) {
              iVar10 = iVar10 + param_1;
              if (*(undefined **)(iVar10 + 0xb8) == (undefined *)((int)register0x00000038 + -0x80))
              {
                *(undefined4 *)(iVar10 + 0xb8) = 0;
              }
            }
            else {
              *(uint *)(iVar10 + param_1 + 0xb8) = uVar6;
            }
            uVar12 = 8;
            if ((*(char *)((int)register0x00000038 + -0x58) == '\0') &&
               (*(char *)((int)register0x00000038 + -0x15) == '\x01')) {
              uVar12 = 5;
            }
          }
          else {
            bVar8 = 0;
            if ((*(word *)(uVar6 + 0x5c) & 0x100) == 0) {
              if ((_scsi_options & 0x40) != 0) {
                if ((*(uint *)(uVar6 + 0x14) & 8) == 0) {
                  if ((*(byte *)(param_1 + 0x43) & 0x20) != 0) {
                    *(undefined *)(param_1 + 0x4c) = 9;
                    *(undefined *)(param_1 + 0x53) = 1;
                  }
                }
                else {
                  *(byte *)(iVar10 + 0x20) = *(byte *)(param_1 + 0x32) & 0xef;
                }
              }
            }
            else {
              *(int *)(param_1 + 0x88) = *(int *)(param_1 + 0x88) + 1;
              *(undefined *)(iVar10 + 0xc) = 0x1a;
              cVar1 = *(char *)(uVar6 + 0x6c);
              *(char *)(param_1 + 0x53) = cVar1;
              if (cVar1 != '\0') {
                uVar2 = 0;
                do {
                  bVar8 = bVar8 + 1;
                  *(undefined *)(param_1 + uVar2 + 0x4c) = *(undefined *)(uVar6 + uVar2 + 0x6d);
                  uVar2 = (uint)bVar8;
                } while (bVar8 < *(byte *)(param_1 + 0x53));
              }
              *(undefined *)(uVar6 + 0x6b) = 0;
            }
            *(undefined *)(iVar10 + 0xc) = 0x12;
            *(sword *)(param_1 + 0xb2) = (sword)uVar3;
            if (*(int *)(param_1 + 0x88) != 0) {
              *(int *)(param_1 + 0x88) = *(int *)(param_1 + 0x88) + -1;
            }
            uVar12 = 0xffffffff;
            *(undefined *)(param_1 + 0x42) = *(undefined *)(param_1 + 0x41);
            *(undefined *)(param_1 + 0x41) = 0x1a;
            *(word *)(uVar6 + 0x5c) = *(word *)(uVar6 + 0x5c) & 0xffef;
            *(undefined4 *)(uVar6 + 0x2c) = *(undefined4 *)(uVar6 + 0x20);
            *(undefined4 *)(uVar6 + 0x30) = *(undefined4 *)(uVar6 + 0x1c);
            *(undefined4 *)(uVar6 + 0x34) = *(undefined4 *)(uVar6 + 0x38);
            *(undefined *)(param_1 + 0x46) = 0;
          }
          goto locret_F00B7078;
        }
      }
    }
  }
loc_F00B7068:
  _esp_printstate(param_1,aFailedReselect);
loc_F00B7074:
  uVar12 = 8;
locret_F00B7078:
  return CONCAT44(param_2,uVar12);
}
/* GHIDRADEC_FUNCTION index=2728 start=0xf00b7080 */

/* WARNING: Removing unreachable block (ram,0xf00b70bc) */

undefined8 _esp_istart(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
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
  if (((*(char *)(param_1 + 0x41) == '\0') && (*(int *)(param_1 + 0x80) == 0)) &&
     (*(uint *)(param_1 + 0x88) < *(uint *)(param_1 + 0x84))) {
    _esp_ustart(param_1,(int)*(sword *)(param_1 + 0xb0));
  }
  return CONCAT44(param_2,0xffffffff);
}
/* GHIDRADEC_FUNCTION index=2729 start=0xf00b70cc */

/* WARNING: Removing unreachable block (ram,0xf00b7190) */
/* WARNING: Removing unreachable block (ram,0xf00b7174) */
/* WARNING: Removing unreachable block (ram,0xf00b7158) */
/* WARNING: Removing unreachable block (ram,0xf00b7188) */
/* WARNING: Removing unreachable block (ram,0xf00b71e4) */
/* WARNING: Removing unreachable block (ram,0xf00b7130) */

undefined8 _esp_runpoll(int param_1,int param_2)

{
  char cVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar6;
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
  iVar6 = *(int *)(((param_2 << 0x10) >> 0xe) + param_1 + 0xb8);
  iVar4 = *(int *)(param_1 + 0x80) + 1;
  iVar5 = *(int *)(iVar6 + 0x18);
  *(int *)(param_1 + 0x80) = iVar4;
  if (iVar4 == 0) {
loc_F00B71C8:
    if (*(char *)(param_1 + 0x41) == '\0') {
      _esp_ustart(param_1,(int)(sword)param_2 + 1U & 0x3f);
    }
locret_F00B71EC:
    return CONCAT44(param_2,param_1);
  }
  cVar1 = *(char *)(param_1 + 0x41);
  do {
    if (cVar1 != '\0') {
      iVar4 = param_1;
      _esp_dopoll(param_1,180000000);
      puVar2 = aRunpollTimeout;
      if (iVar4 != 0) {
loc_F00B7188:
        _printf(puVar2);
        _esp_abort_curcmd(param_1);
        goto locret_F00B71EC;
      }
    }
    if (*(int *)(param_1 + 0x80) == 0) goto loc_F00B71C8;
    iVar4 = param_1;
    _esp_ustart(param_1,(int)(sword)param_2);
    iVar3 = *(int *)(param_1 + 0x80);
    if (iVar4 == 1) {
      do {
        if (iVar3 == 0) {
          iVar3 = *(int *)(param_1 + 0x80);
          break;
        }
        iVar4 = param_1;
        _esp_dopoll(param_1,iVar5 * 1000000);
        puVar2 = aRunpollTimeout_0;
        if (iVar4 != 0) goto loc_F00B7188;
        iVar3 = *(int *)(param_1 + 0x80);
      } while (*(char *)(iVar6 + 0x29) != '\0');
    }
    if (iVar3 == 0) goto loc_F00B71C8;
    cVar1 = *(char *)(param_1 + 0x41);
  } while( true );
}
/* GHIDRADEC_FUNCTION index=2730 start=0xf00b71f4 */

/* WARNING: Removing unreachable block (ram,0xf00b720c) */

undefined8 _esp_reset_bus(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
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
  *(undefined *)(param_1 + 0x42) = *(undefined *)(param_1 + 0x41);
  *(undefined *)(param_1 + 0x41) = 0x1c;
  _esp_internal_reset(param_1,7);
  return CONCAT44(param_2,0xffffffff);
}
/* GHIDRADEC_FUNCTION index=2731 start=0xf00b721c */

/* WARNING: Removing unreachable block (ram,0xf00b727c) */
/* WARNING: Removing unreachable block (ram,0xf00b7268) */
/* WARNING: Removing unreachable block (ram,0xf00b7288) */
/* WARNING: Removing unreachable block (ram,0xf00b7244) */

undefined8 _esp_reset_recovery(int param_1,undefined4 param_2)

{
  char cVar1;
  sword sVar3;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar4;
  undefined4 uVar5;
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
  uVar4 = (uint)*(word *)(param_1 + 0xb2);
  if (*(sword *)(param_1 + 0xb2) == -1) {
    uVar4 = 0;
  }
  cVar1 = *(char *)(param_1 + 0x83);
  _bcopy(param_1 + 0xb8,(undefined *)((int)register0x00000038 + -0x108),0x100);
  if (1 < (byte)(*(char *)(param_1 + 0x41) - 0x1cU)) {
    _esp_internal_reset(param_1,3);
    _esplog(param_1,5,aUnexpectedScsi);
  }
  _esp_internal_reset(param_1,0x10);
  sVar3 = (sword)uVar4;
  *(undefined *)(param_1 + 0x42) = *(undefined *)(param_1 + 0x41);
  *(undefined *)(param_1 + 0x41) = 0x1f;
  do {
    iVar2 = *(int *)((int)register0x00000038 + ((int)(uVar4 << 0x10) >> 0xe) + -0x108);
    if (iVar2 != 0) {
      if (*(char *)(iVar2 + 0x28) == '\0') {
        *(undefined *)(iVar2 + 0x28) = 4;
      }
      *(undefined4 *)(iVar2 + 0x24) = *(undefined4 *)(iVar2 + 0x40);
      if (*(code **)(iVar2 + 0x10) != (code *)0x0) {
        (**(code **)(iVar2 + 0x10))(iVar2);
      }
    }
    uVar4 = uVar4 + 1 & 0x3f;
  } while (uVar4 != (int)sVar3);
  uVar5 = 0xffffffff;
  *(undefined *)(param_1 + 0x42) = *(undefined *)(param_1 + 0x41);
  *(undefined *)(param_1 + 0x41) = 0;
  if ((*(int *)(param_1 + 0x84) != 0) && (cVar1 == '\0')) {
    uVar5 = 5;
  }
  return CONCAT44(param_2,uVar5);
}
/* GHIDRADEC_FUNCTION index=2732 start=0xf00b7338 */

/* WARNING: Removing unreachable block (ram,0xf00b7348) */

undefined8 _esp_handle_selection(undefined4 param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
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
  _esplog(param_1,5,aUnexpectedSele);
  return CONCAT44(param_2,8);
}
/* GHIDRADEC_FUNCTION index=2733 start=0xf00b7358 */

undefined8 _esp_init_cmd(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
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
  *(undefined *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined *)(param_1 + 0x2a) = 0;
  *(undefined *)(param_1 + 0x29) = 0;
  *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(param_1 + 0x20);
  *(undefined **)(param_1 + 0x30) = *(undefined **)(param_1 + 0x1c);
  **(undefined **)(param_1 + 0x1c) = 0;
  *(word *)(param_1 + 0x5c) = *(word *)(param_1 + 0x5c) & 0xefcf;
  *(int *)(param_1 + 0x58) = *(int *)(param_1 + 0x18);
  if (*(int *)(param_1 + 0x18) != 0) {
    *(word *)(param_1 + 0x5c) = *(word *)(param_1 + 0x5c) | 0x20;
  }
  if ((*(word *)(param_1 + 0x5c) & 1) != 0) {
    *(int *)(param_1 + 0x54) = param_1 + 0x48;
    *(undefined4 *)(param_1 + 0x4c) = 0;
    *(undefined4 *)(param_1 + 0x50) = 0;
    *(undefined4 *)(param_1 + 0x38) = *(undefined4 *)(param_1 + 0x3c);
    *(undefined4 *)(param_1 + 0x34) = *(undefined4 *)(param_1 + 0x3c);
    *(undefined4 *)(param_1 + 0x48) = *(undefined4 *)(param_1 + 0x3c);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2734 start=0xf00b73e8 */

/* WARNING: Removing unreachable block (ram,0xf00b73f0) */

undefined8 _esp_makeproxy_cmd(int param_1,undefined4 *param_2,undefined param_3)

{
  undefined4 unaff_l0;
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
  _bzero(param_1,0x70);
  *(undefined4 *)(param_1 + 4) = *param_2;
  *(undefined4 *)(param_1 + 8) = param_2[1];
  *(code **)(param_1 + 0x10) = _scsi_pollintr;
  *(undefined4 *)(param_1 + 0x14) = 9;
  *(int *)(param_1 + 0x1c) = param_1 + 0x60;
  *(int *)(param_1 + 0x20) = param_1 + 100;
  *(undefined *)(param_1 + 0x2b) = 0xff;
  *(undefined2 *)(param_1 + 0x5c) = 0x100;
  *(undefined *)(param_1 + 0x6a) = 1;
  *(undefined *)(param_1 + 0x6b) = 0;
  *(undefined *)(param_1 + 0x6c) = 1;
  *(undefined *)(param_1 + 0x6d) = param_3;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2735 start=0xf00b7458 */

undefined8 _esp_chip_disconnect(int param_1)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  int iVar2;
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
  iVar2 = *(int *)(param_1 + 0x9c);
  *(undefined *)(iVar2 + 0xc) = 0x44;
  if ((*(sword *)(param_1 + 0xb2) != -1) &&
     (iVar1 = *(int *)(*(sword *)(param_1 + 0xb2) * 4 + param_1 + 0xb8), iVar1 != 0)) {
    if ((_scsi_options & 0x40) == 0) {
      *(undefined *)(param_1 + 0x46) = 0;
      goto locret_F00B74B8;
    }
    if ((*(uint *)(iVar1 + 0x14) & 8) == 0) {
      *(undefined *)(param_1 + 0x46) = 0;
      goto locret_F00B74B8;
    }
    *(undefined *)(iVar2 + 0x20) = *(undefined *)(param_1 + 0x32);
  }
  *(undefined *)(param_1 + 0x46) = 0;
locret_F00B74B8:
  return CONCAT44(iVar2,param_1);
}
/* GHIDRADEC_FUNCTION index=2736 start=0xf00b74c0 */

undefined8 _esp_make_sdtr(int param_1,undefined4 param_2,undefined param_3)

{
  undefined4 unaff_l0;
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
  *(undefined *)(param_1 + 0x4c) = 1;
  *(undefined *)(param_1 + 0x4d) = 3;
  *(undefined *)(param_1 + 0x4e) = 1;
  *(char *)(param_1 + 0x4f) = (char)param_2;
  *(undefined *)(param_1 + 0x50) = param_3;
  *(undefined *)(param_1 + 0x53) = 5;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2737 start=0xf00b74f0 */

/* WARNING: Removing unreachable block (ram,0xf00b7544) */
/* WARNING: Removing unreachable block (ram,0xf00b753c) */
/* WARNING: Removing unreachable block (ram,0xf00b7568) */
/* WARNING: Removing unreachable block (ram,0xf00b7524) */

undefined8 _esp_watch(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 unaff_l0;
  undefined4 *puVar2;
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
  bool bVar3;
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
  if (_esp_softc != (undefined4 *)0x0) {
    bVar3 = _esp_softc == (undefined4 *)0x0;
    puVar2 = _esp_softc;
    do {
      if (bVar3) break;
      if (puVar2[1] == 0) {
        puVar2 = (undefined4 *)puVar2[10];
      }
      else {
        uVar1 = *puVar2;
        _splr(uVar1);
        if (puVar2[0x21] != 0) {
          _esp_watchsubr(puVar2);
        }
        _splx(uVar1);
        puVar2 = (undefined4 *)puVar2[10];
      }
      bVar3 = puVar2 == (undefined4 *)0x0;
    } while (!bVar3);
  }
  _timeout(_esp_watch,0,_hz);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2738 start=0xf00b7578 */

/* WARNING: Removing unreachable block (ram,0xf00b762c) */
/* WARNING: Removing unreachable block (ram,0xf00b7610) */
/* WARNING: Removing unreachable block (ram,0xf00b7638) */

undefined8 _esp_watchsubr(int param_1,undefined4 param_2)

{
  word wVar1;
  int iVar2;
  int iVar3;
  undefined4 unaff_l0;
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
  iVar3 = 0;
  iVar2 = 0;
  do {
    iVar2 = *(int *)((iVar2 >> 0xe) + param_1 + 0xb8);
    if (iVar2 != 0) {
      if (*(char *)(iVar2 + 0x29) == '\0') {
        if ((*(sword *)(param_1 + 0xb2) != -1) &&
           (iVar2 != *(int *)(*(sword *)(param_1 + 0xb2) * 4 + param_1 + 0xb8))) goto loc_F00B7648;
        wVar1 = *(word *)(iVar2 + 0x5c);
      }
      else {
        wVar1 = *(word *)(iVar2 + 0x5c);
      }
      if ((wVar1 & 0x20) != 0) {
        if (*(int *)(iVar2 + 0x58) == 0) {
          if ((**(uint **)(param_1 + 0xa0) & 3) == 0) {
            if ((wVar1 & 0x10) == 0) {
              _esp_curcmd_timeout(param_1);
            }
            else {
              _esp_disccmd_timeout(param_1,(int)(sword)iVar3);
            }
          }
          else {
            *(undefined4 *)(iVar2 + 0x58) = 1;
            _espsvc(param_1);
          }
          break;
        }
        *(int *)(iVar2 + 0x58) = *(int *)(iVar2 + 0x58) + -1;
      }
    }
loc_F00B7648:
    iVar3 = iVar3 + 1;
    iVar2 = iVar3 * 0x10000;
  } while (iVar3 * 0x10000 >> 0x10 < 0x40);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2739 start=0xf00b7668 */

/* WARNING: Removing unreachable block (ram,0xf00b7694) */
/* WARNING: Removing unreachable block (ram,0xf00b768c) */
/* WARNING: Removing unreachable block (ram,0xf00b76a8) */
/* WARNING: Removing unreachable block (ram,0xf00b7680) */

undefined8 _esp_curcmd_timeout(int param_1,int param_2)

{
  int iVar1;
  undefined4 unaff_l0;
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
  _esplog(param_1,3,aCurrentCommand,*(undefined2 *)(param_2 + 8),*(undefined *)(param_2 + 10));
  _esp_sync_backoff(param_1,param_2);
  iVar1 = param_1;
  _esp_abort_allcmds();
  if (iVar1 == 5) {
    _esp_ustart(param_1,0);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2740 start=0xf00b76b8 */

/* WARNING: Removing unreachable block (ram,0xf00b7794) */
/* WARNING: Removing unreachable block (ram,0xf00b7730) */

undefined8 _esp_sync_backoff(int param_1,int param_2)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  undefined *puVar4;
  undefined4 unaff_l0;
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
  bVar1 = *(byte *)(param_2 + 9);
  iVar3 = param_1 + (uint)bVar1;
  if (*(char *)(iVar3 + 0x5e) == '\0') {
    cVar2 = *(char *)(param_1 + 0x31);
  }
  else {
    if (*(char *)(iVar3 + 0x6e) == '\0') {
      *(undefined *)(iVar3 + 0x6e) = 1;
      puVar4 = aTargetDDReduci;
    }
    else {
      *(undefined *)(iVar3 + 0x66) = 0;
      *(undefined *)(iVar3 + 0x5e) = 0;
      puVar4 = aTargetDDRevert;
      *(byte *)(param_1 + 0x7a) = *(byte *)(param_1 + 0x7a) | (byte)(1 << (bVar1 & 0x1f));
    }
    _esplog(param_1,3,puVar4,(uint)bVar1,*(undefined *)(param_2 + 10));
    *(byte *)(param_1 + 0x78) = *(byte *)(param_1 + 0x78) & ~(byte)(1 << (bVar1 & 0x1f));
    cVar2 = *(char *)(param_1 + 0x31);
  }
  if ((1 < (byte)(cVar2 - 3U)) && ((*(byte *)(param_1 + 0x32) & 0x80) == 0)) {
    *(byte *)(param_1 + 0x32) = *(byte *)(param_1 + 0x32) | 0x80;
    *(byte *)(*(int *)(param_1 + 0x9c) + 0x20) = *(byte *)(*(int *)(param_1 + 0x9c) + 0x20) | 0x80;
    _esplog(param_1,3,aRevertingToSlo);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2741 start=0xf00b77a4 */

/* WARNING: Removing unreachable block (ram,0xf00b77cc) */

undefined8 _esp_disccmd_timeout(int param_1,int param_2)

{
  undefined4 unaff_l0;
  int iVar1;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  int iVar2;
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
  iVar2 = ((param_2 << 0x10) >> 0xe) + param_1;
  iVar1 = *(int *)(iVar2 + 0xb8);
  _esplog(param_1,3,aDisconnectedCo,*(undefined2 *)(iVar1 + 8),*(undefined *)(iVar1 + 10));
  *(undefined *)(iVar1 + 0x28) = 6;
  *(undefined4 *)(iVar2 + 0xb8) = 0;
  *(int *)(param_1 + 0x88) = *(int *)(param_1 + 0x88) + -1;
  *(int *)(param_1 + 0x84) = *(int *)(param_1 + 0x84) + -1;
  (**(code **)(iVar1 + 0x10))(iVar1);
  return CONCAT44(iVar2,param_1);
}
/* GHIDRADEC_FUNCTION index=2742 start=0xf00b780c */

/* WARNING: Removing unreachable block (ram,0xf00b7828) */

undefined8 _esp_abort_curcmd(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
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
  if (*(char *)(param_1 + 0x41) == '\0') {
    param_1 = -1;
  }
  else {
    _esp_abort_allcmds(param_1);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2743 start=0xf00b783c */

/* WARNING: Removing unreachable block (ram,0xf00b7854) */

undefined8 _esp_abort_allcmds(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
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
  *(undefined *)(param_1 + 0x42) = *(undefined *)(param_1 + 0x41);
  *(undefined *)(param_1 + 0x41) = 0x1d;
  _esp_internal_reset(param_1,7);
  return CONCAT44(param_2,0xffffffff);
}
/* GHIDRADEC_FUNCTION index=2744 start=0xf00b7864 */

/* WARNING: Removing unreachable block (ram,0xf00b78bc) */
/* WARNING: Removing unreachable block (ram,0xf00b788c) */
/* WARNING: Removing unreachable block (ram,0xf00b78b0) */
/* WARNING: Removing unreachable block (ram,0xf00b78c8) */
/* WARNING: Removing unreachable block (ram,0xf00b7878) */

undefined8 _esp_internal_reset(int param_1,uint param_2)

{
  undefined4 unaff_l0;
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
  if ((param_2 & 0x20) != 0) {
    _esp_printstate(param_1,&aReset);
  }
  if ((param_2 & 0xf) != 0) {
    _esp_hw_reset(param_1,param_2);
  }
  if ((param_2 & 0x10) != 0) {
    *(undefined2 *)(param_1 + 0xb0) = *(undefined2 *)(param_1 + 0xb2);
    *(undefined2 *)(param_1 + 0xb2) = 0xffff;
    _bzero(param_1 + 0xb8,0x100);
    _bzero(param_1 + 0x5e,8);
    _bzero(param_1 + 0x66,8);
    *(undefined *)(param_1 + 0x78) = 0;
    *(undefined4 *)(param_1 + 0x88) = 0;
    *(undefined4 *)(param_1 + 0x80) = 0;
    *(undefined4 *)(param_1 + 0x84) = 0;
    *(undefined *)(param_1 + 0x53) = 0;
    *(undefined *)(param_1 + 0x4c) = 0xff;
    *(undefined *)(param_1 + 0x52) = 0xff;
    *(undefined *)(param_1 + 0x54) = 0xff;
    *(undefined *)(param_1 + 0x42) = *(undefined *)(param_1 + 0x41);
    *(undefined *)(param_1 + 0x41) = 0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2745 start=0xf00b7908 */

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
/* GHIDRADEC_FUNCTION index=2746 start=0xf00b7bec */

/* WARNING: Removing unreachable block (ram,0xf00b7c54) */
/* WARNING: Removing unreachable block (ram,0xf00b7c1c) */
/* WARNING: Removing unreachable block (ram,0xf00b7c4c) */
/* WARNING: Removing unreachable block (ram,0xf00b7c7c) */
/* WARNING: Removing unreachable block (ram,0xf00b7c14) */

undefined8
_esplog(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
       undefined4 param_6)

{
  undefined *puVar1;
  undefined4 unaff_l0;
  undefined *puVar2;
  undefined4 unaff_l1;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 unaff_l3;
  undefined4 uVar5;
  undefined8 in_l4_5;
  undefined8 uVar6;
  undefined4 unaff_l6;
  undefined4 uVar7;
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
    *(int *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = (int)((qword)in_l4_5 >> 0x20);
    *(int *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = (int)in_l4_5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  uVar7 = *(undefined4 *)((int)register0x00000038 + 0x5c);
  uVar6 = *(undefined8 *)((int)register0x00000038 + 0x60);
  puVar2 = (undefined *)((int)register0x00000038 + -0x48);
  uVar5 = *(undefined4 *)((int)register0x00000038 + 0x68);
  uVar4 = *(undefined4 *)((int)register0x00000038 + 0x6c);
  uVar3 = *(undefined4 *)((int)register0x00000038 + 0x70);
  _sprintf(puVar2,&aEspD,*(undefined *)(param_1 + 0x30));
  puVar1 = puVar2;
  _strlen(puVar2);
  _sprintf(puVar2 + (int)puVar1,param_3,param_4,param_5,param_6,uVar7,(int)((qword)uVar6 >> 0x20),
           (int)uVar6,uVar5,uVar4,uVar3);
  puVar1 = puVar2;
  _strlen();
  ((undefined *)((int)register0x00000038 + -8) + (int)puVar1)[-0x40] = 10;
  ((undefined *)((int)register0x00000038 + -8) + (int)puVar1)[-0x3f] = 0;
  _log(param_2,puVar2);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2747 start=0xf00b7c8c */

/* WARNING: Removing unreachable block (ram,0xf00b7cd4) */
/* WARNING: Removing unreachable block (ram,0xf00b7cac) */

undefined8
_eprintf(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
        undefined4 param_6)

{
  undefined8 uVar1;
  undefined4 unaff_l0;
  undefined4 uVar2;
  undefined4 unaff_l1;
  undefined4 uVar3;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 uVar4;
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
  uVar4 = *(undefined4 *)((int)register0x00000038 + 0x5c);
  uVar3 = *(undefined4 *)((int)register0x00000038 + 0x60);
  uVar1 = *(undefined8 *)((int)register0x00000038 + 100);
  uVar2 = *(undefined4 *)((int)register0x00000038 + 0x6c);
  _printf(&aEspD_0,*(undefined *)(param_1 + 0x30));
  _printf(param_2,param_3,param_4,param_5,param_6,uVar4,uVar3,uVar1,uVar2);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2748 start=0xf00b7ce4 */

/* WARNING: Removing unreachable block (ram,0xf00b7d04) */

undefined8 _esp_stat_int_print(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
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
  _printf(aStat0xBIntr0xB,*(undefined *)(param_1 + 0x43),_esp_stat_bits,
          *(undefined *)(param_1 + 0x44),_esp_int_bits);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2749 start=0xf00b7d14 */

/* WARNING: Removing unreachable block (ram,0xf00b7df4) */
/* WARNING: Removing unreachable block (ram,0xf00b7dbc) */
/* WARNING: Removing unreachable block (ram,0xf00b7da0) */
/* WARNING: Removing unreachable block (ram,0xf00b7d48) */
/* WARNING: Removing unreachable block (ram,0xf00b7d3c) */
/* WARNING: Removing unreachable block (ram,0xf00b7d58) */
/* WARNING: Removing unreachable block (ram,0xf00b7db0) */
/* WARNING: Removing unreachable block (ram,0xf00b7dcc) */
/* WARNING: Removing unreachable block (ram,0xf00b7e20) */
/* WARNING: Removing unreachable block (ram,0xf00b7d2c) */

undefined8 _esp_printstate(int param_1,undefined4 param_2)

{
  undefined uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint *puVar4;
  undefined4 unaff_l3;
  int iVar5;
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
  iVar5 = *(int *)(param_1 + 0x9c);
  puVar4 = *(uint **)(param_1 + 0xa0);
  _eprintf(param_1,&aS_5,param_2);
  uVar2 = (uint)*(byte *)(param_1 + 0x41);
  _esp_state_name(uVar2);
  uVar3 = (uint)*(byte *)(param_1 + 0x42);
  _esp_state_name(uVar3);
  _printf(aStateSLastStat,uVar2,uVar3);
  if ((*puVar4 & 0x200) == 0) {
    uVar1 = *(undefined *)(iVar5 + 0x1c);
  }
  else {
    uVar2 = *puVar4 & 0xfffffdff;
    *puVar4 = uVar2;
    uVar1 = *(undefined *)(iVar5 + 0x1c);
    *puVar4 = uVar2 | 0x200;
  }
  _printf(aLatchedStat0xB,*(undefined *)(param_1 + 0x43),_esp_stat_bits,
          *(undefined *)(param_1 + 0x44),_esp_int_bits,uVar1);
  uVar2 = (uint)*(byte *)(param_1 + 0x52);
  _scsi_mname(uVar2);
  uVar3 = (uint)*(byte *)(param_1 + 0x54);
  _scsi_mname(uVar3);
  _printf(aLastMsgOutSLas,uVar2,uVar3);
  _printf(aDmaCsr0xBAddrX,**(undefined4 **)(param_1 + 0xa0),_dmaga_bits,
          (*(undefined4 **)(param_1 + 0xa0))[1],*(undefined4 *)(param_1 + 0xa4),
          *(undefined4 *)(param_1 + 0xa8));
  if ((*(sword *)(param_1 + 0xb2) != -1) &&
     (*(int *)(*(sword *)(param_1 + 0xb2) * 4 + param_1 + 0xb8) != 0)) {
    _esp_dump_cmd();
  }
  return CONCAT44(param_2,param_1);
}

