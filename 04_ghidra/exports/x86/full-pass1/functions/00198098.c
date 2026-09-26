/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00198098 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00198098(int *param_1,char param_2)

{
  byte bVar1;
  bool bVar2;
  byte bVar3;
  byte bVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  int iVar11;
  int iVar12;
  int local_48;
  undefined1 *local_44;
  undefined1 *local_40;
  int local_38;
  undefined1 *local_20;
  
  bVar4 = 0;
  bVar2 = false;
  if ((*param_1 == 1) || (*param_1 == 3)) {
    bVar2 = true;
  }
  if (!bVar2) {
    return;
  }
  iVar7 = param_1[0x3d];
  if (iVar7 == 1) {
    if (param_2 == '[') {
      param_1[0x3d] = 2;
      return;
    }
    param_1[0x3d] = 0;
LAB_00198129:
    if ((byte)(param_2 - 0x30U) < 10) {
      *(char *)param_1[0x3f] = (param_2 - 0x30U) + *(char *)param_1[0x3f] * '\n';
      return;
    }
    if (param_2 == ';') {
      if ((int)param_1 + 0xfaU <= (uint)param_1[0x3f]) {
        return;
      }
      param_1[0x3f] = param_1[0x3f] + 1;
      return;
    }
    iVar7 = 0;
    do {
      if (*(char *)(iVar7 + 0xf8 + (int)param_1) == '\0') {
        *(undefined1 *)(iVar7 + 0xf8 + (int)param_1) = 1;
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < 3);
    uVar6 = (uint)*(byte *)param_1[0x3f];
    FUN_00197ca0(param_1);
    iVar7 = _DAT_001e8654;
    switch(param_2) {
    case 'A':
      while (uVar6 = uVar6 - 1, uVar6 != 0xffffffff) {
        if (param_1[0x29] != 0) {
          param_1[0x29] = param_1[0x29] + -1;
        }
      }
      break;
    case 'B':
      while (uVar6 = uVar6 - 1, uVar6 != 0xffffffff) {
        param_1[0x29] = param_1[0x29] + 1;
      }
      break;
    case 'C':
      while (uVar6 = uVar6 - 1, uVar6 != 0xffffffff) {
        param_1[0x2a] = param_1[0x2a] + 1;
      }
      break;
    case 'D':
      while (uVar6 = uVar6 - 1, uVar6 != 0xffffffff) {
        if (param_1[0x2a] != 0) {
          param_1[0x2a] = param_1[0x2a] + -1;
        }
      }
      break;
    case 'E':
      param_1[0x2a] = 0;
      while (uVar6 = uVar6 - 1, uVar6 != 0xffffffff) {
        param_1[0x29] = param_1[0x29] + 1;
      }
      break;
    case 'H':
    case 'f':
      param_1[0x2a] = *(byte *)param_1[0x3f] - 1;
      iVar7 = param_1[0x3f];
      param_1[0x3f] = iVar7 + -1;
      param_1[0x29] = *(byte *)(iVar7 + -1) - 1;
      param_1[0x3f] = param_1[0x3f] + -1;
      break;
    case 'K':
      uVar6 = param_1[0x2a] * 8 + param_1[0x23];
      iVar5 = param_1[4];
      out(0x3ce,0);
      LOCK();
      UNLOCK();
      out(0x3cf,(char)param_1[0x2c]);
      LOCK();
      UNLOCK();
      out(0x3ce,8);
      LOCK();
      _DAT_001e8654 = _DAT_001e8654 + 3;
      UNLOCK();
      iVar11 = (int)uVar6 >> 3;
      bVar3 = (&DAT_001e4685)[uVar6 & 7];
      bVar1 = (&DAT_001e468d)[param_1[0x26] + param_1[0x23] & 7];
      local_44 = (undefined1 *)((param_1[0x24] + param_1[0x29] * 0xc) * iVar5 + param_1[6] + iVar11)
      ;
      iVar11 = (param_1[0x26] + param_1[0x23] >> 3) - iVar11;
      if (iVar11 == 0) {
        out(0x3cf,bVar1 & bVar3);
        LOCK();
        _DAT_001e8654 = iVar7 + 4;
        UNLOCK();
        local_48 = 0xb;
        do {
          *local_44 = 0xff;
          local_44 = local_44 + iVar5;
          local_48 = local_48 + -1;
        } while (-1 < local_48);
      }
      else {
        local_48 = 0xb;
        do {
          out(0x3cf,bVar3);
          LOCK();
          _DAT_001e8654 = _DAT_001e8654 + 1;
          UNLOCK();
          *local_44 = 0xff;
          out(0x3cf,0xff);
          LOCK();
          _DAT_001e8654 = _DAT_001e8654 + 1;
          UNLOCK();
          puVar10 = local_44;
          for (iVar7 = iVar11 + -2; puVar10 = puVar10 + 1, -1 < iVar7; iVar7 = iVar7 + -1) {
            *puVar10 = 0xff;
          }
          out(0x3cf,bVar1);
          LOCK();
          _DAT_001e8654 = _DAT_001e8654 + 1;
          UNLOCK();
          *puVar10 = 0xff;
          local_44 = local_44 + iVar5;
          local_48 = local_48 + -1;
        } while (-1 < local_48);
      }
      out(0x3cf,0xff);
      LOCK();
      _DAT_001e8654 = _DAT_001e8654 + 1;
      UNLOCK();
      break;
    case 'm':
      param_1[0x3f] = param_1[0x3f] + -2;
      if (param_1[0x2c] == param_1[0x2d]) {
        param_1[0x2c] = 3;
        param_1[0x2d] = 0;
      }
    }
    param_1[0x3f] = (int)param_1 + 0xf9;
    iVar7 = 2;
    do {
      *(undefined1 *)(iVar7 + 0xf8 + (int)param_1) = 0;
      iVar7 = iVar7 + -1;
    } while (-1 < iVar7);
    param_1[0x3d] = 0;
  }
  else {
    if (iVar7 == 0) {
      if (param_2 == '\x1b') {
        param_1[0x3d] = 1;
        return;
      }
    }
    else if (iVar7 == 2) goto LAB_00198129;
    FUN_00197ca0(param_1);
    if (param_2 == '\n') {
      param_1[0x2a] = 0;
      param_1[0x29] = param_1[0x29] + 1;
    }
    else {
      if (param_2 < '\v') {
        if (param_2 == '\b') {
          if (param_1[0x2a] != 0) {
            param_1[0x2a] = param_1[0x2a] + -1;
          }
          goto LAB_00198821;
        }
        if (param_2 == '\t') {
          iVar5 = 8 - param_1[0x2a] % 8;
          FUN_00197ca0(param_1);
          iVar7 = 0;
          if (0 < iVar5) {
            do {
              FUN_00198098(param_1,0x20);
              iVar7 = iVar7 + 1;
            } while (iVar7 < iVar5);
          }
          FUN_00197ca0(param_1);
          goto LAB_00198821;
        }
      }
      else {
        if (param_2 == '\r') {
          param_1[0x2a] = 0;
          goto LAB_00198821;
        }
        if (param_2 < '\x0e') {
          if (param_2 == '\f') {
            param_1[0x2a] = 0;
            param_1[0x29] = 0;
            iVar11 = _DAT_001e8654;
            uVar6 = param_1[0x23];
            iVar7 = param_1[0x28];
            iVar5 = param_1[4];
            out(0x3ce,0);
            LOCK();
            UNLOCK();
            out(0x3cf,(char)param_1[0x2c]);
            LOCK();
            UNLOCK();
            out(0x3ce,8);
            LOCK();
            _DAT_001e8654 = _DAT_001e8654 + 3;
            UNLOCK();
            bVar3 = (&DAT_001e4685)[uVar6 & 7];
            bVar1 = (&DAT_001e468d)[uVar6 + param_1[0x26] & 7];
            puVar10 = (undefined1 *)(param_1[0x24] * iVar5 + param_1[6] + ((int)uVar6 >> 3));
            iVar12 = ((int)(uVar6 + param_1[0x26]) >> 3) - ((int)uVar6 >> 3);
            if (iVar12 == 0) {
              out(0x3cf,bVar1 & bVar3);
              LOCK();
              _DAT_001e8654 = iVar11 + 4;
              UNLOCK();
              while (iVar7 = iVar7 + -1, -1 < iVar7) {
                *puVar10 = 0xff;
                puVar10 = puVar10 + iVar5;
              }
            }
            else {
              while (iVar7 = iVar7 + -1, -1 < iVar7) {
                out(0x3cf,bVar3);
                LOCK();
                _DAT_001e8654 = _DAT_001e8654 + 1;
                UNLOCK();
                *puVar10 = 0xff;
                out(0x3cf,0xff);
                LOCK();
                _DAT_001e8654 = _DAT_001e8654 + 1;
                UNLOCK();
                puVar8 = puVar10;
                for (iVar11 = iVar12 + -2; puVar8 = puVar8 + 1, -1 < iVar11; iVar11 = iVar11 + -1) {
                  *puVar8 = 0xff;
                }
                out(0x3cf,bVar1);
                LOCK();
                _DAT_001e8654 = _DAT_001e8654 + 1;
                UNLOCK();
                *puVar8 = 0xff;
                puVar10 = puVar10 + iVar5;
              }
            }
            out(0x3cf,0xff);
            LOCK();
            _DAT_001e8654 = _DAT_001e8654 + 1;
            UNLOCK();
            goto LAB_00198821;
          }
        }
        else if (param_2 == '\x7f') {
          param_1[0x2a] = param_1[0x2a] + 1;
          goto LAB_00198821;
        }
      }
      FUN_00197e58(param_1,(int)param_2);
    }
  }
LAB_00198821:
  if (param_1[0x25] <= param_1[0x2a]) {
    param_1[0x2a] = 0;
    param_1[0x29] = param_1[0x29] + 1;
  }
  if (param_1[0x27] <= param_1[0x29]) {
    param_1[0x29] = param_1[0x27] + -1;
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
    iVar7 = param_1[4];
    puVar8 = (undefined1 *)((param_1[0x24] + 0xc) * iVar7 + param_1[6] + (param_1[0x23] >> 3));
    puVar10 = puVar8 + iVar7 * -0xc;
    local_38 = 0xc;
    iVar5 = param_1[0x28];
    if (0xc < iVar5) {
      iVar11 = param_1[0x26];
      iVar12 = iVar11 >> 3;
      local_20 = puVar10;
      puVar9 = puVar8;
      do {
        for (; iVar12 != 0; iVar12 = iVar12 + -1) {
          *puVar10 = *puVar8;
          puVar8 = puVar8 + (uint)bVar4 * -2 + 1;
          puVar10 = puVar10 + (uint)bVar4 * -2 + 1;
        }
        puVar8 = puVar9 + iVar7;
        puVar10 = local_20 + iVar7;
        local_38 = local_38 + 1;
        iVar12 = iVar11 >> 3;
        local_20 = puVar10;
        puVar9 = puVar8;
      } while (local_38 < iVar5);
    }
    out(0x3ce,5);
    LOCK();
    UNLOCK();
    bVar4 = in(0x3cf);
    out(0x3ce,5);
    LOCK();
    UNLOCK();
    out(0x3cf,bVar4 & 0xfc);
    LOCK();
    _DAT_001e8654 = _DAT_001e8654 + 3;
    UNLOCK();
    param_1[0x2a] = 0;
    iVar5 = _DAT_001e8654;
    uVar6 = param_1[0x23];
    iVar7 = param_1[4];
    out(0x3ce,0);
    LOCK();
    UNLOCK();
    out(0x3cf,(char)param_1[0x2c]);
    LOCK();
    UNLOCK();
    out(0x3ce,8);
    LOCK();
    _DAT_001e8654 = _DAT_001e8654 + 3;
    UNLOCK();
    bVar4 = (&DAT_001e4685)[uVar6 & 7];
    bVar3 = (&DAT_001e468d)[uVar6 + param_1[0x26] & 7];
    local_40 = (undefined1 *)
               ((param_1[0x24] + param_1[0x29] * 0xc) * iVar7 + param_1[6] + ((int)uVar6 >> 3));
    iVar11 = ((int)(uVar6 + param_1[0x26]) >> 3) - ((int)uVar6 >> 3);
    if (iVar11 == 0) {
      out(0x3cf,bVar3 & bVar4);
      LOCK();
      _DAT_001e8654 = iVar5 + 4;
      UNLOCK();
      local_48 = 0xb;
      do {
        *local_40 = 0xff;
        local_40 = local_40 + iVar7;
        local_48 = local_48 + -1;
      } while (-1 < local_48);
    }
    else {
      local_48 = 0xb;
      do {
        out(0x3cf,bVar4);
        LOCK();
        _DAT_001e8654 = _DAT_001e8654 + 1;
        UNLOCK();
        *local_40 = 0xff;
        out(0x3cf,0xff);
        LOCK();
        _DAT_001e8654 = _DAT_001e8654 + 1;
        UNLOCK();
        puVar10 = local_40;
        for (iVar5 = iVar11 + -2; puVar10 = puVar10 + 1, -1 < iVar5; iVar5 = iVar5 + -1) {
          *puVar10 = 0xff;
        }
        out(0x3cf,bVar3);
        LOCK();
        _DAT_001e8654 = _DAT_001e8654 + 1;
        UNLOCK();
        *puVar10 = 0xff;
        local_40 = local_40 + iVar7;
        local_48 = local_48 + -1;
      } while (-1 < local_48);
    }
    out(0x3cf,0xff);
    LOCK();
    _DAT_001e8654 = _DAT_001e8654 + 1;
    UNLOCK();
  }
  FUN_00197ca0(param_1);
  return;
}

