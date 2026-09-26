/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a6154 */

void FUN_001a6154(undefined4 param_1)

{
  int iVar1;
  undefined4 local_c;
  undefined *local_8;
  
  iVar1 = _objc_msgSend(param_1,PTR_s_nextLogicalDisk_001f9c8c);
  if (iVar1 != 0) {
    _objc_msgSend(iVar1,PTR_s_free_001f921c);
  }
  local_c = param_1;
  local_8 = PTR_s_IODisk_001fa130;
  _objc_msgSendSuper(&local_c,PTR_s_free_001f921c);
  return;
}

