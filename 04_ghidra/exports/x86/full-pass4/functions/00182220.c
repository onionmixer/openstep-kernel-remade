/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00182220 */

undefined4
_kern_dev_map_phys(undefined4 param_1,int param_2,uint param_3,int param_4,uint *param_5,int param_6
                  ,int param_7)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined8 uVar7;
  undefined4 local_c;
  
  if (param_7 == 0) {
    local_c = 2;
  }
  else if (param_7 == 1) {
    local_c = 1;
  }
  else {
    local_c = 0;
  }
  uVar1 = _objc_msgSend(param_1,PTR_s_deviceDescription_001f9378);
  uVar1 = _objc_msgSend(uVar1,PTR_s_resourcesForKey__001f9344,s_Memory_Maps_001e10d5);
  iVar2 = _objc_msgSend(uVar1,PTR_s_count_001f92d8);
  iVar4 = 0;
  if (0 < iVar2) {
    do {
      uVar3 = _objc_msgSend(uVar1,PTR_s_objectAt__001f92e8,iVar4,PTR_s_range_001f9278);
      uVar7 = _objc_msgSend(uVar3);
      if (((uint)uVar7 <= param_3) &&
         (param_3 + param_4 <= (int)((ulonglong)uVar7 >> 0x20) + (uint)uVar7)) break;
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar2);
  }
  if (iVar2 == iVar4) {
    uVar1 = 0xfffffd3f;
  }
  else {
    if (param_6 == 0) {
      *param_5 = *param_5 & ~_page_mask;
    }
    else {
      *param_5 = *(uint *)(param_2 + 0x14);
    }
    if (((_kernel_map != param_2) || (param_6 != 0)) || (0xfffff < *param_5)) {
      iVar2 = _vm_map_find(param_2,0,0,param_5,param_4,param_6);
      if (iVar2 != 0) {
        return 0xfffffd25;
      }
      uVar5 = ~_page_mask & *param_5;
      uVar6 = ~_page_mask & _page_mask + param_4;
      _vm_map_inherit(param_2,uVar5,uVar6 + uVar5,2);
      param_3 = param_3 & ~_page_mask;
      for (; uVar6 != 0; uVar6 = uVar6 - _page_size) {
        _pmap_enter_cache_spec(*(undefined4 *)(param_2 + 0x24),uVar5,param_3,3,1,local_c);
        uVar5 = uVar5 + _page_size;
        param_3 = param_3 + _page_size;
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}

