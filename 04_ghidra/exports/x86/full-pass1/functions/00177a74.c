/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00177a74 */

int _vm_map_fork(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  int *piVar9;
  int iVar10;
  int *piVar11;
  int *piVar12;
  int *piVar13;
  int local_8;
  
  _lock_write(param_1);
  *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
  uVar5 = _pmap_create(0);
  uVar8 = *(undefined4 *)(param_1 + 0x14);
  uVar2 = *(undefined4 *)(param_1 + 0x18);
  uVar3 = *(undefined4 *)(param_1 + 0x20);
  iVar6 = _zalloc(_vm_map_zone);
  if (iVar6 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(s_vm_map_create_001e0aa2);
  }
  iVar10 = iVar6 + 0xc;
  *(int *)(iVar6 + 0x10) = iVar10;
  *(int *)(iVar6 + 0xc) = iVar10;
  *(undefined4 *)(iVar6 + 0x1c) = 0;
  *(undefined4 *)(iVar6 + 0x20) = uVar3;
  *(undefined4 *)(iVar6 + 0x28) = 0;
  *(undefined4 *)(iVar6 + 0x30) = 1;
  *(undefined4 *)(iVar6 + 0x24) = uVar5;
  *(undefined4 *)(iVar6 + 0x2c) = 1;
  *(undefined4 *)(iVar6 + 0x14) = uVar8;
  *(undefined4 *)(iVar6 + 0x18) = uVar2;
  *(undefined4 *)(iVar6 + 0x48) = 0;
  *(undefined4 *)(iVar6 + 0x44) = 0;
  *(int *)(iVar6 + 0x40) = iVar10;
  *(int *)(iVar6 + 0x38) = iVar10;
  *(undefined4 *)(iVar6 + 0x4c) = 0;
  _lock_init(iVar6,1);
  *(undefined4 *)(iVar6 + 0x4c) = 0;
  *(undefined4 *)(iVar6 + 0x34) = 0;
  *(undefined4 *)(iVar6 + 0x3c) = 0;
  piVar13 = *(int **)(param_1 + 0x10);
  do {
    if (piVar13 == (int *)(param_1 + 0xc)) {
      *(undefined4 *)(iVar6 + 0x28) = *(undefined4 *)(param_1 + 0x28);
      _lock_done(param_1);
      return iVar6;
    }
    if ((*(byte *)(piVar13 + 6) & 4) != 0) {
                    /* WARNING: Subroutine does not return */
      _panic(s_vm_map_fork__encountered_a_subma_001e0ac4);
    }
    iVar10 = piVar13[9];
    if (iVar10 == 1) {
      uVar8 = _vm_map_kentry_zone;
      if (*(int *)(iVar6 + 0x20) != 0) {
        uVar8 = _vm_map_entry_zone;
      }
      piVar9 = (int *)_zalloc(uVar8);
      if (piVar9 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
        _panic(s_vm_map_entry_create_001e0ab0);
      }
      piVar11 = piVar13;
      piVar12 = piVar9;
      for (iVar10 = 0xb; iVar10 != 0; iVar10 = iVar10 + -1) {
        *piVar12 = *piVar11;
        piVar11 = piVar11 + 1;
        piVar12 = piVar12 + 1;
      }
      *(undefined2 *)(piVar9 + 10) = 0;
      piVar9[4] = 0;
      *(byte *)(piVar9 + 6) = *(byte *)(piVar9 + 6) & 0xfe;
      *(int *)(iVar6 + 0x1c) = *(int *)(iVar6 + 0x1c) + 1;
      *piVar9 = *(int *)(iVar6 + 0xc);
      piVar9[1] = *(int *)(*(int *)(iVar6 + 0xc) + 4);
      iVar10 = *piVar9;
      *(int **)piVar9[1] = piVar9;
      *(int **)(iVar10 + 4) = piVar9;
      if ((*(byte *)(piVar13 + 6) & 1) == 0) {
        if (((*(byte *)(piVar13 + 6) & 4) == 0) && ((*(byte *)(piVar9 + 6) & 4) == 0)) {
          if ((short)piVar9[10] != 0) {
            _vm_fault_unwire(iVar6,piVar9);
            *(undefined2 *)(piVar9 + 10) = 0;
          }
          if (*(int *)(iVar6 + 0x2c) == 0) {
            _vm_object_pmap_remove(piVar9[4],piVar9[5],(piVar9[3] - piVar9[2]) + piVar9[5]);
          }
          _pmap_remove(*(undefined4 *)(iVar6 + 0x24),piVar9[2],piVar9[3]);
          if ((short)piVar13[10] == 0) {
            if ((*(byte *)(piVar13 + 6) & 0x40) == 0) {
              if (*(int *)(param_1 + 0x2c) == 0) {
                piVar11 = (int *)(param_1 + 0x34);
                do {
                  do {
                  } while (*piVar11 != 0);
                  LOCK();
                  iVar10 = *piVar11;
                  *piVar11 = 1;
                  UNLOCK();
                } while (iVar10 == 1);
                LOCK();
                *(undefined4 *)(param_1 + 0x34) = 0;
                UNLOCK();
                if (*(int *)(param_1 + 0x30) != 1) {
                  _vm_object_pmap_copy(piVar13[4],piVar13[5],(piVar13[3] - piVar13[2]) + piVar13[5])
                  ;
                  goto LAB_00177f3f;
                }
              }
              _pmap_protect(*(undefined4 *)(param_1 + 0x24),piVar13[2],piVar13[3],
                            piVar13[7] & 0xfffffffd);
            }
LAB_00177f3f:
            iVar10 = piVar9[4];
            _vm_object_copy(piVar13[4],piVar13[5],piVar13[3] - piVar13[2],piVar9 + 4,piVar9 + 5,
                            &local_8);
            if (local_8 != 0) {
              *(byte *)(piVar13 + 6) = *(byte *)(piVar13 + 6) | 0x40;
            }
            *(byte *)(piVar9 + 6) = *(byte *)(piVar9 + 6) | 0x40;
            *(byte *)(piVar13 + 6) = *(byte *)(piVar13 + 6) | 8;
            *(byte *)(piVar9 + 6) = *(byte *)(piVar9 + 6) | 8;
            if ((*(byte *)(piVar13 + 7) & 4) != 0) {
              piVar9[7] = piVar9[7] | piVar9[8] & 4U;
            }
            _vm_object_deallocate(iVar10);
            _pmap_copy(*(undefined4 *)(iVar6 + 0x24),*(undefined4 *)(param_1 + 0x24),piVar9[2],
                       piVar9[3] - piVar9[2],piVar13[2]);
          }
          else {
            _vm_fault_copy_entry(iVar6,param_1,piVar9,piVar13);
          }
        }
      }
      else {
        iVar10 = _vm_map_copy(iVar6,piVar13[4],piVar9[2],piVar9[3] - piVar9[2],piVar13[5],0,0);
        if (iVar10 != 0) {
          _printf(s_vm_map_fork__copy_in_share_map_r_001e0ae6);
        }
      }
    }
    else if ((iVar10 < 2) && (iVar10 == 0)) {
      if ((*(byte *)(piVar13 + 6) & 1) == 0) {
        iVar10 = piVar13[2];
        iVar4 = piVar13[3];
        iVar7 = _zalloc(_vm_map_zone);
        if (iVar7 == 0) {
                    /* WARNING: Subroutine does not return */
          _panic(s_vm_map_create_001e0aa2);
        }
        iVar1 = iVar7 + 0xc;
        *(int *)(iVar7 + 0x10) = iVar1;
        *(int *)(iVar7 + 0xc) = iVar1;
        *(undefined4 *)(iVar7 + 0x1c) = 0;
        *(undefined4 *)(iVar7 + 0x20) = 1;
        *(undefined4 *)(iVar7 + 0x28) = 0;
        *(undefined4 *)(iVar7 + 0x30) = 1;
        *(undefined4 *)(iVar7 + 0x24) = 0;
        *(undefined4 *)(iVar7 + 0x2c) = 1;
        *(int *)(iVar7 + 0x14) = iVar10;
        *(int *)(iVar7 + 0x18) = iVar4;
        *(undefined4 *)(iVar7 + 0x48) = 0;
        *(undefined4 *)(iVar7 + 0x44) = 0;
        *(int *)(iVar7 + 0x40) = iVar1;
        *(int *)(iVar7 + 0x38) = iVar1;
        *(undefined4 *)(iVar7 + 0x4c) = 0;
        _lock_init(iVar7,1);
        *(undefined4 *)(iVar7 + 0x4c) = 0;
        *(undefined4 *)(iVar7 + 0x34) = 0;
        *(undefined4 *)(iVar7 + 0x3c) = 0;
        *(undefined4 *)(iVar7 + 0x2c) = 0;
        uVar8 = _vm_map_kentry_zone;
        if (*(int *)(iVar7 + 0x20) != 0) {
          uVar8 = _vm_map_entry_zone;
        }
        piVar9 = (int *)_zalloc(uVar8);
        if (piVar9 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
          _panic(s_vm_map_entry_create_001e0ab0);
        }
        piVar11 = piVar13;
        piVar12 = piVar9;
        for (iVar10 = 0xb; iVar10 != 0; iVar10 = iVar10 + -1) {
          *piVar12 = *piVar11;
          piVar11 = piVar11 + 1;
          piVar12 = piVar12 + 1;
        }
        *(int *)(iVar7 + 0x1c) = *(int *)(iVar7 + 0x1c) + 1;
        *piVar9 = *(int *)(iVar7 + 0xc);
        piVar9[1] = *(int *)(*(int *)(iVar7 + 0xc) + 4);
        iVar10 = *piVar9;
        *(int **)piVar9[1] = piVar9;
        *(int **)(iVar10 + 4) = piVar9;
        *(byte *)(piVar13 + 6) = *(byte *)(piVar13 + 6) | 1;
        piVar13[4] = iVar7;
        piVar13[5] = piVar13[2];
      }
      uVar8 = _vm_map_kentry_zone;
      if (*(int *)(iVar6 + 0x20) != 0) {
        uVar8 = _vm_map_entry_zone;
      }
      piVar9 = (int *)_zalloc(uVar8);
      if (piVar9 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
        _panic(s_vm_map_entry_create_001e0ab0);
      }
      piVar11 = piVar13;
      piVar12 = piVar9;
      for (iVar10 = 0xb; iVar10 != 0; iVar10 = iVar10 + -1) {
        *piVar12 = *piVar11;
        piVar11 = piVar11 + 1;
        piVar12 = piVar12 + 1;
      }
      iVar10 = piVar9[4];
      if (iVar10 != 0) {
        piVar11 = (int *)(iVar10 + 0x34);
        do {
          do {
          } while (*piVar11 != 0);
          LOCK();
          iVar4 = *piVar11;
          *piVar11 = 1;
          UNLOCK();
        } while (iVar4 == 1);
        *(int *)(iVar10 + 0x30) = *(int *)(iVar10 + 0x30) + 1;
        LOCK();
        *(undefined4 *)(iVar10 + 0x34) = 0;
        UNLOCK();
      }
      *(int *)(iVar6 + 0x1c) = *(int *)(iVar6 + 0x1c) + 1;
      *piVar9 = *(int *)(iVar6 + 0xc);
      piVar9[1] = *(int *)(*(int *)(iVar6 + 0xc) + 4);
      iVar10 = *piVar9;
      *(int **)piVar9[1] = piVar9;
      *(int **)(iVar10 + 4) = piVar9;
      _pmap_copy(*(undefined4 *)(iVar6 + 0x24),*(undefined4 *)(param_1 + 0x24),piVar9[2],
                 piVar13[3] - piVar13[2],piVar13[2]);
    }
    piVar13 = (int *)piVar13[1];
  } while( true );
}

