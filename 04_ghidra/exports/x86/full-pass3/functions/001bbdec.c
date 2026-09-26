/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001bbdec */

undefined4 __NXAudioGetStreamPeak(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_1 == 0) {
    uVar1 = 0xca;
  }
  else {
    uVar1 = _objc_msgSend(param_1,PTR_s_channel_001f97b0,PTR_s_audioDevice_001f990c,
                          PTR_s__intValueForParameter_forObject__001f97e0,0x197,param_1);
    uVar1 = _objc_msgSend(uVar1);
    iVar2 = _objc_msgSend(uVar1);
    if (iVar2 == 0) {
      uVar1 = 0xd0;
    }
    else {
      _objc_msgSend(param_1,PTR_s_getPeakLeft_right__001f96dc,param_2,param_3);
      uVar1 = 0;
    }
  }
  return uVar1;
}

