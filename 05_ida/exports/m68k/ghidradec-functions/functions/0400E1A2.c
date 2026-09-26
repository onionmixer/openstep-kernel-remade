
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
