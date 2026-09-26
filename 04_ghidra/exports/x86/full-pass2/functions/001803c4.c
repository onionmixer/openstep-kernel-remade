/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001803c4 */

int FUN_001803c4(int param_1,undefined4 param_2,int param_3)

{
  int local_c;
  undefined *local_8;
  
  if (param_3 == 0) {
    param_1 = _objc_msgSend(param_1,PTR_s_free_001f921c);
  }
  else {
    local_c = param_1;
    local_8 = PTR_s_Object_001f9fa0;
    _objc_msgSendSuper(&local_c,PTR_s_init_001f924c);
    *(int *)(param_1 + 0xc) = param_3;
  }
  return param_1;
}

