/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001bae88 */

undefined4 FUN_001bae88(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int local_8;
  
  iVar1 = _objc_msgSend(PTR_s_IOAudio_001f9dbc,PTR_s__instance_001f97c8);
  *(undefined1 *)(param_2 + 3) = 1;
  *(undefined4 *)(param_2 + 4) = 0x18;
  *(undefined4 *)(param_2 + 8) = 0;
  *(undefined4 *)(param_2 + 0xc) = 0;
  *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(param_2 + 0x14) = 0;
  if (*(int *)(param_1 + 0x14) == 0) {
    if (iVar1 == 0) {
      uVar2 = 1;
    }
    else {
      if (DAT_001e53b8 == 0) {
        _kern_serv_port_death_proc(DAT_001e8718,_audio_port_gone);
        uVar2 = _task_self(&local_8);
        iVar3 = _port_allocate_EXTERNAL(uVar2);
        if (iVar3 != 0) {
          _IOLog("Audio: port_allocate");
        }
        _outPort = local_8;
        iVar3 = _kern_serv_port_serv(DAT_001e8718,local_8,_audioMessages,local_8);
        if (iVar3 != 0) {
          _IOLog("Audio: createAudioPorts error %d\n",iVar3);
        }
        uVar2 = _task_self(&local_8);
        iVar3 = _port_allocate_EXTERNAL(uVar2);
        if (iVar3 != 0) {
          _IOLog("Audio: port_allocate");
        }
        _inPort = local_8;
        iVar3 = _kern_serv_port_serv(DAT_001e8718,local_8,_audioMessages,local_8);
        if (iVar3 != 0) {
          _IOLog("Audio: createAudioPorts error %d\n",iVar3);
        }
        uVar2 = _task_self(&local_8);
        iVar3 = _port_allocate_EXTERNAL(uVar2);
        if (iVar3 != 0) {
          _IOLog("Audio: port_allocate");
        }
        _sndPort = local_8;
        iVar3 = _kern_serv_port_serv(DAT_001e8718,local_8,_audioMessages,local_8);
        if (iVar3 != 0) {
          _IOLog("Audio: createAudioPorts error %d\n",iVar3);
        }
        DAT_001e53b8 = 1;
      }
      *(undefined1 *)(param_2 + 3) = 0;
      *(undefined4 *)(param_2 + 4) = 0x28;
      *(undefined4 *)(param_2 + 0x14) = 1;
      *(undefined1 *)(param_2 + 0x18) = 6;
      *(undefined1 *)(param_2 + 0x19) = 0x20;
      *(short *)(param_2 + 0x1a) =
           (short)CONCAT31((uint3)((byte)((ushort)*(undefined2 *)(param_2 + 0x1a) >> 8) & 0xf0),3);
      *(byte *)(param_2 + 0x1b) = *(byte *)(param_2 + 0x1b) & 0x1f | 0x10;
      iVar3 = _IOHostPrivSelf();
      if (iVar3 == 0) {
        _IOLog("Audio: cannot get kernel port (must run as root)\n");
        uVar2 = 1;
      }
      else {
        if (*(int *)(param_1 + 0x1c) == iVar3) {
          if (*(int *)(param_1 + 0x24) != 0) {
            if (_inPort != 0) {
              _kern_serv_port_gone(DAT_001e8718,_inPort);
              uVar2 = _task_self(_inPort);
              iVar3 = _port_deallocate_EXTERNAL(uVar2);
              if (iVar3 != 0) {
                _IOLog("Audio: port_deallocate\n");
              }
            }
            if (_outPort != 0) {
              _kern_serv_port_gone(DAT_001e8718,_outPort);
              uVar2 = _task_self(_outPort);
              iVar3 = _port_deallocate_EXTERNAL(uVar2);
              if (iVar3 != 0) {
                _IOLog("Audio: port_deallocate\n");
              }
            }
            if (_sndPort != 0) {
              _kern_serv_port_gone(DAT_001e8718,_sndPort);
              uVar2 = _task_self(_sndPort);
              iVar3 = _port_deallocate_EXTERNAL(uVar2);
              if (iVar3 != 0) {
                _IOLog("Audio: port_deallocate\n");
              }
            }
            uVar2 = _task_self(&local_8);
            iVar3 = _port_allocate_EXTERNAL(uVar2);
            if (iVar3 != 0) {
              _IOLog("Audio: port_allocate");
            }
            _outPort = local_8;
            iVar3 = _kern_serv_port_serv(DAT_001e8718,local_8,_audioMessages,local_8);
            if (iVar3 != 0) {
              _IOLog("Audio: createAudioPorts error %d\n",iVar3);
            }
            uVar2 = _task_self(&local_8);
            iVar3 = _port_allocate_EXTERNAL(uVar2);
            if (iVar3 != 0) {
              _IOLog("Audio: port_allocate");
            }
            _inPort = local_8;
            iVar3 = _kern_serv_port_serv(DAT_001e8718,local_8,_audioMessages,local_8);
            if (iVar3 != 0) {
              _IOLog("Audio: createAudioPorts error %d\n",iVar3);
            }
            uVar2 = _task_self(&local_8);
            iVar3 = _port_allocate_EXTERNAL(uVar2);
            if (iVar3 != 0) {
              _IOLog("Audio: port_allocate");
            }
            _sndPort = local_8;
            iVar3 = _kern_serv_port_serv(DAT_001e8718,local_8,_audioMessages,local_8);
            if (iVar3 != 0) {
              _IOLog("Audio: createAudioPorts error %d\n",iVar3);
            }
          }
          *(int *)(param_2 + 0x1c) = _inPort;
          *(int *)(param_2 + 0x20) = _outPort;
          *(int *)(param_2 + 0x24) = _sndPort;
        }
        else {
          *(undefined4 *)(param_2 + 0x1c) = 0;
          *(undefined4 *)(param_2 + 0x20) = 0;
          *(undefined4 *)(param_2 + 0x24) = 0;
        }
        uVar2 = _objc_msgSend(iVar1,PTR_s__outputChannel_001f9900,PTR_s_setUserChannelPort__001f96f8
                              ,_outPort);
        _objc_msgSend(uVar2);
        uVar2 = _objc_msgSend(iVar1,PTR_s__outputChannel_001f9900,PTR_s_setUserSndPort__001f96fc,
                              _sndPort);
        _objc_msgSend(uVar2);
        uVar2 = _objc_msgSend(iVar1,PTR_s__inputChannel_001f9908,PTR_s_setUserChannelPort__001f96f8,
                              _inPort);
        _objc_msgSend(uVar2);
        uVar2 = _objc_msgSend(iVar1,PTR_s__inputChannel_001f9908,PTR_s_setUserSndPort__001f96fc,
                              _sndPort);
        _objc_msgSend(uVar2);
        uVar2 = 1;
      }
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

