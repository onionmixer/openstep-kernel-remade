/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001ce0cc */

undefined4 _objc_registerModule(mach_header *param_1,code *param_2)

{
  uint *puVar1;
  int *piVar2;
  int *piVar3;
  uint *puVar4;
  bool bVar5;
  int *piVar6;
  int iVar7;
  undefined4 uVar8;
  char *pcVar9;
  int iVar10;
  int iVar11;
  int *piVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint local_20;
  uint local_18;
  uint local_c;
  uint local_8;
  
  bVar5 = false;
  piVar6 = (int *)_getsectdatafromheader(param_1,"__OBJC","__module_info",&local_8);
  piVar12 = piVar6;
  for (local_c = local_8; (piVar12 != (int *)0x0 && (local_c != 0)); local_c = local_c - *piVar3) {
    iVar7 = piVar12[3];
    local_18 = 0;
    if (*(short *)(iVar7 + 8) != 0) {
      do {
        iVar7 = _objc_lookUpClass(*(undefined4 *)(iVar7 + 0xc + local_18 * 4));
        if (iVar7 != 0) {
          bVar5 = true;
        }
        local_18 = local_18 + 1;
        iVar7 = piVar12[3];
      } while ((int)local_18 < (int)(uint)*(ushort *)(iVar7 + 8));
    }
    piVar3 = piVar12 + 1;
    piVar12 = (int *)((int)piVar12 + piVar12[1]);
  }
  if (bVar5) {
    uVar8 = 1;
  }
  else {
    __objc_addHeader(param_1,0);
    FUN_001ce058(param_1);
    pcVar9 = _getsectdatafromheader(param_1,"__OBJC","__message_refs",&local_c);
    if (pcVar9 != (char *)0x0) {
      uVar15 = local_c >> 2;
      uVar13 = 0;
      if (uVar15 != 0) {
        do {
          iVar7 = _sel_registerName(*(undefined4 *)(pcVar9 + uVar13 * 4));
          if (*(int *)(pcVar9 + uVar13 * 4) != iVar7) {
            *(int *)(pcVar9 + uVar13 * 4) = iVar7;
          }
          uVar13 = uVar13 + 1;
        } while (uVar13 < uVar15);
      }
    }
    pcVar9 = _getsectdatafromheader(param_1,"__OBJC","__protocol",&local_c);
    piVar12 = piVar6;
    uVar13 = local_8;
    if (pcVar9 != (char *)0x0) {
      for (local_20 = 0; local_20 < local_c / 0x14; local_20 = local_20 + 1) {
        if (*(int *)(pcVar9 + local_20 * 0x14 + 0xc) != 0) {
          puVar4 = *(uint **)(pcVar9 + local_20 * 0x14 + 0xc);
          uVar13 = 0;
          if (*puVar4 != 0) {
            do {
              puVar1 = puVar4 + uVar13 * 2 + 1;
              uVar15 = _sel_registerName(*puVar1);
              if (*puVar1 != uVar15) {
                *puVar1 = uVar15;
              }
              uVar13 = uVar13 + 1;
            } while (uVar13 < *puVar4);
          }
        }
        if (*(int *)(pcVar9 + local_20 * 0x14 + 0x10) != 0) {
          puVar4 = *(uint **)(pcVar9 + local_20 * 0x14 + 0x10);
          uVar13 = 0;
          if (*puVar4 != 0) {
            do {
              puVar1 = puVar4 + uVar13 * 2 + 1;
              uVar15 = _sel_registerName(*puVar1);
              if (*puVar1 != uVar15) {
                *puVar1 = uVar15;
              }
              uVar13 = uVar13 + 1;
            } while (uVar13 < *puVar4);
          }
        }
      }
      _objc_msgSend(PTR_s_Protocol_001f9de0,PTR_s__fixup_numElements__001f9cf4,pcVar9,local_c / 0x14
                   );
      uVar13 = local_8;
    }
    while ((local_c = uVar13, piVar3 = piVar6, uVar13 = local_8, piVar12 != (int *)0x0 &&
           (uVar13 = local_8, local_c != 0))) {
      iVar7 = piVar12[3];
      local_18 = 0;
      if (*(short *)(iVar7 + 8) != 0) {
        do {
          _objc_addClass(*(undefined4 *)(iVar7 + 0xc + local_18 * 4));
          local_18 = local_18 + 1;
          iVar7 = piVar12[3];
        } while ((int)local_18 < (int)(uint)*(ushort *)(iVar7 + 8));
      }
      piVar3 = piVar12 + 1;
      piVar12 = (int *)((int)piVar12 + piVar12[1]);
      uVar13 = local_c - *piVar3;
    }
    while ((local_c = uVar13, piVar12 = piVar6, uVar13 = local_8, piVar3 != (int *)0x0 &&
           (uVar13 = local_8, local_c != 0))) {
      iVar7 = piVar3[3];
      local_18 = 0;
      if (*(short *)(iVar7 + 8) != 0) {
        do {
          piVar12 = *(int **)(iVar7 + 0xc + local_18 * 4);
          if (piVar12[7] != 0) {
            iVar7 = piVar12[7];
            uVar13 = 0;
            if (*(int *)(iVar7 + 4) != 0) {
              do {
                piVar2 = (int *)(iVar7 + 8 + uVar13 * 0xc);
                iVar10 = _sel_registerName(*piVar2);
                if (*piVar2 != iVar10) {
                  *piVar2 = iVar10;
                }
                uVar13 = uVar13 + 1;
              } while (uVar13 < *(uint *)(iVar7 + 4));
            }
          }
          if (*(int *)(*piVar12 + 0x1c) != 0) {
            iVar7 = *(int *)(*piVar12 + 0x1c);
            uVar13 = 0;
            if (*(int *)(iVar7 + 4) != 0) {
              do {
                piVar2 = (int *)(iVar7 + 8 + uVar13 * 0xc);
                iVar10 = _sel_registerName(*piVar2);
                if (*piVar2 != iVar10) {
                  *piVar2 = iVar10;
                }
                uVar13 = uVar13 + 1;
              } while (uVar13 < *(uint *)(iVar7 + 4));
            }
          }
          __class_install_relationships(piVar12,*piVar3);
          if ((*(int *)(*piVar12 + 0xc) - 3U < 2) && (piVar12[9] != 0)) {
            piVar12[9] = piVar12[9] + -4;
            *(int *)(*piVar12 + 0x24) = *(int *)(*piVar12 + 0x24) + -4;
          }
          if ((*(int *)(*piVar12 + 0xc) == 3) && (piVar12[9] != 0)) {
            __objc_inform("Unable to install protocols by name...\n");
            __objc_inform("Class %s must be recompiled.\n",piVar12[2]);
            piVar12[9] = 0;
            *(undefined4 *)(*piVar12 + 0x24) = 0;
          }
          local_18 = local_18 + 1;
          iVar7 = piVar3[3];
        } while ((int)local_18 < (int)(uint)*(ushort *)(iVar7 + 8));
      }
      piVar12 = piVar3 + 1;
      piVar3 = (int *)((int)piVar3 + piVar3[1]);
      uVar13 = local_c - *piVar12;
    }
    while ((local_c = uVar13, piVar3 = piVar6, uVar13 = local_8, piVar12 != (int *)0x0 &&
           (uVar13 = local_8, local_c != 0))) {
      iVar7 = piVar12[3];
      local_18 = (uint)*(ushort *)(iVar7 + 8);
      if (local_18 < *(ushort *)(iVar7 + 10) + local_18) {
        do {
          iVar7 = *(int *)(iVar7 + 0xc + local_18 * 4);
          if (*(int *)(iVar7 + 8) != 0) {
            iVar10 = *(int *)(iVar7 + 8);
            uVar13 = 0;
            if (*(int *)(iVar10 + 4) != 0) {
              do {
                piVar3 = (int *)(iVar10 + 8 + uVar13 * 0xc);
                iVar11 = _sel_registerName(*piVar3);
                if (*piVar3 != iVar11) {
                  *piVar3 = iVar11;
                }
                uVar13 = uVar13 + 1;
              } while (uVar13 < *(uint *)(iVar10 + 4));
            }
          }
          if (*(int *)(iVar7 + 0xc) != 0) {
            iVar7 = *(int *)(iVar7 + 0xc);
            uVar13 = 0;
            if (*(int *)(iVar7 + 4) != 0) {
              do {
                piVar3 = (int *)(iVar7 + 8 + uVar13 * 0xc);
                iVar10 = _sel_registerName(*piVar3);
                if (*piVar3 != iVar10) {
                  *piVar3 = iVar10;
                }
                uVar13 = uVar13 + 1;
              } while (uVar13 < *(uint *)(iVar7 + 4));
            }
          }
          __objc_add_category(*(undefined4 *)(piVar12[3] + 0xc + local_18 * 4),*piVar12);
          local_18 = local_18 + 1;
          iVar7 = piVar12[3];
        } while ((int)local_18 < (int)((uint)*(ushort *)(iVar7 + 8) + (uint)*(ushort *)(iVar7 + 10))
                );
      }
      piVar3 = piVar12 + 1;
      piVar12 = (int *)((int)piVar12 + piVar12[1]);
      uVar13 = local_c - *piVar3;
    }
    while ((local_c = uVar13, piVar3 != (int *)0x0 && (local_c != 0))) {
      if (*piVar3 == 1) {
        uVar13 = ((uint *)piVar3[3])[1];
        uVar15 = *(uint *)piVar3[3];
        uVar14 = 0;
        if (uVar15 != 0) {
          do {
            iVar7 = _sel_registerName(*(undefined4 *)(uVar13 + uVar14 * 4));
            if (*(int *)(uVar13 + uVar14 * 4) != iVar7) {
              *(int *)(uVar13 + uVar14 * 4) = iVar7;
            }
            uVar14 = uVar14 + 1;
          } while (uVar14 < uVar15);
        }
      }
      piVar12 = piVar3 + 1;
      piVar3 = (int *)((int)piVar3 + piVar3[1]);
      uVar13 = local_c - *piVar12;
    }
    pcVar9 = _getsectdatafromheader(param_1,"__OBJC","__cls_refs",&local_c);
    piVar12 = piVar6;
    uVar13 = local_8;
    if (pcVar9 != (char *)0x0) {
      for (uVar15 = 0; uVar13 = local_8, uVar15 < local_c >> 2; uVar15 = uVar15 + 1) {
        uVar8 = _objc_getClass(*(undefined4 *)(pcVar9 + uVar15 * 4));
        *(undefined4 *)(pcVar9 + uVar15 * 4) = uVar8;
      }
    }
    while ((local_c = uVar13, uVar13 = local_8, piVar12 != (int *)0x0 &&
           (uVar13 = local_8, local_c != 0))) {
      iVar7 = piVar12[3];
      local_18 = 0;
      if (*(short *)(iVar7 + 8) != 0) {
        do {
          if (param_2 != (code *)0x0) {
            (*param_2)(*(undefined4 *)(iVar7 + 0xc + local_18 * 4),0);
          }
          FUN_001cdf50(*(undefined4 *)(piVar12[3] + 0xc + local_18 * 4),param_1);
          local_18 = local_18 + 1;
          iVar7 = piVar12[3];
        } while ((int)local_18 < (int)(uint)*(ushort *)(iVar7 + 8));
      }
      piVar3 = piVar12 + 1;
      piVar12 = (int *)((int)piVar12 + piVar12[1]);
      uVar13 = local_c - *piVar3;
    }
    while ((local_c = uVar13, piVar6 != (int *)0x0 && (local_c != 0))) {
      iVar7 = piVar6[3];
      local_18 = (uint)*(ushort *)(iVar7 + 8);
      if (local_18 < *(ushort *)(iVar7 + 10) + local_18) {
        do {
          if (param_2 != (code *)0x0) {
            uVar8 = _objc_getClass(*(undefined4 *)(*(int *)(iVar7 + 0xc + local_18 * 4) + 4),
                                   *(undefined4 *)(iVar7 + 0xc + local_18 * 4));
            (*param_2)(uVar8);
          }
          FUN_001cdf90(*(undefined4 *)(piVar6[3] + 0xc + local_18 * 4),param_1);
          local_18 = local_18 + 1;
          iVar7 = piVar6[3];
        } while ((int)local_18 < (int)((uint)*(ushort *)(iVar7 + 8) + (uint)*(ushort *)(iVar7 + 10))
                );
      }
      piVar12 = piVar6 + 1;
      piVar6 = (int *)((int)piVar6 + piVar6[1]);
      uVar13 = local_c - *piVar12;
    }
    uVar8 = 0;
  }
  return uVar8;
}

