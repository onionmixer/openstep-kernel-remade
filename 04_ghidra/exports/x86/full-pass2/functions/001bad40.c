/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001bad40 */

bool _audio_enroll_stream_port(undefined4 param_1,int param_2)

{
  int iVar1;
  
  if (param_2 == 0) {
    _kern_serv_port_gone(DAT_001e8718,param_1);
    iVar1 = 0;
  }
  else {
    iVar1 = _kern_serv_port_serv(DAT_001e8718,param_1,_audioMessages,param_1);
    if (iVar1 != 0) {
      _IOLog("Audio: kern_serv_port_serv returns %d\n",iVar1);
    }
  }
  return iVar1 == 0;
}

