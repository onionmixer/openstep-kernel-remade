/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a9034 */

void FUN_001a9034(int param_1)

{
  undefined4 *puVar1;
  int local_c;
  undefined *local_8;
  
  puVar1 = *(undefined4 **)(param_1 + 4);
  if (puVar1 != (undefined4 *)0x0) {
    _lock_free(*puVar1);
    _kfree(puVar1,4);
  }
  local_c = param_1;
  local_8 = PTR_s_Object_001fa220;
  _objc_msgSendSuper(&local_c,PTR_s_free_001f921c);
  return;
}

