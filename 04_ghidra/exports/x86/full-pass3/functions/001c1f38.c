/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c1f38 */

void FUN_001c1f38(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  uint uVar7;
  
  iVar2 = _objc_msgSend(*(undefined4 *)(param_1 + 0x114),PTR_s_resourcesForKey__001f9344,
                        "PCMCIA_DEVICE_ATTR_MAPPING");
  if (iVar2 != 0) {
    uVar3 = _objc_msgSend(*(undefined4 *)(param_1 + 0x114),PTR_s_resourcesForKey__001f9344,
                          "PCMCIA_WINDOW_LIST");
    uVar7 = 0;
    while( true ) {
      uVar4 = _objc_msgSend(uVar3,PTR_s_count_001f92d8);
      if (uVar4 <= uVar7) break;
      uVar5 = _objc_msgSend(uVar3,PTR_s_objectAt__001f92e8,uVar7);
      uVar6 = _objc_msgSend(uVar5,PTR_s_object_001f965c);
      cVar1 = _objc_msgSend(uVar6,PTR_s_memoryInterface_001f963c);
      if (cVar1 != '\0') {
        cVar1 = _objc_msgSend(uVar6,PTR_s_attributeMemory_001f9638);
        if (cVar1 != '\0') {
          _objc_msgSend(uVar6,PTR_s_setAttributeMemory__001f9648,0);
          _objc_msgSend(uVar6,PTR_s_setEnabled__001f9650,0);
          uVar6 = _objc_msgSend(uVar6,PTR_s_socket_001f9640,PTR_s_setMemoryInterface__001f964c,0);
          _objc_msgSend(uVar6);
          _objc_msgSend(uVar3,PTR_s_removeObject__001f92cc,uVar5);
          _objc_msgSend(uVar5,PTR_s_free_001f921c);
          break;
        }
      }
      uVar7 = uVar7 + 1;
    }
    _objc_msgSend(*(undefined4 *)(param_1 + 0x114),PTR_s_removeResourcesForKey__001f9634,
                  "PCMCIA_DEVICE_ATTR_MAPPING");
  }
  return;
}

