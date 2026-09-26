/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c105c */

undefined4 FUN_001c105c(undefined4 param_1,undefined4 param_2,int param_3,uint param_4)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 uVar3;
  
  if ((param_3 == 1) || (_is_ISA != '\0')) {
    return 0xfffffd39;
  }
  uVar1 = _objc_msgSend(param_1,PTR_s_deviceDescription_001f9378,PTR_s_numChannels_001f97b4);
  uVar2 = _objc_msgSend(uVar1);
  if (param_4 < uVar2) {
    uVar1 = _objc_msgSend(param_1,PTR_s__localToChannel__001f9688,param_4);
    if (param_3 == 0) {
      uVar3 = 0;
    }
    else if (param_3 == 2) {
      uVar3 = 3;
    }
    else {
      if (param_3 != 3) goto LAB_001c10a4;
      uVar3 = 2;
    }
    _dma_xfer_width(uVar1,uVar3);
    uVar1 = 0;
  }
  else {
LAB_001c10a4:
    uVar1 = 0xfffffd3e;
  }
  return uVar1;
}

