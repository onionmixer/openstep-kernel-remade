/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c694c */

undefined4 FUN_001c694c(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 local_60;
  undefined4 local_5c;
  undefined *local_58;
  undefined1 local_54 [80];
  
  local_5c = param_1;
  local_58 = PTR_s_IODisplay_001fa630;
  iVar1 = _objc_msgSendSuper(&local_5c,PTR_s_initFromDeviceDescription__001f9560,param_3);
  if (iVar1 == 0) {
    local_5c = param_1;
    local_58 = PTR_s_IODisplay_001fa630;
    param_1 = _objc_msgSendSuper(&local_5c,PTR_s_free_001f921c);
  }
  else {
    _objc_msgSend(param_1,PTR_s__generateName_andUnit__001f9598,local_54,&local_60);
    _objc_msgSend(param_1,PTR_s_setUnit__001f9478,local_60);
    _objc_msgSend(param_1,PTR_s_setName__001f947c,local_54);
  }
  return param_1;
}

