/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a5e9c */

void FUN_001a5e9c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar1 = _objc_msgSend(param_1,PTR_s__diskParamCommon_length_deviceOf_001f9cb8,param_3,param_4,
                        &local_8,&local_c);
  if (iVar1 == 0) {
    _objc_msgSend(*(undefined4 *)(param_1 + 0x184),PTR_s_readAsyncAt_length_buffer_pendin_001f93ac,
                  local_8,local_c,param_5,param_6,param_7);
  }
  return;
}

