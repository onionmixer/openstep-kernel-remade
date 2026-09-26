
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _pmap_bootstrap(int param_1,int param_2,uint *param_3,undefined4 *param_4,int param_5)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined uStack_11;
  undefined uStack_d;
  int iStack_c;
  int iStack_8;
  
  sub_4096F96(_pt_zone,_m68k_pt1_size);
  sub_4096F96(_pte_zone,_m68k_pte_size);
  _m68k_protection_init();
  _m68k_ptes_per_page = _page_size >> (_m68k_page_shift & 0x3f);
  _kernel_pmap = _kernel_pmap_store;
  _lock_init(&_pmap_lock,0);
  if (_cpu_type == '\0') {
    uVar5 = 0x10;
  }
  else {
    uVar5 = _m68k_pt1_elemsize * _m68k_pt1_entries;
  }
  uVar5 = uVar5 * ((uVar5 + *(int *)(param_1 + 0x14) + -1) / uVar5);
  *(uint *)((int)_kernel_pmap + 8) = uVar5;
  iVar2 = _pmap_size(0);
  _avail_kernel_map = _m68k_pt1_size + uVar5;
  iVar4 = iVar2 + uVar5;
  _max_kernel_map = iVar4;
  *(int *)(param_1 + 0x14) = iVar4;
  puVar1 = (uint *)_kernel_pmap;
  *(uint *)((int)_kernel_pmap + 0xc) = 1;
  *(byte *)((int)puVar1 + 3) = (byte)*puVar1 & 0xfe | 2;
  puVar1 = (uint *)_kernel_pmap;
  *(uint *)_kernel_pmap =
       *(uint *)_kernel_pmap & 0x8000ffff | (_m68k_pt1_entries - 1U & 0x7fff) << 0x10;
  puVar1[1] = uVar5 & 0xfffffff0 | puVar1[1] & 0xf;
  _m68k_kernel_mmu_rp._4_4_ = puVar1[1];
  _m68k_kernel_mmu_rp._0_3_ = (undefined3)(*puVar1 >> 8);
  _m68k_kernel_mmu_rp._3_1_ = (undefined)*puVar1;
  _bzero(uVar5,iVar2);
  uVar5 = ~_page_mask & 0xf0fffff0;
  _pmap_map(uVar5,uVar5,~_page_mask & _page_mask + 0xf0fffff4,3,0,1);
  if (_cpu_type == '\0') {
    _m68k_kernel_mmu_030_tt._0_1_ = _slot_id._0_1_;
    _m68k_kernel_mmu_030_tt._1_1_ = 0xf;
    _m68k_kernel_mmu_030_tt._3_1_ = (byte)_m68k_kernel_mmu_030_tt & 0xcb | 0x43;
    _m68k_kernel_mmu_030_tt._2_1_ =
         -(_cache == 0) & 4U | _m68k_kernel_mmu_030_tt._2_1_ & 0xfb | 0x81;
  }
  else {
    _pmap_map(_slot_id,_slot_id,_slot_id + 0x20000,1,1,0);
    _pmap_map(_slot_id + 0x1000000,_slot_id + 0x1000000,_slot_id + 0x1020000,1,1,0);
    _pmap_map(_slot_id + 0x2000000,_slot_id + 0x2000000,_slot_id + 0x20c0040,3,0,1);
    _pmap_map(_slot_id + 0x2100000,_slot_id + 0x2100000,_slot_id + 0x211e000,3,0,1);
    switch(_machine_type) {
    case :
    case :
      uStack_11 = (undefined)((uint)(_slot_id + 0x4000000) >> 0x18);
      uStack_d = 3;
      _vidGetFBAddrAndSize(&iStack_8,&iStack_c);
      _pmap_map(iStack_8,iStack_8,iStack_c + iStack_8,3,0,1);
      break;
    case :
      uStack_11 = (undefined)((uint)(_slot_id + 0x4000000) >> 0x18);
      uStack_d = 0x2b;
      break;
    :
      uStack_11 = (undefined)((uint)(_slot_id + 0x4000000) >> 0x18);
      uStack_d = 3;
      _vidGetFBAddrAndSize(&iStack_8,&iStack_c);
      _pmap_map(_slot_id + 0x2200000,_slot_id + 0x2200000,_slot_id + 0x2209000,3,0,1);
      _pmap_map(_slot_id + 0x2210000,_slot_id + 0x2210000,_slot_id + 0x2210004,3,0,1);
      _pmap_map(_slot_id + 0x3e00000,_slot_id + 0x3e00000,_slot_id + 0x3e80000,3,0,0);
      _pmap_map(iStack_8,iStack_8,iStack_c + iStack_8,3,0,1);
      iVar2 = 0;
      if (0 < param_2) {
        iVar7 = 0;
        do {
          uVar5 = *(uint *)(param_1 + 0x14 + iVar7);
          if (_slot_id + 0x8000000U <= uVar5) {
            iVar3 = _pmap_size(*(int *)(param_1 + 0x18 + iVar7) - uVar5);
            _max_kernel_map = iVar3 + _max_kernel_map;
            iVar4 = iVar3 + iVar4;
            *(int *)(param_1 + 0x14) = iVar4;
            _pmap_map(uVar5,uVar5,*(undefined4 *)(param_1 + 0x18 + iVar7),3,1,0);
          }
          iVar7 = iVar7 + 0x1c;
          iVar2 = iVar2 + 1;
        } while (iVar2 < param_2);
      }
      _pmap_map(param_5,param_5,param_5 + 0xff4,3,0,1);
    }
    _m68k_kernel_mmu_040_tt._0_1_ = uStack_11;
    _m68k_kernel_mmu_040_tt._1_1_ = uStack_d;
    _m68k_kernel_mmu_040_tt._2_1_ = _m68k_kernel_mmu_040_tt._2_1_ & 0xbf | 0xa0;
    iVar4 = 3;
    if (_cache != 0) {
      iVar4 = 1;
    }
    ram0x040b57bf = ram0x040b57bf & 0x9fffffff | iVar4 << 0x1d;
  }
  *param_3 = 0x10000000;
  *param_4 = 0x14000000;
  _phys_map_vaddr1 = *param_3;
  _phys_map_vaddr2 = _page_size + *param_3;
  *param_3 = _phys_map_vaddr2;
  uVar5 = _page_size + *param_3;
  *param_3 = uVar5;
  uVar6 = _phys_map_vaddr1;
  if (_phys_map_vaddr1 < uVar5) {
    do {
      iVar4 = _pmap_pte(_kernel_pmap,uVar6);
      if (iVar4 < 0) {
        _pmap_expand_kernel(uVar6,iVar4);
      }
      uVar6 = _m68k_page_size + uVar6;
    } while (uVar6 < *param_3);
  }
  _phys_map_pte1 = _pmap_pte_valid(_kernel_pmap,_phys_map_vaddr1);
  _phys_map_pte2 = _pmap_pte_valid(_kernel_pmap,_phys_map_vaddr2);
  *param_3 = ~_page_mask & _page_mask + *param_3;
  return;
}

