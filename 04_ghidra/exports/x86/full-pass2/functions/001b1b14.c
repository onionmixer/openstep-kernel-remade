/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b1b14 */

int FUN_001b1b14(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  _objc_msgSend(*(undefined4 *)(param_1 + 0x20c),PTR_s_lock_001f9220);
  *(undefined1 *)(param_1 + 0x20a) = 0;
  _objc_msgSend(*(undefined4 *)(param_1 + 0x20c),PTR_s_unlock_001f9474);
  iVar1 = _msg_send(*(undefined4 *)(param_1 + 0x14c),1,0);
  if ((iVar1 != -0x67) && (iVar1 != 0)) {
    uVar2 = _objc_msgSend(param_1,PTR_s_name_001f9228,iVar1);
    _IOLog("%s: _performKickEventConsumer msg_send returned %d\n",uVar2);
  }
  return param_1;
}

