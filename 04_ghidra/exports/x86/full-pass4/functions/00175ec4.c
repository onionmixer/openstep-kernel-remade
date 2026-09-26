/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00175ec4 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

undefined4 __analysis_fragment_00175ec4(void)

{
  short sVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 *unaff_EBX;
  int unaff_EBP;
  undefined4 *puVar6;
  undefined4 *puVar7;
  
  iVar5 = *(int *)(unaff_EBP + -0x1c);
  do {
    *(undefined4 *)(unaff_EBP + -0x20) = *(undefined4 *)(unaff_EBP + -0x18);
    *(undefined4 **)(unaff_EBP + -0x24) = unaff_EBX;
    puVar6 = unaff_EBX;
    puVar7 = *(undefined4 **)(unaff_EBP + -0x20);
    for (iVar4 = 0xb; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar7 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar7 = puVar7 + 1;
    }
    iVar4 = *(int *)(unaff_EBP + 0x10);
    unaff_EBX[3] = iVar4;
    piVar2 = *(int **)(unaff_EBP + -0x20);
    piVar2[2] = iVar4;
    piVar2[5] = piVar2[5] + (*(int *)(unaff_EBP + 0x10) - unaff_EBX[2]);
    *(int *)(iVar5 + 0x10) = *(int *)(iVar5 + 0x10) + 1;
    *piVar2 = (int)unaff_EBX;
    piVar2[1] = unaff_EBX[1];
    iVar5 = *piVar2;
    *(int **)piVar2[1] = piVar2;
    *(int **)(iVar5 + 4) = piVar2;
    if ((*(byte *)(unaff_EBX + 6) & 5) == 0) {
      _vm_object_reference();
    }
    else {
      iVar5 = piVar2[4];
      if (iVar5 != 0) {
        piVar2 = (int *)(iVar5 + 0x34);
        do {
          do {
          } while (*piVar2 != 0);
          LOCK();
          iVar4 = *piVar2;
          *piVar2 = 1;
          UNLOCK();
        } while (iVar4 == 1);
        *(int *)(iVar5 + 0x30) = *(int *)(iVar5 + 0x30) + 1;
        LOCK();
        *(undefined4 *)(iVar5 + 0x34) = 0;
        UNLOCK();
      }
    }
    do {
      sVar1 = *(short *)(unaff_EBX + 10);
      *(short *)(unaff_EBX + 10) = sVar1 + 1;
      if ((sVar1 == 0) && ((*(byte *)(unaff_EBX + 6) & 1) == 0)) {
        if (((*(byte *)(unaff_EBX + 6) & 0x40) == 0) || ((*(byte *)(unaff_EBX + 7) & 2) == 0)) {
          if (unaff_EBX[4] == 0) {
            uVar3 = _vm_object_allocate();
            unaff_EBX[4] = uVar3;
            unaff_EBX[5] = 0;
          }
        }
        else {
          _vm_object_shadow(unaff_EBX + 4,unaff_EBX + 5);
          *(byte *)(unaff_EBX + 6) = *(byte *)(unaff_EBX + 6) & 0xbf;
        }
      }
      unaff_EBX = (undefined4 *)unaff_EBX[1];
      if ((unaff_EBX == (undefined4 *)(*(int *)(unaff_EBP + 8) + 0xc)) ||
         (*(uint *)(unaff_EBP + 0x10) <= (uint)unaff_EBX[2])) {
        if (_kernel_map == *(int *)(unaff_EBP + 8)) {
          *(undefined4 *)(unaff_EBP + -8) = 0;
          _lock_done();
        }
        else {
          uVar3 = *(undefined4 *)(unaff_EBP + 8);
          _lock_set_recursive();
          _lock_write_to_read(uVar3);
        }
        iVar5 = *(int *)(unaff_EBP + -4);
        iVar4 = *(int *)(unaff_EBP + 8) + 0xc;
        if (iVar5 == iVar4) goto LAB_00176034;
        *(int *)(unaff_EBP + -0x24) = iVar4;
        goto LAB_00176010;
      }
    } while ((uint)unaff_EBX[3] <= *(uint *)(unaff_EBP + 0x10));
    *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + 8) + 0xc;
    iVar4 = _zalloc();
    *(int *)(unaff_EBP + -0x18) = iVar4;
    iVar5 = *(int *)(unaff_EBP + -0x1c);
    if (iVar4 == 0) {
      *(int *)(unaff_EBP + -0x1c) = iVar5;
                    /* WARNING: Subroutine does not return */
      _panic(s_vm_map_entry_create_001e0ab0);
    }
  } while( true );
  while( true ) {
    if (*(short *)(iVar5 + 0x28) == 1) {
      _vm_fault_wire(*(undefined4 *)(unaff_EBP + 8));
    }
    iVar5 = *(int *)(iVar5 + 4);
    if (*(int *)(unaff_EBP + -0x24) == iVar5) break;
LAB_00176010:
    if (*(uint *)(unaff_EBP + 0x10) <= *(uint *)(iVar5 + 8)) break;
  }
LAB_00176034:
  if ((*(int *)(unaff_EBP + -8) != 0) && (_lock_clear_recursive(), *(int *)(unaff_EBP + -8) != 0)) {
    _lock_done();
  }
  return 0;
}

