/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017733c */

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

undefined4 __analysis_fragment_0017733c(void)

{
  byte *pbVar1;
  byte bVar2;
  int *piVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  uint unaff_EBX;
  uint uVar11;
  int unaff_EBP;
  undefined4 *puVar12;
  undefined4 *puVar13;
  
  iVar7 = *(int *)(unaff_EBP + -0x50);
  do {
    *(undefined4 *)(unaff_EBP + -0x54) = *(undefined4 *)(unaff_EBP + -0x34);
    *(undefined4 **)(unaff_EBP + -0x58) = *(undefined4 **)(unaff_EBP + -0xc);
    puVar12 = *(undefined4 **)(unaff_EBP + -0xc);
    puVar13 = *(undefined4 **)(unaff_EBP + -0x54);
    for (iVar9 = 0xb; iVar9 != 0; iVar9 = iVar9 + -1) {
      *puVar13 = *puVar12;
      puVar12 = puVar12 + 1;
      puVar13 = puVar13 + 1;
    }
    iVar9 = *(int *)(unaff_EBP + -0xc);
    *(uint *)(iVar9 + 0xc) = unaff_EBX;
    piVar10 = *(int **)(unaff_EBP + -0x54);
    piVar10[2] = unaff_EBX;
    piVar10[5] = piVar10[5] + (unaff_EBX - *(int *)(iVar9 + 8));
    *(int *)(iVar7 + 0x10) = *(int *)(iVar7 + 0x10) + 1;
    *piVar10 = iVar9;
    piVar10[1] = *(int *)(iVar9 + 4);
    iVar7 = *piVar10;
    *(int **)piVar10[1] = piVar10;
    *(int **)(iVar7 + 4) = piVar10;
    if ((*(byte *)(*(int *)(unaff_EBP + -0xc) + 0x18) & 5) == 0) {
      _vm_object_reference();
    }
    else {
      iVar7 = *(int *)(*(int *)(unaff_EBP + -0x54) + 0x10);
      if (iVar7 != 0) {
        piVar10 = (int *)(iVar7 + 0x34);
        do {
          do {
          } while (*piVar10 != 0);
          LOCK();
          iVar9 = *piVar10;
          *piVar10 = 1;
          UNLOCK();
        } while (iVar9 == 1);
        *(int *)(iVar7 + 0x30) = *(int *)(iVar7 + 0x30) + 1;
        LOCK();
        *(undefined4 *)(iVar7 + 0x34) = 0;
        UNLOCK();
      }
    }
    do {
      uVar11 = *(int *)(*(int *)(unaff_EBP + -0x10) + 8) +
               (*(int *)(*(int *)(unaff_EBP + -0xc) + 0xc) -
               *(int *)(*(int *)(unaff_EBP + -0xc) + 8));
      if (uVar11 < *(uint *)(*(int *)(unaff_EBP + -0x10) + 0xc)) {
        *(int *)(unaff_EBP + -0x50) = *(int *)(unaff_EBP + 8) + 0xc;
        iVar9 = _zalloc();
        *(int *)(unaff_EBP + -0x38) = iVar9;
        iVar7 = *(int *)(unaff_EBP + -0x50);
        if (iVar9 == 0) {
          *(int *)(unaff_EBP + -0x50) = iVar7;
                    /* WARNING: Subroutine does not return */
          _panic(s_vm_map_entry_create_001e0ab0);
        }
        *(undefined4 *)(unaff_EBP + -0x54) = *(undefined4 *)(unaff_EBP + -0x38);
        *(undefined4 **)(unaff_EBP + -0x58) = *(undefined4 **)(unaff_EBP + -0x10);
        puVar12 = *(undefined4 **)(unaff_EBP + -0x10);
        puVar13 = *(undefined4 **)(unaff_EBP + -0x54);
        for (iVar9 = 0xb; iVar9 != 0; iVar9 = iVar9 + -1) {
          *puVar13 = *puVar12;
          puVar12 = puVar12 + 1;
          puVar13 = puVar13 + 1;
        }
        iVar9 = *(int *)(unaff_EBP + -0x10);
        *(uint *)(iVar9 + 0xc) = uVar11;
        piVar3 = *(int **)(unaff_EBP + -0x54);
        piVar3[2] = uVar11;
        piVar3[5] = piVar3[5] + (uVar11 - *(int *)(iVar9 + 8));
        piVar10 = (int *)(iVar7 + 0x10);
        *piVar10 = *piVar10 + 1;
        *piVar3 = iVar9;
        piVar3[1] = *(int *)(iVar9 + 4);
        iVar7 = *piVar3;
        *(int **)piVar3[1] = piVar3;
        *(int **)(iVar7 + 4) = piVar3;
        if ((*(byte *)(*(int *)(unaff_EBP + -0x10) + 0x18) & 5) == 0) {
          _vm_object_reference();
        }
        else {
          iVar7 = *(int *)(*(int *)(unaff_EBP + -0x54) + 0x10);
          if (iVar7 != 0) {
            piVar10 = (int *)(iVar7 + 0x34);
            do {
              do {
              } while (*piVar10 != 0);
              LOCK();
              iVar9 = *piVar10;
              *piVar10 = 1;
              UNLOCK();
            } while (iVar9 == 1);
            *(int *)(iVar7 + 0x30) = *(int *)(iVar7 + 0x30) + 1;
            LOCK();
            *(undefined4 *)(iVar7 + 0x34) = 0;
            UNLOCK();
          }
        }
      }
      bVar2 = *(byte *)(*(int *)(unaff_EBP + -0xc) + 0x18);
      if ((bVar2 & 1) == 0) {
        iVar7 = *(int *)(unaff_EBP + -0x10);
        if ((*(byte *)(iVar7 + 0x18) & 1) != 0) goto LAB_0017768c;
        if (((bVar2 & 4) == 0) && ((*(byte *)(iVar7 + 0x18) & 4) == 0)) {
          if (*(short *)(iVar7 + 0x28) != 0) {
            _vm_fault_unwire(*(undefined4 *)(unaff_EBP + 8));
            *(undefined2 *)(iVar7 + 0x28) = 0;
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
                piVar10 = (int *)(*(int *)(unaff_EBP + 0xc) + 0x34);
                do {
                  do {
                  } while (*piVar10 != 0);
                  LOCK();
                  iVar7 = *piVar10;
                  *piVar10 = 1;
                  UNLOCK();
                } while (iVar7 == 1);
                iVar7 = *(int *)(unaff_EBP + 0xc);
                LOCK();
                *(undefined4 *)(iVar7 + 0x34) = 0;
                UNLOCK();
                if (*(int *)(iVar7 + 0x30) != 1) {
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
            iVar7 = *(int *)(unaff_EBP + -0x10);
            *(byte *)(iVar7 + 0x18) = *(byte *)(iVar7 + 0x18) | 0x40;
            iVar9 = *(int *)(unaff_EBP + -0xc);
            pbVar1 = (byte *)(iVar9 + 0x18);
            *pbVar1 = *pbVar1 | 8;
            *(byte *)(iVar7 + 0x18) = *(byte *)(iVar7 + 0x18) | 8;
            if ((*(byte *)(iVar9 + 0x1c) & 4) != 0) {
              *(uint *)(iVar7 + 0x1c) = *(uint *)(iVar7 + 0x1c) | *(uint *)(iVar7 + 0x20) & 4;
            }
            _vm_object_deallocate();
            iVar7 = *(int *)(*(int *)(unaff_EBP + -0x10) + 8);
            _pmap_copy(*(undefined4 *)(*(int *)(unaff_EBP + 8) + 0x24),
                       *(undefined4 *)(*(int *)(unaff_EBP + 0xc) + 0x24),iVar7,
                       *(int *)(*(int *)(unaff_EBP + -0x10) + 0xc) - iVar7,
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
        iVar7 = *(int *)(unaff_EBP + -0xc);
        if ((*(byte *)(iVar7 + 0x18) & 1) == 0) {
          *(undefined4 *)(unaff_EBP + -0x44) = *(undefined4 *)(unaff_EBP + 0xc);
          *(undefined4 *)(unaff_EBP + -0x48) = *(undefined4 *)(*(int *)(unaff_EBP + -0xc) + 8);
          _lock_set_recursive();
        }
        else {
          *(undefined4 *)(unaff_EBP + -0x44) = *(undefined4 *)(iVar7 + 0x10);
          *(undefined4 *)(unaff_EBP + -0x48) = *(undefined4 *)(iVar7 + 0x14);
        }
        iVar7 = *(int *)(unaff_EBP + -0x10);
        if ((*(byte *)(iVar7 + 0x18) & 1) == 0) {
          iVar9 = *(int *)(unaff_EBP + 8);
          *(undefined4 *)(unaff_EBP + -0x3c) = *(undefined4 *)(*(int *)(unaff_EBP + -0x10) + 8);
          _lock_set_recursive();
        }
        else {
          iVar9 = *(int *)(iVar7 + 0x10);
          iVar7 = *(int *)(iVar7 + 0x14);
          *(int *)(unaff_EBP + -0x3c) = iVar7;
          uVar11 = iVar7 + *(int *)(unaff_EBP + -0x40);
          *(uint *)(unaff_EBP + -0x4c) = uVar11;
          if (*(int *)(unaff_EBP + -0x44) != iVar9) {
            _lock_write();
            *(int *)(iVar9 + 0x4c) = *(int *)(iVar9 + 0x4c) + 1;
            uVar4 = *(uint *)(unaff_EBP + -0x3c);
            _vm_map_delete(iVar9,uVar4);
            if ((((*(uint *)(iVar9 + 0x14) <= uVar4) && (uVar11 <= *(uint *)(iVar9 + 0x18))) &&
                (uVar4 < uVar11)) && (iVar7 = _vm_map_lookup_entry(iVar9,uVar4), iVar7 == 0)) {
              iVar7 = *(int *)(unaff_EBP + -4);
              if ((*(int *)(iVar7 + 4) == iVar9 + 0xc) ||
                 (uVar11 <= *(uint *)(*(int *)(iVar7 + 4) + 8))) {
                if ((((iVar7 != iVar9 + 0xc) &&
                     ((*(int *)(iVar7 + 0xc) == *(int *)(unaff_EBP + -0x3c) &&
                      ((*(byte *)(iVar7 + 0x18) & 5) == 0)))) && (*(int *)(iVar7 + 0x24) == 1)) &&
                   (((*(int *)(iVar7 + 0x1c) == 3 && (*(int *)(iVar7 + 0x20) == 7)) &&
                    (*(short *)(iVar7 + 0x28) == 0)))) {
                  iVar8 = *(int *)(iVar7 + 8);
                  uVar5 = *(undefined4 *)(iVar7 + 0x14);
                  uVar6 = *(undefined4 *)(iVar7 + 0x10);
                  *(int *)(unaff_EBP + -0x5c) = iVar7;
                  iVar8 = _vm_object_coalesce(uVar6,0,uVar5,0,*(int *)(unaff_EBP + -0x3c) - iVar8);
                  iVar7 = *(int *)(unaff_EBP + -0x5c);
                  if (iVar8 != 0) {
                    *(int *)(iVar9 + 0x28) =
                         *(int *)(iVar9 + 0x28) +
                         (*(int *)(unaff_EBP + -0x4c) - *(int *)(iVar7 + 0xc));
                    *(undefined4 *)(iVar7 + 0xc) = *(undefined4 *)(unaff_EBP + -0x4c);
                    goto LAB_00177870;
                  }
                }
                *(int *)(unaff_EBP + -0x5c) = iVar7;
                iVar8 = _zalloc();
                *(int *)(unaff_EBP + -0x58) = iVar8;
                iVar7 = *(int *)(unaff_EBP + -0x5c);
                if (iVar8 == 0) {
                  *(int *)(unaff_EBP + -0x5c) = iVar7;
                    /* WARNING: Subroutine does not return */
                  _panic(s_vm_map_entry_create_001e0ab0);
                }
                iVar8 = *(int *)(unaff_EBP + -0x58);
                *(undefined4 *)(iVar8 + 8) = *(undefined4 *)(unaff_EBP + -0x3c);
                *(undefined4 *)(iVar8 + 0xc) = *(undefined4 *)(unaff_EBP + -0x4c);
                *(byte *)(iVar8 + 0x18) = *(byte *)(iVar8 + 0x18) & 0xfa;
                *(undefined4 *)(iVar8 + 0x10) = 0;
                *(undefined4 *)(iVar8 + 0x14) = 0;
                *(byte *)(iVar8 + 0x18) = *(byte *)(iVar8 + 0x18) & 0xb7;
                if (*(int *)(iVar9 + 0x2c) != 0) {
                  *(undefined4 *)(iVar8 + 0x24) = 1;
                  *(undefined4 *)(iVar8 + 0x1c) = 3;
                  *(undefined4 *)(iVar8 + 0x20) = 7;
                  *(undefined2 *)(iVar8 + 0x28) = 0;
                }
                *(int *)(iVar9 + 0x1c) = *(int *)(iVar9 + 0x1c) + 1;
                piVar10 = *(int **)(unaff_EBP + -0x58);
                *piVar10 = iVar7;
                piVar10[1] = *(int *)(iVar7 + 4);
                iVar8 = *piVar10;
                *(int **)piVar10[1] = piVar10;
                *(int **)(iVar8 + 4) = piVar10;
                *(int *)(iVar9 + 0x28) = *(int *)(iVar9 + 0x28) + (piVar10[3] - piVar10[2]);
                if ((*(int *)(iVar9 + 0x40) == iVar7) &&
                   (*(uint *)(*(int *)(unaff_EBP + -0x58) + 8) <= *(uint *)(iVar7 + 0xc))) {
                  *(int *)(iVar9 + 0x40) = *(int *)(unaff_EBP + -0x58);
                }
              }
            }
LAB_00177870:
            _lock_done();
          }
        }
        _vm_map_copy(iVar9,*(undefined4 *)(unaff_EBP + -0x44),*(undefined4 *)(unaff_EBP + -0x3c),
                     *(undefined4 *)(unaff_EBP + -0x40),*(undefined4 *)(unaff_EBP + -0x48),0);
        if (*(int *)(unaff_EBP + 8) == iVar9) {
          _lock_clear_recursive();
        }
        if (*(int *)(unaff_EBP + 0xc) == *(int *)(unaff_EBP + -0x44)) {
          _lock_clear_recursive();
        }
      }
      *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(*(int *)(unaff_EBP + -0xc) + 0xc);
      *(undefined4 *)(unaff_EBP + -0xc) = *(undefined4 *)(*(int *)(unaff_EBP + -0xc) + 4);
      *(undefined4 *)(unaff_EBP + -0x10) = *(undefined4 *)(*(int *)(unaff_EBP + -0x10) + 4);
      if (*(uint *)(unaff_EBP + -0x18) <= *(uint *)(unaff_EBP + -0x14)) {
        if (*(int *)(unaff_EBP + -0x28) != 0) {
          _vm_map_delete(*(undefined4 *)(unaff_EBP + 0xc),*(undefined4 *)(unaff_EBP + 0x18));
        }
        iVar7 = *(int *)(unaff_EBP + 0xc);
        _lock_done();
        if (iVar7 != *(int *)(unaff_EBP + 8)) {
          _lock_done();
        }
        return *(undefined4 *)(unaff_EBP + -0x24);
      }
      if (*(uint *)(unaff_EBP + -0x18) < *(uint *)(*(int *)(unaff_EBP + -0xc) + 0xc)) {
        *(int *)(unaff_EBP + -0x50) = *(int *)(unaff_EBP + 0xc) + 0xc;
        iVar9 = _zalloc();
        iVar7 = *(int *)(unaff_EBP + -0x50);
        if (iVar9 == 0) {
          *(int *)(unaff_EBP + -0x50) = iVar7;
                    /* WARNING: Subroutine does not return */
          _panic(s_vm_map_entry_create_001e0ab0);
        }
        *(int *)(unaff_EBP + -0x54) = iVar9;
        *(undefined4 *)(unaff_EBP + -0x58) = *(undefined4 *)(unaff_EBP + -0xc);
        puVar12 = *(undefined4 **)(unaff_EBP + -0x58);
        puVar13 = *(undefined4 **)(unaff_EBP + -0x54);
        for (iVar9 = 0xb; iVar9 != 0; iVar9 = iVar9 + -1) {
          *puVar13 = *puVar12;
          puVar12 = puVar12 + 1;
          puVar13 = puVar13 + 1;
        }
        iVar9 = *(int *)(unaff_EBP + -0x18);
        *(int *)(*(int *)(unaff_EBP + -0xc) + 0xc) = iVar9;
        piVar3 = *(int **)(unaff_EBP + -0x54);
        piVar3[2] = iVar9;
        iVar9 = *(int *)(unaff_EBP + -0xc);
        piVar3[5] = piVar3[5] + (*(int *)(unaff_EBP + -0x18) - *(int *)(iVar9 + 8));
        piVar10 = (int *)(iVar7 + 0x10);
        *piVar10 = *piVar10 + 1;
        *piVar3 = iVar9;
        piVar3[1] = *(int *)(iVar9 + 4);
        iVar7 = *piVar3;
        *(int **)piVar3[1] = piVar3;
        *(int **)(iVar7 + 4) = piVar3;
        if ((*(byte *)(*(int *)(unaff_EBP + -0xc) + 0x18) & 5) == 0) {
          _vm_object_reference();
        }
        else {
          iVar7 = *(int *)(*(int *)(unaff_EBP + -0x54) + 0x10);
          if (iVar7 != 0) {
            piVar10 = (int *)(iVar7 + 0x34);
            do {
              do {
              } while (*piVar10 != 0);
              LOCK();
              iVar9 = *piVar10;
              *piVar10 = 1;
              UNLOCK();
            } while (iVar9 == 1);
            *(int *)(iVar7 + 0x30) = *(int *)(iVar7 + 0x30) + 1;
            LOCK();
            *(undefined4 *)(iVar7 + 0x34) = 0;
            UNLOCK();
          }
        }
      }
      if (*(uint *)(unaff_EBP + -0x20) < *(uint *)(*(int *)(unaff_EBP + -0x10) + 0xc)) {
        *(int *)(unaff_EBP + -0x50) = *(int *)(unaff_EBP + 8) + 0xc;
        iVar9 = _zalloc();
        iVar7 = *(int *)(unaff_EBP + -0x50);
        if (iVar9 == 0) {
          *(int *)(unaff_EBP + -0x50) = iVar7;
                    /* WARNING: Subroutine does not return */
          _panic(s_vm_map_entry_create_001e0ab0);
        }
        *(int *)(unaff_EBP + -0x54) = iVar9;
        *(undefined4 *)(unaff_EBP + -0x58) = *(undefined4 *)(unaff_EBP + -0x10);
        puVar12 = *(undefined4 **)(unaff_EBP + -0x58);
        puVar13 = *(undefined4 **)(unaff_EBP + -0x54);
        for (iVar9 = 0xb; iVar9 != 0; iVar9 = iVar9 + -1) {
          *puVar13 = *puVar12;
          puVar12 = puVar12 + 1;
          puVar13 = puVar13 + 1;
        }
        iVar9 = *(int *)(unaff_EBP + -0x20);
        *(int *)(*(int *)(unaff_EBP + -0x10) + 0xc) = iVar9;
        piVar3 = *(int **)(unaff_EBP + -0x54);
        piVar3[2] = iVar9;
        iVar9 = *(int *)(unaff_EBP + -0x10);
        piVar3[5] = piVar3[5] + (*(int *)(unaff_EBP + -0x20) - *(int *)(iVar9 + 8));
        piVar10 = (int *)(iVar7 + 0x10);
        *piVar10 = *piVar10 + 1;
        *piVar3 = iVar9;
        piVar3[1] = *(int *)(iVar9 + 4);
        iVar7 = *piVar3;
        *(int **)piVar3[1] = piVar3;
        *(int **)(iVar7 + 4) = piVar3;
        if ((*(byte *)(*(int *)(unaff_EBP + -0x10) + 0x18) & 5) == 0) {
          _vm_object_reference();
        }
        else {
          iVar7 = *(int *)(*(int *)(unaff_EBP + -0x54) + 0x10);
          if (iVar7 != 0) {
            piVar10 = (int *)(iVar7 + 0x34);
            do {
              do {
              } while (*piVar10 != 0);
              LOCK();
              iVar9 = *piVar10;
              *piVar10 = 1;
              UNLOCK();
            } while (iVar9 == 1);
            *(int *)(iVar7 + 0x30) = *(int *)(iVar7 + 0x30) + 1;
            LOCK();
            *(undefined4 *)(iVar7 + 0x34) = 0;
            UNLOCK();
          }
        }
      }
      unaff_EBX = *(int *)(*(int *)(unaff_EBP + -0xc) + 8) +
                  (*(int *)(*(int *)(unaff_EBP + -0x10) + 0xc) -
                  *(int *)(*(int *)(unaff_EBP + -0x10) + 8));
    } while (*(uint *)(*(int *)(unaff_EBP + -0xc) + 0xc) <= unaff_EBX);
    *(int *)(unaff_EBP + -0x50) = *(int *)(unaff_EBP + 0xc) + 0xc;
    iVar9 = _zalloc();
    *(int *)(unaff_EBP + -0x34) = iVar9;
    iVar7 = *(int *)(unaff_EBP + -0x50);
    if (iVar9 == 0) {
      *(int *)(unaff_EBP + -0x50) = iVar7;
                    /* WARNING: Subroutine does not return */
      _panic(s_vm_map_entry_create_001e0ab0);
    }
  } while( true );
}

