/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00174f0b */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

undefined4 * __analysis_fragment_00174f0b(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *unaff_EBX;
  int unaff_EBP;
  undefined4 *puVar6;
  
  *(undefined4 *)(unaff_EBP + -8) = *(undefined4 *)(unaff_EBP + -4);
  puVar4 = unaff_EBX;
  puVar6 = *(undefined4 **)(unaff_EBP + -8);
  for (iVar5 = 0xb; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar6 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar6 = puVar6 + 1;
  }
  iVar5 = *(int *)(unaff_EBP + 0x10);
  unaff_EBX[3] = iVar5;
  piVar3 = *(int **)(unaff_EBP + -8);
  piVar3[2] = iVar5;
  piVar3[5] = piVar3[5] + (*(int *)(unaff_EBP + 0x10) - unaff_EBX[2]);
  piVar1 = (int *)(*(int *)(unaff_EBP + 8) + 0x10);
  *piVar1 = *piVar1 + 1;
  *piVar3 = (int)unaff_EBX;
  piVar3[1] = unaff_EBX[1];
  iVar5 = *piVar3;
  puVar4 = (undefined4 *)piVar3[1];
  *puVar4 = piVar3;
  *(int **)(iVar5 + 4) = piVar3;
  if ((*(byte *)(unaff_EBX + 6) & 5) == 0) {
    puVar4 = (undefined4 *)_vm_object_reference();
  }
  else {
    iVar5 = piVar3[4];
    if (iVar5 != 0) {
      piVar1 = (int *)(iVar5 + 0x34);
      do {
        do {
        } while (*piVar1 != 0);
        LOCK();
        iVar2 = *piVar1;
        *piVar1 = 1;
        UNLOCK();
      } while (iVar2 == 1);
      *(int *)(iVar5 + 0x30) = *(int *)(iVar5 + 0x30) + 1;
      LOCK();
      puVar4 = *(undefined4 **)(iVar5 + 0x34);
      *(undefined4 *)(iVar5 + 0x34) = 0;
      UNLOCK();
    }
  }
  return puVar4;
}

