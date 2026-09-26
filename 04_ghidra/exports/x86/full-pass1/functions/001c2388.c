/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c2388 */

void FUN_001c2388(int param_1)

{
  int iVar1;
  ushort uVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  ushort uVar6;
  int iVar7;
  ushort uVar8;
  short sVar9;
  ushort uVar10;
  short sVar11;
  undefined4 local_44;
  undefined4 local_40;
  ushort *local_24;
  ushort *local_20;
  ushort *local_1c;
  short local_14;
  
  iVar7 = _objc_msgSend(param_1,PTR_s_displayInfo_001f9610);
  piVar3 = *(int **)(param_1 + 0x1fc);
  local_44 = piVar3[8];
  local_40 = piVar3[9];
  if ((short)local_40 < (short)piVar3[0xd]) {
    uVar5 = local_40 >> 0x10;
    local_40 = CONCAT22((short)uVar5,(short)piVar3[0xd]);
  }
  if (*(short *)((int)piVar3 + 0x36) < (short)(local_40 >> 0x10)) {
    local_40 = local_40 & 0xffff | (uint)*(ushort *)((int)piVar3 + 0x36) << 0x10;
  }
  if ((short)local_44 < (short)piVar3[0xc]) {
    uVar5 = local_44 >> 0x10;
    local_44 = CONCAT22((short)uVar5,(short)piVar3[0xc]);
  }
  if (*(short *)((int)piVar3 + 0x32) < (short)(local_44 >> 0x10)) {
    local_44 = local_44 & 0xffff | (uint)*(ushort *)((int)piVar3 + 0x32) << 0x10;
  }
  piVar3[3] = local_44;
  piVar3[4] = local_40;
  local_1c = (ushort *)
             (*(int *)(iVar7 + 0x14) +
              ((int)(short)local_40 - (int)(short)piVar3[0xd]) * *(int *)(iVar7 + 8) * 2 +
             ((int)(short)local_44 - (int)(short)piVar3[0xc]) * 2);
  sVar9 = (short)(local_44 >> 0x10) - (short)local_44;
  iVar1 = *(int *)(iVar7 + 8) - (int)sVar9;
  local_20 = (ushort *)(piVar3 + 0x212);
  local_24 = (ushort *)
             ((int)piVar3 +
             (((int)(short)local_40 - (int)(short)piVar3[9]) * 0x10 +
             ((int)(short)local_44 - (int)(short)piVar3[8])) * 2 + *piVar3 * 0x200 + 0x48);
  sVar11 = (short)(local_40 >> 0x10);
  if (*(int *)(iVar7 + 0x18) == 2) {
    local_14 = (sVar11 - (short)local_40) + -1;
    if (local_14 != -1) {
      sVar11 = sVar9;
      do {
        while (sVar11 = sVar11 + -1, sVar11 != -1) {
          uVar2 = *local_1c;
          *local_20 = uVar2;
          local_20 = local_20 + 1;
          uVar6 = *local_24;
          local_24 = local_24 + 1;
          if (uVar6 == 0) {
            local_1c = local_1c + 1;
          }
          else {
            uVar10 = ~uVar6 & 0xf;
            if (uVar10 == 0) {
              *local_1c = uVar6;
            }
            else {
              *local_1c = (((uVar2 & 0xf0f0) >> 4) * uVar10 + 0xf0f & 0xf0f0 |
                          (ushort)((int)((uVar2 & 0xf0f) * (uint)uVar10 + 0xf0f) >> 4) & 0xf0f) +
                          uVar6;
            }
            local_1c = local_1c + 1;
          }
        }
        local_24 = local_24 + (short)(0x10 - sVar9);
        local_1c = local_1c + iVar1;
        local_14 = local_14 + -1;
        sVar11 = sVar9;
      } while (local_14 != -1);
    }
  }
  else {
    iVar7 = *(int *)(param_1 + 0x200);
    if (((iVar7 != 0) && (iVar4 = *(int *)(param_1 + 0x204), iVar4 != 0)) &&
       (local_14 = (sVar11 - (short)local_40) + -1, -1 < local_14)) {
      sVar11 = sVar9;
      do {
        while (sVar11 = sVar11 + -1, -1 < sVar11) {
          uVar2 = *local_1c;
          *local_20 = uVar2;
          local_20 = local_20 + 1;
          uVar6 = *local_24;
          local_24 = local_24 + 1;
          if (uVar6 == 0) {
            local_1c = local_1c + 1;
          }
          else {
            uVar10 = ~uVar6 & 0xf;
            if (uVar10 == 0) {
              *local_1c = (ushort)*(byte *)(((uVar6 & 0xf0) >> 4) + iVar7) |
                          (ushort)*(byte *)(((uVar6 & 0xf00) >> 8) + iVar7) << 5 |
                          (ushort)*(byte *)((uint)(uVar6 >> 0xc) + iVar7) << 10;
              local_1c = local_1c + 1;
            }
            else {
              uVar8 = (ushort)*(byte *)((uVar2 & 0x1f) + iVar4) << 4 |
                      (ushort)*(byte *)(((uVar2 & 0x3e0) >> 5) + iVar4) << 8 | 0xf;
              uVar6 = uVar6 + (((ushort)(uVar8 & 0xf0f0 |
                                        (ushort)*(byte *)(((uVar2 & 0x7c00) >> 10) + iVar4) << 0xc)
                               >> 4) * uVar10 + 0xf0f & 0xf0f0 |
                              (ushort)((int)((uVar8 & 0xf0f) * (uint)uVar10 + 0xf0f) >> 4) & 0xf0f);
              *local_1c = (ushort)*(byte *)((uVar6 >> 4 & 0xf) + iVar7) |
                          (ushort)*(byte *)((uVar6 >> 8 & 0xf) + iVar7) << 5 |
                          (ushort)*(byte *)((uint)(uVar6 >> 0xc) + iVar7) << 10;
              local_1c = local_1c + 1;
            }
          }
        }
        local_24 = local_24 + (short)(0x10 - sVar9);
        local_1c = local_1c + iVar1;
        local_14 = local_14 + -1;
        sVar11 = sVar9;
      } while (-1 < local_14);
    }
  }
  return;
}

