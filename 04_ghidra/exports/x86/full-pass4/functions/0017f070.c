/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017f070 */

int FUN_0017f070(int param_1,undefined4 param_2,int param_3,int param_4,int param_5,
                undefined1 param_6)

{
  int local_c;
  undefined *local_8;
  
  if (param_3 == 0) {
    local_c = param_1;
    local_8 = PTR_s_Object_001f9e60;
    param_1 = _objc_msgSendSuper(&local_c,PTR_s_free_001f921c);
  }
  else {
    local_c = param_1;
    local_8 = PTR_s_Object_001f9e60;
    _objc_msgSendSuper(&local_c,PTR_s_init_001f924c);
    *(int *)(param_1 + 8) = param_3;
    *(int *)(param_1 + 0xc) = param_4;
    *(int *)(param_1 + 0x10) = param_4 + param_5;
    *(undefined4 *)(param_1 + 0x14) = 1;
    *(undefined1 *)(param_1 + 0x18) = param_6;
    *(undefined4 *)(param_1 + 0x1c) = 0;
  }
  return param_1;
}

