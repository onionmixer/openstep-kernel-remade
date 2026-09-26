/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c1cb8 */

undefined4 FUN_001c1cb8(int param_1,undefined4 param_2,undefined4 *param_3,char param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined8 uVar6;
  
  uVar1 = _objc_msgSend(PTR_s_KernBus_001f9d8c,PTR_s_lookupBusInstanceWithName_busId__001f9310,
                        "PCMCIA",0);
  iVar2 = _objc_msgSend(*(undefined4 *)(param_1 + 0x114),PTR_s_resourcesForKey__001f9344,
                        "PCMCIA_DEVICE_ATTR_MAPPING");
  if (iVar2 == 0) {
    uVar3 = _objc_msgSend(*(undefined4 *)(param_1 + 0x114),PTR_s_resourcesForKey__001f9344,
                          "PCMCIA_SOCKET_LIST",PTR_s_objectAt__001f92e8,0);
    iVar2 = _objc_msgSend(uVar3);
    if (iVar2 != 0) {
      uVar3 = _objc_msgSend(iVar2,PTR_s_object_001f965c);
      iVar2 = _objc_msgSend(uVar1,PTR_s_allocMemoryWindowForSocket__001f9658,uVar3);
      if (iVar2 != 0) {
        uVar3 = _objc_msgSend(*(undefined4 *)(param_1 + 0x114),PTR_s_resourcesForKey__001f9344,
                              "PCMCIA_WINDOW_LIST");
        uVar1 = _objc_msgSend(uVar1,PTR_s_memoryRangeResource_001f9654);
        if (param_4 == '\0') {
          uVar4 = _current_task_EXTERNAL(0);
          iVar5 = _objc_msgSend(uVar1,PTR_s_mapToAddress_inTarget_cache__001f9ba0,*param_3,uVar4);
        }
        else {
          uVar4 = _current_task_EXTERNAL(0);
          iVar5 = _objc_msgSend(uVar1,PTR_s_mapInTarget_cache__001f9ba4,uVar4);
        }
        if (iVar5 == 0) {
          _objc_msgSend(iVar2,PTR_s_free_001f921c);
          return 0xfffffd43;
        }
        uVar4 = _objc_msgSend(iVar5,PTR_s_address_001f9b9c);
        *param_3 = uVar4;
        uVar4 = _objc_msgSend(PTR_s_List_001f9d80,PTR_s_alloc_001f9210,PTR_s_initCount__001f92dc,1);
        uVar4 = _objc_msgSend(uVar4);
        _objc_msgSend(uVar4,PTR_s_addObject__001f92c4,iVar5);
        _objc_msgSend(*(undefined4 *)(param_1 + 0x114),PTR_s_setResources_forKey__001f9338,uVar4,
                      "PCMCIA_DEVICE_ATTR_MAPPING");
        uVar4 = _objc_msgSend(iVar2,PTR_s_object_001f965c);
        uVar6 = _objc_msgSend(uVar1,PTR_s_range_001f9278);
        _objc_msgSend(uVar4,PTR_s_setEnabled__001f9650,0);
        _objc_msgSend(uVar4,PTR_s_setMemoryInterface__001f964c,1);
        _objc_msgSend(uVar4,PTR_s_setAttributeMemory__001f9648,1);
        _objc_msgSend(uVar4,PTR_s_setMapWithSize_systemAddress_car_001f9644,
                      (int)((ulonglong)uVar6 >> 0x20),(int)uVar6,0);
        _objc_msgSend(uVar4,PTR_s_setEnabled__001f9650,1);
        uVar1 = _objc_msgSend(uVar4,PTR_s_socket_001f9640,PTR_s_setMemoryInterface__001f964c,1);
        _objc_msgSend(uVar1);
        _objc_msgSend(uVar3,PTR_s_addObject__001f92c4,iVar2);
        return 0;
      }
    }
    uVar1 = 0xfffffd42;
  }
  else {
    uVar1 = 0xfffffd2b;
  }
  return uVar1;
}

