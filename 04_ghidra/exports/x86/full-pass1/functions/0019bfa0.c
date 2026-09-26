/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0019bfa0 */

void FUN_0019bfa0(int *param_1,char param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int *local_30;
  int *local_28;
  int local_20;
  size_t local_1c;
  void *local_18;
  void *local_14;
  int *local_10;
  int local_8;
  
  if (*param_1 == 2) {
    return;
  }
  iVar6 = param_1[0x36];
  if (iVar6 == 1) {
    if (param_2 == '[') {
      param_1[0x36] = 2;
      return;
    }
    param_1[0x36] = 0;
LAB_0019c006:
    if ((byte)(param_2 - 0x30U) < 10) {
      *(char *)param_1[0x38] = (param_2 - 0x30U) + *(char *)param_1[0x38] * '\n';
      return;
    }
    if (param_2 == ';') {
      if ((int)param_1 + 0xdfU <= (uint)param_1[0x38]) {
        return;
      }
      param_1[0x38] = param_1[0x38] + 1;
      return;
    }
    iVar6 = 0;
    do {
      if (*(char *)(iVar6 + 0xdc + (int)param_1) == '\0') {
        *(undefined1 *)(iVar6 + 0xdc + (int)param_1) = 1;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < 3);
    uVar5 = (uint)*(byte *)param_1[0x38];
    FUN_0019ba18(param_1);
    switch(param_2) {
    case 'A':
      while (uVar5 = uVar5 - 1, uVar5 != 0xffffffff) {
        if (param_1[0x29] != 0) {
          param_1[0x29] = param_1[0x29] + -1;
        }
      }
      break;
    case 'B':
      while (uVar5 = uVar5 - 1, uVar5 != 0xffffffff) {
        param_1[0x29] = param_1[0x29] + 1;
      }
      break;
    case 'C':
      while (uVar5 = uVar5 - 1, uVar5 != 0xffffffff) {
        param_1[0x2a] = param_1[0x2a] + 1;
      }
      break;
    case 'D':
      while (uVar5 = uVar5 - 1, uVar5 != 0xffffffff) {
        if (param_1[0x2a] != 0) {
          param_1[0x2a] = param_1[0x2a] + -1;
        }
      }
      break;
    case 'E':
      param_1[0x2a] = 0;
      while (uVar5 = uVar5 - 1, uVar5 != 0xffffffff) {
        param_1[0x29] = param_1[0x29] + 1;
      }
      break;
    case 'H':
    case 'f':
      param_1[0x2a] = *(byte *)param_1[0x38] - 1;
      iVar6 = param_1[0x38];
      param_1[0x38] = iVar6 + -1;
      param_1[0x29] = *(byte *)(iVar6 + -1) - 1;
      param_1[0x38] = param_1[0x38] + -1;
      break;
    case 'K':
      iVar6 = param_1[0x23] + param_1[0x2a] * 8;
      iVar4 = param_1[0x26] + param_1[0x2a] * -8;
      local_30 = (int *)0x0;
      local_8 = param_1[0x24] + param_1[0x29] * 0xc;
      do {
        uVar5 = param_1[7];
        if (uVar5 < 4) {
          if (uVar5 < 2) {
            if (uVar5 != 1) goto LAB_0019c2d4;
            local_10 = (int *)(local_8 * param_1[4] + param_1[6] + iVar6);
          }
          else {
            local_10 = (int *)(local_8 * param_1[4] + param_1[6] + iVar6 * 2);
          }
        }
        else {
          if (uVar5 != 4) {
LAB_0019c2d4:
                    /* WARNING: Subroutine does not return */
            _panic(s_FBConsole_PixelAddress__bogus_bi_001e4704);
          }
          local_10 = (int *)(local_8 * param_1[4] + param_1[6] + iVar6 * 4);
        }
        iVar1 = param_1[0x2c];
        uVar5 = param_1[7];
        if (uVar5 < 4) {
          iVar3 = iVar4;
          if (uVar5 < 2) {
            if (uVar5 != 1) goto LAB_0019c358;
            while (iVar3 + -1 != -1) {
              *(char *)local_10 = (char)iVar1;
              local_10 = (int *)((int)local_10 + 1);
              iVar3 = iVar3 + -1;
            }
          }
          else {
            while (iVar3 + -1 != -1) {
              *(short *)local_10 = (short)iVar1;
              local_10 = (int *)((int)local_10 + 2);
              iVar3 = iVar3 + -1;
            }
          }
        }
        else {
          iVar3 = iVar4;
          if (uVar5 != 4) {
LAB_0019c358:
                    /* WARNING: Subroutine does not return */
            _panic(s_FBConsole_Fill__bogus_bitsPerPix_001e472f);
          }
          while (iVar3 + -1 != -1) {
            *local_10 = iVar1;
            local_10 = local_10 + 1;
            iVar3 = iVar3 + -1;
          }
        }
        local_30 = (int *)((int)local_30 + 1);
        local_8 = local_8 + 1;
      } while ((int)local_30 < 0xc);
      break;
    case 'm':
      param_1[0x38] = param_1[0x38] + -2;
    }
    param_1[0x38] = (int)param_1 + 0xdd;
    iVar6 = 2;
    do {
      *(undefined1 *)(iVar6 + 0xdc + (int)param_1) = 0;
      iVar6 = iVar6 + -1;
    } while (-1 < iVar6);
    param_1[0x36] = 0;
  }
  else {
    if (iVar6 == 0) {
      if (param_2 == '\x1b') {
        param_1[0x36] = 1;
        return;
      }
    }
    else if (iVar6 == 2) goto LAB_0019c006;
    FUN_0019ba18(param_1);
    if (param_2 == '\n') {
      param_1[0x2a] = 0;
      param_1[0x29] = param_1[0x29] + 1;
    }
    else if (param_2 < '\v') {
      if (param_2 == '\b') {
        if (param_1[0x2a] != 0) {
          param_1[0x2a] = param_1[0x2a] + -1;
        }
      }
      else {
        if (param_2 != '\t') goto LAB_0019c5b8;
        iVar4 = 8 - param_1[0x2a] % 8;
        FUN_0019ba18(param_1);
        iVar6 = 0;
        if (0 < iVar4) {
          do {
            FUN_0019bfa0(param_1,0x20);
            iVar6 = iVar6 + 1;
          } while (iVar6 < iVar4);
        }
        FUN_0019ba18(param_1);
      }
    }
    else if (param_2 == '\r') {
      param_1[0x2a] = 0;
    }
    else if (param_2 < '\x0e') {
      if (param_2 == '\f') {
        param_1[0x2a] = 0;
        param_1[0x29] = 0;
        iVar6 = param_1[0x23];
        iVar4 = param_1[0x24];
        uVar5 = param_1[7];
        if (uVar5 < 4) {
          if (uVar5 < 2) {
            if (uVar5 != 1) goto LAB_0019c4f8;
            local_30 = (int *)(iVar4 * param_1[4] + param_1[6] + iVar6);
          }
          else {
            local_30 = (int *)(iVar4 * param_1[4] + param_1[6] + iVar6 * 2);
          }
        }
        else {
          if (uVar5 != 4) {
LAB_0019c4f8:
                    /* WARNING: Subroutine does not return */
            _panic(s_FBConsole_PixelAddress__bogus_bi_001e4704);
          }
          local_30 = (int *)(iVar4 * param_1[4] + param_1[6] + iVar6 * 4);
        }
        iVar6 = 0;
        if (0 < param_1[0x28]) {
          do {
            iVar4 = param_1[0x2c];
            iVar1 = param_1[0x26];
            uVar5 = param_1[7];
            if (uVar5 < 4) {
              piVar2 = local_30;
              if (uVar5 < 2) {
                if (uVar5 != 1) goto LAB_0019c58c;
                while (iVar1 = iVar1 + -1, iVar1 != -1) {
                  *(char *)piVar2 = (char)iVar4;
                  piVar2 = (int *)((int)piVar2 + 1);
                }
              }
              else {
                while (iVar1 = iVar1 + -1, iVar1 != -1) {
                  *(short *)piVar2 = (short)iVar4;
                  piVar2 = (int *)((int)piVar2 + 2);
                }
              }
            }
            else {
              piVar2 = local_30;
              if (uVar5 != 4) {
LAB_0019c58c:
                    /* WARNING: Subroutine does not return */
                _panic(s_FBConsole_Fill__bogus_bitsPerPix_001e472f);
              }
              while (iVar1 = iVar1 + -1, iVar1 != -1) {
                *piVar2 = iVar4;
                piVar2 = piVar2 + 1;
              }
            }
            local_30 = (int *)((int)local_30 + param_1[4]);
            iVar6 = iVar6 + 1;
          } while (iVar6 < param_1[0x28]);
        }
      }
      else {
LAB_0019c5b8:
        FUN_0019bd3c(param_1,(int)param_2);
      }
    }
    else {
      if (param_2 != '\x7f') goto LAB_0019c5b8;
      param_1[0x2a] = param_1[0x2a] + 1;
    }
  }
  if (param_1[0x25] <= param_1[0x2a]) {
    param_1[0x2a] = 0;
    param_1[0x29] = param_1[0x29] + 1;
  }
  if (param_1[0x27] <= param_1[0x29]) {
    param_1[0x29] = param_1[0x27] + -1;
    uVar5 = param_1[7];
    if (uVar5 < 4) {
      if (uVar5 < 2) {
        if (uVar5 != 1) goto LAB_0019c644;
        local_1c = param_1[0x26];
      }
      else {
        local_1c = param_1[0x26] * 2;
      }
    }
    else {
      if (uVar5 != 4) {
LAB_0019c644:
                    /* WARNING: Subroutine does not return */
        _panic(s_FBConsole_FBPutC__bogus_bitsPerP_001e47a3);
      }
      local_1c = param_1[0x26] << 2;
    }
    iVar6 = param_1[0x23];
    iVar4 = param_1[0x24] + 0xc;
    uVar5 = param_1[7];
    if (uVar5 < 4) {
      if (uVar5 < 2) {
        if (uVar5 != 1) goto LAB_0019c6ac;
        local_14 = (void *)(iVar4 * param_1[4] + param_1[6] + iVar6);
      }
      else {
        local_14 = (void *)(iVar4 * param_1[4] + param_1[6] + iVar6 * 2);
      }
    }
    else {
      if (uVar5 != 4) {
LAB_0019c6ac:
                    /* WARNING: Subroutine does not return */
        _panic(s_FBConsole_PixelAddress__bogus_bi_001e4704);
      }
      local_14 = (void *)(iVar4 * param_1[4] + param_1[6] + iVar6 * 4);
    }
    iVar6 = param_1[0x23];
    iVar4 = param_1[0x24];
    uVar5 = param_1[7];
    if (uVar5 < 4) {
      if (uVar5 < 2) {
        if (uVar5 != 1) goto LAB_0019c714;
        local_18 = (void *)(iVar4 * param_1[4] + param_1[6] + iVar6);
      }
      else {
        local_18 = (void *)(iVar4 * param_1[4] + param_1[6] + iVar6 * 2);
      }
    }
    else {
      if (uVar5 != 4) {
LAB_0019c714:
                    /* WARNING: Subroutine does not return */
        _panic(s_FBConsole_PixelAddress__bogus_bi_001e4704);
      }
      local_18 = (void *)(iVar4 * param_1[4] + param_1[6] + iVar6 * 4);
    }
    iVar6 = 0xc;
    if (0xc < param_1[0x28]) {
      do {
        _memmove(local_18,local_14,local_1c);
        local_14 = (void *)((int)local_14 + param_1[4]);
        local_18 = (void *)((int)local_18 + param_1[4]);
        iVar6 = iVar6 + 1;
      } while (iVar6 < param_1[0x28]);
    }
    param_1[0x2a] = 0;
    iVar6 = param_1[0x23];
    iVar4 = param_1[0x26];
    local_30 = (int *)0x0;
    local_20 = param_1[0x24] + param_1[0x29] * 0xc;
    do {
      uVar5 = param_1[7];
      if (uVar5 < 4) {
        if (uVar5 < 2) {
          if (uVar5 != 1) goto LAB_0019c7e8;
          local_28 = (int *)(local_20 * param_1[4] + param_1[6] + iVar6);
        }
        else {
          local_28 = (int *)(local_20 * param_1[4] + param_1[6] + iVar6 * 2);
        }
      }
      else {
        if (uVar5 != 4) {
LAB_0019c7e8:
                    /* WARNING: Subroutine does not return */
          _panic(s_FBConsole_PixelAddress__bogus_bi_001e4704);
        }
        local_28 = (int *)(local_20 * param_1[4] + param_1[6] + iVar6 * 4);
      }
      iVar1 = param_1[0x2c];
      uVar5 = param_1[7];
      if (uVar5 < 4) {
        iVar3 = iVar4;
        if (uVar5 < 2) {
          if (uVar5 != 1) goto LAB_0019c86c;
          while (iVar3 + -1 != -1) {
            *(char *)local_28 = (char)iVar1;
            local_28 = (int *)((int)local_28 + 1);
            iVar3 = iVar3 + -1;
          }
        }
        else {
          while (iVar3 + -1 != -1) {
            *(short *)local_28 = (short)iVar1;
            local_28 = (int *)((int)local_28 + 2);
            iVar3 = iVar3 + -1;
          }
        }
      }
      else {
        iVar3 = iVar4;
        if (uVar5 != 4) {
LAB_0019c86c:
                    /* WARNING: Subroutine does not return */
          _panic(s_FBConsole_Fill__bogus_bitsPerPix_001e472f);
        }
        while (iVar3 + -1 != -1) {
          *local_28 = iVar1;
          local_28 = local_28 + 1;
          iVar3 = iVar3 + -1;
        }
      }
      local_30 = (int *)((int)local_30 + 1);
      local_20 = local_20 + 1;
    } while ((int)local_30 < 0xc);
  }
  FUN_0019ba18(param_1);
  return;
}

