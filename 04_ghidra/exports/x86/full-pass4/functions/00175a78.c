/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00175a78 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

undefined4 __analysis_fragment_00175a78(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 *unaff_EBX;
  int unaff_EBP;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  iVar3 = *(int *)(unaff_EBP + -0x14);
  do {
    *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(unaff_EBP + -0x10);
    *(undefined4 **)(unaff_EBP + -0x1c) = unaff_EBX;
    puVar4 = unaff_EBX;
    puVar5 = *(undefined4 **)(unaff_EBP + -0x18);
    for (iVar2 = 0xb; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    iVar2 = *(int *)(unaff_EBP + 0x10);
    unaff_EBX[3] = iVar2;
    piVar1 = *(int **)(unaff_EBP + -0x18);
    piVar1[2] = iVar2;
    piVar1[5] = piVar1[5] + (*(int *)(unaff_EBP + 0x10) - unaff_EBX[2]);
    *(int *)(iVar3 + 0x10) = *(int *)(iVar3 + 0x10) + 1;
    *piVar1 = (int)unaff_EBX;
    piVar1[1] = unaff_EBX[1];
    iVar3 = *piVar1;
    *(int **)piVar1[1] = piVar1;
    *(int **)(iVar3 + 4) = piVar1;
    if ((*(byte *)(unaff_EBX + 6) & 5) == 0) {
      _vm_object_reference();
    }
    else {
      iVar3 = piVar1[4];
      if (iVar3 != 0) {
        piVar1 = (int *)(iVar3 + 0x34);
        do {
          do {
          } while (*piVar1 != 0);
          LOCK();
          iVar2 = *piVar1;
          *piVar1 = 1;
          UNLOCK();
        } while (iVar2 == 1);
        *(int *)(iVar3 + 0x30) = *(int *)(iVar3 + 0x30) + 1;
        LOCK();
        *(undefined4 *)(iVar3 + 0x34) = 0;
        UNLOCK();
      }
    }
    do {
      unaff_EBX[9] = *(undefined4 *)(unaff_EBP + 0x14);
      unaff_EBX = (undefined4 *)unaff_EBX[1];
      if ((unaff_EBX == (undefined4 *)(*(int *)(unaff_EBP + 8) + 0xc)) ||
         (*(uint *)(unaff_EBP + 0x10) <= (uint)unaff_EBX[2])) {
        _lock_done();
        return 0;
      }
    } while ((uint)unaff_EBX[3] <= *(uint *)(unaff_EBP + 0x10));
    *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + 8) + 0xc;
    iVar2 = _zalloc();
    *(int *)(unaff_EBP + -0x10) = iVar2;
    iVar3 = *(int *)(unaff_EBP + -0x14);
    if (iVar2 == 0) {
      *(int *)(unaff_EBP + -0x14) = iVar3;
                    /* WARNING: Subroutine does not return */
      _panic(s_vm_map_entry_create_001e0ab0);
    }
  } while( true );
}

