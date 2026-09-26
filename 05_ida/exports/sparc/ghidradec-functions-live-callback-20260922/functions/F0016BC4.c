
/* WARNING: Removing unreachable block (ram,0xf0017370) */
/* WARNING: Removing unreachable block (ram,0xf0017570) */
/* WARNING: Removing unreachable block (ram,0xf001723c) */
/* WARNING: Removing unreachable block (ram,0xf001768c) */
/* WARNING: Removing unreachable block (ram,0xf0017160) */
/* WARNING: Removing unreachable block (ram,0xf0017a1c) */
/* WARNING: Removing unreachable block (ram,0xf001797c) */
/* WARNING: Removing unreachable block (ram,0xf001792c) */
/* WARNING: Removing unreachable block (ram,0xf00178bc) */
/* WARNING: Removing unreachable block (ram,0xf00175c0) */
/* WARNING: Removing unreachable block (ram,0xf00177d8) */
/* WARNING: Removing unreachable block (ram,0xf0017500) */
/* WARNING: Removing unreachable block (ram,0xf0017454) */
/* WARNING: Removing unreachable block (ram,0xf0017428) */
/* WARNING: Removing unreachable block (ram,0xf00173e4) */
/* WARNING: Removing unreachable block (ram,0xf00172cc) */
/* WARNING: Removing unreachable block (ram,0xf001724c) */
/* WARNING: Removing unreachable block (ram,0xf001721c) */
/* WARNING: Removing unreachable block (ram,0xf0017a3c) */
/* WARNING: Removing unreachable block (ram,0xf001774c) */
/* WARNING: Removing unreachable block (ram,0xf0017874) */
/* WARNING: Removing unreachable block (ram,0xf0016d78) */
/* WARNING: Removing unreachable block (ram,0xf0016d6c) */
/* WARNING: Removing unreachable block (ram,0xf001720c) */
/* WARNING: Removing unreachable block (ram,0xf00175d4) */
/* WARNING: Removing unreachable block (ram,0xf00171f8) */
/* WARNING: Removing unreachable block (ram,0xf00171e4) */
/* WARNING: Removing unreachable block (ram,0xf0017270) */
/* WARNING: Removing unreachable block (ram,0xf0017258) */
/* WARNING: Removing unreachable block (ram,0xf0017310) */
/* WARNING: Removing unreachable block (ram,0xf001741c) */
/* WARNING: Removing unreachable block (ram,0xf00174b4) */
/* WARNING: Removing unreachable block (ram,0xf00174e0) */
/* WARNING: Removing unreachable block (ram,0xf00177a4) */
/* WARNING: Removing unreachable block (ram,0xf00175b8) */
/* WARNING: Removing unreachable block (ram,0xf0017884) */
/* WARNING: Removing unreachable block (ram,0xf00178dc) */
/* WARNING: Removing unreachable block (ram,0xf0017990) */
/* WARNING: Removing unreachable block (ram,0xf0017a10) */
/* WARNING: Removing unreachable block (ram,0xf0017a24) */
/* WARNING: Removing unreachable block (ram,0xf00171cc) */
/* WARNING: Removing unreachable block (ram,0xf0017698) */
/* WARNING: Removing unreachable block (ram,0xf0017658) */
/* WARNING: Removing unreachable block (ram,0xf0017534) */
/* WARNING: Removing unreachable block (ram,0xf0017a2c) */
/* WARNING: Removing unreachable block (ram,0xf0016bc8) */

undefined8 _ttioctl(undefined4 *param_1,uint param_2,uint *param_3,uint param_4)

{
  sword sVar1;
  sword sVar2;
  word wVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined *puVar6;
  uint uVar7;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  int iVar8;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar9;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 *puVar10;
  uint uVar11;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  puVar10 = param_1;
  _ttynty();
  iVar8 = (int)*(sword *)(param_1 + 0xe);
  if (param_2 == 0x80067411) {
loc_F0016D34:
    sVar1 = *(sword *)(param_1 + 0x11);
    uVar7 = *_active_u;
    sVar2 = *(sword *)(uVar7 + 0x2e);
    while (((((int)sVar2 != (int)sVar1 && (param_1 == (undefined4 *)_active_u[0x59])) &&
            ((*(uint *)(uVar7 + 0x28) & 0x1000) == 0)) &&
           (((*(uint *)(uVar7 + 0x20) & 0x200000) == 0 &&
            ((*(uint *)(uVar7 + 0x1c) & 0x200000) == 0))))) {
      _gsignal((int)sVar2,0x16);
      _sleep(_lbolt,0x1d);
      sVar1 = *(sword *)(param_1 + 0x11);
      uVar7 = *_active_u;
      sVar2 = *(sword *)(uVar7 + 0x2e);
    }
  }
  else {
    if ((int)param_2 < -0x7ff98bee) {
      if (param_2 != 0x80047476) {
        if (-0x7ffb8b8a < (int)param_2) {
          if (-0x7ffb8b84 < (int)param_2) {
            if ((int)param_2 < -0x7ffb8b80) goto loc_F0016D34;
            if ((int)param_2 < -0x7ff98bf5) {
              iVar9 = -0x7ff98bf7;
              goto loc_F0016D20;
            }
          }
          goto loc_F0016DC0;
        }
        if (param_2 != 0x80047401) {
          if ((int)param_2 < -0x7ffb8bfe) {
            uVar7 = 0x80017472;
          }
          else {
            uVar7 = 0x80047410;
          }
loc_F0016CB8:
          if (param_2 != uVar7) goto loc_F0016DC0;
        }
      }
      goto loc_F0016D34;
    }
    if (param_2 == 0x2000745e) goto loc_F0016D34;
    if ((int)param_2 < 0x2000745f) {
      if (param_2 == 0x80087467) goto loc_F0016D34;
      if ((int)param_2 < -0x7ff78b98) {
        uVar7 = 0x80067475;
        goto loc_F0016CB8;
      }
      if ((int)param_2 < -0x7fdb8be9) {
        iVar9 = -0x7fdb8bec;
        goto loc_F0016D20;
      }
    }
    else if (0x2000746d < (int)param_2) {
      if ((int)param_2 < 0x20007470) goto loc_F0016D34;
      if ((int)param_2 < 0x2000747c) {
        iVar9 = 0x2000747a;
loc_F0016D20:
        if (iVar9 <= (int)param_2) goto loc_F0016D34;
      }
    }
  }
loc_F0016DC0:
  if (param_2 == 0x20007402) {
    _spltty();
    uVar7 = param_1[0x10] | 0x200;
loc_F001721C:
    param_1[0x10] = uVar7;
    _splx();
    iVar9 = 0;
    goto locret_F0017A50;
  }
  if ((int)param_2 < 0x20007403) {
    if (param_2 == 0x8004747e) {
      param_1[0xf] = param_1[0xf] & ~(*param_3 << 0x10);
loc_F001763C:
      puVar10[4] = 0x1c251a1c;
      *(undefined *)(puVar10 + 5) = 0x5c;
      *(undefined *)((int)puVar10 + 0x15) = 1;
      *(undefined *)((int)puVar10 + 0x16) = 0;
      _ttysetspec();
      iVar9 = 0;
      goto locret_F0017A50;
    }
    if ((int)param_2 < -0x7ffb8b81) {
      if (param_2 == 0x80047401) {
        puVar10 = (undefined4 *)*param_3;
        if ((_nldisp <= puVar10) || (*(code **)(_linesw + (int)puVar10 * 0x30) == _nodev)) {
          iVar9 = 6;
          goto locret_F0017A50;
        }
        puVar5 = (undefined4 *)(int)*(char *)((int)param_1 + 0x47);
        if (puVar10 == puVar5) {
          iVar9 = 0;
          goto locret_F0017A50;
        }
        _spltty();
        (**(code **)(_linesw + *(char *)((int)param_1 + 0x47) * 0x30 + 4))(param_1);
        param_1[0x21] = 0;
        iVar9 = iVar8;
        (**(code **)(_linesw + (int)puVar10 * 0x30))(iVar8,param_1);
        if (iVar9 != 0) {
          param_1[0x21] = 0;
          (**(code **)(_linesw + *(char *)((int)param_1 + 0x47) * 0x30))(iVar8,param_1);
          _splx(puVar5);
          goto locret_F0017A50;
        }
        *(char *)((int)param_1 + 0x47) = (char)puVar10;
      }
      else {
        if (-0x7ffb8bff < (int)param_2) {
          if (param_2 == 0x80047476) {
            uVar7 = *_active_u;
            uVar11 = *param_3;
            if ((*(uint *)(uVar7 + 0x14) & 0x4000) == 0) {
              if (*(sword *)(_active_u[7] + 2) == 0) {
                *(sword *)(param_1 + 0x11) = (sword)uVar11;
                puVar10 = _cons_tp;
              }
              else {
                if ((param_4 & 1) == 0) {
                  iVar9 = 1;
                  goto locret_F0017A50;
                }
                *(sword *)(param_1 + 0x11) = (sword)uVar11;
                puVar10 = _cons_tp;
              }
            }
            else {
              param_2 = uVar11;
              _pgfind();
              iVar8 = (int)*(sword *)(uVar7 + 0x30);
              _get_posix_proc();
              if (((int)uVar11 < 1) || (param_2 == 0)) {
                iVar9 = 0x16;
                goto locret_F0017A50;
              }
              iVar8 = *(int *)(*(int *)(iVar8 + 0x10) + 8);
              if (iVar8 != puVar10[2]) {
                iVar9 = 0x19;
                goto locret_F0017A50;
              }
              if ((*(uint *)(uVar7 + 0x28) & 0x40000000) == 0) {
                iVar9 = 0x19;
                goto locret_F0017A50;
              }
              if (*(int *)(param_2 + 8) != iVar8) {
                iVar9 = 1;
                goto locret_F0017A50;
              }
              puVar10[3] = param_2;
              *(sword *)(param_1 + 0x11) = (sword)*(undefined4 *)(param_2 + 0xc);
              puVar10 = _cons_tp;
            }
            goto loc_F0017A4C;
          }
          if ((int)param_2 < -0x7ffb8b89) {
            if (param_2 == 0x80047410) {
              uVar7 = *param_3 & 3;
              if (*param_3 == 0) {
                uVar7 = 3;
              }
              _ttyflush(param_1,uVar7);
              iVar9 = 0;
            }
            else {
              iVar9 = -1;
            }
            goto locret_F0017A50;
          }
          if (param_2 != 0x8004747d) {
            iVar9 = -1;
            goto locret_F0017A50;
          }
          uVar7 = param_1[0xf];
          param_1[0xf] = uVar7 & 0xffff;
          param_1[0xf] = uVar7 & 0xffff | *param_3 << 0x10;
          goto loc_F001763C;
        }
        puVar5 = (undefined4 *)0x8004667d;
        if (param_2 == 0x8004667d) {
          _spltty();
          if (*param_3 == 0) {
            uVar7 = param_1[0x10] & 0xffffbfff;
          }
          else {
            uVar7 = param_1[0x10] | 0x4000;
          }
          param_1[0x10] = uVar7;
        }
        else if ((int)param_2 < -0x7ffb9982) {
          if (param_2 != 0x80017472) {
            iVar9 = -1;
            goto locret_F0017A50;
          }
          if ((*(sword *)(_active_u[7] + 2) != 0) && ((param_4 & 1) == 0)) {
            iVar9 = 1;
            goto locret_F0017A50;
          }
          puVar5 = (undefined4 *)0x0;
          if ((*(sword *)(_active_u[7] + 2) != 0) &&
             (puVar5 = (undefined4 *)_active_u[0x59], puVar5 != param_1)) {
            iVar9 = 0xd;
            goto locret_F0017A50;
          }
          _spltty();
          (**(code **)(_linesw + *(char *)((int)param_1 + 0x47) * 0x30 + 0x14))
                    (*(undefined *)param_3,param_1);
        }
        else {
          puVar5 = (undefined4 *)0x8004667e;
          if (param_2 != 0x8004667e) {
            iVar9 = -1;
            goto locret_F0017A50;
          }
          _spltty();
          if (*param_3 == 0) {
            uVar7 = param_1[0x10] & 0xffffdfff;
          }
          else {
            uVar7 = param_1[0x10] | 0x2000;
          }
          param_1[0x10] = uVar7;
        }
      }
    }
    else {
      if (param_2 == 0x80067411) {
        puVar6 = (undefined *)((int)param_1 + 0x4f);
loc_F00175B8:
        _bcopy(param_3,puVar6,6);
        _ttysetspec(puVar10);
        iVar9 = 0;
        goto locret_F0017A50;
      }
      if ((int)param_2 < -0x7ff98bee) {
        if (param_2 == 0x8004747f) {
          param_1[0xf] = param_1[0xf] | *param_3 << 0x10;
          goto loc_F001763C;
        }
        if (-0x7ff98bf6 < (int)param_2) {
          iVar9 = -1;
          goto locret_F0017A50;
        }
        if ((int)param_2 < -0x7ff98bf7) {
          iVar9 = -1;
          goto locret_F0017A50;
        }
        *(undefined *)((int)param_1 + 0x4d) = *(undefined *)((int)param_3 + 2);
        *(char *)((int)param_1 + 0x4e) = (char)*param_3;
        *(undefined *)((int)param_1 + 0x49) = *(undefined *)param_3;
        *(undefined *)((int)param_1 + 0x4a) = *(undefined *)((int)param_3 + 1);
        wVar3 = *(word *)(param_3 + 1);
        puVar5 = (undefined4 *)0xffff;
        uVar11 = param_1[0xf] & 0xffff0000 | (uint)wVar3;
        _spltty();
        uVar7 = param_1[0xf];
        if ((((uVar7 & 0x20) == 0) && (((int)(sword)wVar3 & 0x20U) == 0)) && (param_2 != 0x80067409)
           ) {
          uVar4 = (int)(sword)wVar3 & 2;
          if ((uVar7 & 2) != uVar4) {
            if (uVar4 == 0) {
              param_1[0xf] = uVar7 | 0x20000000;
              uVar11 = uVar11 | 0x20000000;
              _ttwakeup(param_1);
            }
            else {
              _catq(param_1,param_1 + 3);
              *(undefined4 *)((int)register0x00000038 + -0x18) = *param_1;
              *(undefined4 *)((int)register0x00000038 + -0x14) = param_1[1];
              *(undefined4 *)((int)register0x00000038 + -0x10) = param_1[2];
              *param_1 = param_1[3];
              param_1[1] = param_1[4];
              param_1[2] = param_1[5];
              param_1[3] = *(undefined4 *)((int)register0x00000038 + -0x18);
              param_1[4] = *(undefined4 *)((int)register0x00000038 + -0x14);
              param_1[5] = *(undefined4 *)((int)register0x00000038 + -0x10);
            }
          }
          param_1[0xf] = uVar11;
        }
        else {
          _ttywait(param_1);
          _ttyflush(param_1,1);
          param_1[0xf] = uVar11;
        }
        puVar10[4] = 0x1c251a1c;
        *(undefined *)(puVar10 + 5) = 0x5c;
        *(undefined *)((int)puVar10 + 0x15) = 1;
        *(undefined *)((int)puVar10 + 0x16) = 0;
        _ttysetspec(puVar10);
        if ((param_1[0xf] & 0x20) != 0) {
          param_1[0x10] = param_1[0x10] & 0xfffffeff;
          _ttstart();
        }
      }
      else {
        if (param_2 == 0x80087467) {
          puVar5 = param_1 + 0x17;
          _bcmp(puVar5,param_3,8);
          puVar10 = _cons_tp;
          if (puVar5 != (undefined4 *)0x0) {
            *(undefined2 *)(param_1 + 0x17) = *(undefined2 *)param_3;
            *(sword *)((int)param_1 + 0x5e) = (sword)*param_3;
            *(undefined2 *)(param_1 + 0x18) = *(undefined2 *)(param_3 + 1);
            *(undefined2 *)((int)param_1 + 0x62) = *(undefined2 *)((int)param_3 + 6);
            _gsignal((int)*(sword *)(param_1 + 0x11),0x1c);
            iVar9 = 0;
            goto locret_F0017A50;
          }
          goto loc_F0017A4C;
        }
        if ((int)param_2 < -0x7ff78b98) {
          if (param_2 != 0x80067475) {
            iVar9 = -1;
            goto locret_F0017A50;
          }
          puVar6 = (undefined *)((int)param_1 + 0x55);
          goto loc_F00175B8;
        }
        if (-0x7fdb8bea < (int)param_2) {
          iVar9 = -1;
          goto locret_F0017A50;
        }
        puVar5 = (undefined4 *)0x80247414;
        if ((int)param_2 < -0x7fdb8bec) {
          iVar9 = -1;
          goto locret_F0017A50;
        }
        _spltty();
        if (*(char *)((int)param_3 + 0x21) == '\0') {
          *(undefined *)((int)param_3 + 0x21) = *(undefined *)((int)param_3 + 0x22);
        }
        if (param_2 == 0x80247415 || param_2 == 0x80247416) {
          _ttywait(param_1);
          if (param_2 == 0x80247416) {
            _ttyflush(param_1,1);
            uVar7 = param_3[2];
          }
          else {
            uVar7 = param_3[2];
          }
        }
        else {
          uVar7 = param_3[2];
        }
        if ((uVar7 & 1) == 0) {
          if ((param_1[0x10] & 0x10) == 0) {
            if ((puVar10[4] & 0x8000) != 0) {
              if ((uVar7 & 0x8000) != 0) {
                uVar7 = param_1[0xf];
                goto loc_F0017938;
              }
              param_1[0x10] = param_1[0x10] & 0xfffffffb | 2;
              _ttwakeup(param_1);
            }
            uVar7 = param_1[0xf];
          }
          else {
            uVar7 = param_1[0xf];
          }
        }
        else {
          uVar7 = param_1[0xf];
        }
loc_F0017938:
        uVar11 = param_3[3] >> 5 & 1;
        if ((param_2 != 0x80247416) && (uVar11 != ((uVar7 & 0x22) == 0))) {
          if (uVar11 == 0) {
            _catq(param_1,param_1 + 3);
            *(undefined4 *)((int)register0x00000038 + -0x18) = *param_1;
            *(undefined4 *)((int)register0x00000038 + -0x14) = param_1[1];
            *(undefined4 *)((int)register0x00000038 + -0x10) = param_1[2];
            *param_1 = param_1[3];
            param_1[1] = param_1[4];
            param_1[2] = param_1[5];
            param_1[3] = *(undefined4 *)((int)register0x00000038 + -0x18);
            param_1[4] = *(undefined4 *)((int)register0x00000038 + -0x14);
            param_1[5] = *(undefined4 *)((int)register0x00000038 + -0x10);
          }
          else {
            param_1[0xf] = uVar7 | 0x20000000;
            _ttwakeup(param_1);
          }
        }
        if ((uVar11 == 0) && ((puVar10[5] & 0xffff00) != (param_3[6] & 0xffff00))) {
          _ttwakeup(param_1);
        }
        _ttsettermios(puVar10,param_3);
        _ttysetspec(puVar10);
      }
    }
loc_F0017A2C:
    _splx(puVar5);
    iVar9 = 0;
    goto locret_F0017A50;
  }
  if (param_2 == 0x40047460) {
    *param_3 = param_1[0x10];
    puVar10 = _cons_tp;
  }
  else if ((int)param_2 < 0x40047461) {
    if (param_2 != 0x20007468) {
      if ((int)param_2 < 0x20007469) {
        if (param_2 == 0x2000740e) {
          _spltty();
          uVar7 = param_1[0x10] & 0xffffff7f;
        }
        else {
          if (0x2000740e < (int)param_2) {
            if (param_2 == 0x2000745e) {
              _ttywait(param_1);
              iVar9 = 0;
            }
            else {
              iVar9 = -1;
            }
            goto locret_F0017A50;
          }
          if (param_2 != 0x2000740d) {
            iVar9 = -1;
            goto locret_F0017A50;
          }
          _spltty();
          uVar7 = param_1[0x10] | 0x80;
        }
        goto loc_F001721C;
      }
      puVar5 = (undefined4 *)0x2000746f;
      if (param_2 == 0x2000746f) {
        _spltty();
        if ((param_1[0x10] & 0x100) == 0) {
          param_1[0x10] = param_1[0x10] | 0x100;
          (**(code **)(DAT_f011ca00 + (uint)(*(word *)(param_1 + 0xe) >> 8) * 0x2c + 4))(param_1,0);
        }
      }
      else if ((int)param_2 < 0x20007470) {
        puVar5 = (undefined4 *)0x2000746e;
        if (param_2 != 0x2000746e) {
          iVar9 = -1;
          goto locret_F0017A50;
        }
        _spltty();
        if (((param_1[0x10] & 0x100) != 0) || ((param_1[0xf] & 0x800000) != 0)) {
          param_1[0x10] = param_1[0x10] & 0xfffffeff;
          param_1[0xf] = param_1[0xf] & 0xff7fffff;
          _ttstart();
        }
      }
      else {
        puVar5 = (undefined4 *)0x40047400;
        if (param_2 != 0x4004667f) {
          if (param_2 != 0x40047400) {
            iVar9 = -1;
            goto locret_F0017A50;
          }
          *param_3 = (int)*(char *)((int)param_1 + 0x47);
          puVar10 = _cons_tp;
          goto loc_F0017A4C;
        }
        _spltty();
        _ttnread();
        *param_3 = (uint)puVar10;
      }
      goto loc_F0017A2C;
    }
    puVar10 = param_1;
    if (param_1 != (undefined4 *)_cons) {
      (**(code **)(DAT_f011ca00 + (uint)(*(word *)(_cons_tp + 0xe) >> 8) * 0x2c))
                ((int)(sword)*(word *)(_cons_tp + 0xe),0x20006b08,0,0);
      puVar10 = param_1;
    }
  }
  else if (param_2 == 0x40067408) {
    *(undefined *)param_3 = *(undefined *)((int)param_1 + 0x49);
    *(undefined *)((int)param_3 + 1) = *(undefined *)((int)param_1 + 0x4a);
    *(undefined *)((int)param_3 + 2) = *(undefined *)((int)param_1 + 0x4d);
    *(undefined *)((int)param_3 + 3) = *(undefined *)((int)param_1 + 0x4e);
    *(sword *)(param_3 + 1) = (sword)param_1[0xf];
    puVar10 = _cons_tp;
  }
  else {
    if (0x40067408 < (int)param_2) {
      if (param_2 == 0x40067474) {
        puVar6 = (undefined *)((int)param_1 + 0x55);
      }
      else {
        if (0x40067474 < (int)param_2) {
          if (param_2 != 0x40087468) {
            if (param_2 == 0x40247413) {
              _ttgettermios(puVar10,param_3);
              iVar9 = 0;
            }
            else {
              iVar9 = -1;
            }
            goto locret_F0017A50;
          }
          *(undefined2 *)param_3 = *(undefined2 *)(param_1 + 0x17);
          *(undefined2 *)((int)param_3 + 2) = *(undefined2 *)((int)param_1 + 0x5e);
          *(undefined2 *)(param_3 + 1) = *(undefined2 *)(param_1 + 0x18);
          *(undefined2 *)((int)param_3 + 6) = *(undefined2 *)((int)param_1 + 0x62);
          puVar10 = _cons_tp;
          goto loc_F0017A4C;
        }
        puVar6 = (undefined *)((int)param_1 + 0x4f);
        if (param_2 != 0x40067412) {
          iVar9 = -1;
          goto locret_F0017A50;
        }
      }
      _bcopy(puVar6,param_3,6);
      iVar9 = 0;
      goto locret_F0017A50;
    }
    if (param_2 == 0x40047477) {
      param_2 = *_active_u;
      if ((*(uint *)(param_2 + 0x14) & 0x4000) == 0) {
        sVar1 = *(sword *)(param_1 + 0x11);
      }
      else {
        iVar8 = (int)*(sword *)(param_2 + 0x30);
        _get_posix_proc();
        iVar8 = *(int *)(*(int *)(iVar8 + 0x10) + 8);
        if (iVar8 != puVar10[2]) {
          iVar9 = 0x19;
          goto locret_F0017A50;
        }
        if ((*(uint *)(param_2 + 0x28) & 0x40000000) == 0) {
          iVar9 = 0x19;
          goto locret_F0017A50;
        }
        if (*(int *)(iVar8 + 8) == 0) {
          iVar9 = 0x19;
          goto locret_F0017A50;
        }
        sVar1 = *(sword *)(param_1 + 0x11);
      }
      *param_3 = (int)sVar1;
      puVar10 = _cons_tp;
    }
    else if ((int)param_2 < 0x40047478) {
      if (param_2 != 0x40047473) {
        iVar9 = -1;
        goto locret_F0017A50;
      }
      *param_3 = param_1[6];
      puVar10 = _cons_tp;
    }
    else {
      if (param_2 != 0x4004747c) {
        iVar9 = -1;
        goto locret_F0017A50;
      }
      *param_3 = (uint)*(word *)(param_1 + 0xf);
      puVar10 = _cons_tp;
    }
  }
loc_F0017A4C:
  _cons_tp = puVar10;
  iVar9 = 0;
locret_F0017A50:
  return CONCAT44(param_2,iVar9);
}

