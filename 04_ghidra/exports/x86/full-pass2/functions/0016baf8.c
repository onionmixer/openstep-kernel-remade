/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016baf8 */

kern_return_t
_host_zone_info(host_priv_t host,zone_name_array_t *names,mach_msg_type_number_t *namesCnt,
               zone_info_array_t *info,mach_msg_type_number_t *infoCnt)

{
  int iVar1;
  uint uVar2;
  kern_return_t kVar3;
  zone_info_array_t pzVar4;
  int iVar5;
  integer_t iVar6;
  int *piVar7;
  int *piVar8;
  int *piVar9;
  zone_name_array_t local_70;
  zone_info_array_t local_6c;
  uint local_68;
  uint local_60;
  uint local_58;
  zone_name_array_t local_54;
  int local_50 [2];
  integer_t local_48;
  vm_size_t local_3c;
  vm_size_t local_38;
  vm_size_t local_34;
  vm_size_t local_30;
  char *local_28;
  byte local_24;
  undefined *local_14;
  zone_info_array_t local_c;
  zone_name_array_t local_8;
  
  uVar2 = _num_zones;
  piVar7 = _first_zone;
  local_58 = 0;
  local_60 = 0;
  if (host == 0) {
    kVar3 = 0x16;
  }
  else {
    do {
    } while (_all_zones_lock != 0);
    LOCK();
    UNLOCK();
    LOCK();
    _all_zones_lock = 0;
    UNLOCK();
    if (*namesCnt < _num_zones) {
      local_58 = _num_zones * 0x50 + _page_mask & ~_page_mask;
      iVar5 = _kmem_alloc_pageable(_ipc_kernel_map,&local_8,local_58);
      if (iVar5 != 0) {
        return iVar5;
      }
      local_54 = local_8;
    }
    else {
      local_54 = *names;
    }
    if (*infoCnt < uVar2) {
      local_60 = _page_mask + uVar2 * 0x24 & ~_page_mask;
      iVar5 = _kmem_alloc_pageable(_ipc_kernel_map,&local_c,local_60);
      pzVar4 = local_c;
      if (iVar5 != 0) {
        if (*names == local_54) {
          return iVar5;
        }
        _kmem_free(_ipc_kernel_map,local_8,local_58);
        return iVar5;
      }
    }
    else {
      pzVar4 = *info;
    }
    local_68 = 0;
    if (uVar2 != 0) {
      local_70 = local_54;
      local_6c = pzVar4;
      do {
        if ((*(byte *)(piVar7 + 0xb) & 1) == 0) {
          iVar5 = _splhigh();
          do {
            do {
            } while (*piVar7 != 0);
            LOCK();
            iVar1 = *piVar7;
            *piVar7 = 1;
            UNLOCK();
          } while (iVar1 == 1);
          piVar7[1] = iVar5;
        }
        else {
          _lock_write(piVar7 + 0xc);
        }
        piVar8 = piVar7;
        piVar9 = local_50;
        for (iVar5 = 0x11; iVar5 != 0; iVar5 = iVar5 + -1) {
          *piVar9 = *piVar8;
          piVar8 = piVar8 + 1;
          piVar9 = piVar9 + 1;
        }
        if ((*(byte *)(piVar7 + 0xb) & 1) == 0) {
          LOCK();
          *piVar7 = 0;
          UNLOCK();
          _splx(piVar7[1]);
        }
        else {
          _lock_done(piVar7 + 0xc);
        }
        do {
        } while (_all_zones_lock != 0);
        LOCK();
        UNLOCK();
        piVar7 = (int *)piVar7[0x10];
        LOCK();
        _all_zones_lock = 0;
        UNLOCK();
        _strncpy(local_70->zn_name,local_28,0x50);
        local_6c->zi_count = local_48;
        local_6c->zi_cur_size = local_3c;
        local_6c->zi_max_size = local_38;
        local_6c->zi_elem_size = local_34;
        local_6c->zi_alloc_size = local_30;
        local_6c->zi_pageable = local_24 & 1;
        local_6c->zi_sleepable = local_24 >> 1 & 1;
        local_6c->zi_exhaustible = local_24 >> 2 & 1;
        iVar6 = 0;
        if ((local_14 != (undefined *)0x0) && (local_14 != &__zone_default_space)) {
          iVar6 = 1;
        }
        local_6c->zi_collectable = iVar6;
        local_6c = local_6c + 1;
        local_70 = local_70 + 1;
        local_68 = local_68 + 1;
      } while (local_68 < uVar2);
    }
    if (*names != local_54) {
      if (local_58 != uVar2 * 0x50) {
        _bzero(local_8 + uVar2,local_58 + uVar2 * -0x50);
      }
      _vm_move(_ipc_kernel_map,local_8,_ipc_soft_map,local_58,1,&local_8);
      *names = local_8;
    }
    *namesCnt = uVar2;
    if (*info != pzVar4) {
      if (local_60 != uVar2 * 0x24) {
        _bzero(local_c + uVar2,local_60 + uVar2 * -0x24);
      }
      _vm_move(_ipc_kernel_map,local_c,_ipc_soft_map,local_60,1,&local_c);
      *info = local_c;
    }
    *infoCnt = uVar2;
    kVar3 = 0;
  }
  return kVar3;
}

