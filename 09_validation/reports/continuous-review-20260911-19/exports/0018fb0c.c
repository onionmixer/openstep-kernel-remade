
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _pmap_remove_all(uint param_1)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  uint *puVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  int in_FS_OFFSET;
  
  if ((_vm_first_phys <= param_1) && (param_1 < _vm_last_phys)) {
    uVar5 = _splvm();
    piVar1 = (int *)(_pg_desc_tbl +
                    ((param_1 - __pg_first_phys >> 0xc) >> ((char)_ptes_per_vm_page - 1U & 0x1f)) *
                    0x14);
    piVar2 = (int *)piVar1[1];
    while (piVar2 != (int *)0x0) {
      uVar3 = piVar1[2];
      piVar8 = piVar2 + 3;
      do {
        do {
        } while (*piVar8 != 0);
        LOCK();
        iVar9 = *piVar8;
        *piVar8 = 1;
        UNLOCK();
      } while (iVar9 == 1);
      puVar6 = (uint *)((uVar3 >> 0x16) * 4 + *piVar2);
      if ((((*puVar6 & 1) == 0) ||
          (puVar6 = (uint *)((uVar3 >> 10 & 0xffc) + (*puVar6 & 0xfffff000)), puVar6 == (uint *)0x0)
          ) || ((*puVar6 & 1) == 0)) {
                    /* WARNING: Subroutine does not return */
        _panic(s_pmap_remove_all_001e255f);
      }
      if (param_1 != (*puVar6 & 0xfffff000)) {
                    /* WARNING: Subroutine does not return */
        _panic(s_pmap_remove_all_2_001e256f);
      }
      if ((*puVar6 & 0x200) != 0) {
                    /* WARNING: Subroutine does not return */
        _panic(s_pmap_remove_all_3_001e2581);
      }
      if (((piVar2 == _kernel_pmap) || (piVar2[6] != 0)) &&
         (__tlb_stat = __tlb_stat + 1, uVar4 = uVar3, (uVar3 + _page_size) - uVar3 <= _page_size)) {
        for (; uVar4 < uVar3 + _page_size; uVar4 = uVar4 + 0x1000) {
          if (piVar2 == _kernel_pmap) {
            invlpg(uVar4);
          }
          else {
            invlpg(in_FS_OFFSET + uVar4);
          }
        }
        _DAT_001f7af4 = _DAT_001f7af4 + 1;
      }
      piVar8 = (int *)*piVar1;
      if (piVar8 == (int *)0x0) {
        piVar1[1] = 0;
        iVar9 = _ptes_per_vm_page;
      }
      else {
        *piVar1 = *piVar8;
        piVar1[1] = piVar8[1];
        piVar1[2] = piVar8[2];
        _zfree(_pv_entry_zone,piVar8);
        iVar9 = _ptes_per_vm_page;
      }
      while (0 < iVar9) {
        if ((*puVar6 & 0x40) != 0) {
          iVar7 = _vm_phys_to_vm_page(param_1);
          *(byte *)(iVar7 + 0x1e) = *(byte *)(iVar7 + 0x1e) & 0xdf;
          *(byte *)(piVar1 + 4) = *(byte *)(piVar1 + 4) | 1;
        }
        if ((*puVar6 & 0x20) != 0) {
          *(byte *)(piVar1 + 4) = *(byte *)(piVar1 + 4) | 2;
        }
        *puVar6 = 0;
        puVar6 = puVar6 + 1;
        iVar9 = iVar9 + -1;
      }
      FUN_00190f90(piVar2,uVar3,1,0,1);
      LOCK();
      piVar2[3] = 0;
      UNLOCK();
      piVar2 = (int *)piVar1[1];
    }
    _splx(uVar5);
  }
  return;
}

