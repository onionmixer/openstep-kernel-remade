/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001af0f0 */

undefined4
FUN_001af0f0(undefined4 param_1,undefined4 param_2,undefined4 *param_3,char *param_4,int *param_5)

{
  undefined4 uVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  bool bVar5;
  undefined4 local_c;
  undefined *local_8;
  
  iVar2 = 0x11;
  bVar5 = true;
  pcVar3 = param_4;
  pcVar4 = "IOGetDisplayPort";
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar5 = *pcVar3 == *pcVar4;
    pcVar3 = pcVar3 + 1;
    pcVar4 = pcVar4 + 1;
  } while (bVar5);
  if (!bVar5) {
    iVar2 = 0x13;
    bVar5 = true;
    pcVar3 = param_4;
    pcVar4 = "IO_Display_GetPort";
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar5 = *pcVar3 == *pcVar4;
      pcVar3 = pcVar3 + 1;
      pcVar4 = pcVar4 + 1;
    } while (bVar5);
    if (!bVar5) {
      local_c = param_1;
      local_8 = PTR_s_IODirectDevice_001fa3d8;
      uVar1 = _objc_msgSendSuper(&local_c,PTR_s_getIntValues_forParameter_count__001f9528,param_3,
                                 param_4,param_5);
      return uVar1;
    }
  }
  if (*param_5 == 0) {
    uVar1 = 0xfffffd3e;
  }
  else {
    uVar1 = _objc_msgSend(param_1,PTR_s_devicePort_001f9a48);
    uVar1 = _IOConvertPort(uVar1,1,2);
    *param_3 = uVar1;
    *param_5 = 1;
    uVar1 = 0;
  }
  return uVar1;
}

