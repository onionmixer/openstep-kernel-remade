/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001bc1b4 */

undefined4 __NXAudioGetDeviceSupportedParameters(int param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  
  *param_3 = 0;
  if (param_1 != 0) {
    uVar1 = _objc_msgSend(param_1,PTR_s_audioDevice_001f990c,
                          PTR_s__getSupportedParameters_count_fo_001f96b4,param_2,param_3,param_1);
    _objc_msgSend(uVar1);
    return 0;
  }
  return 0xca;
}

