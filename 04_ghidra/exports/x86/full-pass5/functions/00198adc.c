/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00198adc */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00198adc(int param_1,char *param_2)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  undefined4 uVar5;
  undefined1 *puVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  undefined1 *puVar12;
  int iVar13;
  int iVar14;
  char *pcVar15;
  undefined1 *local_64;
  int local_5c;
  int local_58;
  int local_c;
  
  local_c = *(int *)(param_1 + 0xa4);
  iVar4 = *(int *)(param_1 + 0xa8);
  uVar7 = 0xffffffff;
  pcVar15 = param_2;
  do {
    if (uVar7 == 0) break;
    uVar7 = uVar7 - 1;
    cVar1 = *pcVar15;
    pcVar15 = pcVar15 + 1;
  } while (cVar1 != '\0');
  iVar10 = ~uVar7 - 1;
  if ((iVar10 == 0) || (*(int *)(param_1 + 0x94) < iVar10)) {
    _IOLog(s_console__Illegal_title_length____001e4695,iVar10);
  }
  else {
    FUN_00197ca0(param_1);
    if (*(int *)(param_1 + 0xc0) != 0) {
      *(int *)(param_1 + 0x90) = *(int *)(param_1 + 0x90) + -0x18;
      *(int *)(param_1 + 0x9c) = *(int *)(param_1 + 0x9c) + 2;
      *(int *)(param_1 + 0xa0) = *(int *)(param_1 + 0xa0) + 0x18;
      local_c = local_c + 2;
    }
    *(undefined4 *)(param_1 + 0xa4) = 0;
    iVar13 = _DAT_001e8654;
    uVar7 = *(uint *)(param_1 + 0x8c);
    uVar11 = uVar7 + *(int *)(param_1 + 0x94) * 8;
    iVar9 = *(int *)(param_1 + 0x10);
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
    bVar2 = (&DAT_001e4685)[uVar7 & 7];
    bVar3 = (&DAT_001e468d)[uVar11 & 7];
    puVar12 = (undefined1 *)
              (*(int *)(param_1 + 0x90) * iVar9 + *(int *)(param_1 + 0x18) + ((int)uVar7 >> 3));
    iVar8 = ((int)uVar11 >> 3) - ((int)uVar7 >> 3);
    if (iVar8 == 0) {
      out(0x3cf,bVar3 & bVar2);
      LOCK();
      _DAT_001e8654 = iVar13 + 4;
      UNLOCK();
      iVar13 = 0x15;
      do {
        *puVar12 = 0xff;
        puVar12 = puVar12 + iVar9;
        iVar13 = iVar13 + -1;
      } while (-1 < iVar13);
    }
    else {
      iVar13 = 0x15;
      do {
        out(0x3cf,bVar2);
        LOCK();
        _DAT_001e8654 = _DAT_001e8654 + 1;
        UNLOCK();
        *puVar12 = 0xff;
        out(0x3cf,0xff);
        LOCK();
        _DAT_001e8654 = _DAT_001e8654 + 1;
        UNLOCK();
        puVar6 = puVar12;
        for (iVar14 = iVar8 + -2; puVar6 = puVar6 + 1, -1 < iVar14; iVar14 = iVar14 + -1) {
          *puVar6 = 0xff;
        }
        out(0x3cf,bVar3);
        LOCK();
        _DAT_001e8654 = _DAT_001e8654 + 1;
        UNLOCK();
        *puVar6 = 0xff;
        puVar12 = puVar12 + iVar9;
        iVar13 = iVar13 + -1;
      } while (-1 < iVar13);
    }
    out(0x3cf,0xff);
    LOCK();
    _DAT_001e8654 = _DAT_001e8654 + 1;
    UNLOCK();
    iVar9 = *(int *)(param_1 + 0x90);
    *(int *)(param_1 + 0x90) = iVar9 + 6;
    *(int *)(param_1 + 0xa8) = (*(int *)(param_1 + 0x94) - iVar10) / 2;
    FUN_00197ca0(param_1);
    uVar5 = *(undefined4 *)(param_1 + 0xb4);
    *(undefined4 *)(param_1 + 0xb4) = *(undefined4 *)(param_1 + 0xb0);
    *(undefined4 *)(param_1 + 0xb0) = uVar5;
    cVar1 = *param_2;
    while (cVar1 != '\0') {
      cVar1 = *param_2;
      param_2 = param_2 + 1;
      FUN_00198098(param_1,(int)cVar1);
      cVar1 = *param_2;
    }
    uVar5 = *(undefined4 *)(param_1 + 0xb4);
    *(undefined4 *)(param_1 + 0xb4) = *(undefined4 *)(param_1 + 0xb0);
    *(undefined4 *)(param_1 + 0xb0) = uVar5;
    FUN_00197ca0(param_1);
    *(int *)(param_1 + 0x90) = iVar9;
    iVar13 = _DAT_001e8654;
    uVar7 = *(int *)(param_1 + 0x8c) - 2;
    uVar11 = uVar7 + *(int *)(param_1 + 0x98) + 4;
    iVar10 = *(int *)(param_1 + 0x10);
    out(0x3ce,0);
    LOCK();
    UNLOCK();
    out(0x3cf,*(undefined1 *)(param_1 + 0xbc));
    LOCK();
    UNLOCK();
    out(0x3ce,8);
    LOCK();
    _DAT_001e8654 = _DAT_001e8654 + 3;
    UNLOCK();
    bVar2 = (&DAT_001e4685)[uVar7 & 7];
    bVar3 = (&DAT_001e468d)[uVar11 & 7];
    puVar12 = (undefined1 *)((iVar9 + -2) * iVar10 + *(int *)(param_1 + 0x18) + ((int)uVar7 >> 3));
    iVar9 = ((int)uVar11 >> 3) - ((int)uVar7 >> 3);
    if (iVar9 == 0) {
      out(0x3cf,bVar3 & bVar2);
      LOCK();
      _DAT_001e8654 = iVar13 + 4;
      UNLOCK();
      iVar9 = 1;
      do {
        *puVar12 = 0xff;
        puVar12 = puVar12 + iVar10;
        iVar9 = iVar9 + -1;
      } while (-1 < iVar9);
    }
    else {
      iVar13 = 1;
      do {
        out(0x3cf,bVar2);
        LOCK();
        _DAT_001e8654 = _DAT_001e8654 + 1;
        UNLOCK();
        *puVar12 = 0xff;
        out(0x3cf,0xff);
        LOCK();
        _DAT_001e8654 = _DAT_001e8654 + 1;
        UNLOCK();
        puVar6 = puVar12;
        for (iVar8 = iVar9 + -2; puVar6 = puVar6 + 1, -1 < iVar8; iVar8 = iVar8 + -1) {
          *puVar6 = 0xff;
        }
        out(0x3cf,bVar3);
        LOCK();
        _DAT_001e8654 = _DAT_001e8654 + 1;
        UNLOCK();
        *puVar6 = 0xff;
        puVar12 = puVar12 + iVar10;
        iVar13 = iVar13 + -1;
      } while (-1 < iVar13);
    }
    iVar9 = _DAT_001e8654;
    out(0x3cf,0xff);
    LOCK();
    UNLOCK();
    uVar7 = *(int *)(param_1 + 0x8c) - 2;
    uVar11 = uVar7 + *(int *)(param_1 + 0x98) + 4;
    iVar10 = *(int *)(param_1 + 0x10);
    out(0x3ce,0);
    LOCK();
    UNLOCK();
    out(0x3cf,*(undefined1 *)(param_1 + 0xb8));
    LOCK();
    UNLOCK();
    out(0x3ce,8);
    LOCK();
    _DAT_001e8654 = _DAT_001e8654 + 4;
    UNLOCK();
    bVar2 = (&DAT_001e4685)[uVar7 & 7];
    bVar3 = (&DAT_001e468d)[uVar11 & 7];
    puVar12 = (undefined1 *)
              ((*(int *)(param_1 + 0x90) + 0x13) * iVar10 + *(int *)(param_1 + 0x18) +
              ((int)uVar7 >> 3));
    iVar13 = ((int)uVar11 >> 3) - ((int)uVar7 >> 3);
    if (iVar13 == 0) {
      out(0x3cf,bVar3 & bVar2);
      LOCK();
      _DAT_001e8654 = iVar9 + 5;
      UNLOCK();
      iVar9 = 1;
      do {
        *puVar12 = 0xff;
        puVar12 = puVar12 + iVar10;
        iVar9 = iVar9 + -1;
      } while (-1 < iVar9);
    }
    else {
      iVar9 = 1;
      do {
        out(0x3cf,bVar2);
        LOCK();
        _DAT_001e8654 = _DAT_001e8654 + 1;
        UNLOCK();
        *puVar12 = 0xff;
        out(0x3cf,0xff);
        LOCK();
        _DAT_001e8654 = _DAT_001e8654 + 1;
        UNLOCK();
        puVar6 = puVar12;
        for (iVar8 = iVar13 + -2; puVar6 = puVar6 + 1, -1 < iVar8; iVar8 = iVar8 + -1) {
          *puVar6 = 0xff;
        }
        out(0x3cf,bVar3);
        LOCK();
        _DAT_001e8654 = _DAT_001e8654 + 1;
        UNLOCK();
        *puVar6 = 0xff;
        puVar12 = puVar12 + iVar10;
        iVar9 = iVar9 + -1;
      } while (-1 < iVar9);
    }
    out(0x3cf,0xff);
    LOCK();
    _DAT_001e8654 = _DAT_001e8654 + 1;
    UNLOCK();
    iVar10 = 0;
    local_5c = 0x17;
    do {
      iVar8 = _DAT_001e8654;
      iVar9 = iVar10 + *(int *)(param_1 + 0x8c);
      uVar11 = iVar9 - 2;
      uVar7 = iVar9 - 1;
      iVar9 = *(int *)(param_1 + 0x10);
      out(0x3ce,0);
      LOCK();
      UNLOCK();
      out(0x3cf,*(undefined1 *)(param_1 + 0xbc));
      LOCK();
      UNLOCK();
      out(0x3ce,8);
      LOCK();
      _DAT_001e8654 = _DAT_001e8654 + 3;
      UNLOCK();
      iVar14 = (int)uVar11 >> 3;
      bVar2 = (&DAT_001e4685)[uVar11 & 7];
      bVar3 = (&DAT_001e468d)[uVar7 & 7];
      puVar12 = (undefined1 *)
                ((iVar10 + *(int *)(param_1 + 0x90) + -2) * iVar9 + *(int *)(param_1 + 0x18) +
                iVar14);
      iVar14 = ((int)uVar7 >> 3) - iVar14;
      iVar13 = local_5c;
      if (iVar14 == 0) {
        out(0x3cf,bVar3 & bVar2);
        LOCK();
        _DAT_001e8654 = iVar8 + 4;
        UNLOCK();
        while (iVar13 = iVar13 + -1, -1 < iVar13) {
          *puVar12 = 0xff;
          puVar12 = puVar12 + iVar9;
        }
      }
      else {
        while (-1 < iVar13 + -1) {
          out(0x3cf,bVar2);
          LOCK();
          _DAT_001e8654 = _DAT_001e8654 + 1;
          UNLOCK();
          *puVar12 = 0xff;
          out(0x3cf,0xff);
          LOCK();
          _DAT_001e8654 = _DAT_001e8654 + 1;
          UNLOCK();
          puVar6 = puVar12;
          for (iVar8 = iVar14 + -2; puVar6 = puVar6 + 1, -1 < iVar8; iVar8 = iVar8 + -1) {
            *puVar6 = 0xff;
          }
          out(0x3cf,bVar3);
          LOCK();
          _DAT_001e8654 = _DAT_001e8654 + 1;
          UNLOCK();
          *puVar6 = 0xff;
          puVar12 = puVar12 + iVar9;
          iVar13 = iVar13 + -1;
        }
      }
      out(0x3cf,0xff);
      LOCK();
      _DAT_001e8654 = _DAT_001e8654 + 1;
      UNLOCK();
      local_5c = local_5c + -2;
      iVar10 = iVar10 + 1;
    } while (iVar10 < 2);
    iVar10 = 1;
    local_58 = 0x15;
    do {
      iVar8 = _DAT_001e8654;
      uVar7 = iVar10 + -1 + *(int *)(param_1 + 0x8c) + *(int *)(param_1 + 0x98);
      iVar9 = *(int *)(param_1 + 0x10);
      out(0x3ce,0);
      LOCK();
      UNLOCK();
      out(0x3cf,*(undefined1 *)(param_1 + 0xb8));
      LOCK();
      UNLOCK();
      out(0x3ce,8);
      LOCK();
      _DAT_001e8654 = _DAT_001e8654 + 3;
      UNLOCK();
      bVar2 = (&DAT_001e4685)[uVar7 & 7];
      bVar3 = (&DAT_001e468d)[uVar7 + 1 & 7];
      puVar12 = (undefined1 *)
                ((*(int *)(param_1 + 0x90) - iVar10) * iVar9 + *(int *)(param_1 + 0x18) +
                ((int)uVar7 >> 3));
      iVar14 = ((int)(uVar7 + 1) >> 3) - ((int)uVar7 >> 3);
      iVar13 = local_58;
      if (iVar14 == 0) {
        out(0x3cf,bVar3 & bVar2);
        LOCK();
        _DAT_001e8654 = iVar8 + 4;
        UNLOCK();
        while (iVar13 = iVar13 + -1, -1 < iVar13) {
          *puVar12 = 0xff;
          puVar12 = puVar12 + iVar9;
        }
      }
      else {
        while (-1 < iVar13 + -1) {
          out(0x3cf,bVar2);
          LOCK();
          _DAT_001e8654 = _DAT_001e8654 + 1;
          UNLOCK();
          *puVar12 = 0xff;
          out(0x3cf,0xff);
          LOCK();
          _DAT_001e8654 = _DAT_001e8654 + 1;
          UNLOCK();
          puVar6 = puVar12;
          for (iVar8 = iVar14 + -2; puVar6 = puVar6 + 1, -1 < iVar8; iVar8 = iVar8 + -1) {
            *puVar6 = 0xff;
          }
          out(0x3cf,bVar3);
          LOCK();
          _DAT_001e8654 = _DAT_001e8654 + 1;
          UNLOCK();
          *puVar6 = 0xff;
          puVar12 = puVar12 + iVar9;
          iVar13 = iVar13 + -1;
        }
      }
      iVar9 = _DAT_001e8654;
      out(0x3cf,0xff);
      LOCK();
      _DAT_001e8654 = _DAT_001e8654 + 1;
      UNLOCK();
      local_58 = local_58 + 2;
      iVar10 = iVar10 + 1;
    } while (iVar10 < 3);
    uVar7 = *(int *)(param_1 + 0x8c) - 3;
    uVar11 = uVar7 + *(int *)(param_1 + 0x98) + 6;
    iVar10 = *(int *)(param_1 + 0x10);
    out(0x3ce,0);
    LOCK();
    UNLOCK();
    out(0x3cf,*(undefined1 *)(param_1 + 0xb4));
    LOCK();
    UNLOCK();
    out(0x3ce,8);
    LOCK();
    _DAT_001e8654 = iVar9 + 4;
    UNLOCK();
    bVar2 = (&DAT_001e4685)[uVar7 & 7];
    bVar3 = (&DAT_001e468d)[uVar11 & 7];
    puVar12 = (undefined1 *)
              ((*(int *)(param_1 + 0x90) + 0x15) * iVar10 + *(int *)(param_1 + 0x18) +
              ((int)uVar7 >> 3));
    iVar13 = ((int)uVar11 >> 3) - ((int)uVar7 >> 3);
    if (iVar13 == 0) {
      out(0x3cf,bVar3 & bVar2);
      LOCK();
      _DAT_001e8654 = iVar9 + 5;
      UNLOCK();
      iVar9 = 0;
      do {
        *puVar12 = 0xff;
        puVar12 = puVar12 + iVar10;
        iVar9 = iVar9 + -1;
      } while (-1 < iVar9);
    }
    else {
      iVar9 = 0;
      do {
        out(0x3cf,bVar2);
        LOCK();
        _DAT_001e8654 = _DAT_001e8654 + 1;
        UNLOCK();
        *puVar12 = 0xff;
        out(0x3cf,0xff);
        LOCK();
        _DAT_001e8654 = _DAT_001e8654 + 1;
        UNLOCK();
        puVar6 = puVar12;
        for (iVar8 = iVar13 + -2; puVar6 = puVar6 + 1, -1 < iVar8; iVar8 = iVar8 + -1) {
          *puVar6 = 0xff;
        }
        out(0x3cf,bVar3);
        LOCK();
        _DAT_001e8654 = _DAT_001e8654 + 1;
        UNLOCK();
        *puVar6 = 0xff;
        puVar12 = puVar12 + iVar10;
        iVar9 = iVar9 + -1;
      } while (-1 < iVar9);
    }
    out(0x3cf,0xff);
    LOCK();
    _DAT_001e8654 = _DAT_001e8654 + 1;
    UNLOCK();
    *(int *)(param_1 + 0x90) = *(int *)(param_1 + 0x90) + 0x18;
    *(int *)(param_1 + 0x9c) = *(int *)(param_1 + 0x9c) + -2;
    *(int *)(param_1 + 0xa0) = *(int *)(param_1 + 0xa0) + -0x18;
    *(int *)(param_1 + 0xa8) = iVar4;
    iVar10 = _DAT_001e8654;
    if (local_c < 1) {
      uVar7 = *(int *)(param_1 + 0x8c) + iVar4 * 8;
      uVar11 = *(int *)(param_1 + 0x8c) + *(int *)(param_1 + 0x98);
      iVar4 = *(int *)(param_1 + 0x10);
      out(0x3ce,0);
      LOCK();
      UNLOCK();
      out(0x3cf,*(undefined1 *)(param_1 + 0xb0));
      LOCK();
      UNLOCK();
      out(0x3ce,8);
      LOCK();
      _DAT_001e8654 = _DAT_001e8654 + 3;
      UNLOCK();
      iVar9 = (int)uVar7 >> 3;
      bVar2 = (&DAT_001e4685)[uVar7 & 7];
      bVar3 = (&DAT_001e468d)[uVar11 & 7];
      local_64 = (undefined1 *)
                 ((*(int *)(param_1 + 0x90) + *(int *)(param_1 + 0xa4) * 0xc) * iVar4 +
                  *(int *)(param_1 + 0x18) + iVar9);
      iVar9 = ((int)uVar11 >> 3) - iVar9;
      if (iVar9 == 0) {
        out(0x3cf,bVar3 & bVar2);
        LOCK();
        _DAT_001e8654 = iVar10 + 4;
        UNLOCK();
        iVar10 = 0xb;
        do {
          *local_64 = 0xff;
          local_64 = local_64 + iVar4;
          iVar10 = iVar10 + -1;
        } while (-1 < iVar10);
      }
      else {
        iVar10 = 0xb;
        do {
          out(0x3cf,bVar2);
          LOCK();
          _DAT_001e8654 = _DAT_001e8654 + 1;
          UNLOCK();
          *local_64 = 0xff;
          out(0x3cf,0xff);
          LOCK();
          _DAT_001e8654 = _DAT_001e8654 + 1;
          UNLOCK();
          puVar12 = local_64;
          for (iVar13 = iVar9 + -2; puVar12 = puVar12 + 1, -1 < iVar13; iVar13 = iVar13 + -1) {
            *puVar12 = 0xff;
          }
          out(0x3cf,bVar3);
          LOCK();
          _DAT_001e8654 = _DAT_001e8654 + 1;
          UNLOCK();
          *puVar12 = 0xff;
          local_64 = local_64 + iVar4;
          iVar10 = iVar10 + -1;
        } while (-1 < iVar10);
      }
      out(0x3cf,0xff);
      LOCK();
      _DAT_001e8654 = _DAT_001e8654 + 1;
      UNLOCK();
    }
    else {
      *(int *)(param_1 + 0xa4) = local_c + -2;
    }
    FUN_00197ca0(param_1);
    *(undefined4 *)(param_1 + 0xc0) = 1;
  }
  return;
}

