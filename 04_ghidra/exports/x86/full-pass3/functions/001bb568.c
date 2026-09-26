/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001bb568 */

undefined4 __NXAudioControlStreams(int param_1,int param_2,uint param_3)

{
  char cVar1;
  undefined4 uVar2;
  
  if ((param_1 == 0) || (param_2 == 0)) {
    uVar2 = 0xca;
  }
  else {
    cVar1 = _objc_msgSend(param_1,PTR_s_checkOwner__001f96e8,param_2);
    if (cVar1 == '\0') {
      uVar2 = 200;
    }
    else if ((param_3 < 2) || (param_3 - 2 < 2)) {
      _objc_msgSend(param_1,PTR_s_controlStreams__001f96e4,param_3);
      uVar2 = 0;
    }
    else {
      uVar2 = 0xce;
    }
  }
  return uVar2;
}

