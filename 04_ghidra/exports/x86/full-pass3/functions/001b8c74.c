/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b8c74 */

int FUN_001b8c74(int param_1,undefined4 param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar1 = _IOConvertPort(*(undefined4 *)(param_4 + 0x1c),0,1);
  uVar2 = _IOConvertPort(*(undefined4 *)(param_1 + 0x10),0,1);
  if (*(int *)(param_1 + 0x1c) == 0) {
    if ((param_3 == 4) && (*(int *)(param_4 + 0x38) != 0)) {
      param_3 = 6;
    }
    iVar3 = __NXAudioReplyStreamStatus
                      (uVar1,uVar2,uVar1,*(undefined4 *)(param_1 + 0x18),
                       *(undefined4 *)(param_4 + 0x14),param_3);
    if (iVar3 != 0) {
      _IOLog("AS: replyStreamStatus returns %d\n",iVar3);
    }
  }
  else {
    _objc_msgSend(param_1,PTR_s_createSndReplyMsg_001f9744);
    if (param_3 == 0) {
      _audio_snd_reply_started
                (*(undefined4 *)(param_1 + 0x34),uVar1,*(undefined4 *)(param_4 + 0x14));
    }
    else if (param_3 == 1) {
      _audio_snd_reply_completed
                (*(undefined4 *)(param_1 + 0x34),uVar1,*(undefined4 *)(param_4 + 0x14));
    }
    else if (param_3 == 5) {
      _audio_snd_reply_overflow
                (*(undefined4 *)(param_1 + 0x34),uVar1,*(undefined4 *)(param_4 + 0x14));
    }
    _msg_send(*(undefined4 *)(param_1 + 0x34),0x21,1000);
  }
  return param_1;
}

