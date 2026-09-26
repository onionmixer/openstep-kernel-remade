/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c6a10 */

undefined4
FUN_001c6a10(undefined4 param_1,undefined4 param_2,undefined4 *param_3,char *param_4,int *param_5)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  bool bVar8;
  undefined4 local_18;
  undefined *local_14;
  undefined4 local_10 [3];
  
  iVar1 = *param_5;
  iVar5 = 0x13;
  bVar8 = true;
  pcVar6 = param_4;
  pcVar7 = "IO_Framebuffer_Map";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar8 = *pcVar6 == *pcVar7;
    pcVar6 = pcVar6 + 1;
    pcVar7 = pcVar7 + 1;
  } while (bVar8);
  if (bVar8) {
    *param_3 = 0;
    _objc_msgSend(param_1,PTR_s_enterSVGAMode_001f9594);
    _objc_msgSend(_kmId,PTR_s_registerDisplay__001f9608,param_1);
    *param_5 = 1;
    uVar2 = 0;
  }
  else {
    iVar5 = 0x1a;
    bVar8 = true;
    pcVar6 = param_4;
    pcVar7 = "IO_Framebuffer_Dimensions";
    do {
      if (iVar5 == 0) break;
      iVar5 = iVar5 + -1;
      bVar8 = *pcVar6 == *pcVar7;
      pcVar6 = pcVar6 + 1;
      pcVar7 = pcVar7 + 1;
    } while (bVar8);
    if (bVar8) {
      puVar3 = (undefined4 *)_objc_msgSend(param_1,PTR_s_displayInfo_001f9610);
      local_10[0] = *puVar3;
      local_10[1] = puVar3[1];
      local_10[2] = puVar3[3];
      *param_5 = 0;
      iVar5 = 0;
      do {
        if (*param_5 == iVar1) break;
        param_3[iVar5] = local_10[iVar5];
        *param_5 = *param_5 + 1;
        iVar5 = iVar5 + 1;
      } while (iVar5 < 3);
      uVar2 = 0;
    }
    else {
      iVar5 = 0x18;
      bVar8 = true;
      pcVar6 = param_4;
      pcVar7 = "IO_Framebuffer_Register";
      do {
        if (iVar5 == 0) break;
        iVar5 = iVar5 + -1;
        bVar8 = *pcVar6 == *pcVar7;
        pcVar6 = pcVar6 + 1;
        pcVar7 = pcVar7 + 1;
      } while (bVar8);
      if (bVar8) {
        uVar2 = _objc_msgSend(param_1,PTR_s__registerWithED_001f9604);
        *param_5 = 0;
        if (iVar1 != 0) {
          *param_5 = 1;
          uVar4 = _objc_msgSend(param_1,PTR_s_token_001f9600);
          *param_3 = uVar4;
        }
      }
      else {
        local_18 = param_1;
        local_14 = PTR_s_IODisplay_001fa630;
        uVar2 = _objc_msgSendSuper(&local_18,PTR_s_getIntValues_forParameter_count__001f9528,param_3
                                   ,param_4,param_5);
      }
    }
  }
  return uVar2;
}

