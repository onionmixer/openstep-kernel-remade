/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001bbe60 */

undefined4
__NXAudioRecordStream
          (int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
          undefined4 param_6,undefined4 param_7)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 local_804;
  undefined4 local_800;
  undefined4 local_404;
  undefined4 local_400;
  
  if (param_1 == 0) {
    uVar2 = 0xca;
  }
  else {
    uVar2 = _objc_msgSend(param_1,PTR_s_ownerPort_001f9788);
    uVar2 = _objc_msgSend(param_1,PTR_s_channel_001f97b0,PTR_s_checkOwner__001f96e8,uVar2);
    cVar1 = _objc_msgSend(uVar2);
    if (cVar1 == '\0') {
      uVar2 = 200;
    }
    else {
      if (param_2 != 0) {
        local_404 = 0x194;
        local_804 = param_4;
        local_400 = 0x193;
        local_800 = param_5;
        uVar2 = _objc_msgSend(param_1,PTR_s_channel_001f97b0,PTR_s_audioDevice_001f990c,
                              PTR_s__setParameters_toValues_count_fo_001f96cc,&local_404,&local_804,
                              2,param_1);
        uVar2 = _objc_msgSend(uVar2);
        _objc_msgSend(uVar2);
        cVar1 = _objc_msgSend(param_1,PTR_s_recordSize_tag_replyTo_replyMsgs_001f96c4,param_2,
                              param_3,param_6,param_7);
        if (cVar1 != '\0') {
          return 0;
        }
      }
      uVar2 = 0xcc;
    }
  }
  return uVar2;
}

