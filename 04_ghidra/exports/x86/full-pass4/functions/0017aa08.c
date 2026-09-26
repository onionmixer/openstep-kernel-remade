/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017aa08 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _vm_page_startup(undefined4 *param_1,int param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  void *pvVar3;
  uint uVar4;
  byte bVar5;
  int *piVar6;
  byte *pbVar7;
  uint uVar8;
  undefined4 *local_20;
  uint *local_1c;
  uint local_c;
  uint local_8;
  
  _DAT_001f7454 = 0;
  _DAT_001f7458 = 0;
  _DAT_001f745c = 0;
  DAT_001f7460 = 1;
  DAT_001f7461 = DAT_001f7461 & 0xe2;
  DAT_001f745e = DAT_001f745e & 0xe0 | 0x20;
  _DAT_001f7464 = 0;
  _DAT_001f7468 = 0;
  _DAT_001f746c = 0;
  _vm_page_queue_free_lock = 0;
  _vm_page_queue_lock = 0;
  DAT_001f6e4c = &_vm_page_queue_free;
  _vm_page_queue_free = &_vm_page_queue_free;
  DAT_001f6e44 = &_vm_page_queue_active;
  _vm_page_queue_active = &_vm_page_queue_active;
  DAT_001f64e4 = &_vm_page_queue_inactive;
  _vm_page_queue_inactive = &_vm_page_queue_inactive;
  local_8 = 0;
  local_20 = param_1;
  if (param_1 < param_1 + param_2 * 7) {
    piVar6 = param_1 + 5;
    do {
      local_8 = local_8 + ((~_page_mask & piVar6[1]) - (*piVar6 + _page_mask & ~_page_mask));
      piVar6 = piVar6 + 7;
      local_20 = local_20 + 7;
    } while (local_20 < param_1 + param_2 * 7);
  }
  if (_vm_page_bucket_count == 0) {
    _vm_page_bucket_count = 1;
    local_8 = local_8 >> ((byte)_page_shift & 0x1f);
    if (1 < local_8) {
      do {
        _vm_page_bucket_count = _vm_page_bucket_count * 2;
      } while (_vm_page_bucket_count < local_8);
    }
  }
  __vm_page_hash_mask = _vm_page_bucket_count - 1;
  if ((_vm_page_bucket_count & __vm_page_hash_mask) != 0) {
    _printf(s_vm_page_bootstrap__WARNING____st_001e0d53);
  }
  _vm_page_buckets = (undefined4 *)_vm_alloc_from_regions(_vm_page_bucket_count * 8,4);
  _bzero(_vm_page_buckets,_vm_page_bucket_count * 8);
  uVar4 = _vm_page_bucket_count;
  uVar8 = 0;
  puVar2 = _vm_page_buckets;
  if (_vm_page_bucket_count != 0) {
    do {
      puVar2[1] = 0;
      *puVar2 = 0;
      uVar8 = uVar8 + 1;
      puVar2 = puVar2 + 2;
    } while (uVar8 < uVar4);
  }
  _zdata_size = _page_size * 8;
  __zdata = (void *)_vm_alloc_from_regions(_zdata_size,_page_size);
  _bzero(__zdata,_zdata_size);
  _map_data_size = 800;
  _map_data = (void *)_vm_alloc_from_regions(800,4);
  _bzero(_map_data,_map_data_size);
  _kentry_data_size = 0x16000;
  _kentry_data = (void *)_vm_alloc_from_regions(0x16000,4);
  _bzero(_kentry_data,_kentry_data_size);
  local_20 = param_1;
  if (param_1 < param_1 + param_2 * 7) {
    piVar6 = param_1 + 5;
    do {
      pvVar3 = (void *)_vm_alloc_from_regions
                                 (((piVar6[1] & ~_page_mask) - (_page_mask + *piVar6 & ~_page_mask)
                                  >> ((byte)_page_shift & 0x1f)) * 0x30,4);
      *local_20 = pvVar3;
      _bzero(pvVar3,((piVar6[1] & ~_page_mask) - (_page_mask + *piVar6 & ~_page_mask) >>
                    ((byte)_page_shift & 0x1f)) * 0x30);
      piVar6 = piVar6 + 7;
      local_20 = local_20 + 7;
    } while (local_20 < param_1 + param_2 * 7);
  }
  _vm_page_free_count = 0;
  local_20 = param_1;
  if (param_1 < param_1 + param_2 * 7) {
    local_1c = param_1 + 3;
    do {
      uVar4 = ~_page_mask;
      local_1c[2] = local_1c[2] + _page_mask & uVar4;
      local_1c[3] = local_1c[3] & uVar4;
      bVar5 = (byte)_page_shift;
      local_1c[-2] = local_1c[2] >> (bVar5 & 0x1f);
      uVar4 = local_1c[3] >> (bVar5 & 0x1f);
      local_1c[-1] = uVar4;
      uVar4 = uVar4 - local_1c[-2];
      *local_1c = uVar4;
      _vm_page_free_count = _vm_page_free_count + uVar4;
      puVar2 = (undefined4 *)*local_20;
      local_c = local_1c[2];
      uVar4 = 0;
      if (*local_1c != 0) {
        pbVar7 = (byte *)((int)puVar2 + 0x1e);
        do {
          *(uint *)(pbVar7 + 6) = local_c;
          puVar1 = puVar2;
          if ((undefined4 **)DAT_001f6e4c != &_vm_page_queue_free) {
            *DAT_001f6e4c = puVar2;
            puVar1 = _vm_page_queue_free;
          }
          _vm_page_queue_free = puVar1;
          *(undefined4 **)(pbVar7 + -0x1a) = DAT_001f6e4c;
          *puVar2 = &_vm_page_queue_free;
          DAT_001f6e4c = puVar2;
          *pbVar7 = *pbVar7 | 8;
          pbVar7 = pbVar7 + 0x30;
          puVar2 = puVar2 + 0xc;
          local_c = local_c + _page_size;
          uVar4 = uVar4 + 1;
        } while (uVar4 < *local_1c);
      }
      local_1c = local_1c + 7;
      local_20 = local_20 + 7;
    } while (local_20 < param_1 + param_2 * 7);
  }
  _vm_pages_needed_lock = 0;
  return param_3;
}

