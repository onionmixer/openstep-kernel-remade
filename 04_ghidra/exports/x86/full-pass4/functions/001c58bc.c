/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c58bc */

int FUN_001c58bc(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  long lVar4;
  int iVar5;
  uint uVar6;
  char *pcVar7;
  char *pcVar8;
  char *local_28;
  int local_20;
  int local_1c;
  int local_18;
  long local_14;
  long local_10;
  char *local_c;
  char *local_8;
  
  uVar2 = _objc_msgSend(param_1,PTR_s_deviceDescription_001f9378,PTR_s_configTable_001f9cdc);
  iVar3 = _objc_msgSend(uVar2);
  if ((iVar3 != 0) &&
     ((local_28 = (char *)_objc_msgSend(iVar3,PTR_s_valueForStringKey__001f9308,"Display Mode"),
      local_28 != (char *)0x0 ||
      (local_28 = (char *)_objc_msgSend(iVar3,PTR_s_valueForStringKey__001f9308,"DisplayMode"),
      local_28 != (char *)0x0)))) {
    local_10 = 0;
    local_14 = 0;
    uVar6 = 0xffffffff;
    pcVar7 = "Width:";
    do {
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar1 != '\0');
    pcVar7 = local_28;
    if (*local_28 != '\0') {
LAB_001c595c:
      iVar3 = _strncmp(pcVar7,"Width:",~uVar6 - 1);
      if (iVar3 != 0) goto LAB_001c5994;
      for (pcVar7 = pcVar7 + (~uVar6 - 1);
          (cVar1 = *pcVar7, cVar1 != '\0' && ((cVar1 == ' ' || (cVar1 == '\t'))));
          pcVar7 = pcVar7 + 1) {
      }
      pcVar8 = (char *)0x0;
      if (cVar1 != '\0') {
        pcVar8 = pcVar7;
      }
      goto LAB_001c599c;
    }
LAB_001c599a:
    pcVar8 = (char *)0x0;
LAB_001c599c:
    if (pcVar8 != (char *)0x0) {
      local_10 = _strtol(pcVar8,(char **)0x0,10);
    }
    uVar6 = 0xffffffff;
    pcVar7 = "Height:";
    do {
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar1 != '\0');
    pcVar7 = local_28;
    if (*local_28 != '\0') {
LAB_001c59d0:
      iVar3 = _strncmp(pcVar7,"Height:",~uVar6 - 1);
      if (iVar3 != 0) goto LAB_001c5a08;
      for (pcVar7 = pcVar7 + (~uVar6 - 1);
          (cVar1 = *pcVar7, cVar1 != '\0' && ((cVar1 == ' ' || (cVar1 == '\t'))));
          pcVar7 = pcVar7 + 1) {
      }
      pcVar8 = (char *)0x0;
      if (cVar1 != '\0') {
        pcVar8 = pcVar7;
      }
      goto LAB_001c5a10;
    }
LAB_001c5a0e:
    pcVar8 = (char *)0x0;
LAB_001c5a10:
    if (pcVar8 != (char *)0x0) {
      local_14 = _strtol(pcVar8,(char **)0x0,10);
    }
    uVar6 = 0xffffffff;
    pcVar7 = "Refresh:";
    do {
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar1 != '\0');
    pcVar7 = local_28;
    if (*local_28 != '\0') {
LAB_001c5a44:
      iVar3 = _strncmp(pcVar7,"Refresh:",~uVar6 - 1);
      if (iVar3 != 0) goto LAB_001c5a7c;
      for (pcVar7 = pcVar7 + (~uVar6 - 1);
          (cVar1 = *pcVar7, cVar1 != '\0' && ((cVar1 == ' ' || (cVar1 == '\t'))));
          pcVar7 = pcVar7 + 1) {
      }
      pcVar8 = (char *)0x0;
      if (cVar1 != '\0') {
        pcVar8 = pcVar7;
      }
      goto LAB_001c5a84;
    }
LAB_001c5a82:
    pcVar8 = (char *)0x0;
LAB_001c5a84:
    if (pcVar8 != (char *)0x0) {
      lVar4 = _strtol(pcVar8,(char **)0x0,10);
      uVar6 = 0xffffffff;
      pcVar7 = "ColorSpace:";
      do {
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        cVar1 = *pcVar7;
        pcVar7 = pcVar7 + 1;
      } while (cVar1 != '\0');
      pcVar7 = local_28;
      if (*local_28 != '\0') {
LAB_001c5abc:
        iVar3 = _strncmp(pcVar7,"ColorSpace:",~uVar6 - 1);
        if (iVar3 != 0) goto LAB_001c5af4;
        for (pcVar7 = pcVar7 + (~uVar6 - 1);
            (cVar1 = *pcVar7, cVar1 != '\0' && ((cVar1 == ' ' || (cVar1 == '\t'))));
            pcVar7 = pcVar7 + 1) {
        }
        pcVar8 = (char *)0x0;
        if (cVar1 != '\0') {
          pcVar8 = pcVar7;
        }
        goto LAB_001c5afc;
      }
LAB_001c5afa:
      pcVar8 = (char *)0x0;
LAB_001c5afc:
      if (pcVar8 != (char *)0x0) {
        iVar3 = _strncmp(pcVar8,"BW:2",4);
        if (iVar3 == 0) {
          local_1c = 0;
          local_20 = 0;
        }
        else {
          iVar3 = _strncmp(pcVar8,"BW:8",4);
          if (iVar3 == 0) {
            local_1c = 1;
            local_20 = 1;
          }
          else {
            iVar3 = _strncmp(pcVar8,"RGB:256/8",9);
            if (iVar3 == 0) {
              local_1c = 1;
            }
            else {
              iVar3 = _strncmp(pcVar8,"RGB:444/16",10);
              if (iVar3 == 0) {
                local_1c = 2;
              }
              else {
                iVar3 = _strncmp(pcVar8,"RGB:555/16",10);
                if (iVar3 == 0) {
                  local_1c = 3;
                }
                else {
                  iVar3 = _strncmp(pcVar8,"RGB:888/32",10);
                  if (iVar3 != 0) {
                    return -1;
                  }
                  local_1c = 4;
                }
              }
            }
            local_20 = 2;
          }
        }
        uVar6 = 0xffffffff;
        pcVar7 = "Resolution:";
        do {
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          cVar1 = *pcVar7;
          pcVar7 = pcVar7 + 1;
        } while (cVar1 != '\0');
        pcVar7 = local_28;
        if (*local_28 != '\0') {
LAB_001c5bf8:
          iVar3 = _strncmp(pcVar7,"Resolution:",~uVar6 - 1);
          if (iVar3 != 0) goto LAB_001c5c30;
          for (pcVar7 = pcVar7 + (~uVar6 - 1);
              (cVar1 = *pcVar7, cVar1 != '\0' && ((cVar1 == ' ' || (cVar1 == '\t'))));
              pcVar7 = pcVar7 + 1) {
          }
          pcVar8 = (char *)0x0;
          if (cVar1 != '\0') {
            pcVar8 = pcVar7;
          }
          goto LAB_001c5c38;
        }
LAB_001c5c36:
        pcVar8 = (char *)0x0;
LAB_001c5c38:
        if (pcVar8 != (char *)0x0) {
          local_10 = _strtol(pcVar8,&local_8,10);
          local_14 = _strtol(local_8 + 1,(char **)0x0,10);
        }
        if ((local_14 != 0) && (local_10 != 0)) {
          uVar6 = 0xffffffff;
          pcVar7 = "Screen:";
          do {
            if (uVar6 == 0) break;
            uVar6 = uVar6 - 1;
            cVar1 = *pcVar7;
            pcVar7 = pcVar7 + 1;
          } while (cVar1 != '\0');
          pcVar7 = local_28;
          if (*local_28 != '\0') {
LAB_001c5c98:
            iVar3 = _strncmp(pcVar7,"Screen:",~uVar6 - 1);
            if (iVar3 != 0) goto LAB_001c5cd0;
            for (pcVar7 = pcVar7 + (~uVar6 - 1);
                (cVar1 = *pcVar7, cVar1 != '\0' && ((cVar1 == ' ' || (cVar1 == '\t'))));
                pcVar7 = pcVar7 + 1) {
            }
            pcVar8 = (char *)0x0;
            if (cVar1 != '\0') {
              pcVar8 = pcVar7;
            }
            goto LAB_001c5cd8;
          }
LAB_001c5cd6:
          pcVar8 = (char *)0x0;
LAB_001c5cd8:
          if (pcVar8 != (char *)0x0) {
            _strtol(pcVar8,&local_c,10);
            local_14 = _strtol(local_c + 1,(char **)0x0,10);
          }
          uVar6 = 0xffffffff;
          pcVar7 = "Memory:";
          do {
            if (uVar6 == 0) break;
            uVar6 = uVar6 - 1;
            cVar1 = *pcVar7;
            pcVar7 = pcVar7 + 1;
          } while (cVar1 != '\0');
          pcVar7 = local_28;
          if (*local_28 != '\0') {
LAB_001c5d1c:
            iVar3 = _strncmp(pcVar7,"Memory:",~uVar6 - 1);
            if (iVar3 != 0) goto LAB_001c5d54;
            for (pcVar7 = pcVar7 + (~uVar6 - 1);
                (cVar1 = *pcVar7, cVar1 != '\0' && ((cVar1 == ' ' || (cVar1 == '\t'))));
                pcVar7 = pcVar7 + 1) {
            }
            pcVar8 = (char *)0x0;
            if (cVar1 != '\0') {
              pcVar8 = pcVar7;
            }
            goto LAB_001c5d5c;
          }
LAB_001c5d5a:
          pcVar8 = (char *)0x0;
LAB_001c5d5c:
          if (pcVar8 != (char *)0x0) {
            _strtol(pcVar8,(char **)0x0,10);
          }
          uVar6 = 0xffffffff;
          pcVar7 = "RAMDAC:";
          do {
            if (uVar6 == 0) break;
            uVar6 = uVar6 - 1;
            cVar1 = *pcVar7;
            pcVar7 = pcVar7 + 1;
          } while (cVar1 != '\0');
          pcVar7 = local_28;
          if (*local_28 != '\0') {
LAB_001c5d8c:
            iVar3 = _strncmp(pcVar7,"RAMDAC:",~uVar6 - 1);
            if (iVar3 != 0) goto LAB_001c5dc4;
            for (pcVar7 = pcVar7 + (~uVar6 - 1);
                (cVar1 = *pcVar7, cVar1 != '\0' && ((cVar1 == ' ' || (cVar1 == '\t'))));
                pcVar7 = pcVar7 + 1) {
            }
            pcVar8 = (char *)0x0;
            if (cVar1 != '\0') {
              pcVar8 = pcVar7;
            }
            goto LAB_001c5dcc;
          }
LAB_001c5dca:
          pcVar8 = (char *)0x0;
LAB_001c5dcc:
          if (pcVar8 != (char *)0x0) {
            _strtol(pcVar8,(char **)0x0,10);
          }
          uVar6 = 0xffffffff;
          pcVar7 = "Sync:";
          do {
            if (uVar6 == 0) break;
            uVar6 = uVar6 - 1;
            cVar1 = *pcVar7;
            pcVar7 = pcVar7 + 1;
          } while (cVar1 != '\0');
          pcVar7 = local_28;
          if (*local_28 != '\0') {
LAB_001c5dfc:
            iVar3 = _strncmp(pcVar7,"Sync:",~uVar6 - 1);
            if (iVar3 != 0) goto LAB_001c5e34;
            for (pcVar7 = pcVar7 + (~uVar6 - 1);
                (cVar1 = *pcVar7, cVar1 != '\0' && ((cVar1 == ' ' || (cVar1 == '\t'))));
                pcVar7 = pcVar7 + 1) {
            }
            pcVar8 = (char *)0x0;
            if (cVar1 != '\0') {
              pcVar8 = pcVar7;
            }
            goto LAB_001c5e3c;
          }
LAB_001c5e3a:
          pcVar8 = (char *)0x0;
LAB_001c5e3c:
          if (pcVar8 != (char *)0x0) {
            _strtol(pcVar8,(char **)0x0,10);
          }
          local_18 = 0;
          uVar6 = 0xffffffff;
          pcVar7 = "Available:";
          do {
            if (uVar6 == 0) break;
            uVar6 = uVar6 - 1;
            cVar1 = *pcVar7;
            pcVar7 = pcVar7 + 1;
          } while (cVar1 != '\0');
          cVar1 = *local_28;
          do {
            if (cVar1 == '\0') {
              pcVar7 = (char *)0x0;
LAB_001c5eb4:
              if (pcVar7 != (char *)0x0) {
                local_18 = _strtol(pcVar7,(char **)0x0,10);
              }
              iVar3 = 0;
              if (0 < param_4) {
                iVar5 = 0;
                do {
                  if (((((param_5 == 0) || (*(char *)(iVar3 + param_5) != '\0')) && (local_18 == 0))
                      && ((*(int *)(param_3 + iVar5) == local_10 &&
                          (*(int *)(param_3 + 4 + iVar5) == local_14)))) &&
                     ((*(int *)(param_3 + 0x1c + iVar5) == local_20 &&
                      ((*(int *)(param_3 + 0x18 + iVar5) == local_1c &&
                       (*(int *)(param_3 + 0x10 + iVar5) == lVar4)))))) {
                    switch(local_1c) {
                    case 0:
                      pcVar7 = "BW:2";
                      break;
                    case 1:
                      pcVar7 = "BW:8";
                      if (local_20 == 2) {
                        pcVar7 = "RGB:256/8";
                      }
                      break;
                    case 2:
                      pcVar7 = "RGB:444/16";
                      break;
                    case 3:
                      pcVar7 = "RGB:555/16";
                      break;
                    case 4:
                      pcVar7 = "RGB:888/32";
                      break;
                    default:
                      pcVar7 = "Unknown color space";
                    }
                    _IOLog("Display: Mode selected: %d x %d @ %d Hz (%s)\n",local_10,local_14,lVar4,
                           pcVar7);
                    return iVar3;
                  }
                  iVar5 = iVar5 + 0x88;
                  iVar3 = iVar3 + 1;
                } while (iVar3 < param_4);
              }
              _IOLog("Display: Requested mode is not available.\n");
              return -1;
            }
            iVar3 = _strncmp(local_28,"Available:",~uVar6 - 1);
            if (iVar3 == 0) {
              for (local_28 = local_28 + (~uVar6 - 1);
                  (cVar1 = *local_28, cVar1 != '\0' && ((cVar1 == ' ' || (cVar1 == '\t'))));
                  local_28 = local_28 + 1) {
              }
              pcVar7 = (char *)0x0;
              if (cVar1 != '\0') {
                pcVar7 = local_28;
              }
              goto LAB_001c5eb4;
            }
            local_28 = local_28 + 1;
            cVar1 = *local_28;
          } while( true );
        }
      }
    }
  }
  return -1;
LAB_001c5994:
  pcVar7 = pcVar7 + 1;
  if (*pcVar7 == '\0') goto LAB_001c599a;
  goto LAB_001c595c;
LAB_001c5a08:
  pcVar7 = pcVar7 + 1;
  if (*pcVar7 == '\0') goto LAB_001c5a0e;
  goto LAB_001c59d0;
LAB_001c5a7c:
  pcVar7 = pcVar7 + 1;
  if (*pcVar7 == '\0') goto LAB_001c5a82;
  goto LAB_001c5a44;
LAB_001c5af4:
  pcVar7 = pcVar7 + 1;
  if (*pcVar7 == '\0') goto LAB_001c5afa;
  goto LAB_001c5abc;
LAB_001c5c30:
  pcVar7 = pcVar7 + 1;
  if (*pcVar7 == '\0') goto LAB_001c5c36;
  goto LAB_001c5bf8;
LAB_001c5cd0:
  pcVar7 = pcVar7 + 1;
  if (*pcVar7 == '\0') goto LAB_001c5cd6;
  goto LAB_001c5c98;
LAB_001c5d54:
  pcVar7 = pcVar7 + 1;
  if (*pcVar7 == '\0') goto LAB_001c5d5a;
  goto LAB_001c5d1c;
LAB_001c5dc4:
  pcVar7 = pcVar7 + 1;
  if (*pcVar7 == '\0') goto LAB_001c5dca;
  goto LAB_001c5d8c;
LAB_001c5e34:
  pcVar7 = pcVar7 + 1;
  if (*pcVar7 == '\0') goto LAB_001c5e3a;
  goto LAB_001c5dfc;
}

