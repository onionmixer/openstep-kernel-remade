/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00194c73 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

int __analysis_fragment_00194c73(void)

{
  undefined4 *puVar1;
  int *piVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int unaff_EBX;
  uint uVar7;
  int unaff_EBP;
  int unaff_EDI;
  
  do {
    while( true ) {
      while( true ) {
        while( true ) {
          if (*(int *)(*(int *)(unaff_EBP + 0xc) + 0x14) < 1) {
            return unaff_EBX;
          }
          if (unaff_EBX != 0) {
            return unaff_EBX;
          }
          puVar1 = *(undefined4 **)(unaff_EBP + 0xc);
          piVar2 = (int *)*puVar1;
          iVar5 = piVar2[1];
          if (iVar5 != 0) break;
          *puVar1 = piVar2 + 2;
          iVar5 = puVar1[1];
          puVar1[1] = iVar5 + -1;
          if (iVar5 + -1 < 0) {
                    /* WARNING: Subroutine does not return */
            _panic(&DAT_001e36a0);
          }
        }
        if (*(short *)(unaff_EBP + -0xc) != 1) break;
        iVar6 = _kernacc(*(undefined4 *)(*(int *)(unaff_EBP + 0xc) + 8),iVar5);
        if (iVar6 == 0) {
          return 0xe;
        }
        unaff_EBX = _uiomove(*(undefined4 *)(*(int *)(unaff_EBP + 0xc) + 8),iVar5,
                             *(undefined4 *)(unaff_EBP + 0x10));
        unaff_EDI = iVar5;
      }
      if (1 < *(short *)(unaff_EBP + -0xc)) break;
      if (*(short *)(unaff_EBP + -0xc) != 0) goto LAB_00194db8;
      uVar3 = *(uint *)(*(int *)(unaff_EBP + 0xc) + 8);
      uVar7 = ~_page_mask & uVar3;
      if (_mem_size <= uVar3) {
        return 0xe;
      }
      uVar4 = _splvm();
      *(undefined4 *)(unaff_EBP + -8) = uVar4;
      iVar5 = _kernel_map;
      *(int *)(unaff_EBP + -0x10) = _kernel_map;
      *(undefined4 *)(unaff_EBP + -4) = *(undefined4 *)(iVar5 + 0x14);
      iVar5 = _vm_map_find(*(undefined4 *)(unaff_EBP + -0x10),0,0,unaff_EBP + -4,_page_size);
      if (iVar5 != 0) {
        _splx();
        return 0xe;
      }
      _pmap_enter(*(undefined4 *)(_kernel_map + 0x24),*(undefined4 *)(unaff_EBP + -4),uVar7,3);
      iVar5 = *(int *)(*(int *)(unaff_EBP + 0xc) + 8) - uVar7;
      unaff_EDI = _min(_page_size - iVar5,piVar2[1]);
      unaff_EBX = _uiomove(iVar5 + *(int *)(unaff_EBP + -4),unaff_EDI,
                           *(undefined4 *)(unaff_EBP + 0x10),*(undefined4 *)(unaff_EBP + 0xc));
      _vm_map_remove(_kernel_map,*(undefined4 *)(unaff_EBP + -4));
      _splx(*(undefined4 *)(unaff_EBP + -8));
    }
    if ((*(short *)(unaff_EBP + -0xc) == 2) && (unaff_EDI = iVar5, *(int *)(unaff_EBP + 0x10) == 0))
    {
      return 0;
    }
LAB_00194db8:
    *piVar2 = *piVar2 + unaff_EDI;
    piVar2[1] = piVar2[1] - unaff_EDI;
    iVar5 = *(int *)(unaff_EBP + 0xc);
    piVar2 = (int *)(iVar5 + 8);
    *piVar2 = *piVar2 + unaff_EDI;
    piVar2 = (int *)(iVar5 + 0x14);
    *piVar2 = *piVar2 - unaff_EDI;
  } while( true );
}

