/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b9ba8 */

int FUN_001b9ba8(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int local_c;
  undefined *local_8;
  
  local_c = param_1;
  local_8 = PTR_s_AudioStream_001fa4f0;
  _objc_msgSendSuper(&local_c,PTR_s_dmaCompleteDescriptor_transfered_001f9768,param_3,param_4);
  if (*(char *)(param_1 + 0x78) != '\0') {
    _objc_msgSend(param_1,PTR_s_returnRecordedData_001f9704);
  }
  return param_1;
}

