/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b7150 */

void FUN_001b7150(int param_1,undefined4 param_2,char param_3)

{
  undefined4 uVar1;
  
  if (DAT_001e5380 != param_3) {
    if (param_3 == '\0') {
      uVar1 = _objc_msgSend(*(undefined4 *)(param_1 + 0x128),PTR_s_localChannel_001f9894,1);
      _objc_msgSend(param_1,PTR_s_stopDMAForChannel_read__001f986c,uVar1);
    }
    else {
      DAT_001e5384 = 0;
      DAT_001e5388 = _objc_msgSend(*(undefined4 *)(param_1 + 0x128),PTR_s_descriptorSize_001f988c);
      DAT_001e538c = _objc_msgSend(param_1,PTR_s_interruptClearFunc_001f97d8);
      uVar1 = _objc_msgSend(*(undefined4 *)(param_1 + 0x128),PTR_s_channelBuffer_001f9890,
                            DAT_001e5388);
      uVar1 = _objc_msgSend(*(undefined4 *)(param_1 + 0x128),PTR_s_localChannel_001f9894,1,uVar1);
      _objc_msgSend(param_1,PTR_s_startDMAForChannel_read_buffer_b_001f9888,uVar1);
    }
    DAT_001e5380 = param_3;
  }
  return;
}

