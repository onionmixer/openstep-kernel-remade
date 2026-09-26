/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c85b4 */

undefined4
FUN_001c85b4(int param_1,undefined4 param_2,undefined4 param_3,char *param_4,undefined4 param_5)

{
  undefined4 uVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  bool bVar5;
  int local_c;
  undefined *local_8;
  
  if (*(char *)(param_1 + 0x250) != '\0') {
    uVar1 = _objc_msgSend(param_1,PTR_s_name_001f9228,param_4);
    _IOLog("%s: received parameter `%s\'.\n",uVar1);
  }
  iVar2 = 0x14;
  bVar5 = true;
  pcVar3 = param_4;
  pcVar4 = "VPGetVPCodeFilename";
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar5 = *pcVar3 == *pcVar4;
    pcVar3 = pcVar3 + 1;
    pcVar4 = pcVar4 + 1;
  } while (bVar5);
  if (bVar5) {
    iVar2 = _objc_msgSend(param_1,PTR_s_getVPCodeFilename_count__001f9574,param_3,param_5);
    if (iVar2 == 0) {
      uVar1 = 0xfffffd39;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    local_c = param_1;
    local_8 = PTR_s_IOFrameBufferDisplay_001fa658;
    uVar1 = _objc_msgSendSuper(&local_c,PTR_s_getCharValues_forParameter_count_001f9530,param_3,
                               param_4,param_5);
  }
  return uVar1;
}

