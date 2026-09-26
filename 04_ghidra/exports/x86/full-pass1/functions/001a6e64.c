/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a6e64 */

undefined4
FUN_001a6e64(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6,undefined4 param_7)

{
  undefined4 uVar1;
  int local_c;
  undefined *local_8;
  
  if (*(char *)(param_1 + 0x1a8) == '\0') {
    uVar1 = _objc_msgSend(param_1,PTR_s_name_001f9228);
    _IOLog("%s: Read attempt with no valid label\n",uVar1);
    return 0xfffffd3e;
  }
  local_c = param_1;
  local_8 = PTR_s_IOLogicalDisk_001fa158;
  uVar1 = _objc_msgSendSuper(&local_c,PTR_s_readAsyncAt_length_buffer_pendin_001f93ac,param_3,
                             param_4,param_5,param_6,param_7);
  return uVar1;
}

