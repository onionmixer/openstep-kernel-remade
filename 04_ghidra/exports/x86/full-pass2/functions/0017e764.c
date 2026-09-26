/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017e764 */

void FUN_0017e764(int param_1,undefined4 param_2,int param_3)

{
  int local_c;
  undefined *local_8;
  
  if (param_3 == 0) {
    local_c = param_1;
    local_8 = PTR_s_Object_001f9de8;
    _objc_msgSendSuper(&local_c,PTR_s_free_001f921c);
    return;
  }
  *(int *)(param_1 + 8) = param_3;
  return;
}

