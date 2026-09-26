/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c43dc */

int FUN_001c43dc(int param_1,undefined4 param_2,int param_3,int param_4,int param_5,char *param_6)

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
  
  *(int *)(param_1 + 0x218) = param_4;
  *(int *)(param_1 + 0x21c) = param_3;
  if (param_6 == (char *)0x0) {
    uVar2 = _objc_msgSend(param_1,PTR_s_deviceDescription_001f9378,PTR_s_configTable_001f9cdc);
    iVar3 = _objc_msgSend(uVar2);
    if (iVar3 == 0) {
      return -1;
    }
    local_28 = (char *)_objc_msgSend(iVar3,PTR_s_valueForStringKey__001f9308,"Display Mode");
    if ((local_28 == (char *)0x0) &&
       (local_28 = (char *)_objc_msgSend(iVar3,PTR_s_valueForStringKey__001f9308,"DisplayMode"),
       local_28 == (char *)0x0)) {
      return -1;
    }
  }
  else {
    local_28 = param_6;
  }
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
LAB_001c449c:
    iVar3 = _strncmp(pcVar7,"Width:",~uVar6 - 1);
    if (iVar3 != 0) goto LAB_001c44d4;
    for (pcVar7 = pcVar7 + (~uVar6 - 1);
        (cVar1 = *pcVar7, cVar1 != '\0' && ((cVar1 == ' ' || (cVar1 == '\t')))); pcVar7 = pcVar7 + 1
        ) {
    }
    pcVar8 = (char *)0x0;
    if (cVar1 != '\0') {
      pcVar8 = pcVar7;
    }
    goto LAB_001c44dc;
  }
LAB_001c44da:
  pcVar8 = (char *)0x0;
LAB_001c44dc:
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
LAB_001c4510:
    iVar3 = _strncmp(pcVar7,"Height:",~uVar6 - 1);
    if (iVar3 != 0) goto LAB_001c4548;
    for (pcVar7 = pcVar7 + (~uVar6 - 1);
        (cVar1 = *pcVar7, cVar1 != '\0' && ((cVar1 == ' ' || (cVar1 == '\t')))); pcVar7 = pcVar7 + 1
        ) {
    }
    pcVar8 = (char *)0x0;
    if (cVar1 != '\0') {
      pcVar8 = pcVar7;
    }
    goto LAB_001c4550;
  }
LAB_001c454e:
  pcVar8 = (char *)0x0;
LAB_001c4550:
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
LAB_001c4584:
    iVar3 = _strncmp(pcVar7,"Refresh:",~uVar6 - 1);
    if (iVar3 != 0) goto LAB_001c45bc;
    for (pcVar7 = pcVar7 + (~uVar6 - 1);
        (cVar1 = *pcVar7, cVar1 != '\0' && ((cVar1 == ' ' || (cVar1 == '\t')))); pcVar7 = pcVar7 + 1
        ) {
    }
    pcVar8 = (char *)0x0;
    if (cVar1 != '\0') {
      pcVar8 = pcVar7;
    }
    goto LAB_001c45c4;
  }
LAB_001c45c2:
  pcVar8 = (char *)0x0;
LAB_001c45c4:
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
LAB_001c45fc:
      iVar3 = _strncmp(pcVar7,"ColorSpace:",~uVar6 - 1);
      if (iVar3 != 0) goto LAB_001c4634;
      for (pcVar7 = pcVar7 + (~uVar6 - 1);
          (cVar1 = *pcVar7, cVar1 != '\0' && ((cVar1 == ' ' || (cVar1 == '\t'))));
          pcVar7 = pcVar7 + 1) {
      }
      pcVar8 = (char *)0x0;
      if (cVar1 != '\0') {
        pcVar8 = pcVar7;
      }
      goto LAB_001c463c;
    }
LAB_001c463a:
    pcVar8 = (char *)0x0;
LAB_001c463c:
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
LAB_001c4738:
        iVar3 = _strncmp(pcVar7,"Resolution:",~uVar6 - 1);
        if (iVar3 != 0) goto LAB_001c4770;
        for (pcVar7 = pcVar7 + (~uVar6 - 1);
            (cVar1 = *pcVar7, cVar1 != '\0' && ((cVar1 == ' ' || (cVar1 == '\t'))));
            pcVar7 = pcVar7 + 1) {
        }
        pcVar8 = (char *)0x0;
        if (cVar1 != '\0') {
          pcVar8 = pcVar7;
        }
        goto LAB_001c4778;
      }
LAB_001c4776:
      pcVar8 = (char *)0x0;
LAB_001c4778:
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
LAB_001c47d4:
          iVar3 = _strncmp(pcVar7,"Screen:",~uVar6 - 1);
          if (iVar3 != 0) goto LAB_001c480c;
          for (pcVar7 = pcVar7 + (~uVar6 - 1);
              (cVar1 = *pcVar7, cVar1 != '\0' && ((cVar1 == ' ' || (cVar1 == '\t'))));
              pcVar7 = pcVar7 + 1) {
          }
          pcVar8 = (char *)0x0;
          if (cVar1 != '\0') {
            pcVar8 = pcVar7;
          }
          goto LAB_001c4814;
        }
LAB_001c4812:
        pcVar8 = (char *)0x0;
LAB_001c4814:
        if (pcVar8 != (char *)0x0) {
          _strtol(pcVar8,&local_c,10);
          _strtol(local_c + 1,(char **)0x0,10);
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
LAB_001c4854:
          iVar3 = _strncmp(pcVar7,"Memory:",~uVar6 - 1);
          if (iVar3 != 0) goto LAB_001c488c;
          for (pcVar7 = pcVar7 + (~uVar6 - 1);
              (cVar1 = *pcVar7, cVar1 != '\0' && ((cVar1 == ' ' || (cVar1 == '\t'))));
              pcVar7 = pcVar7 + 1) {
          }
          pcVar8 = (char *)0x0;
          if (cVar1 != '\0') {
            pcVar8 = pcVar7;
          }
          goto LAB_001c4894;
        }
LAB_001c4892:
        pcVar8 = (char *)0x0;
LAB_001c4894:
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
LAB_001c48c4:
          iVar3 = _strncmp(pcVar7,"RAMDAC:",~uVar6 - 1);
          if (iVar3 != 0) goto LAB_001c48fc;
          for (pcVar7 = pcVar7 + (~uVar6 - 1);
              (cVar1 = *pcVar7, cVar1 != '\0' && ((cVar1 == ' ' || (cVar1 == '\t'))));
              pcVar7 = pcVar7 + 1) {
          }
          pcVar8 = (char *)0x0;
          if (cVar1 != '\0') {
            pcVar8 = pcVar7;
          }
          goto LAB_001c4904;
        }
LAB_001c4902:
        pcVar8 = (char *)0x0;
LAB_001c4904:
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
LAB_001c4934:
          iVar3 = _strncmp(pcVar7,"Sync:",~uVar6 - 1);
          if (iVar3 != 0) goto LAB_001c496c;
          for (pcVar7 = pcVar7 + (~uVar6 - 1);
              (cVar1 = *pcVar7, cVar1 != '\0' && ((cVar1 == ' ' || (cVar1 == '\t'))));
              pcVar7 = pcVar7 + 1) {
          }
          pcVar8 = (char *)0x0;
          if (cVar1 != '\0') {
            pcVar8 = pcVar7;
          }
          goto LAB_001c4974;
        }
LAB_001c4972:
        pcVar8 = (char *)0x0;
LAB_001c4974:
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
LAB_001c49ec:
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
                  *(int *)(param_1 + 0x210) = iVar3;
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
            goto LAB_001c49ec;
          }
          local_28 = local_28 + 1;
          cVar1 = *local_28;
        } while( true );
      }
    }
  }
  return -1;
LAB_001c44d4:
  pcVar7 = pcVar7 + 1;
  if (*pcVar7 == '\0') goto LAB_001c44da;
  goto LAB_001c449c;
LAB_001c4548:
  pcVar7 = pcVar7 + 1;
  if (*pcVar7 == '\0') goto LAB_001c454e;
  goto LAB_001c4510;
LAB_001c45bc:
  pcVar7 = pcVar7 + 1;
  if (*pcVar7 == '\0') goto LAB_001c45c2;
  goto LAB_001c4584;
LAB_001c4634:
  pcVar7 = pcVar7 + 1;
  if (*pcVar7 == '\0') goto LAB_001c463a;
  goto LAB_001c45fc;
LAB_001c4770:
  pcVar7 = pcVar7 + 1;
  if (*pcVar7 == '\0') goto LAB_001c4776;
  goto LAB_001c4738;
LAB_001c480c:
  pcVar7 = pcVar7 + 1;
  if (*pcVar7 == '\0') goto LAB_001c4812;
  goto LAB_001c47d4;
LAB_001c488c:
  pcVar7 = pcVar7 + 1;
  if (*pcVar7 == '\0') goto LAB_001c4892;
  goto LAB_001c4854;
LAB_001c48fc:
  pcVar7 = pcVar7 + 1;
  if (*pcVar7 == '\0') goto LAB_001c4902;
  goto LAB_001c48c4;
LAB_001c496c:
  pcVar7 = pcVar7 + 1;
  if (*pcVar7 == '\0') goto LAB_001c4972;
  goto LAB_001c4934;
}

