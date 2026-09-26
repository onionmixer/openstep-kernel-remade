/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c7bac */

int FUN_001c7bac(int param_1,undefined4 param_2,char *param_3,uint *param_4)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  long lVar6;
  long lVar7;
  long lVar8;
  uint uVar9;
  char *pcVar10;
  char *pcVar11;
  char local_104 [256];
  
  uVar2 = _objc_msgSend(param_1,PTR_s_deviceDescription_001f9378,PTR_s_configTable_001f9cdc);
  iVar3 = _objc_msgSend(uVar2);
  if (iVar3 != 0) {
    pcVar4 = (char *)_objc_msgSend(iVar3,PTR_s_valueForStringKey__001f9308,"Display Mode");
    uVar9 = 0xffffffff;
    pcVar10 = "Width:";
    do {
      if (uVar9 == 0) break;
      uVar9 = uVar9 - 1;
      cVar1 = *pcVar10;
      pcVar10 = pcVar10 + 1;
    } while (cVar1 != '\0');
    pcVar10 = pcVar4;
    if (*pcVar4 != '\0') {
LAB_001c7c2c:
      iVar5 = _strncmp(pcVar10,"Width:",~uVar9 - 1);
      if (iVar5 != 0) goto LAB_001c7c64;
      for (pcVar10 = pcVar10 + (~uVar9 - 1);
          (cVar1 = *pcVar10, cVar1 != '\0' && ((cVar1 == ' ' || (cVar1 == '\t'))));
          pcVar10 = pcVar10 + 1) {
      }
      pcVar11 = (char *)0x0;
      if (cVar1 != '\0') {
        pcVar11 = pcVar10;
      }
      goto LAB_001c7c6c;
    }
LAB_001c7c6a:
    pcVar11 = (char *)0x0;
LAB_001c7c6c:
    if (pcVar11 != (char *)0x0) {
      lVar6 = _strtol(pcVar11,(char **)0x0,10);
      uVar9 = 0xffffffff;
      pcVar10 = "Height:";
      do {
        if (uVar9 == 0) break;
        uVar9 = uVar9 - 1;
        cVar1 = *pcVar10;
        pcVar10 = pcVar10 + 1;
      } while (cVar1 != '\0');
      pcVar10 = pcVar4;
      if (*pcVar4 != '\0') {
LAB_001c7ca8:
        iVar5 = _strncmp(pcVar10,"Height:",~uVar9 - 1);
        if (iVar5 != 0) goto LAB_001c7ce0;
        for (pcVar10 = pcVar10 + (~uVar9 - 1);
            (cVar1 = *pcVar10, cVar1 != '\0' && ((cVar1 == ' ' || (cVar1 == '\t'))));
            pcVar10 = pcVar10 + 1) {
        }
        pcVar11 = (char *)0x0;
        if (cVar1 != '\0') {
          pcVar11 = pcVar10;
        }
        goto LAB_001c7ce8;
      }
LAB_001c7ce6:
      pcVar11 = (char *)0x0;
LAB_001c7ce8:
      if (pcVar11 != (char *)0x0) {
        lVar7 = _strtol(pcVar11,(char **)0x0,10);
        uVar9 = 0xffffffff;
        pcVar10 = "Refresh:";
        do {
          if (uVar9 == 0) break;
          uVar9 = uVar9 - 1;
          cVar1 = *pcVar10;
          pcVar10 = pcVar10 + 1;
        } while (cVar1 != '\0');
        pcVar10 = pcVar4;
        if (*pcVar4 != '\0') {
LAB_001c7d24:
          iVar5 = _strncmp(pcVar10,"Refresh:",~uVar9 - 1);
          if (iVar5 != 0) goto LAB_001c7d5c;
          for (pcVar10 = pcVar10 + (~uVar9 - 1);
              (cVar1 = *pcVar10, cVar1 != '\0' && ((cVar1 == ' ' || (cVar1 == '\t'))));
              pcVar10 = pcVar10 + 1) {
          }
          pcVar11 = (char *)0x0;
          if (cVar1 != '\0') {
            pcVar11 = pcVar10;
          }
          goto LAB_001c7d64;
        }
LAB_001c7d62:
        pcVar11 = (char *)0x0;
LAB_001c7d64:
        if (pcVar11 != (char *)0x0) {
          lVar8 = _strtol(pcVar11,(char **)0x0,10);
          uVar9 = 0xffffffff;
          pcVar10 = "ColorSpace:";
          do {
            if (uVar9 == 0) break;
            uVar9 = uVar9 - 1;
            cVar1 = *pcVar10;
            pcVar10 = pcVar10 + 1;
          } while (cVar1 != '\0');
          if (*pcVar4 != '\0') {
LAB_001c7da0:
            iVar5 = _strncmp(pcVar4,"ColorSpace:",~uVar9 - 1);
            if (iVar5 != 0) goto LAB_001c7dd8;
            for (pcVar4 = pcVar4 + (~uVar9 - 1);
                (cVar1 = *pcVar4, cVar1 != '\0' && ((cVar1 == ' ' || (cVar1 == '\t'))));
                pcVar4 = pcVar4 + 1) {
            }
            pcVar10 = (char *)0x0;
            if (cVar1 != '\0') {
              pcVar10 = pcVar4;
            }
            goto LAB_001c7de0;
          }
LAB_001c7dde:
          pcVar10 = (char *)0x0;
LAB_001c7de0:
          if (pcVar10 != (char *)0x0) {
            iVar5 = _strncmp(pcVar10,"BW:2",4);
            if (iVar5 == 0) {
              pcVar10 = "BW:2";
            }
            else {
              iVar5 = _strncmp(pcVar10,"BW:8",4);
              if (iVar5 == 0) {
                pcVar10 = "BW:8";
              }
              else {
                iVar5 = _strncmp(pcVar10,"RGB:444/16",10);
                if (iVar5 == 0) {
                  pcVar10 = "RGB:444/16";
                }
                else {
                  iVar5 = _strncmp(pcVar10,"RGB:555/16",10);
                  if (iVar5 == 0) {
                    pcVar10 = "RGB:555/16";
                  }
                  else {
                    iVar5 = _strncmp(pcVar10,"RGB:888/32",10);
                    if (iVar5 != 0) {
                      return 0;
                    }
                    pcVar10 = "RGB:888/32";
                  }
                }
              }
            }
            _sprintf(local_104,"[%d x %d x %s @ %d]",lVar6,lVar7,pcVar10,lVar8);
            if (*(char *)(param_1 + 0x250) != '\0') {
              uVar2 = _objc_msgSend(param_1,PTR_s_name_001f9228,local_104);
              _IOLog("%s: Searching for key `%s\'.\n",uVar2);
            }
            pcVar10 = (char *)_objc_msgSend(iVar3,PTR_s_valueForStringKey__001f9308,local_104);
            if (pcVar10 != (char *)0x0) {
              uVar9 = 0xffffffff;
              pcVar4 = pcVar10;
              do {
                if (uVar9 == 0) break;
                uVar9 = uVar9 - 1;
                cVar1 = *pcVar4;
                pcVar4 = pcVar4 + 1;
              } while (cVar1 != '\0');
              if (~uVar9 <= *param_4) {
                if (*(char *)(param_1 + 0x250) != '\0') {
                  uVar2 = _objc_msgSend(param_1,PTR_s_name_001f9228,pcVar10);
                  _IOLog("%s: Using vpcode from `%s\'.\n",uVar2);
                }
                *param_4 = ~uVar9;
                _strcpy(param_3,pcVar10);
                return param_1;
              }
            }
          }
        }
      }
    }
  }
  return 0;
LAB_001c7c64:
  pcVar10 = pcVar10 + 1;
  if (*pcVar10 == '\0') goto LAB_001c7c6a;
  goto LAB_001c7c2c;
LAB_001c7ce0:
  pcVar10 = pcVar10 + 1;
  if (*pcVar10 == '\0') goto LAB_001c7ce6;
  goto LAB_001c7ca8;
LAB_001c7d5c:
  pcVar10 = pcVar10 + 1;
  if (*pcVar10 == '\0') goto LAB_001c7d62;
  goto LAB_001c7d24;
LAB_001c7dd8:
  pcVar4 = pcVar4 + 1;
  if (*pcVar4 == '\0') goto LAB_001c7dde;
  goto LAB_001c7da0;
}

