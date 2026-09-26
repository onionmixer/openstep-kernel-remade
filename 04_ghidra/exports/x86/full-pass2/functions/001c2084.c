/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c2084 */

int FUN_001c2084(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int local_c;
  undefined4 local_8;
  
  local_c = param_1;
  local_8 = _objc_getOrigClass("IOEISADeviceDescription",PTR_s__initWithDelegate__001f9458,param_3);
  _objc_msgSendSuper(&local_c);
  puVar1 = (undefined4 *)_IOMalloc(8);
  *(undefined4 **)(param_1 + 0x24) = puVar1;
  *puVar1 = 0;
  puVar1[1] = 0;
  return param_1;
}

