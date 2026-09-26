/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c2b20 */

void FUN_001c2b20(int param_1)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint *puVar9;
  undefined4 local_34;
  undefined4 local_30;
  uint *local_28;
  uint *local_24;
  int local_14;
  
  iVar5 = _objc_msgSend(param_1,PTR_s_displayInfo_001f9610);
  piVar2 = *(int **)(param_1 + 0x1fc);
  local_34 = piVar2[8];
  local_30 = piVar2[9];
  if ((short)local_30 < (short)piVar2[0xd]) {
    uVar4 = local_30 >> 0x10;
    local_30 = CONCAT22((short)uVar4,(short)piVar2[0xd]);
  }
  if (*(short *)((int)piVar2 + 0x36) < (short)(local_30 >> 0x10)) {
    local_30 = local_30 & 0xffff | (uint)*(ushort *)((int)piVar2 + 0x36) << 0x10;
  }
  if ((short)local_34 < (short)piVar2[0xc]) {
    uVar4 = local_34 >> 0x10;
    local_34 = CONCAT22((short)uVar4,(short)piVar2[0xc]);
  }
  if (*(short *)((int)piVar2 + 0x32) < (short)(local_34 >> 0x10)) {
    local_34 = local_34 & 0xffff | (uint)*(ushort *)((int)piVar2 + 0x32) << 0x10;
  }
  piVar2[3] = local_34;
  piVar2[4] = local_30;
  local_14 = (int)(short)local_30;
  iVar6 = (int)(short)local_34;
  puVar9 = (uint *)(*(int *)(iVar5 + 0x14) +
                    (local_14 - (short)piVar2[0xd]) * *(int *)(iVar5 + 8) * 4 +
                   (iVar6 - (short)piVar2[0xc]) * 4);
  iVar8 = ((int)local_34 >> 0x10) - iVar6;
  iVar1 = *(int *)(iVar5 + 8) - iVar8;
  local_24 = (uint *)(piVar2 + 0x412);
  local_28 = (uint *)(piVar2 + *piVar2 * 0x100 +
                               (local_14 - (short)piVar2[9]) * 0x10 + (iVar6 - (short)piVar2[8]) +
                               0x12);
  if ((*(char *)(iVar5 + 0x20) == 'A') || (*(char *)(iVar5 + 0x20) == '-')) {
    local_14 = ((int)local_30 >> 0x10) - local_14;
    while (local_14 = local_14 + -1, iVar5 = iVar8, local_14 != -1) {
      while (iVar5 + -1 != -1) {
        uVar3 = *puVar9;
        *local_24 = uVar3;
        local_24 = local_24 + 1;
        uVar4 = *local_28;
        local_28 = local_28 + 1;
        if (uVar4 >> 0x18 != 0) {
          if (uVar4 >> 0x18 == 0xff) {
            *puVar9 = uVar4;
          }
          else {
            uVar3 = uVar3 << 8;
            uVar7 = (uint)(byte)~(byte)(uVar4 >> 0x18);
            *puVar9 = (((uVar3 & 0xff00ff00) >> 8) * uVar7 + 0xff00ff & 0xff00ff00 |
                      (uVar3 & 0xff00ff) * uVar7 + 0xff00ff >> 8 & 0xff00ff) + uVar4 * 0x100 >> 8 |
                      0xff000000;
          }
        }
        puVar9 = puVar9 + 1;
        iVar5 = iVar5 + -1;
      }
      local_28 = local_28 + (0x10 - iVar8);
      puVar9 = puVar9 + iVar1;
    }
  }
  else {
    local_14 = ((int)local_30 >> 0x10) - local_14;
    while (local_14 = local_14 + -1, iVar5 = iVar8, local_14 != -1) {
      while (iVar5 + -1 != -1) {
        uVar4 = *puVar9;
        *local_24 = uVar4;
        local_24 = local_24 + 1;
        uVar3 = *local_28;
        local_28 = local_28 + 1;
        if ((uVar3 & 0xff) != 0) {
          if ((uVar3 & 0xff) == 0xff) {
            *puVar9 = uVar3;
          }
          else {
            *puVar9 = (((uVar4 & 0xff00ff00) >> 8) * (uint)(byte)~(byte)uVar3 + 0xff00ff &
                       0xff00ff00 |
                      (uVar4 & 0xff00ff) * (uint)(byte)~(byte)uVar3 + 0xff00ff >> 8 & 0xff00ff) +
                      uVar3;
          }
        }
        puVar9 = puVar9 + 1;
        iVar5 = iVar5 + -1;
      }
      local_28 = local_28 + (0x10 - iVar8);
      puVar9 = puVar9 + iVar1;
    }
  }
  return;
}

