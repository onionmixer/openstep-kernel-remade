/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c2e1c */

int FUN_001c2e1c(int param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  short sVar5;
  int iVar6;
  int iVar7;
  undefined1 *puVar8;
  undefined4 *puVar9;
  undefined2 *puVar10;
  undefined4 *puVar11;
  undefined2 *puVar12;
  undefined1 *puVar13;
  short local_24;
  short local_20;
  
  iVar6 = _ev_try_lock(*(int *)(param_1 + 0x1fc) + 4);
  if (iVar6 == 0) {
    return param_1;
  }
  cVar1 = *(char *)(*(int *)(param_1 + 0x1fc) + 8);
  *(char *)(*(int *)(param_1 + 0x1fc) + 8) = cVar1 + '\x01';
  if (cVar1 == '\0') {
    iVar6 = _objc_msgSend(param_1,PTR_s_displayInfo_001f9610);
    uVar2 = *(uint *)(iVar6 + 0x18);
    if (uVar2 < 4) {
      if ((uVar2 < 2) && (uVar2 == 1)) {
        iVar7 = _objc_msgSend(param_1,PTR_s_displayInfo_001f9610);
        iVar6 = *(int *)(param_1 + 0x1fc);
        iVar3 = *(int *)(iVar7 + 8);
        local_20 = (short)*(undefined4 *)(iVar6 + 0x10);
        local_24 = (short)*(undefined4 *)(iVar6 + 0xc);
        puVar8 = (undefined1 *)
                 (((int)local_24 - (int)*(short *)(iVar6 + 0x30)) +
                 ((int)local_20 - (int)*(short *)(iVar6 + 0x34)) * iVar3 + *(int *)(iVar7 + 0x14));
        local_24 = (short)((uint)*(undefined4 *)(iVar6 + 0xc) >> 0x10) - local_24;
        puVar13 = (undefined1 *)(iVar6 + 0x848);
        local_20 = (short)((uint)*(undefined4 *)(iVar6 + 0x10) >> 0x10) - local_20;
        while (local_20 = local_20 + -1, sVar5 = local_24, local_20 != -1) {
          while ((short)(sVar5 + -1) != -1) {
            *puVar8 = *puVar13;
            puVar13 = puVar13 + 1;
            puVar8 = puVar8 + 1;
            sVar5 = sVar5 + -1;
          }
          puVar8 = puVar8 + (iVar3 - local_24);
        }
        goto LAB_001c309b;
      }
    }
    else if (uVar2 == 4) {
      iVar7 = _objc_msgSend(param_1,PTR_s_displayInfo_001f9610);
      iVar6 = *(int *)(param_1 + 0x1fc);
      iVar3 = *(int *)(iVar7 + 8);
      local_20 = (short)*(int *)(iVar6 + 0x10);
      local_24 = (short)*(int *)(iVar6 + 0xc);
      puVar11 = (undefined4 *)
                (*(int *)(iVar7 + 0x14) +
                 ((int)local_20 - (int)*(short *)(iVar6 + 0x34)) * iVar3 * 4 +
                ((int)local_24 - (int)*(short *)(iVar6 + 0x30)) * 4);
      iVar7 = (*(int *)(iVar6 + 0xc) >> 0x10) - (int)local_24;
      puVar9 = (undefined4 *)(iVar6 + 0x1048);
      iVar6 = (*(int *)(iVar6 + 0x10) >> 0x10) - (int)local_20;
      while (iVar6 = iVar6 + -1, iVar4 = iVar7, iVar6 != -1) {
        while (iVar4 + -1 != -1) {
          *puVar11 = *puVar9;
          puVar9 = puVar9 + 1;
          puVar11 = puVar11 + 1;
          iVar4 = iVar4 + -1;
        }
        puVar11 = puVar11 + (iVar3 - iVar7);
      }
      goto LAB_001c309b;
    }
    iVar7 = _objc_msgSend(param_1,PTR_s_displayInfo_001f9610);
    iVar6 = *(int *)(param_1 + 0x1fc);
    iVar3 = *(int *)(iVar7 + 8);
    local_20 = (short)*(undefined4 *)(iVar6 + 0x10);
    local_24 = (short)*(undefined4 *)(iVar6 + 0xc);
    puVar10 = (undefined2 *)
              (*(int *)(iVar7 + 0x14) + ((int)local_20 - (int)*(short *)(iVar6 + 0x34)) * iVar3 * 2
              + ((int)local_24 - (int)*(short *)(iVar6 + 0x30)) * 2);
    local_24 = (short)((uint)*(undefined4 *)(iVar6 + 0xc) >> 0x10) - local_24;
    puVar12 = (undefined2 *)(iVar6 + 0x848);
    local_20 = (short)((uint)*(undefined4 *)(iVar6 + 0x10) >> 0x10) - local_20;
    while (local_20 = local_20 + -1, sVar5 = local_24, local_20 != -1) {
      while ((short)(sVar5 + -1) != -1) {
        *puVar10 = *puVar12;
        puVar12 = puVar12 + 1;
        puVar10 = puVar10 + 1;
        sVar5 = sVar5 + -1;
      }
      puVar10 = puVar10 + (iVar3 - local_24);
    }
  }
LAB_001c309b:
  _ev_unlock(*(int *)(param_1 + 0x1fc) + 4);
  return param_1;
}

