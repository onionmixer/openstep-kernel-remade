/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001bd310 */

undefined4 _snd_server(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 local_8;
  
  local_8 = 1;
  iVar2 = 0;
  *(undefined1 *)(param_2 + 3) = 1;
  *(undefined4 *)(param_2 + 4) = 0x18;
  *(undefined4 *)(param_2 + 8) = 0;
  *(undefined4 *)(param_2 + 0xc) = 0;
  *(undefined4 *)(param_2 + 0x10) = 0;
  *(undefined4 *)(param_2 + 0x14) = 0;
  uVar1 = *(uint *)(param_1 + 0x14);
  if (uVar1 < 2) {
    iVar2 = FUN_001bc56c(param_1,param_2);
  }
  else if (uVar1 - 100 < 0x11) {
    iVar2 = FUN_001bcad4(param_1,param_2);
  }
  else if (uVar1 - 200 < 8) {
    _IOLog("Audio: received dsp cmd port msg!\n");
    _audio_snd_reply_illegal_msg
              (param_2,0,*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x14),0x66);
    local_8 = 0;
  }
  else {
    _audio_snd_reply_illegal_msg(param_2,0,*(undefined4 *)(param_1 + 0x10),uVar1,0x66);
    local_8 = 0;
  }
  if (iVar2 != 0) {
    _audio_snd_reply_illegal_msg
              (param_2,0,*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x14),iVar2);
  }
  return local_8;
}

