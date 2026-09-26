/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c0e04 */

undefined4 FUN_001c0e04(int param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar1 = _objc_msgSend(*(undefined4 *)(param_1 + 0x108),PTR_s_numChannels_001f97b4);
  if (param_4 < uVar1) {
    uVar2 = _objc_msgSend(param_1,PTR_s__localToChannel__001f9688,param_4);
    iVar3 = _dma_xfer_chan(uVar2,param_3);
    if (iVar3 == 0) {
      uVar2 = 0xfffffd20;
    }
    else {
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 0xfffffd3e;
  }
  return uVar2;
}

