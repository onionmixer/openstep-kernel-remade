/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b65ec */

void FUN_001b65ec(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  undefined4 uVar2;
  undefined *puVar3;
  
  cVar1 = _objc_msgSend(param_3,PTR_s_isRead_001f98fc);
  uVar2 = _objc_msgSend(param_3,PTR_s_localChannel_001f9894,(int)cVar1);
  _objc_msgSend(param_1,PTR_s_stopDMAForChannel_read__001f986c,uVar2);
  _objc_msgSend(param_3,PTR_s_freeDescriptors_001f9868);
  cVar1 = _objc_msgSend(param_3,PTR_s_isRead_001f98fc);
  puVar3 = PTR_s__setOutputActive__001f987c;
  if (cVar1 != '\0') {
    puVar3 = PTR_s__setInputActive__001f9880;
  }
  _objc_msgSend(param_1,puVar3,0);
  cVar1 = _objc_msgSend(param_1,PTR_s_isInputActive_001f98f8);
  if ((cVar1 == '\0') &&
     (cVar1 = _objc_msgSend(param_1,PTR_s_isOutputActive_001f98f4), cVar1 == '\0')) {
    _objc_msgSend(param_1,PTR_s__setTimeout__001f9874,0xffffffff);
  }
  return;
}

