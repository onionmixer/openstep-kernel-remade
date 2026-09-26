/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00175db8 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

undefined4 __analysis_fragment_00175db8(void)

{
  short sVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 *unaff_EBX;
  int unaff_EBP;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  iVar4 = *(int *)(unaff_EBP + -0x1c);
  do {
    *(undefined4 *)(unaff_EBP + -0x20) = *(undefined4 *)(unaff_EBP + -0x14);
    *(undefined4 **)(unaff_EBP + -0x24) = unaff_EBX;
    puVar5 = unaff_EBX;
    puVar6 = *(undefined4 **)(unaff_EBP + -0x20);
    for (iVar3 = 0xb; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar6 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
    }
    iVar3 = *(int *)(unaff_EBP + 0x10);
    unaff_EBX[3] = iVar3;
    piVar2 = *(int **)(unaff_EBP + -0x20);
    piVar2[2] = iVar3;
    piVar2[5] = piVar2[5] + (*(int *)(unaff_EBP + 0x10) - unaff_EBX[2]);
    *(int *)(iVar4 + 0x10) = *(int *)(iVar4 + 0x10) + 1;
    *piVar2 = (int)unaff_EBX;
    piVar2[1] = unaff_EBX[1];
    iVar4 = *piVar2;
    *(int **)piVar2[1] = piVar2;
    *(int **)(iVar4 + 4) = piVar2;
    if ((*(byte *)(unaff_EBX + 6) & 5) == 0) {
      _vm_object_reference();
    }
    else {
      iVar4 = piVar2[4];
      if (iVar4 != 0) {
        piVar2 = (int *)(iVar4 + 0x34);
        do {
          do {
          } while (*piVar2 != 0);
          LOCK();
          iVar3 = *piVar2;
          *piVar2 = 1;
          UNLOCK();
        } while (iVar3 == 1);
        *(int *)(iVar4 + 0x30) = *(int *)(iVar4 + 0x30) + 1;
        LOCK();
        *(undefined4 *)(iVar4 + 0x34) = 0;
        UNLOCK();
      }
    }
    do {
      sVar1 = *(short *)(unaff_EBX + 10);
      *(short *)(unaff_EBX + 10) = sVar1 + -1;
      if (sVar1 == 1) {
        _vm_fault_unwire(*(undefined4 *)(unaff_EBP + 8));
      }
      unaff_EBX = (undefined4 *)unaff_EBX[1];
      if ((unaff_EBX == (undefined4 *)(*(int *)(unaff_EBP + 8) + 0xc)) ||
         (*(uint *)(unaff_EBP + 0x10) <= (uint)unaff_EBX[2])) {
        if (*(int *)(unaff_EBP + -8) != 0) {
          _lock_done();
        }
        return 0;
      }
    } while ((uint)unaff_EBX[3] <= *(uint *)(unaff_EBP + 0x10));
    *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + 8) + 0xc;
    iVar3 = _zalloc();
    *(int *)(unaff_EBP + -0x14) = iVar3;
    iVar4 = *(int *)(unaff_EBP + -0x1c);
    if (iVar3 == 0) {
      *(int *)(unaff_EBP + -0x1c) = iVar4;
                    /* WARNING: Subroutine does not return */
      _panic(s_vm_map_entry_create_001e0ab0);
    }
  } while( true );
}

