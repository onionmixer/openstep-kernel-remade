/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0019c898 */

void FUN_0019c898(int param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  char *pcVar8;
  int iVar9;
  int local_84;
  undefined2 local_80;
  int local_78;
  int local_74;
  undefined4 *local_70;
  int local_68;
  undefined4 *local_64;
  int local_60;
  int local_58;
  undefined4 *local_54;
  undefined4 *local_4c;
  undefined4 *local_44;
  int local_40;
  int local_38;
  undefined4 *local_34;
  int local_30;
  int local_28;
  undefined4 *local_24;
  int local_20;
  int local_18;
  int local_14;
  int local_8;
  
  local_8 = *(int *)(param_1 + 0xa4);
  iVar2 = *(int *)(param_1 + 0xa8);
  uVar7 = 0xffffffff;
  pcVar8 = param_2;
  do {
    if (uVar7 == 0) break;
    uVar7 = uVar7 - 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  iVar4 = ~uVar7 - 1;
  if ((iVar4 == 0) || (*(int *)(param_1 + 0x94) < iVar4)) {
    _IOLog(s_console__Illegal_title_length____001e47c8,iVar4);
  }
  else {
    FUN_0019ba18(param_1);
    if (*(int *)(param_1 + 0xc0) != 0) {
      *(int *)(param_1 + 0x90) = *(int *)(param_1 + 0x90) + -0x18;
      *(int *)(param_1 + 0x9c) = *(int *)(param_1 + 0x9c) + 2;
      *(int *)(param_1 + 0xa0) = *(int *)(param_1 + 0xa0) + 0x18;
      local_8 = local_8 + 2;
    }
    *(undefined4 *)(param_1 + 0xa4) = 0;
    iVar5 = *(int *)(param_1 + 0x8c);
    iVar9 = *(int *)(param_1 + 0x94) * 8;
    uVar3 = *(undefined4 *)(param_1 + 0xb4);
    local_20 = 0x15;
    local_18 = *(int *)(param_1 + 0x90);
    do {
      uVar7 = *(uint *)(param_1 + 0x1c);
      if (uVar7 < 4) {
        if (uVar7 < 2) {
          if (uVar7 != 1) goto LAB_0019c9b0;
          local_24 = (undefined4 *)
                     (local_18 * *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x18) + iVar5);
        }
        else {
          local_24 = (undefined4 *)
                     (local_18 * *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x18) + iVar5 * 2);
        }
      }
      else {
        if (uVar7 != 4) {
LAB_0019c9b0:
                    /* WARNING: Subroutine does not return */
          _panic(s_FBConsole_PixelAddress__bogus_bi_001e4704);
        }
        local_24 = (undefined4 *)
                   (local_18 * *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x18) + iVar5 * 4);
      }
      uVar7 = *(uint *)(param_1 + 0x1c);
      if (uVar7 < 4) {
        iVar6 = iVar9;
        if (uVar7 < 2) {
          if (uVar7 != 1) goto LAB_0019ca2c;
          while (iVar6 + -1 != -1) {
            *(char *)local_24 = (char)uVar3;
            local_24 = (undefined4 *)((int)local_24 + 1);
            iVar6 = iVar6 + -1;
          }
        }
        else {
          while (iVar6 + -1 != -1) {
            *(short *)local_24 = (short)uVar3;
            local_24 = (undefined4 *)((int)local_24 + 2);
            iVar6 = iVar6 + -1;
          }
        }
      }
      else {
        iVar6 = iVar9;
        if (uVar7 != 4) {
LAB_0019ca2c:
                    /* WARNING: Subroutine does not return */
          _panic(s_FBConsole_Fill__bogus_bitsPerPix_001e472f);
        }
        while (iVar6 + -1 != -1) {
          *local_24 = uVar3;
          local_24 = local_24 + 1;
          iVar6 = iVar6 + -1;
        }
      }
      local_20 = local_20 + -1;
      local_18 = local_18 + 1;
    } while (local_20 != -1);
    iVar5 = *(int *)(param_1 + 0x90);
    *(int *)(param_1 + 0x90) = iVar5 + 6;
    *(int *)(param_1 + 0xa8) = (*(int *)(param_1 + 0x94) - iVar4) / 2;
    FUN_0019ba18(param_1);
    uVar3 = *(undefined4 *)(param_1 + 0xb4);
    *(undefined4 *)(param_1 + 0xb4) = *(undefined4 *)(param_1 + 0xb0);
    *(undefined4 *)(param_1 + 0xb0) = uVar3;
    while (*param_2 != '\0') {
      cVar1 = *param_2;
      param_2 = param_2 + 1;
      FUN_0019bfa0(param_1,(int)cVar1);
    }
    uVar3 = *(undefined4 *)(param_1 + 0xb4);
    *(undefined4 *)(param_1 + 0xb4) = *(undefined4 *)(param_1 + 0xb0);
    *(undefined4 *)(param_1 + 0xb0) = uVar3;
    FUN_0019ba18(param_1);
    *(int *)(param_1 + 0x90) = iVar5;
    iVar9 = *(int *)(param_1 + 0x8c) + -2;
    iVar4 = *(int *)(param_1 + 0x98);
    uVar3 = *(undefined4 *)(param_1 + 0xbc);
    local_30 = 1;
    local_28 = iVar5 + -2;
    do {
      uVar7 = *(uint *)(param_1 + 0x1c);
      if (uVar7 < 4) {
        if (uVar7 < 2) {
          if (uVar7 != 1) goto LAB_0019cb60;
          local_34 = (undefined4 *)
                     (local_28 * *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x18) + iVar9);
        }
        else {
          local_34 = (undefined4 *)
                     (local_28 * *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x18) + iVar9 * 2);
        }
      }
      else {
        if (uVar7 != 4) {
LAB_0019cb60:
                    /* WARNING: Subroutine does not return */
          _panic(s_FBConsole_PixelAddress__bogus_bi_001e4704);
        }
        local_34 = (undefined4 *)
                   (local_28 * *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x18) + iVar9 * 4);
      }
      uVar7 = *(uint *)(param_1 + 0x1c);
      if (uVar7 < 4) {
        if (uVar7 < 2) {
          if (uVar7 != 1) goto LAB_0019cbdc;
          for (iVar5 = iVar4 + 3; iVar5 != -1; iVar5 = iVar5 + -1) {
            *(char *)local_34 = (char)uVar3;
            local_34 = (undefined4 *)((int)local_34 + 1);
          }
        }
        else {
          for (iVar5 = iVar4 + 3; iVar5 != -1; iVar5 = iVar5 + -1) {
            *(short *)local_34 = (short)uVar3;
            local_34 = (undefined4 *)((int)local_34 + 2);
          }
        }
      }
      else {
        if (uVar7 != 4) {
LAB_0019cbdc:
                    /* WARNING: Subroutine does not return */
          _panic(s_FBConsole_Fill__bogus_bitsPerPix_001e472f);
        }
        for (iVar5 = iVar4 + 3; iVar5 != -1; iVar5 = iVar5 + -1) {
          *local_34 = uVar3;
          local_34 = local_34 + 1;
        }
      }
      local_30 = local_30 + -1;
      local_28 = local_28 + 1;
    } while (local_30 != -1);
    iVar5 = *(int *)(param_1 + 0x8c) + -2;
    iVar4 = *(int *)(param_1 + 0x98);
    uVar3 = *(undefined4 *)(param_1 + 0xb8);
    local_40 = 1;
    local_38 = *(int *)(param_1 + 0x90) + 0x13;
    do {
      uVar7 = *(uint *)(param_1 + 0x1c);
      if (uVar7 < 4) {
        if (uVar7 < 2) {
          if (uVar7 != 1) goto LAB_0019cc88;
          local_44 = (undefined4 *)
                     (local_38 * *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x18) + iVar5);
        }
        else {
          local_44 = (undefined4 *)
                     (local_38 * *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x18) + iVar5 * 2);
        }
      }
      else {
        if (uVar7 != 4) {
LAB_0019cc88:
                    /* WARNING: Subroutine does not return */
          _panic(s_FBConsole_PixelAddress__bogus_bi_001e4704);
        }
        local_44 = (undefined4 *)
                   (local_38 * *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x18) + iVar5 * 4);
      }
      uVar7 = *(uint *)(param_1 + 0x1c);
      if (uVar7 < 4) {
        if (uVar7 < 2) {
          if (uVar7 != 1) goto LAB_0019cd04;
          for (iVar9 = iVar4 + 3; iVar9 != -1; iVar9 = iVar9 + -1) {
            *(char *)local_44 = (char)uVar3;
            local_44 = (undefined4 *)((int)local_44 + 1);
          }
        }
        else {
          for (iVar9 = iVar4 + 3; iVar9 != -1; iVar9 = iVar9 + -1) {
            *(short *)local_44 = (short)uVar3;
            local_44 = (undefined4 *)((int)local_44 + 2);
          }
        }
      }
      else {
        if (uVar7 != 4) {
LAB_0019cd04:
                    /* WARNING: Subroutine does not return */
          _panic(s_FBConsole_Fill__bogus_bitsPerPix_001e472f);
        }
        for (iVar9 = iVar4 + 3; iVar9 != -1; iVar9 = iVar9 + -1) {
          *local_44 = uVar3;
          local_44 = local_44 + 1;
        }
      }
      local_40 = local_40 + -1;
      local_38 = local_38 + 1;
    } while (local_40 != -1);
    local_14 = 0;
    local_78 = 0x17;
    do {
      iVar9 = local_14 + *(int *)(param_1 + 0x8c) + -2;
      uVar3 = *(undefined4 *)(param_1 + 0xbc);
      iVar4 = local_14 + *(int *)(param_1 + 0x90) + -2;
      iVar5 = local_78;
      while (iVar5 = iVar5 + -1, iVar5 != -1) {
        iVar6 = iVar4 + 1;
        uVar7 = *(uint *)(param_1 + 0x1c);
        if (uVar7 < 4) {
          if (uVar7 < 2) {
            if (uVar7 != 1) goto LAB_0019cdb8;
            local_4c = (undefined4 *)
                       (iVar4 * *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x18) + iVar9);
          }
          else {
            local_4c = (undefined4 *)
                       (iVar4 * *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x18) + iVar9 * 2);
          }
        }
        else {
          if (uVar7 != 4) {
LAB_0019cdb8:
                    /* WARNING: Subroutine does not return */
            _panic(s_FBConsole_PixelAddress__bogus_bi_001e4704);
          }
          local_4c = (undefined4 *)
                     (iVar4 * *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x18) + iVar9 * 4);
        }
        uVar7 = *(uint *)(param_1 + 0x1c);
        iVar4 = iVar6;
        if (uVar7 < 4) {
          if (uVar7 < 2) {
            if (uVar7 != 1) {
LAB_0019ce30:
                    /* WARNING: Subroutine does not return */
              _panic(s_FBConsole_Fill__bogus_bitsPerPix_001e472f);
            }
            iVar6 = 0;
            do {
              local_80._0_1_ = (undefined1)uVar3;
              *(undefined1 *)local_4c = (undefined1)local_80;
              local_4c = (undefined4 *)((int)local_4c + 1);
              iVar6 = iVar6 + -1;
            } while (iVar6 != -1);
          }
          else {
            iVar6 = 0;
            do {
              local_80 = (undefined2)uVar3;
              *(undefined2 *)local_4c = local_80;
              local_4c = (undefined4 *)((int)local_4c + 2);
              iVar6 = iVar6 + -1;
            } while (iVar6 != -1);
          }
        }
        else {
          if (uVar7 != 4) goto LAB_0019ce30;
          iVar6 = 0;
          do {
            *local_4c = uVar3;
            local_4c = local_4c + 1;
            iVar6 = iVar6 + -1;
          } while (iVar6 != -1);
        }
      }
      local_78 = local_78 + -2;
      local_14 = local_14 + 1;
    } while (local_14 < 2);
    local_14 = 1;
    local_74 = 0x15;
    do {
      iVar4 = local_14 + -1 + *(int *)(param_1 + 0x8c) + *(int *)(param_1 + 0x98);
      uVar3 = *(undefined4 *)(param_1 + 0xb8);
      iVar5 = *(int *)(param_1 + 0x90) - local_14;
      iVar9 = local_74;
      while (iVar9 = iVar9 + -1, iVar9 != -1) {
        iVar6 = iVar5 + 1;
        uVar7 = *(uint *)(param_1 + 0x1c);
        if (uVar7 < 4) {
          if (uVar7 < 2) {
            if (uVar7 != 1) goto LAB_0019cefc;
            local_54 = (undefined4 *)
                       (iVar5 * *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x18) + iVar4);
          }
          else {
            local_54 = (undefined4 *)
                       (iVar5 * *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x18) + iVar4 * 2);
          }
        }
        else {
          if (uVar7 != 4) {
LAB_0019cefc:
                    /* WARNING: Subroutine does not return */
            _panic(s_FBConsole_PixelAddress__bogus_bi_001e4704);
          }
          local_54 = (undefined4 *)
                     (iVar5 * *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x18) + iVar4 * 4);
        }
        uVar7 = *(uint *)(param_1 + 0x1c);
        iVar5 = iVar6;
        if (uVar7 < 4) {
          if (uVar7 < 2) {
            if (uVar7 != 1) {
LAB_0019cf74:
                    /* WARNING: Subroutine does not return */
              _panic(s_FBConsole_Fill__bogus_bitsPerPix_001e472f);
            }
            iVar6 = 0;
            do {
              local_80._0_1_ = (undefined1)uVar3;
              *(undefined1 *)local_54 = (undefined1)local_80;
              local_54 = (undefined4 *)((int)local_54 + 1);
              iVar6 = iVar6 + -1;
            } while (iVar6 != -1);
          }
          else {
            iVar6 = 0;
            do {
              local_80 = (undefined2)uVar3;
              *(undefined2 *)local_54 = local_80;
              local_54 = (undefined4 *)((int)local_54 + 2);
              iVar6 = iVar6 + -1;
            } while (iVar6 != -1);
          }
        }
        else {
          if (uVar7 != 4) goto LAB_0019cf74;
          iVar6 = 0;
          do {
            *local_54 = uVar3;
            local_54 = local_54 + 1;
            iVar6 = iVar6 + -1;
          } while (iVar6 != -1);
        }
      }
      local_74 = local_74 + 2;
      local_14 = local_14 + 1;
    } while (local_14 < 3);
    iVar5 = *(int *)(param_1 + 0x8c) + -3;
    iVar4 = *(int *)(param_1 + 0x98);
    uVar3 = *(undefined4 *)(param_1 + 0xb4);
    local_60 = 0;
    local_58 = *(int *)(param_1 + 0x90) + 0x15;
    do {
      uVar7 = *(uint *)(param_1 + 0x1c);
      if (uVar7 < 4) {
        if (uVar7 < 2) {
          if (uVar7 != 1) goto LAB_0019d030;
          local_64 = (undefined4 *)
                     (local_58 * *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x18) + iVar5);
        }
        else {
          local_64 = (undefined4 *)
                     (local_58 * *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x18) + iVar5 * 2);
        }
      }
      else {
        if (uVar7 != 4) {
LAB_0019d030:
                    /* WARNING: Subroutine does not return */
          _panic(s_FBConsole_PixelAddress__bogus_bi_001e4704);
        }
        local_64 = (undefined4 *)
                   (local_58 * *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x18) + iVar5 * 4);
      }
      uVar7 = *(uint *)(param_1 + 0x1c);
      if (uVar7 < 4) {
        if (uVar7 < 2) {
          if (uVar7 != 1) goto LAB_0019d0ac;
          for (iVar9 = iVar4 + 5; iVar9 != -1; iVar9 = iVar9 + -1) {
            *(char *)local_64 = (char)uVar3;
            local_64 = (undefined4 *)((int)local_64 + 1);
          }
        }
        else {
          for (iVar9 = iVar4 + 5; iVar9 != -1; iVar9 = iVar9 + -1) {
            *(short *)local_64 = (short)uVar3;
            local_64 = (undefined4 *)((int)local_64 + 2);
          }
        }
      }
      else {
        if (uVar7 != 4) {
LAB_0019d0ac:
                    /* WARNING: Subroutine does not return */
          _panic(s_FBConsole_Fill__bogus_bitsPerPix_001e472f);
        }
        for (iVar9 = iVar4 + 5; iVar9 != -1; iVar9 = iVar9 + -1) {
          *local_64 = uVar3;
          local_64 = local_64 + 1;
        }
      }
      local_60 = local_60 + -1;
      local_58 = local_58 + 1;
    } while (local_60 != -1);
    *(int *)(param_1 + 0x90) = *(int *)(param_1 + 0x90) + 0x18;
    *(int *)(param_1 + 0x9c) = *(int *)(param_1 + 0x9c) + -2;
    *(int *)(param_1 + 0xa0) = *(int *)(param_1 + 0xa0) + -0x18;
    *(int *)(param_1 + 0xa8) = iVar2;
    if (local_8 < 1) {
      iVar2 = *(int *)(param_1 + 0x8c) + iVar2 * 8;
      iVar4 = *(int *)(param_1 + 0x98) - (iVar2 - *(int *)(param_1 + 0x8c));
      local_84 = 0;
      local_68 = *(int *)(param_1 + 0x90) + *(int *)(param_1 + 0xa4) * 0xc;
      do {
        uVar7 = *(uint *)(param_1 + 0x1c);
        if (uVar7 < 4) {
          if (uVar7 < 2) {
            if (uVar7 != 1) goto LAB_0019d18c;
            local_70 = (undefined4 *)
                       (local_68 * *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x18) + iVar2);
          }
          else {
            local_70 = (undefined4 *)
                       (local_68 * *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x18) + iVar2 * 2);
          }
        }
        else {
          if (uVar7 != 4) {
LAB_0019d18c:
                    /* WARNING: Subroutine does not return */
            _panic(s_FBConsole_PixelAddress__bogus_bi_001e4704);
          }
          local_70 = (undefined4 *)
                     (local_68 * *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x18) + iVar2 * 4);
        }
        uVar3 = *(undefined4 *)(param_1 + 0xb0);
        uVar7 = *(uint *)(param_1 + 0x1c);
        if (uVar7 < 4) {
          iVar5 = iVar4;
          if (uVar7 < 2) {
            if (uVar7 != 1) goto LAB_0019d21c;
            while (iVar5 + -1 != -1) {
              local_80._0_1_ = (undefined1)uVar3;
              *(undefined1 *)local_70 = (undefined1)local_80;
              local_70 = (undefined4 *)((int)local_70 + 1);
              iVar5 = iVar5 + -1;
            }
          }
          else {
            while (iVar5 + -1 != -1) {
              local_80 = (undefined2)uVar3;
              *(undefined2 *)local_70 = local_80;
              local_70 = (undefined4 *)((int)local_70 + 2);
              iVar5 = iVar5 + -1;
            }
          }
        }
        else {
          iVar5 = iVar4;
          if (uVar7 != 4) {
LAB_0019d21c:
                    /* WARNING: Subroutine does not return */
            _panic(s_FBConsole_Fill__bogus_bitsPerPix_001e472f);
          }
          while (iVar5 + -1 != -1) {
            *local_70 = uVar3;
            local_70 = local_70 + 1;
            iVar5 = iVar5 + -1;
          }
        }
        local_84 = local_84 + 1;
        local_68 = local_68 + 1;
      } while (local_84 < 0xc);
    }
    else {
      *(int *)(param_1 + 0xa4) = local_8 + -2;
    }
    FUN_0019ba18(param_1);
    *(undefined4 *)(param_1 + 0xc0) = 1;
  }
  return;
}

