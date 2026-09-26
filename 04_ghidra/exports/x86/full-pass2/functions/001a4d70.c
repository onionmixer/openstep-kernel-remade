/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a4d70 */

int FUN_001a4d70(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  undefined4 local_8;
  
  _objc_msgSend(DAT_001e8674,PTR_s_lock_001f9220);
  iVar1 = FUN_001a3d58(param_5,&local_8);
  _objc_msgSend(DAT_001e8674,PTR_s_unlock_001f9474);
  if (iVar1 == 0) {
    iVar1 = _objc_msgSend(local_8,PTR_s_setIntValues_forParameter_count__001f94bc,param_3,param_4,
                          param_6);
  }
  return iVar1;
}

