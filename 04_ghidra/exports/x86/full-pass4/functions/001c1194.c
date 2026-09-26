/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c1194 */

undefined4 FUN_001c1194(undefined4 param_1,undefined4 param_2,int param_3,uint param_4)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 unaff_EBX;
  
  if (_is_ISA == '\0') {
    uVar1 = _objc_msgSend(param_1,PTR_s_deviceDescription_001f9378,PTR_s_numChannels_001f97b4);
    uVar2 = _objc_msgSend(uVar1);
    if (param_4 < uVar2) {
      uVar1 = _objc_msgSend(param_1,PTR_s__localToChannel__001f9688,param_4);
      if (param_3 == 1) {
        unaff_EBX = 1;
      }
      else if (param_3 == 0) {
        unaff_EBX = 0;
      }
      else if (param_3 == 2) {
        unaff_EBX = 2;
      }
      else if (param_3 == 3) {
        unaff_EBX = 3;
      }
      _dma_timing(uVar1,unaff_EBX);
      uVar1 = 0;
    }
    else {
      uVar1 = 0xfffffd3e;
    }
  }
  else {
    uVar1 = 0xfffffd39;
  }
  return uVar1;
}

