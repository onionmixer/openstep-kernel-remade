/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b8b44 */

int FUN_001b8b44(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (*(int *)(param_1 + 0x1c) == 0) {
    if ((*(uint *)(param_1 + 0x60) & param_4) != 0) {
      uVar1 = _IOConvertPort(*(undefined4 *)(param_1 + 0x5c),0,1);
      uVar2 = _IOConvertPort(*(undefined4 *)(param_1 + 0x10),0,1);
      __NXAudioReplyStreamStatus(uVar1,uVar2,uVar1,*(undefined4 *)(param_1 + 0x18),0,param_3);
    }
  }
  else {
    _objc_msgSend(*(undefined4 *)(param_1 + 0x28),PTR_s_lock_001f9220);
    if (*(int *)(param_1 + 0x2c) == param_1 + 0x2c) {
      _objc_msgSend(*(undefined4 *)(param_1 + 0x28),PTR_s_unlock_001f9474);
    }
    else {
      _objc_msgSend(param_1,PTR_s_createSndReplyMsg_001f9744);
      iVar3 = *(int *)(param_1 + 0x2c);
      if (param_1 + 0x2c != iVar3) {
        do {
          if ((*(uint *)(iVar3 + 0x18) & param_4) != 0) {
            uVar1 = _IOConvertPort(*(undefined4 *)(iVar3 + 0x1c),0,1);
            if (param_3 == 2) {
              _audio_snd_reply_paused
                        (*(undefined4 *)(param_1 + 0x34),uVar1,*(undefined4 *)(iVar3 + 0x14));
            }
            else if (param_3 == 3) {
              _audio_snd_reply_resumed
                        (*(undefined4 *)(param_1 + 0x34),uVar1,*(undefined4 *)(iVar3 + 0x14));
            }
            else if (param_3 == 4) {
              _audio_snd_reply_aborted
                        (*(undefined4 *)(param_1 + 0x34),uVar1,*(undefined4 *)(iVar3 + 0x14));
            }
            _msg_send(*(undefined4 *)(param_1 + 0x34),0x21,1000);
          }
          iVar3 = *(int *)(iVar3 + 0x3c);
        } while (param_1 + 0x2c != iVar3);
      }
      _objc_msgSend(*(undefined4 *)(param_1 + 0x28),PTR_s_unlock_001f9474);
    }
  }
  return param_1;
}

