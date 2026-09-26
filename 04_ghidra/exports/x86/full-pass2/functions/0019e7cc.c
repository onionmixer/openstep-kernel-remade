/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0019e7cc */

undefined4 FUN_0019e7cc(int param_1,ushort *param_2)

{
  char cVar1;
  ushort uVar2;
  int iVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  undefined4 *puVar10;
  uint uVar11;
  int iVar12;
  byte *pbVar13;
  undefined2 *puVar14;
  int *piVar15;
  int local_58;
  byte *local_54;
  int local_2c;
  int local_28;
  byte local_20;
  int local_1c;
  undefined2 local_14;
  
  iVar3 = *(int *)(param_1 + 0x1c);
  iVar9 = (uint)param_2[1] + (*(int *)(iVar3 + 8) + -0x1e0) / 2;
  uVar11 = (uint)*param_2 + (*(int *)(iVar3 + 4) + -0x280) / 2 & 0xfffffffc;
  uVar2 = param_2[2];
  param_2[2] = uVar2 & 0xfffc;
  if ((*(int *)(iVar3 + 4) < (int)((uVar2 & 0xfffc) + uVar11)) ||
     (*(int *)(iVar3 + 8) < (int)((uint)param_2[3] + iVar9))) {
    uVar7 = 0xffffffff;
  }
  else {
    puVar10 = (undefined4 *)0x0;
    switch(*(undefined4 *)(*(int *)(param_1 + 0x1c) + 0x1c)) {
    case 0:
      puVar10 = (undefined4 *)&DAT_001e4838;
      break;
    case 1:
      puVar10 = (undefined4 *)&DAT_001e4848;
      break;
    case 2:
    case 3:
      local_1c = 0x10;
      break;
    case 4:
      local_1c = 0x20;
      break;
    default:
                    /* WARNING: Subroutine does not return */
      _panic(s_FBConsole_Fill__bogus_bitsPerPix_001e4868);
    }
    if (puVar10 == (undefined4 *)0x0) {
      local_58._0_1_ = 0;
      local_20 = 0;
      bVar4 = 0;
      local_54 = (byte *)0xffffffff;
      local_28 = -1;
      local_2c = -1;
      iVar12 = 0;
      bVar5 = 0;
      bVar6 = 0;
      if (0 < local_1c) {
        do {
          local_20 = bVar6;
          local_58._0_1_ = bVar5;
          cVar1 = *(char *)(iVar12 + *(int *)(param_1 + 0x1c) + 0x24);
          if (cVar1 == 'G') {
            if (local_28 == -1) {
              local_28 = iVar12;
            }
            local_20 = local_20 + 1;
          }
          else if (cVar1 < 'H') {
            if (cVar1 == 'B') {
              if (local_2c == -1) {
                local_2c = iVar12;
              }
              bVar4 = bVar4 + 1;
            }
          }
          else if (cVar1 == 'R') {
            if (local_54 == (byte *)0xffffffff) {
              local_54 = (byte *)iVar12;
            }
            local_58._0_1_ = (byte)local_58 + 1;
          }
          iVar12 = iVar12 + 1;
          bVar5 = (byte)local_58;
          bVar6 = local_20;
        } while (iVar12 < local_1c);
      }
      iVar12 = 0;
      cVar1 = (char)local_1c;
      do {
        iVar8 = 3 - iVar12;
        (&DAT_001e4858)[iVar12] =
             (((1 << ((byte)local_58 & 0x1f)) + -1) * iVar8) / 3 <<
             ((cVar1 - (char)local_54) - (byte)local_58 & 0x1f) |
             (((1 << (local_20 & 0x1f)) + -1) * iVar8) / 3 <<
             ((cVar1 - (char)local_28) - local_20 & 0x1f) |
             (((1 << (bVar4 & 0x1f)) + -1) * iVar8) / 3 << ((cVar1 - (char)local_2c) - bVar4 & 0x1f)
        ;
        iVar12 = iVar12 + 1;
      } while (iVar12 < 4);
      puVar10 = &DAT_001e4858;
    }
    iVar12 = puVar10[*(uint *)(param_2 + 4) & 3];
    local_14._0_1_ = (byte)iVar12;
    switch(*(undefined4 *)(iVar3 + 0x1c)) {
    case 0:
      if ((int)uVar11 < 0) {
        uVar11 = uVar11 + 3;
      }
      pbVar13 = (byte *)(((int)uVar11 >> 2) + *(int *)(iVar3 + 0x18) +
                        iVar9 * *(int *)(iVar3 + 0x10));
      local_14._0_1_ =
           (byte)(iVar12 << 2) | (byte)local_14 | (byte)(iVar12 << 4) | (byte)(iVar12 << 6);
      iVar9 = 0;
      if (param_2[3] != 0) {
        do {
          local_58 = 0;
          local_54 = pbVar13;
          if (param_2[2] != 0) {
            do {
              *local_54 = (byte)local_14;
              local_54 = local_54 + 1;
              local_58 = local_58 + 4;
            } while (local_58 < (int)(uint)param_2[2]);
          }
          pbVar13 = pbVar13 + *(int *)(iVar3 + 0x10);
          iVar9 = iVar9 + 1;
        } while (iVar9 < (int)(uint)param_2[3]);
      }
      break;
    case 1:
      pbVar13 = (byte *)(uVar11 + *(int *)(iVar3 + 0x18) + iVar9 * *(int *)(iVar3 + 0x10));
      iVar9 = 0;
      if (param_2[3] != 0) {
        do {
          local_58 = 0;
          local_54 = pbVar13;
          if (param_2[2] != 0) {
            do {
              *local_54 = (byte)local_14;
              local_54 = local_54 + 1;
              local_58 = local_58 + 1;
            } while (local_58 < (int)(uint)param_2[2]);
          }
          pbVar13 = pbVar13 + *(int *)(iVar3 + 0x10);
          iVar9 = iVar9 + 1;
        } while (iVar9 < (int)(uint)param_2[3]);
      }
      break;
    case 2:
    case 3:
      puVar14 = (undefined2 *)(*(int *)(iVar3 + 0x18) + uVar11 * 2 + iVar9 * *(int *)(iVar3 + 0x10))
      ;
      iVar9 = 0;
      if (param_2[3] != 0) {
        local_14 = (undefined2)iVar12;
        do {
          local_58 = 0;
          local_54 = (byte *)puVar14;
          if (param_2[2] != 0) {
            do {
              *(undefined2 *)local_54 = local_14;
              local_54 = (byte *)((int)local_54 + 2);
              local_58 = local_58 + 1;
            } while (local_58 < (int)(uint)param_2[2]);
          }
          puVar14 = (undefined2 *)((int)puVar14 + *(int *)(iVar3 + 0x10));
          iVar9 = iVar9 + 1;
        } while (iVar9 < (int)(uint)param_2[3]);
      }
      break;
    case 4:
      piVar15 = (int *)(*(int *)(iVar3 + 0x18) + uVar11 * 4 + iVar9 * *(int *)(iVar3 + 0x10));
      iVar9 = 0;
      if (param_2[3] != 0) {
        do {
          local_58 = 0;
          local_54 = (byte *)piVar15;
          if (param_2[2] != 0) {
            do {
              *(int *)local_54 = iVar12;
              local_54 = (byte *)((int)local_54 + 4);
              local_58 = local_58 + 1;
            } while (local_58 < (int)(uint)param_2[2]);
          }
          piVar15 = (int *)((int)piVar15 + *(int *)(iVar3 + 0x10));
          iVar9 = iVar9 + 1;
        } while (iVar9 < (int)(uint)param_2[3]);
      }
    }
    uVar7 = 0;
  }
  return uVar7;
}

