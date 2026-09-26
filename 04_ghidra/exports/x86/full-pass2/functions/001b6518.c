/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b6518 */

undefined4 FUN_001b6518(int param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  int iVar2;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_8 = _objc_msgSend(param_1,PTR_s_sampleRate_001f98b4);
  local_c = *(undefined4 *)(param_1 + 0x148);
  local_10 = _objc_msgSend(param_1,PTR_s_channelCount_001f98b0);
  iVar2 = _objc_msgSend(param_3,PTR_s_enqueueCount_001f98a4);
  if (iVar2 != 0) {
    _objc_msgSend(param_3,PTR_s_dequeueDescriptor_001f9870);
  }
  cVar1 = _objc_msgSend(param_3,PTR_s_enqueueDescriptor_dataFormat_cha_001f98a8,&local_8,&local_c,
                        &local_10);
  if ((cVar1 == '\0') && (iVar2 = _objc_msgSend(param_3,PTR_s_enqueueCount_001f98a4), iVar2 == 0)) {
    _objc_msgSend(param_1,PTR_s__stopDMAForChannel__001f98c0,param_3);
    _objc_msgSend(param_1,PTR_s__setOutputStartTime__001f9884,0,0);
    _objc_msgSend(param_1,PTR_s__setLastInterruptTimeStamp__001f98e8,0,0);
    return 1;
  }
  return 0;
}

