/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001751df */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

undefined4 __analysis_fragment_001751df(void)

{
  int *piVar1;
  byte *pbVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 *unaff_EBX;
  int unaff_EBP;
  undefined4 *puVar6;
  undefined4 *puVar7;
  
  *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(unaff_EBP + -0x18);
  puVar6 = unaff_EBX;
  puVar7 = *(undefined4 **)(unaff_EBP + -0x1c);
  for (iVar5 = 0xb; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar7 = *puVar6;
    puVar6 = puVar6 + 1;
    puVar7 = puVar7 + 1;
  }
  iVar5 = *(int *)(unaff_EBP + 0x10);
  unaff_EBX[3] = iVar5;
  piVar4 = *(int **)(unaff_EBP + -0x1c);
  piVar4[2] = iVar5;
  piVar4[5] = piVar4[5] + (*(int *)(unaff_EBP + 0x10) - unaff_EBX[2]);
  piVar1 = (int *)(*(int *)(unaff_EBP + -0x14) + 0x10);
  *piVar1 = *piVar1 + 1;
  *piVar4 = (int)unaff_EBX;
  piVar4[1] = unaff_EBX[1];
  iVar5 = *piVar4;
  *(int **)piVar4[1] = piVar4;
  *(int **)(iVar5 + 4) = piVar4;
  if ((*(byte *)(unaff_EBX + 6) & 5) == 0) {
    _vm_object_reference();
  }
  else {
    iVar5 = piVar4[4];
    if (iVar5 != 0) {
      piVar1 = (int *)(iVar5 + 0x34);
      do {
        do {
        } while (*piVar1 != 0);
        LOCK();
        iVar3 = *piVar1;
        *piVar1 = 1;
        UNLOCK();
      } while (iVar3 == 1);
      *(int *)(iVar5 + 0x30) = *(int *)(iVar5 + 0x30) + 1;
      LOCK();
      *(undefined4 *)(iVar5 + 0x34) = 0;
      UNLOCK();
    }
  }
  iVar5 = *(int *)(unaff_EBP + -4);
  if ((((*(int *)(iVar5 + 8) == *(int *)(unaff_EBP + 0xc)) &&
       (*(int *)(iVar5 + 0xc) == *(int *)(unaff_EBP + 0x10))) &&
      ((*(byte *)(iVar5 + 0x18) & 1) == 0)) &&
     ((_vm_submap_object == *(int *)(iVar5 + 0x10) && ((*(byte *)(iVar5 + 0x18) & 8) == 0)))) {
    *(undefined4 *)(iVar5 + 0x10) = 0;
    _vm_object_deallocate();
    pbVar2 = (byte *)(*(int *)(unaff_EBP + -4) + 0x18);
    *pbVar2 = *pbVar2 | 4;
    *(undefined4 *)(*(int *)(unaff_EBP + -4) + 0x10) = *(undefined4 *)(unaff_EBP + 0x14);
    iVar5 = *(int *)(unaff_EBP + 0x14);
    if (iVar5 != 0) {
      piVar1 = (int *)(iVar5 + 0x34);
      do {
        do {
        } while (*piVar1 != 0);
        LOCK();
        iVar3 = *piVar1;
        *piVar1 = 1;
        UNLOCK();
      } while (iVar3 == 1);
      *(int *)(iVar5 + 0x30) = *(int *)(iVar5 + 0x30) + 1;
      LOCK();
      *(undefined4 *)(iVar5 + 0x34) = 0;
      UNLOCK();
    }
    *(undefined4 *)(unaff_EBP + -8) = 0;
  }
  _lock_done();
  return *(undefined4 *)(unaff_EBP + -8);
}

