/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001bba44 */

undefined4 __NXAudioSetStreamGain(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = _objc_msgSend(param_1,PTR_s_channel_001f97b0,PTR_s_audioDevice_001f990c,
                        PTR_s__setParameter_toInt_forObject__001f97e4,0x199,param_2,param_1);
  uVar1 = _objc_msgSend(uVar1);
  _objc_msgSend(uVar1);
  uVar1 = _objc_msgSend(param_1,PTR_s_channel_001f97b0,PTR_s_audioDevice_001f990c,
                        PTR_s__setParameter_toInt_forObject__001f97e4,0x19a,param_3,param_1);
  uVar1 = _objc_msgSend(uVar1);
  _objc_msgSend(uVar1);
  return 0;
}

