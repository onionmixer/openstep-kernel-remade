/* GHIDRADEC_FUNCTION index=300 start=0x400ce04 */

byte _ttywait(int param_1)

{
  int iVar1;
  char cVar2;
  bool bVar3;
  bool bVar4;
  
  cVar2 = '\0';
  if (*(int *)(param_1 + 0x18) == 0) goto loc_400CE60;
  do {
    do {
      if ((*(byte *)(param_1 + 0x41) & 0x10) == 0) {
        iVar1 = _ttynty(param_1);
        bVar3 = *(sword *)(iVar1 + 0x12) < 0;
        bVar4 = *(sword *)(iVar1 + 0x12) == 0;
        if (!bVar3) goto loc_400CE6C;
      }
      (**(code **)(param_1 + 0x24))(param_1);
      *(uint *)(param_1 + 0x3e) = *(uint *)(param_1 + 0x3e) | 0x40;
      _sleep((int *)(param_1 + 0x18),0x1d);
    } while (*(int *)(param_1 + 0x18) != 0);
loc_400CE60:
    bVar3 = false;
    bVar4 = (*(uint *)(param_1 + 0x3e) & 0x2000020) == 0;
  } while (!bVar4);
loc_400CE6C:
  return cVar2 << 4 | bVar3 << 3 | bVar4 << 2;
}
/* GHIDRADEC_FUNCTION index=301 start=0x400ce7a */

byte _ttyflush(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  char cVar3;
  char cVar4;
  bool bVar5;
  char cVar6;
  byte bVar7;
  
  cVar3 = '\0';
  cVar4 = '\0';
  cVar6 = '\0';
  bVar7 = 0;
  if ((param_2 & 1) != 0) {
    do {
      iVar1 = _getc(param_1 + 0xc);
    } while (-1 < iVar1);
    cVar4 = param_1 < 0;
    cVar6 = '\0';
    bVar7 = 0;
    _wakeup(param_1);
  }
  if ((param_2 & 2) != 0) {
    _wakeup(param_1 + 0x18);
    *(word *)(param_1 + 0x40) = *(word *)(param_1 + 0x40) & 0xfeff;
    uVar2 = (uint)*(byte *)(param_1 + 0x38);
    cVar3 = uVar2 * 0xc < uVar2;
    (**(code **)(DAT_40b0ad4 + uVar2 * 0x2c))(param_1,param_2);
    do {
      iVar1 = _getc(param_1 + 0x18);
      cVar6 = '\0';
      bVar7 = 0;
      cVar4 = iVar1 < 0;
    } while (!(bool)cVar4);
  }
  bVar5 = (param_2 & 1) == 0;
  if (!bVar5) {
    do {
      iVar1 = _getc(param_1);
    } while (-1 < iVar1);
    *(undefined *)(param_1 + 0x49) = 0;
    *(undefined *)(param_1 + 0x4a) = 0;
    cVar6 = '\0';
    bVar7 = 0;
    uVar2 = *(uint *)(param_1 + 0x3e) & 0xff40ffff;
    *(uint *)(param_1 + 0x3e) = uVar2;
    cVar4 = (int)uVar2 < 0;
    bVar5 = uVar2 == 0;
  }
  return cVar3 << 4 | cVar4 << 3 | bVar5 << 2 | cVar6 << 1 | bVar7;
}
/* GHIDRADEC_FUNCTION index=302 start=0x400cf32 */

byte _ttrstrt(int param_1)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  byte bVar5;
  
  if (param_1 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(&aTtrstrt);
  }
  *(uint *)(param_1 + 0x3e) = *(uint *)(param_1 + 0x3e) & 0xfffffffe;
  cVar1 = ((uint)(*(char *)(param_1 + 0x45) * 3) >> 0x1c & 1) != 0;
  cVar2 = param_1 < 0;
  cVar3 = param_1 == 0;
  cVar4 = '\0';
  bVar5 = 0;
  (**(code **)(DAT_40ae4cc + *(char *)(param_1 + 0x45) * 0x30))(param_1);
  return cVar1 << 4 | cVar2 << 3 | cVar3 << 2 | cVar4 << 1 | bVar5;
}
/* GHIDRADEC_FUNCTION index=303 start=0x400cf8e */

undefined4 _ttstart(int param_1)

{
  code *pcVar1;
  uint uVar2;
  undefined2 uVar3;
  undefined2 extraout_D0u;
  char cVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  byte bVar8;
  
  cVar4 = '\0';
  cVar7 = '\0';
  bVar8 = 0;
  uVar2 = *(uint *)(param_1 + 0x3e) & 0x4000121;
  uVar3 = (undefined2)(uVar2 >> 0x10);
  cVar5 = '\0';
  cVar6 = '\0';
  if (uVar2 == 0) {
    pcVar1 = *(code **)(param_1 + 0x24);
    cVar7 = '\0';
    bVar8 = 0;
    cVar5 = (int)pcVar1 < 0;
    cVar6 = pcVar1 == (code *)0x0;
    if (!(bool)cVar6) {
      cVar5 = param_1 < 0;
      cVar6 = param_1 == 0;
      cVar7 = '\0';
      bVar8 = 0;
      (*pcVar1)(param_1);
      uVar3 = extraout_D0u;
    }
  }
  return CONCAT22(uVar3,(word)(byte)(cVar4 << 4 | cVar5 << 3 | cVar6 << 2 | cVar7 << 1 | bVar8));
}
/* GHIDRADEC_FUNCTION index=304 start=0x400cfc6 */

int _ttioctl(uint *param_1,int param_2,uint *param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  sword sVar3;
  word wVar4;
  uint *puVar5;
  uint *puVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint **ppuVar11;
  uint *puStack_40;
  uint *puStack_3c;
  uint *puStack_38;
  
  puStack_38 = param_1;
  puStack_3c = (uint *)0x400cfe6;
  puVar6 = (uint *)_ttynty();
  sVar3 = *(sword *)(param_1 + 0xe);
  ppuVar11 = (uint **)&stack0xffffffcc;
  if (param_2 == -0x7ff98bef) {
loc_400D0D0:
    while( true ) {
      iVar7 = *_active_u;
      if ((((*(sword *)(iVar7 + 0x2e) == *(sword *)((int)param_1 + 0x42)) ||
           (param_1 != *(uint **)((int)_active_u + 0x15e))) ||
          ((*(byte *)(iVar7 + 0x2a) & 0x10) != 0)) ||
         (((*(byte *)(iVar7 + 0x21) & 0x20) != 0 || ((*(byte *)(iVar7 + 0x1d) & 0x20) != 0))))
      break;
      puStack_38 = (uint *)0x16;
      puStack_3c = (uint *)(int)*(sword *)(iVar7 + 0x2e);
      puStack_40 = (uint *)0x400d0bc;
      _gsignal();
      puStack_40 = (uint *)0x1d;
      _sleep(&_lbolt);
    }
  }
  else {
    if (-0x7ff98bef < param_2) {
      if (param_2 != 0x2000745e) {
        if (param_2 < 0x2000745f) {
          if (param_2 != -0x7ff78b99) {
            if (param_2 < -0x7ff78b98) {
              if (param_2 == -0x7ff98b8b) goto loc_400D0D0;
            }
            else if ((param_2 < -0x7fdb8be9) && (-0x7fdb8bed < param_2)) goto loc_400D0D0;
            goto loc_400D102;
          }
        }
        else if ((param_2 < 0x2000746e) ||
                ((0x2000746f < param_2 && ((0x2000747b < param_2 || (param_2 < 0x2000747a))))))
        goto loc_400D102;
      }
      goto loc_400D0D0;
    }
    if (param_2 == -0x7ffb8b8a) goto loc_400D0D0;
    if (-0x7ffb8b8a < param_2) {
      if ((param_2 < -0x7ffb8b83) ||
         ((-0x7ffb8b81 < param_2 && ((-0x7ff98bf6 < param_2 || (param_2 < -0x7ff98bf7))))))
      goto loc_400D102;
      goto loc_400D0D0;
    }
    if (param_2 == -0x7ffb8bff) goto loc_400D0D0;
    if (param_2 < -0x7ffb8bfe) {
      if (param_2 == -0x7ffe8b8e) goto loc_400D0D0;
    }
    else if (param_2 == -0x7ffb8bf0) goto loc_400D0D0;
  }
loc_400D102:
  if (param_2 == 0x20007402) {
    *(word *)(param_1 + 0x10) = *(word *)(param_1 + 0x10) | 0x200;
    return 0;
  }
  if (0x20007402 < param_2) {
    if (param_2 == 0x40047460) {
      *param_3 = *(uint *)((int)param_1 + 0x3e);
      return 0;
    }
    if (0x40047460 < param_2) {
      if (param_2 == 0x40067408) {
        *(undefined *)param_3 = *(undefined *)((int)param_1 + 0x47);
        *(undefined *)((int)param_3 + 1) = *(undefined *)(param_1 + 0x12);
        *(undefined *)((int)param_3 + 2) = *(undefined *)(param_1 + 0x13);
        *(undefined *)((int)param_3 + 3) = *(undefined *)((int)param_1 + 0x4d);
        *(undefined2 *)(param_3 + 1) = *(undefined2 *)(param_1 + 0xf);
        return 0;
      }
      if (param_2 < 0x40067409) {
        if (param_2 != 0x40047477) {
          if (0x40047477 < param_2) {
            if (param_2 == 0x4004747c) {
              *param_3 = (uint)*(word *)((int)param_1 + 0x3a);
              return 0;
            }
            return -1;
          }
          if (param_2 == 0x40047473) {
            *param_3 = param_1[6];
            return 0;
          }
          return -1;
        }
        iVar7 = *_active_u;
        if ((*(byte *)(iVar7 + 0x16) & 0x40) != 0) {
          puStack_38 = (uint *)(int)*(sword *)(iVar7 + 0x30);
          puStack_3c = (uint *)0x400d79a;
          iVar10 = _get_posix_proc();
          uVar8 = *(uint *)(*(int *)(iVar10 + 0xe) + 8);
          if (uVar8 != puVar6[2]) {
            return 0x19;
          }
          if ((*(byte *)(iVar7 + 0x28) & 0x40) == 0) {
            return 0x19;
          }
          if (*(int *)(uVar8 + 8) == 0) {
            return 0x19;
          }
        }
        *param_3 = (int)*(sword *)((int)param_1 + 0x42);
        return 0;
      }
      if (param_2 == 0x40067474) {
        puStack_38 = (uint *)0x6;
        puStack_3c = param_3;
        puStack_40 = param_1 + 0x15;
        _bcopy();
        return 0;
      }
      if (param_2 < 0x40067475) {
        if (param_2 == 0x40067412) {
          puStack_38 = (uint *)0x6;
          puStack_3c = param_3;
          puStack_40 = (uint *)((int)param_1 + 0x4e);
          _bcopy();
          return 0;
        }
        return -1;
      }
      if (param_2 == 0x40087468) {
        uVar8 = *(uint *)((int)param_1 + 0x5e);
        *param_3 = *(uint *)((int)param_1 + 0x5a);
        param_3[1] = uVar8;
        return 0;
      }
      if (param_2 == 0x40247413) {
        puStack_38 = param_3;
        puStack_40 = (uint *)0x400d86c;
        puStack_3c = puVar6;
        _ttgettermios();
        return 0;
      }
      return -1;
    }
    if (param_2 == 0x20007468) {
      if (param_1 != (uint *)_cons) {
        puStack_38 = (uint *)0x0;
        puStack_3c = (uint *)0x0;
        puStack_40 = (uint *)0x20006b08;
        (**(code **)(DAT_40b0ad0 + (uint)(*(word *)((int)_cons_tp + 0x38) >> 8) * 0x2c))
                  ((int)(sword)*(word *)((int)_cons_tp + 0x38));
      }
      _cons_tp = param_1;
      return 0;
    }
    if (param_2 < 0x20007469) {
      if (param_2 == 0x2000740e) {
        *(word *)(param_1 + 0x10) = *(word *)(param_1 + 0x10) & 0xff7f;
        return 0;
      }
      if (param_2 < 0x2000740f) {
        if (param_2 == 0x2000740d) {
          *(word *)(param_1 + 0x10) = *(word *)(param_1 + 0x10) | 0x80;
          return 0;
        }
        return -1;
      }
      if (param_2 == 0x2000745e) {
        puStack_38 = param_1;
        puStack_3c = (uint *)0x400d9a2;
        _ttywait();
        return 0;
      }
      return -1;
    }
    if (param_2 == 0x2000746f) {
      if ((*(uint *)((int)param_1 + 0x3e) & 0x100) != 0) {
        return 0;
      }
      *(uint *)((int)param_1 + 0x3e) = *(uint *)((int)param_1 + 0x3e) | 0x100;
      puStack_38 = (uint *)0x0;
      puStack_3c = param_1;
      puStack_40 = (uint *)0x400d438;
      (**(code **)(DAT_40b0ad0 + (uint)*(byte *)(param_1 + 0xe) * 0x2c + 4))();
      return 0;
    }
    if (0x2000746f < param_2) {
      if (param_2 == 0x4004667f) {
        puStack_3c = (uint *)0x400d3e4;
        puStack_38 = puVar6;
        uVar8 = _ttnread();
        *param_3 = uVar8;
        return 0;
      }
      if (param_2 == 0x40047400) {
        *param_3 = (int)*(char *)((int)param_1 + 0x45);
        return 0;
      }
      return -1;
    }
    if (param_2 != 0x2000746e) {
      return -1;
    }
    if (((*(uint *)((int)param_1 + 0x3e) & 0x100) == 0) && (-1 < *(char *)((int)param_1 + 0x3b))) {
      return 0;
    }
    *(uint *)((int)param_1 + 0x3e) = *(uint *)((int)param_1 + 0x3e) & 0xfffffeff;
    *(byte *)((int)param_1 + 0x3b) = *(byte *)((int)param_1 + 0x3b) & 0x7f;
    puStack_38 = param_1;
    puStack_3c = (uint *)0x400d470;
    _ttstart();
    return 0;
  }
  if (param_2 == -0x7ffb8b82) {
    *(uint *)((int)param_1 + 0x3a) = ~(*param_3 << 0x10) & *(uint *)((int)param_1 + 0x3a);
  }
  else if (param_2 < -0x7ffb8b81) {
    if (param_2 == -0x7ffb8bff) {
      uVar8 = *param_3;
      if ((_nldisp <= uVar8) || ((code *)(&_linesw)[uVar8 * 0xc] == _nodev)) {
        return 6;
      }
      if ((int)*(char *)((int)param_1 + 0x45) == uVar8) {
        return 0;
      }
      puStack_38 = param_1;
      puStack_3c = (uint *)0x400d322;
      (**(code **)(unk_40AE4B0 + *(char *)((int)param_1 + 0x45) * 0x30))();
      *(undefined4 *)((int)param_1 + 0x82) = 0;
      puStack_3c = param_1;
      puStack_40 = (uint *)(int)sVar3;
      iVar7 = (*(code *)(&_linesw)[uVar8 * 0xc])();
      if (iVar7 == 0) {
        *(char *)((int)param_1 + 0x45) = (char)uVar8;
        return 0;
      }
      *(undefined4 *)((int)param_1 + 0x82) = 0;
      puStack_38 = param_1;
      puStack_40 = (uint *)0x400d358;
      puStack_3c = (uint *)(int)sVar3;
      (*(code *)(&_linesw)[*(char *)((int)param_1 + 0x45) * 0xc])();
      return iVar7;
    }
    if (param_2 < -0x7ffb8bfe) {
      if (param_2 == -0x7ffb9983) {
        if (*param_3 != 0) {
          *(word *)(param_1 + 0x10) = *(word *)(param_1 + 0x10) | 0x4000;
          return 0;
        }
        *(word *)(param_1 + 0x10) = *(word *)(param_1 + 0x10) & 0xbfff;
        return 0;
      }
      if (param_2 < -0x7ffb9982) {
        if (param_2 != -0x7ffe8b8e) {
          return -1;
        }
        if (*(sword *)(*(int *)((int)_active_u + 0x1a) + 2) != 0) {
          if ((param_4 & 1) == 0) {
            return 1;
          }
          if (param_1 != *(uint **)((int)_active_u + 0x15e)) {
            return 0xd;
          }
        }
        puStack_38 = param_1;
        puStack_3c = (uint *)(uint)*(byte *)param_3;
        puStack_40 = (uint *)0x400d4cc;
        (**(code **)(unk_40AE4B0 + *(char *)((int)param_1 + 0x45) * 0x30 + 0x10))();
        return 0;
      }
      if (param_2 != -0x7ffb9982) {
        return -1;
      }
      if (*param_3 != 0) {
        *(word *)(param_1 + 0x10) = *(word *)(param_1 + 0x10) | 0x2000;
        return 0;
      }
      *(word *)(param_1 + 0x10) = *(word *)(param_1 + 0x10) & 0xdfff;
      return 0;
    }
    if (param_2 == -0x7ffb8b8a) {
      iVar7 = *_active_u;
      uVar8 = *param_3;
      if ((*(byte *)(iVar7 + 0x16) & 0x40) == 0) {
        if ((*(sword *)(*(int *)((int)_active_u + 0x1a) + 2) != 0) && ((param_4 & 1) == 0)) {
          return 1;
        }
        *(sword *)((int)param_1 + 0x42) = (sword)uVar8;
        return 0;
      }
      puStack_3c = (uint *)0x400d718;
      puStack_38 = (uint *)uVar8;
      uVar9 = _pgfind();
      puStack_3c = (uint *)(int)*(sword *)(iVar7 + 0x30);
      puStack_40 = (uint *)0x400d726;
      iVar10 = _get_posix_proc();
      if ((0 < (int)uVar8) && (uVar9 != 0)) {
        uVar8 = *(uint *)(*(int *)(iVar10 + 0xe) + 8);
        if ((uVar8 == puVar6[2]) && ((*(byte *)(iVar7 + 0x28) & 0x40) != 0)) {
          if (uVar8 == *(uint *)(uVar9 + 8)) {
            puVar6[3] = uVar9;
            *(undefined2 *)((int)param_1 + 0x42) = *(undefined2 *)(uVar9 + 0xe);
            return 0;
          }
          return 1;
        }
        return 0x19;
      }
      return 0x16;
    }
    if (param_2 < -0x7ffb8b89) {
      if (param_2 != -0x7ffb8bf0) {
        return -1;
      }
      if (*param_3 == 0) {
        puStack_38 = (uint *)0x3;
      }
      else {
        puStack_38 = (uint *)(*param_3 & 3);
      }
      puStack_3c = param_1;
      puStack_40 = (uint *)0x400d3ce;
      _ttyflush();
      return 0;
    }
    if (param_2 != -0x7ffb8b83) {
      return -1;
    }
    *(uint *)((int)param_1 + 0x3a) = (uint)*(word *)(param_1 + 0xf);
    *(uint *)((int)param_1 + 0x3a) = *param_3 << 0x10 | (uint)*(word *)(param_1 + 0xf);
  }
  else {
    if (param_2 == -0x7ff98bef) {
      puStack_38 = (uint *)0x6;
      puStack_3c = (uint *)((int)param_1 + 0x4e);
      ppuVar11 = &puStack_40;
      puStack_40 = param_3;
      _bcopy();
      goto loc_400D6E2;
    }
    if (-0x7ff98bef < param_2) {
      if (param_2 == -0x7ff78b99) {
        puStack_38 = (uint *)0x8;
        puStack_3c = param_3;
        puStack_40 = (uint *)((int)param_1 + 0x5a);
        iVar7 = _bcmp();
        if (iVar7 == 0) {
          return 0;
        }
        uVar8 = param_3[1];
        *(uint *)((int)param_1 + 0x5a) = *param_3;
        *(uint *)((int)param_1 + 0x5e) = uVar8;
        puStack_38 = (uint *)0x1c;
        puStack_3c = (uint *)(int)*(sword *)((int)param_1 + 0x42);
        puStack_40 = (uint *)0x400d804;
        _gsignal();
        return 0;
      }
      if (-0x7ff78b99 < param_2) {
        if (-0x7fdb8bea < param_2) {
          return -1;
        }
        if (-0x7fdb8bed < param_2) {
          if (*(char *)((int)param_3 + 0x21) == '\0') {
            *(undefined *)((int)param_3 + 0x21) = *(undefined *)((int)param_3 + 0x22);
          }
          if (param_2 + 0x7fdb8bebU < 2) {
            puStack_38 = param_1;
            puStack_3c = (uint *)0x400d89e;
            _ttywait();
            if (param_2 == -0x7fdb8bea) {
              puStack_38 = (uint *)0x1;
              puStack_3c = param_1;
              puStack_40 = (uint *)0x400d8b4;
              _ttyflush();
            }
          }
          if ((((param_3[2] & 1) == 0) && ((*(uint *)((int)param_1 + 0x3e) & 0x10) == 0)) &&
             ((*(sword *)((int)puVar6 + 0x12) < 0 && (-1 < (sword)param_3[2])))) {
            *(uint *)((int)param_1 + 0x3e) = *(uint *)((int)param_1 + 0x3e) & 0xfffffffb | 2;
            puStack_38 = param_1;
            puStack_3c = (uint *)0x400d8e8;
            _ttwakeup();
          }
          iVar7 = *(int *)((int)param_3 + 0xf) << 2;
          if ((param_2 != -0x7fdb8bea) &&
             (iVar7 >> 0x1f != (int)-((*(uint *)((int)param_1 + 0x3a) & 0x22) == 0))) {
            if (iVar7 < 0) {
              *(uint *)((int)param_1 + 0x3a) = *(uint *)((int)param_1 + 0x3a) | 0x20000000;
              puStack_38 = param_1;
              puStack_3c = (uint *)0x400d91e;
              _ttwakeup();
            }
            else {
              puVar5 = param_1 + 3;
              puStack_3c = param_1;
              puStack_40 = (uint *)0x400d930;
              puStack_38 = puVar5;
              _catq();
              uVar9 = *param_1;
              uVar1 = param_1[1];
              uVar8 = param_1[2];
              *param_1 = *puVar5;
              param_1[1] = param_1[4];
              param_1[2] = param_1[5];
              *puVar5 = uVar9;
              param_1[4] = uVar1;
              param_1[5] = uVar8;
            }
          }
          if ((-1 < iVar7) && ((param_3[6] & 0xffff00) != (puVar6[5] & 0xffff00))) {
            puStack_38 = param_1;
            puStack_3c = (uint *)0x400d980;
            _ttwakeup();
          }
          puStack_38 = param_3;
          puStack_40 = (uint *)0x400d98c;
          puStack_3c = puVar6;
          _ttsettermios();
          puStack_40 = puVar6;
          _ttysetspec();
          return 0;
        }
        return -1;
      }
      if (param_2 != -0x7ff98b8b) {
        return -1;
      }
      puStack_38 = (uint *)0x6;
      puStack_3c = param_1 + 0x15;
      ppuVar11 = &puStack_40;
      puStack_40 = param_3;
      _bcopy();
      goto loc_400D6E2;
    }
    if (param_2 != -0x7ffb8b81) {
      if (-0x7ff98bf6 < param_2) {
        return -1;
      }
      if (-0x7ff98bf8 < param_2) {
        *(undefined *)(param_1 + 0x13) = *(undefined *)((int)param_3 + 2);
        *(char *)((int)param_1 + 0x4d) = (char)*param_3;
        *(undefined *)((int)param_1 + 0x47) = *(undefined *)param_3;
        *(undefined *)(param_1 + 0x12) = *(undefined *)((int)param_3 + 1);
        wVar4 = *(word *)(param_3 + 1);
        uVar9 = CONCAT22((sword)((uint)*(undefined4 *)((int)param_1 + 0x3a) >> 0x10),wVar4);
        uVar8 = *(uint *)((int)param_1 + 0x3a);
        if ((((uVar8 & 0x20) == 0) && ((wVar4 & 0x20) == 0)) && (param_2 != -0x7ff98bf7)) {
          if ((wVar4 & 2) != (uVar8 & 2)) {
            if ((wVar4 & 2) == 0) {
              *(uint *)((int)param_1 + 0x3a) = uVar8 | 0x20000000;
              uVar9 = uVar9 | 0x20000000;
              puStack_38 = param_1;
              puStack_3c = (uint *)0x400d594;
              _ttwakeup();
            }
            else {
              puVar5 = param_1 + 3;
              puStack_3c = param_1;
              puStack_40 = (uint *)0x400d552;
              puStack_38 = puVar5;
              _catq();
              uVar1 = *param_1;
              uVar2 = param_1[1];
              uVar8 = param_1[2];
              *param_1 = *puVar5;
              param_1[1] = param_1[4];
              param_1[2] = param_1[5];
              *puVar5 = uVar1;
              param_1[4] = uVar2;
              param_1[5] = uVar8;
            }
          }
        }
        else {
          puStack_38 = param_1;
          puStack_3c = (uint *)0x400d522;
          _ttywait();
          puStack_3c = (uint *)0x1;
          puStack_40 = param_1;
          _ttyflush();
        }
        *(uint *)((int)param_1 + 0x3a) = uVar9;
        puVar6[4] = 0x1c251a1c;
        *(undefined *)(puVar6 + 5) = 0x5c;
        *(undefined *)((int)puVar6 + 0x15) = 1;
        *(undefined *)((int)puVar6 + 0x16) = 0;
        puStack_3c = (uint *)0x400d5ba;
        puStack_38 = puVar6;
        _ttysetspec();
        if ((*(byte *)((int)param_1 + 0x3d) & 0x20) == 0) {
          return 0;
        }
        *(word *)(param_1 + 0x10) = *(word *)(param_1 + 0x10) & 0xfeff;
        puStack_38 = param_1;
        puStack_3c = (uint *)0x400d5d2;
        _ttstart();
        return 0;
      }
      return -1;
    }
    *(uint *)((int)param_1 + 0x3a) = *param_3 << 0x10 | *(uint *)((int)param_1 + 0x3a);
  }
  puVar6[4] = 0x1c251a1c;
  *(undefined *)(puVar6 + 5) = 0x5c;
  *(undefined *)((int)puVar6 + 0x15) = 1;
  *(undefined *)((int)puVar6 + 0x16) = 0;
loc_400D6E2:
  *(uint **)((int)ppuVar11 + -4) = puVar6;
  *(undefined4 *)((int)ppuVar11 + -8) = 0x400d6ea;
  _ttysetspec();
  return 0;
}
/* GHIDRADEC_FUNCTION index=305 start=0x400d9b4 */

int _ttnread(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)*param_1;
  if ((*(byte *)((int)piVar1 + 0x3a) & 0x20) != 0) {
    _ttypend(piVar1);
  }
  iVar2 = piVar1[3];
  if (((*(uint *)((int)piVar1 + 0x3a) & 0x22) != 0) &&
     (iVar2 = *piVar1 + iVar2, iVar2 < (int)(uint)*(byte *)((int)param_1 + 0x15))) {
    iVar2 = 0;
  }
  return iVar2;
}
/* GHIDRADEC_FUNCTION index=306 start=0x400d9fa */

undefined4 _ttselect(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = _ttynty(param_1);
  if (param_2 == 1) {
    iVar2 = _ttnread(iVar1);
    if ((0 < iVar2) ||
       ((-1 < *(sword *)(iVar1 + 0x12) && ((*(byte *)(param_1 + 0x41) & 0x10) == 0)))) {
      return 1;
    }
    iVar1 = _selthreadcache(param_1 + 0x28);
    if (iVar1 != 0) {
      *(word *)(param_1 + 0x40) = *(word *)(param_1 + 0x40) | 0x800;
    }
  }
  else if (param_2 == 2) {
    if (*(int *)(param_1 + 0x18) <=
        (int)*(sword *)(_ttlowat + (*(byte *)(param_1 + 0x48) & 0x1f) * 2)) {
      return 1;
    }
    iVar1 = _selthreadcache(param_1 + 0x2c);
    if (iVar1 != 0) {
      *(word *)(param_1 + 0x40) = *(word *)(param_1 + 0x40) | 0x1000;
    }
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=307 start=0x400daa4 */

undefined4 _ttyopen(undefined2 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  sword sVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  
  iVar6 = _ttynty(param_2);
  iVar1 = *_active_u;
  iVar7 = _get_posix_proc((int)*(sword *)(iVar1 + 0x30));
  if ((*(byte *)(iVar1 + 0x16) & 0x40) == 0) {
    if ((*(byte *)(iVar1 + 0x28) & 0x40) != 0) goto loc_400DBBE;
    *(int *)((int)_active_u + 0x15e) = param_2;
    *(undefined2 *)((int)_active_u + 0x162) = param_1;
    *(undefined4 *)(iVar6 + 8) = *(undefined4 *)(*(int *)(iVar7 + 0xe) + 8);
    *(int *)(*(int *)(*(int *)(iVar7 + 0xe) + 8) + 8) = param_2;
    sVar4 = *(sword *)(param_2 + 0x42);
    if (sVar4 == 0) {
      _enterpgrp(iVar1,(int)*(sword *)(iVar1 + 0x30),1);
      *(undefined4 *)(iVar6 + 0xc) = *(undefined4 *)(iVar7 + 0xe);
      *(undefined2 *)(param_2 + 0x42) = *(undefined2 *)(*(int *)(iVar7 + 0xe) + 0xe);
    }
    else if (sVar4 != *(sword *)(iVar1 + 0x2e)) {
      _enterpgrp(iVar1,(int)sVar4,0);
    }
  }
  else {
    iVar2 = *(int *)(*(int *)(iVar7 + 0xe) + 8);
    if ((((iVar1 != *(int *)(iVar2 + 4)) || (*(int *)(iVar2 + 8) != 0)) ||
        (*(int *)(iVar6 + 8) != 0)) || ((*(byte *)(iVar7 + 0x16) & 0x40) != 0)) goto loc_400DBBE;
    *(int *)((int)_active_u + 0x15e) = param_2;
    *(undefined2 *)((int)_active_u + 0x162) = param_1;
    *(undefined4 *)(iVar6 + 8) = *(undefined4 *)(*(int *)(iVar7 + 0xe) + 8);
    *(int *)(*(int *)(*(int *)(iVar7 + 0xe) + 8) + 8) = param_2;
    *(undefined4 *)(iVar6 + 0xc) = *(undefined4 *)(iVar7 + 0xe);
    *(undefined2 *)(param_2 + 0x42) = *(undefined2 *)(*(int *)(iVar7 + 0xe) + 0xe);
  }
  *(byte *)(iVar1 + 0x28) = *(byte *)(iVar1 + 0x28) | 0x40;
loc_400DBBE:
  *(undefined2 *)(param_2 + 0x38) = param_1;
  uVar3 = *(uint *)(param_2 + 0x3e);
  uVar5 = uVar3 & 0xfffffffd;
  *(uint *)(param_2 + 0x3e) = uVar5;
  if ((uVar3 & 4) == 0) {
    *(uint *)(param_2 + 0x3e) = uVar5 | 4;
    *(undefined4 *)(iVar6 + 0x10) = 0x1c251a1c;
    *(undefined *)(iVar6 + 0x14) = 0x5c;
    *(undefined *)(iVar6 + 0x15) = 1;
    *(undefined *)(iVar6 + 0x16) = 0;
    _bzero(param_2 + 0x5a,8);
    if (*(char *)(param_2 + 0x45) != '\x02') {
      _ttywflush(param_2);
    }
  }
  _ttysetspec(iVar6);
  return 0;
}
/* GHIDRADEC_FUNCTION index=308 start=0x400dc3e */

void _ttylclose(int param_1)

{
  _ttywflush(param_1);
  *(undefined *)(param_1 + 0x45) = 0;
  return;
}
/* GHIDRADEC_FUNCTION index=309 start=0x400dc5c */

byte _ttyclose(undefined *param_1)

{
  undefined *puVar1;
  int iVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  byte bVar7;
  
  iVar2 = _ttynty(param_1);
  if (param_1 == _cons_tp) {
    _cons_tp = _cons;
    (**(code **)(DAT_40b0ad0 + (uint)(*(word *)(param_1 + 0x38) >> 8) * 0x2c))
              ((int)(sword)*(word *)(param_1 + 0x38),0x20006b08,0,0);
  }
  _ttyflush(param_1,3);
  if ((*(byte *)(*_active_u + 0x16) & 0x40) != 0) {
    *(undefined4 *)(iVar2 + 8) = 0;
    *(undefined4 *)(iVar2 + 0xc) = 0;
  }
  puVar1 = *(undefined **)((int)_active_u + 0x15e);
  if (param_1 == puVar1) {
    *(byte *)(*_active_u + 0x28) = *(byte *)(*_active_u + 0x28) & 0xbf;
  }
  *(undefined2 *)(param_1 + 0x42) = 0;
  *(undefined4 *)(param_1 + 0x3e) = 0;
  param_1[0x45] = 0;
  *(undefined4 *)(param_1 + 0x82) = 0;
  cVar3 = '\0';
  cVar4 = '\0';
  cVar5 = (byte)((param_1 < puVar1) << 4 | 4U) == 0;
  cVar6 = '\0';
  bVar7 = 0;
  _selthreadclear(param_1 + 0x2c);
  _selthreadclear(param_1 + 0x28);
  return cVar3 << 4 | cVar4 << 3 | cVar5 << 2 | cVar6 << 1 | bVar7;
}
/* GHIDRADEC_FUNCTION index=310 start=0x400dd2a */

undefined4 _ttymodem(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = _ttynty(param_1);
  uVar1 = *(uint *)(param_1 + 0x3e);
  if (((uVar1 & 2) == 0) && ((*(byte *)(param_1 + 0x3b) & 0x10) != 0)) {
    if (param_2 == 0) {
      if ((uVar1 & 0x100) == 0) {
        *(uint *)(param_1 + 0x3e) = uVar1 | 0x100;
        (**(code **)(DAT_40b0ad4 + (uint)*(byte *)(param_1 + 0x38) * 0x2c))(param_1,0);
      }
    }
    else {
      *(uint *)(param_1 + 0x3e) = uVar1 & 0xfffffeff;
      _ttstart(param_1);
    }
  }
  else if (param_2 == 0) {
    uVar1 = *(uint *)(param_1 + 0x3e);
    *(uint *)(param_1 + 0x3e) = uVar1 & 0xffffffef;
    if ((((uVar1 & 4) != 0) && (-1 < *(sword *)(iVar2 + 0x12))) &&
       (_ttwakeup(param_1), (*(byte *)(param_1 + 0x3a) & 1) == 0)) {
      _gsignal((int)*(sword *)(param_1 + 0x42),1);
      _gsignal((int)*(sword *)(param_1 + 0x42),0x13);
      _ttyflush(param_1,3);
      return 0;
    }
  }
  else {
    *(uint *)(param_1 + 0x3e) = *(uint *)(param_1 + 0x3e) | 0x10;
    _wakeup(param_1);
  }
  return 1;
}
/* GHIDRADEC_FUNCTION index=311 start=0x400de1a */

int _nullmodem(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = _ttynty(param_1);
  if (param_2 == 0) {
    *(uint *)(param_1 + 0x3e) = *(uint *)(param_1 + 0x3e) & 0xffffffef;
    if (-1 < *(sword *)(iVar1 + 0x12)) {
      param_2 = 0;
    }
  }
  else {
    *(uint *)(param_1 + 0x3e) = *(uint *)(param_1 + 0x3e) | 0x10;
  }
  return param_2;
}
/* GHIDRADEC_FUNCTION index=312 start=0x400de5c */

void _ttypend(undefined4 *param_1)

{
  int iVar1;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  *(byte *)((int)param_1 + 0x3a) = *(byte *)((int)param_1 + 0x3a) & 0xdf;
  *(byte *)((int)param_1 + 0x3f) = *(byte *)((int)param_1 + 0x3f) | 0x10;
  uStack_10 = *param_1;
  uStack_c = param_1[1];
  uStack_8 = param_1[2];
  *param_1 = 0;
  param_1[2] = 0;
  param_1[1] = 0;
  while( true ) {
    iVar1 = _getc(&uStack_10);
    if (iVar1 < 0) break;
    _ttyinput(iVar1,param_1);
  }
  *(byte *)((int)param_1 + 0x3f) = *(byte *)((int)param_1 + 0x3f) & 0xef;
  return;
}
/* GHIDRADEC_FUNCTION index=313 start=0x400deb6 */

void _ttyinput(uint param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = _ttynty(param_2);
  if ((*(byte *)(iVar2 + 0x12) & 8) != 0) {
    if ((*(byte *)((int)param_2 + 0x3a) & 0x20) != 0) {
      _ttypend(param_2);
    }
    _tk_nin = _tk_nin + 1;
    if (((param_1 & 0xff000000) == 0) && ((*(byte *)((int)param_2 + 0x3d) & 0x20) != 0)) {
      if (*param_2 < 0x401) {
        iVar3 = _putc(param_1,param_2);
        if (-1 < iVar3) {
          iVar3 = _ttcheckwakeup(iVar2);
          if (iVar3 != 0) {
            _ttwakeup(param_2);
          }
          _ttyecho(param_1,iVar2);
        }
      }
      else {
        _log(4,aTtyDRawInputOv,(int)*(sword *)(param_2 + 0xe));
        _ttwakeup(param_2);
      }
      uVar1 = *(uint *)((int)param_2 + 0x3a);
      *(uint *)((int)param_2 + 0x3a) = uVar1 & 0xff7fffff;
      if (((*(byte *)(iVar2 + 0x13) & 0x10) != 0) &&
         (((uVar1 & 0x40000000) == 0 ||
          ((*(char *)((int)param_2 + 0x51) != -1 &&
           (*(char *)((int)param_2 + 0x51) == *(char *)(param_2 + 0x14))))))) {
        *(word *)(param_2 + 0x10) = *(word *)(param_2 + 0x10) & 0xfeff;
      }
    }
    else {
      _ttcooked(param_1,iVar2);
    }
    if ((0x1ff < param_2[3] + *param_2) &&
       (((*(uint *)((int)param_2 + 0x3a) & 0x22) != 0 || (0 < param_2[3])))) {
      if (((*(uint *)((int)param_2 + 0x3a) & 1) != 0) && (*(char *)((int)param_2 + 0x51) != -1)) {
        iVar2 = _putc((int)*(char *)((int)param_2 + 0x51),param_2 + 6);
        if (iVar2 == 0) {
          *(word *)(param_2 + 0x10) = *(word *)(param_2 + 0x10) | 0x400;
          _ttstart(param_2);
        }
      }
      *(byte *)((int)param_2 + 0x3f) = *(byte *)((int)param_2 + 0x3f) | 0x80;
    }
    _ttstart(param_2);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=314 start=0x400e014 */

void _ttyblkin(undefined *param_1,int param_2,int *param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  word wVar4;
  sword sVar5;
  undefined *puVar6;
  
  iVar2 = _ttynty(param_3);
  if ((*(byte *)(iVar2 + 0x12) & 8) != 0) {
    if ((*(byte *)((int)param_3 + 0x3a) & 0x20) != 0) {
      _ttypend(param_3);
    }
    _tk_nin = param_2 + _tk_nin;
    if ((*(byte *)((int)param_3 + 0x3d) & 0x20) == 0) {
      param_2 = param_2 + -1;
      if (-1 < param_2) {
        do {
          do {
            puVar6 = param_1 + 1;
            _ttcooked(*param_1,iVar2);
            wVar4 = (word)((uint)param_2 >> 0x10);
            sVar5 = (sword)param_2 + -1;
            param_2 = CONCAT22(wVar4,sVar5);
            param_1 = puVar6;
          } while (sVar5 != -1);
          param_2 = (uint)wVar4 * 0x10000 + -1;
        } while (wVar4 != 0);
      }
    }
    else {
      if (0x400 < param_2 + *param_3) {
        param_2 = 0x400 - *param_3;
        if (param_2 < 0) {
          param_2 = 0;
        }
        _log(4,aTtyDRawInputOv,(int)*(sword *)(param_3 + 0xe));
      }
      iVar3 = _b_to_q(param_1,param_2,param_3);
      if ((param_2 != iVar3 && -1 < param_2 - iVar3) && (iVar3 = _ttcheckwakeup(iVar2), iVar3 != 0))
      {
        _ttwakeup(param_3);
      }
      uVar1 = *(uint *)((int)param_3 + 0x3a);
      *(uint *)((int)param_3 + 0x3a) = uVar1 & 0xff7fffff;
      if ((uVar1 & 8) != 0) {
        iVar3 = _b_to_q(param_1,param_2,param_3 + 6);
        _tk_nout = iVar3 + _tk_nout;
      }
      if (((*(byte *)(iVar2 + 0x13) & 0x10) != 0) &&
         (((*(byte *)((int)param_3 + 0x3a) & 0x40) == 0 ||
          ((*(char *)((int)param_3 + 0x51) != -1 &&
           (*(char *)((int)param_3 + 0x51) == *(char *)(param_3 + 0x14))))))) {
        *(word *)(param_3 + 0x10) = *(word *)(param_3 + 0x10) & 0xfeff;
      }
    }
    if ((0x1ff < param_3[3] + *param_3) &&
       (((*(uint *)((int)param_3 + 0x3a) & 0x22) != 0 || (0 < param_3[3])))) {
      if (((*(uint *)((int)param_3 + 0x3a) & 1) != 0) &&
         ((*(char *)((int)param_3 + 0x51) != -1 &&
          (iVar2 = _putc((int)*(char *)((int)param_3 + 0x51),param_3 + 6), iVar2 == 0)))) {
        *(word *)(param_3 + 0x10) = *(word *)(param_3 + 0x10) | 0x400;
        _ttstart(param_3);
      }
      *(byte *)((int)param_3 + 0x3f) = *(byte *)((int)param_3 + 0x3f) | 0x80;
    }
    _ttstart(param_3);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=315 start=0x400e1a2 */

uint _ttcooked(uint *param_1,uint *param_2)

{
  uint *puVar1;
  uint uVar2;
  sword sVar3;
  char cVar4;
  byte bVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  undefined4 uVar10;
  uint *puVar11;
  char cVar12;
  uint **ppuVar13;
  uint *puStack_38;
  uint *puStack_34;
  uint *puStack_30;
  
  puVar1 = (uint *)*param_2;
  uVar8 = *(uint *)((int)puVar1 + 0x3a);
  uVar2 = param_2[4];
  puStack_34 = (uint *)((uint)param_1 & 0xff000000);
  puVar11 = param_1;
  if (puStack_34 == (uint *)0x0) {
loc_400E248:
    if ((((*(byte *)((int)puVar1 + 0x3f) & 0x10) == 0) && ((uVar8 & 0x8000020) == 0)) &&
       ((uVar2 & 0x400000) != 0)) {
      puVar11 = (uint *)((uint)puVar11 & 0xffffff7f);
    }
    if ((*(uint *)((int)puVar1 + 0x3e) & 0x80000) != 0) {
      puVar11 = (uint *)((uint)puVar11 | 0x100);
      *(uint *)((int)puVar1 + 0x3e) = *(uint *)((int)puVar1 + 0x3e) & 0xfff7ffff;
    }
    if (((((uint)puVar11 & 0x100) != 0) || ((*(byte *)((int)puVar1 + 0x3f) & 0x40) != 0)) ||
       ((*(uint *)((int)puVar1 + ((int)puVar11 >> 5) * 4 + 0x62) & 1 << ((uint)puVar11 & 0x1f)) == 0
       )) {
loc_400E4BC:
      if ((uVar8 & 0x22) == 0) goto loc_400E768;
loc_400E4EA:
      if ((int)*puVar1 < 0x401) {
        puStack_38 = (uint *)0x400e538;
        puStack_34 = puVar11;
        puStack_30 = puVar1;
        puStack_34 = (uint *)_putc();
        if (-1 < (int)puStack_34) {
          puStack_30 = param_2;
          puStack_34 = (uint *)0x400e548;
          iVar9 = _ttcheckwakeup();
          if (iVar9 != 0) {
            puStack_34 = (uint *)0x400e556;
            puStack_30 = puVar1;
            _ttwakeup();
          }
          puStack_30 = param_2;
          puStack_38 = (uint *)0x400e562;
          puStack_34 = puVar11;
          puStack_34 = (uint *)_ttyecho();
        }
        goto loc_400E8B8;
      }
      if (((int)puVar1[6] < (int)*(sword *)(_tthiwat + (*(byte *)(puVar1 + 0x12) & 0x1f) * 2)) &&
         ((uVar2 & 0x8000000) != 0)) {
        puStack_34 = (uint *)0x7;
        puStack_38 = (uint *)0x400e51c;
        puStack_30 = puVar1;
        _ttyoutput();
      }
      sVar3 = *(sword *)(puVar1 + 0xe);
      puStack_34 = (uint *)aTtyDCbreakInpu;
loc_400E7AE:
      puStack_30 = (uint *)(int)sVar3;
      puStack_38 = (uint *)0x4;
      puStack_34 = (uint *)_log();
      goto loc_400E8B8;
    }
    puStack_34 = (uint *)(uVar2 & 0x181000);
    if ((puStack_34 == (uint *)0x101000) && (puVar11 == (uint *)0xff)) {
      puStack_34 = (uint *)0x1ff;
      puStack_38 = (uint *)0x400e2c2;
      puStack_30 = puVar1;
      puStack_34 = (uint *)_putc();
      puVar11 = (uint *)0x1ff;
    }
    cVar12 = (char)puVar11;
    if (((uVar2 & 0x10) != 0) && (cVar12 != -1)) {
      if (cVar12 == *(char *)((int)puVar1 + 0x59)) {
        if ((uVar8 & 8) != 0) {
          if ((uVar8 & 0x40000) == 0) {
            puStack_30 = param_2;
            puStack_38 = (uint *)0x400e304;
            puStack_34 = puVar11;
            puStack_34 = (uint *)_ttyecho();
          }
          else {
            puStack_34 = (uint *)&asc_40A635C;
            puStack_38 = (uint *)0x400e2f8;
            puStack_30 = puVar1;
            puStack_34 = (uint *)_ttyoutstr();
          }
        }
        *(byte *)((int)puVar1 + 0x3f) = *(byte *)((int)puVar1 + 0x3f) | 8;
        goto loc_400E8B8;
      }
      if ((cVar12 != -1) && (cVar12 == *(char *)((int)puVar1 + 0x57))) {
        if ((uVar8 & 0x800000) == 0) {
          puStack_30 = (uint *)0x2;
          puStack_38 = (uint *)0x400e32e;
          puStack_34 = puVar1;
          _ttyflush();
          puStack_38 = param_2;
          _ttyecho(puVar11);
          uVar8 = 0;
          if (puVar1[3] + *puVar1 != 0) {
            puStack_30 = param_2;
            puStack_34 = (uint *)0x400e34c;
            uVar8 = _ttyretype();
          }
          *(byte *)((int)puVar1 + 0x3b) = *(byte *)((int)puVar1 + 0x3b) | 0x80;
          return uVar8;
        }
        goto loc_400E8E2;
      }
    }
    if (((uVar2 & 8) != 0) && (cVar12 != -1)) {
      if ((cVar12 == *(char *)((int)puVar1 + 0x4e)) || (cVar12 == *(char *)((int)puVar1 + 0x4f))) {
        if (-1 < (int)uVar8) {
          puStack_30 = (uint *)0x3;
          puStack_38 = (uint *)0x400e380;
          puStack_34 = puVar1;
          _ttyflush();
        }
        puStack_30 = param_2;
        puStack_38 = (uint *)0x400e38c;
        puStack_34 = puVar11;
        _ttyecho();
        puStack_30 = (uint *)0x3;
        if ((cVar12 != -1) && (cVar12 == *(char *)((int)puVar1 + 0x4e))) {
          puStack_30 = (uint *)0x2;
        }
        ppuVar13 = &puStack_30;
      }
      else {
        if ((cVar12 == -1) || (cVar12 != *(char *)(puVar1 + 0x15))) goto loc_400E3DE;
        if (-1 < (int)uVar8) {
          puStack_30 = (uint *)0x1;
          puStack_38 = (uint *)0x400e3be;
          puStack_34 = puVar1;
          _ttyflush();
        }
        puStack_30 = param_2;
        puStack_38 = (uint *)0x400e3ca;
        puStack_34 = puVar11;
        _ttyecho();
        ppuVar13 = &puStack_38;
        puStack_38 = (uint *)0x12;
      }
loc_400E3CE:
      *(int *)((int)ppuVar13 + -4) = (int)*(sword *)((int)puVar1 + 0x42);
      *(undefined4 *)((int)ppuVar13 + -8) = 0x400e3da;
      puStack_34 = (uint *)_gsignal();
      goto loc_400E8B8;
    }
loc_400E3DE:
    if (((uVar2 & 0x4000000) == 0) || (cVar12 == -1)) {
loc_400E44A:
      if (puVar11 == (uint *)0xd) {
        if ((uVar2 & 0x1000000) != 0) goto loc_400E8B8;
        if (((uVar8 & 0x10) != 0) || ((uVar2 & 0x2000000) != 0)) {
          puVar11 = (uint *)0xa;
        }
      }
      else if ((puVar11 == (uint *)0xa) && ((uVar2 & 0x800000) != 0)) {
        puVar11 = (uint *)0xd;
      }
      if (((uVar8 & 4) != 0) && ((int)puVar11 < 0x80)) {
        if ((*(uint *)((int)puVar1 + 0x3e) & 0x10000) != 0) {
          puStack_30 = param_2;
          puStack_38 = (uint *)0x400e496;
          puStack_34 = puVar1;
          puStack_34 = (uint *)_unputc();
          puStack_38 = (uint *)0x400e49e;
          _ttyrub();
          if (*(char *)((int)puVar11 + 0x40ae35e) != '\0') {
            puVar11 = (uint *)(int)*(char *)((int)puVar11 + 0x40ae35e);
          }
          puVar11 = (uint *)((uint)puVar11 | 0x100);
          *(uint *)((int)puVar1 + 0x3e) = *(uint *)((int)puVar1 + 0x3e) & 0xfffcffff;
          goto loc_400E4BC;
        }
        if ((int)puVar11 - 0x41U < 0x1a) {
          puVar11 = puVar11 + 8;
        }
        else if (puVar11 == (uint *)0x5c) {
          *(uint *)((int)puVar1 + 0x3e) = *(uint *)((int)puVar1 + 0x3e) | 0x10000;
        }
      }
      if ((uVar8 & 0x22) != 0) goto loc_400E4EA;
      cVar12 = (char)puVar11;
      if ((*(byte *)((int)puVar1 + 0x3f) & 2) == 0) {
loc_400E59E:
        if (cVar12 != -1) {
          if (cVar12 == *(char *)(puVar1 + 0x13)) {
            puStack_34 = (uint *)0x0;
            if (*puVar1 != 0) {
              puStack_30 = param_2;
              puStack_38 = (uint *)0x400e5be;
              puStack_34 = puVar1;
              uVar10 = _unputc();
              puStack_38 = (uint *)0x400e5cc;
              puStack_34 = (uint *)uVar10;
              puStack_34 = (uint *)_ttyrub();
              if ((((uVar8 & 0x80000) != 0) && ((char)uVar10 < '\0')) && (*puVar1 != 0)) {
                puStack_34 = (uint *)0x400e5e6;
                puStack_30 = puVar1;
                puStack_34 = (uint *)_unputc();
                if ((char)puStack_34 != -0x72) {
                  puStack_30 = param_2;
                  puStack_38 = (uint *)0x400e5f8;
                  puStack_34 = (uint *)_ttyrub();
                }
              }
            }
            goto loc_400E8B8;
          }
          if (cVar12 != -1) {
            if (cVar12 == *(char *)((int)puVar1 + 0x4d)) {
              if (((uVar2 & 4) == 0) || ((uVar8 & 0x4000000) == 0)) {
loc_400E640:
                puStack_30 = param_2;
                puStack_38 = (uint *)0x400e64c;
                puStack_34 = puVar11;
                _ttyecho();
                if ((uVar2 & 4) != 0) {
                  puStack_30 = param_2;
                  puStack_34 = (uint *)0xa;
                  puStack_38 = (uint *)0x400e65c;
                  _ttyecho();
                }
                do {
                  puStack_34 = (uint *)0x400e666;
                  puStack_30 = puVar1;
                  puStack_34 = (uint *)_getc();
                } while (0 < (int)puStack_34);
                *(undefined *)((int)puVar1 + 0x49) = 0;
              }
              else {
                puStack_34 = (uint *)(int)*(char *)((int)puVar1 + 0x49);
                uVar6 = *puVar1;
                if (puStack_34 != (uint *)uVar6) goto loc_400E640;
                while (uVar6 != 0) {
                  puStack_30 = param_2;
                  puStack_38 = (uint *)0x400e630;
                  puStack_34 = puVar1;
                  puStack_34 = (uint *)_unputc();
                  puStack_38 = (uint *)0x400e638;
                  puStack_34 = (uint *)_ttyrub();
                  uVar6 = *puVar1;
                }
              }
              *(uint *)((int)puVar1 + 0x3e) = *(uint *)((int)puVar1 + 0x3e) & 0xffc0ffff;
              goto loc_400E8B8;
            }
            if (cVar12 != -1) {
              if (cVar12 == *(char *)(puVar1 + 0x16)) {
                while( true ) {
                  puStack_34 = (uint *)0x400e698;
                  puStack_30 = puVar1;
                  puStack_34 = (uint *)_unputc();
                  if ((puStack_34 != (uint *)0x20) && (puStack_34 != (uint *)0x9)) break;
                  puStack_30 = param_2;
                  puStack_38 = (uint *)0x400e6b2;
                  _ttyrub();
                }
                if (puStack_34 != (uint *)0xffffffff) {
                  puStack_30 = param_2;
                  puStack_38 = (uint *)0x400e6c8;
                  _ttyrub();
                  puStack_38 = puVar1;
                  puStack_34 = (uint *)_unputc();
                  if (puStack_34 != (uint *)0xffffffff) {
                    bVar5 = _partab[(uint)puStack_34 & 0xff];
                    if ((puStack_34 != (uint *)0x20) && (puStack_34 != (uint *)0x9)) {
                      while (((uVar2 & 0x20) == 0 ||
                             ((bVar5 & 0x40) == (_partab[(uint)puStack_34 & 0xff] & 0x40)))) {
                        puStack_30 = param_2;
                        puStack_38 = (uint *)0x400e720;
                        _ttyrub();
                        puStack_38 = puVar1;
                        puStack_34 = (uint *)_unputc();
                        if (puStack_34 == (uint *)0xffffffff) goto loc_400E8B8;
                        if ((puStack_34 == (uint *)0x20) || (puStack_34 == (uint *)0x9)) break;
                      }
                    }
                    puStack_38 = (uint *)0x400e74c;
                    puStack_30 = puVar1;
                    puStack_34 = (uint *)_putc();
                  }
                }
              }
              else {
                if ((cVar12 == -1) || (cVar12 != *(char *)((int)puVar1 + 0x56))) goto loc_400E768;
                puStack_30 = param_2;
                puStack_34 = (uint *)0x400e764;
                puStack_34 = (uint *)_ttyretype();
              }
              goto loc_400E8B8;
            }
          }
        }
      }
      else if (cVar12 != -1) {
        if ((cVar12 != *(char *)(puVar1 + 0x13)) && (cVar12 != *(char *)((int)puVar1 + 0x4d)))
        goto loc_400E59E;
        puStack_30 = param_2;
        puStack_38 = (uint *)0x400e58c;
        puStack_34 = puVar1;
        puStack_34 = (uint *)_unputc();
        puStack_38 = (uint *)0x400e594;
        _ttyrub();
        puVar11 = (uint *)((uint)puVar11 | 0x100);
      }
loc_400E768:
      if ((int)(puVar1[3] + *puVar1) < 0x400) {
        puStack_38 = (uint *)0x400e7c6;
        puStack_34 = puVar11;
        puStack_30 = puVar1;
        puStack_34 = (uint *)_putc();
        if (-1 < (int)puStack_34) {
          if ((puVar11 == (uint *)0xa) ||
             ((((uint *)(uint)*(byte *)((int)puVar1 + 0x52) == puVar11 ||
               ((uint *)(uint)*(byte *)((int)puVar1 + 0x53) == puVar11)) &&
              (puVar11 != (uint *)0xff)))) {
            *(undefined *)((int)puVar1 + 0x49) = 0;
            puStack_30 = puVar1 + 3;
            puStack_38 = (uint *)0x400e800;
            puStack_34 = puVar1;
            _catq();
            puStack_38 = puVar1;
            _ttwakeup();
          }
          else {
            cVar12 = *(char *)((int)puVar1 + 0x49);
            *(char *)((int)puVar1 + 0x49) = *(char *)((int)puVar1 + 0x49) + '\x01';
            if (cVar12 == '\0') {
              *(undefined *)((int)puVar1 + 0x4a) = *(undefined *)((int)puVar1 + 0x46);
            }
          }
          puStack_34 = *(uint **)((int)puVar1 + 0x3e);
          *(uint *)((int)puVar1 + 0x3e) = (uint)puStack_34 & 0xfffdffff;
          if (((uint)puStack_34 & 0x400000) == 0) {
            cVar12 = (char)puVar11;
            if ((cVar12 != -1) && (cVar12 == *(char *)(param_2 + 5))) {
              *(uint *)((int)puVar1 + 0x3e) = (uint)puStack_34 & 0xfffdffff | 0x20000;
            }
            if ((*(uint *)((int)puVar1 + 0x3e) & 0x40000) != 0) {
              *(uint *)((int)puVar1 + 0x3e) = *(uint *)((int)puVar1 + 0x3e) & 0xfffbffff;
              puStack_34 = (uint *)0x2f;
              puStack_38 = (uint *)0x400e868;
              puStack_30 = puVar1;
              _ttyoutput();
            }
            cVar4 = *(char *)((int)puVar1 + 0x46);
            puStack_30 = param_2;
            puStack_38 = (uint *)0x400e87a;
            puStack_34 = puVar11;
            puStack_34 = (uint *)_ttyecho();
            if (((cVar12 != -1) && (cVar12 == *(char *)((int)puVar1 + 0x52))) && ((uVar8 & 8) != 0))
            {
              uVar6 = (int)*(char *)((int)puVar1 + 0x46) - (int)cVar4;
              uVar7 = 2;
              puStack_34 = (uint *)2;
              if ((int)uVar6 < 3) {
                uVar7 = uVar6;
                puStack_34 = (uint *)uVar6;
              }
              for (; 0 < (int)uVar7; uVar7 = uVar7 - 1) {
                puStack_34 = (uint *)0x8;
                puStack_38 = (uint *)0x400e8b0;
                puStack_30 = puVar1;
                puStack_34 = (uint *)_ttyoutput();
              }
            }
          }
        }
        goto loc_400E8B8;
      }
      if (((uVar2 & 0x8000000) != 0) &&
         ((int)puVar1[6] < (int)*(sword *)(_tthiwat + (*(byte *)(puVar1 + 0x12) & 0x1f) * 2))) {
        puStack_34 = (uint *)0x7;
        puStack_38 = (uint *)0x400e7a0;
        puStack_30 = puVar1;
        _ttyoutput();
      }
      sVar3 = *(sword *)(puVar1 + 0xe);
      puStack_34 = (uint *)aTtyDCanonInput;
      goto loc_400E7AE;
    }
    if (cVar12 == *(char *)((int)puVar1 + 0x51)) {
      puStack_34 = *(uint **)((int)puVar1 + 0x3e);
      if (((uint)puStack_34 & 0x100) == 0) {
        *(uint *)((int)puVar1 + 0x3e) = (uint)puStack_34 | 0x100;
        puStack_30 = (uint *)0x0;
        puStack_38 = (uint *)0x400e424;
        puStack_34 = puVar1;
        uVar8 = (**(code **)(DAT_40b0ad4 + (uint)*(byte *)(puVar1 + 0xe) * 0x2c))();
        return uVar8;
      }
      if (cVar12 == -1) {
        return (uint)puStack_34;
      }
      if (cVar12 != *(char *)(puVar1 + 0x14)) {
        return (uint)puStack_34;
      }
      goto loc_400E8B8;
    }
    if ((cVar12 == -1) || (cVar12 != *(char *)(puVar1 + 0x14))) goto loc_400E44A;
  }
  else {
    puVar11 = (uint *)((uint)param_1 & 0xffffff);
    if ((((uint)param_1 & 0x1000000) == 0) || (puVar11 != (uint *)0x0)) {
      if (((((uint)param_1 & 0x2000000) != 0) && ((uVar2 & 0x200000) != 0)) ||
         (((uint)param_1 & 0x1000000) != 0)) {
        if ((uVar2 & 0x80000) != 0) goto loc_400E8B8;
        if ((uVar2 & 0x100000) != 0) goto loc_400E222;
        puVar11 = (uint *)0x100;
      }
      goto loc_400E248;
    }
    if ((uVar2 & 0x20000) == 0) {
      if ((uVar2 & 0x40000) == 0) {
        if ((uVar2 & 0x100000) != 0) {
loc_400E222:
          puStack_34 = (uint *)0x1ff;
          puStack_38 = (uint *)0x400e230;
          puStack_30 = puVar1;
          _putc();
          puStack_38 = puVar1;
          _putc(0x100);
          puVar11 = (uint *)((uint)puVar11 | 0x100);
        }
        goto loc_400E248;
      }
      puStack_30 = (uint *)0x3;
      puStack_38 = (uint *)0x400e1f2;
      puStack_34 = puVar1;
      _ttyflush();
      ppuVar13 = &puStack_38;
      puStack_38 = (uint *)0x2;
      goto loc_400E3CE;
    }
loc_400E8B8:
    if ((uVar2 & 0x10) == 0) {
      return (uint)puStack_34;
    }
    if (((uVar8 & 0x40000000) != 0) && ((puVar1[0x10] & 0x1000000) != 0)) {
      bVar5 = *(byte *)((int)puVar1 + 0x51);
      puStack_34 = (uint *)(uint)bVar5;
      if (bVar5 == 0xff) {
        return 0xff;
      }
      if (bVar5 != *(byte *)(puVar1 + 0x14)) {
        return (uint)puStack_34;
      }
    }
  }
  *(word *)(puVar1 + 0x10) = *(word *)(puVar1 + 0x10) & 0xfeff;
loc_400E8E2:
  *(byte *)((int)puVar1 + 0x3b) = *(byte *)((int)puVar1 + 0x3b) & 0x7f;
  return (uint)puStack_34;
}
/* GHIDRADEC_FUNCTION index=316 start=0x400e8f2 */

uint _ttyoutput(uint param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  byte bVar5;
  uint uVar6;
  char *pcVar7;
  char *pcVar8;
  
  iVar2 = _ttynty(param_2);
  uVar1 = *(uint *)(param_2 + 0x3a);
  if (((uVar1 & 0x200020) != 0) || ((*(uint *)(iVar2 + 0x10) & 0x10000000) == 0)) {
    if ((uVar1 & 0x800000) != 0) {
      return 0xffffffff;
    }
    iVar2 = _putc(param_1,param_2 + 0x18);
    if (iVar2 == 0) {
      _tk_nout = _tk_nout + 1;
      return 0xffffffff;
    }
    return param_1;
  }
  if (((uVar1 & 0x2000000) == 0) && ((*(uint *)(iVar2 + 0x10) & 0x300) != 0x300)) {
    param_1 = param_1 & 0x7f;
  }
  else {
    param_1 = param_1 & 0xff;
  }
  if ((param_1 == 4) && ((uVar1 & 2) == 0)) {
    return 0xffffffff;
  }
  if (((param_1 == 9) && ((uVar1 & 0xc00) == 0xc00)) && ((*(byte *)(param_2 + 0x3f) & 0x40) == 0)) {
    iVar2 = 8 - (*(byte *)(param_2 + 0x46) & 7);
    if ((uVar1 & 0x800000) == 0) {
      iVar3 = _b_to_q(asc_40A6398,iVar2,param_2 + 0x18);
      iVar2 = iVar2 - iVar3;
      _tk_nout = iVar2 + _tk_nout;
    }
    *(char *)(param_2 + 0x46) = (char)iVar2 + *(char *)(param_2 + 0x46);
    if (iVar2 != 0) {
      return 0xffffffff;
    }
    return 9;
  }
  _tk_nout = _tk_nout + 1;
  if ((uVar1 & 4) != 0) {
    pcVar7 = asc_40A63A1 + 1;
    do {
      pcVar8 = pcVar7 + 1;
      if ((int)*pcVar7 == param_1) {
        iVar3 = _ttyoutput(0x5c,param_2);
        if (-1 < iVar3) {
          return param_1;
        }
        param_1 = (uint)pcVar7[-1];
        break;
      }
      pcVar7 = pcVar7 + 2;
    } while (*pcVar8 != '\0');
    if (param_1 - 0x41 < 0x1a) {
      iVar3 = _ttyoutput(0x5c,param_2);
      if (-1 < iVar3) {
        return param_1;
      }
    }
    else if (param_1 - 0x61 < 0x1a) {
      param_1 = param_1 - 0x20;
    }
  }
  if (((param_1 == 10) && (((uVar1 & 0x10) != 0 || ((*(byte *)(iVar2 + 0x10) & 0x20) != 0)))) &&
     (iVar3 = _ttyoutput(0xd,param_2), -1 < iVar3)) {
    return 10;
  }
  if (((uVar1 & 0x800000) == 0) && (iVar3 = _putc(param_1,param_2 + 0x18), iVar3 != 0)) {
    return param_1;
  }
  bVar5 = *(byte *)(param_2 + 0x46);
  uVar4 = (uint)(char)bVar5;
  uVar6 = 0;
  switch(_partab[param_1] & 0x3f) {
  case :
    bVar5 = bVar5 + 1;
    break;
  case :
    if (0 < (int)uVar4) {
      bVar5 = bVar5 - 1;
    }
    break;
  case :
    uVar1 = (uVar1 & 0x3ff) >> 8;
    if (uVar1 == 1) {
      if ((0 < (int)uVar4) && (uVar6 = (uVar4 >> 4) + 3, 6 < uVar6)) {
        uVar6 = 6;
      }
    }
    else if (uVar1 == 2) {
      iVar3 = _hz * 100;
      goto loc_400EB2E;
    }
    goto loc_400EBC6;
  case :
    if (((uVar1 & 0xc00) == 0x400) && (uVar6 = 1 - (uVar4 | 0xfffffff8), (int)uVar6 < 5)) {
      uVar6 = 0;
    }
    bVar5 = bVar5 + 8 & 0xf8;
    break;
  case :
    if ((uVar1 & 0x4000) != 0) {
      uVar6 = 0x7f;
    }
    break;
  case :
    uVar1 = (*(uint *)(param_2 + 0x3c) & 0x3fffffff) >> 0x1c;
    if (uVar1 == 2) {
      iVar3 = _hz * 0xa6;
loc_400EB2E:
      uVar6 = iVar3 >> 10;
    }
    else if (uVar1 < 3) {
      if (uVar1 == 1) {
        iVar3 = _hz * 0x53;
        goto loc_400EB2E;
      }
    }
    else if (uVar1 == 3) {
      if (-1 < (int)uVar4) {
        for (; (int)uVar4 < 9; uVar4 = uVar4 + 1) {
          _putc(0x7f,param_2 + 0x18);
        }
      }
      uVar6 = 0;
    }
loc_400EBC6:
    bVar5 = 0;
  }
  *(byte *)(param_2 + 0x46) = bVar5;
  if (((uVar6 != 0) && ((*(uint *)(param_2 + 0x3a) & 0x2800000) == 0)) &&
     ((*(uint *)(iVar2 + 0x10) & 0x300) != 0x300)) {
    _putc(uVar6 | 0x80,param_2 + 0x18);
  }
  return 0xffffffff;
}
/* GHIDRADEC_FUNCTION index=317 start=0x400ec0a */

int _ttread(int *param_1,int param_2)

{
  uint uVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  char cVar8;
  int iVar9;
  int iVar10;
  int *piVar11;
  int iStack_20;
  int iStack_1c;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  
  iVar4 = _ttynty(param_1);
  iVar9 = 0;
loc_400EC24:
  bVar2 = false;
loc_400EC26:
  while( true ) {
    uVar1 = *(uint *)((int)param_1 + 0x3a);
    if ((uVar1 & 0x20000000) != 0) {
      _ttypend(param_1);
    }
    while ((uVar6 = *(uint *)((int)param_1 + 0x3e), (uVar6 & 0x10) == 0 &&
           (-1 < *(sword *)(iVar4 + 0x12)))) {
      if (-1 < (sword)uVar6) {
        return 5;
      }
      if ((uVar6 & 0x2000) != 0) goto loc_400EE90;
      _sleep(param_1,0x1c);
    }
    iVar7 = *_active_u;
    if ((*(byte *)(iVar7 + 0x16) & 0x40) != 0) break;
    if ((param_1 != *(int **)((int)_active_u + 0x15e)) ||
       (*(sword *)(iVar7 + 0x2e) == *(sword *)((int)param_1 + 0x42))) goto loc_400ED2E;
    if (((*(byte *)(iVar7 + 0x21) & 0x10) != 0) ||
       (((*(byte *)(iVar7 + 0x1d) & 0x10) != 0 || ((*(byte *)(iVar7 + 0x2a) & 0x10) != 0)))) {
      return 5;
    }
    iVar10 = (int)*(sword *)(iVar7 + 0x2e);
loc_400ED10:
    _gsignal(iVar10,0x15);
    _sleep(&_lbolt,0x1c);
  }
  iVar5 = _get_posix_proc((int)*(sword *)(iVar7 + 0x30));
  if (param_1 == *(int **)((int)_active_u + 0x15e)) {
    iVar10 = *(int *)(*(int *)(iVar5 + 0xe) + 0xc);
    if (*(sword *)((int)param_1 + 0x42) != iVar10) {
      if ((*(byte *)(iVar7 + 0x21) & 0x10) != 0) {
        return 5;
      }
      if ((*(byte *)(iVar7 + 0x1d) & 0x10) != 0) {
        return 5;
      }
      if (*(int *)(*(int *)(iVar5 + 0xe) + 0x10) == 0) {
        return 5;
      }
      if ((*(byte *)(iVar7 + 0x2a) & 0x10) != 0) {
        return 5;
      }
      goto loc_400ED10;
    }
  }
loc_400ED2E:
  if ((uVar1 & 0x22) == 0) {
    piVar11 = param_1 + 3;
    if (0 < param_1[3]) goto loc_400EEC0;
  }
  else {
    uVar6 = (uint)*(byte *)(iVar4 + 0x15);
    piVar11 = param_1;
    if (*(byte *)(iVar4 + 0x16) == 0) {
      if ((int)uVar6 <= *param_1) goto loc_400EEC0;
    }
    else {
      iVar7 = (uint)*(byte *)(iVar4 + 0x16) * 100000;
      if (uVar6 == 0) {
        if (0 < *param_1) goto loc_400EEC0;
        if (bVar2) {
          _getthetime(&iStack_1c);
          iVar7 = iVar7 - ((iStack_18 - iStack_8) + (iStack_1c - iStack_c) * 1000000);
        }
        else {
          bVar2 = true;
          _getthetime(&iStack_c);
        }
      }
      else {
        iVar5 = *param_1;
        if (iVar5 < 1) goto loc_400EE5C;
        if ((int)uVar6 <= iVar5) goto loc_400EEC0;
        if (bVar2) {
          if (iStack_20 < iVar5) {
            _getthetime(&iStack_c);
          }
          else {
            _getthetime(&iStack_14);
            iVar7 = iVar7 - ((iStack_10 - iStack_8) + (iStack_14 - iStack_c) * 1000000);
          }
        }
        else {
          bVar2 = true;
          _getthetime(&iStack_c);
        }
        iStack_20 = *param_1;
      }
      if (iVar7 < 1) goto loc_400EEC0;
      iVar7 = _hz * iVar7;
      _untimeout(_wakeup,param_1);
      _timeout(_wakeup,param_1,(iVar7 + 999999) / 1000000);
    }
  }
loc_400EE5C:
  bVar3 = false;
  if (((*(byte *)((int)param_1 + 0x41) & 0x10) != 0) || (*(sword *)(iVar4 + 0x12) < 0)) {
    bVar3 = true;
  }
  if ((!bVar3) && ((*(byte *)((int)param_1 + 0x41) & 4) != 0)) {
    return 0;
  }
  if ((*(byte *)(param_1 + 0x10) & 0x20) != 0) {
loc_400EE90:
    if ((*(byte *)(*_active_u + 0x16) & 0x40) != 0) {
      return 0xb;
    }
    return 0x23;
  }
  _sleep(param_1,0x1c);
  goto loc_400EC26;
loc_400EEC0:
  bVar2 = true;
  do {
    uVar6 = _getc(piVar11);
    if ((int)uVar6 < 0) goto loc_400EF76;
    cVar8 = (char)uVar6;
    if (cVar8 != -1) {
      if (((cVar8 == *(char *)((int)param_1 + 0x55)) && ((uVar1 & 0x20) == 0)) &&
         ((*(byte *)(iVar4 + 0x13) & 8) != 0)) break;
      if (((cVar8 != -1) && (cVar8 == *(char *)((int)param_1 + 0x52))) && ((uVar1 & 0x22) == 0))
      goto loc_400EF76;
    }
    iVar9 = _ureadc(uVar6,param_2);
    if (((iVar9 != 0) || (*(int *)(param_2 + 0x12) == 0)) ||
       (((uVar1 & 0x22) == 0 &&
        ((uVar6 == 10 ||
         (((*(byte *)((int)param_1 + 0x52) == uVar6 || (*(byte *)((int)param_1 + 0x53) == uVar6)) &&
          (uVar6 != 0xff)))))))) goto loc_400EF76;
    bVar2 = false;
  } while( true );
  _gsignal((int)*(sword *)((int)param_1 + 0x42),0x12);
  if (!bVar2) {
loc_400EF76:
    if (*param_1 < 0xcc) {
      *(byte *)((int)param_1 + 0x3f) = *(byte *)((int)param_1 + 0x3f) & 0x7f;
      if ((((*(uint *)((int)param_1 + 0x3e) & 0x400) != 0) &&
          ((*(uint *)((int)param_1 + 0x3e) & 0x1000000) == 0)) &&
         ((*(char *)(param_1 + 0x14) != -1 &&
          (iVar4 = _putc((int)*(char *)(param_1 + 0x14),param_1 + 6), iVar4 == 0)))) {
        *(word *)(param_1 + 0x10) = *(word *)(param_1 + 0x10) & 0xfbff;
        _ttstart(param_1);
      }
    }
    return iVar9;
  }
  _sleep(param_1,0x1c);
  goto loc_400EC24;
}
/* GHIDRADEC_FUNCTION index=318 start=0x400efe8 */

undefined4 _ttycheckoutq(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = (int)*(sword *)(_tthiwat + (*(byte *)(param_1 + 0x48) & 0x1f) * 2);
  if ((iVar1 + 200 < *(int *)(param_1 + 0x18)) && (iVar1 < *(int *)(param_1 + 0x18))) {
    do {
      _ttstart(param_1);
      if (param_2 == 0) {
        return 0;
      }
      *(uint *)(param_1 + 0x3e) = *(uint *)(param_1 + 0x3e) | 0x40;
      _sleep((int *)(param_1 + 0x18),0x1d);
    } while (iVar1 < *(int *)(param_1 + 0x18));
  }
  return 1;
}
/* GHIDRADEC_FUNCTION index=319 start=0x400f066 */

int _ttwrite(int param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  word wVar7;
  sword sVar8;
  int iVar9;
  int iVar10;
  byte *pbVar11;
  byte *pbVar12;
  byte *pbVar13;
  int iVar14;
  byte abStack_68 [100];
  
  iVar4 = _ttynty(param_1);
  iVar14 = (int)*(sword *)(_tthiwat + (*(byte *)(param_1 + 0x48) & 0x1f) * 2);
  iVar1 = *(int *)((int)param_2 + 0x12);
  iVar10 = 0;
loc_400F0B8:
  do {
    uVar2 = *(uint *)(param_1 + 0x3e);
    if (((uVar2 & 0x10) != 0) || (*(sword *)(iVar4 + 0x12) < 0)) {
      iVar9 = *_active_u;
      if ((*(byte *)(iVar9 + 0x16) & 0x40) == 0) {
        if ((((*(sword *)(iVar9 + 0x2e) == *(sword *)(param_1 + 0x42)) ||
             (param_1 != *(int *)((int)_active_u + 0x15e))) ||
            ((*(byte *)(param_1 + 0x3b) & 0x40) == 0)) ||
           ((((*(byte *)(iVar9 + 0x2a) & 0x10) != 0 || ((*(byte *)(iVar9 + 0x21) & 0x20) != 0)) ||
            ((*(byte *)(iVar9 + 0x1d) & 0x20) != 0)))) goto loc_400F1C8;
        iVar6 = (int)*(sword *)(iVar9 + 0x2e);
      }
      else {
        iVar5 = _get_posix_proc((int)*(sword *)(iVar9 + 0x30));
        iVar6 = *(int *)(*(int *)(iVar5 + 0xe) + 0xc);
        if (((*(sword *)(param_1 + 0x42) == iVar6) || (param_1 != *(int *)((int)_active_u + 0x15e)))
           || (((*(byte *)(param_1 + 0x3b) & 0x40) == 0 ||
               (((*(byte *)(iVar9 + 0x21) & 0x20) != 0 || ((*(byte *)(iVar9 + 0x1d) & 0x20) != 0))))
              )) {
loc_400F1C8:
          if (*(int *)((int)param_2 + 0x12) < 1) {
loc_400F3C6:
            _ttstart(param_1);
            return iVar10;
          }
          do {
            iVar9 = *(int *)(*param_2 + 4);
            if (iVar9 == 0) {
              param_2[1] = param_2[1] + -1;
              *param_2 = *param_2 + 8;
              if (param_2[1] < 1) {
                    /* WARNING: Subroutine does not return */
                _panic(&aTtwrite);
              }
            }
            else {
              if (100 < iVar9) {
                iVar9 = 100;
              }
              pbVar13 = abStack_68;
              iVar10 = _uiomove(pbVar13,iVar9,1,param_2);
              if (iVar10 != 0) goto loc_400F3C6;
              if (iVar14 < *(int *)(param_1 + 0x18)) goto loc_400F3D4;
              if ((*(uint *)(param_1 + 0x3a) & 0x800000) == 0) {
                if (((*(uint *)(param_1 + 0x3a) & 0x200024) == 4) &&
                   ((*(byte *)(iVar4 + 0x10) & 0x10) != 0)) {
                  if (0 < iVar9) {
                    while( true ) {
                      bVar3 = *pbVar13;
                      *(undefined *)(param_1 + 0x49) = 0;
                      iVar6 = _ttyoutput((int)(char)bVar3,param_1);
                      if (-1 < iVar6) break;
                      iVar9 = iVar9 + -1;
                      if (iVar14 < *(int *)(param_1 + 0x18)) goto loc_400F3D4;
                      pbVar13 = pbVar13 + 1;
                      if (iVar9 < 1) goto loc_400F3BE;
                    }
                    _ttstart(param_1);
                    _sleep(&_lbolt,0x1d);
                    *(undefined *)(param_1 + 0x49) = 0;
loc_400F286:
                    if (iVar9 != 0) {
                      *(int *)*param_2 = *(int *)*param_2 - iVar9;
                      *(int *)(*param_2 + 4) = iVar9 + *(int *)(*param_2 + 4);
                      *(int *)((int)param_2 + 0x12) = iVar9 + *(int *)((int)param_2 + 0x12);
                      param_2[2] = param_2[2] - iVar9;
                    }
                    goto loc_400F0B8;
                  }
                }
                else {
                  if (((*(uint *)(param_1 + 0x3a) & 0x2200020) == 0) &&
                     ((((*(uint *)(iVar4 + 0x10) & 0x10000000) != 0 &&
                       ((*(uint *)(iVar4 + 0x10) & 0x300) != 0x300)) &&
                      (iVar6 = iVar9 + -1, pbVar11 = pbVar13, -1 < iVar6)))) {
                    do {
                      do {
                        pbVar12 = pbVar11 + 1;
                        *pbVar11 = *pbVar11 & 0x7f;
                        wVar7 = (word)((uint)iVar6 >> 0x10);
                        sVar8 = (sword)iVar6 + -1;
                        iVar6 = CONCAT22(wVar7,sVar8);
                        pbVar11 = pbVar12;
                      } while (sVar8 != -1);
                      iVar6 = (uint)wVar7 * 0x10000 + -1;
                    } while (wVar7 != 0);
                  }
                  while (0 < iVar9) {
                    iVar6 = iVar9;
                    if (((*(uint *)(param_1 + 0x3a) & 0x200020) == 0) &&
                       ((*(byte *)(iVar4 + 0x10) & 0x10) != 0)) {
                      iVar5 = _scanc(iVar9,pbVar13,_partab,0x3f);
                      iVar6 = iVar9 - iVar5;
                      if (iVar9 - iVar5 != 0) goto loc_400F382;
                      *(undefined *)(param_1 + 0x49) = 0;
                      iVar6 = _ttyoutput((int)(char)*pbVar13,param_1);
                      if (-1 < iVar6) {
                        _ttstart(param_1);
                        _sleep(&_lbolt,0x1d);
                        goto loc_400F286;
                      }
                      pbVar13 = pbVar13 + 1;
                      iVar9 = iVar9 + -1;
                      if (*(char *)(param_1 + 0x3b) < '\0') goto loc_400F3D4;
                      iVar6 = *(int *)(param_1 + 0x18);
                    }
                    else {
loc_400F382:
                      *(undefined *)(param_1 + 0x49) = 0;
                      iVar5 = _b_to_q(pbVar13,iVar6,(int *)(param_1 + 0x18));
                      iVar6 = iVar6 - iVar5;
                      *(char *)(param_1 + 0x46) = (char)iVar6 + *(char *)(param_1 + 0x46);
                      pbVar13 = pbVar13 + iVar6;
                      iVar9 = iVar9 - iVar6;
                      _tk_nout = iVar6 + _tk_nout;
                      if (0 < iVar5) {
                        _ttstart(param_1);
                        _sleep(&_lbolt,0x1d);
                        *(int *)*param_2 = *(int *)*param_2 - iVar9;
                        *(int *)(*param_2 + 4) = iVar9 + *(int *)(*param_2 + 4);
                        *(int *)((int)param_2 + 0x12) = iVar9 + *(int *)((int)param_2 + 0x12);
                        param_2[2] = param_2[2] - iVar9;
                        goto loc_400F0B8;
                      }
                      if (*(char *)(param_1 + 0x3b) < '\0') goto loc_400F3D4;
                      iVar6 = *(int *)(param_1 + 0x18);
                    }
                    if (iVar14 < iVar6) goto loc_400F3D4;
                  }
                }
              }
            }
loc_400F3BE:
            if (*(int *)((int)param_2 + 0x12) < 1) goto loc_400F3C6;
          } while( true );
        }
        if (*(int *)(*(int *)(iVar5 + 0xe) + 0x10) == 0) {
          return 5;
        }
      }
      _gsignal(iVar6,0x16);
      _sleep(&_lbolt,0x1c);
      goto loc_400F0B8;
    }
    if (-1 < (sword)uVar2) {
      return 5;
    }
    if ((uVar2 & 0x2000) != 0) goto loc_400F420;
    _sleep(param_1,0x1c);
  } while( true );
loc_400F3D4:
  if (iVar9 != 0) {
    *(int *)*param_2 = *(int *)*param_2 - iVar9;
    *(int *)(*param_2 + 4) = iVar9 + *(int *)(*param_2 + 4);
    *(int *)((int)param_2 + 0x12) = iVar9 + *(int *)((int)param_2 + 0x12);
    param_2[2] = param_2[2] - iVar9;
  }
  _ttstart(param_1);
  if (iVar14 < *(int *)(param_1 + 0x18)) {
    if ((*(uint *)(param_1 + 0x3e) & 0x2000) != 0) {
      if (iVar1 != *(int *)((int)param_2 + 0x12)) {
        return 0;
      }
loc_400F420:
      if ((*(byte *)(*_active_u + 0x16) & 0x40) != 0) {
        return 0xb;
      }
      return 0x23;
    }
    *(uint *)(param_1 + 0x3e) = *(uint *)(param_1 + 0x3e) | 0x40;
    _sleep(param_1 + 0x18,0x1d);
  }
  goto loc_400F0B8;
}
/* GHIDRADEC_FUNCTION index=320 start=0x400f464 */

void _ttyrub(uint param_1,int *param_2)

{
  int *piVar1;
  uint uVar2;
  char cVar3;
  int iVar4;
  word wVar5;
  sword sVar6;
  undefined4 uVar7;
  undefined4 uStack_8;
  
  piVar1 = (int *)*param_2;
  uVar2 = *(uint *)((int)piVar1 + 0x3a);
  if ((uVar2 & 8) == 0) {
    return;
  }
  if ((*(byte *)((int)piVar1 + 0x3f) & 0x40) != 0) {
    return;
  }
  *(uint *)((int)piVar1 + 0x3a) = uVar2 & 0xff7fffff;
  if ((uVar2 & 0x10000) == 0) {
    if ((uVar2 & 0x20000) == 0) {
      param_1 = (uint)*(byte *)(piVar1 + 0x13);
    }
    else if ((*(byte *)((int)piVar1 + 0x3f) & 4) == 0) {
      _ttyoutput(0x5c,piVar1);
      *(byte *)((int)piVar1 + 0x3f) = *(byte *)((int)piVar1 + 0x3f) | 4;
    }
    _ttyecho(param_1,param_2);
    goto loc_400F606;
  }
  if (*(char *)((int)piVar1 + 0x49) == '\0') {
loc_400F520:
    _ttyretype(param_2);
    return;
  }
  if (param_1 - 0x109 < 2) {
loc_400F506:
    uVar7 = 2;
  }
  else {
    switch(_partab[param_1 & 0xff] & 0x3f) {
    case :
      uVar7 = 1;
      break;
    case :
    case :
    case :
    case :
    case :
      if ((*(byte *)((int)piVar1 + 0x3a) & 0x10) == 0) goto loc_400F606;
      goto loc_400F506;
    case :
      if ((int)*(char *)((int)piVar1 + 0x49) < *piVar1) goto loc_400F520;
      cVar3 = *(char *)((int)piVar1 + 0x46);
      *(byte *)((int)piVar1 + 0x3f) = *(byte *)((int)piVar1 + 0x3f) | 0x20;
      *(byte *)((int)piVar1 + 0x3b) = *(byte *)((int)piVar1 + 0x3b) | 0x80;
      *(undefined *)((int)piVar1 + 0x46) = *(undefined *)((int)piVar1 + 0x4a);
      iVar4 = piVar1[1] + -1;
      while (iVar4 = _nextc3(piVar1,iVar4,&uStack_8), iVar4 != 0) {
        _ttyecho(uStack_8,param_2);
      }
      *(byte *)((int)piVar1 + 0x3b) = *(byte *)((int)piVar1 + 0x3b) & 0x7f;
      *(byte *)((int)piVar1 + 0x3f) = *(byte *)((int)piVar1 + 0x3f) & 0xdf;
      iVar4 = (int)cVar3 - (int)*(char *)((int)piVar1 + 0x46);
      *(char *)((int)piVar1 + 0x46) = (char)iVar4 + *(char *)((int)piVar1 + 0x46);
      if (8 < iVar4) {
        iVar4 = 8;
      }
      iVar4 = iVar4 + -1;
      if (-1 < iVar4) {
        do {
          do {
            _ttyoutput(8,piVar1);
            wVar5 = (word)((uint)iVar4 >> 0x10);
            sVar6 = (sword)iVar4 + -1;
            iVar4 = CONCAT22(wVar5,sVar6);
          } while (sVar6 != -1);
          iVar4 = (uint)wVar5 * 0x10000 + -1;
        } while (wVar5 != 0);
      }
      goto loc_400F606;
    :
                    /* WARNING: Subroutine does not return */
      _panic(&aTtyrub);
    }
  }
  _ttyrubo(piVar1,uVar7);
loc_400F606:
  *(char *)((int)piVar1 + 0x49) = *(char *)((int)piVar1 + 0x49) + -1;
  return;
}
/* GHIDRADEC_FUNCTION index=321 start=0x400f614 */

void _ttyrubo(int param_1,int param_2)

{
  word wVar1;
  sword sVar2;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)&DAT_40a63bf;
  if ((*(byte *)(param_1 + 0x3b) & 4) != 0) {
    puVar3 = &DAT_40a63bb;
  }
  param_2 = param_2 + -1;
  if (-1 < param_2) {
    do {
      do {
        _ttyoutstr(puVar3,param_1);
        wVar1 = (word)((uint)param_2 >> 0x10);
        sVar2 = (sword)param_2 + -1;
        param_2 = CONCAT22(wVar1,sVar2);
      } while (sVar2 != -1);
      param_2 = (uint)wVar1 * 0x10000 + -1;
    } while (wVar1 != 0);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=322 start=0x400f65c */

byte _ttyretype(int *param_1)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  char cVar4;
  undefined4 uStack_8;
  
  iVar1 = *param_1;
  if (*(char *)(iVar1 + 0x56) != -1) {
    _ttyecho(*(char *)(iVar1 + 0x56),param_1);
  }
  _ttyoutput(10,iVar1);
  iVar3 = *(int *)(iVar1 + 0x10) + -1;
  while( true ) {
    iVar3 = _nextc3(iVar1 + 0xc,iVar3,&uStack_8);
    if (iVar3 == 0) break;
    _ttyecho(uStack_8,param_1);
  }
  cVar4 = *(int *)(iVar1 + 4) == 0;
  iVar3 = *(int *)(iVar1 + 4) + -1;
  while( true ) {
    iVar3 = _nextc3(iVar1,iVar3,&uStack_8);
    if (iVar3 == 0) break;
    _ttyecho(uStack_8,param_1);
  }
  bVar2 = *(byte *)(iVar1 + 0x3f);
  *(byte *)(iVar1 + 0x3f) = bVar2 & 0xfb;
  *(undefined *)(iVar1 + 0x49) = *(undefined *)(iVar1 + 3);
  *(undefined *)(iVar1 + 0x4a) = 0;
  return cVar4 << 4 | ((bVar2 & 4) == 0) << 2;
}
/* GHIDRADEC_FUNCTION index=323 start=0x400f714 */

void _ttyecho(uint param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = *param_2;
  if ((*(byte *)(iVar1 + 0x3f) & 0x20) == 0) {
    *(byte *)(iVar1 + 0x3b) = *(byte *)(iVar1 + 0x3b) & 0x7f;
  }
  if ((((*(uint *)(iVar1 + 0x3a) & 8) != 0) ||
      (((*(byte *)((int)param_2 + 0x13) & 2) != 0 && (param_1 == 10)))) &&
     ((*(byte *)(iVar1 + 0x3f) & 0x40) == 0)) {
    if (((*(uint *)(iVar1 + 0x3a) & 0x10000000) != 0) &&
       ((((param_1 & 0xff) < 0x20 && (1 < param_1 - 9)) || ((param_1 & 0xff) == 0x7f)))) {
      _ttyoutput(0x5e,iVar1);
      param_1 = param_1 & 0xff;
      if (param_1 == 0x7f) {
        param_1 = 0x3f;
      }
      else if ((*(byte *)(iVar1 + 0x3d) & 4) == 0) {
        param_1 = param_1 + 0x40;
      }
      else {
        param_1 = param_1 + 0x60;
      }
    }
    param_1 = param_1 & 0xff;
    if (((0x1f < param_1) &&
        ((((*(byte *)(iVar1 + 0x3a) & 8) != 0 || ((*(byte *)((int)param_2 + 0x11) & 0x40) != 0)) ||
         (param_1 < 0x7f)))) || ((param_1 - 7 < 4 || (param_1 == 0xd)))) {
      _ttyoutput(param_1,iVar1);
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=324 start=0x400f7fe */

void _ttyoutstr(char *param_1,undefined4 param_2)

{
  while( true ) {
    if (*param_1 == '\0') break;
    _ttyoutput((int)*param_1,param_2);
    param_1 = param_1 + 1;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=325 start=0x400f82e */

undefined4 _ttcheckwakeup(int *param_1)

{
  undefined4 uVar1;
  
  uVar1 = 1;
  if ((((*(uint *)(*param_1 + 0x3a) & 0x22) != 0) &&
      (*(int *)*param_1 < (int)(uint)*(byte *)((int)param_1 + 0x15))) &&
     (*(char *)((int)param_1 + 0x16) == '\0')) {
    uVar1 = 0;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=326 start=0x400f85a */

void _ttwakeup(int param_1)

{
  if (*(int *)(param_1 + 0x28) != 0) {
    _selwakeup(*(int *)(param_1 + 0x28),*(uint *)(param_1 + 0x3e) & 0x800);
    _selthreadclear(param_1 + 0x28);
    *(word *)(param_1 + 0x40) = *(word *)(param_1 + 0x40) & 0xf7ff;
  }
  if ((*(byte *)(param_1 + 0x40) & 0x40) != 0) {
    _gsignal((int)*(sword *)(param_1 + 0x42),0x17);
  }
  _wakeup(param_1);
  return;
}
/* GHIDRADEC_FUNCTION index=327 start=0x400f8d0 */

undefined4
_tty_ld_install(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
               undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12)

{
  int iVar1;
  
  if (((((-1 < param_1) && (param_1 < _nldisp)) &&
       (iVar1 = param_1 * 0x30, (code *)(&_linesw)[param_1 * 0xc] == _nodev)) &&
      ((((*(code **)(unk_40AE4B0 + iVar1) == _nodev &&
         (*(code **)(unk_40AE4B0 + iVar1 + 4) == _nodev)) &&
        ((*(code **)(unk_40AE4B0 + iVar1 + 8) == _nodev &&
         ((*(code **)(unk_40AE4B0 + iVar1 + 0xc) == _nodev &&
          (*(code **)(unk_40AE4B0 + iVar1 + 0x10) == _nodev)))))) &&
       (*(code **)(unk_40AE4B0 + iVar1 + 0x14) == _nodev)))) &&
     (((*(code **)(unk_40AE4B0 + iVar1 + 0x1c) == _nodev &&
       (*(code **)(unk_40AE4B0 + iVar1 + 0x20) == _nodev)) &&
      (*(code **)(unk_40AE4B0 + iVar1 + 0x24) == _nodev)))) {
    *(undefined4 *)(unk_40AE4B0 + iVar1 + 0x28) = param_2;
    (&_linesw)[param_1 * 0xc] = param_3;
    *(undefined4 *)(unk_40AE4B0 + iVar1) = param_4;
    *(undefined4 *)(unk_40AE4B0 + iVar1 + 4) = param_5;
    *(undefined4 *)(unk_40AE4B0 + iVar1 + 8) = param_6;
    *(undefined4 *)(unk_40AE4B0 + iVar1 + 0xc) = param_7;
    *(undefined4 *)(unk_40AE4B0 + iVar1 + 0x10) = param_8;
    *(undefined4 *)(unk_40AE4B0 + iVar1 + 0x14) = param_9;
    *(undefined4 *)(unk_40AE4B0 + iVar1 + 0x1c) = param_10;
    *(undefined4 *)(unk_40AE4B0 + iVar1 + 0x20) = param_11;
    *(undefined4 *)(unk_40AE4B0 + iVar1 + 0x24) = param_12;
    return 0;
  }
  return 0xffffffff;
}
/* GHIDRADEC_FUNCTION index=328 start=0x400f99e */

void _tty_ld_remove(int param_1)

{
  int iVar1;
  
  if ((-1 < param_1) && (param_1 < _nldisp)) {
    iVar1 = param_1 * 0x30;
    (&_linesw)[param_1 * 0xc] = _nodev;
    *(code **)(unk_40AE4B0 + iVar1) = _nodev;
    *(code **)(unk_40AE4B0 + iVar1 + 4) = _nodev;
    *(code **)(unk_40AE4B0 + iVar1 + 8) = _nodev;
    *(code **)(unk_40AE4B0 + iVar1 + 0xc) = _nodev;
    *(code **)(unk_40AE4B0 + iVar1 + 0x10) = _nodev;
    *(code **)(unk_40AE4B0 + iVar1 + 0x14) = _nodev;
    *(code **)(unk_40AE4B0 + iVar1 + 0x1c) = _nodev;
    *(code **)(unk_40AE4B0 + iVar1 + 0x20) = _nodev;
    *(code **)(unk_40AE4B0 + iVar1 + 0x24) = _nodev;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=329 start=0x400fa20 */

void _ttydevstart(int param_1)

{
  if (*(code **)(param_1 + 0x24) != (code *)0x0) {
    (**(code **)(param_1 + 0x24))(param_1);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=330 start=0x400fa38 */

void _ttydevstop(int param_1)

{
  (**(code **)(DAT_40b0ad4 + (uint)*(byte *)(param_1 + 0x38) * 0x2c))(param_1,0);
  return;
}
/* GHIDRADEC_FUNCTION index=331 start=0x400fa6c */

byte _ttyselwait(int param_1,uint param_2)

{
  word wVar1;
  int iVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  char cVar6;
  bool bVar7;
  
  cVar6 = 1 < param_2;
  if (param_2 == 1) {
    iVar2 = _selthreadcache(param_1 + 0x28);
    bVar5 = false;
    bVar7 = false;
    bVar3 = iVar2 < 0;
    bVar4 = iVar2 == 0;
    if (!bVar4) {
      bVar5 = false;
      bVar7 = false;
      wVar1 = *(word *)(param_1 + 0x40) | 0x800;
      *(word *)(param_1 + 0x40) = wVar1;
      bVar3 = (sword)wVar1 < 0;
      bVar4 = wVar1 == 0;
    }
  }
  else {
    cVar6 = 2 < param_2;
    bVar5 = SBORROW4(2,param_2);
    bVar3 = (int)(2 - param_2) < 0;
    if (param_2 == 2) {
      iVar2 = _selthreadcache(param_1 + 0x2c);
      bVar5 = false;
      bVar7 = false;
      bVar3 = iVar2 < 0;
      bVar4 = iVar2 == 0;
      if (!bVar4) {
        bVar5 = false;
        bVar7 = false;
        wVar1 = *(word *)(param_1 + 0x40) | 0x1000;
        *(word *)(param_1 + 0x40) = wVar1;
        bVar3 = (sword)wVar1 < 0;
        bVar4 = wVar1 == 0;
      }
    }
    else {
      bVar4 = false;
      bVar7 = (bool)cVar6;
    }
  }
  return cVar6 << 4 | bVar3 << 3 | bVar4 << 2 | bVar5 << 1 | bVar7;
}
/* GHIDRADEC_FUNCTION index=332 start=0x400facc */

undefined4 _ttselwakeup(int param_1)

{
  int iVar1;
  word wVar2;
  undefined2 extraout_D0u;
  undefined2 uVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  byte bVar8;
  
  cVar4 = '\0';
  iVar1 = *(int *)(param_1 + 0x28);
  cVar5 = iVar1 < 0;
  cVar6 = iVar1 == 0;
  cVar7 = '\0';
  bVar8 = 0;
  uVar3 = 0;
  if (!(bool)cVar6) {
    _selwakeup(iVar1,*(uint *)(param_1 + 0x3e) & 0x800);
    cVar7 = '\0';
    bVar8 = 0;
    wVar2 = *(word *)(param_1 + 0x40) & 0xf7ff;
    *(word *)(param_1 + 0x40) = wVar2;
    cVar5 = (int)((uint)wVar2 << 0x10) < 0;
    cVar6 = wVar2 == 0;
    _selthreadclear(param_1 + 0x28);
    uVar3 = extraout_D0u;
  }
  return CONCAT22(uVar3,(word)(byte)(cVar4 << 4 | cVar5 << 3 | cVar6 << 2 | cVar7 << 1 | bVar8));
}
/* GHIDRADEC_FUNCTION index=333 start=0x400fb1c */

void _ttsettermios(int *param_1,uint *param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  iVar1 = *param_1;
  uVar2 = *param_2;
  uVar3 = param_2[3];
  uVar4 = param_2[1];
  uVar5 = param_2[2];
  uVar8 = 0;
  uVar7 = 0;
  if (((((uVar2 & 0x23e2) == 0) && ((uVar4 & 1) == 0)) && ((uVar3 & 0xe0) == 0)) &&
     ((uVar5 & 0x1300) == 0x300)) {
    uVar8 = 0x20;
  }
  else {
    if ((uVar2 & 2) != 0) {
      uVar7 = 0x40000;
    }
    if ((uVar2 & 0x20) != 0) {
      uVar7 = uVar7 | 0x400000;
    }
    if ((uVar2 & 0x40) != 0) {
      uVar7 = uVar7 | 0x800000;
    }
    if ((char)uVar2 < '\0') {
      uVar7 = uVar7 | 0x1000000;
    }
    if ((uVar2 & 0x200) != 0) {
      uVar7 = uVar7 | 0x4000000;
    }
    if ((uVar2 & 0x2000) != 0) {
      uVar7 = uVar7 | 0x8000000;
    }
    if ((uVar4 & 1) != 0) {
      uVar7 = uVar7 | 0x10000000;
    }
    if ((uVar4 & 2) == 0) {
loc_400FBC8:
      if ((uVar2 & 0x100) != 0) {
        uVar7 = uVar7 | 0x2000000;
      }
    }
    else {
      if ((uVar2 & 0x100) == 0) {
        uVar7 = uVar7 | 0x20000000;
        goto loc_400FBC8;
      }
      uVar8 = 0x10;
    }
    if ((uVar3 & 0x20) == 0) {
      uVar8 = uVar8 | 2;
    }
    if ((uVar3 & 0x40) != 0) {
      uVar7 = uVar7 | 8;
    }
    if ((char)uVar3 < '\0') {
      uVar7 = uVar7 | 0x10;
    }
    if ((uVar5 & 0x1000) != 0) {
      uVar7 = uVar7 | 0x1000;
    }
    uVar6 = uVar5 & 0x300;
    if (uVar6 == 0x100) {
      uVar7 = uVar7 | 0x100;
    }
    else if (0x100 < uVar6) {
      if (uVar6 == 0x200) {
        uVar7 = uVar7 | 0x200;
      }
      else if ((uVar6 == 0x300) && (uVar7 = uVar7 | 0x300, (uVar5 & 0x1000) == 0)) {
        if ((uVar4 & 1) == 0) {
          uVar6 = 0x200000;
        }
        else {
          uVar6 = 0x2000000;
        }
        uVar8 = uVar8 | uVar6;
        if ((uVar2 & 0x20) == 0) {
          uVar8 = uVar8 | 0x8000000;
        }
      }
    }
  }
  if ((uVar5 & 0x2000) != 0) {
    uVar8 = uVar8 | 0x40;
    goto loc_400FC78;
  }
  if ((char)uVar3 < '\0') {
    if ((uVar5 & 0x40000) != 0) {
      uVar8 = uVar8 | 0xc0;
      goto loc_400FC78;
    }
    if ((uVar5 & 0x20000) != 0) goto loc_400FC78;
  }
  uVar8 = uVar8 | 0x80;
loc_400FC78:
  if ((uVar5 & 0x400) != 0) {
    uVar7 = uVar7 | 0x400;
  }
  if ((uVar5 & 0x800) != 0) {
    uVar7 = uVar7 | 0x800;
  }
  if ((uVar5 & 0x4000) == 0) {
    uVar8 = uVar8 | 0x1000000;
  }
  if ((sword)uVar5 < 0) {
    uVar7 = uVar7 | 0x8000;
  }
  if ((uVar5 & 0x10000) != 0) {
    uVar7 = uVar7 | 0x10000;
  }
  if ((uVar2 & 1) != 0) {
    uVar7 = uVar7 | 0x20000;
  }
  if ((uVar2 & 4) != 0) {
    uVar7 = uVar7 | 0x80000;
  }
  if ((uVar2 & 8) != 0) {
    uVar7 = uVar7 | 0x100000;
  }
  if ((uVar2 & 0x10) != 0) {
    uVar7 = uVar7 | 0x200000;
  }
  if ((uVar2 & 0x400) != 0) {
    uVar8 = uVar8 | 1;
  }
  if ((uVar2 & 0x800) == 0) {
    uVar8 = uVar8 | 0x40000000;
  }
  uVar8 = uVar4 & 0xff00 | uVar8;
  if ((uVar3 & 2) != 0) {
    uVar8 = uVar8 | 0x10000;
  }
  if ((uVar3 & 4) != 0) {
    uVar7 = uVar7 | 4;
  }
  if ((uVar3 & 1) != 0) {
    uVar8 = uVar8 | 0x4000000;
  }
  if ((uVar3 & 0x100) != 0) {
    uVar8 = uVar8 | 0x40000;
  }
  if ((uVar3 & 0x200) != 0) {
    uVar8 = uVar8 | 0x20000;
  }
  if ((uVar3 & 0x400) != 0) {
    uVar8 = uVar8 | 0x10000000;
  }
  if ((uVar3 & 0x10) != 0) {
    uVar7 = uVar7 | 2;
  }
  if ((uVar3 & 0x800) != 0) {
    uVar7 = uVar7 | 0x20;
  }
  if ((uVar3 & 0x4000000) != 0) {
    uVar8 = uVar8 | 4;
  }
  if ((uVar3 & 0x8000000) != 0) {
    uVar8 = uVar8 | 0x80000;
  }
  *(uint *)(*param_1 + 0x3a) = uVar3 & 0x80500008 | uVar8;
  param_1[4] = uVar7;
  *(undefined *)(iVar1 + 0x47) = *(undefined *)((int)param_2 + 0x21);
  *(undefined *)(iVar1 + 0x48) = *(undefined *)((int)param_2 + 0x22);
  *(undefined *)(iVar1 + 0x4c) = *(undefined *)((int)param_2 + 0x12);
  *(undefined *)(iVar1 + 0x4d) = *(undefined *)((int)param_2 + 0x13);
  *(undefined *)(iVar1 + 0x4e) = *(undefined *)(param_2 + 5);
  *(undefined *)(iVar1 + 0x4f) = *(undefined *)((int)param_2 + 0x15);
  *(undefined *)(iVar1 + 0x50) = *(undefined *)((int)param_2 + 0x17);
  *(undefined *)(iVar1 + 0x51) = *(undefined *)(param_2 + 6);
  *(undefined *)(iVar1 + 0x52) = *(undefined *)(param_2 + 4);
  *(undefined *)(iVar1 + 0x53) = *(undefined *)((int)param_2 + 0x11);
  *(undefined *)(iVar1 + 0x54) = *(undefined *)((int)param_2 + 0x16);
  *(undefined *)(iVar1 + 0x55) = *(undefined *)((int)param_2 + 0x1f);
  *(undefined *)(iVar1 + 0x56) = *(undefined *)(param_2 + 7);
  *(undefined *)(iVar1 + 0x57) = *(undefined *)((int)param_2 + 0x1e);
  *(undefined *)(iVar1 + 0x58) = *(undefined *)((int)param_2 + 0x1b);
  *(undefined *)(iVar1 + 0x59) = *(undefined *)((int)param_2 + 0x1d);
  *(undefined *)((int)param_1 + 0x15) = *(undefined *)((int)param_2 + 0x19);
  *(undefined *)((int)param_1 + 0x16) = *(undefined *)((int)param_2 + 0x1a);
  *(undefined *)(param_1 + 5) = *(undefined *)(param_2 + 8);
  return;
}
/* GHIDRADEC_FUNCTION index=334 start=0x400fde2 */

void _ttgettermios(int *param_1,uint *param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  iVar1 = *param_1;
  uVar2 = *(uint *)(iVar1 + 0x3a);
  uVar3 = param_1[4];
  uVar5 = 0;
  uVar8 = 0;
  uVar6 = 0;
  uVar7 = 0;
  if ((uVar2 & 0x20) != 0) {
    uVar7 = 0x300;
    goto loc_400FEF6;
  }
  if ((uVar3 & 0x40000) != 0) {
    uVar5 = 2;
  }
  if ((uVar3 & 0x400000) != 0) {
    uVar5 = uVar5 | 0x20;
  }
  if ((uVar3 & 0x800000) != 0) {
    uVar5 = uVar5 | 0x40;
  }
  if ((uVar3 & 0x1000000) != 0) {
    uVar5 = uVar5 | 0x80;
  }
  if ((uVar3 & 0x4000000) != 0) {
    uVar5 = uVar5 | 0x200;
  }
  if ((uVar3 & 0x8000000) != 0) {
    uVar5 = uVar5 | 0x2000;
  }
  uVar8 = (uint)((uVar3 & 0x10000000) != 0);
  if ((uVar2 & 0x10) == 0) {
    if ((uVar3 & 0x2000000) != 0) {
      uVar5 = uVar5 | 0x100;
    }
    if ((uVar3 & 0x20000000) != 0) goto loc_400FE72;
  }
  else {
    uVar5 = uVar5 | 0x100;
loc_400FE72:
    uVar8 = uVar8 | 2;
  }
  if ((uVar2 & 2) == 0) {
    uVar6 = 0x20;
  }
  if ((uVar3 & 8) != 0) {
    uVar6 = uVar6 | 0x40;
  }
  if ((uVar3 & 0x10) != 0) {
    uVar6 = uVar6 | 0x80;
  }
  if ((uVar2 & 0xa200000) == 0) {
    if ((uVar3 & 0x1000) != 0) {
      uVar7 = 0x1000;
    }
    uVar4 = uVar3 & 0x300;
    if (uVar4 == 0x100) {
      uVar7 = uVar7 | 0x100;
    }
    else if (0x100 < uVar4) {
      if (uVar4 == 0x200) {
        uVar7 = uVar7 | 0x200;
      }
      else if (uVar4 == 0x300) {
        uVar7 = uVar7 | 0x300;
      }
    }
  }
  else {
    uVar7 = 0x300;
    if ((uVar2 & 0x8000000) != 0) {
      uVar5 = uVar5 & 0xffffffdf;
    }
    if ((uVar2 & 0x200000) != 0) {
      uVar8 = uVar8 & 0xfffffffe;
    }
  }
loc_400FEF6:
  uVar4 = uVar2 & 0xc0;
  if (uVar4 == 0x40) {
    uVar7 = uVar7 | 0x2000;
  }
  else if (uVar4 < 0x41) {
    if (uVar4 == 0) {
      uVar7 = uVar7 | 0x20000;
    }
  }
  else if ((uVar4 != 0x80) && (uVar4 == 0xc0)) {
    uVar7 = uVar7 | 0x40000;
  }
  if ((uVar3 & 0x400) != 0) {
    uVar7 = uVar7 | 0x400;
  }
  if ((uVar3 & 0x800) != 0) {
    uVar7 = uVar7 | 0x800;
  }
  if ((uVar2 & 0x1000000) == 0) {
    uVar7 = uVar7 | 0x4000;
  }
  if ((sword)uVar3 < 0) {
    uVar7 = uVar7 | 0x8000;
  }
  if ((uVar3 & 0x10000) != 0) {
    uVar7 = uVar7 | 0x10000;
  }
  if ((uVar3 & 0x20000) != 0) {
    uVar5 = uVar5 | 1;
  }
  if ((uVar3 & 0x80000) != 0) {
    uVar5 = uVar5 | 4;
  }
  if ((uVar3 & 0x100000) != 0) {
    uVar5 = uVar5 | 8;
  }
  if ((uVar3 & 0x200000) != 0) {
    uVar5 = uVar5 | 0x10;
  }
  if ((uVar2 & 1) != 0) {
    uVar5 = uVar5 | 0x400;
  }
  if ((uVar2 & 0x40000000) == 0) {
    uVar5 = uVar5 | 0x800;
  }
  if ((uVar2 & 0x10000) != 0) {
    uVar6 = uVar6 | 2;
  }
  if ((uVar3 & 4) != 0) {
    uVar6 = uVar6 | 4;
  }
  if ((uVar2 & 0x4000000) != 0) {
    uVar6 = uVar6 | 1;
  }
  if ((uVar2 & 0x40000) != 0) {
    uVar6 = uVar6 | 0x100;
  }
  if ((uVar2 & 0x20000) != 0) {
    uVar6 = uVar6 | 0x200;
  }
  if ((uVar2 & 0x10000000) != 0) {
    uVar6 = uVar6 | 0x400;
  }
  if ((uVar3 & 2) != 0) {
    uVar6 = uVar6 | 0x10;
  }
  if ((uVar3 & 0x20) != 0) {
    uVar6 = uVar6 | 0x800;
  }
  if ((uVar2 & 4) != 0) {
    uVar6 = uVar6 | 0x4000000;
  }
  if ((uVar2 & 0x80000) != 0) {
    uVar6 = uVar6 | 0x8000000;
  }
  *param_2 = uVar5;
  param_2[1] = uVar2 & 0xff00 | uVar8;
  param_2[3] = uVar2 & 0x80500008 | uVar6;
  param_2[2] = uVar7;
  *(undefined *)((int)param_2 + 0x21) = *(undefined *)(iVar1 + 0x47);
  *(undefined *)((int)param_2 + 0x22) = *(undefined *)(iVar1 + 0x48);
  *(undefined *)((int)param_2 + 0x12) = *(undefined *)(iVar1 + 0x4c);
  *(undefined *)((int)param_2 + 0x13) = *(undefined *)(iVar1 + 0x4d);
  *(undefined *)(param_2 + 5) = *(undefined *)(iVar1 + 0x4e);
  *(undefined *)((int)param_2 + 0x15) = *(undefined *)(iVar1 + 0x4f);
  *(undefined *)((int)param_2 + 0x17) = *(undefined *)(iVar1 + 0x50);
  *(undefined *)(param_2 + 6) = *(undefined *)(iVar1 + 0x51);
  *(undefined *)(param_2 + 4) = *(undefined *)(iVar1 + 0x52);
  *(undefined *)((int)param_2 + 0x11) = *(undefined *)(iVar1 + 0x53);
  *(undefined *)((int)param_2 + 0x16) = *(undefined *)(iVar1 + 0x54);
  *(undefined *)((int)param_2 + 0x1f) = *(undefined *)(iVar1 + 0x55);
  *(undefined *)(param_2 + 7) = *(undefined *)(iVar1 + 0x56);
  *(undefined *)((int)param_2 + 0x1e) = *(undefined *)(iVar1 + 0x57);
  *(undefined *)((int)param_2 + 0x1b) = *(undefined *)(iVar1 + 0x58);
  *(undefined *)((int)param_2 + 0x1d) = *(undefined *)(iVar1 + 0x59);
  *(undefined *)((int)param_2 + 0x19) = *(undefined *)((int)param_1 + 0x15);
  *(undefined *)((int)param_2 + 0x1a) = *(undefined *)((int)param_1 + 0x16);
  *(undefined *)(param_2 + 8) = *(undefined *)(param_1 + 5);
  return;
}
/* GHIDRADEC_FUNCTION index=335 start=0x401009c */

int * _ttynty(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  if (param_1 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aTtynty0);
  }
  piVar2 = (int *)&dword_40B3180;
  piVar1 = dword_40B3180;
  if (dword_40B3180 != (int *)0x0) {
    do {
      if (param_1 == *piVar1) break;
      piVar2 = piVar1 + 1;
      piVar1 = (int *)*piVar2;
    } while (piVar1 != (int *)0x0);
    if (piVar1 != (int *)0x0) {
      *piVar2 = piVar1[1];
      goto loc_4010116;
    }
  }
  piVar1 = (int *)_kalloc(0x18);
  *piVar1 = param_1;
  piVar1[4] = 0x1c251a1c;
  *(undefined *)(piVar1 + 5) = 0x5c;
  *(undefined *)((int)piVar1 + 0x15) = 1;
  *(undefined *)((int)piVar1 + 0x16) = 0;
  piVar1[2] = 0;
  piVar1[3] = 0;
loc_4010116:
  piVar1[1] = (int)dword_40B3180;
  dword_40B3180 = piVar1;
  return piVar1;
}
/* GHIDRADEC_FUNCTION index=336 start=0x4010136 */

undefined4 _nullioctl(void)

{
  return 0xffffffff;
}
/* GHIDRADEC_FUNCTION index=337 start=0x4010140 */

void _pty_init(void)

{
  _lock_init(&_pty_alloc_lock,1);
  return;
}
/* GHIDRADEC_FUNCTION index=338 start=0x4010158 */

int _pty_alloc(byte param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (sword)(word)param_1 * 0xe;
  if (*(int *)((int)&dword_40B318A + iVar1) == 0) {
    _lock_write(&_pty_alloc_lock);
    if (*(int *)((int)&dword_40B318A + iVar1) == 0) {
      uVar2 = _kalloc(0x86);
      *(undefined4 *)((int)&dword_40B318A + iVar1) = uVar2;
      _bzero(uVar2,0x86);
      uVar2 = _kalloc(0xe);
      *(undefined4 *)((int)&dword_40B318E + iVar1) = uVar2;
      _bzero(uVar2,0xe);
    }
    _lock_done(&_pty_alloc_lock);
  }
  return (int)&unk_40B3184 + iVar1;
}
/* GHIDRADEC_FUNCTION index=339 start=0x40101d8 */

int _ptsopen(word param_1,byte param_2)

{
  int iVar1;
  int iVar2;
  word *pwVar3;
  
  if ((param_1 & 0xff) < 0x20) {
    pwVar3 = (word *)_pty_alloc((int)(sword)param_1);
    iVar1 = *(int *)(pwVar3 + 3);
    *pwVar3 = param_1;
    if ((*(uint *)(iVar1 + 0x3e) & 4) == 0) {
      _ttychars(iVar1);
      *(undefined *)(iVar1 + 0x48) = 0xf;
      *(undefined *)(iVar1 + 0x47) = 0xf;
      *(undefined4 *)(iVar1 + 0x3a) = 0;
    }
    else if (((char)*(uint *)(iVar1 + 0x3e) < '\0') &&
            (*(sword *)(*(int *)(_active_u + 0x1a) + 2) != 0)) {
      return 0x10;
    }
    if (*(int *)(iVar1 + 0x24) != 0) {
      *(uint *)(iVar1 + 0x3e) = *(uint *)(iVar1 + 0x3e) | 0x10;
    }
    if ((param_2 & 4) == 0) {
      while ((*(uint *)(iVar1 + 0x3e) & 0x10) == 0) {
        *(uint *)(iVar1 + 0x3e) = *(uint *)(iVar1 + 0x3e) | 2;
        _sleep(iVar1,0x1c);
      }
    }
    else {
      *(word *)(iVar1 + 0x40) = *(word *)(iVar1 + 0x40) | 0x8000;
    }
    iVar2 = (*(code *)(&_linesw)[*(char *)(iVar1 + 0x45) * 0xc])((int)(sword)param_1,iVar1);
    if (iVar2 == 0) {
      *(uint *)(pwVar3 + 1) = *(uint *)(pwVar3 + 1) | 1;
    }
    _ptcwakeup(iVar1,3);
  }
  else {
    iVar2 = 6;
  }
  return iVar2;
}
/* GHIDRADEC_FUNCTION index=340 start=0x40102ca */

void _ptsclose(byte param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = (sword)(word)param_1 * 0xe;
  iVar1 = *(int *)((int)&dword_40B318A + iVar2);
  if ((*(byte *)((int)&DAT_40b3186 + iVar2 + 3) & 1) != 0) {
    (**(code **)(unk_40AE4B0 + *(char *)(iVar1 + 0x45) * 0x30))(iVar1);
    _ttyclose(iVar1);
    *(undefined4 *)((int)&DAT_40b3186 + iVar2) = 0;
  }
  _ptcwakeup(iVar1,3);
  return;
}
/* GHIDRADEC_FUNCTION index=341 start=0x4010334 */

undefined4 _ptsread(byte param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  
  iVar2 = *(int *)((int)&dword_40B318A + (sword)(word)param_1 * 0xe);
  iVar5 = *(int *)((int)&dword_40B318E + (sword)(word)param_1 * 0xe);
  uVar6 = 0;
  while ((*(byte *)(iVar5 + 3) & 0x20) != 0) {
    while ((iVar2 == *(int *)((int)_active_u + 0x15e) &&
           (iVar1 = *_active_u, *(sword *)(iVar2 + 0x42) != *(sword *)(iVar1 + 0x2e)))) {
      if ((*(byte *)(iVar1 + 0x16) & 0x40) == 0) {
        if ((((*(byte *)(iVar1 + 0x21) & 0x10) != 0) || ((*(byte *)(iVar1 + 0x1d) & 0x10) != 0)) ||
           ((*(byte *)(iVar1 + 0x2a) & 0x10) != 0)) {
          return 5;
        }
      }
      else {
        iVar3 = _get_posix_proc((int)*(sword *)(iVar1 + 0x30));
        if ((*(byte *)(iVar1 + 0x21) & 0x10) != 0) {
          return 5;
        }
        if ((*(byte *)(iVar1 + 0x1d) & 0x10) != 0) {
          return 5;
        }
        if (*(int *)(*(int *)(iVar3 + 0xe) + 0x10) == 0) {
          return 5;
        }
      }
      _gsignal((int)*(sword *)(*_active_u + 0x2e),0x15);
      _sleep(&_lbolt,0x1c);
    }
    if (*(int *)(iVar2 + 0xc) != 0) {
      if (*(int *)(iVar2 + 0xc) < 2) goto loc_4010470;
      goto loc_401044C;
    }
    if ((*(byte *)(iVar2 + 0x40) & 0x20) != 0) {
      if ((*(byte *)(*_active_u + 0x16) & 0x40) != 0) {
        return 0xb;
      }
      return 0x23;
    }
    _sleep(iVar2 + 0xc,0x1c);
  }
  if (*(int *)(iVar2 + 0x24) != 0) {
    uVar6 = (**(code **)(DAT_40ae4b4 + *(char *)(iVar2 + 0x45) * 0x30))(iVar2,param_2);
  }
  goto loc_40104B6;
  while( true ) {
    uVar4 = _getc((int *)(iVar2 + 0xc),param_2);
    iVar5 = _ureadc(uVar4);
    if (iVar5 < 0) {
      uVar6 = 0xe;
      break;
    }
    if (*(int *)(iVar2 + 0xc) < 2) break;
loc_401044C:
    if (*(int *)(param_2 + 0x12) < 1) break;
  }
loc_4010470:
  if (*(int *)(iVar2 + 0xc) == 1) {
    _getc(iVar2 + 0xc);
  }
  if (*(int *)(iVar2 + 0xc) != 0) {
    return uVar6;
  }
loc_40104B6:
  _ptcwakeup(iVar2,2);
  return uVar6;
}
/* GHIDRADEC_FUNCTION index=342 start=0x40104ce */

undefined4 _ptswrite(byte param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)((int)&dword_40B318A + (sword)(word)param_1 * 0xe);
  if (*(int *)(iVar1 + 0x24) == 0) {
    uVar2 = 5;
  }
  else {
    uVar2 = (**(code **)(DAT_40ae4b8 + *(char *)(iVar1 + 0x45) * 0x30))(iVar1,param_2);
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=343 start=0x401051c */

void _ptsselect(byte param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = *(int *)((int)&dword_40B318A + (sword)(word)param_1 * 0xe);
  (**(code **)(DAT_40ae4d4 + *(char *)(iVar1 + 0x45) * 0x30))(iVar1,param_2);
  return;
}
/* GHIDRADEC_FUNCTION index=344 start=0x4010560 */

void _ptsstart(int param_1)

{
  uint *puVar1;
  
  puVar1 = *(uint **)((int)&dword_40B318E + (sword)(*(word *)(param_1 + 0x38) & 0xff) * 0xe);
  if ((*(word *)(param_1 + 0x38) != 0) && ((*(byte *)(param_1 + 0x40) & 1) == 0)) {
    if ((*puVar1 & 0x10) != 0) {
      *puVar1 = *puVar1 & 0xffffffef;
      *(undefined *)(puVar1 + 3) = 8;
    }
    _ptcwakeup(param_1,1);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=345 start=0x40105b6 */

void _ptcwakeup(int param_1,uint param_2)

{
  uint *puVar1;
  
  puVar1 = *(uint **)((int)&dword_40B318E + (sword)(*(word *)(param_1 + 0x38) & 0xff) * 0xe);
  if (*(word *)(param_1 + 0x38) != 0) {
    if ((param_2 & 1) != 0) {
      if (puVar1[1] != 0) {
        _selwakeup(puVar1[1],*puVar1 & 1);
        _selthreadclear(puVar1 + 1);
        *puVar1 = *puVar1 & 0xfffffffe;
      }
      _wakeup(param_1 + 0x1c);
    }
    if ((param_2 & 2) != 0) {
      if (puVar1[2] != 0) {
        _selwakeup(puVar1[2],*puVar1 & 2);
        _selthreadclear(puVar1 + 2);
        *puVar1 = *puVar1 & 0xfffffffd;
      }
      _wakeup(param_1 + 4);
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=346 start=0x4010678 */

undefined4 _ptcopen(word param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  
  if ((param_1 & 0xff) < 0x20) {
    iVar3 = _pty_alloc((int)(sword)param_1);
    iVar3 = *(int *)(iVar3 + 6);
    if (*(int *)(iVar3 + 0x24) == 0) {
      *(code **)(iVar3 + 0x24) = _ptsstart;
      (**(code **)(DAT_40ae4d0 + *(char *)(iVar3 + 0x45) * 0x30))(iVar3,1);
      *(uint *)(iVar3 + 0x3e) = *(uint *)(iVar3 + 0x3e) & 0xffbfffff | 0x10;
      puVar1 = *(undefined4 **)((int)&dword_40B318E + (sword)(param_1 & 0xff) * 0xe);
      *puVar1 = 0;
      *(undefined *)(puVar1 + 3) = 0;
      *(undefined *)((int)puVar1 + 0xd) = 0;
      puVar1[2] = 0;
      puVar1[1] = 0;
      uVar2 = 0;
    }
    else {
      uVar2 = 5;
    }
  }
  else {
    uVar2 = 6;
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=347 start=0x401071a */

void _ptcclose(byte param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = (sword)(word)param_1 * 0xe;
  iVar1 = *(int *)((int)&dword_40B318E + iVar2);
  iVar3 = *(int *)((int)&dword_40B318A + iVar2);
  (**(code **)(DAT_40ae4d0 + *(char *)(iVar3 + 0x45) * 0x30))(iVar3,0);
  if ((*(byte *)((int)&unk_40B3184 + iVar2 + 5) & 1) != 0) {
    _forceclose((int)*(sword *)((int)&unk_40B3184 + iVar2));
    _ptsclose((int)*(sword *)((int)&unk_40B3184 + iVar2));
  }
  if (*(int *)(iVar1 + 4) != 0) {
    _selthreadclear(iVar1 + 4);
  }
  if (*(int *)(iVar1 + 8) != 0) {
    _selthreadclear(iVar1 + 8);
  }
  *(undefined4 *)(iVar3 + 0x24) = 0;
  iVar3 = _ttynty(iVar3);
  *(undefined4 *)(iVar3 + 8) = 0;
  return;
}
/* GHIDRADEC_FUNCTION index=348 start=0x40107cc */

int _ptcread(byte param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined uStack_82;
  undefined uStack_81;
  undefined uStack_80;
  undefined uStack_7f;
  undefined2 uStack_7e;
  undefined auStack_7c [6];
  undefined auStack_76 [6];
  undefined4 uStack_70;
  uint uStack_6c;
  undefined auStack_68 [100];
  
  iVar2 = *(int *)((int)&dword_40B318A + (sword)(word)param_1 * 0xe);
  iVar3 = *(int *)((int)&dword_40B318E + (sword)(word)param_1 * 0xe);
  iVar4 = 0;
  do {
    if ((*(byte *)(iVar2 + 0x41) & 4) != 0) {
      if (((*(byte *)(iVar3 + 3) & 8) != 0) && (*(char *)(iVar3 + 0xc) != '\0')) {
        iVar4 = _ureadc(*(char *)(iVar3 + 0xc),param_2);
        if (iVar4 != 0) {
          return iVar4;
        }
        if ((*(byte *)(iVar3 + 0xc) & 0x40) != 0) {
          uStack_82 = *(undefined *)(iVar2 + 0x47);
          uStack_81 = *(undefined *)(iVar2 + 0x48);
          uStack_80 = *(undefined *)(iVar2 + 0x4c);
          uStack_7f = *(undefined *)(iVar2 + 0x4d);
          uStack_7e = *(undefined2 *)(iVar2 + 0x3c);
          _bcopy(iVar2 + 0x4e,auStack_7c,6);
          _bcopy(iVar2 + 0x54,auStack_76,6);
          uStack_70 = *(undefined4 *)(iVar2 + 0x3e);
          uStack_6c = (uint)*(word *)(iVar2 + 0x3a);
          uVar1 = 0x1a;
          if (*(uint *)(param_2 + 0x12) < 0x1a) {
            uVar1 = *(uint *)(param_2 + 0x12);
          }
          _uiomove(&uStack_82,uVar1,0,param_2);
        }
        *(undefined *)(iVar3 + 0xc) = 0;
        return 0;
      }
      if ((*(char *)(iVar3 + 3) < '\0') && (*(char *)(iVar3 + 0xd) != '\0')) {
        iVar2 = _ureadc(*(char *)(iVar3 + 0xd),param_2);
        if (iVar2 != 0) {
          return iVar2;
        }
        *(undefined *)(iVar3 + 0xd) = 0;
        return 0;
      }
      if ((*(int *)(iVar2 + 0x18) != 0) && ((*(byte *)(iVar2 + 0x40) & 1) == 0)) {
        if ((*(byte *)(iVar3 + 3) & 0x88) != 0) {
          iVar4 = _ureadc(0,param_2);
        }
        iVar3 = *(int *)(param_2 + 0x12);
        if ((iVar3 < 1) || (iVar4 != 0)) goto loc_4010988;
        break;
      }
    }
    if ((*(byte *)(iVar2 + 0x41) & 0x10) == 0) {
      return 5;
    }
    if ((*(byte *)(iVar3 + 3) & 4) != 0) {
      iVar2 = 0x23;
      if ((*(byte *)(*_active_u + 0x16) & 0x40) != 0) {
        iVar2 = 0xb;
      }
      return iVar2;
    }
    _sleep(iVar2 + 0x1c,0x1c);
  } while( true );
loc_401094C:
  if (100 < iVar3) {
    iVar3 = 100;
  }
  iVar3 = _q_to_b(iVar2 + 0x18,auStack_68,iVar3);
  if (iVar3 < 1) {
loc_4010988:
    if ((int)*(sword *)(_ttlowat + (*(byte *)(iVar2 + 0x48) & 0x1f) * 2) < *(int *)(iVar2 + 0x18)) {
      return iVar4;
    }
    if ((*(uint *)(iVar2 + 0x3e) & 0x40) != 0) {
      *(uint *)(iVar2 + 0x3e) = *(uint *)(iVar2 + 0x3e) & 0xffffffbf;
      _wakeup(iVar2 + 0x18);
    }
    if (*(int *)(iVar2 + 0x2c) == 0) {
      return iVar4;
    }
    _selwakeup(*(int *)(iVar2 + 0x2c),*(uint *)(iVar2 + 0x3e) & 0x1000);
    _thread_deallocate(*(undefined4 *)(iVar2 + 0x2c));
    *(undefined4 *)(iVar2 + 0x2c) = 0;
    *(word *)(iVar2 + 0x40) = *(word *)(iVar2 + 0x40) & 0xefff;
    return iVar4;
  }
  iVar4 = _uiomove(auStack_68,iVar3,0,param_2);
  iVar3 = *(int *)(param_2 + 0x12);
  if ((iVar3 < 1) || (iVar4 != 0)) goto loc_4010988;
  goto loc_401094C;
}
/* GHIDRADEC_FUNCTION index=349 start=0x40109f8 */

void _ptsstop(int param_1,uint param_2)

{
  uint *puVar1;
  uint uVar2;
  
  puVar1 = *(uint **)((int)&dword_40B318E + (sword)(*(word *)(param_1 + 0x38) & 0xff) * 0xe);
  if (*(word *)(param_1 + 0x38) != 0) {
    if (param_2 == 0) {
      param_2 = 4;
      *puVar1 = *puVar1 | 0x10;
    }
    else {
      *puVar1 = *puVar1 & 0xffffffef;
    }
    *(byte *)(puVar1 + 3) = (byte)param_2 | *(byte *)(puVar1 + 3);
    uVar2 = 0;
    if ((param_2 & 1) != 0) {
      uVar2 = 2;
    }
    if ((param_2 & 2) != 0) {
      uVar2 = uVar2 | 1;
    }
    _ptcwakeup(param_1,uVar2);
  }
  return;
}

