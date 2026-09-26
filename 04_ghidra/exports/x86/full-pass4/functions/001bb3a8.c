/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001bb3a8 */

int _audio_port_to_device(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = _objc_msgSend(PTR_s_IOAudio_001f9dbc,PTR_s__channelForUserPort__001f96f4,param_1);
  if (iVar1 == 0) {
    _IOLog("Audio: server can\'t translate port to channel\n");
    return 0;
  }
  return iVar1;
}

