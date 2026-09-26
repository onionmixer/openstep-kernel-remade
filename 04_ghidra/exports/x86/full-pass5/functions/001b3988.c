/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b3988 */

int FUN_001b3988(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  
  _objc_msgSend(*(undefined4 *)(param_1 + 0x110),PTR_s_lock_001f9220);
  if (*(int *)(param_1 + 0x108) == param_3) {
    iVar4 = 0;
    *(undefined4 *)(param_1 + 0x108) = 0;
  }
  else {
    iVar4 = -0x2d5;
  }
  _objc_msgSend(*(undefined4 *)(param_1 + 0x110),PTR_s_unlock_001f9474);
  if (((iVar4 == 0) && (iVar1 = *(int *)(param_1 + 0x10c), iVar1 != 0)) && (iVar1 != param_3)) {
    cVar2 = _objc_msgSend(iVar1,PTR_s_respondsTo__001f9464,PTR_s_canBecomeOwner__001f9950);
    if (cVar2 == '\0') {
      uVar3 = _objc_msgSend(param_1,PTR_s_name_001f9228);
      _IOLog("%s: desiredOwner does not respond to canBecomeOwner:\n",uVar3);
    }
    else {
      _objc_msgSend(*(undefined4 *)(param_1 + 0x10c),PTR_s_canBecomeOwner__001f9950,param_1);
    }
  }
  return iVar4;
}

