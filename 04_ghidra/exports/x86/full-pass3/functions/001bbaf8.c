/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001bbaf8 */

undefined4 __NXAudioStreamControl(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    return 0xca;
  }
  uVar2 = _objc_msgSend(param_1,PTR_s_ownerPort_001f9788);
  uVar2 = _objc_msgSend(param_1,PTR_s_channel_001f97b0,PTR_s_checkOwner__001f96e8,uVar2);
  cVar1 = _objc_msgSend(uVar2);
  if (cVar1 != '\0') {
    if (param_2 == 1) {
      uVar2 = 1;
    }
    else if (param_2 < 2) {
      if (param_2 != 0) {
        return 0xce;
      }
      uVar2 = 0;
    }
    else {
      if (param_2 != 2) {
        if (param_2 == 3) {
          _objc_msgSend(param_1,PTR_s_returnRecordedData_001f9704);
          return 0;
        }
        return 0xce;
      }
      uVar2 = 2;
    }
    _objc_msgSend(param_1,PTR_s_control_atTime__001f971c,uVar2,param_3,param_4);
    return 0;
  }
  return 200;
}

