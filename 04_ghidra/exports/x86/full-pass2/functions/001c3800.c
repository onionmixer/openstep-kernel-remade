/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c3800 */

int FUN_001c3800(int param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4)

{
  char cVar1;
  undefined4 *puVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined1 *puVar9;
  undefined4 *puVar10;
  undefined2 *puVar11;
  undefined4 *puVar12;
  short sVar13;
  short sVar14;
  undefined2 *puVar15;
  undefined1 *puVar16;
  short local_2c;
  short local_28;
  
  puVar2 = *(undefined4 **)(param_1 + 0x1fc);
  iVar7 = _ev_try_lock(puVar2 + 1);
  if (iVar7 == 0) {
    return param_1;
  }
  *puVar2 = param_4;
  puVar2[7] = *param_3;
  if (*(char *)((int)puVar2 + 10) != '\0') {
    piVar3 = *(int **)(param_1 + 0x1fc);
    sVar13 = (short)piVar3[7] - (short)piVar3[*piVar3 + 0xe];
    sVar14 = *(short *)((int)piVar3 + 0x1e) - (short)((uint)piVar3[*piVar3 + 0xe] >> 0x10);
    cVar1 = '\0';
    if ((((sVar13 < *(short *)((int)piVar3 + 0x16)) && ((short)piVar3[5] < (short)(sVar13 + 0x10)))
        && (sVar14 < *(short *)((int)piVar3 + 0x1a))) && ((short)piVar3[6] < (short)(sVar14 + 0x10))
       ) {
      cVar1 = '\x01';
    }
    if (cVar1 != *(char *)((int)piVar3 + 0xb)) {
      *(char *)((int)piVar3 + 0xb) = cVar1;
      if (*(char *)((int)piVar3 + 0xb) == '\0') {
        iVar7 = *(int *)(param_1 + 0x1fc);
        if ((*(char *)(iVar7 + 8) != '\0') &&
           (*(char *)(iVar7 + 8) = *(char *)(iVar7 + 8) + -1, *(char *)(iVar7 + 8) == '\0')) {
          piVar3 = *(int **)(param_1 + 0x1fc);
          iVar7 = piVar3[*piVar3 + 0xe];
          *(short *)(piVar3 + 8) = (short)piVar3[7] - (short)iVar7;
          *(short *)((int)piVar3 + 0x22) = (short)piVar3[8] + 0x10;
          *(short *)(piVar3 + 9) = *(short *)((int)piVar3 + 0x1e) - (short)((uint)iVar7 >> 0x10);
          *(short *)((int)piVar3 + 0x26) = (short)piVar3[9] + 0x10;
          iVar7 = _objc_msgSend(param_1,PTR_s_displayInfo_001f9610);
          uVar4 = *(uint *)(iVar7 + 0x18);
          if (uVar4 < 4) {
            if ((uVar4 < 2) && (uVar4 == 1)) {
              FUN_001c27b4(param_1);
            }
            else {
LAB_001c3bd5:
              FUN_001c2388(param_1);
            }
          }
          else {
            if (uVar4 != 4) goto LAB_001c3bd5;
            FUN_001c2b20(param_1);
          }
          piVar3[10] = piVar3[8];
          piVar3[0xb] = piVar3[9];
        }
      }
      else {
        cVar1 = *(char *)(*(int *)(param_1 + 0x1fc) + 8);
        *(char *)(*(int *)(param_1 + 0x1fc) + 8) = cVar1 + '\x01';
        if (cVar1 == '\0') {
          iVar7 = _objc_msgSend(param_1,PTR_s_displayInfo_001f9610);
          uVar4 = *(uint *)(iVar7 + 0x18);
          if (uVar4 < 4) {
            if ((uVar4 < 2) && (uVar4 == 1)) {
              iVar8 = _objc_msgSend(param_1,PTR_s_displayInfo_001f9610);
              iVar7 = *(int *)(param_1 + 0x1fc);
              iVar5 = *(int *)(iVar8 + 8);
              local_28 = (short)*(undefined4 *)(iVar7 + 0x10);
              local_2c = (short)*(undefined4 *)(iVar7 + 0xc);
              puVar9 = (undefined1 *)
                       (((int)local_2c - (int)*(short *)(iVar7 + 0x30)) +
                       ((int)local_28 - (int)*(short *)(iVar7 + 0x34)) * iVar5 +
                       *(int *)(iVar8 + 0x14));
              local_2c = (short)((uint)*(undefined4 *)(iVar7 + 0xc) >> 0x10) - local_2c;
              puVar16 = (undefined1 *)(iVar7 + 0x848);
              local_28 = (short)((uint)*(undefined4 *)(iVar7 + 0x10) >> 0x10) - local_28;
              while (local_28 = local_28 + -1, sVar13 = local_2c, local_28 != -1) {
                while ((short)(sVar13 + -1) != -1) {
                  *puVar9 = *puVar16;
                  puVar16 = puVar16 + 1;
                  puVar9 = puVar9 + 1;
                  sVar13 = sVar13 + -1;
                }
                puVar9 = puVar9 + (iVar5 - local_2c);
              }
            }
            else {
LAB_001c393d:
              iVar8 = _objc_msgSend(param_1,PTR_s_displayInfo_001f9610);
              iVar7 = *(int *)(param_1 + 0x1fc);
              iVar5 = *(int *)(iVar8 + 8);
              local_28 = (short)*(undefined4 *)(iVar7 + 0x10);
              local_2c = (short)*(undefined4 *)(iVar7 + 0xc);
              puVar11 = (undefined2 *)
                        (*(int *)(iVar8 + 0x14) +
                         ((int)local_28 - (int)*(short *)(iVar7 + 0x34)) * iVar5 * 2 +
                        ((int)local_2c - (int)*(short *)(iVar7 + 0x30)) * 2);
              local_2c = (short)((uint)*(undefined4 *)(iVar7 + 0xc) >> 0x10) - local_2c;
              puVar15 = (undefined2 *)(iVar7 + 0x848);
              local_28 = (short)((uint)*(undefined4 *)(iVar7 + 0x10) >> 0x10) - local_28;
              while (local_28 = local_28 + -1, sVar13 = local_2c, local_28 != -1) {
                while ((short)(sVar13 + -1) != -1) {
                  *puVar11 = *puVar15;
                  puVar15 = puVar15 + 1;
                  puVar11 = puVar11 + 1;
                  sVar13 = sVar13 + -1;
                }
                puVar11 = puVar11 + (iVar5 - local_2c);
              }
            }
          }
          else {
            if (uVar4 != 4) goto LAB_001c393d;
            iVar8 = _objc_msgSend(param_1,PTR_s_displayInfo_001f9610);
            iVar7 = *(int *)(param_1 + 0x1fc);
            iVar5 = *(int *)(iVar8 + 8);
            local_28 = (short)*(int *)(iVar7 + 0x10);
            local_2c = (short)*(int *)(iVar7 + 0xc);
            puVar12 = (undefined4 *)
                      (*(int *)(iVar8 + 0x14) +
                       ((int)local_28 - (int)*(short *)(iVar7 + 0x34)) * iVar5 * 4 +
                      ((int)local_2c - (int)*(short *)(iVar7 + 0x30)) * 4);
            iVar8 = (*(int *)(iVar7 + 0xc) >> 0x10) - (int)local_2c;
            puVar10 = (undefined4 *)(iVar7 + 0x1048);
            iVar7 = (*(int *)(iVar7 + 0x10) >> 0x10) - (int)local_28;
            while (iVar7 = iVar7 + -1, iVar6 = iVar8, iVar7 != -1) {
              while (iVar6 + -1 != -1) {
                *puVar12 = *puVar10;
                puVar10 = puVar10 + 1;
                puVar12 = puVar12 + 1;
                iVar6 = iVar6 + -1;
              }
              puVar12 = puVar12 + (iVar5 - iVar8);
            }
          }
        }
      }
    }
  }
  iVar7 = *(int *)(param_1 + 0x1fc);
  if ((*(char *)(iVar7 + 8) == '\0') ||
     (*(char *)(iVar7 + 8) = *(char *)(iVar7 + 8) + -1, *(char *)(iVar7 + 8) != '\0'))
  goto LAB_001c3cc0;
  piVar3 = *(int **)(param_1 + 0x1fc);
  iVar7 = piVar3[*piVar3 + 0xe];
  *(short *)(piVar3 + 8) = (short)piVar3[7] - (short)iVar7;
  *(short *)((int)piVar3 + 0x22) = (short)piVar3[8] + 0x10;
  *(short *)(piVar3 + 9) = *(short *)((int)piVar3 + 0x1e) - (short)((uint)iVar7 >> 0x10);
  *(short *)((int)piVar3 + 0x26) = (short)piVar3[9] + 0x10;
  iVar7 = _objc_msgSend(param_1,PTR_s_displayInfo_001f9610);
  uVar4 = *(uint *)(iVar7 + 0x18);
  if (uVar4 < 4) {
    if ((uVar4 < 2) && (uVar4 == 1)) {
      FUN_001c27b4(param_1);
    }
    else {
LAB_001c3c91:
      FUN_001c2388(param_1);
    }
  }
  else {
    if (uVar4 != 4) goto LAB_001c3c91;
    FUN_001c2b20(param_1);
  }
  piVar3[10] = piVar3[8];
  piVar3[0xb] = piVar3[9];
LAB_001c3cc0:
  _ev_unlock(puVar2 + 1);
  return param_1;
}

