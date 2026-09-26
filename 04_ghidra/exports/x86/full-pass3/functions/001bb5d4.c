/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001bb5d4 */

undefined4
__NXAudioAddStream(int param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  char cVar1;
  undefined4 uVar2;
  
  if ((param_1 == 0) || (param_3 == 0)) {
    uVar2 = 0xca;
  }
  else {
    cVar1 = _objc_msgSend(param_1,PTR_s_checkOwner__001f96e8,param_3);
    if (cVar1 == '\0') {
      uVar2 = 200;
    }
    else {
      cVar1 = _objc_msgSend(param_1,PTR_s_addStreamTag_user_owner_type__001f96e0,param_4,param_2,
                            param_3,param_5);
      uVar2 = 0;
      if (cVar1 == '\0') {
        uVar2 = 5;
      }
    }
  }
  return uVar2;
}

