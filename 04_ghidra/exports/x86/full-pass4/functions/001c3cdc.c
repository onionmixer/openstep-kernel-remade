/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c3cdc */

undefined4 FUN_001c3cdc(int param_1,undefined4 param_2,int *param_3,char *param_4,int *param_5)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  char *pcVar9;
  bool bVar10;
  int local_20;
  undefined *local_1c;
  int local_18 [5];
  
  iVar3 = *param_5;
  iVar7 = 0x13;
  bVar10 = true;
  pcVar4 = param_4;
  pcVar9 = "IO_Framebuffer_Map";
  do {
    if (iVar7 == 0) break;
    iVar7 = iVar7 + -1;
    bVar10 = *pcVar4 == *pcVar9;
    pcVar4 = pcVar4 + 1;
    pcVar9 = pcVar9 + 1;
  } while (bVar10);
  if (bVar10) {
    *param_3 = 0;
    _objc_msgSend(param_1,PTR_s_revertToVGAMode_001f94a8);
    _objc_msgSend(param_1,PTR_s_enterLinearMode_001f960c);
    _objc_msgSend(_kmId,PTR_s_registerDisplay__001f9608,param_1);
    *param_5 = 1;
    return 0;
  }
  iVar7 = 0x1a;
  bVar10 = true;
  pcVar4 = param_4;
  pcVar9 = "IO_Framebuffer_Dimensions";
  do {
    if (iVar7 == 0) break;
    iVar7 = iVar7 + -1;
    bVar10 = *pcVar4 == *pcVar9;
    pcVar4 = pcVar4 + 1;
    pcVar9 = pcVar9 + 1;
  } while (bVar10);
  if (bVar10) {
    piVar2 = (int *)_objc_msgSend(param_1,PTR_s_displayInfo_001f9610);
    local_18[0] = *piVar2;
    local_18[1] = piVar2[1];
    local_18[2] = piVar2[3];
    local_18[4] = piVar2[0x18];
    switch(piVar2[6]) {
    case 0:
      local_18[3] = 2;
      break;
    case 1:
      local_18[3] = 8;
      break;
    case 2:
      local_18[3] = 0xc;
      break;
    case 3:
      local_18[3] = 0xf;
      break;
    case 4:
      local_18[3] = 0x20;
    }
    *param_5 = 0;
    iVar7 = 0;
    do {
      if (*param_5 == iVar3) break;
      param_3[iVar7] = local_18[iVar7];
      *param_5 = *param_5 + 1;
      iVar7 = iVar7 + 1;
    } while (iVar7 < 5);
LAB_001c410a:
    uVar6 = 0;
  }
  else {
    iVar7 = 0x18;
    bVar10 = true;
    pcVar4 = param_4;
    pcVar9 = "IO_Framebuffer_Register";
    do {
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      bVar10 = *pcVar4 == *pcVar9;
      pcVar4 = pcVar4 + 1;
      pcVar9 = pcVar9 + 1;
    } while (bVar10);
    if (bVar10) {
      uVar6 = _objc_msgSend(param_1,PTR_s__registerWithED_001f9604);
      *param_5 = 0;
      if (iVar3 != 0) {
        *param_5 = 1;
        iVar3 = _objc_msgSend(param_1,PTR_s_token_001f9600);
        *param_3 = iVar3;
        return uVar6;
      }
      return uVar6;
    }
    iVar7 = 0x11;
    bVar10 = true;
    pcVar4 = param_4;
    pcVar9 = "IOGetDisplayInfo";
    do {
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      bVar10 = *pcVar4 == *pcVar9;
      pcVar4 = pcVar4 + 1;
      pcVar9 = pcVar9 + 1;
    } while (bVar10);
    if (bVar10) {
      if ((iVar3 == 5) || (iVar3 == 7)) {
        piVar2 = (int *)_objc_msgSend(param_1,PTR_s_displayInfo_001f9610);
        *param_3 = *piVar2;
        param_3[1] = piVar2[1];
        param_3[2] = piVar2[4];
        param_3[3] = piVar2[6];
        param_3[4] = piVar2[7];
        if (*param_5 == 7) {
          param_3[5] = piVar2[2];
          param_3[6] = piVar2[3];
        }
        goto LAB_001c410a;
      }
    }
    else {
      iVar7 = 0x14;
      bVar10 = true;
      pcVar4 = param_4;
      pcVar9 = "IOGetDisplayModeNum";
      do {
        if (iVar7 == 0) break;
        iVar7 = iVar7 + -1;
        bVar10 = *pcVar4 == *pcVar9;
        pcVar4 = pcVar4 + 1;
        pcVar9 = pcVar9 + 1;
      } while (bVar10);
      if (bVar10) {
        if (iVar3 == 1) {
          iVar3 = _objc_msgSend(param_1,PTR_s_displayModeCount_001f95fc);
          *param_3 = iVar3;
          return 0;
        }
      }
      else {
        iVar3 = _strncmp(param_4,"IOGetDisplayModeInfo:",0x15);
        if (iVar3 == 0) {
          if (*param_5 == 0xe) {
            uVar8 = 0xffffffff;
            pcVar4 = "IOGetDisplayModeInfo:";
            do {
              if (uVar8 == 0) break;
              uVar8 = uVar8 - 1;
              cVar1 = *pcVar4;
              pcVar4 = pcVar4 + 1;
            } while (cVar1 != '\0');
            if (*param_4 != '\0') {
LAB_001c3f70:
              iVar3 = _strncmp(param_4,"IOGetDisplayModeInfo:",~uVar8 - 1);
              if (iVar3 != 0) goto LAB_001c3fa8;
              for (param_4 = param_4 + (~uVar8 - 1);
                  (cVar1 = *param_4, cVar1 != '\0' && ((cVar1 == ' ' || (cVar1 == '\t'))));
                  param_4 = param_4 + 1) {
              }
              pcVar4 = (char *)0x0;
              if (cVar1 != '\0') {
                pcVar4 = param_4;
              }
              goto LAB_001c3fb0;
            }
LAB_001c3fae:
            pcVar4 = (char *)0x0;
LAB_001c3fb0:
            if (((pcVar4 != (char *)0x0) &&
                (uVar8 = _strtol(pcVar4,(char **)0x0,10), -1 < (int)uVar8)) &&
               (uVar5 = _objc_msgSend(param_1,PTR_s_displayModeCount_001f95fc), uVar8 < uVar5)) {
              iVar3 = _objc_msgSend(param_1,PTR_s_displayModes_001f95f8);
              piVar2 = (int *)(iVar3 + uVar8 * 0x88);
              *param_3 = *piVar2;
              param_3[1] = piVar2[1];
              param_3[2] = piVar2[4];
              param_3[3] = piVar2[6];
              param_3[4] = piVar2[7];
              param_3[5] = piVar2[2];
              param_3[6] = piVar2[3];
              param_3[7] = piVar2[0x1a];
              param_3[8] = piVar2[0x1b];
              param_3[9] = 0;
              param_3[10] = piVar2[0x1d];
              param_3[0xb] = piVar2[0x1e];
              param_3[0xc] = piVar2[0x1f];
              param_3[0xd] = piVar2[0x20];
              return 0;
            }
          }
        }
        else {
          iVar3 = 0x13;
          bVar10 = true;
          pcVar4 = param_4;
          pcVar9 = "IOGetDisplayMemory";
          do {
            if (iVar3 == 0) break;
            iVar3 = iVar3 + -1;
            bVar10 = *pcVar4 == *pcVar9;
            pcVar4 = pcVar4 + 1;
            pcVar9 = pcVar9 + 1;
          } while (bVar10);
          if (bVar10) {
            if (*param_5 == 1) {
              iVar3 = _objc_msgSend(param_1,PTR_s_displayMemorySize_001f95f4);
              *param_3 = iVar3;
              return 0;
            }
          }
          else {
            iVar3 = 0x11;
            bVar10 = true;
            pcVar4 = param_4;
            pcVar9 = "IOGetRAMDACSpeed";
            do {
              if (iVar3 == 0) break;
              iVar3 = iVar3 + -1;
              bVar10 = *pcVar4 == *pcVar9;
              pcVar4 = pcVar4 + 1;
              pcVar9 = pcVar9 + 1;
            } while (bVar10);
            if (bVar10) {
              if (*param_5 == 1) {
                iVar3 = _objc_msgSend(param_1,PTR_s_ramdacSpeed_001f95f0);
                *param_3 = iVar3;
                return 0;
              }
            }
            else {
              iVar3 = 0x18;
              bVar10 = true;
              pcVar4 = param_4;
              pcVar9 = "IOGetCurrentDisplayMode";
              do {
                if (iVar3 == 0) break;
                iVar3 = iVar3 + -1;
                bVar10 = *pcVar4 == *pcVar9;
                pcVar4 = pcVar4 + 1;
                pcVar9 = pcVar9 + 1;
              } while (bVar10);
              if (bVar10) {
                if (*param_5 == 1) {
                  if (*(int *)(param_1 + 0x210) < 0) {
                    return 0xfffffd12;
                  }
                  *param_3 = *(int *)(param_1 + 0x210);
                  goto LAB_001c410a;
                }
              }
              else {
                iVar3 = 0x18;
                bVar10 = true;
                pcVar4 = param_4;
                pcVar9 = "IOGetPendingDisplayMode";
                do {
                  if (iVar3 == 0) break;
                  iVar3 = iVar3 + -1;
                  bVar10 = *pcVar4 == *pcVar9;
                  pcVar4 = pcVar4 + 1;
                  pcVar9 = pcVar9 + 1;
                } while (bVar10);
                if (!bVar10) {
                  local_20 = param_1;
                  local_1c = PTR_s_IODisplay_001fa608;
                  uVar6 = _objc_msgSendSuper(&local_20,
                                             PTR_s_getIntValues_forParameter_count__001f9528,param_3
                                             ,param_4,param_5);
                  return uVar6;
                }
                if (*param_5 == 1) {
                  if (*(int *)(param_1 + 0x214) < 0) {
                    return 0xfffffd12;
                  }
                  *param_3 = *(int *)(param_1 + 0x214);
                  goto LAB_001c410a;
                }
              }
            }
          }
        }
      }
    }
    uVar6 = 0xfffffd3e;
  }
  return uVar6;
LAB_001c3fa8:
  param_4 = param_4 + 1;
  if (*param_4 == '\0') goto LAB_001c3fae;
  goto LAB_001c3f70;
}

