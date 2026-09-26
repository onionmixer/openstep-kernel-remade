/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0019f6b8 */

void FUN_0019f6b8(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = _objc_msgSend(param_3,PTR_s_becomeOwner__001f9494,param_1);
  if (iVar1 == 0) {
    *(undefined1 *)(param_1 + 0x130) = 1;
  }
  else {
    uVar2 = _objc_msgSend(param_1,PTR_s_stringFromReturn__001f9490,iVar1);
    uVar2 = _objc_msgSend(param_3,PTR_s_name_001f9228,uVar2);
    uVar2 = _objc_msgSend(param_1,PTR_s_name_001f9228,uVar2);
    _IOLog(s__s__becomeOwner_of__s_failed___s_001e48c7,uVar2);
  }
  return;
}

