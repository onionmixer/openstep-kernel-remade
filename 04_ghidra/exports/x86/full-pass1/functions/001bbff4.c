/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001bbff4 */

undefined4
__NXAudioPlayStreamData
          (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
          undefined4 param_6)

{
  char cVar1;
  
  if (param_1 == 0) {
    return 0xca;
  }
  cVar1 = _objc_msgSend(param_1,PTR_s_playBuffer_size_tag_replyTo_repl_001f96c8,param_2,param_3,
                        param_4,param_5,param_6);
  if (cVar1 == '\0') {
    return 0xcc;
  }
  return 0;
}

