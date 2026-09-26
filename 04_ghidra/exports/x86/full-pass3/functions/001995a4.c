/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001995a4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_001995a4(int param_1,uint param_2,int param_3,undefined4 param_4,int param_5,int param_6)

{
  byte bVar1;
  undefined1 uVar2;
  byte bVar3;
  int iVar4;
  undefined2 uVar5;
  uint uVar6;
  int iVar7;
  undefined1 *puVar8;
  int iVar9;
  undefined1 *puVar10;
  uint uVar11;
  int iVar12;
  uint local_a4;
  int local_a0;
  undefined1 *local_94;
  undefined1 *local_90;
  undefined1 *local_10;
  
  local_a4 = param_2;
  if ((int)param_2 < 0) {
    local_a4 = param_2 + 7;
  }
  param_3 = (param_3 / 0xc) * 0xc;
  uVar6 = *(int *)(param_1 + 4) - 6;
  param_2 = local_a4 & 0xfffffff8;
  if ((int)uVar6 < (int)(local_a4 & 0xfffffff8)) {
    param_2 = uVar6;
  }
  iVar7 = *(int *)(param_1 + 8) + -6;
  if (iVar7 < param_3) {
    param_3 = iVar7;
  }
  *(int *)(param_1 + 0x8c) = (int)(*(int *)(param_1 + 4) - param_2) / 2;
  *(int *)(param_1 + 0x90) = (*(int *)(param_1 + 8) - param_3) / 2;
  *(uint *)(param_1 + 0x98) = param_2;
  *(int *)(param_1 + 0xa0) = param_3;
  *(uint *)(param_1 + 0x8c) = *(uint *)(param_1 + 0x8c) & 0xfffffff8;
  iVar7 = *(int *)(param_1 + 0x98);
  if (iVar7 < 0) {
    iVar7 = iVar7 + 7;
  }
  *(int *)(param_1 + 0x94) = iVar7 >> 3;
  *(int *)(param_1 + 0x9c) = *(int *)(param_1 + 0xa0) / 0xc;
  *(undefined4 *)(param_1 + 0xa8) = 0;
  *(undefined4 *)(param_1 + 0xc0) = 0;
  if (param_5 == 0) {
    *(int *)(param_1 + 0xa4) = *(int *)(param_1 + 0x9c) + -1;
    FUN_00198adc(param_1,param_4);
    FUN_00198098(param_1,10);
  }
  else {
    if (param_6 != 0) {
      local_90 = (undefined1 *)0x0;
      do {
        out(0x3ce,local_90._0_1_);
        LOCK();
        UNLOCK();
        out(0x3cf,(&DAT_001e467c)[(int)local_90]);
        LOCK();
        _DAT_001e8654 = _DAT_001e8654 + 2;
        UNLOCK();
        local_90 = (undefined1 *)((int)local_90 + 1);
      } while ((int)local_90 < 9);
      if (*(int *)(param_1 + 0x100) == 0) {
        *(int *)(param_1 + 200) = param_3 + 6;
        uVar6 = param_2;
        if ((int)param_2 < 0) {
          uVar6 = param_2 + 7;
        }
        iVar7 = ((int)uVar6 >> 3) + 2;
        *(int *)(param_1 + 0xcc) = iVar7;
        *(int *)(param_1 + 0xd0) = iVar7 * *(int *)(param_1 + 200);
        puVar10 = *(undefined1 **)(param_1 + 0xc4);
        puVar8 = (undefined1 *)
                 ((*(int *)(param_1 + 0x8c) >> 3) + -1 +
                 (*(int *)(param_1 + 0x90) + -3) * *(int *)(param_1 + 0x10) +
                 *(int *)(param_1 + 0x18));
        *(undefined1 **)(param_1 + 0xd4) = puVar8;
        out(0x3ce,5);
        LOCK();
        UNLOCK();
        bVar3 = in(0x3cf);
        out(0x3ce,5);
        LOCK();
        UNLOCK();
        out(0x3cf,bVar3 & 0xfc | 1);
        LOCK();
        _DAT_001e8654 = _DAT_001e8654 + 3;
        UNLOCK();
        local_90 = *(undefined1 **)(param_1 + 200);
        if (local_90 != (undefined1 *)0x0) {
          iVar7 = *(int *)(param_1 + 0xcc);
          iVar4 = *(int *)(param_1 + 0x10);
          iVar12 = iVar7;
          local_10 = puVar10;
          local_94 = puVar8;
          do {
            for (; iVar12 != 0; iVar12 = iVar12 + -1) {
              *puVar10 = *puVar8;
              puVar8 = puVar8 + 1;
              puVar10 = puVar10 + 1;
            }
            puVar8 = local_94 + iVar4;
            puVar10 = local_10 + iVar7;
            local_90 = (undefined1 *)((int)local_90 + -1);
            iVar12 = iVar7;
            local_10 = puVar10;
            local_94 = puVar8;
          } while (local_90 != (undefined1 *)0x0);
        }
        out(0x3ce,5);
        LOCK();
        UNLOCK();
        bVar3 = in(0x3cf);
        bVar3 = bVar3 & 0xfc;
        out(0x3ce,5);
        LOCK();
        _DAT_001e8654 = _DAT_001e8654 + 2;
        UNLOCK();
        uVar5 = 0x3cf;
      }
      else {
        iVar7 = 0;
        do {
          out(0x3ce,(char)iVar7);
          LOCK();
          _DAT_001e8654 = _DAT_001e8654 + 1;
          UNLOCK();
          uVar2 = in(0x3cf);
          *(undefined1 *)(iVar7 + param_1 + 0xe6) = uVar2;
          iVar7 = iVar7 + 1;
        } while (iVar7 < 9);
        out(0x3c4,2);
        LOCK();
        _DAT_001e8654 = _DAT_001e8654 + 1;
        UNLOCK();
        uVar2 = in(0x3c5);
        *(undefined1 *)(param_1 + 0xf1) = uVar2;
        *(int *)(param_1 + 200) = param_3 + 6;
        uVar6 = param_2;
        if ((int)param_2 < 0) {
          uVar6 = param_2 + 7;
        }
        iVar7 = ((int)uVar6 >> 3) + 2;
        *(int *)(param_1 + 0xcc) = iVar7;
        *(int *)(param_1 + 0xd0) = iVar7 * *(int *)(param_1 + 200);
        puVar10 = *(undefined1 **)(param_1 + 0xc4);
        out(0x3ce,5);
        LOCK();
        UNLOCK();
        bVar3 = in(0x3cf);
        out(0x3ce,5);
        LOCK();
        UNLOCK();
        out(0x3cf,bVar3 & 0xf7);
        LOCK();
        UNLOCK();
        out(0x3ce,4);
        LOCK();
        UNLOCK();
        bVar3 = in(0x3cf);
        out(0x3ce,4);
        LOCK();
        UNLOCK();
        out(0x3cf,bVar3 & 0xfc);
        LOCK();
        _DAT_001e8654 = _DAT_001e8654 + 6;
        UNLOCK();
        puVar8 = (undefined1 *)
                 ((*(int *)(param_1 + 0x8c) >> 3) + -1 +
                 (*(int *)(param_1 + 0x90) + -3) * *(int *)(param_1 + 0x10) +
                 *(int *)(param_1 + 0x18));
        *(undefined1 **)(param_1 + 0xd4) = puVar8;
        local_90 = *(undefined1 **)(param_1 + 200);
        local_10 = puVar10;
        if (local_90 != (undefined1 *)0x0) {
          iVar7 = *(int *)(param_1 + 0xcc);
          iVar4 = *(int *)(param_1 + 0x10);
          iVar12 = iVar7;
          local_94 = puVar8;
          do {
            for (; iVar12 != 0; iVar12 = iVar12 + -1) {
              *puVar10 = *puVar8;
              puVar8 = puVar8 + 1;
              puVar10 = puVar10 + 1;
            }
            puVar8 = local_94 + iVar4;
            puVar10 = local_10 + iVar7;
            local_90 = (undefined1 *)((int)local_90 + -1);
            iVar12 = iVar7;
            local_10 = puVar10;
            local_94 = puVar8;
          } while (local_90 != (undefined1 *)0x0);
        }
        out(0x3ce,4);
        LOCK();
        UNLOCK();
        bVar3 = in(0x3cf);
        out(0x3ce,4);
        LOCK();
        UNLOCK();
        out(0x3cf,bVar3 & 0xfc | 1);
        LOCK();
        _DAT_001e8654 = _DAT_001e8654 + 3;
        UNLOCK();
        puVar8 = (undefined1 *)
                 ((*(int *)(param_1 + 0x8c) >> 3) + -1 +
                 (*(int *)(param_1 + 0x90) + -3) * *(int *)(param_1 + 0x10) +
                 *(int *)(param_1 + 0x18));
        *(undefined1 **)(param_1 + 0xd4) = puVar8;
        local_90 = *(undefined1 **)(param_1 + 200);
        if (local_90 != (undefined1 *)0x0) {
          iVar7 = *(int *)(param_1 + 0xcc);
          iVar4 = *(int *)(param_1 + 0x10);
          iVar12 = iVar7;
          puVar10 = local_10;
          local_94 = puVar8;
          do {
            for (; iVar12 != 0; iVar12 = iVar12 + -1) {
              *puVar10 = *puVar8;
              puVar8 = puVar8 + 1;
              puVar10 = puVar10 + 1;
            }
            puVar8 = local_94 + iVar4;
            puVar10 = local_10 + iVar7;
            local_90 = (undefined1 *)((int)local_90 + -1);
            iVar12 = iVar7;
            local_10 = puVar10;
            local_94 = puVar8;
          } while (local_90 != (undefined1 *)0x0);
        }
        out(0x3ce,5);
        LOCK();
        UNLOCK();
        bVar3 = in(0x3cf);
        out(0x3ce,5);
        LOCK();
        UNLOCK();
        out(0x3cf,bVar3 & 0xfc);
        LOCK();
        _DAT_001e8654 = _DAT_001e8654 + 3;
        UNLOCK();
        local_a4 = 0;
        do {
          iVar7 = _DAT_001e8654;
          out(0x3ce,(undefined1)local_a4);
          LOCK();
          UNLOCK();
          out(0x3cf,*(undefined1 *)(local_a4 + param_1 + 0xe6));
          LOCK();
          _DAT_001e8654 = _DAT_001e8654 + 2;
          UNLOCK();
          local_a4 = local_a4 + 1;
        } while ((int)local_a4 < 9);
        bVar3 = *(byte *)(param_1 + 0xf1);
        out(0x3c4,2);
        LOCK();
        _DAT_001e8654 = iVar7 + 3;
        UNLOCK();
        uVar5 = 0x3c5;
      }
      out(uVar5,bVar3);
      LOCK();
      _DAT_001e8654 = _DAT_001e8654 + 1;
      UNLOCK();
    }
    *(undefined4 *)(param_1 + 0xa4) = 0;
    *(undefined4 *)(param_1 + 0xc0) = 0;
    iVar4 = _DAT_001e8654;
    uVar11 = *(int *)(param_1 + 0x8c) - 3;
    uVar6 = *(int *)(param_1 + 0x8c) + 3 + param_2;
    iVar7 = *(int *)(param_1 + 0x10);
    out(0x3ce,0);
    LOCK();
    UNLOCK();
    out(0x3cf,*(undefined1 *)(param_1 + 0xb4));
    LOCK();
    UNLOCK();
    out(0x3ce,8);
    LOCK();
    _DAT_001e8654 = _DAT_001e8654 + 3;
    UNLOCK();
    iVar12 = (int)uVar11 >> 3;
    bVar3 = (&DAT_001e4685)[uVar11 & 7];
    bVar1 = (&DAT_001e468d)[uVar6 & 7];
    puVar8 = (undefined1 *)
             ((*(int *)(param_1 + 0x90) + -3) * iVar7 + *(int *)(param_1 + 0x18) + iVar12);
    iVar12 = ((int)uVar6 >> 3) - iVar12;
    if (iVar12 == 0) {
      out(0x3cf,bVar1 & bVar3);
      LOCK();
      _DAT_001e8654 = iVar4 + 4;
      UNLOCK();
      local_a0 = 0;
      do {
        *puVar8 = 0xff;
        puVar8 = puVar8 + iVar7;
        local_a0 = local_a0 + -1;
      } while (-1 < local_a0);
    }
    else {
      local_a0 = 0;
      do {
        out(0x3cf,bVar3);
        LOCK();
        _DAT_001e8654 = _DAT_001e8654 + 1;
        UNLOCK();
        *puVar8 = 0xff;
        out(0x3cf,0xff);
        LOCK();
        _DAT_001e8654 = _DAT_001e8654 + 1;
        UNLOCK();
        puVar10 = puVar8;
        for (iVar4 = iVar12 + -2; puVar10 = puVar10 + 1, -1 < iVar4; iVar4 = iVar4 + -1) {
          *puVar10 = 0xff;
        }
        out(0x3cf,bVar1);
        LOCK();
        _DAT_001e8654 = _DAT_001e8654 + 1;
        UNLOCK();
        *puVar10 = 0xff;
        puVar8 = puVar8 + iVar7;
        local_a0 = local_a0 + -1;
      } while (-1 < local_a0);
    }
    iVar4 = _DAT_001e8654;
    out(0x3cf,0xff);
    LOCK();
    UNLOCK();
    uVar11 = *(int *)(param_1 + 0x8c) - 2;
    uVar6 = *(int *)(param_1 + 0x8c) + 2 + param_2;
    iVar7 = *(int *)(param_1 + 0x10);
    out(0x3ce,0);
    LOCK();
    UNLOCK();
    out(0x3cf,*(undefined1 *)(param_1 + 0xb0));
    LOCK();
    UNLOCK();
    out(0x3ce,8);
    LOCK();
    _DAT_001e8654 = _DAT_001e8654 + 4;
    UNLOCK();
    iVar12 = (int)uVar11 >> 3;
    bVar3 = (&DAT_001e4685)[uVar11 & 7];
    bVar1 = (&DAT_001e468d)[uVar6 & 7];
    puVar8 = (undefined1 *)
             ((*(int *)(param_1 + 0x90) + -2) * iVar7 + *(int *)(param_1 + 0x18) + iVar12);
    iVar12 = ((int)uVar6 >> 3) - iVar12;
    if (iVar12 == 0) {
      out(0x3cf,bVar1 & bVar3);
      LOCK();
      _DAT_001e8654 = iVar4 + 5;
      UNLOCK();
      local_a0 = 1;
      do {
        *puVar8 = 0xff;
        puVar8 = puVar8 + iVar7;
        local_a0 = local_a0 + -1;
      } while (-1 < local_a0);
    }
    else {
      local_a0 = 1;
      do {
        out(0x3cf,bVar3);
        LOCK();
        _DAT_001e8654 = _DAT_001e8654 + 1;
        UNLOCK();
        *puVar8 = 0xff;
        out(0x3cf,0xff);
        LOCK();
        _DAT_001e8654 = _DAT_001e8654 + 1;
        UNLOCK();
        puVar10 = puVar8;
        for (iVar4 = iVar12 + -2; puVar10 = puVar10 + 1, -1 < iVar4; iVar4 = iVar4 + -1) {
          *puVar10 = 0xff;
        }
        out(0x3cf,bVar1);
        LOCK();
        _DAT_001e8654 = _DAT_001e8654 + 1;
        UNLOCK();
        *puVar10 = 0xff;
        puVar8 = puVar8 + iVar7;
        local_a0 = local_a0 + -1;
      } while (-1 < local_a0);
    }
    iVar4 = _DAT_001e8654;
    out(0x3cf,0xff);
    LOCK();
    UNLOCK();
    uVar11 = *(int *)(param_1 + 0x8c) - 2;
    uVar6 = *(int *)(param_1 + 0x8c) + 2 + param_2;
    iVar7 = *(int *)(param_1 + 0x10);
    out(0x3ce,0);
    LOCK();
    UNLOCK();
    out(0x3cf,*(undefined1 *)(param_1 + 0xb0));
    LOCK();
    UNLOCK();
    out(0x3ce,8);
    LOCK();
    _DAT_001e8654 = _DAT_001e8654 + 4;
    UNLOCK();
    iVar12 = (int)uVar11 >> 3;
    bVar3 = (&DAT_001e4685)[uVar11 & 7];
    bVar1 = (&DAT_001e468d)[uVar6 & 7];
    puVar8 = (undefined1 *)
             ((param_3 + *(int *)(param_1 + 0x90)) * iVar7 + *(int *)(param_1 + 0x18) + iVar12);
    iVar12 = ((int)uVar6 >> 3) - iVar12;
    if (iVar12 == 0) {
      out(0x3cf,bVar1 & bVar3);
      LOCK();
      _DAT_001e8654 = iVar4 + 5;
      UNLOCK();
      local_a0 = 1;
      do {
        *puVar8 = 0xff;
        puVar8 = puVar8 + iVar7;
        local_a0 = local_a0 + -1;
      } while (-1 < local_a0);
    }
    else {
      local_a0 = 1;
      do {
        out(0x3cf,bVar3);
        LOCK();
        _DAT_001e8654 = _DAT_001e8654 + 1;
        UNLOCK();
        *puVar8 = 0xff;
        out(0x3cf,0xff);
        LOCK();
        _DAT_001e8654 = _DAT_001e8654 + 1;
        UNLOCK();
        puVar10 = puVar8;
        for (iVar4 = iVar12 + -2; puVar10 = puVar10 + 1, -1 < iVar4; iVar4 = iVar4 + -1) {
          *puVar10 = 0xff;
        }
        out(0x3cf,bVar1);
        LOCK();
        _DAT_001e8654 = _DAT_001e8654 + 1;
        UNLOCK();
        *puVar10 = 0xff;
        puVar8 = puVar8 + iVar7;
        local_a0 = local_a0 + -1;
      } while (-1 < local_a0);
    }
    iVar4 = _DAT_001e8654;
    out(0x3cf,0xff);
    LOCK();
    UNLOCK();
    uVar11 = *(int *)(param_1 + 0x8c) - 3;
    uVar6 = *(int *)(param_1 + 0x8c) + 3 + param_2;
    iVar7 = *(int *)(param_1 + 0x10);
    out(0x3ce,0);
    LOCK();
    UNLOCK();
    out(0x3cf,*(undefined1 *)(param_1 + 0xb4));
    LOCK();
    UNLOCK();
    out(0x3ce,8);
    LOCK();
    _DAT_001e8654 = _DAT_001e8654 + 4;
    UNLOCK();
    iVar12 = (int)uVar11 >> 3;
    bVar3 = (&DAT_001e4685)[uVar11 & 7];
    bVar1 = (&DAT_001e468d)[uVar6 & 7];
    local_90 = (undefined1 *)
               ((param_3 + *(int *)(param_1 + 0x90) + 2) * iVar7 + *(int *)(param_1 + 0x18) + iVar12
               );
    iVar12 = ((int)uVar6 >> 3) - iVar12;
    if (iVar12 == 0) {
      out(0x3cf,bVar1 & bVar3);
      LOCK();
      _DAT_001e8654 = iVar4 + 5;
      UNLOCK();
      local_a0 = 0;
      do {
        *local_90 = 0xff;
        local_90 = local_90 + iVar7;
        local_a0 = local_a0 + -1;
      } while (-1 < local_a0);
    }
    else {
      local_a0 = 0;
      do {
        out(0x3cf,bVar3);
        LOCK();
        _DAT_001e8654 = _DAT_001e8654 + 1;
        UNLOCK();
        *local_90 = 0xff;
        out(0x3cf,0xff);
        LOCK();
        _DAT_001e8654 = _DAT_001e8654 + 1;
        UNLOCK();
        puVar8 = local_90;
        for (iVar4 = iVar12 + -2; puVar8 = puVar8 + 1, -1 < iVar4; iVar4 = iVar4 + -1) {
          *puVar8 = 0xff;
        }
        out(0x3cf,bVar1);
        LOCK();
        _DAT_001e8654 = _DAT_001e8654 + 1;
        UNLOCK();
        *puVar8 = 0xff;
        local_90 = local_90 + iVar7;
        local_a0 = local_a0 + -1;
      } while (-1 < local_a0);
    }
    iVar4 = _DAT_001e8654;
    out(0x3cf,0xff);
    LOCK();
    UNLOCK();
    uVar11 = *(int *)(param_1 + 0x8c) - 3;
    uVar6 = *(int *)(param_1 + 0x8c) - 2;
    iVar7 = *(int *)(param_1 + 0x10);
    out(0x3ce,0);
    LOCK();
    UNLOCK();
    out(0x3cf,*(undefined1 *)(param_1 + 0xb4));
    LOCK();
    UNLOCK();
    out(0x3ce,8);
    LOCK();
    _DAT_001e8654 = _DAT_001e8654 + 4;
    UNLOCK();
    iVar12 = (int)uVar11 >> 3;
    bVar3 = (&DAT_001e4685)[uVar11 & 7];
    bVar1 = (&DAT_001e468d)[uVar6 & 7];
    puVar8 = (undefined1 *)
             ((*(int *)(param_1 + 0x90) + -3) * iVar7 + *(int *)(param_1 + 0x18) + iVar12);
    iVar12 = ((int)uVar6 >> 3) - iVar12;
    if (iVar12 == 0) {
      out(0x3cf,bVar1 & bVar3);
      LOCK();
      _DAT_001e8654 = iVar4 + 5;
      UNLOCK();
      for (iVar4 = param_3 + 5; -1 < iVar4; iVar4 = iVar4 + -1) {
        *puVar8 = 0xff;
        puVar8 = puVar8 + iVar7;
      }
    }
    else {
      for (iVar4 = param_3 + 5; -1 < iVar4; iVar4 = iVar4 + -1) {
        out(0x3cf,bVar3);
        LOCK();
        _DAT_001e8654 = _DAT_001e8654 + 1;
        UNLOCK();
        *puVar8 = 0xff;
        out(0x3cf,0xff);
        LOCK();
        _DAT_001e8654 = _DAT_001e8654 + 1;
        UNLOCK();
        puVar10 = puVar8;
        for (iVar9 = iVar12 + -2; puVar10 = puVar10 + 1, -1 < iVar9; iVar9 = iVar9 + -1) {
          *puVar10 = 0xff;
        }
        out(0x3cf,bVar1);
        LOCK();
        _DAT_001e8654 = _DAT_001e8654 + 1;
        UNLOCK();
        *puVar10 = 0xff;
        puVar8 = puVar8 + iVar7;
      }
    }
    iVar4 = _DAT_001e8654;
    out(0x3cf,0xff);
    LOCK();
    UNLOCK();
    uVar6 = *(uint *)(param_1 + 0x8c);
    iVar7 = *(int *)(param_1 + 0x10);
    out(0x3ce,0);
    LOCK();
    UNLOCK();
    out(0x3cf,*(undefined1 *)(param_1 + 0xb0));
    LOCK();
    UNLOCK();
    out(0x3ce,8);
    LOCK();
    _DAT_001e8654 = _DAT_001e8654 + 4;
    UNLOCK();
    iVar12 = (int)(uVar6 - 2) >> 3;
    bVar3 = (&DAT_001e4685)[uVar6 - 2 & 7];
    bVar1 = (&DAT_001e468d)[uVar6 & 7];
    puVar8 = (undefined1 *)
             ((*(int *)(param_1 + 0x90) + -2) * iVar7 + *(int *)(param_1 + 0x18) + iVar12);
    iVar12 = ((int)uVar6 >> 3) - iVar12;
    if (iVar12 == 0) {
      out(0x3cf,bVar1 & bVar3);
      LOCK();
      _DAT_001e8654 = iVar4 + 5;
      UNLOCK();
      for (iVar4 = param_3 + 3; -1 < iVar4; iVar4 = iVar4 + -1) {
        *puVar8 = 0xff;
        puVar8 = puVar8 + iVar7;
      }
    }
    else {
      for (iVar4 = param_3 + 3; -1 < iVar4; iVar4 = iVar4 + -1) {
        out(0x3cf,bVar3);
        LOCK();
        _DAT_001e8654 = _DAT_001e8654 + 1;
        UNLOCK();
        *puVar8 = 0xff;
        out(0x3cf,0xff);
        LOCK();
        _DAT_001e8654 = _DAT_001e8654 + 1;
        UNLOCK();
        puVar10 = puVar8;
        for (iVar9 = iVar12 + -2; puVar10 = puVar10 + 1, -1 < iVar9; iVar9 = iVar9 + -1) {
          *puVar10 = 0xff;
        }
        out(0x3cf,bVar1);
        LOCK();
        _DAT_001e8654 = _DAT_001e8654 + 1;
        UNLOCK();
        *puVar10 = 0xff;
        puVar8 = puVar8 + iVar7;
      }
    }
    iVar4 = _DAT_001e8654;
    out(0x3cf,0xff);
    LOCK();
    UNLOCK();
    uVar6 = param_2 + *(int *)(param_1 + 0x8c);
    iVar7 = *(int *)(param_1 + 0x10);
    out(0x3ce,0);
    LOCK();
    UNLOCK();
    out(0x3cf,*(undefined1 *)(param_1 + 0xb0));
    LOCK();
    UNLOCK();
    out(0x3ce,8);
    LOCK();
    _DAT_001e8654 = _DAT_001e8654 + 4;
    UNLOCK();
    bVar3 = (&DAT_001e4685)[uVar6 & 7];
    bVar1 = (&DAT_001e468d)[uVar6 + 2 & 7];
    puVar8 = (undefined1 *)
             ((*(int *)(param_1 + 0x90) + -2) * iVar7 + *(int *)(param_1 + 0x18) + ((int)uVar6 >> 3)
             );
    iVar12 = ((int)(uVar6 + 2) >> 3) - ((int)uVar6 >> 3);
    if (iVar12 == 0) {
      out(0x3cf,bVar1 & bVar3);
      LOCK();
      _DAT_001e8654 = iVar4 + 5;
      UNLOCK();
      for (iVar4 = param_3 + 3; -1 < iVar4; iVar4 = iVar4 + -1) {
        *puVar8 = 0xff;
        puVar8 = puVar8 + iVar7;
      }
    }
    else {
      for (iVar4 = param_3 + 3; -1 < iVar4; iVar4 = iVar4 + -1) {
        out(0x3cf,bVar3);
        LOCK();
        _DAT_001e8654 = _DAT_001e8654 + 1;
        UNLOCK();
        *puVar8 = 0xff;
        out(0x3cf,0xff);
        LOCK();
        _DAT_001e8654 = _DAT_001e8654 + 1;
        UNLOCK();
        puVar10 = puVar8;
        for (iVar9 = iVar12 + -2; puVar10 = puVar10 + 1, -1 < iVar9; iVar9 = iVar9 + -1) {
          *puVar10 = 0xff;
        }
        out(0x3cf,bVar1);
        LOCK();
        _DAT_001e8654 = _DAT_001e8654 + 1;
        UNLOCK();
        *puVar10 = 0xff;
        puVar8 = puVar8 + iVar7;
      }
    }
    iVar4 = _DAT_001e8654;
    out(0x3cf,0xff);
    LOCK();
    UNLOCK();
    iVar7 = param_2 + *(int *)(param_1 + 0x8c);
    uVar6 = iVar7 + 2;
    uVar11 = iVar7 + 3;
    iVar7 = *(int *)(param_1 + 0x10);
    out(0x3ce,0);
    LOCK();
    UNLOCK();
    out(0x3cf,*(undefined1 *)(param_1 + 0xb4));
    LOCK();
    UNLOCK();
    out(0x3ce,8);
    LOCK();
    _DAT_001e8654 = _DAT_001e8654 + 4;
    UNLOCK();
    iVar12 = (int)uVar6 >> 3;
    bVar3 = (&DAT_001e4685)[uVar6 & 7];
    bVar1 = (&DAT_001e468d)[uVar11 & 7];
    puVar8 = (undefined1 *)
             ((*(int *)(param_1 + 0x90) + -3) * iVar7 + *(int *)(param_1 + 0x18) + iVar12);
    iVar12 = ((int)uVar11 >> 3) - iVar12;
    if (iVar12 == 0) {
      out(0x3cf,bVar1 & bVar3);
      LOCK();
      _DAT_001e8654 = iVar4 + 5;
      UNLOCK();
      for (param_3 = param_3 + 5; -1 < param_3; param_3 = param_3 + -1) {
        *puVar8 = 0xff;
        puVar8 = puVar8 + iVar7;
      }
    }
    else {
      for (param_3 = param_3 + 5; -1 < param_3; param_3 = param_3 + -1) {
        out(0x3cf,bVar3);
        LOCK();
        _DAT_001e8654 = _DAT_001e8654 + 1;
        UNLOCK();
        *puVar8 = 0xff;
        out(0x3cf,0xff);
        LOCK();
        _DAT_001e8654 = _DAT_001e8654 + 1;
        UNLOCK();
        puVar10 = puVar8;
        for (iVar4 = iVar12 + -2; puVar10 = puVar10 + 1, -1 < iVar4; iVar4 = iVar4 + -1) {
          *puVar10 = 0xff;
        }
        out(0x3cf,bVar1);
        LOCK();
        _DAT_001e8654 = _DAT_001e8654 + 1;
        UNLOCK();
        *puVar10 = 0xff;
        puVar8 = puVar8 + iVar7;
      }
    }
    iVar12 = _DAT_001e8654;
    out(0x3cf,0xff);
    LOCK();
    UNLOCK();
    uVar6 = *(uint *)(param_1 + 0x8c);
    iVar7 = *(int *)(param_1 + 0xa0);
    uVar11 = uVar6 + *(int *)(param_1 + 0x98);
    iVar4 = *(int *)(param_1 + 0x10);
    out(0x3ce,0);
    LOCK();
    UNLOCK();
    out(0x3cf,*(undefined1 *)(param_1 + 0xb0));
    LOCK();
    UNLOCK();
    out(0x3ce,8);
    LOCK();
    _DAT_001e8654 = _DAT_001e8654 + 4;
    UNLOCK();
    bVar3 = (&DAT_001e4685)[uVar6 & 7];
    bVar1 = (&DAT_001e468d)[uVar11 & 7];
    puVar8 = (undefined1 *)
             (*(int *)(param_1 + 0x90) * iVar4 + *(int *)(param_1 + 0x18) + ((int)uVar6 >> 3));
    iVar9 = ((int)uVar11 >> 3) - ((int)uVar6 >> 3);
    if (iVar9 == 0) {
      out(0x3cf,bVar1 & bVar3);
      LOCK();
      _DAT_001e8654 = iVar12 + 5;
      UNLOCK();
      while (iVar7 = iVar7 + -1, -1 < iVar7) {
        *puVar8 = 0xff;
        puVar8 = puVar8 + iVar4;
      }
    }
    else {
      while (iVar7 = iVar7 + -1, -1 < iVar7) {
        out(0x3cf,bVar3);
        LOCK();
        _DAT_001e8654 = _DAT_001e8654 + 1;
        UNLOCK();
        *puVar8 = 0xff;
        out(0x3cf,0xff);
        LOCK();
        _DAT_001e8654 = _DAT_001e8654 + 1;
        UNLOCK();
        puVar10 = puVar8;
        for (iVar12 = iVar9 + -2; puVar10 = puVar10 + 1, -1 < iVar12; iVar12 = iVar12 + -1) {
          *puVar10 = 0xff;
        }
        out(0x3cf,bVar1);
        LOCK();
        _DAT_001e8654 = _DAT_001e8654 + 1;
        UNLOCK();
        *puVar10 = 0xff;
        puVar8 = puVar8 + iVar4;
      }
    }
    out(0x3cf,0xff);
    LOCK();
    _DAT_001e8654 = _DAT_001e8654 + 1;
    UNLOCK();
    FUN_00197ca0(param_1);
    FUN_00198adc(param_1,param_4);
  }
  return;
}

