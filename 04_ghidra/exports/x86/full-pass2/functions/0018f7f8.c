/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018f7f8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0018f7f8(int *param_1,uint param_2,uint param_3,undefined4 param_4)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  uint uVar7;
  int *piVar8;
  uint *puVar9;
  int local_18;
  int local_14;
  uint local_10;
  uint *local_8;
  
  local_10 = param_2;
  local_14 = 0;
  local_18 = 0;
  puVar9 = (uint *)(*param_1 + (param_2 >> 0x16) * 4);
  if (((*puVar9 & 1) != 0) &&
     (puVar9 = (uint *)((param_2 >> 10 & 0xffc) + (*puVar9 & 0xfffff000)), puVar9 != (uint *)0x0)) {
    puVar1 = (uint *)(*param_1 + (param_3 >> 0x16) * 4);
    if ((*puVar1 & 1) == 0) {
      local_8 = (uint *)0x0;
    }
    else {
      local_8 = (uint *)((*puVar1 & 0xfffff000) + (param_3 >> 10 & 0xffc));
    }
    uVar7 = ~_page_mask;
    if (((uint)puVar9 & uVar7) != ((uint)local_8 & uVar7)) {
      local_8 = (uint *)((uint)((int)puVar9 + _page_mask + _ptes_per_vm_page * 4) & uVar7);
    }
    while (puVar9 < local_8) {
      if ((*puVar9 & 1) == 0) {
        puVar9 = puVar9 + _ptes_per_vm_page;
      }
      else {
        local_14 = local_14 + 1;
        if ((*puVar9 & 0x200) != 0) {
          local_18 = local_18 + 1;
        }
        uVar7 = *puVar9 & 0xfffff000;
        iVar4 = _ptes_per_vm_page;
        if ((uVar7 < _vm_first_phys) || (_vm_last_phys <= uVar7)) {
          for (; 0 < iVar4; iVar4 = iVar4 + -1) {
            *puVar9 = 0;
            puVar9 = puVar9 + 1;
          }
        }
        else {
          piVar8 = (int *)(_pg_desc_tbl +
                          ((uVar7 - __pg_first_phys >> 0xc) >>
                          ((byte)(_ptes_per_vm_page + -1) & 0x1f)) * 0x14);
          iVar3 = _ptes_per_vm_page + -1;
          while (iVar2 = iVar3, 0 < iVar4) {
            if ((*puVar9 & 0x40) != 0) {
              iVar4 = _vm_phys_to_vm_page(uVar7);
              *(byte *)(iVar4 + 0x1e) = *(byte *)(iVar4 + 0x1e) & 0xdf;
              *(byte *)(piVar8 + 4) = *(byte *)(piVar8 + 4) | 1;
            }
            if ((*puVar9 & 0x20) != 0) {
              *(byte *)(piVar8 + 4) = *(byte *)(piVar8 + 4) | 2;
            }
            *puVar9 = 0;
            puVar9 = puVar9 + 1;
            iVar3 = iVar2 + -1;
            iVar4 = iVar2;
          }
          if (piVar8[1] == 0) {
                    /* WARNING: Subroutine does not return */
            _panic(s_pmap_remove_range_001e2539);
          }
          if ((piVar8[2] == local_10) && ((int *)piVar8[1] == param_1)) {
            piVar6 = (int *)*piVar8;
            if (piVar6 == (int *)0x0) {
              piVar8[1] = 0;
              goto LAB_0018fa0d;
            }
            *piVar8 = *piVar6;
            piVar8[1] = piVar6[1];
            piVar8[2] = piVar6[2];
          }
          else {
            piVar6 = (int *)*piVar8;
            if ((int *)*piVar8 == (int *)0x0) {
LAB_0018f9ec:
                    /* WARNING: Subroutine does not return */
              _panic(s_pmap_remove_range_2_001e254b);
            }
            do {
              piVar5 = piVar6;
              if ((piVar5[2] == local_10) && (piVar6 = piVar5, (int *)piVar5[1] == param_1)) break;
              piVar6 = (int *)*piVar5;
              piVar8 = piVar5;
            } while (piVar6 != (int *)0x0);
            if (piVar6 == (int *)0x0) goto LAB_0018f9ec;
            *piVar8 = *piVar6;
          }
          _zfree(_pv_entry_zone,piVar6);
        }
      }
LAB_0018fa0d:
      local_10 = local_10 + _page_size;
    }
    FUN_00190f90(param_1,param_2,local_14,local_18,param_4);
  }
  return;
}

