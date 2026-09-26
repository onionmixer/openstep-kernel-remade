/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018f9f6 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_0018f9f6(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  int *unaff_EBX;
  int unaff_EBP;
  int *unaff_ESI;
  uint *unaff_EDI;
  
LAB_0018f9f9:
  *unaff_ESI = *unaff_EBX;
  do {
    _zfree(_pv_entry_zone);
    while( true ) {
      while( true ) {
        while( true ) {
          *(int *)(unaff_EBP + -0xc) = *(int *)(unaff_EBP + -0xc) + _page_size;
          if (*(uint **)(unaff_EBP + -4) <= unaff_EDI) {
            FUN_00190f90(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0xc),
                         *(undefined4 *)(unaff_EBP + -0x10),*(undefined4 *)(unaff_EBP + -0x14));
            return;
          }
          if ((*unaff_EDI & 1) != 0) break;
          unaff_EDI = unaff_EDI + _ptes_per_vm_page;
        }
        *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
        if ((*unaff_EDI & 0x200) != 0) {
          *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 1;
        }
        uVar4 = *unaff_EDI & 0xfffff000;
        *(uint *)(unaff_EBP + -8) = uVar4;
        iVar3 = _ptes_per_vm_page;
        if ((_vm_first_phys <= uVar4) && (uVar4 < _vm_last_phys)) break;
        for (; 0 < iVar3; iVar3 = iVar3 + -1) {
          *unaff_EDI = 0;
          unaff_EDI = unaff_EDI + 1;
        }
      }
      unaff_ESI = (int *)(_pg_desc_tbl +
                         (((uint)(*(int *)(unaff_EBP + -8) - __pg_first_phys) >> 0xc) >>
                         ((byte)(_ptes_per_vm_page + -1) & 0x1f)) * 0x14);
      iVar2 = _ptes_per_vm_page + -1;
      while (iVar1 = iVar2, 0 < iVar3) {
        if ((*unaff_EDI & 0x40) != 0) {
          iVar3 = _vm_phys_to_vm_page();
          *(byte *)(iVar3 + 0x1e) = *(byte *)(iVar3 + 0x1e) & 0xdf;
          *(byte *)(unaff_ESI + 4) = *(byte *)(unaff_ESI + 4) | 1;
        }
        if ((*unaff_EDI & 0x20) != 0) {
          *(byte *)(unaff_ESI + 4) = *(byte *)(unaff_ESI + 4) | 2;
        }
        *unaff_EDI = 0;
        unaff_EDI = unaff_EDI + 1;
        iVar2 = iVar1 + -1;
        iVar3 = iVar1;
      }
      if (unaff_ESI[1] == 0) {
                    /* WARNING: Subroutine does not return */
        _panic(s_pmap_remove_range_001e2539);
      }
      if ((unaff_ESI[2] != *(int *)(unaff_EBP + -0xc)) || (unaff_ESI[1] != *(int *)(unaff_EBP + 8)))
      {
        unaff_EBX = (int *)*unaff_ESI;
        if ((int *)*unaff_ESI != (int *)0x0) goto LAB_0018f9d0;
        goto LAB_0018f9ec;
      }
      piVar5 = (int *)*unaff_ESI;
      if (piVar5 != (int *)0x0) break;
      unaff_ESI[1] = 0;
    }
    *unaff_ESI = *piVar5;
    unaff_ESI[1] = piVar5[1];
    unaff_ESI[2] = piVar5[2];
  } while( true );
  while (unaff_EBX = (int *)*piVar5, unaff_ESI = piVar5, unaff_EBX != (int *)0x0) {
LAB_0018f9d0:
    piVar5 = unaff_EBX;
    if ((piVar5[2] == *(int *)(unaff_EBP + -0xc)) &&
       (unaff_EBX = piVar5, piVar5[1] == *(int *)(unaff_EBP + 8))) break;
  }
  if (unaff_EBX == (int *)0x0) {
LAB_0018f9ec:
                    /* WARNING: Subroutine does not return */
    _panic(s_pmap_remove_range_2_001e254b);
  }
  goto LAB_0018f9f9;
}

