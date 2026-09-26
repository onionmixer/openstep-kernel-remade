/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00176df3 */

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
/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

undefined4 __analysis_fragment_00176df3(void)

{
  byte *pbVar1;
  byte bVar2;
  undefined4 uVar3;
  int *piVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined4 *puVar11;
  int *piVar12;
  int unaff_EBX;
  uint uVar13;
  int unaff_EBP;
  undefined4 *puVar14;
  
  *(undefined4 *)(unaff_EBP + -0x54) = *(undefined4 *)(unaff_EBP + -0x2c);
  puVar7 = *(undefined4 **)(unaff_EBP + -0x54);
  puVar11 = *(undefined4 **)(unaff_EBP + -0xc);
  puVar14 = puVar7;
  for (iVar10 = 0xb; iVar10 != 0; iVar10 = iVar10 + -1) {
    *puVar14 = *puVar11;
    puVar11 = puVar11 + 1;
    puVar14 = puVar14 + 1;
  }
  uVar3 = *(undefined4 *)(unaff_EBP + -0x14);
  puVar7[3] = uVar3;
  puVar7 = *(undefined4 **)(unaff_EBP + -0xc);
  puVar7[5] = puVar7[5] + (*(int *)(unaff_EBP + -0x14) - puVar7[2]);
  puVar7[2] = uVar3;
  *(int *)(unaff_EBX + 0x10) = *(int *)(unaff_EBX + 0x10) + 1;
  **(undefined4 **)(unaff_EBP + -0x54) = *puVar7;
  piVar12 = *(int **)(unaff_EBP + -0xc);
  piVar4 = *(int **)(unaff_EBP + -0x54);
  piVar4[1] = *(int *)(*piVar12 + 4);
  iVar10 = *piVar4;
  *(int **)piVar4[1] = piVar4;
  *(int **)(iVar10 + 4) = piVar4;
  if ((*(byte *)(piVar12 + 6) & 5) == 0) {
    _vm_object_reference();
  }
  else {
    iVar10 = piVar4[4];
    if (iVar10 != 0) {
      piVar12 = (int *)(iVar10 + 0x34);
      do {
        do {
        } while (*piVar12 != 0);
        LOCK();
        iVar8 = *piVar12;
        *piVar12 = 1;
        UNLOCK();
      } while (iVar8 == 1);
      *(int *)(iVar10 + 0x30) = *(int *)(iVar10 + 0x30) + 1;
      LOCK();
      *(undefined4 *)(iVar10 + 0x34) = 0;
      UNLOCK();
    }
  }
  piVar12 = (int *)(*(int *)(unaff_EBP + 8) + 0x3c);
  do {
    do {
    } while (*piVar12 != 0);
    LOCK();
    iVar10 = *piVar12;
    *piVar12 = 1;
    UNLOCK();
  } while (iVar10 == 1);
  iVar10 = *(int *)(unaff_EBP + 8);
  puVar11 = *(undefined4 **)(iVar10 + 0x38);
  LOCK();
  *(undefined4 *)(iVar10 + 0x3c) = 0;
  UNLOCK();
  puVar7 = (undefined4 *)(iVar10 + 0xc);
  if (puVar11 == puVar7) {
    puVar11 = *(undefined4 **)(iVar10 + 0x10);
  }
  if (*(uint *)(unaff_EBP + 0x10) < (uint)puVar11[2]) {
    puVar7 = (undefined4 *)puVar11[1];
    puVar11 = *(undefined4 **)(*(int *)(unaff_EBP + 8) + 0x10);
LAB_00176f1f:
    if (puVar11 != puVar7) {
      if ((uint)puVar11[3] <= *(uint *)(unaff_EBP + 0x10)) goto LAB_00176f1c;
      if ((uint)puVar11[2] <= *(uint *)(unaff_EBP + 0x10)) {
        *(undefined4 **)(unaff_EBP + -8) = puVar11;
        piVar12 = (int *)(*(int *)(unaff_EBP + 8) + 0x3c);
        do {
          do {
          } while (*piVar12 != 0);
          LOCK();
          iVar10 = *piVar12;
          *piVar12 = 1;
          UNLOCK();
        } while (iVar10 == 1);
        iVar10 = *(int *)(unaff_EBP + 8);
        *(undefined4 **)(iVar10 + 0x38) = puVar11;
        LOCK();
        *(undefined4 *)(iVar10 + 0x3c) = 0;
        UNLOCK();
        goto LAB_00176f52;
      }
    }
    goto LAB_00176f23;
  }
  if (puVar11 == puVar7) {
LAB_00176f23:
    *(undefined4 *)(unaff_EBP + -8) = *puVar11;
    piVar12 = (int *)(*(int *)(unaff_EBP + 8) + 0x3c);
    do {
      do {
      } while (*piVar12 != 0);
      LOCK();
      iVar10 = *piVar12;
      *piVar12 = 1;
      UNLOCK();
    } while (iVar10 == 1);
    iVar10 = *(int *)(unaff_EBP + 8);
    *(undefined4 *)(iVar10 + 0x38) = *(undefined4 *)(unaff_EBP + -8);
    LOCK();
    *(undefined4 *)(iVar10 + 0x3c) = 0;
    UNLOCK();
  }
  else {
    if ((uint)puVar11[3] <= *(uint *)(unaff_EBP + 0x10)) goto LAB_00176f1f;
    *(undefined4 **)(unaff_EBP + -8) = puVar11;
  }
LAB_00176f52:
  *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -8);
  if (*(uint *)(*(int *)(unaff_EBP + -8) + 8) < *(uint *)(unaff_EBP + -0x1c)) {
    iVar10 = *(int *)(unaff_EBP + 8);
    iVar8 = _zalloc();
    *(int *)(unaff_EBP + -0x30) = iVar8;
    if (iVar8 == 0) {
                    /* WARNING: Subroutine does not return */
      _panic(s_vm_map_entry_create_001e0ab0);
    }
    *(undefined4 *)(unaff_EBP + -0x54) = *(undefined4 *)(unaff_EBP + -0x30);
    puVar7 = *(undefined4 **)(unaff_EBP + -0x54);
    puVar11 = *(undefined4 **)(unaff_EBP + -0x10);
    puVar14 = puVar7;
    for (iVar8 = 0xb; iVar8 != 0; iVar8 = iVar8 + -1) {
      *puVar14 = *puVar11;
      puVar11 = puVar11 + 1;
      puVar14 = puVar14 + 1;
    }
    uVar3 = *(undefined4 *)(unaff_EBP + -0x1c);
    puVar7[3] = uVar3;
    puVar7 = *(undefined4 **)(unaff_EBP + -0x10);
    puVar7[5] = puVar7[5] + (*(int *)(unaff_EBP + -0x1c) - puVar7[2]);
    puVar7[2] = uVar3;
    piVar12 = (int *)(iVar10 + 0x1c);
    *piVar12 = *piVar12 + 1;
    **(undefined4 **)(unaff_EBP + -0x54) = *puVar7;
    piVar12 = *(int **)(unaff_EBP + -0x10);
    piVar4 = *(int **)(unaff_EBP + -0x54);
    piVar4[1] = *(int *)(*piVar12 + 4);
    iVar10 = *piVar4;
    *(int **)piVar4[1] = piVar4;
    *(int **)(iVar10 + 4) = piVar4;
    if ((*(byte *)(piVar12 + 6) & 5) == 0) {
      _vm_object_reference();
    }
    else {
      iVar10 = piVar4[4];
      if (iVar10 != 0) {
        piVar12 = (int *)(iVar10 + 0x34);
        do {
          do {
          } while (*piVar12 != 0);
          LOCK();
          iVar8 = *piVar12;
          *piVar12 = 1;
          UNLOCK();
        } while (iVar8 == 1);
        *(int *)(iVar10 + 0x30) = *(int *)(iVar10 + 0x30) + 1;
        LOCK();
        *(undefined4 *)(iVar10 + 0x34) = 0;
        UNLOCK();
      }
    }
  }
  if (*(int *)(unaff_EBP + -0xc) == *(int *)(unaff_EBP + -0x10)) {
    piVar12 = (int *)(*(int *)(unaff_EBP + 0xc) + 0x3c);
    do {
      do {
      } while (*piVar12 != 0);
      LOCK();
      iVar10 = *piVar12;
      *piVar12 = 1;
      UNLOCK();
    } while (iVar10 == 1);
    iVar10 = *(int *)(unaff_EBP + 0xc);
    puVar11 = *(undefined4 **)(iVar10 + 0x38);
    LOCK();
    *(undefined4 *)(iVar10 + 0x3c) = 0;
    UNLOCK();
    puVar7 = (undefined4 *)(iVar10 + 0xc);
    if (puVar11 == puVar7) {
      puVar11 = *(undefined4 **)(iVar10 + 0x10);
    }
    if (*(uint *)(unaff_EBP + 0x18) < (uint)puVar11[2]) {
      puVar7 = (undefined4 *)puVar11[1];
      puVar11 = *(undefined4 **)(*(int *)(unaff_EBP + 0xc) + 0x10);
LAB_001770d3:
      if (puVar11 != puVar7) {
        if ((uint)puVar11[3] <= *(uint *)(unaff_EBP + 0x18)) goto LAB_001770d0;
        if ((uint)puVar11[2] <= *(uint *)(unaff_EBP + 0x18)) {
          *(undefined4 **)(unaff_EBP + -8) = puVar11;
          piVar12 = (int *)(*(int *)(unaff_EBP + 0xc) + 0x3c);
          do {
            do {
            } while (*piVar12 != 0);
            LOCK();
            iVar10 = *piVar12;
            *piVar12 = 1;
            UNLOCK();
          } while (iVar10 == 1);
          iVar10 = *(int *)(unaff_EBP + 0xc);
          *(undefined4 **)(iVar10 + 0x38) = puVar11;
          LOCK();
          *(undefined4 *)(iVar10 + 0x3c) = 0;
          UNLOCK();
          goto LAB_00177106;
        }
      }
      goto LAB_001770d7;
    }
    if (puVar11 == puVar7) {
LAB_001770d7:
      *(undefined4 *)(unaff_EBP + -8) = *puVar11;
      piVar12 = (int *)(*(int *)(unaff_EBP + 0xc) + 0x3c);
      do {
        do {
        } while (*piVar12 != 0);
        LOCK();
        iVar10 = *piVar12;
        *piVar12 = 1;
        UNLOCK();
      } while (iVar10 == 1);
      iVar10 = *(int *)(unaff_EBP + 0xc);
      *(undefined4 *)(iVar10 + 0x38) = *(undefined4 *)(unaff_EBP + -8);
      LOCK();
      *(undefined4 *)(iVar10 + 0x3c) = 0;
      UNLOCK();
    }
    else {
      if ((uint)puVar11[3] <= *(uint *)(unaff_EBP + 0x18)) goto LAB_001770d3;
      *(undefined4 **)(unaff_EBP + -8) = puVar11;
    }
LAB_00177106:
    *(int *)(unaff_EBP + -0xc) = *(int *)(unaff_EBP + -8);
    if (*(int *)(unaff_EBP + -8) == *(int *)(unaff_EBP + -0x10)) goto LAB_00177a31;
  }
  if (*(uint *)(unaff_EBP + -0x14) < *(uint *)(unaff_EBP + -0x18)) {
    do {
      if (*(uint *)(unaff_EBP + -0x18) < *(uint *)(*(int *)(unaff_EBP + -0xc) + 0xc)) {
        *(int *)(unaff_EBP + -0x50) = *(int *)(unaff_EBP + 0xc) + 0xc;
        iVar8 = _zalloc();
        iVar10 = *(int *)(unaff_EBP + -0x50);
        if (iVar8 == 0) {
          *(int *)(unaff_EBP + -0x50) = iVar10;
                    /* WARNING: Subroutine does not return */
          _panic(s_vm_map_entry_create_001e0ab0);
        }
        *(int *)(unaff_EBP + -0x54) = iVar8;
        *(undefined4 *)(unaff_EBP + -0x58) = *(undefined4 *)(unaff_EBP + -0xc);
        puVar7 = *(undefined4 **)(unaff_EBP + -0x58);
        puVar11 = *(undefined4 **)(unaff_EBP + -0x54);
        for (iVar8 = 0xb; iVar8 != 0; iVar8 = iVar8 + -1) {
          *puVar11 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar11 = puVar11 + 1;
        }
        iVar8 = *(int *)(unaff_EBP + -0x18);
        *(int *)(*(int *)(unaff_EBP + -0xc) + 0xc) = iVar8;
        piVar4 = *(int **)(unaff_EBP + -0x54);
        piVar4[2] = iVar8;
        iVar8 = *(int *)(unaff_EBP + -0xc);
        piVar4[5] = piVar4[5] + (*(int *)(unaff_EBP + -0x18) - *(int *)(iVar8 + 8));
        piVar12 = (int *)(iVar10 + 0x10);
        *piVar12 = *piVar12 + 1;
        *piVar4 = iVar8;
        piVar4[1] = *(int *)(iVar8 + 4);
        iVar10 = *piVar4;
        *(int **)piVar4[1] = piVar4;
        *(int **)(iVar10 + 4) = piVar4;
        if ((*(byte *)(*(int *)(unaff_EBP + -0xc) + 0x18) & 5) == 0) {
          _vm_object_reference();
        }
        else {
          iVar10 = *(int *)(*(int *)(unaff_EBP + -0x54) + 0x10);
          if (iVar10 != 0) {
            piVar12 = (int *)(iVar10 + 0x34);
            do {
              do {
              } while (*piVar12 != 0);
              LOCK();
              iVar8 = *piVar12;
              *piVar12 = 1;
              UNLOCK();
            } while (iVar8 == 1);
            *(int *)(iVar10 + 0x30) = *(int *)(iVar10 + 0x30) + 1;
            LOCK();
            *(undefined4 *)(iVar10 + 0x34) = 0;
            UNLOCK();
          }
        }
      }
      if (*(uint *)(unaff_EBP + -0x20) < *(uint *)(*(int *)(unaff_EBP + -0x10) + 0xc)) {
        *(int *)(unaff_EBP + -0x50) = *(int *)(unaff_EBP + 8) + 0xc;
        iVar8 = _zalloc();
        iVar10 = *(int *)(unaff_EBP + -0x50);
        if (iVar8 == 0) {
          *(int *)(unaff_EBP + -0x50) = iVar10;
                    /* WARNING: Subroutine does not return */
          _panic(s_vm_map_entry_create_001e0ab0);
        }
        *(int *)(unaff_EBP + -0x54) = iVar8;
        *(undefined4 *)(unaff_EBP + -0x58) = *(undefined4 *)(unaff_EBP + -0x10);
        puVar7 = *(undefined4 **)(unaff_EBP + -0x58);
        puVar11 = *(undefined4 **)(unaff_EBP + -0x54);
        for (iVar8 = 0xb; iVar8 != 0; iVar8 = iVar8 + -1) {
          *puVar11 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar11 = puVar11 + 1;
        }
        iVar8 = *(int *)(unaff_EBP + -0x20);
        *(int *)(*(int *)(unaff_EBP + -0x10) + 0xc) = iVar8;
        piVar4 = *(int **)(unaff_EBP + -0x54);
        piVar4[2] = iVar8;
        iVar8 = *(int *)(unaff_EBP + -0x10);
        piVar4[5] = piVar4[5] + (*(int *)(unaff_EBP + -0x20) - *(int *)(iVar8 + 8));
        piVar12 = (int *)(iVar10 + 0x10);
        *piVar12 = *piVar12 + 1;
        *piVar4 = iVar8;
        piVar4[1] = *(int *)(iVar8 + 4);
        iVar10 = *piVar4;
        *(int **)piVar4[1] = piVar4;
        *(int **)(iVar10 + 4) = piVar4;
        if ((*(byte *)(*(int *)(unaff_EBP + -0x10) + 0x18) & 5) == 0) {
          _vm_object_reference();
        }
        else {
          iVar10 = *(int *)(*(int *)(unaff_EBP + -0x54) + 0x10);
          if (iVar10 != 0) {
            piVar12 = (int *)(iVar10 + 0x34);
            do {
              do {
              } while (*piVar12 != 0);
              LOCK();
              iVar8 = *piVar12;
              *piVar12 = 1;
              UNLOCK();
            } while (iVar8 == 1);
            *(int *)(iVar10 + 0x30) = *(int *)(iVar10 + 0x30) + 1;
            LOCK();
            *(undefined4 *)(iVar10 + 0x34) = 0;
            UNLOCK();
          }
        }
      }
      uVar13 = *(int *)(*(int *)(unaff_EBP + -0xc) + 8) +
               (*(int *)(*(int *)(unaff_EBP + -0x10) + 0xc) -
               *(int *)(*(int *)(unaff_EBP + -0x10) + 8));
      if (uVar13 < *(uint *)(*(int *)(unaff_EBP + -0xc) + 0xc)) {
        *(int *)(unaff_EBP + -0x50) = *(int *)(unaff_EBP + 0xc) + 0xc;
        iVar8 = _zalloc();
        *(int *)(unaff_EBP + -0x34) = iVar8;
        iVar10 = *(int *)(unaff_EBP + -0x50);
        if (iVar8 == 0) {
          *(int *)(unaff_EBP + -0x50) = iVar10;
                    /* WARNING: Subroutine does not return */
          _panic(s_vm_map_entry_create_001e0ab0);
        }
        *(undefined4 *)(unaff_EBP + -0x54) = *(undefined4 *)(unaff_EBP + -0x34);
        *(undefined4 **)(unaff_EBP + -0x58) = *(undefined4 **)(unaff_EBP + -0xc);
        puVar7 = *(undefined4 **)(unaff_EBP + -0xc);
        puVar11 = *(undefined4 **)(unaff_EBP + -0x54);
        for (iVar8 = 0xb; iVar8 != 0; iVar8 = iVar8 + -1) {
          *puVar11 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar11 = puVar11 + 1;
        }
        iVar8 = *(int *)(unaff_EBP + -0xc);
        *(uint *)(iVar8 + 0xc) = uVar13;
        piVar4 = *(int **)(unaff_EBP + -0x54);
        piVar4[2] = uVar13;
        piVar4[5] = piVar4[5] + (uVar13 - *(int *)(iVar8 + 8));
        piVar12 = (int *)(iVar10 + 0x10);
        *piVar12 = *piVar12 + 1;
        *piVar4 = iVar8;
        piVar4[1] = *(int *)(iVar8 + 4);
        iVar10 = *piVar4;
        *(int **)piVar4[1] = piVar4;
        *(int **)(iVar10 + 4) = piVar4;
        if ((*(byte *)(*(int *)(unaff_EBP + -0xc) + 0x18) & 5) == 0) {
          _vm_object_reference();
        }
        else {
          iVar10 = *(int *)(*(int *)(unaff_EBP + -0x54) + 0x10);
          if (iVar10 != 0) {
            piVar12 = (int *)(iVar10 + 0x34);
            do {
              do {
              } while (*piVar12 != 0);
              LOCK();
              iVar8 = *piVar12;
              *piVar12 = 1;
              UNLOCK();
            } while (iVar8 == 1);
            *(int *)(iVar10 + 0x30) = *(int *)(iVar10 + 0x30) + 1;
            LOCK();
            *(undefined4 *)(iVar10 + 0x34) = 0;
            UNLOCK();
          }
        }
      }
      uVar13 = *(int *)(*(int *)(unaff_EBP + -0x10) + 8) +
               (*(int *)(*(int *)(unaff_EBP + -0xc) + 0xc) -
               *(int *)(*(int *)(unaff_EBP + -0xc) + 8));
      if (uVar13 < *(uint *)(*(int *)(unaff_EBP + -0x10) + 0xc)) {
        *(int *)(unaff_EBP + -0x50) = *(int *)(unaff_EBP + 8) + 0xc;
        iVar8 = _zalloc();
        *(int *)(unaff_EBP + -0x38) = iVar8;
        iVar10 = *(int *)(unaff_EBP + -0x50);
        if (iVar8 == 0) {
          *(int *)(unaff_EBP + -0x50) = iVar10;
                    /* WARNING: Subroutine does not return */
          _panic(s_vm_map_entry_create_001e0ab0);
        }
        *(undefined4 *)(unaff_EBP + -0x54) = *(undefined4 *)(unaff_EBP + -0x38);
        *(undefined4 **)(unaff_EBP + -0x58) = *(undefined4 **)(unaff_EBP + -0x10);
        puVar7 = *(undefined4 **)(unaff_EBP + -0x10);
        puVar11 = *(undefined4 **)(unaff_EBP + -0x54);
        for (iVar8 = 0xb; iVar8 != 0; iVar8 = iVar8 + -1) {
          *puVar11 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar11 = puVar11 + 1;
        }
        iVar8 = *(int *)(unaff_EBP + -0x10);
        *(uint *)(iVar8 + 0xc) = uVar13;
        piVar4 = *(int **)(unaff_EBP + -0x54);
        piVar4[2] = uVar13;
        piVar4[5] = piVar4[5] + (uVar13 - *(int *)(iVar8 + 8));
        piVar12 = (int *)(iVar10 + 0x10);
        *piVar12 = *piVar12 + 1;
        *piVar4 = iVar8;
        piVar4[1] = *(int *)(iVar8 + 4);
        iVar10 = *piVar4;
        *(int **)piVar4[1] = piVar4;
        *(int **)(iVar10 + 4) = piVar4;
        if ((*(byte *)(*(int *)(unaff_EBP + -0x10) + 0x18) & 5) == 0) {
          _vm_object_reference();
        }
        else {
          iVar10 = *(int *)(*(int *)(unaff_EBP + -0x54) + 0x10);
          if (iVar10 != 0) {
            piVar12 = (int *)(iVar10 + 0x34);
            do {
              do {
              } while (*piVar12 != 0);
              LOCK();
              iVar8 = *piVar12;
              *piVar12 = 1;
              UNLOCK();
            } while (iVar8 == 1);
            *(int *)(iVar10 + 0x30) = *(int *)(iVar10 + 0x30) + 1;
            LOCK();
            *(undefined4 *)(iVar10 + 0x34) = 0;
            UNLOCK();
          }
        }
      }
      bVar2 = *(byte *)(*(int *)(unaff_EBP + -0xc) + 0x18);
      if ((bVar2 & 1) == 0) {
        iVar10 = *(int *)(unaff_EBP + -0x10);
        if ((*(byte *)(iVar10 + 0x18) & 1) != 0) goto LAB_0017768c;
        if (((bVar2 & 4) == 0) && ((*(byte *)(iVar10 + 0x18) & 4) == 0)) {
          if (*(short *)(iVar10 + 0x28) != 0) {
            _vm_fault_unwire(*(undefined4 *)(unaff_EBP + 8));
            *(undefined2 *)(iVar10 + 0x28) = 0;
          }
          if (*(int *)(*(int *)(unaff_EBP + 8) + 0x2c) == 0) {
            _vm_object_pmap_remove
                      (*(undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x10),
                       *(undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x14));
          }
          _pmap_remove(*(undefined4 *)(*(int *)(unaff_EBP + 8) + 0x24),
                       *(undefined4 *)(*(int *)(unaff_EBP + -0x10) + 8));
          if (*(short *)(*(int *)(unaff_EBP + -0xc) + 0x28) == 0) {
            if ((*(byte *)(*(int *)(unaff_EBP + -0xc) + 0x18) & 0x40) == 0) {
              if (*(int *)(*(int *)(unaff_EBP + 0xc) + 0x2c) == 0) {
                piVar12 = (int *)(*(int *)(unaff_EBP + 0xc) + 0x34);
                do {
                  do {
                  } while (*piVar12 != 0);
                  LOCK();
                  iVar10 = *piVar12;
                  *piVar12 = 1;
                  UNLOCK();
                } while (iVar10 == 1);
                iVar10 = *(int *)(unaff_EBP + 0xc);
                LOCK();
                *(undefined4 *)(iVar10 + 0x34) = 0;
                UNLOCK();
                if (*(int *)(iVar10 + 0x30) != 1) {
                  _vm_object_pmap_copy
                            (*(undefined4 *)(*(int *)(unaff_EBP + -0xc) + 0x10),
                             *(undefined4 *)(*(int *)(unaff_EBP + -0xc) + 0x14));
                  goto LAB_001775cf;
                }
              }
              _pmap_protect(*(undefined4 *)(*(int *)(unaff_EBP + 0xc) + 0x24),
                            *(undefined4 *)(*(int *)(unaff_EBP + -0xc) + 8),
                            *(undefined4 *)(*(int *)(unaff_EBP + -0xc) + 0xc));
            }
LAB_001775cf:
            _vm_object_copy(*(undefined4 *)(*(int *)(unaff_EBP + -0xc) + 0x10),
                            *(undefined4 *)(*(int *)(unaff_EBP + -0xc) + 0x14),
                            *(int *)(*(int *)(unaff_EBP + -0xc) + 0xc) -
                            *(int *)(*(int *)(unaff_EBP + -0xc) + 8),
                            *(int *)(unaff_EBP + -0x10) + 0x10,*(int *)(unaff_EBP + -0x10) + 0x14);
            if (*(int *)(unaff_EBP + -4) != 0) {
              pbVar1 = (byte *)(*(int *)(unaff_EBP + -0xc) + 0x18);
              *pbVar1 = *pbVar1 | 0x40;
            }
            iVar10 = *(int *)(unaff_EBP + -0x10);
            *(byte *)(iVar10 + 0x18) = *(byte *)(iVar10 + 0x18) | 0x40;
            iVar8 = *(int *)(unaff_EBP + -0xc);
            pbVar1 = (byte *)(iVar8 + 0x18);
            *pbVar1 = *pbVar1 | 8;
            *(byte *)(iVar10 + 0x18) = *(byte *)(iVar10 + 0x18) | 8;
            if ((*(byte *)(iVar8 + 0x1c) & 4) != 0) {
              *(uint *)(iVar10 + 0x1c) = *(uint *)(iVar10 + 0x1c) | *(uint *)(iVar10 + 0x20) & 4;
            }
            _vm_object_deallocate();
            iVar10 = *(int *)(*(int *)(unaff_EBP + -0x10) + 8);
            _pmap_copy(*(undefined4 *)(*(int *)(unaff_EBP + 8) + 0x24),
                       *(undefined4 *)(*(int *)(unaff_EBP + 0xc) + 0x24),iVar10,
                       *(int *)(*(int *)(unaff_EBP + -0x10) + 0xc) - iVar10,
                       *(undefined4 *)(*(int *)(unaff_EBP + -0xc) + 8));
          }
          else {
            _vm_fault_copy_entry
                      (*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0xc),
                       *(undefined4 *)(unaff_EBP + -0x10));
          }
        }
      }
      else {
LAB_0017768c:
        *(int *)(unaff_EBP + -0x40) =
             *(int *)(*(int *)(unaff_EBP + -0x10) + 0xc) - *(int *)(*(int *)(unaff_EBP + -0x10) + 8)
        ;
        iVar10 = *(int *)(unaff_EBP + -0xc);
        if ((*(byte *)(iVar10 + 0x18) & 1) == 0) {
          *(undefined4 *)(unaff_EBP + -0x44) = *(undefined4 *)(unaff_EBP + 0xc);
          *(undefined4 *)(unaff_EBP + -0x48) = *(undefined4 *)(*(int *)(unaff_EBP + -0xc) + 8);
          _lock_set_recursive();
        }
        else {
          *(undefined4 *)(unaff_EBP + -0x44) = *(undefined4 *)(iVar10 + 0x10);
          *(undefined4 *)(unaff_EBP + -0x48) = *(undefined4 *)(iVar10 + 0x14);
        }
        iVar10 = *(int *)(unaff_EBP + -0x10);
        if ((*(byte *)(iVar10 + 0x18) & 1) == 0) {
          iVar8 = *(int *)(unaff_EBP + 8);
          *(undefined4 *)(unaff_EBP + -0x3c) = *(undefined4 *)(*(int *)(unaff_EBP + -0x10) + 8);
          _lock_set_recursive();
        }
        else {
          iVar8 = *(int *)(iVar10 + 0x10);
          iVar10 = *(int *)(iVar10 + 0x14);
          *(int *)(unaff_EBP + -0x3c) = iVar10;
          uVar13 = iVar10 + *(int *)(unaff_EBP + -0x40);
          *(uint *)(unaff_EBP + -0x4c) = uVar13;
          if (*(int *)(unaff_EBP + -0x44) != iVar8) {
            _lock_write();
            *(int *)(iVar8 + 0x4c) = *(int *)(iVar8 + 0x4c) + 1;
            uVar5 = *(uint *)(unaff_EBP + -0x3c);
            _vm_map_delete(iVar8,uVar5);
            if ((((*(uint *)(iVar8 + 0x14) <= uVar5) && (uVar13 <= *(uint *)(iVar8 + 0x18))) &&
                (uVar5 < uVar13)) && (iVar10 = _vm_map_lookup_entry(iVar8,uVar5), iVar10 == 0)) {
              iVar10 = *(int *)(unaff_EBP + -4);
              if ((*(int *)(iVar10 + 4) == iVar8 + 0xc) ||
                 (uVar13 <= *(uint *)(*(int *)(iVar10 + 4) + 8))) {
                if ((((iVar10 != iVar8 + 0xc) &&
                     ((*(int *)(iVar10 + 0xc) == *(int *)(unaff_EBP + -0x3c) &&
                      ((*(byte *)(iVar10 + 0x18) & 5) == 0)))) && (*(int *)(iVar10 + 0x24) == 1)) &&
                   (((*(int *)(iVar10 + 0x1c) == 3 && (*(int *)(iVar10 + 0x20) == 7)) &&
                    (*(short *)(iVar10 + 0x28) == 0)))) {
                  iVar9 = *(int *)(iVar10 + 8);
                  uVar3 = *(undefined4 *)(iVar10 + 0x14);
                  uVar6 = *(undefined4 *)(iVar10 + 0x10);
                  *(int *)(unaff_EBP + -0x5c) = iVar10;
                  iVar9 = _vm_object_coalesce(uVar6,0,uVar3,0,*(int *)(unaff_EBP + -0x3c) - iVar9);
                  iVar10 = *(int *)(unaff_EBP + -0x5c);
                  if (iVar9 != 0) {
                    *(int *)(iVar8 + 0x28) =
                         *(int *)(iVar8 + 0x28) +
                         (*(int *)(unaff_EBP + -0x4c) - *(int *)(iVar10 + 0xc));
                    *(undefined4 *)(iVar10 + 0xc) = *(undefined4 *)(unaff_EBP + -0x4c);
                    goto LAB_00177870;
                  }
                }
                *(int *)(unaff_EBP + -0x5c) = iVar10;
                iVar9 = _zalloc();
                *(int *)(unaff_EBP + -0x58) = iVar9;
                iVar10 = *(int *)(unaff_EBP + -0x5c);
                if (iVar9 == 0) {
                  *(int *)(unaff_EBP + -0x5c) = iVar10;
                    /* WARNING: Subroutine does not return */
                  _panic(s_vm_map_entry_create_001e0ab0);
                }
                iVar9 = *(int *)(unaff_EBP + -0x58);
                *(undefined4 *)(iVar9 + 8) = *(undefined4 *)(unaff_EBP + -0x3c);
                *(undefined4 *)(iVar9 + 0xc) = *(undefined4 *)(unaff_EBP + -0x4c);
                *(byte *)(iVar9 + 0x18) = *(byte *)(iVar9 + 0x18) & 0xfa;
                *(undefined4 *)(iVar9 + 0x10) = 0;
                *(undefined4 *)(iVar9 + 0x14) = 0;
                *(byte *)(iVar9 + 0x18) = *(byte *)(iVar9 + 0x18) & 0xb7;
                if (*(int *)(iVar8 + 0x2c) != 0) {
                  *(undefined4 *)(iVar9 + 0x24) = 1;
                  *(undefined4 *)(iVar9 + 0x1c) = 3;
                  *(undefined4 *)(iVar9 + 0x20) = 7;
                  *(undefined2 *)(iVar9 + 0x28) = 0;
                }
                *(int *)(iVar8 + 0x1c) = *(int *)(iVar8 + 0x1c) + 1;
                piVar12 = *(int **)(unaff_EBP + -0x58);
                *piVar12 = iVar10;
                piVar12[1] = *(int *)(iVar10 + 4);
                iVar9 = *piVar12;
                *(int **)piVar12[1] = piVar12;
                *(int **)(iVar9 + 4) = piVar12;
                *(int *)(iVar8 + 0x28) = *(int *)(iVar8 + 0x28) + (piVar12[3] - piVar12[2]);
                if ((*(int *)(iVar8 + 0x40) == iVar10) &&
                   (*(uint *)(*(int *)(unaff_EBP + -0x58) + 8) <= *(uint *)(iVar10 + 0xc))) {
                  *(int *)(iVar8 + 0x40) = *(int *)(unaff_EBP + -0x58);
                }
              }
            }
LAB_00177870:
            _lock_done();
          }
        }
        _vm_map_copy(iVar8,*(undefined4 *)(unaff_EBP + -0x44),*(undefined4 *)(unaff_EBP + -0x3c),
                     *(undefined4 *)(unaff_EBP + -0x40),*(undefined4 *)(unaff_EBP + -0x48),0);
        if (*(int *)(unaff_EBP + 8) == iVar8) {
          _lock_clear_recursive();
        }
        if (*(int *)(unaff_EBP + 0xc) == *(int *)(unaff_EBP + -0x44)) {
          _lock_clear_recursive();
        }
      }
      *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(*(int *)(unaff_EBP + -0xc) + 0xc);
      *(undefined4 *)(unaff_EBP + -0xc) = *(undefined4 *)(*(int *)(unaff_EBP + -0xc) + 4);
      *(undefined4 *)(unaff_EBP + -0x10) = *(undefined4 *)(*(int *)(unaff_EBP + -0x10) + 4);
    } while (*(uint *)(unaff_EBP + -0x14) < *(uint *)(unaff_EBP + -0x18));
  }
LAB_00177a31:
  if (*(int *)(unaff_EBP + -0x28) != 0) {
    _vm_map_delete(*(undefined4 *)(unaff_EBP + 0xc),*(undefined4 *)(unaff_EBP + 0x18));
  }
  iVar10 = *(int *)(unaff_EBP + 0xc);
  _lock_done();
  if (iVar10 != *(int *)(unaff_EBP + 8)) {
    _lock_done();
  }
  return *(undefined4 *)(unaff_EBP + -0x24);
LAB_00176f1c:
  puVar11 = (undefined4 *)puVar11[1];
  goto LAB_00176f1f;
LAB_001770d0:
  puVar11 = (undefined4 *)puVar11[1];
  goto LAB_001770d3;
}

