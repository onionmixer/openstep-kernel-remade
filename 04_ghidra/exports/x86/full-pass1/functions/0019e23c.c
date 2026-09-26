/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0019e23c */

undefined4 FUN_0019e23c(int param_1,ushort *param_2)

{
  char cVar1;
  byte bVar2;
  ushort uVar3;
  int iVar4;
  byte bVar5;
  int iVar6;
  undefined4 uVar7;
  byte bVar8;
  undefined4 *puVar9;
  uint uVar10;
  undefined1 *puVar11;
  undefined2 *puVar12;
  undefined4 *puVar13;
  int iVar14;
  byte bVar15;
  byte *pbVar16;
  undefined1 *puVar17;
  undefined2 *puVar18;
  undefined4 *puVar19;
  int local_54;
  int local_50;
  byte local_48;
  byte *local_44;
  int local_2c;
  int local_28;
  byte local_24;
  int local_20;
  byte *local_10;
  int local_c;
  
  iVar4 = *(int *)(param_1 + 0x1c);
  puVar9 = (undefined4 *)0x0;
  switch(*(undefined4 *)(iVar4 + 0x1c)) {
  case 0:
    puVar9 = (undefined4 *)&DAT_001e4838;
    break;
  case 1:
    puVar9 = (undefined4 *)&DAT_001e4848;
    break;
  case 2:
  case 3:
    local_20 = 0x10;
    break;
  case 4:
    local_20 = 0x20;
    break;
  default:
                    /* WARNING: Subroutine does not return */
    _panic(s_FBConsole_Fill__bogus_bitsPerPix_001e4868);
  }
  if (puVar9 == (undefined4 *)0x0) {
    local_54._0_1_ = 0;
    local_24 = 0;
    bVar15 = 0;
    local_50 = -1;
    local_28 = -1;
    local_2c = -1;
    iVar14 = 0;
    bVar2 = 0;
    bVar8 = 0;
    bVar5 = 0;
    if (0 < local_20) {
      do {
        local_24 = bVar5;
        local_54._0_1_ = bVar8;
        bVar15 = bVar2;
        cVar1 = *(char *)(iVar14 + iVar4 + 0x24);
        if (cVar1 == 'G') {
          if (local_28 == -1) {
            local_28 = iVar14;
          }
          local_24 = local_24 + 1;
        }
        else if (cVar1 < 'H') {
          if (cVar1 == 'B') {
            if (local_2c == -1) {
              local_2c = iVar14;
            }
            bVar15 = bVar15 + 1;
          }
        }
        else if (cVar1 == 'R') {
          if (local_50 == -1) {
            local_50 = iVar14;
          }
          local_54._0_1_ = (byte)local_54 + 1;
        }
        iVar14 = iVar14 + 1;
        bVar2 = bVar15;
        bVar8 = (byte)local_54;
        bVar5 = local_24;
      } while (iVar14 < local_20);
    }
    iVar14 = 0;
    cVar1 = (char)local_20;
    do {
      iVar6 = 3 - iVar14;
      (&DAT_001e4858)[iVar14] =
           (((1 << ((byte)local_54 & 0x1f)) + -1) * iVar6) / 3 <<
           ((cVar1 - (char)local_50) - (byte)local_54 & 0x1f) |
           (((1 << (local_24 & 0x1f)) + -1) * iVar6) / 3 <<
           ((cVar1 - (char)local_28) - local_24 & 0x1f) |
           (((1 << (bVar15 & 0x1f)) + -1) * iVar6) / 3 << ((cVar1 - (char)local_2c) - bVar15 & 0x1f)
      ;
      iVar14 = iVar14 + 1;
    } while (iVar14 < 4);
    puVar9 = &DAT_001e4858;
  }
  iVar14 = (uint)param_2[1] + (*(int *)(iVar4 + 8) + -0x1e0) / 2;
  uVar10 = (uint)*param_2 + (*(int *)(iVar4 + 4) + -0x280) / 2 & 0xfffffffc;
  uVar3 = param_2[2];
  param_2[2] = uVar3 & 0xfffc;
  if ((*(int *)(iVar4 + 4) < (int)((uVar3 & 0xfffc) + uVar10)) ||
     (*(int *)(iVar4 + 8) < (int)((uint)param_2[3] + iVar14))) {
    uVar7 = 0xffffffff;
  }
  else {
    local_10 = *(byte **)(param_2 + 4);
    switch(*(undefined4 *)(iVar4 + 0x1c)) {
    case 0:
      if ((int)uVar10 < 0) {
        uVar10 = uVar10 + 3;
      }
      local_44 = (byte *)(((int)uVar10 >> 2) + *(int *)(iVar4 + 0x18) +
                         iVar14 * *(int *)(iVar4 + 0x10));
      local_c = 0;
      if (param_2[3] != 0) {
        do {
          iVar14 = 0;
          pbVar16 = local_44;
          if (param_2[2] != 0) {
            do {
              bVar2 = *local_10;
              local_10 = local_10 + 1;
              bVar8 = 0;
              local_54 = 0;
              do {
                local_48 = (byte)((puVar9[(int)(uint)bVar2 >> ((byte)local_54 & 0x1f) & 3] & 3) <<
                                 ((byte)local_54 & 0x1f));
                bVar8 = bVar8 | local_48;
                local_54 = local_54 + 2;
              } while (local_54 < 8);
              *pbVar16 = bVar8;
              pbVar16 = pbVar16 + 1;
              iVar14 = iVar14 + 4;
            } while (iVar14 < (int)(uint)param_2[2]);
          }
          local_44 = local_44 + *(int *)(iVar4 + 0x10);
          local_c = local_c + 1;
        } while (local_c < (int)(uint)param_2[3]);
      }
      break;
    case 1:
      puVar11 = (undefined1 *)(uVar10 + *(int *)(iVar4 + 0x18) + iVar14 * *(int *)(iVar4 + 0x10));
      local_c = 0;
      if (param_2[3] != 0) {
        do {
          iVar14 = 0;
          puVar17 = puVar11;
          if (param_2[2] != 0) {
            do {
              bVar2 = *local_10;
              local_10 = local_10 + 1;
              *puVar17 = *(undefined1 *)(puVar9 + (bVar2 >> 6));
              puVar17[1] = *(undefined1 *)(puVar9 + (bVar2 >> 4 & 3));
              puVar17[2] = *(undefined1 *)(puVar9 + (bVar2 >> 2 & 3));
              puVar17[3] = *(undefined1 *)(puVar9 + (bVar2 & 3));
              puVar17 = puVar17 + 4;
              iVar14 = iVar14 + 4;
            } while (iVar14 < (int)(uint)param_2[2]);
          }
          puVar11 = puVar11 + *(int *)(iVar4 + 0x10);
          local_c = local_c + 1;
        } while (local_c < (int)(uint)param_2[3]);
      }
      break;
    case 2:
    case 3:
      puVar12 = (undefined2 *)
                (*(int *)(iVar4 + 0x18) + uVar10 * 2 + iVar14 * *(int *)(iVar4 + 0x10));
      local_c = 0;
      if (param_2[3] != 0) {
        do {
          iVar14 = 0;
          puVar18 = puVar12;
          if (param_2[2] != 0) {
            do {
              bVar2 = *local_10;
              local_10 = local_10 + 1;
              *puVar18 = *(undefined2 *)(puVar9 + (bVar2 >> 6));
              puVar18[1] = *(undefined2 *)(puVar9 + (bVar2 >> 4 & 3));
              puVar18[2] = *(undefined2 *)(puVar9 + (bVar2 >> 2 & 3));
              puVar18[3] = *(undefined2 *)(puVar9 + (bVar2 & 3));
              puVar18 = puVar18 + 4;
              iVar14 = iVar14 + 4;
            } while (iVar14 < (int)(uint)param_2[2]);
          }
          puVar12 = (undefined2 *)((int)puVar12 + *(int *)(iVar4 + 0x10));
          local_c = local_c + 1;
        } while (local_c < (int)(uint)param_2[3]);
      }
      break;
    case 4:
      puVar13 = (undefined4 *)
                (*(int *)(iVar4 + 0x18) + uVar10 * 4 + iVar14 * *(int *)(iVar4 + 0x10));
      local_c = 0;
      if (param_2[3] != 0) {
        do {
          iVar14 = 0;
          puVar19 = puVar13;
          if (param_2[2] != 0) {
            do {
              bVar2 = *local_10;
              local_10 = local_10 + 1;
              *puVar19 = puVar9[bVar2 >> 6];
              puVar19[1] = puVar9[bVar2 >> 4 & 3];
              puVar19[2] = puVar9[bVar2 >> 2 & 3];
              puVar19[3] = puVar9[bVar2 & 3];
              puVar19 = puVar19 + 4;
              iVar14 = iVar14 + 4;
            } while (iVar14 < (int)(uint)param_2[2]);
          }
          puVar13 = (undefined4 *)((int)puVar13 + *(int *)(iVar4 + 0x10));
          local_c = local_c + 1;
        } while (local_c < (int)(uint)param_2[3]);
      }
    }
    uVar7 = 0;
  }
  return uVar7;
}

