/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018fdfc */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_0018fdfc(void)

{
  uint uVar1;
  byte bVar2;
  uint uVar3;
  uint *puVar4;
  int iVar5;
  byte bVar6;
  int *piVar7;
  byte *unaff_EBX;
  int unaff_EBP;
  uint unaff_ESI;
  int in_FS_OFFSET;
  
  while( true ) {
    iVar5 = _kernel_pmap;
    uVar3 = _page_size;
    uVar1 = _page_size + unaff_ESI;
    *(int *)(unaff_EBP + -0x10) = _kernel_pmap;
    if (((*(int *)(unaff_EBP + -0xc) == iVar5) || (*(int *)(*(int *)(unaff_EBP + -0xc) + 0x18) != 0)
        ) && (__tlb_stat = __tlb_stat + 1, uVar1 - unaff_ESI <= uVar3)) {
      if (unaff_ESI < uVar1) {
        do {
          if (*(int *)(unaff_EBP + -0xc) == *(int *)(unaff_EBP + -0x10)) {
            invlpg(unaff_ESI);
          }
          else {
            invlpg(in_FS_OFFSET + unaff_ESI);
          }
          unaff_ESI = unaff_ESI + 0x1000;
        } while (unaff_ESI < uVar1);
      }
      _DAT_001f7af4 = _DAT_001f7af4 + 1;
    }
    iVar5 = _ptes_per_vm_page;
    if (((*unaff_EBX & 6) == 6) || ((*unaff_EBX & 6) == 2)) {
      while (0 < iVar5) {
        bVar2 = *unaff_EBX;
        bVar6 = (byte)DAT_001f7b04;
        if (_kernel_pmap == *(int *)(unaff_EBP + -0xc)) {
          bVar6 = (byte)DAT_001f7a84;
        }
        *unaff_EBX = bVar2 & 0xf9 | (bVar6 & 3) * '\x02';
        *unaff_EBX = *unaff_EBX & 0xfe | bVar2 & 1;
        unaff_EBX = unaff_EBX + 4;
        iVar5 = iVar5 + -1;
      }
    }
    LOCK();
    *(undefined4 *)(*(int *)(unaff_EBP + -0xc) + 0xc) = 0;
    UNLOCK();
    iVar5 = **(int **)(unaff_EBP + -4);
    *(int *)(unaff_EBP + -4) = iVar5;
    if (iVar5 == 0) break;
    *(undefined4 *)(unaff_EBP + -0xc) = *(undefined4 *)(*(int *)(unaff_EBP + -4) + 4);
    unaff_ESI = *(uint *)(*(int *)(unaff_EBP + -4) + 8);
    piVar7 = (int *)(*(int *)(unaff_EBP + -0xc) + 0xc);
    do {
      do {
      } while (*piVar7 != 0);
      LOCK();
      iVar5 = *piVar7;
      *piVar7 = 1;
      UNLOCK();
    } while (iVar5 == 1);
    puVar4 = (uint *)((unaff_ESI >> 0x16) * 4 + **(int **)(unaff_EBP + -0xc));
    if ((((*puVar4 & 1) == 0) ||
        (unaff_EBX = (byte *)((unaff_ESI >> 10 & 0xffc) + (*puVar4 & 0xfffff000)),
        unaff_EBX == (byte *)0x0)) || ((*unaff_EBX & 1) == 0)) {
                    /* WARNING: Subroutine does not return */
      _panic(s_pmap_copy_on_write_001e2593);
    }
  }
  _splx();
  return;
}

