/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001bad9c */

undefined4 _audio_reset_snd_dev_port(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_8;
  
  iVar1 = _IOHostPrivSelf();
  if (iVar1 == 0) {
    _IOLog("Audio: cannot get kernel port (must run as root)\n");
    _IOLog("reset_snd_dev_port");
  }
  if (param_2 == iVar1) {
    uVar2 = _objc_msgSend(param_1,PTR_s__outputChannel_001f9900,PTR_s_userSndPort_001f9904);
    uVar2 = _objc_msgSend(uVar2);
    uVar2 = _task_self(uVar2);
    iVar1 = _port_deallocate_EXTERNAL(uVar2);
    if (iVar1 != 0) {
      _IOLog("Audio: port_deallocate\n");
    }
    uVar2 = _task_self(&local_8);
    iVar1 = _port_allocate_EXTERNAL(uVar2);
    if (iVar1 != 0) {
      _IOLog("Audio: port_allocate");
    }
    uVar2 = _objc_msgSend(param_1,PTR_s__inputChannel_001f9908,PTR_s_setUserSndPort__001f96fc,
                          local_8);
    _objc_msgSend(uVar2);
    uVar2 = _objc_msgSend(param_1,PTR_s__outputChannel_001f9900,PTR_s_setUserSndPort__001f96fc,
                          local_8);
    _objc_msgSend(uVar2);
  }
  else {
    local_8 = 0;
  }
  return local_8;
}

