/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001bc484 */

undefined4
__NXAudioGetStreamParameterValues
          (int param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  char cVar1;
  undefined4 uVar2;
  
  *param_4 = 0;
  if (param_1 == 0) {
    return 0xca;
  }
  uVar2 = _objc_msgSend(param_1,PTR_s_channel_001f97b0,PTR_s_audioDevice_001f990c,
                        PTR_s__getValues_count_forParameter_fo_001f96b0,param_3,param_4,param_2,
                        param_1);
  uVar2 = _objc_msgSend(uVar2);
  cVar1 = _objc_msgSend(uVar2);
  uVar2 = 0;
  if (cVar1 == '\0') {
    uVar2 = 0xd2;
  }
  return uVar2;
}

