/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001bc250 */

undefined4
__NXAudioGetSamplingRates
          (int param_1,int *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
          undefined4 *param_6)

{
  char cVar1;
  undefined4 uVar2;
  
  *param_6 = 0;
  if (param_1 == 0) {
    uVar2 = 0xca;
  }
  else {
    uVar2 = _objc_msgSend(param_1,PTR_s_audioDevice_001f990c,
                          PTR_s_acceptsContinuousSamplingRates_001f96ac);
    cVar1 = _objc_msgSend(uVar2);
    *param_2 = (int)cVar1;
    uVar2 = _objc_msgSend(param_1,PTR_s_audioDevice_001f990c,
                          PTR_s_getSamplingRatesLow_high__001f96a8,param_3,param_4);
    _objc_msgSend(uVar2);
    uVar2 = _objc_msgSend(param_1,PTR_s_audioDevice_001f990c,PTR_s_getSamplingRates_count__001f96a4,
                          param_5,param_6);
    _objc_msgSend(uVar2);
    uVar2 = 0;
  }
  return uVar2;
}

