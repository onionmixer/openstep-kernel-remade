/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001763b0 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

undefined4 __analysis_fragment_001763b0(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int *unaff_EBX;
  int unaff_EBP;
  int *piVar4;
  int *piVar5;
  
  iVar3 = *(int *)(unaff_EBP + -0x1c);
  do {
    *(undefined4 *)(unaff_EBP + -0x20) = *(undefined4 *)(unaff_EBP + -0x18);
    piVar4 = unaff_EBX;
    piVar5 = *(int **)(unaff_EBP + -0x20);
    for (iVar2 = 0xb; iVar2 != 0; iVar2 = iVar2 + -1) {
      *piVar5 = *piVar4;
      piVar4 = piVar4 + 1;
      piVar5 = piVar5 + 1;
    }
    iVar2 = *(int *)(unaff_EBP + 0x10);
    unaff_EBX[3] = iVar2;
    piVar4 = *(int **)(unaff_EBP + -0x20);
    piVar4[2] = iVar2;
    piVar4[5] = piVar4[5] + (*(int *)(unaff_EBP + 0x10) - unaff_EBX[2]);
    *(int *)(iVar3 + 0x10) = *(int *)(iVar3 + 0x10) + 1;
    *piVar4 = (int)unaff_EBX;
    piVar4[1] = unaff_EBX[1];
    iVar3 = *piVar4;
    *(int **)piVar4[1] = piVar4;
    *(int **)(iVar3 + 4) = piVar4;
    if ((*(byte *)(unaff_EBX + 6) & 5) == 0) {
      _vm_object_reference();
    }
    else {
      iVar3 = piVar4[4];
      if (iVar3 != 0) {
        piVar4 = (int *)(iVar3 + 0x34);
        do {
          do {
          } while (*piVar4 != 0);
          LOCK();
          iVar2 = *piVar4;
          *piVar4 = 1;
          UNLOCK();
        } while (iVar2 == 1);
        *(int *)(iVar3 + 0x30) = *(int *)(iVar3 + 0x30) + 1;
        LOCK();
        *(undefined4 *)(iVar3 + 0x34) = 0;
        UNLOCK();
      }
    }
    do {
      *(int *)(unaff_EBP + -0x10) = unaff_EBX[1];
      *(int *)(unaff_EBP + -0x14) = unaff_EBX[2];
      *(int *)(unaff_EBP + -0x20) = unaff_EBX[3];
      iVar3 = unaff_EBX[4];
      if ((short)unaff_EBX[10] != 0) {
        _vm_fault_unwire(*(undefined4 *)(unaff_EBP + 8));
        *(undefined2 *)(unaff_EBX + 10) = 0;
      }
      if (_kernel_object == iVar3) {
        _vm_object_page_remove(iVar3,unaff_EBX[5]);
      }
      if (*(int *)(*(int *)(unaff_EBP + 8) + 0x2c) == 0) {
        _vm_object_pmap_remove(iVar3,unaff_EBX[5]);
      }
      _pmap_remove(*(undefined4 *)(*(int *)(unaff_EBP + 8) + 0x24),
                   *(undefined4 *)(unaff_EBP + -0x14));
      if ((short)unaff_EBX[10] != 0) {
        _vm_fault_unwire(*(undefined4 *)(unaff_EBP + 8));
        *(undefined2 *)(unaff_EBX + 10) = 0;
      }
      piVar4 = (int *)(*(int *)(unaff_EBP + 8) + 0x1c);
      *piVar4 = *piVar4 + -1;
      *(int *)unaff_EBX[1] = *unaff_EBX;
      *(int *)(*unaff_EBX + 4) = unaff_EBX[1];
      piVar4 = (int *)(*(int *)(unaff_EBP + 8) + 0x28);
      *piVar4 = *piVar4 - (unaff_EBX[3] - unaff_EBX[2]);
      if ((*(byte *)(unaff_EBX + 6) & 5) == 0) {
        _vm_object_deallocate();
      }
      else {
        iVar3 = unaff_EBX[4];
        if (iVar3 != 0) {
          piVar4 = (int *)(iVar3 + 0x34);
          do {
            do {
            } while (*piVar4 != 0);
            LOCK();
            iVar2 = *piVar4;
            *piVar4 = 1;
            UNLOCK();
          } while (iVar2 == 1);
          iVar2 = *(int *)(iVar3 + 0x30);
          *(int *)(iVar3 + 0x30) = iVar2 + -1;
          LOCK();
          *(undefined4 *)(iVar3 + 0x34) = 0;
          UNLOCK();
          if (iVar2 == 1 || iVar2 + -1 < 0) {
            _lock_write();
            *(int *)(iVar3 + 0x4c) = *(int *)(iVar3 + 0x4c) + 1;
            _vm_map_delete(iVar3,*(undefined4 *)(iVar3 + 0x14));
            _pmap_destroy(*(undefined4 *)(iVar3 + 0x24));
            _zfree(_vm_map_zone,iVar3);
          }
        }
      }
      uVar1 = _vm_map_kentry_zone;
      if (*(int *)(*(int *)(unaff_EBP + 8) + 0x20) != 0) {
        uVar1 = _vm_map_entry_zone;
      }
      _zfree(uVar1);
      unaff_EBX = *(int **)(unaff_EBP + -0x10);
      if ((unaff_EBX == (int *)(*(int *)(unaff_EBP + 8) + 0xc)) ||
         (*(uint *)(unaff_EBP + 0x10) <= (uint)unaff_EBX[2])) {
        return 0;
      }
    } while ((uint)unaff_EBX[3] <= *(uint *)(unaff_EBP + 0x10));
    *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + 8) + 0xc;
    iVar2 = _zalloc();
    *(int *)(unaff_EBP + -0x18) = iVar2;
    iVar3 = *(int *)(unaff_EBP + -0x1c);
    if (iVar2 == 0) {
      *(int *)(unaff_EBP + -0x1c) = iVar3;
                    /* WARNING: Subroutine does not return */
      _panic(s_vm_map_entry_create_001e0ab0);
    }
  } while( true );
}

