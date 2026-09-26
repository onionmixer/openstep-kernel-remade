/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b38d0 */

int FUN_001b38d0(int param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  
  _objc_msgSend(*(undefined4 *)(param_1 + 0x110),PTR_s_lock_001f9220);
  if (*(int *)(param_1 + 0x108) == 0) {
    *(undefined4 *)(param_1 + 0x108) = param_3;
    iVar2 = 0;
  }
  else {
    cVar1 = _objc_msgSend(*(int *)(param_1 + 0x108),PTR_s_respondsTo__001f9464,
                          PTR_s_relinquishOwnership__001f9518);
    if (cVar1 == '\0') {
      uVar3 = _objc_msgSend(param_1,PTR_s_name_001f9228);
      _IOLog("%s: owner does not respond to relinquishOwnership:\n",uVar3);
      iVar2 = -0x2d5;
    }
    else {
      iVar2 = _objc_msgSend(*(undefined4 *)(param_1 + 0x108),PTR_s_relinquishOwnership__001f9518,
                            param_1);
    }
    if (iVar2 == 0) {
      *(undefined4 *)(param_1 + 0x108) = param_3;
    }
  }
  _objc_msgSend(*(undefined4 *)(param_1 + 0x110),PTR_s_unlock_001f9474);
  return iVar2;
}

