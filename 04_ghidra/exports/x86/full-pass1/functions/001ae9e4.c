/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001ae9e4 */

void FUN_001ae9e4(int param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  
  _objc_msgSend(*(undefined4 *)(param_1 + 300),PTR_s_lock_001f9220);
  if (*(int *)(param_1 + 0x130) == param_3) {
    _objc_msgSend(param_1,PTR_s_clearReservation_001f9a54);
    *(undefined4 *)(param_1 + 0x130) = 0;
  }
  else {
    uVar1 = _objc_msgSend(param_1,PTR_s_name_001f9228);
    _IOLog("%s: bogus close call\n",uVar1);
  }
  _objc_msgSend(*(undefined4 *)(param_1 + 300),PTR_s_unlock_001f9474);
  return;
}

