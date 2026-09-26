/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017f4e8 */

int FUN_0017f4e8(int param_1)

{
  undefined4 uVar1;
  int local_c;
  undefined *local_8;
  
  local_c = param_1;
  local_8 = PTR_s_Object_001f9e10;
  _objc_msgSendSuper(&local_c,PTR_s_init_001f924c);
  if (*(int *)(param_1 + 4) == 0) {
    uVar1 = _objc_msgSend(PTR_s_HashTable_001f9d74,PTR_s_alloc_001f9210,PTR_s_initKeyDesc__001f9284,
                          &DAT_001e0fce);
    uVar1 = _objc_msgSend(uVar1);
    *(undefined4 *)(param_1 + 4) = uVar1;
  }
  return param_1;
}

