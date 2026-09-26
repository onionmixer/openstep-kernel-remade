/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c30bc */

int FUN_001c30bc(int param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined1 *puVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  undefined2 *puVar11;
  short sVar12;
  short sVar13;
  char cVar14;
  undefined2 *puVar15;
  undefined1 *puVar16;
  short local_48;
  short local_44;
  
  puVar1 = *(undefined4 **)(param_1 + 0x1fc);
  iVar6 = _ev_try_lock(puVar1 + 1);
  if (iVar6 == 0) {
    return param_1;
  }
  *puVar1 = param_4;
  puVar1[7] = *param_3;
  cVar14 = *(char *)(puVar1 + 2);
  *(char *)(puVar1 + 2) = cVar14 + '\x01';
  if (cVar14 == '\0') {
    iVar6 = _objc_msgSend(param_1,PTR_s_displayInfo_001f9610);
    uVar2 = *(uint *)(iVar6 + 0x18);
    if (uVar2 < 4) {
      if ((uVar2 < 2) && (uVar2 == 1)) {
        iVar7 = _objc_msgSend(param_1,PTR_s_displayInfo_001f9610);
        iVar6 = *(int *)(param_1 + 0x1fc);
        iVar3 = *(int *)(iVar7 + 8);
        local_44 = (short)*(undefined4 *)(iVar6 + 0x10);
        local_48 = (short)*(undefined4 *)(iVar6 + 0xc);
        puVar8 = (undefined1 *)
                 (((int)local_48 - (int)*(short *)(iVar6 + 0x30)) +
                 ((int)local_44 - (int)*(short *)(iVar6 + 0x34)) * iVar3 + *(int *)(iVar7 + 0x14));
        local_48 = (short)((uint)*(undefined4 *)(iVar6 + 0xc) >> 0x10) - local_48;
        puVar16 = (undefined1 *)(iVar6 + 0x848);
        local_44 = (short)((uint)*(undefined4 *)(iVar6 + 0x10) >> 0x10) - local_44;
        while (local_44 = local_44 + -1, sVar12 = local_48, local_44 != -1) {
          while ((short)(sVar12 + -1) != -1) {
            *puVar8 = *puVar16;
            puVar16 = puVar16 + 1;
            puVar8 = puVar8 + 1;
            sVar12 = sVar12 + -1;
          }
          puVar8 = puVar8 + (iVar3 - local_48);
        }
      }
      else {
LAB_001c3145:
        iVar7 = _objc_msgSend(param_1,PTR_s_displayInfo_001f9610);
        iVar6 = *(int *)(param_1 + 0x1fc);
        iVar3 = *(int *)(iVar7 + 8);
        local_44 = (short)*(undefined4 *)(iVar6 + 0x10);
        local_48 = (short)*(undefined4 *)(iVar6 + 0xc);
        puVar11 = (undefined2 *)
                  (*(int *)(iVar7 + 0x14) +
                   ((int)local_44 - (int)*(short *)(iVar6 + 0x34)) * iVar3 * 2 +
                  ((int)local_48 - (int)*(short *)(iVar6 + 0x30)) * 2);
        local_48 = (short)((uint)*(undefined4 *)(iVar6 + 0xc) >> 0x10) - local_48;
        puVar15 = (undefined2 *)(iVar6 + 0x848);
        local_44 = (short)((uint)*(undefined4 *)(iVar6 + 0x10) >> 0x10) - local_44;
        while (local_44 = local_44 + -1, sVar12 = local_48, local_44 != -1) {
          while ((short)(sVar12 + -1) != -1) {
            *puVar11 = *puVar15;
            puVar15 = puVar15 + 1;
            puVar11 = puVar11 + 1;
            sVar12 = sVar12 + -1;
          }
          puVar11 = puVar11 + (iVar3 - local_48);
        }
      }
    }
    else {
      if (uVar2 != 4) goto LAB_001c3145;
      iVar7 = _objc_msgSend(param_1,PTR_s_displayInfo_001f9610);
      iVar6 = *(int *)(param_1 + 0x1fc);
      iVar3 = *(int *)(iVar7 + 8);
      local_44 = (short)*(int *)(iVar6 + 0x10);
      local_48 = (short)*(int *)(iVar6 + 0xc);
      puVar10 = (undefined4 *)
                (*(int *)(iVar7 + 0x14) +
                 ((int)local_44 - (int)*(short *)(iVar6 + 0x34)) * iVar3 * 4 +
                ((int)local_48 - (int)*(short *)(iVar6 + 0x30)) * 4);
      iVar7 = (*(int *)(iVar6 + 0xc) >> 0x10) - (int)local_48;
      puVar9 = (undefined4 *)(iVar6 + 0x1048);
      iVar6 = (*(int *)(iVar6 + 0x10) >> 0x10) - (int)local_44;
      while (iVar6 = iVar6 + -1, iVar5 = iVar7, iVar6 != -1) {
        while (iVar5 + -1 != -1) {
          *puVar10 = *puVar9;
          puVar9 = puVar9 + 1;
          puVar10 = puVar10 + 1;
          iVar5 = iVar5 + -1;
        }
        puVar10 = puVar10 + (iVar3 - iVar7);
      }
    }
  }
  if ((*(char *)((int)puVar1 + 9) != '\0') &&
     (*(undefined1 *)((int)puVar1 + 9) = 0, *(char *)(puVar1 + 2) != '\0')) {
    *(char *)(puVar1 + 2) = *(char *)(puVar1 + 2) + -1;
  }
  if (*(char *)((int)puVar1 + 10) != '\0') {
    piVar4 = *(int **)(param_1 + 0x1fc);
    sVar12 = (short)piVar4[7] - (short)piVar4[*piVar4 + 0xe];
    sVar13 = *(short *)((int)piVar4 + 0x1e) - (short)((uint)piVar4[*piVar4 + 0xe] >> 0x10);
    cVar14 = '\0';
    if ((((sVar12 < *(short *)((int)piVar4 + 0x16)) && ((short)piVar4[5] < (short)(sVar12 + 0x10)))
        && (sVar13 < *(short *)((int)piVar4 + 0x1a))) && ((short)piVar4[6] < (short)(sVar13 + 0x10))
       ) {
      cVar14 = '\x01';
    }
    if (cVar14 != *(char *)((int)piVar4 + 0xb)) {
      *(char *)((int)piVar4 + 0xb) = cVar14;
      if (*(char *)((int)piVar4 + 0xb) == '\0') {
        iVar6 = *(int *)(param_1 + 0x1fc);
        if ((*(char *)(iVar6 + 8) != '\0') &&
           (*(char *)(iVar6 + 8) = *(char *)(iVar6 + 8) + -1, *(char *)(iVar6 + 8) == '\0')) {
          piVar4 = *(int **)(param_1 + 0x1fc);
          iVar6 = piVar4[*piVar4 + 0xe];
          *(short *)(piVar4 + 8) = (short)piVar4[7] - (short)iVar6;
          *(short *)((int)piVar4 + 0x22) = (short)piVar4[8] + 0x10;
          *(short *)(piVar4 + 9) = *(short *)((int)piVar4 + 0x1e) - (short)((uint)iVar6 >> 0x10);
          *(short *)((int)piVar4 + 0x26) = (short)piVar4[9] + 0x10;
          iVar6 = _objc_msgSend(param_1,PTR_s_displayInfo_001f9610);
          uVar2 = *(uint *)(iVar6 + 0x18);
          if (uVar2 < 4) {
            if ((uVar2 < 2) && (uVar2 == 1)) {
              FUN_001c27b4(param_1);
            }
            else {
LAB_001c36f9:
              FUN_001c2388(param_1);
            }
          }
          else {
            if (uVar2 != 4) goto LAB_001c36f9;
            FUN_001c2b20(param_1);
          }
          piVar4[10] = piVar4[8];
          piVar4[0xb] = piVar4[9];
        }
      }
      else {
        cVar14 = *(char *)(*(int *)(param_1 + 0x1fc) + 8);
        *(char *)(*(int *)(param_1 + 0x1fc) + 8) = cVar14 + '\x01';
        if (cVar14 == '\0') {
          iVar6 = _objc_msgSend(param_1,PTR_s_displayInfo_001f9610);
          uVar2 = *(uint *)(iVar6 + 0x18);
          if (uVar2 < 4) {
            if ((uVar2 < 2) && (uVar2 == 1)) {
              iVar7 = _objc_msgSend(param_1,PTR_s_displayInfo_001f9610);
              iVar6 = *(int *)(param_1 + 0x1fc);
              iVar3 = *(int *)(iVar7 + 8);
              local_44 = (short)*(undefined4 *)(iVar6 + 0x10);
              local_48 = (short)*(undefined4 *)(iVar6 + 0xc);
              puVar8 = (undefined1 *)
                       (((int)local_48 - (int)*(short *)(iVar6 + 0x30)) +
                       ((int)local_44 - (int)*(short *)(iVar6 + 0x34)) * iVar3 +
                       *(int *)(iVar7 + 0x14));
              local_48 = (short)((uint)*(undefined4 *)(iVar6 + 0xc) >> 0x10) - local_48;
              puVar16 = (undefined1 *)(iVar6 + 0x848);
              local_44 = (short)((uint)*(undefined4 *)(iVar6 + 0x10) >> 0x10) - local_44;
              while (local_44 = local_44 + -1, sVar12 = local_48, local_44 != -1) {
                while ((short)(sVar12 + -1) != -1) {
                  *puVar8 = *puVar16;
                  puVar16 = puVar16 + 1;
                  puVar8 = puVar8 + 1;
                  sVar12 = sVar12 + -1;
                }
                puVar8 = puVar8 + (iVar3 - local_48);
              }
            }
            else {
LAB_001c3461:
              iVar7 = _objc_msgSend(param_1,PTR_s_displayInfo_001f9610);
              iVar6 = *(int *)(param_1 + 0x1fc);
              iVar3 = *(int *)(iVar7 + 8);
              local_44 = (short)*(undefined4 *)(iVar6 + 0x10);
              local_48 = (short)*(undefined4 *)(iVar6 + 0xc);
              puVar11 = (undefined2 *)
                        (*(int *)(iVar7 + 0x14) +
                         ((int)local_44 - (int)*(short *)(iVar6 + 0x34)) * iVar3 * 2 +
                        ((int)local_48 - (int)*(short *)(iVar6 + 0x30)) * 2);
              local_48 = (short)((uint)*(undefined4 *)(iVar6 + 0xc) >> 0x10) - local_48;
              puVar15 = (undefined2 *)(iVar6 + 0x848);
              local_44 = (short)((uint)*(undefined4 *)(iVar6 + 0x10) >> 0x10) - local_44;
              while (local_44 = local_44 + -1, sVar12 = local_48, local_44 != -1) {
                while ((short)(sVar12 + -1) != -1) {
                  *puVar11 = *puVar15;
                  puVar15 = puVar15 + 1;
                  puVar11 = puVar11 + 1;
                  sVar12 = sVar12 + -1;
                }
                puVar11 = puVar11 + (iVar3 - local_48);
              }
            }
          }
          else {
            if (uVar2 != 4) goto LAB_001c3461;
            iVar7 = _objc_msgSend(param_1,PTR_s_displayInfo_001f9610);
            iVar6 = *(int *)(param_1 + 0x1fc);
            iVar3 = *(int *)(iVar7 + 8);
            local_44 = (short)*(int *)(iVar6 + 0x10);
            local_48 = (short)*(int *)(iVar6 + 0xc);
            puVar10 = (undefined4 *)
                      (*(int *)(iVar7 + 0x14) +
                       ((int)local_44 - (int)*(short *)(iVar6 + 0x34)) * iVar3 * 4 +
                      ((int)local_48 - (int)*(short *)(iVar6 + 0x30)) * 4);
            iVar7 = (*(int *)(iVar6 + 0xc) >> 0x10) - (int)local_48;
            puVar9 = (undefined4 *)(iVar6 + 0x1048);
            iVar6 = (*(int *)(iVar6 + 0x10) >> 0x10) - (int)local_44;
            while (iVar6 = iVar6 + -1, iVar5 = iVar7, iVar6 != -1) {
              while (iVar5 + -1 != -1) {
                *puVar10 = *puVar9;
                puVar9 = puVar9 + 1;
                puVar10 = puVar10 + 1;
                iVar5 = iVar5 + -1;
              }
              puVar10 = puVar10 + (iVar3 - iVar7);
            }
          }
        }
      }
    }
  }
  if ((*(char *)(puVar1 + 2) == '\0') ||
     (*(char *)(puVar1 + 2) = *(char *)(puVar1 + 2) + -1, *(char *)(puVar1 + 2) != '\0'))
  goto LAB_001c37e4;
  piVar4 = *(int **)(param_1 + 0x1fc);
  iVar6 = piVar4[*piVar4 + 0xe];
  *(short *)(piVar4 + 8) = (short)piVar4[7] - (short)iVar6;
  *(short *)((int)piVar4 + 0x22) = (short)piVar4[8] + 0x10;
  *(short *)(piVar4 + 9) = *(short *)((int)piVar4 + 0x1e) - (short)((uint)iVar6 >> 0x10);
  *(short *)((int)piVar4 + 0x26) = (short)piVar4[9] + 0x10;
  iVar6 = _objc_msgSend(param_1,PTR_s_displayInfo_001f9610);
  uVar2 = *(uint *)(iVar6 + 0x18);
  if (uVar2 < 4) {
    if ((uVar2 < 2) && (uVar2 == 1)) {
      FUN_001c27b4(param_1);
    }
    else {
LAB_001c37b5:
      FUN_001c2388(param_1);
    }
  }
  else {
    if (uVar2 != 4) goto LAB_001c37b5;
    FUN_001c2b20(param_1);
  }
  piVar4[10] = piVar4[8];
  piVar4[0xb] = piVar4[9];
LAB_001c37e4:
  _ev_unlock(puVar1 + 1);
  return param_1;
}

