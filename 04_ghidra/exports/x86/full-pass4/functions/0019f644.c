/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0019f644 */

undefined4 FUN_0019f644(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar1 = _objc_msgSend(param_1,PTR_s_ownerLock_001f9510,PTR_s_lock_001f9220);
  _objc_msgSend(uVar1);
  iVar2 = _objc_msgSend(param_1,PTR_s_owner_001f94f8);
  if (iVar2 == 0) {
    *(undefined1 *)(param_1 + 0x130) = 0;
    uVar1 = 0;
  }
  else {
    uVar1 = 0xfffffd2b;
  }
  uVar3 = _objc_msgSend(param_1,PTR_s_ownerLock_001f9510,PTR_s_unlock_001f9474);
  _objc_msgSend(uVar3);
  return uVar1;
}

