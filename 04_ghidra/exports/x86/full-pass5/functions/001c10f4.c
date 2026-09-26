/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c10f4 */

undefined4 FUN_001c10f4(undefined4 param_1,undefined4 param_2,undefined4 *param_3,uint param_4)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  
  uVar1 = _objc_msgSend(param_1,PTR_s_deviceDescription_001f9378,PTR_s_numChannels_001f97b4);
  uVar2 = _objc_msgSend(uVar1);
  if (uVar2 <= param_4) {
    return 0xfffffd3e;
  }
  uVar1 = _objc_msgSend(param_1,PTR_s__localToChannel__001f9688,param_4);
  iVar3 = _get_dma_xfer_width(uVar1);
  if (iVar3 == 1) {
    *param_3 = 1;
  }
  else if (iVar3 < 2) {
    if (iVar3 != 0) {
      return 0xfffffd27;
    }
    *param_3 = 0;
  }
  else if (iVar3 == 2) {
    *param_3 = 3;
  }
  else {
    if (iVar3 != 3) {
      return 0xfffffd27;
    }
    *param_3 = 2;
  }
  return 0;
}

