/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b2bc8 */

void FUN_001b2bc8(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = _objc_msgSend(param_3,PTR_s_becomeOwner__001f9494,param_1);
  if (iVar1 != 0) {
    uVar2 = _objc_msgSend(param_1,PTR_s_stringFromReturn__001f9490,iVar1);
    uVar2 = _objc_msgSend(param_3,PTR_s_name_001f9228,uVar2);
    uVar2 = _objc_msgSend(param_1,PTR_s_name_001f9228,uVar2);
    _IOLog("%s: becomeOwner of %s failed (%s)\n",uVar2);
  }
  return;
}

