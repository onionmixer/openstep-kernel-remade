/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a3d0c */

undefined4 _IOGetObjectForDeviceName(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined1 local_8 [4];
  
  _objc_msgSend(DAT_001e8674,PTR_s_lock_001f9220);
  uVar1 = FUN_001a3d9c(param_1,param_2,local_8);
  _objc_msgSend(DAT_001e8674,PTR_s_unlock_001f9474);
  return uVar1;
}

