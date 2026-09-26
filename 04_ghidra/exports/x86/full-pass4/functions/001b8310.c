/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b8310 */

void FUN_001b8310(int param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = _objc_msgSend(param_3,PTR_s_userPort_001f978c,0);
  _audio_enroll_stream_port(uVar2);
  _objc_msgSend(*(undefined4 *)(param_1 + 0x10),PTR_s_lock_001f9220);
  iVar3 = _objc_msgSend(*(undefined4 *)(param_1 + 0xc),PTR_s_count_001f92d8);
  if (iVar3 == 1) {
    _objc_msgSend(*(undefined4 *)(param_1 + 0x10),PTR_s_unlock_001f9474);
    cVar1 = _objc_msgSend(param_1,PTR_s_isRead_001f98fc);
    if (cVar1 == '\0') {
      uVar2 = 7;
    }
    else {
      uVar2 = 6;
    }
    uVar2 = _objc_msgSend(*(undefined4 *)(param_1 + 4),PTR_s__audioCommand_001f98e0,
                          PTR_s_send__001f9b4c,uVar2);
    _objc_msgSend(uVar2);
    _objc_msgSend(*(undefined4 *)(param_1 + 0x10),PTR_s_lock_001f9220);
    if (*(int *)(param_1 + 0x58) != 0) {
      _audio_clear_peaks(*(int *)(param_1 + 0x58),0x10);
    }
    if (*(int *)(param_1 + 0x5c) != 0) {
      _audio_clear_peaks(*(int *)(param_1 + 0x5c),0x10);
    }
    *(undefined4 *)(param_1 + 100) = 0;
  }
  _objc_msgSend(*(undefined4 *)(param_1 + 0xc),PTR_s_removeObject__001f92cc,param_3);
  _objc_msgSend(PTR_s_AudioChannel_001f9db8,PTR_s_removeStream__001f9760,param_3);
  _objc_msgSend(param_3,PTR_s_free_001f921c);
  _objc_msgSend(*(undefined4 *)(param_1 + 0x10),PTR_s_unlock_001f9474);
  return;
}

