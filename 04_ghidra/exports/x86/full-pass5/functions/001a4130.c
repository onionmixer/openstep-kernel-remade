/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a4130 */

void FUN_001a4130(undefined4 param_1)

{
  undefined4 local_c;
  undefined *local_8;
  
  _objc_msgSend(param_1,PTR_s_unregisterDevice_001f9ce4);
  local_c = param_1;
  local_8 = PTR_s_Object_001fa0b8;
  _objc_msgSendSuper(&local_c,PTR_s_free_001f921c);
  return;
}

