/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001cfa50 */

void FUN_001cfa50(int param_1)

{
  int *piVar1;
  uint *puVar2;
  int *piVar3;
  int *piVar4;
  uint *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint local_24;
  uint local_18;
  uint local_10;
  uint local_8;
  
  iVar9 = *(int *)(param_1 + 4);
  iVar6 = _getsectdatafromheaderinfo(param_1,"__OBJC","__message_refs",&local_8);
  if (iVar6 != 0) {
    uVar11 = local_8 >> 2;
    uVar10 = 0;
    if (uVar11 != 0) {
      do {
        iVar7 = __sel_registerName(*(undefined4 *)(iVar6 + uVar10 * 4));
        if (*(int *)(iVar6 + uVar10 * 4) != iVar7) {
          *(int *)(iVar6 + uVar10 * 4) = iVar7;
        }
        uVar10 = uVar10 + 1;
      } while (uVar10 < uVar11);
    }
  }
  for (local_10 = 0; local_10 < *(uint *)(param_1 + 8); local_10 = local_10 + 1) {
    if (*(int *)(iVar9 + 0xc + local_10 * 0x10) != 0) {
      local_18 = 0;
      if (*(short *)(*(int *)(iVar9 + 0xc + local_10 * 0x10) + 8) != 0) {
        do {
          piVar3 = *(int **)(*(int *)(iVar9 + 0xc + local_10 * 0x10) + 0xc + local_18 * 4);
          if (piVar3[7] != 0) {
            piVar4 = (int *)piVar3[7];
            iVar6 = *piVar4;
            while (iVar6 != 0) {
              piVar4 = (int *)*piVar4;
              iVar6 = *piVar4;
            }
            uVar10 = 0;
            if (piVar4[1] != 0) {
              do {
                piVar1 = piVar4 + uVar10 * 3 + 2;
                iVar6 = __sel_registerName(*piVar1);
                if (*piVar1 != iVar6) {
                  *piVar1 = iVar6;
                }
                uVar10 = uVar10 + 1;
              } while (uVar10 < (uint)piVar4[1]);
            }
          }
          if (*(int *)(*piVar3 + 0x1c) != 0) {
            piVar3 = *(int **)(*piVar3 + 0x1c);
            iVar6 = *piVar3;
            while (iVar6 != 0) {
              piVar3 = (int *)*piVar3;
              iVar6 = *piVar3;
            }
            uVar10 = 0;
            if (piVar3[1] != 0) {
              do {
                piVar4 = piVar3 + uVar10 * 3 + 2;
                iVar6 = __sel_registerName(*piVar4);
                if (*piVar4 != iVar6) {
                  *piVar4 = iVar6;
                }
                uVar10 = uVar10 + 1;
              } while (uVar10 < (uint)piVar3[1]);
            }
          }
          local_18 = local_18 + 1;
        } while (local_18 < *(ushort *)(*(int *)(iVar9 + 0xc + local_10 * 0x10) + 8));
      }
      iVar6 = *(int *)(iVar9 + 0xc + local_10 * 0x10);
      local_18 = (uint)*(ushort *)(iVar6 + 8);
      if (local_18 < *(ushort *)(iVar6 + 10) + local_18) {
        do {
          iVar6 = *(int *)(*(int *)(iVar9 + 0xc + local_10 * 0x10) + 0xc + local_18 * 4);
          if (*(int *)(iVar6 + 8) != 0) {
            iVar7 = *(int *)(iVar6 + 8);
            uVar10 = 0;
            if (*(int *)(iVar7 + 4) != 0) {
              do {
                piVar3 = (int *)(iVar7 + 8 + uVar10 * 0xc);
                iVar8 = __sel_registerName(*piVar3);
                if (*piVar3 != iVar8) {
                  *piVar3 = iVar8;
                }
                uVar10 = uVar10 + 1;
              } while (uVar10 < *(uint *)(iVar7 + 4));
            }
          }
          if (*(int *)(iVar6 + 0xc) != 0) {
            iVar6 = *(int *)(iVar6 + 0xc);
            uVar10 = 0;
            if (*(int *)(iVar6 + 4) != 0) {
              do {
                piVar3 = (int *)(iVar6 + 8 + uVar10 * 0xc);
                iVar7 = __sel_registerName(*piVar3);
                if (*piVar3 != iVar7) {
                  *piVar3 = iVar7;
                }
                uVar10 = uVar10 + 1;
              } while (uVar10 < *(uint *)(iVar6 + 4));
            }
          }
          local_18 = local_18 + 1;
          iVar6 = *(int *)(iVar9 + 0xc + local_10 * 0x10);
        } while (local_18 < (uint)*(ushort *)(iVar6 + 10) + (uint)*(ushort *)(iVar6 + 8));
      }
    }
  }
  iVar9 = _getsectdatafromheaderinfo(param_1,"__OBJC","__protocol",&local_8);
  if (iVar9 != 0) {
    for (local_24 = 0; local_24 < local_8 / 0x14; local_24 = local_24 + 1) {
      if (*(int *)(iVar9 + 0xc + local_24 * 0x14) != 0) {
        puVar5 = *(uint **)(iVar9 + 0xc + local_24 * 0x14);
        uVar10 = 0;
        if (*puVar5 != 0) {
          do {
            puVar2 = puVar5 + uVar10 * 2 + 1;
            uVar11 = __sel_registerName(*puVar2);
            if (*puVar2 != uVar11) {
              *puVar2 = uVar11;
            }
            uVar10 = uVar10 + 1;
          } while (uVar10 < *puVar5);
        }
      }
      if (*(int *)(iVar9 + 0x10 + local_24 * 0x14) != 0) {
        puVar5 = *(uint **)(iVar9 + 0x10 + local_24 * 0x14);
        uVar10 = 0;
        if (*puVar5 != 0) {
          do {
            puVar2 = puVar5 + uVar10 * 2 + 1;
            uVar11 = __sel_registerName(*puVar2);
            if (*puVar2 != uVar11) {
              *puVar2 = uVar11;
            }
            uVar10 = uVar10 + 1;
          } while (uVar10 < *puVar5);
        }
      }
    }
  }
  return;
}

