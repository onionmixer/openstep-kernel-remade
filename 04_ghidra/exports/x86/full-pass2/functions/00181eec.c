/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00181eec */

undefined4
_kern_IOGetEISADeviceConfig
          (int param_1,int param_2,int *param_3,int param_4,int *param_5,int param_6,int *param_7,
          int param_8,int *param_9)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined8 uVar6;
  
  if (param_1 == 0) {
    uVar1 = 0xfffffd3f;
  }
  else {
    uVar1 = _objc_msgSend(param_1,PTR_s_deviceDescription_001f9378);
    uVar2 = _objc_msgSend(uVar1,PTR_s_resourcesForKey__001f9344,s_IRQ_Levels_001e109d);
    iVar3 = _objc_msgSend(uVar2,PTR_s_count_001f92d8);
    if (7 < iVar3) {
      iVar3 = 7;
    }
    iVar5 = 0;
    if (0 < iVar3) {
      do {
        uVar4 = _objc_msgSend(uVar2,PTR_s_objectAt__001f92e8,iVar5,PTR_s_item_001f933c);
        uVar4 = _objc_msgSend(uVar4);
        *(undefined4 *)(param_2 + iVar5 * 4) = uVar4;
        iVar5 = iVar5 + 1;
      } while (iVar5 < iVar3);
    }
    *param_3 = iVar3;
    uVar2 = _objc_msgSend(uVar1,PTR_s_resourcesForKey__001f9344,s_DMA_Channels_001e10a8);
    iVar3 = _objc_msgSend(uVar2,PTR_s_count_001f92d8);
    if (4 < iVar3) {
      iVar3 = 4;
    }
    iVar5 = 0;
    if (0 < iVar3) {
      do {
        uVar4 = _objc_msgSend(uVar2,PTR_s_objectAt__001f92e8,iVar5,PTR_s_item_001f933c);
        uVar4 = _objc_msgSend(uVar4);
        *(undefined4 *)(param_4 + iVar5 * 4) = uVar4;
        iVar5 = iVar5 + 1;
      } while (iVar5 < iVar3);
    }
    *param_5 = iVar3;
    uVar2 = _objc_msgSend(uVar1,PTR_s_resourcesForKey__001f9344,s_I_O_Ports_001e10b5);
    iVar3 = _objc_msgSend(uVar2,PTR_s_count_001f92d8);
    if (0x14 < iVar3) {
      iVar3 = 0x14;
    }
    iVar5 = 0;
    if (0 < iVar3) {
      do {
        uVar4 = _objc_msgSend(uVar2,PTR_s_objectAt__001f92e8,iVar5,PTR_s_range_001f9278);
        uVar6 = _objc_msgSend(uVar4);
        *(int *)(param_6 + iVar5 * 8) = (int)uVar6;
        *(int *)(param_6 + 4 + iVar5 * 8) = (int)((ulonglong)uVar6 >> 0x20);
        iVar5 = iVar5 + 1;
      } while (iVar5 < iVar3);
    }
    *param_7 = iVar3;
    uVar1 = _objc_msgSend(uVar1,PTR_s_resourcesForKey__001f9344,s_Memory_Maps_001e10bf);
    iVar3 = _objc_msgSend(uVar1,PTR_s_count_001f92d8);
    if (9 < iVar3) {
      iVar3 = 9;
    }
    iVar5 = 0;
    if (0 < iVar3) {
      do {
        uVar2 = _objc_msgSend(uVar1,PTR_s_objectAt__001f92e8,iVar5,PTR_s_range_001f9278);
        uVar6 = _objc_msgSend(uVar2);
        *(int *)(param_8 + iVar5 * 8) = (int)uVar6;
        *(int *)(param_8 + 4 + iVar5 * 8) = (int)((ulonglong)uVar6 >> 0x20);
        iVar5 = iVar5 + 1;
      } while (iVar5 < iVar3);
    }
    *param_9 = iVar3;
    uVar1 = 0;
  }
  return uVar1;
}

