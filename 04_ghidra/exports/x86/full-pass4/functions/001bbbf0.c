/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001bbbf0 */

undefined4 __NXAudioRemoveStream(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 != 0) {
    uVar1 = _objc_msgSend(param_1,PTR_s_channel_001f97b0,PTR_s_removeStream__001f9760,param_1);
    _objc_msgSend(uVar1);
    return 0;
  }
  return 0xca;
}

