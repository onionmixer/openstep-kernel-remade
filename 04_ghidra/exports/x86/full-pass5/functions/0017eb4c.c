/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017eb4c */

int FUN_0017eb4c(int param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined1 param_5)

{
  int local_c;
  undefined *local_8;
  
  if (param_3 == 0) {
    local_c = param_1;
    local_8 = PTR_s_Object_001f9eb0;
    param_1 = _objc_msgSendSuper(&local_c,PTR_s_free_001f921c);
  }
  else {
    local_c = param_1;
    local_8 = PTR_s_Object_001f9eb0;
    _objc_msgSendSuper(&local_c,PTR_s_init_001f924c);
    *(int *)(param_1 + 4) = param_3;
    *(undefined4 *)(param_1 + 8) = param_4;
    *(undefined4 *)(param_1 + 0xc) = 1;
    *(undefined1 *)(param_1 + 0x10) = param_5;
  }
  return param_1;
}

