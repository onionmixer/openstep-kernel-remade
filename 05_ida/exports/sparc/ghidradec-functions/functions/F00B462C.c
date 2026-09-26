
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
