
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _vm_page_startup(undefined4 *param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  uint uVar2;
  uint *puVar3;
  uint *puVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  uint *puVar8;
  byte *pbVar9;
  int *piVar10;
  uint *puStack_8;
  
  dword_40C32A4 = 0;
  dword_40C32A8 = 0;
  dword_40C32AC._0_2_ = 0;
  dword_40C32B0._0_1_ = 0x80;
  dword_40C32B0._1_1_ = dword_40C32B0._1_1_ & 0x47;
  dword_40C32AC._2_1_ = dword_40C32AC._2_1_ & 7 | 4;
  ram0x040c32b2 = 0;
  uRam040c32b6 = 0;
  uRam040c32ba = 0;
  dword_40C2C1C = &_vm_page_queue_free;
  _vm_page_queue_free = &_vm_page_queue_free;
  dword_40C2C14 = &_vm_page_queue_active;
  _vm_page_queue_active = &_vm_page_queue_active;
  dword_40C23DC = &_vm_page_queue_inactive;
  _vm_page_queue_inactive = &_vm_page_queue_inactive;
  uVar5 = 0;
  if (param_1 < param_1 + param_2 * 7) {
    puVar6 = param_1;
    do {
      uVar5 = ((~_page_mask & puVar6[6]) - (~_page_mask & _page_mask + puVar6[5])) + uVar5;
      puVar6 = puVar6 + 7;
    } while (puVar6 < param_1 + param_2 * 7);
  }
  if (_vm_page_bucket_count == 0) {
    _vm_page_bucket_count = 1;
    uVar5 = uVar5 >> (_page_shift & 0x3f);
    if (1 < uVar5) {
      do {
        _vm_page_bucket_count = _vm_page_bucket_count * 2;
      } while (_vm_page_bucket_count < uVar5);
    }
  }
  _vm_page_hash_mask = _vm_page_bucket_count - 1;
  if ((_vm_page_bucket_count & _vm_page_hash_mask) != 0) {
    _printf(aVmPageBootstra);
  }
  _vm_page_buckets = (undefined4 *)_vm_alloc_from_regions(_vm_page_bucket_count << 2,2);
  _bzero(_vm_page_buckets,_vm_page_bucket_count << 2);
  uVar2 = _vm_page_bucket_count;
  uVar5 = 0;
  puVar6 = _vm_page_buckets;
  if (_vm_page_bucket_count != 0) {
    do {
      *puVar6 = 0;
      uVar5 = uVar5 + 1;
      puVar6 = puVar6 + 1;
    } while (uVar5 < uVar2);
  }
  _zdata_size = _page_size << 3;
  _zdata = _vm_alloc_from_regions(_zdata_size,_page_size);
  _bzero(_zdata,_zdata_size);
  _map_data_size = 0x2a8;
  _map_data = _vm_alloc_from_regions(0x2a8,2);
  _bzero(_map_data,_map_data_size);
  _kentry_data_size = 0x15000;
  _kentry_data = _vm_alloc_from_regions(0x15000,2);
  _bzero(_kentry_data,_kentry_data_size);
  if (param_1 < param_1 + param_2 * 7) {
    piVar10 = param_1 + 5;
    puVar8 = param_1 + 6;
    puVar6 = param_1;
    do {
      uVar1 = _vm_alloc_from_regions
                        (((~_page_mask & *puVar8) - (~_page_mask & *piVar10 + _page_mask) >>
                         (_page_shift & 0x3f)) * 0x2e,2);
      *puVar6 = uVar1;
      _bzero(uVar1,((~_page_mask & *puVar8) - (~_page_mask & *piVar10 + _page_mask) >>
                   (_page_shift & 0x3f)) * 0x2e);
      piVar10 = piVar10 + 7;
      puVar8 = puVar8 + 7;
      puVar6 = puVar6 + 7;
    } while (puVar6 < param_1 + param_2 * 7);
  }
  _vm_page_free_count = 0;
  if (param_1 < param_1 + param_2 * 7) {
    puStack_8 = param_1 + 3;
    puVar8 = param_1 + 5;
    puVar4 = param_1 + 1;
    puVar3 = param_1 + 6;
    puVar6 = param_1;
    do {
      uVar5 = ~_page_mask;
      *puVar8 = uVar5 & _page_mask + *puVar8;
      *puVar3 = uVar5 & *puVar3;
      uVar5 = _page_shift;
      *puVar4 = *puVar8 >> (_page_shift & 0x3f);
      uVar5 = *puVar3 >> (uVar5 & 0x3f);
      puVar6[2] = uVar5;
      uVar5 = uVar5 - *puVar4;
      *puStack_8 = uVar5;
      _vm_page_free_count = uVar5 + _vm_page_free_count;
      puVar7 = (undefined4 *)*puVar6;
      uVar5 = *puVar8;
      uVar2 = 0;
      if (*puStack_8 != 0) {
        pbVar9 = (byte *)((int)puVar7 + 0x1e);
        do {
          *(uint *)((int)puVar7 + 0x22) = uVar5;
          *dword_40C2C1C = puVar7;
          puVar7[1] = dword_40C2C1C;
          *puVar7 = &_vm_page_queue_free;
          dword_40C2C1C = puVar7;
          *pbVar9 = *pbVar9 | 0x10;
          pbVar9 = pbVar9 + 0x2e;
          puVar7 = (undefined4 *)((int)puVar7 + 0x2e);
          uVar5 = _page_size + uVar5;
          uVar2 = uVar2 + 1;
        } while (uVar2 < *puStack_8);
      }
      puStack_8 = puStack_8 + 7;
      puVar8 = puVar8 + 7;
      puVar4 = puVar4 + 7;
      puVar3 = puVar3 + 7;
      puVar6 = puVar6 + 7;
    } while (puVar6 < param_1 + param_2 * 7);
  }
  return param_3;
}
