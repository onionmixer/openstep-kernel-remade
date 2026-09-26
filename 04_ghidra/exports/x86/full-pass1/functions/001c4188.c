/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c4188 */

undefined4
FUN_001c4188(int param_1,undefined4 param_2,undefined4 *param_3,char *param_4,int param_5)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  bool bVar7;
  int local_c;
  undefined *local_8;
  
  iVar3 = 0x15;
  bVar7 = true;
  pcVar5 = param_4;
  pcVar6 = "IO_Framebuffer_Unmap";
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    bVar7 = *pcVar5 == *pcVar6;
    pcVar5 = pcVar5 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar7);
  if (bVar7) {
    _objc_msgSend(param_1,PTR_s_revertToVGAMode_001f94a8);
    return 0;
  }
  iVar3 = 0x1a;
  bVar7 = true;
  pcVar5 = param_4;
  pcVar6 = "IO_Framebuffer_Unregister";
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    bVar7 = *pcVar5 == *pcVar6;
    pcVar5 = pcVar5 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar7);
  if (bVar7) {
    if (param_5 == 1) {
      uVar2 = _objc_msgSend(PTR_s_EventDriver_001f9dc8,PTR_s_instance_001f9964,
                            PTR_s_unregisterScreen__001f9618,*param_3);
      _objc_msgSend(uVar2);
      return 0;
    }
  }
  else {
    iVar3 = 0x13;
    bVar7 = true;
    pcVar5 = param_4;
    pcVar6 = "IOSetTransferTable";
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar7 = *pcVar5 == *pcVar6;
      pcVar5 = pcVar5 + 1;
      pcVar6 = pcVar6 + 1;
    } while (bVar7);
    if (bVar7) {
      iVar3 = _objc_msgSend(param_1,PTR_s_displayInfo_001f9610);
      switch(*(undefined4 *)(iVar3 + 0x18)) {
      case 0:
        if (param_5 == 4) {
LAB_001c4289:
          _objc_msgSend(param_1,PTR_s_setTransferTable_count__001f95ec,param_3,param_5);
          return 0;
        }
        break;
      case 1:
      case 4:
        if (param_5 == 0x100) goto LAB_001c4289;
        break;
      case 2:
        if (param_5 == 0x10) goto LAB_001c4289;
        break;
      case 3:
        if (param_5 == 0x20) goto LAB_001c4289;
      }
    }
    else {
      iVar3 = 0x15;
      bVar7 = true;
      pcVar5 = param_4;
      pcVar6 = "IO_BM256_to_BM38_map";
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar7 = *pcVar5 == *pcVar6;
        pcVar5 = pcVar5 + 1;
        pcVar6 = pcVar6 + 1;
      } while (bVar7);
      if (bVar7) {
        if (param_5 == 0x100) {
          if (*(int *)(param_1 + 0x208) == 0) {
            uVar2 = _IOMalloc(0x400);
            *(undefined4 *)(param_1 + 0x208) = uVar2;
          }
          uVar4 = 0;
          do {
            *(undefined4 *)(*(int *)(param_1 + 0x208) + uVar4 * 4) = param_3[uVar4];
            uVar4 = uVar4 + 1;
          } while (uVar4 < 0x100);
          return 0;
        }
      }
      else {
        iVar3 = 0x15;
        bVar7 = true;
        pcVar5 = param_4;
        pcVar6 = "IO_BM38_to_BM256_map";
        do {
          if (iVar3 == 0) break;
          iVar3 = iVar3 + -1;
          bVar7 = *pcVar5 == *pcVar6;
          pcVar5 = pcVar5 + 1;
          pcVar6 = pcVar6 + 1;
        } while (bVar7);
        if (bVar7) {
          if (param_5 == 0x100) {
            if (*(int *)(param_1 + 0x20c) == 0) {
              uVar2 = _IOMalloc(0x400);
              *(undefined4 *)(param_1 + 0x20c) = uVar2;
            }
            uVar4 = 0;
            do {
              *(undefined4 *)(*(int *)(param_1 + 0x20c) + uVar4 * 4) = param_3[uVar4];
              uVar4 = uVar4 + 1;
            } while (uVar4 < 0x100);
            return 0;
          }
        }
        else {
          iVar3 = 0x1b;
          bVar7 = true;
          pcVar5 = param_4;
          pcVar6 = "IOSelectPendingDisplayMode";
          do {
            if (iVar3 == 0) break;
            iVar3 = iVar3 + -1;
            bVar7 = *pcVar5 == *pcVar6;
            pcVar5 = pcVar5 + 1;
            pcVar6 = pcVar6 + 1;
          } while (bVar7);
          if (!bVar7) {
            local_c = param_1;
            local_8 = PTR_s_IODisplay_001fa608;
            uVar2 = _objc_msgSendSuper(&local_c,PTR_s_setIntValues_forParameter_count__001f94bc,
                                       param_3,param_4,param_5);
            return uVar2;
          }
          if (param_5 == 1) {
            cVar1 = _objc_msgSend(param_1,PTR_s_setPendingDisplayMode__001f95e8,*param_3);
            if (cVar1 == '\x01') {
              return 0;
            }
            return 0xfffffd11;
          }
        }
      }
    }
  }
  return 0xfffffd3e;
}

