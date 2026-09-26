/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b8200 */

int FUN_001b8200(int param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
                undefined4 param_5,undefined4 param_6)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  cVar1 = _objc_msgSend(*(undefined4 *)(param_1 + 4),PTR_s__channelWillAddStream_001f9758);
  if (cVar1 != '\0') {
    uVar2 = _objc_msgSend(param_1,PTR_s_streamClass_001f9754,PTR_s_alloc_001f9210,
                          PTR_s_initChannel_tag_user_owner_type__001f9750,param_1,param_3,param_4,
                          param_5,param_6);
    uVar2 = _objc_msgSend(uVar2);
    iVar3 = _objc_msgSend(uVar2);
    if (iVar3 != 0) {
      _objc_msgSend(*(undefined4 *)(param_1 + 0x10),PTR_s_lock_001f9220);
      iVar4 = _objc_msgSend(*(undefined4 *)(param_1 + 0xc),PTR_s_count_001f92d8);
      if ((iVar4 == 0) &&
         (cVar1 = _objc_msgSend(param_1,PTR_s_createChannelBuffer_001f974c), cVar1 == '\0')) {
        _objc_msgSend(*(undefined4 *)(param_1 + 0x10),PTR_s_unlock_001f9474);
        return 0;
      }
      _objc_msgSend(*(undefined4 *)(param_1 + 0xc),PTR_s_addObject__001f92c4,iVar3);
      _objc_msgSend(*(undefined4 *)(param_1 + 0x10),PTR_s_unlock_001f9474);
      _objc_msgSend(PTR_s_AudioChannel_001f9db8,PTR_s_addStream__001f9748,iVar3);
      cVar1 = _audio_enroll_stream_port(*param_4,1);
      return (int)cVar1;
    }
  }
  return 0;
}

