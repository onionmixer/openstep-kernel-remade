/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00179aaa */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

int __analysis_fragment_00179aaa(void)

{
  uint uVar1;
  undefined *puVar2;
  undefined *puVar3;
  int *piVar4;
  undefined *puVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int unaff_EBP;
  int *unaff_ESI;
  
LAB_00179aad:
  LOCK();
  unaff_ESI[4] = 0;
  UNLOCK();
  do {
  } while (_vm_object_list_lock != 0);
  LOCK();
  UNLOCK();
  puVar2 = (undefined *)unaff_ESI[2];
  puVar3 = (undefined *)unaff_ESI[3];
  puVar5 = puVar3;
  if (puVar2 != &_vm_object_list) {
    *(undefined **)(puVar2 + 0xc) = puVar3;
    puVar5 = DAT_001f7354;
  }
  DAT_001f7354 = puVar5;
  if (puVar3 != &_vm_object_list) {
    *(undefined **)(puVar3 + 8) = puVar2;
    puVar2 = __vm_object_list;
  }
  __vm_object_list = puVar2;
  __vm_object_count = __vm_object_count + -1;
  LOCK();
  _vm_object_list_lock = 0;
  UNLOCK();
  iVar7 = _zfree(_vm_object_zone);
  __object_collapses = __object_collapses + 1;
  do {
    if (*(int *)(unaff_EBP + 8) == 0) {
      return iVar7;
    }
    iVar6 = *(int *)(unaff_EBP + 8);
    if (*(short *)(iVar6 + 0x44) != 0) {
      return iVar7;
    }
    if (*(int *)(iVar6 + 0x28) != 0) {
      return iVar7;
    }
    unaff_ESI = *(int **)(iVar6 + 0x20);
    if (unaff_ESI == (int *)0x0) {
      return iVar7;
    }
    piVar4 = unaff_ESI + 4;
    do {
      do {
      } while (*piVar4 != 0);
      LOCK();
      iVar7 = *piVar4;
      *piVar4 = 1;
      UNLOCK();
    } while (iVar7 == 1);
    if (((unaff_ESI[0x11] & 0x10ffffU) != 0x100000) ||
       ((unaff_ESI[8] != 0 && (*(int *)(unaff_ESI[8] + 0x1c) != 0)))) {
LAB_00179b4f:
      LOCK();
      iVar7 = unaff_ESI[4];
      unaff_ESI[4] = 0;
      UNLOCK();
      return iVar7;
    }
    *(undefined4 *)(unaff_EBP + -4) = *(undefined4 *)(*(int *)(unaff_EBP + 8) + 0x24);
    *(undefined4 *)(unaff_EBP + -8) = *(undefined4 *)(*(int *)(unaff_EBP + 8) + 0x14);
    if ((short)unaff_ESI[6] == 1) break;
    if (unaff_ESI[10] != 0) goto LAB_00179b4f;
    for (piVar4 = (int *)*unaff_ESI; unaff_ESI != piVar4; piVar4 = (int *)piVar4[2]) {
      if (((*(uint *)(unaff_EBP + -4) <= (uint)piVar4[6]) &&
          ((uint)(piVar4[6] - *(int *)(unaff_EBP + -4)) <= *(uint *)(unaff_EBP + -8))) &&
         (iVar7 = _vm_page_lookup(*(undefined4 *)(unaff_EBP + 8)), iVar7 == 0)) goto LAB_00179b4f;
    }
    iVar7 = unaff_ESI[8];
    *(int *)(*(int *)(unaff_EBP + 8) + 0x20) = iVar7;
    if (iVar7 != 0) {
      piVar4 = (int *)(iVar7 + 0x10);
      do {
        do {
        } while (*piVar4 != 0);
        LOCK();
        iVar6 = *piVar4;
        *piVar4 = 1;
        UNLOCK();
      } while (iVar6 == 1);
      *(short *)(iVar7 + 0x18) = *(short *)(iVar7 + 0x18) + 1;
      LOCK();
      *(undefined4 *)(iVar7 + 0x10) = 0;
      UNLOCK();
    }
    piVar4 = (int *)(*(int *)(unaff_EBP + 8) + 0x24);
    *piVar4 = *piVar4 + unaff_ESI[9];
    *(short *)(unaff_ESI + 6) = (short)unaff_ESI[6] + -1;
    LOCK();
    iVar7 = unaff_ESI[4];
    unaff_ESI[4] = 0;
    UNLOCK();
    __object_bypasses = __object_bypasses + 1;
  } while( true );
LAB_001799c1:
  if ((int *)*unaff_ESI != unaff_ESI) {
    iVar7 = *unaff_ESI;
    uVar1 = *(uint *)(iVar7 + 0x18);
    uVar8 = uVar1 - *(int *)(unaff_EBP + -4);
    if ((uVar1 < *(uint *)(unaff_EBP + -4)) || (*(uint *)(unaff_EBP + -8) <= uVar8)) {
      do {
      } while (_vm_page_queue_lock != 0);
      LOCK();
      UNLOCK();
LAB_00179a33:
      _vm_page_queue_lock = 1;
      _vm_page_free();
      LOCK();
      _vm_page_queue_lock = 0;
      UNLOCK();
    }
    else {
      *(uint *)(unaff_EBP + -0xc) = uVar8;
      iVar6 = _vm_page_lookup(*(undefined4 *)(unaff_EBP + 8));
      if (iVar6 != 0) {
        do {
        } while (_vm_page_queue_lock != 0);
        LOCK();
        UNLOCK();
        goto LAB_00179a33;
      }
      _vm_page_rename(iVar7,*(undefined4 *)(unaff_EBP + 8));
    }
    goto LAB_001799c1;
  }
  iVar7 = *(int *)(unaff_EBP + 8);
  *(int *)(iVar7 + 0x28) = unaff_ESI[10];
  *(int *)(iVar7 + 0x2c) = *(int *)(unaff_EBP + -4) + unaff_ESI[0xb];
  unaff_ESI[10] = 0;
  unaff_ESI[0xc] = 0;
  unaff_ESI[0xd] = 0;
  *(int *)(iVar7 + 0x20) = unaff_ESI[8];
  *(int *)(iVar7 + 0x24) = *(int *)(iVar7 + 0x24) + unaff_ESI[9];
  if ((*(int *)(iVar7 + 0x20) != 0) && (*(int *)(*(int *)(iVar7 + 0x20) + 0x1c) != 0)) {
                    /* WARNING: Subroutine does not return */
    _panic(s_vm_object_collapse__we_collapsed_001e0c60);
  }
  goto LAB_00179aad;
}

