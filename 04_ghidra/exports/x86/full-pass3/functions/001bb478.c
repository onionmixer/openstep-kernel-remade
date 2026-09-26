/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001bb478 */

undefined4 __NXAudioGetBufferOptions(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0xca;
  }
  else {
    uVar1 = _objc_msgSend(param_1,PTR_s_audioDevice_001f990c,
                          PTR_s__intValueForParameter_forObject__001f97e0,0,param_1);
    uVar1 = _objc_msgSend(uVar1);
    *param_2 = uVar1;
    uVar1 = _objc_msgSend(param_1,PTR_s_audioDevice_001f990c,
                          PTR_s__intValueForParameter_forObject__001f97e0,1,param_1);
    uVar1 = _objc_msgSend(uVar1);
    *param_3 = uVar1;
    uVar1 = 0;
  }
  return uVar1;
}

