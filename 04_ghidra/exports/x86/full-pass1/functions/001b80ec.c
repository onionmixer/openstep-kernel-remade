/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b80ec */

void FUN_001b80ec(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  *(undefined4 *)(param_1 + 0x14) = param_3;
  _objc_msgSend(*(undefined4 *)(param_1 + 0x10),PTR_s_lock_001f9220);
  iVar1 = _objc_msgSend(*(undefined4 *)(param_1 + 0xc),PTR_s_count_001f92d8);
  if ((iVar1 != 0) && (iVar3 = 0, 0 < iVar1)) {
    do {
      uVar2 = _objc_msgSend(*(undefined4 *)(param_1 + 0xc),PTR_s_objectAt__001f92e8,iVar3,
                            PTR_s_control__001f975c,4);
      _objc_msgSend(uVar2);
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar1);
  }
  _objc_msgSend(*(undefined4 *)(param_1 + 0x10),PTR_s_unlock_001f9474);
  return;
}

