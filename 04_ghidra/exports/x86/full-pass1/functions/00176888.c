/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00176888 */

/* WARNING: Removing unreachable block (ram,0x001778f4) */
/* WARNING: Removing unreachable block (ram,0x00177901) */
/* WARNING: Removing unreachable block (ram,0x0017790e) */
/* WARNING: Removing unreachable block (ram,0x0017791a) */
/* WARNING: Removing unreachable block (ram,0x0017792d) */
/* WARNING: Removing unreachable block (ram,0x001779c8) */
/* WARNING: Removing unreachable block (ram,0x00177954) */
/* WARNING: Removing unreachable block (ram,0x0017795b) */
/* WARNING: Removing unreachable block (ram,0x00177960) */
/* WARNING: Removing unreachable block (ram,0x00177962) */
/* WARNING: Removing unreachable block (ram,0x00177966) */
/* WARNING: Removing unreachable block (ram,0x00177974) */
/* WARNING: Removing unreachable block (ram,0x00177987) */
/* WARNING: Removing unreachable block (ram,0x001779d4) */
/* WARNING: Removing unreachable block (ram,0x001779e4) */
/* WARNING: Removing unreachable block (ram,0x001779dd) */
/* WARNING: Removing unreachable block (ram,0x001779e9) */
/* WARNING: Removing unreachable block (ram,0x00177a17) */

undefined4
_vm_map_copy(int param_1,int param_2,uint param_3,int param_4,uint param_5,int param_6,int param_7)

{
  uint *puVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int iVar7;
  undefined4 uVar8;
  int *piVar9;
  uint uVar10;
  int iVar11;
  int *piVar12;
  uint uVar13;
  uint uVar14;
  int *piVar15;
  bool bVar16;
  int local_4c;
  int local_48;
  uint local_40;
  undefined4 uVar17;
  int *local_c;
  undefined4 *local_8;
  
  uVar13 = param_5 + param_4;
  uVar14 = param_3 + param_4;
  if ((uVar14 < param_3) || (uVar13 < param_5)) {
    return 3;
  }
  iVar4 = param_1;
  if (param_2 == param_1) {
LAB_00176906:
    _lock_write(iVar4);
    *(int *)(iVar4 + 0x4c) = *(int *)(iVar4 + 0x4c) + 1;
  }
  else {
    if (param_1 <= param_2) {
      _lock_write(param_1);
      *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
      iVar4 = param_2;
      goto LAB_00176906;
    }
    _lock_write(param_2);
    *(int *)(param_2 + 0x4c) = *(int *)(param_2 + 0x4c) + 1;
    _lock_write(param_1);
    *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
  }
  if ((*(int *)(param_2 + 0x2c) != 0) && (*(int *)(param_1 + 0x2c) != 0)) {
    piVar9 = (int *)(param_2 + 0x3c);
    do {
      do {
      } while (*piVar9 != 0);
      LOCK();
      iVar4 = *piVar9;
      *piVar9 = 1;
      UNLOCK();
    } while (iVar4 == 1);
    local_8 = *(undefined4 **)(param_2 + 0x38);
    LOCK();
    *(undefined4 *)(param_2 + 0x3c) = 0;
    UNLOCK();
    puVar3 = (undefined4 *)(param_2 + 0xc);
    if (local_8 == puVar3) {
      local_8 = *(undefined4 **)(param_2 + 0x10);
    }
    if (param_5 < (uint)local_8[2]) {
      puVar3 = (undefined4 *)local_8[1];
      local_8 = *(undefined4 **)(param_2 + 0x10);
LAB_001769c7:
      if (local_8 != puVar3) {
        if ((uint)local_8[3] <= param_5) goto LAB_001769c4;
        if ((uint)local_8[2] <= param_5) {
          piVar9 = (int *)(param_2 + 0x3c);
          do {
            do {
            } while (*piVar9 != 0);
            LOCK();
            iVar4 = *piVar9;
            *piVar9 = 1;
            UNLOCK();
          } while (iVar4 == 1);
          *(undefined4 **)(param_2 + 0x38) = local_8;
          LOCK();
          *(undefined4 *)(param_2 + 0x3c) = 0;
          UNLOCK();
          goto LAB_00176a00;
        }
      }
      goto LAB_001769cb;
    }
    if (local_8 == puVar3) {
LAB_001769cb:
      local_8 = (undefined4 *)*local_8;
      piVar9 = (int *)(param_2 + 0x3c);
      do {
        do {
        } while (*piVar9 != 0);
        LOCK();
        iVar4 = *piVar9;
        *piVar9 = 1;
        UNLOCK();
      } while (iVar4 == 1);
      *(undefined4 **)(param_2 + 0x38) = local_8;
      LOCK();
      *(undefined4 *)(param_2 + 0x3c) = 0;
      UNLOCK();
LAB_00176cd4:
      uVar17 = 2;
      goto LAB_00177a31;
    }
    if ((uint)local_8[3] <= param_5) goto LAB_001769c7;
LAB_00176a00:
    if (param_5 < uVar13) {
      puVar3 = local_8;
      uVar10 = param_5;
      do {
        if (((puVar3 == (undefined4 *)(param_2 + 0xc)) || (uVar10 < (uint)puVar3[2])) ||
           ((*(byte *)(puVar3 + 7) & 1) == 0)) goto LAB_00176cd4;
        uVar10 = puVar3[3];
        puVar3 = (undefined4 *)puVar3[1];
      } while (uVar10 < uVar13);
    }
    if (param_6 == 0) {
      piVar9 = (int *)(param_1 + 0x3c);
      do {
        do {
        } while (*piVar9 != 0);
        LOCK();
        iVar4 = *piVar9;
        *piVar9 = 1;
        UNLOCK();
      } while (iVar4 == 1);
      local_8 = *(undefined4 **)(param_1 + 0x38);
      LOCK();
      *(undefined4 *)(param_1 + 0x3c) = 0;
      UNLOCK();
      puVar3 = (undefined4 *)(param_1 + 0xc);
      if (local_8 == puVar3) {
        local_8 = *(undefined4 **)(param_1 + 0x10);
      }
      if (param_3 < (uint)local_8[2]) {
        puVar3 = (undefined4 *)local_8[1];
        local_8 = *(undefined4 **)(param_1 + 0x10);
LAB_00176c73:
        if (local_8 != puVar3) {
          if ((uint)local_8[3] <= param_3) goto LAB_00176c70;
          if ((uint)local_8[2] <= param_3) {
            piVar9 = (int *)(param_1 + 0x3c);
            do {
              do {
              } while (*piVar9 != 0);
              LOCK();
              iVar4 = *piVar9;
              *piVar9 = 1;
              UNLOCK();
            } while (iVar4 == 1);
            *(undefined4 **)(param_1 + 0x38) = local_8;
            LOCK();
            *(undefined4 *)(param_1 + 0x3c) = 0;
            UNLOCK();
            goto LAB_00176ca8;
          }
        }
        goto LAB_00176c77;
      }
      if (local_8 == puVar3) {
LAB_00176c77:
        local_8 = (undefined4 *)*local_8;
        piVar9 = (int *)(param_1 + 0x3c);
        do {
          do {
          } while (*piVar9 != 0);
          LOCK();
          iVar4 = *piVar9;
          *piVar9 = 1;
          UNLOCK();
        } while (iVar4 == 1);
        *(undefined4 **)(param_1 + 0x38) = local_8;
        LOCK();
        *(undefined4 *)(param_1 + 0x3c) = 0;
        UNLOCK();
        goto LAB_00176cd4;
      }
      if ((uint)local_8[3] <= param_3) goto LAB_00176c73;
LAB_00176ca8:
      if (param_3 < uVar14) {
        puVar3 = local_8;
        uVar10 = param_3;
        do {
          if (((puVar3 == (undefined4 *)(param_1 + 0xc)) || (uVar10 < (uint)puVar3[2])) ||
             ((*(byte *)(puVar3 + 7) & 2) == 0)) goto LAB_00176cd4;
          uVar10 = puVar3[3];
          puVar3 = (undefined4 *)puVar3[1];
        } while (uVar10 < uVar14);
      }
    }
    else {
      if (((param_3 < *(uint *)(param_1 + 0x14)) || (*(uint *)(param_1 + 0x18) < uVar14)) ||
         (uVar14 <= param_3)) {
        uVar17 = 1;
        goto LAB_00177a31;
      }
      iVar4 = _vm_map_lookup_entry(param_1,param_3,&local_8);
      puVar3 = local_8;
      if ((iVar4 != 0) || ((local_8[1] != param_1 + 0xc && (*(uint *)(local_8[1] + 8) < uVar14)))) {
        uVar17 = 3;
        goto LAB_00177a31;
      }
      if (((local_8 == (undefined4 *)(param_1 + 0xc)) ||
          (((((local_8[3] != param_3 || ((*(byte *)(local_8 + 6) & 5) != 0)) || (local_8[9] != 1))
            || ((local_8[7] != 3 || (local_8[8] != 7)))) || (*(short *)(local_8 + 10) != 0)))) ||
         (iVar4 = _vm_object_coalesce(local_8[4],0,local_8[5],0,param_3 - local_8[2],
                                      uVar14 - param_3), iVar4 == 0)) {
        uVar17 = _vm_map_kentry_zone;
        if (*(int *)(param_1 + 0x20) != 0) {
          uVar17 = _vm_map_entry_zone;
        }
        piVar9 = (int *)_zalloc(uVar17);
        if (piVar9 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
          _panic(s_vm_map_entry_create_001e0ab0);
        }
        piVar9[2] = param_3;
        piVar9[3] = uVar14;
        *(byte *)(piVar9 + 6) = *(byte *)(piVar9 + 6) & 0xfa;
        piVar9[4] = 0;
        piVar9[5] = 0;
        *(byte *)(piVar9 + 6) = *(byte *)(piVar9 + 6) & 0xb7;
        if (*(int *)(param_1 + 0x2c) != 0) {
          piVar9[9] = 1;
          piVar9[7] = 3;
          piVar9[8] = 7;
          *(undefined2 *)(piVar9 + 10) = 0;
        }
        *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
        *piVar9 = (int)puVar3;
        piVar9[1] = puVar3[1];
        iVar4 = *piVar9;
        *(int **)piVar9[1] = piVar9;
        *(int **)(iVar4 + 4) = piVar9;
        *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + (piVar9[3] - piVar9[2]);
        if ((*(undefined4 **)(param_1 + 0x40) == puVar3) && ((uint)piVar9[2] <= (uint)puVar3[3])) {
          *(int **)(param_1 + 0x40) = piVar9;
        }
      }
      else {
        *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + (uVar14 - puVar3[3]);
        puVar3[3] = uVar14;
      }
    }
  }
  uVar17 = 0;
  piVar9 = (int *)(param_2 + 0x3c);
  do {
    do {
    } while (*piVar9 != 0);
    LOCK();
    iVar4 = *piVar9;
    *piVar9 = 1;
    UNLOCK();
  } while (iVar4 == 1);
  local_c = *(int **)(param_2 + 0x38);
  LOCK();
  *(undefined4 *)(param_2 + 0x3c) = 0;
  UNLOCK();
  piVar9 = (int *)(param_2 + 0xc);
  if (local_c == piVar9) {
    local_c = *(int **)(param_2 + 0x10);
  }
  if (param_5 < (uint)local_c[2]) {
    piVar9 = (int *)local_c[1];
    local_c = *(int **)(param_2 + 0x10);
LAB_00176d77:
    if (local_c != piVar9) {
      if ((uint)local_c[3] <= param_5) goto LAB_00176d74;
      if ((uint)local_c[2] <= param_5) {
        piVar9 = (int *)(param_2 + 0x3c);
        do {
          do {
          } while (*piVar9 != 0);
          LOCK();
          iVar4 = *piVar9;
          *piVar9 = 1;
          UNLOCK();
        } while (iVar4 == 1);
        *(int **)(param_2 + 0x38) = local_c;
        LOCK();
        *(undefined4 *)(param_2 + 0x3c) = 0;
        UNLOCK();
        goto LAB_00176daa;
      }
    }
    goto LAB_00176d7b;
  }
  if (local_c == piVar9) {
LAB_00176d7b:
    local_c = (int *)*local_c;
    piVar9 = (int *)(param_2 + 0x3c);
    do {
      do {
      } while (*piVar9 != 0);
      LOCK();
      iVar4 = *piVar9;
      *piVar9 = 1;
      UNLOCK();
    } while (iVar4 == 1);
    *(int **)(param_2 + 0x38) = local_c;
    LOCK();
    *(undefined4 *)(param_2 + 0x3c) = 0;
    UNLOCK();
  }
  else if ((uint)local_c[3] <= param_5) goto LAB_00176d77;
LAB_00176daa:
  piVar9 = local_c;
  if ((uint)local_c[2] < param_5) {
    uVar8 = _vm_map_kentry_zone;
    if (*(int *)(param_2 + 0x20) != 0) {
      uVar8 = _vm_map_entry_zone;
    }
    piVar5 = (int *)_zalloc(uVar8);
    if (piVar5 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      _panic(s_vm_map_entry_create_001e0ab0);
    }
    piVar6 = local_c;
    piVar12 = piVar5;
    for (iVar4 = 0xb; iVar4 != 0; iVar4 = iVar4 + -1) {
      *piVar12 = *piVar6;
      piVar6 = piVar6 + 1;
      piVar12 = piVar12 + 1;
    }
    piVar5[3] = param_5;
    local_c[5] = local_c[5] + (param_5 - local_c[2]);
    local_c[2] = param_5;
    *(int *)(param_2 + 0x1c) = *(int *)(param_2 + 0x1c) + 1;
    *piVar5 = *local_c;
    piVar5[1] = *(int *)(*local_c + 4);
    iVar4 = *piVar5;
    *(int **)piVar5[1] = piVar5;
    *(int **)(iVar4 + 4) = piVar5;
    if ((*(byte *)(local_c + 6) & 5) == 0) {
      _vm_object_reference(piVar5[4]);
    }
    else {
      iVar4 = piVar5[4];
      if (iVar4 != 0) {
        piVar5 = (int *)(iVar4 + 0x34);
        do {
          do {
          } while (*piVar5 != 0);
          LOCK();
          iVar2 = *piVar5;
          *piVar5 = 1;
          UNLOCK();
        } while (iVar2 == 1);
        *(int *)(iVar4 + 0x30) = *(int *)(iVar4 + 0x30) + 1;
        LOCK();
        *(undefined4 *)(iVar4 + 0x34) = 0;
        UNLOCK();
      }
    }
  }
  piVar5 = (int *)(param_1 + 0x3c);
  do {
    do {
    } while (*piVar5 != 0);
    LOCK();
    iVar4 = *piVar5;
    *piVar5 = 1;
    UNLOCK();
  } while (iVar4 == 1);
  local_c = *(int **)(param_1 + 0x38);
  LOCK();
  *(undefined4 *)(param_1 + 0x3c) = 0;
  UNLOCK();
  piVar5 = (int *)(param_1 + 0xc);
  if (local_c == piVar5) {
    local_c = *(int **)(param_1 + 0x10);
  }
  if (param_3 < (uint)local_c[2]) {
    piVar5 = (int *)local_c[1];
    local_c = *(int **)(param_1 + 0x10);
LAB_00176f1f:
    if (local_c != piVar5) {
      if ((uint)local_c[3] <= param_3) goto LAB_00176f1c;
      if ((uint)local_c[2] <= param_3) {
        piVar5 = (int *)(param_1 + 0x3c);
        do {
          do {
          } while (*piVar5 != 0);
          LOCK();
          iVar4 = *piVar5;
          *piVar5 = 1;
          UNLOCK();
        } while (iVar4 == 1);
        *(int **)(param_1 + 0x38) = local_c;
        LOCK();
        *(undefined4 *)(param_1 + 0x3c) = 0;
        UNLOCK();
        goto LAB_00176f52;
      }
    }
    goto LAB_00176f23;
  }
  if (local_c == piVar5) {
LAB_00176f23:
    local_c = (int *)*local_c;
    piVar5 = (int *)(param_1 + 0x3c);
    do {
      do {
      } while (*piVar5 != 0);
      LOCK();
      iVar4 = *piVar5;
      *piVar5 = 1;
      UNLOCK();
    } while (iVar4 == 1);
    *(int **)(param_1 + 0x38) = local_c;
    LOCK();
    *(undefined4 *)(param_1 + 0x3c) = 0;
    UNLOCK();
  }
  else if ((uint)local_c[3] <= param_3) goto LAB_00176f1f;
LAB_00176f52:
  piVar5 = local_c;
  if ((uint)local_c[2] < param_3) {
    uVar8 = _vm_map_kentry_zone;
    if (*(int *)(param_1 + 0x20) != 0) {
      uVar8 = _vm_map_entry_zone;
    }
    piVar6 = (int *)_zalloc(uVar8);
    if (piVar6 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      _panic(s_vm_map_entry_create_001e0ab0);
    }
    piVar12 = local_c;
    piVar15 = piVar6;
    for (iVar4 = 0xb; iVar4 != 0; iVar4 = iVar4 + -1) {
      *piVar15 = *piVar12;
      piVar12 = piVar12 + 1;
      piVar15 = piVar15 + 1;
    }
    piVar6[3] = param_3;
    local_c[5] = local_c[5] + (param_3 - local_c[2]);
    local_c[2] = param_3;
    *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
    *piVar6 = *local_c;
    piVar6[1] = *(int *)(*local_c + 4);
    iVar4 = *piVar6;
    *(int **)piVar6[1] = piVar6;
    *(int **)(iVar4 + 4) = piVar6;
    if ((*(byte *)(local_c + 6) & 5) == 0) {
      _vm_object_reference(piVar6[4]);
    }
    else {
      iVar4 = piVar6[4];
      if (iVar4 != 0) {
        piVar6 = (int *)(iVar4 + 0x34);
        do {
          do {
          } while (*piVar6 != 0);
          LOCK();
          iVar2 = *piVar6;
          *piVar6 = 1;
          UNLOCK();
        } while (iVar2 == 1);
        *(int *)(iVar4 + 0x30) = *(int *)(iVar4 + 0x30) + 1;
        LOCK();
        *(undefined4 *)(iVar4 + 0x34) = 0;
        UNLOCK();
      }
    }
  }
  bVar16 = piVar9 == local_c;
  local_c = piVar9;
  uVar10 = param_5;
  if (bVar16) {
    piVar9 = (int *)(param_2 + 0x3c);
    do {
      do {
      } while (*piVar9 != 0);
      LOCK();
      iVar4 = *piVar9;
      *piVar9 = 1;
      UNLOCK();
    } while (iVar4 == 1);
    local_c = *(int **)(param_2 + 0x38);
    LOCK();
    *(undefined4 *)(param_2 + 0x3c) = 0;
    UNLOCK();
    piVar9 = (int *)(param_2 + 0xc);
    if (local_c == piVar9) {
      local_c = *(int **)(param_2 + 0x10);
    }
    if (param_5 < (uint)local_c[2]) {
      piVar9 = (int *)local_c[1];
      local_c = *(int **)(param_2 + 0x10);
LAB_001770d3:
      if (local_c != piVar9) {
        if ((uint)local_c[3] <= param_5) goto LAB_001770d0;
        if ((uint)local_c[2] <= param_5) {
          piVar9 = (int *)(param_2 + 0x3c);
          do {
            do {
            } while (*piVar9 != 0);
            LOCK();
            iVar4 = *piVar9;
            *piVar9 = 1;
            UNLOCK();
          } while (iVar4 == 1);
          *(int **)(param_2 + 0x38) = local_c;
          LOCK();
          *(undefined4 *)(param_2 + 0x3c) = 0;
          UNLOCK();
          goto LAB_00177106;
        }
      }
      goto LAB_001770d7;
    }
    if (local_c == piVar9) {
LAB_001770d7:
      local_c = (int *)*local_c;
      piVar9 = (int *)(param_2 + 0x3c);
      do {
        do {
        } while (*piVar9 != 0);
        LOCK();
        iVar4 = *piVar9;
        *piVar9 = 1;
        UNLOCK();
      } while (iVar4 == 1);
      *(int **)(param_2 + 0x38) = local_c;
      LOCK();
      *(undefined4 *)(param_2 + 0x3c) = 0;
      UNLOCK();
    }
    else if ((uint)local_c[3] <= param_5) goto LAB_001770d3;
LAB_00177106:
    if (local_c == piVar5) goto LAB_00177a31;
  }
  while (uVar10 < uVar13) {
    if (uVar13 < (uint)local_c[3]) {
      uVar8 = _vm_map_kentry_zone;
      if (*(int *)(param_2 + 0x20) != 0) {
        uVar8 = _vm_map_entry_zone;
      }
      piVar9 = (int *)_zalloc(uVar8);
      if (piVar9 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
        _panic(s_vm_map_entry_create_001e0ab0);
      }
      piVar6 = local_c;
      piVar12 = piVar9;
      for (iVar4 = 0xb; iVar4 != 0; iVar4 = iVar4 + -1) {
        *piVar12 = *piVar6;
        piVar6 = piVar6 + 1;
        piVar12 = piVar12 + 1;
      }
      local_c[3] = uVar13;
      piVar9[2] = uVar13;
      piVar9[5] = piVar9[5] + (uVar13 - local_c[2]);
      *(int *)(param_2 + 0x1c) = *(int *)(param_2 + 0x1c) + 1;
      *piVar9 = (int)local_c;
      piVar9[1] = local_c[1];
      iVar4 = *piVar9;
      *(int **)piVar9[1] = piVar9;
      *(int **)(iVar4 + 4) = piVar9;
      if ((*(byte *)(local_c + 6) & 5) == 0) {
        _vm_object_reference(piVar9[4]);
      }
      else {
        iVar4 = piVar9[4];
        if (iVar4 != 0) {
          piVar9 = (int *)(iVar4 + 0x34);
          do {
            do {
            } while (*piVar9 != 0);
            LOCK();
            iVar2 = *piVar9;
            *piVar9 = 1;
            UNLOCK();
          } while (iVar2 == 1);
          *(int *)(iVar4 + 0x30) = *(int *)(iVar4 + 0x30) + 1;
          LOCK();
          *(undefined4 *)(iVar4 + 0x34) = 0;
          UNLOCK();
        }
      }
    }
    if (uVar14 < (uint)piVar5[3]) {
      uVar8 = _vm_map_kentry_zone;
      if (*(int *)(param_1 + 0x20) != 0) {
        uVar8 = _vm_map_entry_zone;
      }
      piVar9 = (int *)_zalloc(uVar8);
      if (piVar9 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
        _panic(s_vm_map_entry_create_001e0ab0);
      }
      piVar6 = piVar5;
      piVar12 = piVar9;
      for (iVar4 = 0xb; iVar4 != 0; iVar4 = iVar4 + -1) {
        *piVar12 = *piVar6;
        piVar6 = piVar6 + 1;
        piVar12 = piVar12 + 1;
      }
      piVar5[3] = uVar14;
      piVar9[2] = uVar14;
      piVar9[5] = piVar9[5] + (uVar14 - piVar5[2]);
      *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
      *piVar9 = (int)piVar5;
      piVar9[1] = piVar5[1];
      iVar4 = *piVar9;
      *(int **)piVar9[1] = piVar9;
      *(int **)(iVar4 + 4) = piVar9;
      if ((*(byte *)(piVar5 + 6) & 5) == 0) {
        _vm_object_reference(piVar9[4]);
      }
      else {
        iVar4 = piVar9[4];
        if (iVar4 != 0) {
          piVar9 = (int *)(iVar4 + 0x34);
          do {
            do {
            } while (*piVar9 != 0);
            LOCK();
            iVar2 = *piVar9;
            *piVar9 = 1;
            UNLOCK();
          } while (iVar2 == 1);
          *(int *)(iVar4 + 0x30) = *(int *)(iVar4 + 0x30) + 1;
          LOCK();
          *(undefined4 *)(iVar4 + 0x34) = 0;
          UNLOCK();
        }
      }
    }
    uVar10 = local_c[2] + (piVar5[3] - piVar5[2]);
    if (uVar10 < (uint)local_c[3]) {
      uVar8 = _vm_map_kentry_zone;
      if (*(int *)(param_2 + 0x20) != 0) {
        uVar8 = _vm_map_entry_zone;
      }
      piVar9 = (int *)_zalloc(uVar8);
      if (piVar9 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
        _panic(s_vm_map_entry_create_001e0ab0);
      }
      piVar6 = local_c;
      piVar12 = piVar9;
      for (iVar4 = 0xb; iVar4 != 0; iVar4 = iVar4 + -1) {
        *piVar12 = *piVar6;
        piVar6 = piVar6 + 1;
        piVar12 = piVar12 + 1;
      }
      local_c[3] = uVar10;
      piVar9[2] = uVar10;
      piVar9[5] = piVar9[5] + (uVar10 - local_c[2]);
      *(int *)(param_2 + 0x1c) = *(int *)(param_2 + 0x1c) + 1;
      *piVar9 = (int)local_c;
      piVar9[1] = local_c[1];
      iVar4 = *piVar9;
      *(int **)piVar9[1] = piVar9;
      *(int **)(iVar4 + 4) = piVar9;
      if ((*(byte *)(local_c + 6) & 5) == 0) {
        _vm_object_reference(piVar9[4]);
      }
      else {
        iVar4 = piVar9[4];
        if (iVar4 != 0) {
          piVar9 = (int *)(iVar4 + 0x34);
          do {
            do {
            } while (*piVar9 != 0);
            LOCK();
            iVar2 = *piVar9;
            *piVar9 = 1;
            UNLOCK();
          } while (iVar2 == 1);
          *(int *)(iVar4 + 0x30) = *(int *)(iVar4 + 0x30) + 1;
          LOCK();
          *(undefined4 *)(iVar4 + 0x34) = 0;
          UNLOCK();
        }
      }
    }
    uVar10 = piVar5[2] + (local_c[3] - local_c[2]);
    if (uVar10 < (uint)piVar5[3]) {
      uVar8 = _vm_map_kentry_zone;
      if (*(int *)(param_1 + 0x20) != 0) {
        uVar8 = _vm_map_entry_zone;
      }
      piVar9 = (int *)_zalloc(uVar8);
      if (piVar9 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
        _panic(s_vm_map_entry_create_001e0ab0);
      }
      piVar6 = piVar5;
      piVar12 = piVar9;
      for (iVar4 = 0xb; iVar4 != 0; iVar4 = iVar4 + -1) {
        *piVar12 = *piVar6;
        piVar6 = piVar6 + 1;
        piVar12 = piVar12 + 1;
      }
      piVar5[3] = uVar10;
      piVar9[2] = uVar10;
      piVar9[5] = piVar9[5] + (uVar10 - piVar5[2]);
      *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
      *piVar9 = (int)piVar5;
      piVar9[1] = piVar5[1];
      iVar4 = *piVar9;
      *(int **)piVar9[1] = piVar9;
      *(int **)(iVar4 + 4) = piVar9;
      if ((*(byte *)(piVar5 + 6) & 5) == 0) {
        _vm_object_reference(piVar9[4]);
      }
      else {
        iVar4 = piVar9[4];
        if (iVar4 != 0) {
          piVar9 = (int *)(iVar4 + 0x34);
          do {
            do {
            } while (*piVar9 != 0);
            LOCK();
            iVar2 = *piVar9;
            *piVar9 = 1;
            UNLOCK();
          } while (iVar2 == 1);
          *(int *)(iVar4 + 0x30) = *(int *)(iVar4 + 0x30) + 1;
          LOCK();
          *(undefined4 *)(iVar4 + 0x34) = 0;
          UNLOCK();
        }
      }
    }
    if (((*(byte *)(local_c + 6) & 1) == 0) && ((*(byte *)(piVar5 + 6) & 1) == 0)) {
      if (((*(byte *)(local_c + 6) & 4) == 0) && ((*(byte *)(piVar5 + 6) & 4) == 0)) {
        if ((short)piVar5[10] != 0) {
          _vm_fault_unwire(param_1,piVar5);
          *(undefined2 *)(piVar5 + 10) = 0;
        }
        if (*(int *)(param_1 + 0x2c) == 0) {
          _vm_object_pmap_remove(piVar5[4],piVar5[5],(piVar5[3] - piVar5[2]) + piVar5[5]);
        }
        _pmap_remove(*(undefined4 *)(param_1 + 0x24),piVar5[2],piVar5[3]);
        if ((short)local_c[10] == 0) {
          if ((*(byte *)(local_c + 6) & 0x40) == 0) {
            if (*(int *)(param_2 + 0x2c) == 0) {
              piVar9 = (int *)(param_2 + 0x34);
              do {
                do {
                } while (*piVar9 != 0);
                LOCK();
                iVar4 = *piVar9;
                *piVar9 = 1;
                UNLOCK();
              } while (iVar4 == 1);
              LOCK();
              *(undefined4 *)(param_2 + 0x34) = 0;
              UNLOCK();
              if (*(int *)(param_2 + 0x30) != 1) {
                _vm_object_pmap_copy(local_c[4],local_c[5],(local_c[3] - local_c[2]) + local_c[5]);
                goto LAB_001775cf;
              }
            }
            _pmap_protect(*(undefined4 *)(param_2 + 0x24),local_c[2],local_c[3],
                          local_c[7] & 0xfffffffd);
          }
LAB_001775cf:
          iVar4 = piVar5[4];
          _vm_object_copy(local_c[4],local_c[5],local_c[3] - local_c[2],piVar5 + 4,piVar5 + 5,
                          &local_8);
          if (local_8 != (undefined4 *)0x0) {
            *(byte *)(local_c + 6) = *(byte *)(local_c + 6) | 0x40;
          }
          *(byte *)(piVar5 + 6) = *(byte *)(piVar5 + 6) | 0x40;
          *(byte *)(local_c + 6) = *(byte *)(local_c + 6) | 8;
          *(byte *)(piVar5 + 6) = *(byte *)(piVar5 + 6) | 8;
          if ((*(byte *)(local_c + 7) & 4) != 0) {
            piVar5[7] = piVar5[7] | piVar5[8] & 4U;
          }
          _vm_object_deallocate(iVar4);
          _pmap_copy(*(undefined4 *)(param_1 + 0x24),*(undefined4 *)(param_2 + 0x24),piVar5[2],
                     piVar5[3] - piVar5[2],local_c[2]);
        }
        else {
          _vm_fault_copy_entry(param_1,param_2,piVar5,local_c);
        }
      }
    }
    else {
      iVar4 = piVar5[3];
      iVar2 = piVar5[2];
      if ((*(byte *)(local_c + 6) & 1) == 0) {
        local_48 = param_2;
        local_4c = local_c[2];
        _lock_set_recursive(param_2);
      }
      else {
        local_48 = local_c[4];
        local_4c = local_c[5];
      }
      if ((*(byte *)(piVar5 + 6) & 1) == 0) {
        local_40 = piVar5[2];
        _lock_set_recursive(param_1);
        iVar11 = param_1;
      }
      else {
        iVar11 = piVar5[4];
        local_40 = piVar5[5];
        uVar10 = local_40 + (iVar4 - iVar2);
        if (local_48 != iVar11) {
          _lock_write(iVar11);
          *(int *)(iVar11 + 0x4c) = *(int *)(iVar11 + 0x4c) + 1;
          _vm_map_delete(iVar11,local_40,uVar10);
          if ((((*(uint *)(iVar11 + 0x14) <= local_40) && (uVar10 <= *(uint *)(iVar11 + 0x18))) &&
              (local_40 < uVar10)) &&
             (iVar7 = _vm_map_lookup_entry(iVar11,local_40,&local_8), puVar3 = local_8, iVar7 == 0))
          {
            if (((undefined4 *)local_8[1] == (undefined4 *)(iVar11 + 0xc)) ||
               (uVar10 <= (uint)((undefined4 *)local_8[1])[2])) {
              if (((((local_8 == (undefined4 *)(iVar11 + 0xc)) ||
                    ((local_8[3] != local_40 || ((*(byte *)(local_8 + 6) & 5) != 0)))) ||
                   (local_8[9] != 1)) ||
                  (((local_8[7] != 3 || (local_8[8] != 7)) || (*(short *)(local_8 + 10) != 0)))) ||
                 (iVar7 = _vm_object_coalesce(local_8[4],0,local_8[5],0,local_40 - local_8[2],
                                              uVar10 - local_40), iVar7 == 0)) {
                uVar8 = _vm_map_kentry_zone;
                if (*(int *)(iVar11 + 0x20) != 0) {
                  uVar8 = _vm_map_entry_zone;
                }
                piVar9 = (int *)_zalloc(uVar8);
                if (piVar9 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
                  _panic(s_vm_map_entry_create_001e0ab0);
                }
                piVar9[2] = local_40;
                piVar9[3] = uVar10;
                *(byte *)(piVar9 + 6) = *(byte *)(piVar9 + 6) & 0xfa;
                piVar9[4] = 0;
                piVar9[5] = 0;
                *(byte *)(piVar9 + 6) = *(byte *)(piVar9 + 6) & 0xb7;
                if (*(int *)(iVar11 + 0x2c) != 0) {
                  piVar9[9] = 1;
                  piVar9[7] = 3;
                  piVar9[8] = 7;
                  *(undefined2 *)(piVar9 + 10) = 0;
                }
                *(int *)(iVar11 + 0x1c) = *(int *)(iVar11 + 0x1c) + 1;
                *piVar9 = (int)puVar3;
                piVar9[1] = puVar3[1];
                iVar7 = *piVar9;
                *(int **)piVar9[1] = piVar9;
                *(int **)(iVar7 + 4) = piVar9;
                *(int *)(iVar11 + 0x28) = *(int *)(iVar11 + 0x28) + (piVar9[3] - piVar9[2]);
                if ((*(undefined4 **)(iVar11 + 0x40) == puVar3) &&
                   ((uint)piVar9[2] <= (uint)puVar3[3])) {
                  *(int **)(iVar11 + 0x40) = piVar9;
                }
              }
              else {
                *(int *)(iVar11 + 0x28) = *(int *)(iVar11 + 0x28) + (uVar10 - puVar3[3]);
                puVar3[3] = uVar10;
              }
            }
          }
          _lock_done(iVar11);
        }
      }
      _vm_map_copy(iVar11,local_48,local_40,iVar4 - iVar2,local_4c,0,0);
      if (param_1 == iVar11) {
        _lock_clear_recursive(param_1);
      }
      if (param_2 == local_48) {
        _lock_clear_recursive(param_2);
      }
    }
    puVar1 = (uint *)(local_c + 3);
    piVar5 = (int *)piVar5[1];
    local_c = (int *)local_c[1];
    uVar10 = *puVar1;
  }
LAB_00177a31:
  if (param_7 != 0) {
    _vm_map_delete(param_2,param_5,param_5 + param_4);
  }
  _lock_done(param_2);
  if (param_2 != param_1) {
    _lock_done(param_1);
  }
  return uVar17;
LAB_001769c4:
  local_8 = (undefined4 *)local_8[1];
  goto LAB_001769c7;
LAB_00176c70:
  local_8 = (undefined4 *)local_8[1];
  goto LAB_00176c73;
LAB_00176d74:
  local_c = (int *)local_c[1];
  goto LAB_00176d77;
LAB_00176f1c:
  local_c = (int *)local_c[1];
  goto LAB_00176f1f;
LAB_001770d0:
  local_c = (int *)local_c[1];
  goto LAB_001770d3;
}

