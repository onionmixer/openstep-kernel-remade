
void _kmpaint(byte param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  word wVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  sword sVar10;
  uint uVar9;
  uint uVar11;
  int iVar12;
  sword *psVar13;
  undefined2 *puVar14;
  uint *puVar15;
  uint *puVar16;
  undefined4 *puVar17;
  undefined4 *puVar18;
  undefined4 *puVar19;
  undefined4 *puVar20;
  int iStack_8;
  
  if ((unk_40B6904 & 8) == 0) {
    _putchar(param_1);
    return;
  }
  if ((word_40B68F8 == 1) && (param_1 == 0x5b)) {
    word_40B68F8 = 2;
    return;
  }
  _km_begin_access();
  if (word_40B68F8 == 2) {
    if ((byte)(param_1 - 0x30) < 10) {
      *dword_40B68FA = *dword_40B68FA * 10 + (param_1 - 0x30);
      goto loc_4071476;
    }
    if (param_1 == 0x3b) {
      if (dword_40B68FA < &unk_40B6904) {
        dword_40B68FA = dword_40B68FA + 1;
      }
      goto loc_4071476;
    }
    psVar13 = (sword *)&unk_40B68FE;
    do {
      if (*psVar13 == 0) {
        *psVar13 = 1;
      }
      psVar13 = psVar13 + 1;
    } while ((int)psVar13 < 0x40b6903);
    iVar6 = (int)*dword_40B68FA;
    _km_flip_cursor();
    switch(param_1) {
    case :
      iVar6 = iVar6 + -1;
      if (iVar6 != -1) {
        do {
          do {
            word_40B68DA = word_40B68DA + -1;
            wVar5 = (word)((uint)iVar6 >> 0x10);
            sVar10 = (sword)iVar6 + -1;
            iVar6 = CONCAT22(wVar5,sVar10);
          } while (sVar10 != -1);
          iVar6 = (uint)wVar5 * 0x10000 + -1;
        } while (wVar5 != 0);
      }
      break;
    case :
      iVar6 = iVar6 + -1;
      if (iVar6 != -1) {
        do {
          do {
            word_40B68DA = word_40B68DA + 1;
            wVar5 = (word)((uint)iVar6 >> 0x10);
            sVar10 = (sword)iVar6 + -1;
            iVar6 = CONCAT22(wVar5,sVar10);
          } while (sVar10 != -1);
          iVar6 = (uint)wVar5 * 0x10000 + -1;
        } while (wVar5 != 0);
      }
      break;
    case :
      iVar6 = iVar6 + -1;
      if (iVar6 != -1) {
        do {
          do {
            word_40B68D8 = word_40B68D8 + 1;
            wVar5 = (word)((uint)iVar6 >> 0x10);
            sVar10 = (sword)iVar6 + -1;
            iVar6 = CONCAT22(wVar5,sVar10);
          } while (sVar10 != -1);
          iVar6 = (uint)wVar5 * 0x10000 + -1;
        } while (wVar5 != 0);
      }
      break;
    case :
      iVar6 = iVar6 + -1;
      if (iVar6 != -1) {
        do {
          do {
            word_40B68D8 = word_40B68D8 + -1;
            wVar5 = (word)((uint)iVar6 >> 0x10);
            sVar10 = (sword)iVar6 + -1;
            iVar6 = CONCAT22(wVar5,sVar10);
          } while (sVar10 != -1);
          iVar6 = (uint)wVar5 * 0x10000 + -1;
        } while (wVar5 != 0);
      }
      break;
    case :
      iVar6 = iVar6 + -1;
      if (iVar6 != -1) {
        do {
          do {
            word_40B68D8 = 0;
            word_40B68DA = word_40B68DA + 1;
            wVar5 = (word)((uint)iVar6 >> 0x10);
            sVar10 = (sword)iVar6 + -1;
            iVar6 = CONCAT22(wVar5,sVar10);
          } while (sVar10 != -1);
          iVar6 = (uint)wVar5 * 0x10000 + -1;
        } while (wVar5 != 0);
      }
      break;
    case :
    case :
      word_40B68D8 = *dword_40B68FA + -1;
      word_40B68DA = dword_40B68FA[-1] + -1;
      break;
    case :
      _km_clear_eol(0);
      break;
    case :
      dword_40B68F4 = (&_km_color)[(int)*dword_40B68FA - 1U & 3];
      dword_40B68F0 = (&_km_color)[(int)dword_40B68FA[-1] - 1U & 3];
      if (dword_40B68F4 == dword_40B68F0) {
        dword_40B68F4 = 0xffffffff;
      }
    }
    dword_40B68FA = (sword *)((int)&unk_40B68FE + 2);
    iVar6 = 2;
    puVar14 = &unk_40B6902;
    do {
      do {
        *puVar14 = 0;
        puVar14 = puVar14 + -1;
        wVar5 = (word)((uint)iVar6 >> 0x10);
        sVar10 = (sword)iVar6 + -1;
        iVar6 = CONCAT22(wVar5,sVar10);
      } while (sVar10 != -1);
      iVar6 = (uint)wVar5 * 0x10000 + -1;
    } while (wVar5 != 0);
    word_40B68F8 = 0;
  }
  else {
    _km_flip_cursor();
    switch(param_1) {
    case :
      break;
    case :
      if (word_40B68D8 != 0) {
        word_40B68D8 = word_40B68D8 + -1;
      }
      break;
    case :
      iVar2 = (int)word_40B68D8;
      for (iVar6 = 0; iVar6 < 8 - iVar2 % 8; iVar6 = iVar6 + 1) {
        _km_flip_cursor();
        _kmpaint(0x20);
      }
      _km_flip_cursor();
      break;
    case :
      word_40B68DA = word_40B68DA + 1;
      break;
    :
      if (0x1f < (param_1 & 0x7f)) {
        if ((unk_40B6904 & 0x200) == 0) {
          unk_40B6904 = unk_40B6904 | 0x200;
        }
        if (word_40B68D8 < 0) {
          iStack_8 = dword_40B6980 + (uint)(word_40B68D8 * -4) / _km_coni;
        }
        else {
          iStack_8 = dword_40B6940 * 0xc * (int)word_40B68DC +
                     dword_40B6980 +
                     (uint)(((int)word_40B68DE + (int)word_40B68D8) * 0x20) / _km_coni;
        }
        iVar6 = 0;
        do {
          if (word_40B68DA < 0) {
            if (word_40B68D8 < 0) {
              iVar2 = -(int)word_40B68DA;
            }
            else {
              iVar2 = (int)word_40B68DA;
            }
          }
          else {
            iVar2 = word_40B68DA * 0xc;
          }
          puVar15 = (uint *)(dword_40B6940 * (iVar6 + iVar2) + iStack_8);
          uVar9 = (uint)(char)_ohlfs12[iVar6 + (uint)(byte)((param_1 & 0x7f) - 0x20) * 0xc];
          uVar11 = 0;
          if (_km_coni == 2) {
            uVar11 = 7;
            do {
              puVar16 = (uint *)((int)puVar15 + 2);
              if ((uVar9 & 1 << (uVar11 & 0x1f)) == 0) {
                *(undefined2 *)puVar15 = dword_40B68F4._2_2_;
              }
              else {
                *(undefined2 *)puVar15 = dword_40B68F0._2_2_;
              }
              wVar5 = (word)(uVar11 >> 0x10);
              sVar10 = (sword)uVar11 + -1;
              uVar11 = CONCAT22(wVar5,sVar10);
              puVar15 = puVar16;
            } while ((sVar10 != -1) || (uVar11 = (uint)wVar5 * 0x10000 - 1, wVar5 != 0));
          }
          else if ((int)_km_coni < 3) {
            if (_km_coni == 1) {
              uVar11 = 7;
              do {
                puVar16 = puVar15 + 1;
                if ((uVar9 & 1 << (uVar11 & 0x1f)) == 0) {
                  *puVar15 = dword_40B68F4;
                }
                else {
                  *puVar15 = dword_40B68F0;
                }
                wVar5 = (word)(uVar11 >> 0x10);
                sVar10 = (sword)uVar11 + -1;
                uVar11 = CONCAT22(wVar5,sVar10);
                puVar15 = puVar16;
              } while ((sVar10 != -1) || (uVar11 = (uint)wVar5 * 0x10000 - 1, wVar5 != 0));
            }
          }
          else if (_km_coni == 4) {
            uVar11 = 7;
            do {
              puVar16 = (uint *)((int)puVar15 + 1);
              if ((uVar9 & 1 << (uVar11 & 0x1f)) == 0) {
                *(undefined *)puVar15 = (undefined)dword_40B68F4;
              }
              else {
                *(undefined *)puVar15 = (undefined)dword_40B68F0;
              }
              wVar5 = (word)(uVar11 >> 0x10);
              sVar10 = (sword)uVar11 + -1;
              uVar11 = CONCAT22(wVar5,sVar10);
              puVar15 = puVar16;
            } while ((sVar10 != -1) || (uVar11 = (uint)wVar5 * 0x10000 - 1, wVar5 != 0));
          }
          else if (_km_coni == 0x10) {
            uVar7 = 0;
            do {
              uVar1 = dword_40B68F4;
              if ((uVar9 & 1 << (uVar7 & 0x1f)) != 0) {
                uVar1 = dword_40B68F0;
              }
              uVar11 = (uVar1 & 3) << (uVar7 * 2 & 0x3f) | uVar11;
              uVar7 = uVar7 + 1;
            } while ((int)uVar7 < 8);
            *(sword *)puVar15 = (sword)uVar11;
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < 0xc);
        if (word_40B68D8 < 0) {
          word_40B68D8 = word_40B68D8 + -8;
        }
        else {
          word_40B68D8 = word_40B68D8 + 1;
        }
      }
      break;
    case :
      word_40B68DA = 0;
      word_40B68D8 = 0;
      _km_clear_win();
      break;
    case :
      if ((unk_40B6904 & 0x200) == 0) {
        unk_40B6904 = unk_40B6904 | 0x200;
        _km_flip_cursor();
      }
      word_40B68D8 = 0;
      break;
    case :
      word_40B68F8 = 1;
    }
  }
  if (word_40B68E0 <= word_40B68D8) {
    word_40B68D8 = 0;
    word_40B68DA = word_40B68DA + 1;
  }
  if (word_40B68E4 <= word_40B68DA) {
    if ((int)_km_coni < 3) {
      _adb_watchdog(0);
    }
    iVar2 = dword_40B6940;
    word_40B68DA = word_40B68E4 + -1;
    iVar6 = dword_40B6980 + (uint)((int)word_40B68DE << 5) / _km_coni;
    uVar11 = ((int)word_40B68E0 << 3) / (int)_km_coni;
    iVar12 = word_40B68DC * 0xc;
    if (iVar12 < (word_40B68E4 + -1 + (int)word_40B68DC) * 0xc) {
      iVar8 = dword_40B6940 * iVar12;
      do {
        puVar19 = (undefined4 *)(iVar8 + iVar6);
        puVar17 = puVar19 + iVar2 * 3;
        iVar3 = (int)uVar11 >> 5;
        iVar4 = iVar3;
        puVar18 = puVar17;
        puVar20 = puVar19;
        switch(uVar11 & 0x1f) {
        case :
          while (iVar3 = iVar4 + -1, 0 < iVar4) {
            puVar17 = puVar18 + 1;
            puVar19 = puVar20 + 1;
            *puVar20 = *puVar18;
loc_40713e6:
            puVar18 = puVar17 + 1;
            puVar20 = puVar19 + 1;
            *puVar19 = *puVar17;
loc_40713e8:
            puVar17 = puVar18 + 1;
            puVar19 = puVar20 + 1;
            *puVar20 = *puVar18;
loc_40713ea:
            puVar18 = puVar17 + 1;
            puVar20 = puVar19 + 1;
            *puVar19 = *puVar17;
loc_40713ec:
            puVar17 = puVar18 + 1;
            puVar19 = puVar20 + 1;
            *puVar20 = *puVar18;
loc_40713ee:
            puVar18 = puVar17 + 1;
            puVar20 = puVar19 + 1;
            *puVar19 = *puVar17;
loc_40713f0:
            puVar17 = puVar18 + 1;
            puVar19 = puVar20 + 1;
            *puVar20 = *puVar18;
loc_40713f2:
            puVar18 = puVar17 + 1;
            puVar20 = puVar19 + 1;
            *puVar19 = *puVar17;
loc_40713f4:
            puVar17 = puVar18 + 1;
            puVar19 = puVar20 + 1;
            *puVar20 = *puVar18;
loc_40713f6:
            puVar18 = puVar17 + 1;
            puVar20 = puVar19 + 1;
            *puVar19 = *puVar17;
loc_40713f8:
            puVar17 = puVar18 + 1;
            puVar19 = puVar20 + 1;
            *puVar20 = *puVar18;
loc_40713fa:
            puVar18 = puVar17 + 1;
            puVar20 = puVar19 + 1;
            *puVar19 = *puVar17;
loc_40713fc:
            puVar17 = puVar18 + 1;
            puVar19 = puVar20 + 1;
            *puVar20 = *puVar18;
loc_40713fe:
            puVar18 = puVar17 + 1;
            puVar20 = puVar19 + 1;
            *puVar19 = *puVar17;
loc_4071400:
            puVar17 = puVar18 + 1;
            puVar19 = puVar20 + 1;
            *puVar20 = *puVar18;
loc_4071402:
            puVar18 = puVar17 + 1;
            puVar20 = puVar19 + 1;
            *puVar19 = *puVar17;
loc_4071404:
            puVar17 = puVar18 + 1;
            puVar19 = puVar20 + 1;
            *puVar20 = *puVar18;
loc_4071406:
            puVar18 = puVar17 + 1;
            puVar20 = puVar19 + 1;
            *puVar19 = *puVar17;
loc_4071408:
            puVar17 = puVar18 + 1;
            puVar19 = puVar20 + 1;
            *puVar20 = *puVar18;
loc_407140a:
            puVar18 = puVar17 + 1;
            puVar20 = puVar19 + 1;
            *puVar19 = *puVar17;
loc_407140c:
            puVar17 = puVar18 + 1;
            puVar19 = puVar20 + 1;
            *puVar20 = *puVar18;
loc_407140e:
            puVar18 = puVar17 + 1;
            puVar20 = puVar19 + 1;
            *puVar19 = *puVar17;
loc_4071410:
            puVar17 = puVar18 + 1;
            puVar19 = puVar20 + 1;
            *puVar20 = *puVar18;
loc_4071412:
            puVar18 = puVar17 + 1;
            puVar20 = puVar19 + 1;
            *puVar19 = *puVar17;
loc_4071414:
            puVar17 = puVar18 + 1;
            puVar19 = puVar20 + 1;
            *puVar20 = *puVar18;
loc_4071416:
            puVar18 = puVar17 + 1;
            puVar20 = puVar19 + 1;
            *puVar19 = *puVar17;
loc_4071418:
            puVar17 = puVar18 + 1;
            puVar19 = puVar20 + 1;
            *puVar20 = *puVar18;
loc_407141a:
            puVar18 = puVar17 + 1;
            puVar20 = puVar19 + 1;
            *puVar19 = *puVar17;
loc_407141c:
            puVar17 = puVar18 + 1;
            puVar19 = puVar20 + 1;
            *puVar20 = *puVar18;
loc_407141e:
            puVar18 = puVar17 + 1;
            puVar20 = puVar19 + 1;
            *puVar19 = *puVar17;
loc_4071420:
            puVar17 = puVar18 + 1;
            puVar19 = puVar20 + 1;
            *puVar20 = *puVar18;
loc_4071422:
            puVar18 = puVar17 + 1;
            puVar20 = puVar19 + 1;
            *puVar19 = *puVar17;
            iVar4 = iVar3;
          }
          break;
        case :
          goto loc_4071422;
        case :
          goto loc_4071420;
        case :
          goto loc_407141e;
        case :
          goto loc_407141c;
        case :
          goto loc_407141a;
        case :
          goto loc_4071418;
        case :
          goto loc_4071416;
        case :
          goto loc_4071414;
        case :
          goto loc_4071412;
        case :
          goto loc_4071410;
        case :
          goto loc_407140e;
        case :
          goto loc_407140c;
        case :
          goto loc_407140a;
        case :
          goto loc_4071408;
        case :
          goto loc_4071406;
        case :
          goto loc_4071404;
        case :
          goto loc_4071402;
        case :
          goto loc_4071400;
        case :
          goto loc_40713fe;
        case :
          goto loc_40713fc;
        case :
          goto loc_40713fa;
        case :
          goto loc_40713f8;
        case :
          goto loc_40713f6;
        case :
          goto loc_40713f4;
        case :
          goto loc_40713f2;
        case :
          goto loc_40713f0;
        case :
          goto loc_40713ee;
        case :
          goto loc_40713ec;
        case :
          goto loc_40713ea;
        case :
          goto loc_40713e8;
        case :
          goto loc_40713e6;
        }
        iVar8 = iVar2 + iVar8;
        iVar12 = iVar12 + 1;
      } while (iVar12 < (word_40B68E4 + -1 + (int)word_40B68DC) * 0xc);
    }
    _km_clear_eol(1);
    if ((int)_km_coni < 3) {
      _adb_watchdog(1);
    }
  }
  _km_flip_cursor();
loc_4071476:
  _km_end_access();
  return;
}
