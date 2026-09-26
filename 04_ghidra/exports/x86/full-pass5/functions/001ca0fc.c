/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001ca0fc */

undefined4 FUN_001ca0fc(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_1 == 0) {
    uVar1 = 0;
  }
  else {
    iVar2 = _objc_msgSend(param_1,PTR_s_methodArgSize__001f9d18,param_3);
    if (iVar2 == 0) {
      uVar1 = _objc_msgSend(param_1,PTR_s_doesNotRecognize__001f9d1c,param_3);
    }
    else {
      uVar1 = _objc_msgSendv(param_1,param_3,iVar2,param_4);
    }
  }
  return uVar1;
}

