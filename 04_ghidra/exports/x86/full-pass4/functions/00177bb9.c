/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00177bb9 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

undefined4 __analysis_fragment_00177bb9(void)

{
  byte *pbVar1;
  int iVar2;
  byte bVar3;
  int iVar4;
  int *piVar5;
  int unaff_EBX;
  int unaff_EBP;
  undefined4 unaff_ESI;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  
  do {
    iVar4 = unaff_EBX + 0xc;
    *(int *)(unaff_EBX + 0x10) = iVar4;
    *(int *)(unaff_EBX + 0xc) = iVar4;
    *(undefined4 *)(unaff_EBX + 0x1c) = 0;
    *(undefined4 *)(unaff_EBX + 0x20) = 1;
    *(undefined4 *)(unaff_EBX + 0x28) = 0;
    *(undefined4 *)(unaff_EBX + 0x30) = 1;
    *(undefined4 *)(unaff_EBX + 0x24) = 0;
    *(undefined4 *)(unaff_EBX + 0x2c) = 1;
    *(undefined4 *)(unaff_EBX + 0x14) = unaff_ESI;
    *(undefined4 *)(unaff_EBX + 0x18) = *(undefined4 *)(unaff_EBP + -0x18);
    *(undefined4 *)(unaff_EBX + 0x48) = 0;
    *(undefined4 *)(unaff_EBX + 0x44) = 0;
    *(int *)(unaff_EBX + 0x40) = iVar4;
    *(int *)(unaff_EBX + 0x38) = iVar4;
    *(undefined4 *)(unaff_EBX + 0x4c) = 0;
    _lock_init(unaff_EBX);
    *(undefined4 *)(unaff_EBX + 0x4c) = 0;
    *(undefined4 *)(unaff_EBX + 0x34) = 0;
    *(undefined4 *)(unaff_EBX + 0x3c) = 0;
    *(undefined4 *)(unaff_EBX + 0x2c) = 0;
    iVar4 = _zalloc();
    *(int *)(unaff_EBP + -0x18) = iVar4;
    if (iVar4 == 0) {
                    /* WARNING: Subroutine does not return */
      _panic(s_vm_map_entry_create_001e0ab0);
    }
    puVar6 = *(undefined4 **)(unaff_EBP + -0xc);
    puVar7 = *(undefined4 **)(unaff_EBP + -0x18);
    for (iVar4 = 0xb; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar7 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar7 = puVar7 + 1;
    }
    *(int *)(unaff_EBX + 0x1c) = *(int *)(unaff_EBX + 0x1c) + 1;
    piVar5 = *(int **)(unaff_EBP + -0x18);
    *piVar5 = *(int *)(unaff_EBX + 0xc);
    piVar5[1] = *(int *)(*(int *)(unaff_EBX + 0xc) + 4);
    iVar4 = *piVar5;
    *(int **)piVar5[1] = piVar5;
    *(int **)(iVar4 + 4) = piVar5;
    iVar4 = *(int *)(unaff_EBP + -0xc);
    pbVar1 = (byte *)(iVar4 + 0x18);
    *pbVar1 = *pbVar1 | 1;
    *(int *)(iVar4 + 0x10) = unaff_EBX;
    *(undefined4 *)(*(int *)(unaff_EBP + -0xc) + 0x14) =
         *(undefined4 *)(*(int *)(unaff_EBP + -0xc) + 8);
    do {
      iVar4 = _zalloc();
      if (iVar4 == 0) {
                    /* WARNING: Subroutine does not return */
        _panic(s_vm_map_entry_create_001e0ab0);
      }
      *(int *)(unaff_EBP + -0x18) = iVar4;
      puVar6 = *(undefined4 **)(unaff_EBP + -0x18);
      puVar7 = *(undefined4 **)(unaff_EBP + -0xc);
      puVar8 = puVar6;
      for (iVar4 = 0xb; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar8 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar8 = puVar8 + 1;
      }
      iVar4 = puVar6[4];
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
      iVar4 = *(int *)(unaff_EBP + -8);
      piVar5 = (int *)(iVar4 + 0x1c);
      *piVar5 = *piVar5 + 1;
      **(undefined4 **)(unaff_EBP + -0x18) = *(undefined4 *)(iVar4 + 0xc);
      piVar5 = *(int **)(unaff_EBP + -0x18);
      piVar5[1] = *(int *)(*(int *)(*(int *)(unaff_EBP + -8) + 0xc) + 4);
      iVar4 = *piVar5;
      *(int **)piVar5[1] = piVar5;
      *(int **)(iVar4 + 4) = piVar5;
      _pmap_copy(*(undefined4 *)(*(int *)(unaff_EBP + -8) + 0x24),
                 *(undefined4 *)(*(int *)(unaff_EBP + 8) + 0x24),
                 *(undefined4 *)(*(int *)(unaff_EBP + -0x18) + 8),
                 *(int *)(*(int *)(unaff_EBP + -0xc) + 0xc) -
                 *(int *)(*(int *)(unaff_EBP + -0xc) + 8));
      do {
        while( true ) {
          iVar4 = *(int *)(*(int *)(unaff_EBP + -0xc) + 4);
          *(int *)(unaff_EBP + -0xc) = iVar4;
          if (iVar4 == *(int *)(unaff_EBP + 8) + 0xc) {
            *(undefined4 *)(*(int *)(unaff_EBP + -8) + 0x28) =
                 *(undefined4 *)(*(int *)(unaff_EBP + 8) + 0x28);
            _lock_done();
            return *(undefined4 *)(unaff_EBP + -8);
          }
          if ((*(byte *)(*(int *)(unaff_EBP + -0xc) + 0x18) & 4) != 0) {
                    /* WARNING: Subroutine does not return */
            _panic(s_vm_map_fork__encountered_a_subma_001e0ac4);
          }
          iVar4 = *(int *)(unaff_EBP + -0xc);
          iVar2 = *(int *)(iVar4 + 0x24);
          if (iVar2 != 1) break;
          iVar4 = _zalloc();
          if (iVar4 == 0) {
                    /* WARNING: Subroutine does not return */
            _panic(s_vm_map_entry_create_001e0ab0);
          }
          *(int *)(unaff_EBP + -0x18) = iVar4;
          puVar6 = *(undefined4 **)(unaff_EBP + -0x18);
          puVar7 = *(undefined4 **)(unaff_EBP + -0xc);
          puVar8 = puVar6;
          for (iVar4 = 0xb; iVar4 != 0; iVar4 = iVar4 + -1) {
            *puVar8 = *puVar7;
            puVar7 = puVar7 + 1;
            puVar8 = puVar8 + 1;
          }
          *(undefined2 *)(puVar6 + 10) = 0;
          puVar6 = *(undefined4 **)(unaff_EBP + -0x18);
          puVar6[4] = 0;
          *(byte *)(puVar6 + 6) = *(byte *)(puVar6 + 6) & 0xfe;
          iVar4 = *(int *)(unaff_EBP + -8);
          piVar5 = (int *)(iVar4 + 0x1c);
          *piVar5 = *piVar5 + 1;
          *puVar6 = *(undefined4 *)(iVar4 + 0xc);
          piVar5 = *(int **)(unaff_EBP + -0x18);
          piVar5[1] = *(int *)(*(int *)(*(int *)(unaff_EBP + -8) + 0xc) + 4);
          iVar4 = *piVar5;
          *(int **)piVar5[1] = piVar5;
          *(int **)(iVar4 + 4) = piVar5;
          bVar3 = *(byte *)(*(int *)(unaff_EBP + -0xc) + 0x18);
          if ((bVar3 & 1) == 0) {
            if (((bVar3 & 4) == 0) &&
               (iVar4 = *(int *)(unaff_EBP + -0x18), (*(byte *)(iVar4 + 0x18) & 4) == 0)) {
              if (*(short *)(iVar4 + 0x28) != 0) {
                _vm_fault_unwire(*(undefined4 *)(unaff_EBP + -8));
                *(undefined2 *)(iVar4 + 0x28) = 0;
              }
              if (*(int *)(*(int *)(unaff_EBP + -8) + 0x2c) == 0) {
                _vm_object_pmap_remove
                          (*(undefined4 *)(*(int *)(unaff_EBP + -0x18) + 0x10),
                           *(undefined4 *)(*(int *)(unaff_EBP + -0x18) + 0x14));
              }
              _pmap_remove(*(undefined4 *)(*(int *)(unaff_EBP + -8) + 0x24),
                           *(undefined4 *)(*(int *)(unaff_EBP + -0x18) + 8));
              if (*(short *)(*(int *)(unaff_EBP + -0xc) + 0x28) == 0) {
                if ((*(byte *)(*(int *)(unaff_EBP + -0xc) + 0x18) & 0x40) == 0) {
                  if (*(int *)(*(int *)(unaff_EBP + 8) + 0x2c) == 0) {
                    piVar5 = (int *)(*(int *)(unaff_EBP + 8) + 0x34);
                    do {
                      do {
                      } while (*piVar5 != 0);
                      LOCK();
                      iVar4 = *piVar5;
                      *piVar5 = 1;
                      UNLOCK();
                    } while (iVar4 == 1);
                    iVar4 = *(int *)(unaff_EBP + 8);
                    LOCK();
                    *(undefined4 *)(iVar4 + 0x34) = 0;
                    UNLOCK();
                    if (*(int *)(iVar4 + 0x30) != 1) {
                      _vm_object_pmap_copy
                                (*(undefined4 *)(*(int *)(unaff_EBP + -0xc) + 0x10),
                                 *(undefined4 *)(*(int *)(unaff_EBP + -0xc) + 0x14));
                      goto LAB_00177f3f;
                    }
                  }
                  _pmap_protect(*(undefined4 *)(*(int *)(unaff_EBP + 8) + 0x24),
                                *(undefined4 *)(*(int *)(unaff_EBP + -0xc) + 8),
                                *(undefined4 *)(*(int *)(unaff_EBP + -0xc) + 0xc));
                }
LAB_00177f3f:
                _vm_object_copy(*(undefined4 *)(*(int *)(unaff_EBP + -0xc) + 0x10),
                                *(undefined4 *)(*(int *)(unaff_EBP + -0xc) + 0x14),
                                *(int *)(*(int *)(unaff_EBP + -0xc) + 0xc) -
                                *(int *)(*(int *)(unaff_EBP + -0xc) + 8),
                                *(int *)(unaff_EBP + -0x18) + 0x10,
                                *(int *)(unaff_EBP + -0x18) + 0x14);
                if (*(int *)(unaff_EBP + -4) != 0) {
                  pbVar1 = (byte *)(*(int *)(unaff_EBP + -0xc) + 0x18);
                  *pbVar1 = *pbVar1 | 0x40;
                }
                iVar4 = *(int *)(unaff_EBP + -0x18);
                *(byte *)(iVar4 + 0x18) = *(byte *)(iVar4 + 0x18) | 0x40;
                iVar2 = *(int *)(unaff_EBP + -0xc);
                pbVar1 = (byte *)(iVar2 + 0x18);
                *pbVar1 = *pbVar1 | 8;
                *(byte *)(iVar4 + 0x18) = *(byte *)(iVar4 + 0x18) | 8;
                if ((*(byte *)(iVar2 + 0x1c) & 4) != 0) {
                  *(uint *)(iVar4 + 0x1c) = *(uint *)(iVar4 + 0x1c) | *(uint *)(iVar4 + 0x20) & 4;
                }
                _vm_object_deallocate();
                iVar4 = *(int *)(*(int *)(unaff_EBP + -0x18) + 8);
                _pmap_copy(*(undefined4 *)(*(int *)(unaff_EBP + -8) + 0x24),
                           *(undefined4 *)(*(int *)(unaff_EBP + 8) + 0x24),iVar4,
                           *(int *)(*(int *)(unaff_EBP + -0x18) + 0xc) - iVar4,
                           *(undefined4 *)(*(int *)(unaff_EBP + -0xc) + 8));
              }
              else {
                _vm_fault_copy_entry
                          (*(undefined4 *)(unaff_EBP + -8),*(undefined4 *)(unaff_EBP + 8),
                           *(undefined4 *)(unaff_EBP + -0x18));
              }
            }
          }
          else {
            iVar4 = *(int *)(*(int *)(unaff_EBP + -0x18) + 8);
            iVar4 = _vm_map_copy(*(undefined4 *)(unaff_EBP + -8),
                                 *(undefined4 *)(*(int *)(unaff_EBP + -0xc) + 0x10),iVar4,
                                 *(int *)(*(int *)(unaff_EBP + -0x18) + 0xc) - iVar4,
                                 *(undefined4 *)(*(int *)(unaff_EBP + -0xc) + 0x14),0);
            if (iVar4 != 0) {
              _printf(s_vm_map_fork__copy_in_share_map_r_001e0ae6);
            }
          }
        }
      } while ((1 < iVar2) || (iVar2 != 0));
    } while ((*(byte *)(iVar4 + 0x18) & 1) != 0);
    unaff_ESI = *(undefined4 *)(iVar4 + 8);
    *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(iVar4 + 0xc);
    unaff_EBX = _zalloc();
    if (unaff_EBX == 0) {
                    /* WARNING: Subroutine does not return */
      _panic(s_vm_map_create_001e0aa2);
    }
  } while( true );
}

