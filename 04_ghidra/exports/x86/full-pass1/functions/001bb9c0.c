/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001bb9c0 */

undefined4 __NXAudioSetSpeaker(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    uVar2 = 0xca;
  }
  else {
    cVar1 = _objc_msgSend(param_1,PTR_s_checkOwner__001f96e8,param_2);
    if (cVar1 == '\0') {
      uVar2 = 200;
    }
    else {
      uVar2 = _objc_msgSend(param_1,PTR_s_audioDevice_001f990c,
                            PTR_s__setParameter_toInt_forObject__001f97e4,0xc,param_3,param_1);
      _objc_msgSend(uVar2);
      uVar2 = _objc_msgSend(param_1,PTR_s_audioDevice_001f990c,
                            PTR_s__setParameter_toInt_forObject__001f97e4,0xd,param_4,param_1);
      _objc_msgSend(uVar2);
      uVar2 = 0;
    }
  }
  return uVar2;
}

