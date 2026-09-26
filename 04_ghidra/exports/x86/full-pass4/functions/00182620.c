/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00182620 */

undefined4
_kern_IOMapDeviceMemory
          (int param_1,int param_2,uint param_3,int param_4,uint *param_5,char param_6,int param_7)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  undefined8 uVar9;
  undefined4 local_14;
  
  if (param_1 == 0) {
    uVar2 = 0xfffffd3f;
  }
  else {
    iVar1 = *(int *)(param_2 + 0xc);
    iVar5 = (int)param_6;
    if (param_7 == 0) {
      local_14 = 2;
    }
    else if (param_7 == 1) {
      local_14 = 1;
    }
    else {
      local_14 = 0;
    }
    uVar2 = _objc_msgSend(param_1,PTR_s_deviceDescription_001f9378);
    uVar2 = _objc_msgSend(uVar2,PTR_s_resourcesForKey__001f9344,s_Memory_Maps_001e10d5);
    iVar3 = _objc_msgSend(uVar2,PTR_s_count_001f92d8);
    iVar6 = 0;
    if (0 < iVar3) {
      do {
        uVar4 = _objc_msgSend(uVar2,PTR_s_objectAt__001f92e8,iVar6,PTR_s_range_001f9278);
        uVar9 = _objc_msgSend(uVar4);
        if (((uint)uVar9 <= param_3) &&
           (param_3 + param_4 <= (int)((ulonglong)uVar9 >> 0x20) + (uint)uVar9)) break;
        iVar6 = iVar6 + 1;
      } while (iVar6 < iVar3);
    }
    if (iVar3 == iVar6) {
      uVar2 = 0xfffffd3f;
    }
    else {
      if (iVar5 == 0) {
        *param_5 = *param_5 & ~_page_mask;
      }
      else {
        *param_5 = *(uint *)(iVar1 + 0x14);
      }
      if (((_kernel_map != iVar1) || (iVar5 != 0)) || (0xfffff < *param_5)) {
        iVar5 = _vm_map_find(iVar1,0,0,param_5,param_4,iVar5);
        if (iVar5 != 0) {
          return 0xfffffd25;
        }
        uVar7 = ~_page_mask & *param_5;
        uVar8 = ~_page_mask & _page_mask + param_4;
        _vm_map_inherit(iVar1,uVar7,uVar8 + uVar7,2);
        param_3 = param_3 & ~_page_mask;
        for (; uVar8 != 0; uVar8 = uVar8 - _page_size) {
          _pmap_enter_cache_spec(*(undefined4 *)(iVar1 + 0x24),uVar7,param_3,3,1,local_14);
          uVar7 = uVar7 + _page_size;
          param_3 = param_3 + _page_size;
        }
      }
      uVar2 = 0;
    }
  }
  return uVar2;
}

