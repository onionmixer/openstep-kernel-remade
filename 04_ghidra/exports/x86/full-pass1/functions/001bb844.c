/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001bb844 */

undefined4 __NXAudioSetSndoutOptions(int param_1,undefined4 param_2,uint param_3)

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
      uVar2 = _objc_msgSend(param_1,PTR_s_audioDevice_001f990c);
      _objc_msgSend(uVar2,PTR_s__setParameter_toInt_forObject__001f97e4,5,(param_3 & 1) != 0,param_1
                   );
      _objc_msgSend(uVar2,PTR_s__setParameter_toInt_forObject__001f97e4,3,(param_3 & 2) != 0,param_1
                   );
      _objc_msgSend(uVar2,PTR_s__setParameter_toInt_forObject__001f97e4,4,(param_3 & 4) != 0,param_1
                   );
      _objc_msgSend(uVar2,PTR_s__setParameter_toInt_forObject__001f97e4,6,(param_3 & 8) != 0,param_1
                   );
      _objc_msgSend(uVar2,PTR_s__setParameter_toInt_forObject__001f97e4,7,(param_3 & 0x10) == 0,
                    param_1);
      uVar2 = 0;
    }
  }
  return uVar2;
}

