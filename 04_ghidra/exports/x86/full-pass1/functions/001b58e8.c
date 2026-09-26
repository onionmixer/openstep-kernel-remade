/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b58e8 */

int FUN_001b58e8(int param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  undefined4 *puVar5;
  uint uVar6;
  char *pcVar7;
  undefined4 local_114;
  int local_110;
  undefined *local_10c;
  char local_108 [260];
  
  local_110 = param_1;
  local_10c = PTR_s_IODirectDevice_001fa478;
  iVar2 = _objc_msgSendSuper(&local_110,PTR_s_initFromDeviceDescription__001f9560,param_3);
  if ((iVar2 != 0) &&
     (iVar2 = _objc_msgSend(param_1,PTR_s_attachInterruptPort_001f9bd8), iVar2 == 0)) {
    uVar3 = _objc_msgSend(param_1,PTR_s_interruptPort_001f9b58,0x10);
    uVar3 = _task_self(uVar3);
    _port_set_backlog_EXTERNAL(uVar3);
    cVar1 = _objc_msgSend(param_1,PTR_s_reset_001f97d4);
    if (cVar1 != '\0') {
      _objc_msgSend(param_1,PTR_s__initAudioHardwareSettings_001f97d0);
      iVar2 = _objc_msgSend(param_3,PTR_s_configTable_001f9cdc);
      if (iVar2 == 0) {
        _IOLog("Audio: no configTable\n");
        return 0;
      }
      pcVar4 = (char *)_objc_msgSend(iVar2,PTR_s_valueForStringKey__001f9308,"Server Name");
      uVar6 = 0xffffffff;
      pcVar7 = "KernelServerInstance";
      do {
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        cVar1 = *pcVar7;
        pcVar7 = pcVar7 + 1;
      } while (cVar1 != '\0');
      _strncpy(local_108,pcVar4,0x101 - ~uVar6);
      _strcat(local_108,"KernelServerInstance");
      iVar2 = _objc_lookUpClass(local_108);
      if (iVar2 == 0) {
        _IOLog("Audio: no kernel server instance class \'%s\'\n",local_108);
        return 0;
      }
      iVar2 = _objc_msgSend(iVar2,PTR_s_kernelServerInstance_001f97cc);
      if (iVar2 == 0) {
        _IOLog("Audio: no kernel server instance\n");
        return 0;
      }
      _audioKernServInit(iVar2);
      _audio_makeIMuLawTab();
      uVar3 = _IOMalloc(0x1c);
      *(undefined4 *)(param_1 + 0x174) = uVar3;
      iVar2 = _objc_msgSend(PTR_s_IOAudio_001f9dbc,PTR_s__instance_001f97c8);
      if (iVar2 != 0) {
        _IOLog("Audio: replacing previously registered driver\n");
      }
      _objc_msgSend(PTR_s_IOAudio_001f9dbc,PTR_s__setInstance__001f97c4,param_1);
      uVar3 = _objc_msgSend(PTR_s_AudioChannel_001f9db8,PTR_s_alloc_001f9210,
                            PTR_s_initOnDevice_read__001f97c0,param_1,1);
      uVar3 = _objc_msgSend(uVar3);
      *(undefined4 *)(param_1 + 0x128) = uVar3;
      _objc_msgSend(PTR_s_IOAudio_001f9dbc,PTR_s__addChannel__001f97bc,uVar3);
      uVar3 = _objc_msgSend(PTR_s_AudioChannel_001f9db8,PTR_s_alloc_001f9210,
                            PTR_s_initOnDevice_read__001f97c0,param_1,0);
      uVar3 = _objc_msgSend(uVar3);
      *(undefined4 *)(param_1 + 300) = uVar3;
      _objc_msgSend(PTR_s_IOAudio_001f9dbc,PTR_s__addChannel__001f97bc,uVar3);
      _objc_msgSend(*(undefined4 *)(param_1 + 0x128),PTR_s_setLocalChannel__001f97b8,0);
      iVar2 = _objc_msgSend(param_3,PTR_s_numChannels_001f97b4);
      if (iVar2 == 1) {
        uVar3 = _objc_msgSend(param_3,PTR_s_interrupt_001f97ac);
        uVar3 = _objc_msgSend(param_3,PTR_s_channel_001f97b0,uVar3);
        uVar3 = _objc_msgSend(param_1,PTR_s_name_001f9228,uVar3);
        _IOLog("%s at dma channel %d irq %d\n",uVar3);
        _objc_msgSend(*(undefined4 *)(param_1 + 300),PTR_s_setLocalChannel__001f97b8,0);
      }
      else {
        iVar2 = _objc_msgSend(param_3,PTR_s_numChannels_001f97b4);
        if (iVar2 == 2) {
          puVar5 = (undefined4 *)_objc_msgSend(param_3,PTR_s_channelList_001f97a8);
          uVar3 = _objc_msgSend(param_3,PTR_s_interrupt_001f97ac);
          uVar3 = _objc_msgSend(param_1,PTR_s_name_001f9228,*puVar5,puVar5[1],uVar3);
          _IOLog("%s at dma channels %d and %d irq %d\n",uVar3);
          _objc_msgSend(*(undefined4 *)(param_1 + 300),PTR_s_setLocalChannel__001f97b8,1);
        }
      }
      uVar3 = _task_self(&local_114);
      iVar2 = _port_set_allocate_EXTERNAL(uVar3);
      if (iVar2 != 0) {
        _IOLog("Audio: port_set_allocate: %d\n",iVar2);
      }
      *(undefined4 *)(param_1 + 0x138) = local_114;
      uVar3 = _objc_msgSend(param_1,PTR_s_interruptPort_001f9b58);
      uVar3 = _task_self(*(undefined4 *)(param_1 + 0x138),uVar3);
      iVar2 = _port_set_add_EXTERNAL(uVar3);
      if (iVar2 != 0) {
        _IOLog("Audio: port_set_add\n");
      }
      uVar3 = _task_self(&local_114);
      iVar2 = _port_allocate_EXTERNAL(uVar3);
      if (iVar2 != 0) {
        _IOLog("Audio: port_allocate");
      }
      *(undefined4 *)(param_1 + 0x134) = local_114;
      uVar3 = _task_self(*(undefined4 *)(param_1 + 0x138),local_114);
      iVar2 = _port_set_add_EXTERNAL(uVar3);
      if (iVar2 != 0) {
        _IOLog("Audio: port_set_add\n");
      }
      uVar3 = _IOConvertPort(*(undefined4 *)(param_1 + 0x134),1,0);
      *(undefined4 *)(param_1 + 0x134) = uVar3;
      uVar3 = _objc_msgSend(PTR_s_AudioCommand_001f9db4,PTR_s_alloc_001f9210,
                            PTR_s_initPort__001f9b54,uVar3);
      uVar3 = _objc_msgSend(uVar3);
      *(undefined4 *)(param_1 + 0x130) = uVar3;
      _objc_msgSend(param_1,PTR_s__setTimeout__001f9874,0xffffffff);
      uVar3 = _IOForkThread(FUN_001b5d68,param_1);
      _IOSetThreadPolicy(uVar3,2);
      _IOSetThreadPriority(uVar3,0x1e);
      _IOForkThread(FUN_001b5eb0,param_1);
      _objc_msgSend(param_1,PTR_s_registerDevice_001f948c);
      return param_1;
    }
  }
  return 0;
}

