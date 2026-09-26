/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c4ecc */

undefined4 FUN_001c4ecc(int param_1,undefined4 param_2,char *param_3,char *param_4,int *param_5)

{
  undefined4 uVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  bool bVar5;
  size_t sVar6;
  int local_c;
  undefined *local_8;
  
  iVar2 = 0x1e;
  bVar5 = true;
  pcVar3 = param_4;
  pcVar4 = "IO_Framebuffer_Pixel_Encoding";
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar5 = *pcVar3 == *pcVar4;
    pcVar3 = pcVar3 + 1;
    pcVar4 = pcVar4 + 1;
  } while (bVar5);
  if (bVar5) {
    if (*param_5 == 0x40) {
      sVar6 = 0x40;
      iVar2 = _objc_msgSend(param_1,PTR_s_displayInfo_001f9610);
      _strncpy(param_3,(char *)(iVar2 + 0x20),sVar6);
      uVar1 = 0;
    }
    else {
      uVar1 = 0xfffffd3e;
    }
  }
  else {
    iVar2 = 0x12;
    bVar5 = true;
    pcVar3 = param_4;
    pcVar4 = "PostScript Driver";
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar5 = *pcVar3 == *pcVar4;
      pcVar3 = pcVar3 + 1;
      pcVar4 = pcVar4 + 1;
    } while (bVar5);
    if (bVar5) {
      if (-1 < *(int *)(param_1 + 0x214)) {
        _objc_msgSend(param_1,PTR_s__commitToPendingMode_001f95e4);
        *(undefined4 *)(param_1 + 0x214) = 0xffffffff;
      }
      local_c = param_1;
      local_8 = PTR_s_IODisplay_001fa608;
      uVar1 = _objc_msgSendSuper(&local_c,PTR_s_getCharValues_forParameter_count_001f9530,param_3,
                                 param_4,param_5);
    }
    else {
      local_c = param_1;
      local_8 = PTR_s_IODisplay_001fa608;
      uVar1 = _objc_msgSendSuper(&local_c,PTR_s_getCharValues_forParameter_count_001f9530,param_3,
                                 param_4,param_5);
    }
  }
  return uVar1;
}

