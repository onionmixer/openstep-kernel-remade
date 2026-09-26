/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017597f */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

undefined4 __analysis_fragment_0017597f(void)

{
  int iVar1;
  int iVar2;
  int *unaff_EBX;
  int unaff_EBP;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  
  *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(unaff_EBP + -0xc);
  piVar4 = *(int **)(unaff_EBP + -0x18);
  piVar3 = unaff_EBX;
  piVar5 = piVar4;
  for (iVar2 = 0xb; iVar2 != 0; iVar2 = iVar2 + -1) {
    *piVar5 = *piVar3;
    piVar3 = piVar3 + 1;
    piVar5 = piVar5 + 1;
  }
  iVar2 = *(int *)(unaff_EBP + 0xc);
  piVar4[3] = iVar2;
  unaff_EBX[5] = unaff_EBX[5] + (*(int *)(unaff_EBP + 0xc) - unaff_EBX[2]);
  unaff_EBX[2] = iVar2;
  piVar4 = (int *)(*(int *)(unaff_EBP + -8) + 0x10);
  *piVar4 = *piVar4 + 1;
  piVar4 = *(int **)(unaff_EBP + -0x18);
  *piVar4 = *unaff_EBX;
  piVar4[1] = *(int *)(*unaff_EBX + 4);
  iVar2 = *piVar4;
  *(int **)piVar4[1] = piVar4;
  *(int **)(iVar2 + 4) = piVar4;
  if ((*(byte *)(unaff_EBX + 6) & 5) == 0) {
    _vm_object_reference();
  }
  else {
    iVar2 = piVar4[4];
    if (iVar2 != 0) {
      piVar4 = (int *)(iVar2 + 0x34);
      do {
        do {
        } while (*piVar4 != 0);
        LOCK();
        iVar1 = *piVar4;
        *piVar4 = 1;
        UNLOCK();
      } while (iVar1 == 1);
      *(int *)(iVar2 + 0x30) = *(int *)(iVar2 + 0x30) + 1;
      LOCK();
      *(undefined4 *)(iVar2 + 0x34) = 0;
      UNLOCK();
    }
  }
  for (; (unaff_EBX != (int *)(*(int *)(unaff_EBP + 8) + 0xc) &&
         ((uint)unaff_EBX[2] < *(uint *)(unaff_EBP + 0x10))); unaff_EBX = (int *)unaff_EBX[1]) {
    if (*(uint *)(unaff_EBP + 0x10) < (uint)unaff_EBX[3]) {
      *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + 8) + 0xc;
      iVar1 = _zalloc();
      *(int *)(unaff_EBP + -0x10) = iVar1;
      iVar2 = *(int *)(unaff_EBP + -0x14);
      if (iVar1 == 0) {
        *(int *)(unaff_EBP + -0x14) = iVar2;
                    /* WARNING: Subroutine does not return */
        _panic(s_vm_map_entry_create_001e0ab0);
      }
      *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(unaff_EBP + -0x10);
      *(int **)(unaff_EBP + -0x1c) = unaff_EBX;
      piVar4 = unaff_EBX;
      piVar3 = *(int **)(unaff_EBP + -0x18);
      for (iVar1 = 0xb; iVar1 != 0; iVar1 = iVar1 + -1) {
        *piVar3 = *piVar4;
        piVar4 = piVar4 + 1;
        piVar3 = piVar3 + 1;
      }
      iVar1 = *(int *)(unaff_EBP + 0x10);
      unaff_EBX[3] = iVar1;
      piVar3 = *(int **)(unaff_EBP + -0x18);
      piVar3[2] = iVar1;
      piVar3[5] = piVar3[5] + (*(int *)(unaff_EBP + 0x10) - unaff_EBX[2]);
      piVar4 = (int *)(iVar2 + 0x10);
      *piVar4 = *piVar4 + 1;
      *piVar3 = (int)unaff_EBX;
      piVar3[1] = unaff_EBX[1];
      iVar2 = *piVar3;
      *(int **)piVar3[1] = piVar3;
      *(int **)(iVar2 + 4) = piVar3;
      if ((*(byte *)(unaff_EBX + 6) & 5) == 0) {
        _vm_object_reference();
      }
      else {
        iVar2 = piVar3[4];
        if (iVar2 != 0) {
          piVar4 = (int *)(iVar2 + 0x34);
          do {
            do {
            } while (*piVar4 != 0);
            LOCK();
            iVar1 = *piVar4;
            *piVar4 = 1;
            UNLOCK();
          } while (iVar1 == 1);
          *(int *)(iVar2 + 0x30) = *(int *)(iVar2 + 0x30) + 1;
          LOCK();
          *(undefined4 *)(iVar2 + 0x34) = 0;
          UNLOCK();
        }
      }
    }
    unaff_EBX[9] = *(int *)(unaff_EBP + 0x14);
  }
  _lock_done();
  return 0;
}

