/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017628b */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

undefined4 __analysis_fragment_0017628b(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int *unaff_EBX;
  int unaff_EBP;
  int *piVar5;
  int *piVar6;
  
  *(undefined4 *)(unaff_EBP + -0x20) = *(undefined4 *)(unaff_EBP + -0xc);
  piVar4 = *(int **)(unaff_EBP + -0x20);
  piVar5 = unaff_EBX;
  piVar6 = piVar4;
  for (iVar3 = 0xb; iVar3 != 0; iVar3 = iVar3 + -1) {
    *piVar6 = *piVar5;
    piVar5 = piVar5 + 1;
    piVar6 = piVar6 + 1;
  }
  iVar3 = *(int *)(unaff_EBP + 0xc);
  piVar4[3] = iVar3;
  unaff_EBX[5] = unaff_EBX[5] + (*(int *)(unaff_EBP + 0xc) - unaff_EBX[2]);
  unaff_EBX[2] = iVar3;
  piVar4 = (int *)(*(int *)(unaff_EBP + -8) + 0x10);
  *piVar4 = *piVar4 + 1;
  piVar4 = *(int **)(unaff_EBP + -0x20);
  *piVar4 = *unaff_EBX;
  piVar4[1] = *(int *)(*unaff_EBX + 4);
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
        iVar1 = *piVar4;
        *piVar4 = 1;
        UNLOCK();
      } while (iVar1 == 1);
      *(int *)(iVar3 + 0x30) = *(int *)(iVar3 + 0x30) + 1;
      LOCK();
      *(undefined4 *)(iVar3 + 0x34) = 0;
      UNLOCK();
    }
  }
  piVar4 = (int *)(*(int *)(unaff_EBP + 8) + 0x3c);
  do {
    do {
    } while (*piVar4 != 0);
    LOCK();
    iVar3 = *piVar4;
    *piVar4 = 1;
    UNLOCK();
  } while (iVar3 == 1);
  iVar3 = *(int *)(unaff_EBP + 8);
  *(int *)(iVar3 + 0x38) = *unaff_EBX;
  LOCK();
  *(undefined4 *)(iVar3 + 0x3c) = 0;
  UNLOCK();
  if (*(uint *)(unaff_EBP + 0xc) <= *(uint *)(*(int *)(*(int *)(unaff_EBP + 8) + 0x40) + 8)) {
    *(int *)(*(int *)(unaff_EBP + 8) + 0x40) = *unaff_EBX;
  }
  while ((unaff_EBX != (int *)(*(int *)(unaff_EBP + 8) + 0xc) &&
         ((uint)unaff_EBX[2] < *(uint *)(unaff_EBP + 0x10)))) {
    if (*(uint *)(unaff_EBP + 0x10) < (uint)unaff_EBX[3]) {
      *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + 8) + 0xc;
      iVar1 = _zalloc();
      *(int *)(unaff_EBP + -0x18) = iVar1;
      iVar3 = *(int *)(unaff_EBP + -0x1c);
      if (iVar1 == 0) {
        *(int *)(unaff_EBP + -0x1c) = iVar3;
                    /* WARNING: Subroutine does not return */
        _panic(s_vm_map_entry_create_001e0ab0);
      }
      *(undefined4 *)(unaff_EBP + -0x20) = *(undefined4 *)(unaff_EBP + -0x18);
      piVar4 = unaff_EBX;
      piVar5 = *(int **)(unaff_EBP + -0x20);
      for (iVar1 = 0xb; iVar1 != 0; iVar1 = iVar1 + -1) {
        *piVar5 = *piVar4;
        piVar4 = piVar4 + 1;
        piVar5 = piVar5 + 1;
      }
      iVar1 = *(int *)(unaff_EBP + 0x10);
      unaff_EBX[3] = iVar1;
      piVar5 = *(int **)(unaff_EBP + -0x20);
      piVar5[2] = iVar1;
      piVar5[5] = piVar5[5] + (*(int *)(unaff_EBP + 0x10) - unaff_EBX[2]);
      piVar4 = (int *)(iVar3 + 0x10);
      *piVar4 = *piVar4 + 1;
      *piVar5 = (int)unaff_EBX;
      piVar5[1] = unaff_EBX[1];
      iVar3 = *piVar5;
      *(int **)piVar5[1] = piVar5;
      *(int **)(iVar3 + 4) = piVar5;
      if ((*(byte *)(unaff_EBX + 6) & 5) == 0) {
        _vm_object_reference();
      }
      else {
        iVar3 = piVar5[4];
        if (iVar3 != 0) {
          piVar4 = (int *)(iVar3 + 0x34);
          do {
            do {
            } while (*piVar4 != 0);
            LOCK();
            iVar1 = *piVar4;
            *piVar4 = 1;
            UNLOCK();
          } while (iVar1 == 1);
          *(int *)(iVar3 + 0x30) = *(int *)(iVar3 + 0x30) + 1;
          LOCK();
          *(undefined4 *)(iVar3 + 0x34) = 0;
          UNLOCK();
        }
      }
    }
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
    _pmap_remove(*(undefined4 *)(*(int *)(unaff_EBP + 8) + 0x24),*(undefined4 *)(unaff_EBP + -0x14))
    ;
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
          iVar1 = *piVar4;
          *piVar4 = 1;
          UNLOCK();
        } while (iVar1 == 1);
        iVar1 = *(int *)(iVar3 + 0x30);
        *(int *)(iVar3 + 0x30) = iVar1 + -1;
        LOCK();
        *(undefined4 *)(iVar3 + 0x34) = 0;
        UNLOCK();
        if (iVar1 == 1 || iVar1 + -1 < 0) {
          _lock_write();
          *(int *)(iVar3 + 0x4c) = *(int *)(iVar3 + 0x4c) + 1;
          _vm_map_delete(iVar3,*(undefined4 *)(iVar3 + 0x14));
          _pmap_destroy(*(undefined4 *)(iVar3 + 0x24));
          _zfree(_vm_map_zone,iVar3);
        }
      }
    }
    uVar2 = _vm_map_kentry_zone;
    if (*(int *)(*(int *)(unaff_EBP + 8) + 0x20) != 0) {
      uVar2 = _vm_map_entry_zone;
    }
    _zfree(uVar2);
    unaff_EBX = *(int **)(unaff_EBP + -0x10);
  }
  return 0;
}

