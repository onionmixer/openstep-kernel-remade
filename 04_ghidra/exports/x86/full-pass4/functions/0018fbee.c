/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018fbee */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_0018fbee(void)

{
  byte *pbVar1;
  int *piVar2;
  uint uVar3;
  uint *puVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  int iVar8;
  int unaff_EBP;
  uint *unaff_ESI;
  int in_FS_OFFSET;
  
  while( true ) {
    uVar3 = _page_size;
    if ((*unaff_ESI & 0x200) != 0) {
                    /* WARNING: Subroutine does not return */
      _panic(s_pmap_remove_all_3_001e2581);
    }
    uVar7 = *(uint *)(unaff_EBP + -0xc);
    *(uint *)(unaff_EBP + -0x1c) = uVar7 + _page_size;
    iVar8 = _kernel_pmap;
    *(int *)(unaff_EBP + -0x18) = _kernel_pmap;
    if (((*(int *)(unaff_EBP + -0x10) == iVar8) ||
        (*(int *)(*(int *)(unaff_EBP + -0x10) + 0x18) != 0)) &&
       (__tlb_stat = __tlb_stat + 1,
       (uint)(*(int *)(unaff_EBP + -0x1c) - *(int *)(unaff_EBP + -0xc)) <= uVar3)) {
      if (*(uint *)(unaff_EBP + -0xc) < *(uint *)(unaff_EBP + -0x1c)) {
        do {
          if (*(int *)(unaff_EBP + -0x10) == *(int *)(unaff_EBP + -0x18)) {
            invlpg(uVar7);
          }
          else {
            invlpg(in_FS_OFFSET + uVar7);
          }
          uVar7 = uVar7 + 0x1000;
        } while (uVar7 < *(uint *)(unaff_EBP + -0x1c));
      }
      _DAT_001f7af4 = _DAT_001f7af4 + 1;
    }
    piVar6 = *(int **)(unaff_EBP + -4);
    piVar2 = (int *)*piVar6;
    if (piVar2 == (int *)0x0) {
      *(undefined4 *)(*(int *)(unaff_EBP + -4) + 4) = 0;
      iVar8 = _ptes_per_vm_page;
    }
    else {
      *piVar6 = *piVar2;
      piVar6[1] = piVar2[1];
      piVar6[2] = piVar2[2];
      _zfree(_pv_entry_zone);
      iVar8 = _ptes_per_vm_page;
    }
    while (0 < iVar8) {
      if ((*unaff_ESI & 0x40) != 0) {
        iVar5 = _vm_phys_to_vm_page();
        *(byte *)(iVar5 + 0x1e) = *(byte *)(iVar5 + 0x1e) & 0xdf;
        pbVar1 = (byte *)(*(int *)(unaff_EBP + -8) + 0x10);
        *pbVar1 = *pbVar1 | 1;
      }
      if ((*unaff_ESI & 0x20) != 0) {
        pbVar1 = (byte *)(*(int *)(unaff_EBP + -8) + 0x10);
        *pbVar1 = *pbVar1 | 2;
      }
      *unaff_ESI = 0;
      unaff_ESI = unaff_ESI + 1;
      iVar8 = iVar8 + -1;
    }
    FUN_00190f90(*(undefined4 *)(unaff_EBP + -0x10),*(undefined4 *)(unaff_EBP + -0xc),1,0);
    LOCK();
    *(undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xc) = 0;
    UNLOCK();
    iVar8 = *(int *)(*(int *)(unaff_EBP + -4) + 4);
    *(int *)(unaff_EBP + -0x10) = iVar8;
    if (iVar8 == 0) break;
    *(undefined4 *)(unaff_EBP + -0xc) = *(undefined4 *)(*(int *)(unaff_EBP + -4) + 8);
    piVar6 = (int *)(*(int *)(unaff_EBP + -0x10) + 0xc);
    do {
      do {
      } while (*piVar6 != 0);
      LOCK();
      iVar8 = *piVar6;
      *piVar6 = 1;
      UNLOCK();
    } while (iVar8 == 1);
    puVar4 = (uint *)((*(uint *)(unaff_EBP + -0xc) >> 0x16) * 4 + **(int **)(unaff_EBP + -0x10));
    if ((((*puVar4 & 1) == 0) ||
        (unaff_ESI = (uint *)((*(uint *)(unaff_EBP + -0xc) >> 10 & 0xffc) + (*puVar4 & 0xfffff000)),
        unaff_ESI == (uint *)0x0)) || ((*unaff_ESI & 1) == 0)) {
                    /* WARNING: Subroutine does not return */
      _panic(s_pmap_remove_all_001e255f);
    }
    if (*(uint *)(unaff_EBP + 8) != (*unaff_ESI & 0xfffff000)) {
                    /* WARNING: Subroutine does not return */
      _panic(s_pmap_remove_all_2_001e256f);
    }
  }
  _splx();
  return;
}

