/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b8598 */

int FUN_001b8598(int param_1,undefined4 param_2,int param_3,int param_4,int param_5)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  
  if (param_3 == 1) {
    if ((param_4 == 0) && (param_5 == 0)) {
      *(undefined1 *)(param_1 + 0x24) = 0;
      _objc_msgSend(param_1,PTR_s_sendControlMessage_mask__001f9728,3,8);
      uVar3 = _objc_msgSend(param_1,PTR_s_channel_001f97b0);
      _objc_msgSend(*(undefined4 *)(param_1 + 8),PTR_s__dataPendingForChannel__001f9724,uVar3);
      return param_1;
    }
    *(int *)(param_1 + 0x4c) = param_4;
    *(int *)(param_1 + 0x50) = param_5;
    iVar5 = param_1 + 0x4c;
    puVar2 = (undefined4 *)_IOMalloc(0x28);
    if (*(int *)(param_1 + 0x3c) == 0) {
      uVar3 = _task_self((undefined4 *)(param_1 + 0x3c));
      iVar4 = _port_allocate_EXTERNAL(uVar3);
      if (iVar4 != 0) {
        _IOLog("Audio: stream control thread port_allocate: %s\n","MACH ERR");
        _IOLog("Audio Driver error");
      }
      if (DAT_001e53a8 == 0) {
        uVar3 = _objc_msgSend(PTR_s_NXLock_001f9da4,PTR_s_alloc_001f9210,PTR_s_init_001f924c);
        DAT_001e53a8 = _objc_msgSend(uVar3);
      }
      _objc_msgSend(DAT_001e53a8,PTR_s_lock_001f9220);
      DAT_001e53a4 = *(undefined4 *)(param_1 + 0x3c);
      uVar3 = _current_task_EXTERNAL(FUN_001b9160);
      _kernel_thread(uVar3);
    }
    puVar6 = &DAT_001d5e6c;
    puVar7 = puVar2;
    for (iVar4 = 10; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar7 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar7 = puVar7 + 1;
    }
    puVar2[4] = *(undefined4 *)(param_1 + 0x3c);
    puVar2[7] = param_1;
    puVar2[8] = 1;
  }
  else if (param_3 == 0) {
    if ((param_4 == 0) && (param_5 == 0)) {
      *(undefined1 *)(param_1 + 0x24) = 1;
      _objc_msgSend(param_1,PTR_s_sendControlMessage_mask__001f9728,2,4);
      return param_1;
    }
    *(int *)(param_1 + 0x44) = param_4;
    *(int *)(param_1 + 0x48) = param_5;
    iVar5 = param_1 + 0x44;
    puVar2 = (undefined4 *)_IOMalloc(0x28);
    if (*(int *)(param_1 + 0x38) == 0) {
      uVar3 = _task_self((undefined4 *)(param_1 + 0x38));
      iVar4 = _port_allocate_EXTERNAL(uVar3);
      if (iVar4 != 0) {
        _IOLog("Audio: stream control thread port_allocate: %s\n","MACH ERR");
        _IOLog("Audio Driver error");
      }
      if (DAT_001e53a8 == 0) {
        uVar3 = _objc_msgSend(PTR_s_NXLock_001f9da4,PTR_s_alloc_001f9210,PTR_s_init_001f924c);
        DAT_001e53a8 = _objc_msgSend(uVar3);
      }
      _objc_msgSend(DAT_001e53a8,PTR_s_lock_001f9220);
      DAT_001e53a4 = *(undefined4 *)(param_1 + 0x38);
      uVar3 = _current_task_EXTERNAL(FUN_001b9160);
      _kernel_thread(uVar3);
    }
    puVar6 = &DAT_001d5e6c;
    puVar7 = puVar2;
    for (iVar4 = 10; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar7 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar7 = puVar7 + 1;
    }
    puVar2[4] = *(undefined4 *)(param_1 + 0x38);
    puVar2[7] = param_1;
    puVar2[8] = 0;
  }
  else {
    if (param_3 != 2) {
      if (param_3 != 4) {
        _IOLog("audio: unrecognized stream control %d\n",param_3);
        return param_1;
      }
      _objc_msgSend(param_1,PTR_s_markAbortionsExclude__001f9720,1);
      return param_1;
    }
    if ((param_4 == 0) && (param_5 == 0)) {
      cVar1 = _objc_msgSend(param_1,PTR_s_markAbortionsExclude__001f9720,0);
      if (cVar1 != '\0') {
        return param_1;
      }
      _objc_msgSend(param_1,PTR_s_sendControlMessage_mask__001f9728,4,0x10);
      return param_1;
    }
    *(int *)(param_1 + 0x54) = param_4;
    *(int *)(param_1 + 0x58) = param_5;
    iVar5 = param_1 + 0x54;
    puVar2 = (undefined4 *)_IOMalloc(0x28);
    if (*(int *)(param_1 + 0x40) == 0) {
      uVar3 = _task_self((undefined4 *)(param_1 + 0x40));
      iVar4 = _port_allocate_EXTERNAL(uVar3);
      if (iVar4 != 0) {
        _IOLog("Audio: stream control thread port_allocate: %s\n","MACH ERR");
        _IOLog("Audio Driver error");
      }
      if (DAT_001e53a8 == 0) {
        uVar3 = _objc_msgSend(PTR_s_NXLock_001f9da4,PTR_s_alloc_001f9210,PTR_s_init_001f924c);
        DAT_001e53a8 = _objc_msgSend(uVar3);
      }
      _objc_msgSend(DAT_001e53a8,PTR_s_lock_001f9220);
      DAT_001e53a4 = *(undefined4 *)(param_1 + 0x40);
      uVar3 = _current_task_EXTERNAL(FUN_001b9160);
      _kernel_thread(uVar3);
    }
    puVar6 = &DAT_001d5e6c;
    puVar7 = puVar2;
    for (iVar4 = 10; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar7 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar7 = puVar7 + 1;
    }
    puVar2[4] = *(undefined4 *)(param_1 + 0x40);
    puVar2[7] = param_1;
    puVar2[8] = 2;
  }
  puVar2[9] = iVar5;
  _msg_send(puVar2,1,1000);
  return param_1;
}

