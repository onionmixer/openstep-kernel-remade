/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0019ff48 */

int FUN_0019ff48(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int local_c;
  undefined *local_8;
  
  local_c = param_1;
  local_8 = PTR_s_IOEventSource_001fa040;
  iVar1 = _objc_msgSendSuper(&local_c,PTR_s_relinquishOwnership__001f9518,param_3);
  uVar2 = _objc_msgSend(param_1,PTR_s_ownerLock_001f9510,PTR_s_lock_001f9220);
  _objc_msgSend(uVar2);
  if (iVar1 == 0) {
    iVar3 = _objc_msgSend(param_1,PTR_s_owner_001f94f8);
    if (iVar3 == 0) {
      iVar3 = _objc_msgSend(*(undefined4 *)(param_1 + 300),PTR_s_relinquishOwnership__001f9518,
                            param_1);
      if (iVar3 == 0) {
        *(undefined1 *)(param_1 + 0x130) = 0;
      }
    }
  }
  uVar2 = _objc_msgSend(param_1,PTR_s_ownerLock_001f9510,PTR_s_unlock_001f9474);
  _objc_msgSend(uVar2);
  return iVar1;
}

