/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c6c44 */

int FUN_001c6c44(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  int local_24 [8];
  
  if (*(char *)(param_1 + 0x250) != '\0') {
    uVar2 = _objc_msgSend(param_1,PTR_s_name_001f9228);
    _IOLog("%s: Getting pixel encoding.\n",uVar2);
  }
  iVar3 = _objc_msgSend(param_1,PTR_s_runVPCode_withRegs__001f9590,6,local_24);
  if (iVar3 == 0) {
    uVar2 = _objc_msgSend(param_1,PTR_s_name_001f9228);
    _IOLog("%s: Can\'t obtain pixel encoding.\n",uVar2);
    return 0;
  }
  iVar3 = _objc_msgSend(param_1,PTR_s_displayInfo_001f9610);
  pcVar6 = (char *)(iVar3 + 0x20);
  _memset(pcVar6,0,0x40);
  if (*(uint *)(iVar3 + 0x1c) < 2) {
    if (*(int *)(iVar3 + 0x18) == 0) {
      iVar5 = 0;
      do {
        *(undefined1 *)(iVar5 + 0x20 + iVar3) = (undefined1)local_24[0];
        iVar5 = iVar5 + 1;
      } while (iVar5 < 2);
    }
    else {
      if (*(int *)(iVar3 + 0x18) != 1) {
        uVar2 = _objc_msgSend(param_1,PTR_s_name_001f9228,*(undefined4 *)(iVar3 + 0x18),
                              *(undefined4 *)(iVar3 + 0x1c));
        _IOLog("%s: invalid `bitsPerPixel\' (%d) for color space %d.\n",uVar2);
        return 0;
      }
      iVar5 = 0;
      do {
        *(undefined1 *)(iVar5 + 0x20 + iVar3) = (undefined1)local_24[0];
        iVar5 = iVar5 + 1;
      } while (iVar5 < 8);
    }
  }
  else {
    if (*(uint *)(iVar3 + 0x1c) != 2) {
      uVar2 = _objc_msgSend(param_1,PTR_s_name_001f9228,*(undefined4 *)(iVar3 + 0x1c));
      _IOLog("%s: Sorry, color space %d is not supported.\n",uVar2);
      return 0;
    }
    uVar1 = *(uint *)(iVar3 + 0x18);
    if (uVar1 == 3) {
      if ((((local_24[0] != 0x2d) || (local_24[1] != 0x52)) || (local_24[2] != 0x47)) ||
         (local_24[3] != 0x42)) {
        uVar2 = _objc_msgSend(param_1,PTR_s_name_001f9228);
        _IOLog("%s: Sorry, only `-RRRRRGGGGGBBBBB\' supported for `IO_15BitsPerPixel\'.\n",uVar2);
        return 0;
      }
      pcVar7 = "-RRRRRGGGGGBBBBB";
      for (iVar5 = 4; iVar5 != 0; iVar5 = iVar5 + -1) {
        *(undefined4 *)pcVar6 = *(undefined4 *)pcVar7;
        pcVar7 = pcVar7 + 4;
        pcVar6 = pcVar6 + 4;
      }
      *pcVar6 = *pcVar7;
    }
    else {
      if (uVar1 < 4) {
        if (uVar1 == 2) {
          if (((local_24[0] != 0x52) || (local_24[1] != 0x47)) ||
             ((local_24[2] != 0x42 || (local_24[3] != 0x2d)))) {
            uVar2 = _objc_msgSend(param_1,PTR_s_name_001f9228);
            _IOLog("%s: Sorry, only `RRRRGGGGBBBB----\' supported for `IO_12BitsPerPixel\'.\n",uVar2
                  );
            return 0;
          }
          pcVar7 = "RRRRGGGGBBBB----";
          for (iVar5 = 4; iVar5 != 0; iVar5 = iVar5 + -1) {
            *(undefined4 *)pcVar6 = *(undefined4 *)pcVar7;
            pcVar7 = pcVar7 + 4;
            pcVar6 = pcVar6 + 4;
          }
          *pcVar6 = *pcVar7;
          goto LAB_001c6e8c;
        }
      }
      else if (uVar1 == 4) {
        iVar5 = 0;
        do {
          iVar4 = 7;
          do {
            *pcVar6 = (char)local_24[iVar5];
            pcVar6 = pcVar6 + 1;
            iVar4 = iVar4 + -1;
          } while (-1 < iVar4);
          iVar5 = iVar5 + 1;
        } while (iVar5 < 4);
        goto LAB_001c6e8c;
      }
      uVar2 = _objc_msgSend(param_1,PTR_s_name_001f9228,*(undefined4 *)(iVar3 + 0x18));
      _IOLog("%s: invalid `bitsPerPixel\' (%d) for RGB color space.\n",uVar2);
    }
  }
LAB_001c6e8c:
  if (*(char *)(param_1 + 0x250) != '\0') {
    uVar2 = _objc_msgSend(param_1,PTR_s_name_001f9228,iVar3 + 0x20);
    _IOLog("%s: pixelEncoding = `%s\'.\n",uVar2);
  }
  return param_1;
}

