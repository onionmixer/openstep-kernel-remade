
void _pmap_enter_mapping(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                        int param_7)

{
  undefined4 *puVar1;
  uint *puVar2;
  undefined4 uVar3;
  byte bVar4;
  int iVar5;
  byte bVar6;
  bool bVar7;
  int iVar8;
  uint *puVar9;
  uint uVar10;
  uint *puVar11;
  undefined4 *puVar12;
  byte *pbStack_10;
  undefined2 uStack_8;
  byte bStack_6;
  byte bStack_5;
  
  bVar7 = false;
  if (param_1 != 0) {
    if (param_4 == 0) {
      _pmap_remove(param_1,param_2,_page_size + param_2);
    }
    else {
      if ((param_6 == 0) ||
         ((_managed_page_count != 0 && (iVar8 = _pmap_phys_to_index(param_3), iVar8 == -1)))) {
        bVar7 = true;
      }
      uVar3 = *(undefined4 *)(_protection_codes + param_4 * 4);
      puVar12 = (undefined4 *)0x0;
      while( true ) {
        while (puVar9 = (uint *)_pmap_pte(param_1,param_2), (int)puVar9 < 0) {
          if (param_1 == _kernel_pmap) {
            _pmap_expand_kernel(param_2,puVar9);
          }
          else {
            _pmap_expand(param_1,param_2,puVar9);
          }
        }
        if (_pv_head_table == 0) goto loc_4098444;
        if (_cpu_type == '\0') {
          uVar10 = *puVar9 >> 8;
        }
        else {
          uVar10 = *puVar9 >> 0xc;
        }
        if (((*puVar9 & 3) == 1) && (param_3 == uVar10 << (_m68k_pte_pfn & 0x3f))) goto loc_4098444;
        _pmap_remove_range(param_1,param_2,_page_size + param_2);
        iVar8 = _pmap_phys_to_index(param_3);
        if (iVar8 == -1) goto loc_4098444;
        puVar1 = (undefined4 *)(_pv_head_table + iVar8 * 0xc);
        if (puVar1[1] == 0) {
          puVar1[2] = param_2;
          puVar1[1] = param_1;
          *puVar1 = 0;
          goto loc_4098436;
        }
        if (puVar12 != (undefined4 *)0x0) break;
        puVar12 = (undefined4 *)_zalloc(_pv_list_zone);
      }
      puVar12[2] = param_2;
      puVar12[1] = param_1;
      *puVar12 = *puVar1;
      *puVar1 = puVar12;
      puVar12 = (undefined4 *)0x0;
loc_4098436:
      *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
      if (param_5 != 0) {
        *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
      }
loc_4098444:
      iVar8 = _m68k_page_size;
      if ((*puVar9 & 3) == 1) {
        if (param_1 == _kernel_pmap) {
          _pflush_super();
        }
        else if (_active_threads != 0) {
          _pflush_user();
        }
        puVar2 = puVar9 + _m68k_ptes_per_page;
        if (puVar9 < puVar2) {
          bVar6 = ((byte)uVar3 & 1) << 2;
          puVar11 = (uint *)((int)puVar9 + 3);
          pbStack_10 = (byte *)((int)puVar9 + 2);
          do {
            bVar4 = *(byte *)puVar11;
            *(byte *)puVar11 = bVar6 | bVar4 & 0xfb;
            if (_cpu_type == '\0') {
              *(byte *)puVar11 = ((byte)param_5 & 1) << 5 | bVar6 | bVar4 & 0xdb;
            }
            else {
              *pbStack_10 = ((byte)param_5 & 1) << 3 | *pbStack_10 & 0xf7;
            }
            uVar10 = _m68k_cache;
            if ((bVar7) && (uVar10 = _m68k_cache_inhibit_nonserial, param_7 != 0)) {
              uVar10 = _m68k_cache_inhibit_serial;
            }
            if (_cpu_type == '\0') {
              *(byte *)puVar11 = ((byte)uVar10 & 1) << 6 | *(byte *)puVar11 & 0xbf;
            }
            else {
              *puVar11 = *puVar11 & 0x9fffffff | (uVar10 & 3) << 0x1d;
            }
            puVar11 = puVar11 + 1;
            pbStack_10 = pbStack_10 + 4;
            puVar9 = puVar9 + 1;
          } while (puVar9 < puVar2);
        }
      }
      else {
        bStack_6 = 0;
        bStack_5 = ((byte)uVar3 & 1) << 2 | 1;
        if ((_cpu_type != '\0') && (param_1 == _kernel_pmap)) {
          bStack_6 = 4;
        }
        if (_cpu_type == '\0') {
          bStack_5 = ((byte)param_5 & 1) << 5 | bStack_5;
        }
        else {
          bStack_6 = ((byte)param_5 & 1) << 3 | bStack_6;
        }
        uVar10 = _m68k_cache;
        if ((bVar7) && (uVar10 = _m68k_cache_inhibit_nonserial, param_7 != 0)) {
          uVar10 = _m68k_cache_inhibit_serial;
        }
        if (_cpu_type == '\0') {
          bStack_5 = ((byte)uVar10 & 1) << 6 | bStack_5;
        }
        else {
          bStack_5 = bStack_5 & 0x9f | (byte)(((uVar10 & 3) << 0x1d) >> 0x18);
        }
        param_3 = param_3 >> (_m68k_pte_pfn & 0x3f);
        if (_cpu_type == '\0') {
          uVar10 = CONCAT31((int3)param_3,bStack_5);
        }
        else {
          uVar10 = param_3 << 0xc | (uint)CONCAT11(bStack_6,bStack_5);
        }
        uStack_8 = (undefined2)(uVar10 >> 0x10);
        bStack_6 = (byte)(uVar10 >> 8);
        bStack_5 = (byte)uVar10;
        puVar2 = puVar9 + _m68k_ptes_per_page;
        for (; puVar9 < puVar2; puVar9 = puVar9 + 1) {
          *puVar9 = CONCAT31(CONCAT21(uStack_8,bStack_6),bStack_5);
          iVar5 = iVar8 + CONCAT31(CONCAT21(uStack_8,bStack_6),bStack_5);
          uStack_8 = (undefined2)((uint)iVar5 >> 0x10);
          bStack_6 = (byte)((uint)iVar5 >> 8);
          bStack_5 = (byte)iVar5;
        }
      }
      if (puVar12 != (undefined4 *)0x0) {
        _zfree(_pv_list_zone,puVar12);
      }
    }
  }
  return;
}

