
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
