/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017e934 */

int FUN_0017e934(int param_1)

{
  int local_c;
  undefined *local_8;
  
  if (*(int *)(param_1 + 0x14) < 1) {
    if ((*(int *)(param_1 + 8) != 0) && (*(int *)(param_1 + 0x18) != 0)) {
      _IOFree(*(int *)(param_1 + 0x18),4);
    }
    local_c = param_1;
    local_8 = PTR_s_Object_001f9ed8;
    param_1 = _objc_msgSendSuper(&local_c,PTR_s_free_001f921c);
  }
  return param_1;
}

