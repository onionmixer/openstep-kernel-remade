/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a4bdc */

undefined4 FUN_001a4bdc(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  _objc_msgSend(DAT_001e8674,PTR_s_lock_001f9220);
  uVar1 = FUN_001a3d58(param_3,param_4);
  _objc_msgSend(DAT_001e8674,PTR_s_unlock_001f9474);
  return uVar1;
}

