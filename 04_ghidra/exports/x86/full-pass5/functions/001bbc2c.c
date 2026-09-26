/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001bbc2c */

undefined4
__NXAudioPlayStream(int param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5
                   ,int param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,
                   undefined4 param_10,undefined4 param_11,undefined4 param_12)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 local_804;
  undefined4 local_800;
  undefined4 local_7fc;
  undefined4 local_7f8;
  undefined4 local_404;
  undefined4 local_400;
  undefined4 local_3fc;
  undefined4 local_3f8;
  
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
      if (param_3 != 0) {
        local_404 = 0x192;
        local_804 = param_5;
        local_400 = 0x191;
        if (param_6 == 1) {
          local_800 = 0x5622;
        }
        else {
          local_800 = 0xac44;
        }
        local_3fc = 0x194;
        local_7fc = param_9;
        local_3f8 = 0x193;
        local_7f8 = param_10;
        uVar2 = _objc_msgSend(param_1,PTR_s_channel_001f97b0,PTR_s_audioDevice_001f990c,
                              PTR_s__setParameters_toValues_count_fo_001f96cc,&local_404,&local_804,
                              4,param_1);
        uVar2 = _objc_msgSend(uVar2);
        _objc_msgSend(uVar2);
        cVar1 = _objc_msgSend(param_1,PTR_s_playBuffer_size_tag_replyTo_repl_001f96c8,param_2,
                              param_3,param_4,param_11,param_12);
        if (cVar1 != '\0') {
          return 0;
        }
      }
      uVar2 = 0xcc;
    }
    uVar3 = _task_self(param_2,param_3);
    iVar4 = _vm_deallocate_EXTERNAL(uVar3);
    if (iVar4 != 0) {
      _IOLog("Audio: audio server vm_deallocate error: %s (%d)\n","MACH ERR",iVar4);
    }
  }
  return uVar2;
}

