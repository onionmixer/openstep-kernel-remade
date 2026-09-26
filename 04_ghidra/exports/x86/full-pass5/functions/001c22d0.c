/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c22d0 */

void FUN_001c22d0(int param_1)

{
  int iVar1;
  int local_c;
  undefined *local_8;
  
  iVar1 = *(int *)(param_1 + 4);
  if (*(int *)(iVar1 + 0xc) != 0) {
    _IOFree(*(int *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 8));
  }
  _IOFree(iVar1,0x10);
  local_c = param_1;
  local_8 = PTR_s_Object_001fa5e0;
  _objc_msgSendSuper(&local_c,PTR_s_free_001f921c);
  return;
}

