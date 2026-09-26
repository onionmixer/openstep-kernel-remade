/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c0bd4 */

undefined4 FUN_001c0bd4(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 unaff_EBX;
  
  uVar1 = _objc_msgSend(*(undefined4 *)(param_1 + 0x108),PTR_s_numChannels_001f97b4);
  if (param_4 < uVar1) {
    uVar2 = _objc_msgSend(param_1,PTR_s__localToChannel__001f9688,param_4);
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
    _dma_chan_xfer_mode(uVar2,unaff_EBX);
    uVar2 = 0;
  }
  else {
    uVar2 = 0xfffffd3e;
  }
  return uVar2;
}

