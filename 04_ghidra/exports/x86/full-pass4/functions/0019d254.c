/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0019d254 */

void FUN_0019d254(int param_1,uint param_2,int param_3,undefined4 param_4,int param_5,int param_6)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  void *pvVar4;
  int iVar5;
  void *pvVar6;
  int iVar7;
  int iVar8;
  int local_84;
  int local_80;
  undefined4 *local_78;
  undefined4 *local_74;
  undefined4 *local_6c;
  undefined4 *local_60;
  undefined4 *local_54;
  undefined4 *local_48;
  int local_44;
  int local_3c;
  undefined4 *local_38;
  int local_34;
  int local_2c;
  undefined4 *local_28;
  int local_24;
  int local_1c;
  undefined4 *local_18;
  int local_14;
  int local_c;
  
  if ((int)param_2 < 0) {
    param_2 = param_2 + 7;
  }
  param_2 = param_2 & 0xfffffff8;
  param_3 = (param_3 / 0xc) * 0xc;
  uVar1 = *(int *)(param_1 + 4) - 6;
  if ((int)uVar1 < (int)param_2) {
    param_2 = uVar1;
  }
  iVar5 = *(int *)(param_1 + 8) + -6;
  if (iVar5 < param_3) {
    param_3 = iVar5;
  }
  *(int *)(param_1 + 0x8c) = (int)(*(int *)(param_1 + 4) - param_2) / 2;
  *(int *)(param_1 + 0x90) = (*(int *)(param_1 + 8) - param_3) / 2;
  *(uint *)(param_1 + 0x98) = param_2;
  *(int *)(param_1 + 0xa0) = param_3;
  *(uint *)(param_1 + 0x8c) = *(uint *)(param_1 + 0x8c) & 0xfffffff8;
  iVar5 = *(int *)(param_1 + 0x98);
  if (iVar5 < 0) {
    iVar5 = iVar5 + 7;
  }
  *(int *)(param_1 + 0x94) = iVar5 >> 3;
  *(int *)(param_1 + 0x9c) = *(int *)(param_1 + 0xa0) / 0xc;
  *(undefined4 *)(param_1 + 0xa8) = 0;
  *(undefined4 *)(param_1 + 0xc0) = 0;
  if (param_5 == 0) {
    *(int *)(param_1 + 0xa4) = *(int *)(param_1 + 0x9c) + -1;
    FUN_0019c898(param_1,param_4);
    FUN_0019bfa0(param_1,10);
  }
  else {
    if (param_6 != 0) {
      iVar5 = 0;
      uVar1 = *(uint *)(param_1 + 0x1c);
      if (uVar1 < 4) {
        if (uVar1 < 2) {
          if (uVar1 == 1) {
            iVar5 = 1;
          }
        }
        else {
          iVar5 = 2;
        }
      }
      else if (uVar1 == 4) {
        iVar5 = 4;
      }
      *(int *)(param_1 + 200) = param_3 + 6;
      iVar5 = iVar5 * (param_2 + 6);
      *(int *)(param_1 + 0xcc) = iVar5;
      iVar5 = iVar5 * *(int *)(param_1 + 200);
      *(int *)(param_1 + 0xd0) = iVar5;
      pvVar4 = (void *)_IOMalloc(iVar5);
      *(void **)(param_1 + 0xc4) = pvVar4;
      iVar5 = *(int *)(param_1 + 0x8c) + -3;
      iVar7 = *(int *)(param_1 + 0x90) + -3;
      uVar1 = *(uint *)(param_1 + 0x1c);
      if (uVar1 < 4) {
        if (uVar1 < 2) {
          if (uVar1 != 1) goto LAB_0019d428;
          pvVar6 = (void *)(iVar5 + iVar7 * *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x18));
        }
        else {
          pvVar6 = (void *)(iVar7 * *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x18) + iVar5 * 2)
          ;
        }
      }
      else {
        if (uVar1 != 4) {
LAB_0019d428:
                    /* WARNING: Subroutine does not return */
          _panic(s_FBConsole_PixelAddress__bogus_bi_001e4704);
        }
        pvVar6 = (void *)(iVar7 * *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x18) + iVar5 * 4);
      }
      *(void **)(param_1 + 0xd4) = pvVar6;
      for (iVar5 = *(int *)(param_1 + 200); iVar5 != 0; iVar5 = iVar5 + -1) {
        _memmove(pvVar4,pvVar6,*(size_t *)(param_1 + 0xcc));
        pvVar6 = (void *)((int)pvVar6 + *(int *)(param_1 + 0x10));
        pvVar4 = (void *)((int)pvVar4 + *(int *)(param_1 + 0xcc));
      }
    }
    *(undefined4 *)(param_1 + 0xa4) = 0;
    *(undefined4 *)(param_1 + 0xc0) = 0;
    iVar5 = *(int *)(param_1 + 0x8c) + -3;
    uVar2 = *(undefined4 *)(param_1 + 0xb4);
    local_14 = 0;
    local_c = *(int *)(param_1 + 0x90) + -3;
    do {
      uVar1 = *(uint *)(param_1 + 0x1c);
      if (uVar1 < 4) {
        if (uVar1 < 2) {
          if (uVar1 != 1) goto LAB_0019d510;
          local_18 = (undefined4 *)
                     (local_c * *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x18) + iVar5);
        }
        else {
          local_18 = (undefined4 *)
                     (local_c * *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x18) + iVar5 * 2);
        }
      }
      else {
        if (uVar1 != 4) {
LAB_0019d510:
                    /* WARNING: Subroutine does not return */
          _panic(s_FBConsole_PixelAddress__bogus_bi_001e4704);
        }
        local_18 = (undefined4 *)
                   (local_c * *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x18) + iVar5 * 4);
      }
      uVar1 = *(uint *)(param_1 + 0x1c);
      if (uVar1 < 4) {
        if (uVar1 < 2) {
          if (uVar1 != 1) goto LAB_0019d598;
          for (iVar7 = param_2 + 5; iVar7 != -1; iVar7 = iVar7 + -1) {
            *(char *)local_18 = (char)uVar2;
            local_18 = (undefined4 *)((int)local_18 + 1);
          }
        }
        else {
          for (iVar7 = param_2 + 5; iVar7 != -1; iVar7 = iVar7 + -1) {
            *(short *)local_18 = (short)uVar2;
            local_18 = (undefined4 *)((int)local_18 + 2);
          }
        }
      }
      else {
        if (uVar1 != 4) {
LAB_0019d598:
                    /* WARNING: Subroutine does not return */
          _panic(s_FBConsole_Fill__bogus_bitsPerPix_001e472f);
        }
        for (iVar7 = param_2 + 5; iVar7 != -1; iVar7 = iVar7 + -1) {
          *local_18 = uVar2;
          local_18 = local_18 + 1;
        }
      }
      local_14 = local_14 + -1;
      local_c = local_c + 1;
    } while (local_14 != -1);
    iVar5 = *(int *)(param_1 + 0x8c) + -2;
    uVar2 = *(undefined4 *)(param_1 + 0xb0);
    local_24 = 1;
    local_1c = *(int *)(param_1 + 0x90) + -2;
    do {
      uVar1 = *(uint *)(param_1 + 0x1c);
      if (uVar1 < 4) {
        if (uVar1 < 2) {
          if (uVar1 != 1) goto LAB_0019d644;
          local_28 = (undefined4 *)
                     (local_1c * *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x18) + iVar5);
        }
        else {
          local_28 = (undefined4 *)
                     (local_1c * *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x18) + iVar5 * 2);
        }
      }
      else {
        if (uVar1 != 4) {
LAB_0019d644:
                    /* WARNING: Subroutine does not return */
          _panic(s_FBConsole_PixelAddress__bogus_bi_001e4704);
        }
        local_28 = (undefined4 *)
                   (local_1c * *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x18) + iVar5 * 4);
      }
      uVar1 = *(uint *)(param_1 + 0x1c);
      if (uVar1 < 4) {
        if (uVar1 < 2) {
          if (uVar1 != 1) goto LAB_0019d6cc;
          for (iVar7 = param_2 + 3; iVar7 != -1; iVar7 = iVar7 + -1) {
            *(char *)local_28 = (char)uVar2;
            local_28 = (undefined4 *)((int)local_28 + 1);
          }
        }
        else {
          for (iVar7 = param_2 + 3; iVar7 != -1; iVar7 = iVar7 + -1) {
            *(short *)local_28 = (short)uVar2;
            local_28 = (undefined4 *)((int)local_28 + 2);
          }
        }
      }
      else {
        if (uVar1 != 4) {
LAB_0019d6cc:
                    /* WARNING: Subroutine does not return */
          _panic(s_FBConsole_Fill__bogus_bitsPerPix_001e472f);
        }
        for (iVar7 = param_2 + 3; iVar7 != -1; iVar7 = iVar7 + -1) {
          *local_28 = uVar2;
          local_28 = local_28 + 1;
        }
      }
      local_24 = local_24 + -1;
      local_1c = local_1c + 1;
    } while (local_24 != -1);
    iVar5 = *(int *)(param_1 + 0x8c) + -2;
    uVar2 = *(undefined4 *)(param_1 + 0xb0);
    local_34 = 1;
    local_2c = param_3 + *(int *)(param_1 + 0x90);
    do {
      uVar1 = *(uint *)(param_1 + 0x1c);
      if (uVar1 < 4) {
        if (uVar1 < 2) {
          if (uVar1 != 1) goto LAB_0019d778;
          local_38 = (undefined4 *)
                     (local_2c * *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x18) + iVar5);
        }
        else {
          local_38 = (undefined4 *)
                     (local_2c * *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x18) + iVar5 * 2);
        }
      }
      else {
        if (uVar1 != 4) {
LAB_0019d778:
                    /* WARNING: Subroutine does not return */
          _panic(s_FBConsole_PixelAddress__bogus_bi_001e4704);
        }
        local_38 = (undefined4 *)
                   (local_2c * *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x18) + iVar5 * 4);
      }
      uVar1 = *(uint *)(param_1 + 0x1c);
      if (uVar1 < 4) {
        if (uVar1 < 2) {
          if (uVar1 != 1) goto LAB_0019d800;
          for (iVar7 = param_2 + 3; iVar7 != -1; iVar7 = iVar7 + -1) {
            *(char *)local_38 = (char)uVar2;
            local_38 = (undefined4 *)((int)local_38 + 1);
          }
        }
        else {
          for (iVar7 = param_2 + 3; iVar7 != -1; iVar7 = iVar7 + -1) {
            *(short *)local_38 = (short)uVar2;
            local_38 = (undefined4 *)((int)local_38 + 2);
          }
        }
      }
      else {
        if (uVar1 != 4) {
LAB_0019d800:
                    /* WARNING: Subroutine does not return */
          _panic(s_FBConsole_Fill__bogus_bitsPerPix_001e472f);
        }
        for (iVar7 = param_2 + 3; iVar7 != -1; iVar7 = iVar7 + -1) {
          *local_38 = uVar2;
          local_38 = local_38 + 1;
        }
      }
      local_34 = local_34 + -1;
      local_2c = local_2c + 1;
    } while (local_34 != -1);
    iVar5 = *(int *)(param_1 + 0x8c) + -3;
    uVar2 = *(undefined4 *)(param_1 + 0xb4);
    local_44 = 0;
    local_3c = param_3 + *(int *)(param_1 + 0x90) + 2;
    do {
      uVar1 = *(uint *)(param_1 + 0x1c);
      if (uVar1 < 4) {
        if (uVar1 < 2) {
          if (uVar1 != 1) goto LAB_0019d8ac;
          local_48 = (undefined4 *)
                     (local_3c * *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x18) + iVar5);
        }
        else {
          local_48 = (undefined4 *)
                     (local_3c * *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x18) + iVar5 * 2);
        }
      }
      else {
        if (uVar1 != 4) {
LAB_0019d8ac:
                    /* WARNING: Subroutine does not return */
          _panic(s_FBConsole_PixelAddress__bogus_bi_001e4704);
        }
        local_48 = (undefined4 *)
                   (local_3c * *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x18) + iVar5 * 4);
      }
      uVar1 = *(uint *)(param_1 + 0x1c);
      if (uVar1 < 4) {
        if (uVar1 < 2) {
          if (uVar1 != 1) goto LAB_0019d934;
          for (iVar7 = param_2 + 5; iVar7 != -1; iVar7 = iVar7 + -1) {
            *(char *)local_48 = (char)uVar2;
            local_48 = (undefined4 *)((int)local_48 + 1);
          }
        }
        else {
          for (iVar7 = param_2 + 5; iVar7 != -1; iVar7 = iVar7 + -1) {
            *(short *)local_48 = (short)uVar2;
            local_48 = (undefined4 *)((int)local_48 + 2);
          }
        }
      }
      else {
        if (uVar1 != 4) {
LAB_0019d934:
                    /* WARNING: Subroutine does not return */
          _panic(s_FBConsole_Fill__bogus_bitsPerPix_001e472f);
        }
        for (iVar7 = param_2 + 5; iVar7 != -1; iVar7 = iVar7 + -1) {
          *local_48 = uVar2;
          local_48 = local_48 + 1;
        }
      }
      local_44 = local_44 + -1;
      local_3c = local_3c + 1;
    } while (local_44 != -1);
    iVar8 = *(int *)(param_1 + 0x8c) + -3;
    uVar2 = *(undefined4 *)(param_1 + 0xb4);
    iVar7 = *(int *)(param_1 + 0x90) + -3;
    for (iVar5 = param_3 + 5; iVar5 != -1; iVar5 = iVar5 + -1) {
      uVar1 = *(uint *)(param_1 + 0x1c);
      if (uVar1 < 4) {
        if (uVar1 < 2) {
          if (uVar1 != 1) goto LAB_0019d9e0;
          local_54 = (undefined4 *)
                     (iVar7 * *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x18) + iVar8);
        }
        else {
          local_54 = (undefined4 *)
                     (iVar7 * *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x18) + iVar8 * 2);
        }
      }
      else {
        if (uVar1 != 4) {
LAB_0019d9e0:
                    /* WARNING: Subroutine does not return */
          _panic(s_FBConsole_PixelAddress__bogus_bi_001e4704);
        }
        local_54 = (undefined4 *)
                   (iVar7 * *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x18) + iVar8 * 4);
      }
      uVar1 = *(uint *)(param_1 + 0x1c);
      if (uVar1 < 4) {
        if (uVar1 < 2) {
          if (uVar1 != 1) goto LAB_0019da64;
          local_84 = 0;
          do {
            *(char *)local_54 = (char)uVar2;
            local_54 = (undefined4 *)((int)local_54 + 1);
            local_84 = local_84 + -1;
          } while (local_84 != -1);
        }
        else {
          local_84 = 0;
          do {
            *(short *)local_54 = (short)uVar2;
            local_54 = (undefined4 *)((int)local_54 + 2);
            local_84 = local_84 + -1;
          } while (local_84 != -1);
        }
      }
      else {
        if (uVar1 != 4) {
LAB_0019da64:
                    /* WARNING: Subroutine does not return */
          _panic(s_FBConsole_Fill__bogus_bitsPerPix_001e472f);
        }
        local_84 = 0;
        do {
          *local_54 = uVar2;
          local_54 = local_54 + 1;
          local_84 = local_84 + -1;
        } while (local_84 != -1);
      }
      iVar7 = iVar7 + 1;
    }
    iVar8 = *(int *)(param_1 + 0x8c) + -2;
    uVar2 = *(undefined4 *)(param_1 + 0xb0);
    iVar7 = *(int *)(param_1 + 0x90) + -2;
    for (iVar5 = param_3 + 3; iVar5 != -1; iVar5 = iVar5 + -1) {
      uVar1 = *(uint *)(param_1 + 0x1c);
      if (uVar1 < 4) {
        if (uVar1 < 2) {
          if (uVar1 != 1) goto LAB_0019db10;
          local_60 = (undefined4 *)
                     (iVar7 * *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x18) + iVar8);
        }
        else {
          local_60 = (undefined4 *)
                     (iVar7 * *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x18) + iVar8 * 2);
        }
      }
      else {
        if (uVar1 != 4) {
LAB_0019db10:
                    /* WARNING: Subroutine does not return */
          _panic(s_FBConsole_PixelAddress__bogus_bi_001e4704);
        }
        local_60 = (undefined4 *)
                   (iVar7 * *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x18) + iVar8 * 4);
      }
      uVar1 = *(uint *)(param_1 + 0x1c);
      if (uVar1 < 4) {
        if (uVar1 < 2) {
          if (uVar1 != 1) goto LAB_0019db94;
          local_84 = 1;
          do {
            *(char *)local_60 = (char)uVar2;
            local_60 = (undefined4 *)((int)local_60 + 1);
            local_84 = local_84 + -1;
          } while (local_84 != -1);
        }
        else {
          local_84 = 1;
          do {
            *(short *)local_60 = (short)uVar2;
            local_60 = (undefined4 *)((int)local_60 + 2);
            local_84 = local_84 + -1;
          } while (local_84 != -1);
        }
      }
      else {
        if (uVar1 != 4) {
LAB_0019db94:
                    /* WARNING: Subroutine does not return */
          _panic(s_FBConsole_Fill__bogus_bitsPerPix_001e472f);
        }
        local_84 = 1;
        do {
          *local_60 = uVar2;
          local_60 = local_60 + 1;
          local_84 = local_84 + -1;
        } while (local_84 != -1);
      }
      iVar7 = iVar7 + 1;
    }
    iVar8 = param_2 + *(int *)(param_1 + 0x8c);
    uVar2 = *(undefined4 *)(param_1 + 0xb0);
    iVar7 = *(int *)(param_1 + 0x90) + -2;
    for (iVar5 = param_3 + 3; iVar5 != -1; iVar5 = iVar5 + -1) {
      uVar1 = *(uint *)(param_1 + 0x1c);
      if (uVar1 < 4) {
        if (uVar1 < 2) {
          if (uVar1 != 1) goto LAB_0019dc40;
          local_6c = (undefined4 *)
                     (iVar7 * *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x18) + iVar8);
        }
        else {
          local_6c = (undefined4 *)
                     (iVar7 * *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x18) + iVar8 * 2);
        }
      }
      else {
        if (uVar1 != 4) {
LAB_0019dc40:
                    /* WARNING: Subroutine does not return */
          _panic(s_FBConsole_PixelAddress__bogus_bi_001e4704);
        }
        local_6c = (undefined4 *)
                   (iVar7 * *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x18) + iVar8 * 4);
      }
      uVar1 = *(uint *)(param_1 + 0x1c);
      if (uVar1 < 4) {
        if (uVar1 < 2) {
          if (uVar1 != 1) goto LAB_0019dcc4;
          local_84 = 1;
          do {
            *(char *)local_6c = (char)uVar2;
            local_6c = (undefined4 *)((int)local_6c + 1);
            local_84 = local_84 + -1;
          } while (local_84 != -1);
        }
        else {
          local_84 = 1;
          do {
            *(short *)local_6c = (short)uVar2;
            local_6c = (undefined4 *)((int)local_6c + 2);
            local_84 = local_84 + -1;
          } while (local_84 != -1);
        }
      }
      else {
        if (uVar1 != 4) {
LAB_0019dcc4:
                    /* WARNING: Subroutine does not return */
          _panic(s_FBConsole_Fill__bogus_bitsPerPix_001e472f);
        }
        local_84 = 1;
        do {
          *local_6c = uVar2;
          local_6c = local_6c + 1;
          local_84 = local_84 + -1;
        } while (local_84 != -1);
      }
      iVar7 = iVar7 + 1;
    }
    iVar7 = param_2 + *(int *)(param_1 + 0x8c) + 2;
    uVar2 = *(undefined4 *)(param_1 + 0xb4);
    iVar5 = *(int *)(param_1 + 0x90) + -3;
    for (param_3 = param_3 + 5; param_3 != -1; param_3 = param_3 + -1) {
      uVar1 = *(uint *)(param_1 + 0x1c);
      if (uVar1 < 4) {
        if (uVar1 < 2) {
          if (uVar1 != 1) goto LAB_0019dd74;
          local_74 = (undefined4 *)
                     (iVar5 * *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x18) + iVar7);
        }
        else {
          local_74 = (undefined4 *)
                     (iVar5 * *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x18) + iVar7 * 2);
        }
      }
      else {
        if (uVar1 != 4) {
LAB_0019dd74:
                    /* WARNING: Subroutine does not return */
          _panic(s_FBConsole_PixelAddress__bogus_bi_001e4704);
        }
        local_74 = (undefined4 *)
                   (iVar5 * *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x18) + iVar7 * 4);
      }
      uVar1 = *(uint *)(param_1 + 0x1c);
      if (uVar1 < 4) {
        if (uVar1 < 2) {
          if (uVar1 != 1) goto LAB_0019de04;
          local_80 = 0;
          do {
            local_84._0_1_ = (undefined1)uVar2;
            *(undefined1 *)local_74 = (undefined1)local_84;
            local_74 = (undefined4 *)((int)local_74 + 1);
            local_80 = local_80 + -1;
          } while (local_80 != -1);
        }
        else {
          local_80 = 0;
          do {
            local_84._0_2_ = (undefined2)uVar2;
            *(undefined2 *)local_74 = (undefined2)local_84;
            local_74 = (undefined4 *)((int)local_74 + 2);
            local_80 = local_80 + -1;
          } while (local_80 != -1);
        }
      }
      else {
        if (uVar1 != 4) {
LAB_0019de04:
                    /* WARNING: Subroutine does not return */
          _panic(s_FBConsole_Fill__bogus_bitsPerPix_001e472f);
        }
        local_80 = 0;
        do {
          *local_74 = uVar2;
          local_74 = local_74 + 1;
          local_80 = local_80 + -1;
        } while (local_80 != -1);
      }
      iVar5 = iVar5 + 1;
    }
    iVar5 = *(int *)(param_1 + 0x8c);
    iVar7 = *(int *)(param_1 + 0x90);
    uVar1 = *(uint *)(param_1 + 0x1c);
    if (uVar1 < 4) {
      if (uVar1 < 2) {
        if (uVar1 != 1) goto LAB_0019de7c;
        local_78 = (undefined4 *)
                   (iVar7 * *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x18) + iVar5);
      }
      else {
        local_78 = (undefined4 *)
                   (iVar7 * *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x18) + iVar5 * 2);
      }
    }
    else {
      if (uVar1 != 4) {
LAB_0019de7c:
                    /* WARNING: Subroutine does not return */
        _panic(s_FBConsole_PixelAddress__bogus_bi_001e4704);
      }
      local_78 = (undefined4 *)
                 (iVar7 * *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x18) + iVar5 * 4);
    }
    iVar5 = 0;
    if (0 < *(int *)(param_1 + 0xa0)) {
      do {
        uVar2 = *(undefined4 *)(param_1 + 0xb0);
        iVar7 = *(int *)(param_1 + 0x98);
        uVar1 = *(uint *)(param_1 + 0x1c);
        if (uVar1 < 4) {
          puVar3 = local_78;
          if (uVar1 < 2) {
            if (uVar1 != 1) goto LAB_0019df1c;
            while (iVar7 = iVar7 + -1, iVar7 != -1) {
              local_84._0_1_ = (undefined1)uVar2;
              *(undefined1 *)puVar3 = (undefined1)local_84;
              puVar3 = (undefined4 *)((int)puVar3 + 1);
            }
          }
          else {
            while (iVar7 = iVar7 + -1, iVar7 != -1) {
              local_84._0_2_ = (undefined2)uVar2;
              *(undefined2 *)puVar3 = (undefined2)local_84;
              puVar3 = (undefined4 *)((int)puVar3 + 2);
            }
          }
        }
        else {
          puVar3 = local_78;
          if (uVar1 != 4) {
LAB_0019df1c:
                    /* WARNING: Subroutine does not return */
            _panic(s_FBConsole_Fill__bogus_bitsPerPix_001e472f);
          }
          while (iVar7 = iVar7 + -1, iVar7 != -1) {
            *puVar3 = uVar2;
            puVar3 = puVar3 + 1;
          }
        }
        local_78 = (undefined4 *)((int)local_78 + *(int *)(param_1 + 0x10));
        iVar5 = iVar5 + 1;
      } while (iVar5 < *(int *)(param_1 + 0xa0));
    }
    FUN_0019ba18(param_1);
    FUN_0019c898(param_1,param_4);
  }
  return;
}

