/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a83e8 */

int FUN_001a83e8(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int local_c;
  undefined *local_8;
  
  local_c = param_1;
  local_8 = PTR_s_IODevice_001fa1a8;
  _objc_msgSendSuper(&local_c,PTR_s_init_001f924c);
  _objc_msgSend(param_1,PTR_s_setDeviceDescription__001f9bf4,param_3);
  _objc_msgSend(param_1,PTR_s_initEISA_001f9bf0);
  puVar1 = (undefined4 *)_IOMalloc(8);
  *(undefined4 **)(param_1 + 0x11c) = puVar1;
  puVar1[1] = 0;
  *puVar1 = 0;
  return param_1;
}

