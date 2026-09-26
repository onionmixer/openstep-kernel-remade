/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c27b4 */

void FUN_001c27b4(int param_1)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  byte bVar7;
  short sVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  short sVar12;
  short sVar13;
  undefined4 local_44;
  undefined4 local_40;
  short local_3c;
  byte *local_30;
  byte *local_2c;
  byte local_28;
  byte *local_24;
  byte *local_20;
  short local_14;
  
  iVar10 = *(int *)(param_1 + 0x208);
  iVar3 = *(int *)(param_1 + 0x20c);
  iVar5 = _objc_msgSend(param_1,PTR_s_displayInfo_001f9610);
  piVar4 = *(int **)(param_1 + 0x1fc);
  local_44 = piVar4[8];
  local_40 = piVar4[9];
  if ((short)local_40 < (short)piVar4[0xd]) {
    uVar11 = local_40 >> 0x10;
    local_40 = CONCAT22((short)uVar11,(short)piVar4[0xd]);
  }
  if (*(short *)((int)piVar4 + 0x36) < (short)(local_40 >> 0x10)) {
    local_40 = local_40 & 0xffff | (uint)*(ushort *)((int)piVar4 + 0x36) << 0x10;
  }
  if ((short)local_44 < (short)piVar4[0xc]) {
    uVar11 = local_44 >> 0x10;
    local_44 = CONCAT22((short)uVar11,(short)piVar4[0xc]);
  }
  if (*(short *)((int)piVar4 + 0x32) < (short)(local_44 >> 0x10)) {
    local_44 = local_44 & 0xffff | (uint)*(ushort *)((int)piVar4 + 0x32) << 0x10;
  }
  piVar4[3] = local_44;
  piVar4[4] = local_40;
  local_20 = (byte *)(((int)(short)local_40 - (int)(short)piVar4[0xd]) * *(int *)(iVar5 + 8) +
                      *(int *)(iVar5 + 0x14) + ((int)(short)local_44 - (int)(short)piVar4[0xc]));
  sVar8 = (short)(local_44 >> 0x10) - (short)local_44;
  iVar1 = *(int *)(iVar5 + 8) - (int)sVar8;
  sVar13 = 0x10 - sVar8;
  local_24 = (byte *)(piVar4 + 0x212);
  local_3c = ((short)local_40 - (short)piVar4[9]) * 0x10;
  iVar9 = (int)(short)(((short)local_44 - (short)piVar4[8]) + local_3c);
  local_2c = (byte *)((int)piVar4 + iVar9 + *piVar4 * 0x100 + 0x48);
  local_30 = (byte *)((int)piVar4 + iVar9 + *piVar4 * 0x100 + 0x448);
  local_14 = (short)(local_40 >> 0x10);
  if (*(int *)(iVar5 + 0x1c) == 1) {
    local_14 = (local_14 - (short)local_40) + -1;
    if (-1 < local_14) {
      sVar12 = sVar8;
      do {
        while (-1 < (short)(sVar12 + -1)) {
          bVar7 = *local_20;
          *local_24 = bVar7;
          local_24 = local_24 + 1;
          bVar2 = *local_2c;
          local_2c = local_2c + 1;
          iVar10 = (uint)bVar7 * (0xff - (uint)*local_30);
          local_30 = local_30 + 1;
          *local_20 = bVar2 + (char)((uint)((iVar10 >> 8) + 1 + iVar10) >> 8);
          local_20 = local_20 + 1;
          sVar12 = sVar12 + -1;
        }
        local_2c = local_2c + sVar13;
        local_30 = local_30 + sVar13;
        local_20 = local_20 + iVar1;
        local_14 = local_14 + -1;
        sVar12 = sVar8;
      } while (-1 < local_14);
    }
  }
  else {
    local_14 = local_14 - (short)local_40;
    while (local_14 = local_14 + -1, sVar12 = sVar8, -1 < local_14) {
      while (-1 < (short)(sVar12 + -1)) {
        *local_24 = *local_20;
        if (*local_30 != 0) {
          local_28 = *local_2c;
          bVar7 = ~*local_30;
          if (bVar7 != 0) {
            uVar11 = *(uint *)(iVar10 + (uint)*local_20 * 4);
            uVar6 = ((uVar11 & 0xff00ff00) >> 8) * (uint)bVar7;
            uVar11 = (uVar11 & 0xff00ff) * (uint)bVar7;
            uVar11 = (*(uint *)(iVar10 + (uint)local_28 * 4) & 0xffffff00) +
                     (((uVar6 & 0xff00ff00) >> 8) + 0x10001 + uVar6 & 0xff00ff00 |
                     ((uVar11 & 0xff00ff00) >> 8) + 0x10001 + uVar11 >> 8 & 0xff00ff);
            if (((uVar11 ^ uVar11 >> 8) & 0xffff00) == 0) {
              local_28 = *(byte *)(iVar3 + 0x300 + (uVar11 >> 0x18));
            }
            else {
              local_28 = *(char *)((uVar11 >> 0x18) + iVar3) +
                         *(char *)(iVar3 + 0x100 + (uVar11 >> 0x10 & 0xff)) +
                         *(char *)(iVar3 + 0x200 + (uVar11 >> 8 & 0xff));
            }
          }
          *local_20 = local_28;
        }
        local_24 = local_24 + 1;
        local_30 = local_30 + 1;
        local_2c = local_2c + 1;
        local_20 = local_20 + 1;
        sVar12 = sVar12 + -1;
      }
      local_2c = local_2c + sVar13;
      local_30 = local_30 + sVar13;
      local_20 = local_20 + iVar1;
    }
  }
  return;
}

