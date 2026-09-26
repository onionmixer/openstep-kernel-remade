/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001bc088 */

undefined4 __NXAudioGetDeviceName(int param_1,char *param_2,int *param_3)

{
  char cVar1;
  undefined4 uVar2;
  char *pcVar3;
  uint uVar4;
  size_t sVar5;
  
  if (param_1 == 0) {
    uVar2 = 0xca;
  }
  else {
    sVar5 = 0xff;
    uVar2 = _objc_msgSend(PTR_s_IOAudio_001f9dbc,PTR_s__instance_001f97c8,PTR_s_name_001f9228);
    pcVar3 = (char *)_objc_msgSend(uVar2);
    _strncpy(param_2,pcVar3,sVar5);
    param_2[0xff] = '\0';
    uVar4 = 0xffffffff;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *param_2;
      param_2 = param_2 + 1;
    } while (cVar1 != '\0');
    *param_3 = ~uVar4 - 1;
    uVar2 = 0;
  }
  return uVar2;
}

