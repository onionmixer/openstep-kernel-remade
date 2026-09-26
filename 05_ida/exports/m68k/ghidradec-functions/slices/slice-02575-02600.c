/* GHIDRADEC_FUNCTION index=2575 start=0x4097e6c */

byte _pmap_remove(int param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  byte bVar5;
  
  bVar5 = 0;
  if (param_1 != 0) {
    cVar1 = '\0';
    cVar2 = param_1 < 0;
    cVar3 = param_1 == 0;
    cVar4 = '\0';
    bVar5 = 0;
    _pmap_remove_range(param_1,param_2,param_3);
    bVar5 = cVar1 << 4 | cVar2 << 3 | cVar3 << 2 | cVar4 << 1 | bVar5;
  }
  return bVar5;
}
/* GHIDRADEC_FUNCTION index=2576 start=0x4097e9c */

byte _pmap_remove_all(undefined4 param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int *piVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  bool bVar9;
  bool bVar10;
  bool bVar11;
  
  iVar5 = _vm_phys_to_vm_page(param_1);
  iVar6 = _pmap_phys_to_index(param_1);
  bVar11 = false;
  bVar10 = SBORROW4(-1,iVar6);
  iVar8 = -1 - iVar6;
  bVar9 = iVar6 == -1;
  if (!bVar9) {
    piVar1 = (int *)(_pv_head_table + iVar6 * 0xc);
    while( true ) {
      iVar6 = piVar1[1];
      bVar10 = false;
      bVar9 = true;
      iVar8 = 0;
      if (iVar6 == 0) break;
      if (iVar6 == _kernel_pmap) {
        _pflush_super();
      }
      else if (_active_threads != 0) {
        _pflush_user();
      }
      iVar8 = piVar1[2];
      puVar7 = (undefined4 *)_pmap_pte_valid(iVar6,iVar8);
      *(int *)(iVar6 + 0x10) = *(int *)(iVar6 + 0x10) + -1;
      if (_cpu_type == '\0') {
        bVar4 = *(byte *)((int)puVar7 + 3) & 0x20;
      }
      else {
        bVar4 = *(byte *)((int)puVar7 + 2) & 8;
      }
      if (bVar4 != 0) {
        *(int *)(iVar6 + 0x14) = *(int *)(iVar6 + 0x14) + -1;
      }
      piVar3 = (int *)*piVar1;
      if (piVar3 == (int *)0x0) {
        piVar1[1] = 0;
      }
      else {
        *piVar1 = *piVar3;
        piVar1[1] = piVar3[1];
        piVar1[2] = piVar3[2];
        _zfree(_pv_list_zone,piVar3);
      }
      puVar2 = puVar7 + _m68k_ptes_per_page;
      bVar11 = puVar2 < puVar7;
      if (puVar7 < puVar2) {
        do {
          if (((*(byte *)((int)puVar7 + 3) & 0x13) == 0x11) && (iVar5 != 0)) {
            *(byte *)(iVar5 + 0x1e) = *(byte *)(iVar5 + 0x1e) & 0xfb;
          }
          *puVar7 = 0;
          _pmap_collapse(iVar6,iVar8,puVar7);
          puVar7 = puVar7 + 1;
          iVar8 = _m68k_page_size + iVar8;
          bVar11 = puVar2 < puVar7;
        } while (!bVar11 && puVar2 != puVar7);
      }
    }
  }
  return bVar11 << 4 | (iVar8 < 0) << 3 | bVar9 << 2 | bVar10 << 1;
}
/* GHIDRADEC_FUNCTION index=2577 start=0x4097fba */

void _pmap_collapse(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  uint *puVar2;
  byte *pbVar3;
  uint uVar4;
  uint *puVar5;
  uint *puVar6;
  
  if ((param_1 != _kernel_pmap) && (_pmap_coll != 0)) {
    uVar4 = param_3 + ((_m68k_pte_mask & param_2) >> (_m68k_pte_shift & 0x3f)) * -4;
    uVar1 = uVar4 + _m68k_pte_entries * 4;
    for (; uVar4 < uVar1; uVar4 = uVar4 + 4) {
      if ((*(byte *)(uVar4 + 3) & 3) == 1) {
        return;
      }
    }
    puVar2 = (uint *)(*(int *)(param_1 + 8) +
                     ((_m68k_pt1_mask & param_2) >> (_m68k_pt1_shift & 0x3f)) * 4);
    puVar6 = (uint *)(((*puVar2 >> 9) << (_m68k_pt1_l2ptr & 0x3f)) +
                     ((_m68k_pt2_mask & param_2) >> (_m68k_pt2_shift & 0x3f)) * 4);
    sub_40970C6(_pte_zone,(*puVar6 >> 7) << (_m68k_pt2_l3ptr & 0x3f));
    *(byte *)((int)puVar6 + 3) = *(byte *)((int)puVar6 + 3) & 0xfc;
    puVar6 = puVar6 + -((_m68k_pt2_mask & param_2) >> (_m68k_pt2_shift & 0x3f));
    for (puVar5 = puVar6; puVar5 < puVar6 + _m68k_pt2_entries; puVar5 = puVar5 + 1) {
      if (_m68k_pt2_desctype == ((byte)*puVar5 & 3)) {
        return;
      }
    }
    sub_40970C6(_pt_zone,puVar6);
    pbVar3 = (byte *)((int)puVar2 + 3);
    *pbVar3 = *pbVar3 & 0xfc;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2578 start=0x40980d6 */

byte _pmap_copy_on_write(undefined4 param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;
  byte *pbVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  
  iVar5 = _pmap_phys_to_index(param_1);
  bVar10 = false;
  bVar9 = SBORROW4(-1,iVar5);
  iVar3 = -1 - iVar5;
  bVar8 = iVar5 == -1;
  if (!bVar8) {
    puVar1 = (undefined4 *)(_pv_head_table + iVar5 * 0xc);
    bVar10 = false;
    puVar4 = (undefined4 *)puVar1[1];
    while( true ) {
      bVar9 = false;
      iVar3 = 0;
      bVar8 = true;
      if (puVar4 == (undefined4 *)0x0) break;
      iVar3 = puVar1[1];
      if (iVar3 == _kernel_pmap) {
        _pflush_super();
      }
      else if (_active_threads != 0) {
        _pflush_user();
      }
      uVar6 = _pmap_pte_valid(iVar3,puVar1[2]);
      uVar2 = uVar6 + _m68k_ptes_per_page * 4;
      bVar10 = uVar2 < uVar6;
      if (uVar6 < uVar2) {
        pbVar7 = (byte *)(uVar6 + 3);
        do {
          if ((*pbVar7 & 3) == 1) {
            *pbVar7 = *pbVar7 | 4;
          }
          pbVar7 = pbVar7 + 4;
          uVar6 = uVar6 + 4;
          bVar10 = uVar2 < uVar6;
        } while (!bVar10 && uVar2 != uVar6);
      }
      puVar1 = (undefined4 *)*puVar1;
      puVar4 = puVar1;
    }
  }
  return bVar10 << 4 | (iVar3 < 0) << 3 | bVar8 << 2 | bVar9 << 1;
}
/* GHIDRADEC_FUNCTION index=2579 start=0x409818a */

uint _pmap_protect(uint param_1,uint param_2,uint param_3,uint param_4)

{
  undefined4 uVar1;
  uint uVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  byte *pbVar6;
  
  if (param_1 != 0) {
    if (param_4 == 0) {
      param_4 = _pmap_remove(param_1,param_2,param_3);
    }
    else {
      uVar1 = *(undefined4 *)(_protection_codes + param_4 * 4);
      if (param_1 == _kernel_pmap) {
        param_4 = _pflush_super();
      }
      else if (_active_threads != 0) {
        param_4 = _pflush_user();
      }
      if (param_2 < param_3) {
        do {
          uVar2 = _m68k_pte_maps + (-_m68k_pte_maps & param_2);
          uVar4 = _pmap_pte(param_1,param_2);
          param_4 = uVar4;
          if (0 < (int)uVar4) {
            if (param_3 < uVar2) {
              param_4 = param_3 - param_2 >> (_m68k_page_shift & 0x3f);
              uVar5 = uVar4 + param_4 * 4;
            }
            else {
              param_4 = _pmap_pte(param_1,uVar2 - 1);
              uVar5 = param_4 + 4;
            }
            if (uVar4 < uVar5) {
              pbVar6 = (byte *)(uVar4 + 3);
              do {
                bVar3 = ((byte)uVar1 & 1) << 2 | *pbVar6 & 0xfb;
                param_4 = (uint)bVar3;
                *pbVar6 = bVar3;
                pbVar6 = pbVar6 + 4;
                uVar4 = uVar4 + 4;
              } while (uVar4 < uVar5);
            }
          }
          param_2 = uVar2;
        } while (uVar2 < param_3);
      }
      if (param_1 == _kernel_pmap) {
        param_4 = (uint)(byte)((param_1 < _kernel_pmap) << 4 |
                               ((int)(param_1 - _kernel_pmap) < 0) << 3 | 4U |
                               SBORROW4(param_1,_kernel_pmap) << 1 | param_1 < _kernel_pmap);
      }
    }
  }
  return param_4;
}
/* GHIDRADEC_FUNCTION index=2580 start=0x409827e */

void _pmap_enter(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5)

{
  _pmap_enter_mapping(param_1,param_2,param_3,param_4,param_5,1,0);
  return;
}
/* GHIDRADEC_FUNCTION index=2581 start=0x40982a6 */

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
/* GHIDRADEC_FUNCTION index=2582 start=0x409865e */

uint _pmap_change_wiring(uint param_1,undefined4 param_2,byte param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  byte bVar4;
  byte *pbVar5;
  byte *pbVar6;
  
  uVar2 = _pmap_pte_valid(param_1,param_2);
  if (param_1 == _kernel_pmap) {
    uVar3 = _pflush_super();
  }
  else {
    uVar3 = uVar2;
    if (_active_threads != 0) {
      uVar3 = _pflush_user();
    }
  }
  uVar3 = CONCAT31((int3)(uVar3 >> 8),*(byte *)(uVar2 + 3)) & 0xffffff03;
  if (((*(byte *)(uVar2 + 3) & 3) == 1) &&
     (uVar1 = uVar2 + _m68k_ptes_per_page * 4, uVar3 = _m68k_ptes_per_page, uVar2 < uVar1)) {
    uVar3 = CONCAT31((int3)(_m68k_ptes_per_page >> 8),param_3) & 0xffffff01;
    pbVar6 = (byte *)(uVar2 + 3);
    pbVar5 = (byte *)(uVar2 + 2);
    do {
      if (_cpu_type == '\0') {
        bVar4 = (param_3 & 1) << 5 | *pbVar6 & 0xdf;
        *pbVar6 = bVar4;
      }
      else {
        bVar4 = (param_3 & 1) << 3 | *pbVar5 & 0xf7;
        *pbVar5 = bVar4;
      }
      uVar3 = CONCAT31((int3)(uVar3 >> 8),bVar4);
      pbVar6 = pbVar6 + 4;
      pbVar5 = pbVar5 + 4;
      uVar2 = uVar2 + 4;
    } while (uVar2 < uVar1);
  }
  if (param_1 == _kernel_pmap) {
    uVar3 = (uint)(byte)((param_1 < _kernel_pmap) << 4 | ((int)(param_1 - _kernel_pmap) < 0) << 3 |
                         4U | SBORROW4(param_1,_kernel_pmap) << 1 | param_1 < _kernel_pmap);
  }
  return uVar3;
}
/* GHIDRADEC_FUNCTION index=2583 start=0x409871e */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint _pmap_extract(int param_1,uint param_2)

{
  byte bVar1;
  int iVar2;
  byte bVar3;
  uint *puVar4;
  uint uVar5;
  
  puVar4 = (uint *)_pmap_pte(param_1,param_2);
  if (((int)puVar4 < 0) || ((*puVar4 & 3) != 1)) {
    bVar3 = _m68k_kernel_mmu_030_tt._1_1_;
    bVar1 = _m68k_kernel_mmu_030_tt._0_1_;
    iVar2 = ram0x040b57b6;
    if (_cpu_type != '\0') {
      bVar3 = _m68k_kernel_mmu_040_tt._1_1_;
      bVar1 = _m68k_kernel_mmu_040_tt._0_1_;
      iVar2 = ram0x040b57be;
    }
    uVar5 = 0;
    if (((param_1 == _kernel_pmap) && (iVar2 < 0)) &&
       ((uint)bVar1 == (~(uint)bVar3 & param_2 >> 0x18))) {
      uVar5 = param_2;
    }
  }
  else {
    if (_cpu_type == '\0') {
      uVar5 = *puVar4 >> 8;
    }
    else {
      uVar5 = *puVar4 >> 0xc;
    }
    uVar5 = (_m68k_page_mask & param_2) + (uVar5 << (_m68k_pte_pfn & 0x3f));
  }
  return uVar5;
}
/* GHIDRADEC_FUNCTION index=2584 start=0x40987f8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint _pmap_resident_extract(int param_1,uint param_2)

{
  byte bVar1;
  int iVar2;
  byte bVar3;
  uint *puVar4;
  uint uVar5;
  
  puVar4 = (uint *)_pmap_pte(param_1,param_2);
  if (((int)puVar4 < 0) || ((*puVar4 & 3) != 1)) {
    bVar3 = _m68k_kernel_mmu_030_tt._1_1_;
    bVar1 = _m68k_kernel_mmu_030_tt._0_1_;
    iVar2 = ram0x040b57b6;
    if (_cpu_type != '\0') {
      bVar3 = _m68k_kernel_mmu_040_tt._1_1_;
      bVar1 = _m68k_kernel_mmu_040_tt._0_1_;
      iVar2 = ram0x040b57be;
    }
    uVar5 = 0;
    if (((param_1 == _kernel_pmap) && (iVar2 < 0)) &&
       ((uint)bVar1 == (~(uint)bVar3 & param_2 >> 0x18))) {
      uVar5 = param_2;
    }
  }
  else {
    if (_cpu_type == '\0') {
      uVar5 = *puVar4 >> 8;
    }
    else {
      uVar5 = *puVar4 >> 0xc;
    }
    uVar5 = (_m68k_page_mask & param_2) + (uVar5 << (_m68k_pte_pfn & 0x3f));
  }
  return uVar5;
}
/* GHIDRADEC_FUNCTION index=2585 start=0x40988b0 */

void _pmap_expand_kernel(uint param_1,int param_2)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  puVar1 = (uint *)(*(int *)(_kernel_pmap + 8) +
                   ((_m68k_pt1_mask & param_1) >> (_m68k_pt1_shift & 0x3f)) * 4);
  if (param_2 == -4) {
    uVar2 = 1 << (_m68k_pt1_l2ptr & 0x3f);
    iVar4 = (uVar2 + _avail_kernel_map + -1) / uVar2 << (_m68k_pt1_l2ptr & 0x3f);
    _avail_kernel_map = iVar4;
    _bzero(iVar4,_m68k_pt2_size);
    _avail_kernel_map = _m68k_pt2_size + _avail_kernel_map;
    *puVar1 = (iVar4 >> (_m68k_pt1_l2ptr & 0x3f)) << 9 | *puVar1 & 0x1ff;
    *(byte *)((int)puVar1 + 3) = (byte)*puVar1 & 0xfb | 8;
    *(byte *)((int)puVar1 + 3) = (byte)*puVar1 & 0xf8 | 8 | (byte)_m68k_pt1_desctype & 3;
  }
  else {
    iVar4 = (*puVar1 >> 9) << (_m68k_pt1_l2ptr & 0x3f);
  }
  uVar2 = 1 << (_m68k_pt2_l3ptr & 0x3f);
  iVar3 = (uVar2 + _avail_kernel_map + -1) / uVar2 << (_m68k_pt2_l3ptr & 0x3f);
  _avail_kernel_map = _m68k_pte_size + iVar3;
  if (_max_kernel_map < _avail_kernel_map) {
                    /* WARNING: Subroutine does not return */
    _panic(aNoMoreRoomInKe);
  }
  _bzero(iVar3,_m68k_pte_size);
  puVar1 = (uint *)(iVar4 + ((_m68k_pt2_mask & param_1) >> (_m68k_pt2_shift & 0x3f)) * 4);
  *puVar1 = (iVar3 >> (_m68k_pt2_l3ptr & 0x3f)) << 7 | *puVar1 & 0x7f;
  *(byte *)((int)puVar1 + 3) = (byte)*puVar1 & 0xfb | 8;
  *(byte *)((int)puVar1 + 3) = bRam040c97cf & 3 | (byte)*puVar1 & 0xf8 | 8;
  return;
}
/* GHIDRADEC_FUNCTION index=2586 start=0x4098a14 */

void _pmap_expand(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int unaff_A2;
  
  uVar4 = _m68k_pt1_mask & param_2;
  uVar1 = _m68k_pt1_shift & 0x3f;
  uVar5 = _m68k_pt2_mask & param_2;
  uVar2 = _m68k_pt2_shift & 0x3f;
  if (param_3 == -4) {
    unaff_A2 = sub_4096FD0(_pt_zone);
  }
  iVar6 = sub_4096FD0(_pte_zone);
  iVar7 = _pmap_pte(param_1,param_2);
  if (iVar7 < 1) {
    puVar3 = (uint *)(*(int *)(param_1 + 8) + (uVar4 >> uVar1) * 4);
    if (param_3 == -4) {
      *puVar3 = (unaff_A2 >> (_m68k_pt1_l2ptr & 0x3f)) << 9 | *puVar3 & 0x1ff;
      *(byte *)((int)puVar3 + 3) = (byte)*puVar3 & 0xfb | 8;
      *(byte *)((int)puVar3 + 3) = (byte)*puVar3 & 0xf8 | 8 | (byte)_m68k_pt1_desctype & 3;
    }
    else {
      unaff_A2 = (*puVar3 >> 9) << (_m68k_pt1_l2ptr & 0x3f);
    }
    puVar3 = (uint *)(unaff_A2 + (uVar5 >> uVar2) * 4);
    *puVar3 = (iVar6 >> (_m68k_pt2_l3ptr & 0x3f)) << 7 | *puVar3 & 0x7f;
    *(byte *)((int)puVar3 + 3) = (byte)*puVar3 & 0xfb | 8;
    *(byte *)((int)puVar3 + 3) = bRam040c97cf & 3 | (byte)*puVar3 & 0xf8 | 8;
  }
  else {
    if (param_3 == -4) {
      sub_40970C6(_pt_zone,unaff_A2);
    }
    sub_40970C6(_pte_zone,iVar6);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2587 start=0x4098b48 */

void _pmap_copy(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=2588 start=0x4098b50 */

void _pmap_update(void)

{
  _pflush_super();
  if (_active_threads != 0) {
    _pflush_user();
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2589 start=0x4098b6c */

void _pmap_collect(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (((param_1 != 0) && (param_1 != _kernel_pmap)) && (*(int *)(param_1 + 0x10) == 0)) {
    iVar2 = _m68k_pt1_elemsize * _m68k_pt1_entries;
    iVar1 = sub_4096FD0(_pt_zone);
    if (iVar1 != 0) {
      if (_active_threads != 0) {
        _pflush_user();
      }
      _pmap_remove_range(param_1,0,0xfffffffc);
      _bcopy(*(undefined4 *)(param_1 + 8),iVar1,iVar2);
      _bzero(*(undefined4 *)(param_1 + 8),iVar2);
      _pmap_free_maps(param_1,iVar1);
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2590 start=0x4098c08 */

undefined4 _pmap_kernel(void)

{
  return _kernel_pmap;
}
/* GHIDRADEC_FUNCTION index=2591 start=0x4098c16 */

void _pmap_pageable(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=2592 start=0x4098c1e */

undefined4 _pmap_attribute(void)

{
  return 4;
}
/* GHIDRADEC_FUNCTION index=2593 start=0x4098c28 */

byte _pmap_clear_modify(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  byte *pbVar4;
  int *piVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  
  iVar2 = _pmap_phys_to_index(param_1);
  bVar9 = false;
  bVar8 = SBORROW4(-1,iVar2);
  bVar6 = -1 - iVar2 < 0;
  bVar7 = iVar2 == -1;
  if (!bVar7) {
    piVar5 = (int *)(_pv_head_table + iVar2 * 0xc);
    do {
      iVar2 = piVar5[1];
      bVar6 = iVar2 < 0;
      bVar8 = false;
      bVar7 = true;
      if (iVar2 == 0) break;
      uVar3 = _pmap_pte_valid(iVar2,piVar5[2]);
      uVar1 = uVar3 + _m68k_ptes_per_page * 4;
      bVar9 = uVar1 < uVar3;
      if (uVar3 < uVar1) {
        pbVar4 = (byte *)(uVar3 + 3);
        do {
          *pbVar4 = *pbVar4 & 0xef;
          pbVar4 = pbVar4 + 4;
          uVar3 = uVar3 + 4;
          bVar9 = uVar1 < uVar3;
        } while (!bVar9 && uVar1 != uVar3);
      }
      piVar5 = (int *)*piVar5;
      bVar8 = false;
      bVar6 = (int)piVar5 < 0;
      bVar7 = piVar5 == (int *)0x0;
    } while (!bVar7);
  }
  return bVar9 << 4 | bVar6 << 3 | bVar7 << 2 | bVar8 << 1;
}
/* GHIDRADEC_FUNCTION index=2594 start=0x4098cac */

byte _pmap_clear_reference(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  byte *pbVar4;
  int *piVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  
  iVar2 = _pmap_phys_to_index(param_1);
  bVar9 = false;
  bVar8 = SBORROW4(-1,iVar2);
  bVar6 = -1 - iVar2 < 0;
  bVar7 = iVar2 == -1;
  if (!bVar7) {
    piVar5 = (int *)(_pv_head_table + iVar2 * 0xc);
    do {
      iVar2 = piVar5[1];
      bVar6 = iVar2 < 0;
      bVar8 = false;
      bVar7 = true;
      if (iVar2 == 0) break;
      uVar3 = _pmap_pte_valid(iVar2,piVar5[2]);
      uVar1 = uVar3 + _m68k_ptes_per_page * 4;
      bVar9 = uVar1 < uVar3;
      if (uVar3 < uVar1) {
        pbVar4 = (byte *)(uVar3 + 3);
        do {
          *pbVar4 = *pbVar4 & 0xf7;
          pbVar4 = pbVar4 + 4;
          uVar3 = uVar3 + 4;
          bVar9 = uVar1 < uVar3;
        } while (!bVar9 && uVar1 != uVar3);
      }
      piVar5 = (int *)*piVar5;
      bVar8 = false;
      bVar6 = (int)piVar5 < 0;
      bVar7 = piVar5 == (int *)0x0;
    } while (!bVar7);
  }
  return bVar9 << 4 | bVar6 << 3 | bVar7 << 2 | bVar8 << 1;
}
/* GHIDRADEC_FUNCTION index=2595 start=0x4098d30 */

int _pmap_is_referenced(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  
  iVar4 = 0;
  iVar2 = _pmap_phys_to_index(param_1);
  if (iVar2 != -1) {
    piVar5 = (int *)(_pv_head_table + iVar2 * 0xc);
    while (piVar5[1] != 0) {
      uVar3 = _pmap_pte_valid(piVar5[1],piVar5[2]);
      uVar1 = uVar3 + _m68k_ptes_per_page * 4;
      for (; (iVar4 == 0 && (uVar3 < uVar1)); uVar3 = uVar3 + 4) {
        if ((*(byte *)(uVar3 + 3) & 8) != 0) {
          iVar4 = 1;
        }
      }
      piVar5 = (int *)*piVar5;
      if (piVar5 == (int *)0x0) {
        return iVar4;
      }
      if (iVar4 != 0) {
        return iVar4;
      }
    }
  }
  return iVar4;
}
/* GHIDRADEC_FUNCTION index=2596 start=0x4098dbe */

int _pmap_is_modified(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  
  iVar4 = 0;
  iVar2 = _pmap_phys_to_index(param_1);
  if (iVar2 != -1) {
    piVar5 = (int *)(_pv_head_table + iVar2 * 0xc);
    while (piVar5[1] != 0) {
      uVar3 = _pmap_pte_valid(piVar5[1],piVar5[2]);
      uVar1 = uVar3 + _m68k_ptes_per_page * 4;
      for (; (iVar4 == 0 && (uVar3 < uVar1)); uVar3 = uVar3 + 4) {
        if ((*(byte *)(uVar3 + 3) & 0x10) != 0) {
          iVar4 = 1;
        }
      }
      piVar5 = (int *)*piVar5;
      if (piVar5 == (int *)0x0) {
        return iVar4;
      }
      if (iVar4 != 0) {
        return iVar4;
      }
    }
  }
  return iVar4;
}
/* GHIDRADEC_FUNCTION index=2597 start=0x4098e4c */

int _pmap_phys_to_index(uint param_1)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  undefined *in_A1;
  
  iVar3 = 0;
  iVar2 = 0;
  if (0 < _num_regions) {
    puVar1 = _mem_region;
    do {
      in_A1 = puVar1;
      if ((*(uint *)(in_A1 + 0x14) <= param_1) && (param_1 < *(uint *)(in_A1 + 0x18))) break;
      iVar3 = *(int *)(in_A1 + 0xc) + iVar3;
      iVar2 = iVar2 + 1;
      puVar1 = in_A1 + 0x1c;
    } while (iVar2 < _num_regions);
  }
  if (iVar2 == _num_regions) {
    iVar2 = -1;
  }
  else {
    iVar3 = iVar3 + ((param_1 >> (_page_shift & 0x3f)) - *(int *)(in_A1 + 4));
    iVar2 = -1;
    if (iVar3 < _managed_page_count) {
      iVar2 = iVar3;
    }
  }
  return iVar2;
}
/* GHIDRADEC_FUNCTION index=2598 start=0x4098ebc */

void _pmap_page_protect(undefined4 param_1,int param_2)

{
  if (param_2 == 5) {
loc_4098EE2:
    _pmap_copy_on_write(param_1);
  }
  else {
    if (param_2 < 6) {
      if (param_2 == 1) goto loc_4098EE2;
    }
    else if (param_2 == 7) {
      return;
    }
    _pmap_remove_all(param_1);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2599 start=0x4098efc */

void _pmap_copy_page(undefined4 param_1,undefined4 param_2)

{
  _bcopy(param_1,param_2,_page_size);
  return;
}

