
void _pmap_remove_range(int param_1,uint param_2,uint param_3)

{
  int *piVar1;
  byte bVar2;
  uint *puVar3;
  uint *puVar4;
  int iVar5;
  uint uVar6;
  uint *puVar7;
  int *piVar8;
  uint *puVar9;
  
  if (param_1 == _kernel_pmap) {
    _pflush_super();
  }
  else if (_active_threads != 0) {
    _pflush_user();
  }
  do {
    while( true ) {
      if (param_3 <= param_2) {
        return;
      }
      puVar4 = (uint *)_pmap_pte(param_1,param_2);
      if (-1 < (int)puVar4) break;
      uVar6 = _m68k_pt2_maps;
      if (puVar4 == (uint *)0xfffffffd) {
        uVar6 = _m68k_pte_maps;
      }
      param_2 = uVar6 + (-uVar6 & param_2);
      if (param_2 == 0) {
        return;
      }
    }
    uVar6 = _m68k_page_shift & 0x3f;
    iVar5 = _pmap_pte(param_1,_m68k_pte_maps * ((_m68k_pte_maps + param_2) / _m68k_pte_maps) + -1);
    puVar7 = puVar4 + (param_3 - param_2 >> uVar6);
    if ((uint *)(iVar5 + 4) < puVar4 + (param_3 - param_2 >> uVar6)) {
      puVar7 = (uint *)(iVar5 + 4);
    }
    puVar9 = puVar4;
    if (puVar4 < puVar7) {
      do {
        if ((*puVar9 & 0x13) == 0x11) {
          if (_cpu_type == '\0') {
            uVar6 = *puVar9 >> 8;
          }
          else {
            uVar6 = *puVar9 >> 0xc;
          }
          iVar5 = _vm_phys_to_vm_page(uVar6 << (_m68k_pte_pfn & 0x3f));
          if (iVar5 != 0) {
            *(byte *)(iVar5 + 0x1e) = *(byte *)(iVar5 + 0x1e) & 0xfb;
          }
        }
        puVar9 = puVar9 + 1;
        puVar3 = puVar4;
      } while (puVar9 < puVar7);
      for (; puVar3 < puVar7; puVar3 = puVar3 + _m68k_ptes_per_page) {
        if (_cpu_type == '\0') {
          uVar6 = *puVar3 >> 8;
        }
        else {
          uVar6 = *puVar3 >> 0xc;
        }
        if (((*puVar3 & 3) == 1) &&
           (iVar5 = _pmap_phys_to_index(uVar6 << (_m68k_pte_pfn & 0x3f)), iVar5 != -1)) {
          *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + -1;
          if (_cpu_type == '\0') {
            bVar2 = (byte)*puVar3 & 0x20;
          }
          else {
            bVar2 = *(byte *)((int)puVar3 + 2) & 8;
          }
          if (bVar2 != 0) {
            *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + -1;
          }
          piVar1 = (int *)(_pv_head_table + iVar5 * 0xc);
          if ((param_2 == piVar1[2]) && (param_1 == piVar1[1])) {
            piVar8 = (int *)*piVar1;
            if (piVar8 == (int *)0x0) {
              piVar1[1] = 0;
              goto loc_4097E1C;
            }
            *piVar1 = *piVar8;
            piVar1[1] = piVar8[1];
            piVar1[2] = piVar8[2];
          }
          else {
            for (piVar8 = (int *)*piVar1;
                (piVar8 != (int *)0x0 && ((param_2 != piVar8[2] || (param_1 != piVar8[1]))));
                piVar8 = (int *)*piVar8) {
              piVar1 = piVar8;
            }
            *piVar1 = *piVar8;
          }
          _zfree(_pv_list_zone,piVar8);
        }
loc_4097E1C:
        *puVar3 = 0;
        param_2 = _page_size + param_2;
      }
    }
    if (1 < _m68k_ptes_per_page) {
      _bzero(puVar4,_m68k_pte_elemsize * ((int)puVar7 - (int)puVar4 >> 2));
    }
  } while( true );
}
