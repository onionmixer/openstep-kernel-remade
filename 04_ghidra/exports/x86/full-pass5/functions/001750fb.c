/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001750fb */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

undefined4 __analysis_fragment_001750fb(void)

{
  byte *pbVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  int *unaff_EBX;
  int unaff_EBP;
  int *piVar6;
  undefined4 *puVar7;
  int *piVar8;
  undefined4 *puVar9;
  
  *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(unaff_EBP + -0x10);
  piVar3 = *(int **)(unaff_EBP + -0x1c);
  piVar6 = unaff_EBX;
  piVar8 = piVar3;
  for (iVar5 = 0xb; iVar5 != 0; iVar5 = iVar5 + -1) {
    *piVar8 = *piVar6;
    piVar6 = piVar6 + 1;
    piVar8 = piVar8 + 1;
  }
  iVar5 = *(int *)(unaff_EBP + 0xc);
  piVar3[3] = iVar5;
  unaff_EBX[5] = unaff_EBX[5] + (*(int *)(unaff_EBP + 0xc) - unaff_EBX[2]);
  unaff_EBX[2] = iVar5;
  piVar3 = (int *)(*(int *)(unaff_EBP + -0xc) + 0x10);
  *piVar3 = *piVar3 + 1;
  piVar3 = *(int **)(unaff_EBP + -0x1c);
  *piVar3 = *unaff_EBX;
  piVar3[1] = *(int *)(*unaff_EBX + 4);
  iVar5 = *piVar3;
  *(int **)piVar3[1] = piVar3;
  *(int **)(iVar5 + 4) = piVar3;
  if ((*(byte *)(unaff_EBX + 6) & 5) == 0) {
    _vm_object_reference();
  }
  else {
    iVar5 = piVar3[4];
    if (iVar5 != 0) {
      piVar3 = (int *)(iVar5 + 0x34);
      do {
        do {
        } while (*piVar3 != 0);
        LOCK();
        iVar2 = *piVar3;
        *piVar3 = 1;
        UNLOCK();
      } while (iVar2 == 1);
      *(int *)(iVar5 + 0x30) = *(int *)(iVar5 + 0x30) + 1;
      LOCK();
      *(undefined4 *)(iVar5 + 0x34) = 0;
      UNLOCK();
    }
  }
  puVar4 = *(undefined4 **)(unaff_EBP + -4);
  if (*(uint *)(unaff_EBP + 0x10) < (uint)puVar4[3]) {
    *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + 8) + 0xc;
    iVar5 = _zalloc();
    *(int *)(unaff_EBP + -0x18) = iVar5;
    if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
      _panic(s_vm_map_entry_create_001e0ab0);
    }
    *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(unaff_EBP + -0x18);
    puVar7 = puVar4;
    puVar9 = *(undefined4 **)(unaff_EBP + -0x1c);
    for (iVar5 = 0xb; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar9 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar9 = puVar9 + 1;
    }
    iVar5 = *(int *)(unaff_EBP + 0x10);
    puVar4[3] = iVar5;
    piVar6 = *(int **)(unaff_EBP + -0x1c);
    piVar6[2] = iVar5;
    piVar6[5] = piVar6[5] + (*(int *)(unaff_EBP + 0x10) - puVar4[2]);
    piVar3 = (int *)(*(int *)(unaff_EBP + -0x14) + 0x10);
    *piVar3 = *piVar3 + 1;
    *piVar6 = (int)puVar4;
    piVar6[1] = puVar4[1];
    iVar5 = *piVar6;
    *(int **)piVar6[1] = piVar6;
    *(int **)(iVar5 + 4) = piVar6;
    if ((*(byte *)(puVar4 + 6) & 5) == 0) {
      _vm_object_reference();
    }
    else {
      iVar5 = piVar6[4];
      if (iVar5 != 0) {
        piVar3 = (int *)(iVar5 + 0x34);
        do {
          do {
          } while (*piVar3 != 0);
          LOCK();
          iVar2 = *piVar3;
          *piVar3 = 1;
          UNLOCK();
        } while (iVar2 == 1);
        *(int *)(iVar5 + 0x30) = *(int *)(iVar5 + 0x30) + 1;
        LOCK();
        *(undefined4 *)(iVar5 + 0x34) = 0;
        UNLOCK();
      }
    }
  }
  iVar5 = *(int *)(unaff_EBP + -4);
  if ((((*(int *)(iVar5 + 8) == *(int *)(unaff_EBP + 0xc)) &&
       (*(int *)(iVar5 + 0xc) == *(int *)(unaff_EBP + 0x10))) &&
      ((*(byte *)(iVar5 + 0x18) & 1) == 0)) &&
     ((_vm_submap_object == *(int *)(iVar5 + 0x10) && ((*(byte *)(iVar5 + 0x18) & 8) == 0)))) {
    *(undefined4 *)(iVar5 + 0x10) = 0;
    _vm_object_deallocate();
    pbVar1 = (byte *)(*(int *)(unaff_EBP + -4) + 0x18);
    *pbVar1 = *pbVar1 | 4;
    *(undefined4 *)(*(int *)(unaff_EBP + -4) + 0x10) = *(undefined4 *)(unaff_EBP + 0x14);
    iVar5 = *(int *)(unaff_EBP + 0x14);
    if (iVar5 != 0) {
      piVar3 = (int *)(iVar5 + 0x34);
      do {
        do {
        } while (*piVar3 != 0);
        LOCK();
        iVar2 = *piVar3;
        *piVar3 = 1;
        UNLOCK();
      } while (iVar2 == 1);
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

