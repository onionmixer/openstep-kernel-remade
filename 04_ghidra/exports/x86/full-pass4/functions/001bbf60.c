/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001bbf60 */

void _audio_port_gone(int param_1)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (param_1 != 0) {
    do {
      bVar1 = false;
      iVar2 = _objc_msgSend(PTR_s_IOAudio_001f9dbc,PTR_s__channelForExclusivePort__001f96c0,param_1)
      ;
      if (iVar2 == 0) {
        iVar2 = _objc_msgSend(PTR_s_AudioChannel_001f9db8,PTR_s_streamForOwnerPort__001f96bc,param_1
                             );
        if (iVar2 != 0) {
          uVar3 = _objc_msgSend(iVar2,PTR_s_channel_001f97b0,PTR_s_removeStream__001f9760,iVar2);
          _objc_msgSend(uVar3);
          bVar1 = true;
        }
      }
      else {
        _objc_msgSend(iVar2,PTR_s_setExclusiveUser__001f96ec,0);
        bVar1 = true;
      }
    } while (bVar1);
  }
  return;
}

