/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001bb308 */

void _audioMessages(int param_1,int param_2)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  
  if (*(int *)(param_1 + 0xc) == 0) {
    iVar1 = FUN_001bae88(param_1,param_2);
    if (iVar1 != 0) goto LAB_001bb377;
    uVar3 = *(undefined4 *)(param_1 + 0x14);
    pcVar2 = "Audio: unrecognized control message %d\n";
  }
  else if (*(int *)(param_1 + 0x14) < 700) {
    iVar1 = _snd_server(param_1,param_2);
    if (iVar1 != 0) goto LAB_001bb377;
    uVar3 = *(undefined4 *)(param_1 + 0x14);
    pcVar2 = "Audio: unrecognized snd user message %d\n";
  }
  else {
    iVar1 = _audio_server(param_1,param_2);
    if (iVar1 != 0) goto LAB_001bb377;
    uVar3 = *(undefined4 *)(param_1 + 0x14);
    pcVar2 = "Audio: unrecognized audio user message %d\n";
  }
  _IOLog(pcVar2,uVar3);
LAB_001bb377:
  iVar1 = _msg_send(param_2,1,1000);
  if (iVar1 != 0) {
    _IOLog("msg_send failed %d\n",iVar1);
  }
  *(undefined4 *)(param_2 + 0x1c) = 0xfffffecf;
  return;
}

