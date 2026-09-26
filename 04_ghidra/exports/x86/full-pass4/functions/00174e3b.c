/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00174e3b */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

undefined4 * __analysis_fragment_00174e3b(void)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  int *unaff_EBX;
  int unaff_EBP;
  int *piVar5;
  int *piVar6;
  
  *(undefined4 *)(unaff_EBP + -8) = *(undefined4 *)(unaff_EBP + -4);
  piVar2 = *(int **)(unaff_EBP + -8);
  piVar5 = unaff_EBX;
  piVar6 = piVar2;
  for (iVar4 = 0xb; iVar4 != 0; iVar4 = iVar4 + -1) {
    *piVar6 = *piVar5;
    piVar5 = piVar5 + 1;
    piVar6 = piVar6 + 1;
  }
  iVar4 = *(int *)(unaff_EBP + 0x10);
  piVar2[3] = iVar4;
  unaff_EBX[5] = unaff_EBX[5] + (*(int *)(unaff_EBP + 0x10) - unaff_EBX[2]);
  unaff_EBX[2] = iVar4;
  piVar2 = (int *)(*(int *)(unaff_EBP + 8) + 0x10);
  *piVar2 = *piVar2 + 1;
  piVar2 = *(int **)(unaff_EBP + -8);
  *piVar2 = *unaff_EBX;
  piVar2[1] = *(int *)(*unaff_EBX + 4);
  iVar4 = *piVar2;
  puVar3 = (undefined4 *)piVar2[1];
  *puVar3 = piVar2;
  *(int **)(iVar4 + 4) = piVar2;
  if ((*(byte *)(unaff_EBX + 6) & 5) == 0) {
    puVar3 = (undefined4 *)_vm_object_reference();
  }
  else {
    iVar4 = piVar2[4];
    if (iVar4 != 0) {
      piVar2 = (int *)(iVar4 + 0x34);
      do {
        do {
        } while (*piVar2 != 0);
        LOCK();
        iVar1 = *piVar2;
        *piVar2 = 1;
        UNLOCK();
      } while (iVar1 == 1);
      *(int *)(iVar4 + 0x30) = *(int *)(iVar4 + 0x30) + 1;
      LOCK();
      puVar3 = *(undefined4 **)(iVar4 + 0x34);
      *(undefined4 *)(iVar4 + 0x34) = 0;
      UNLOCK();
    }
  }
  return puVar3;
}

