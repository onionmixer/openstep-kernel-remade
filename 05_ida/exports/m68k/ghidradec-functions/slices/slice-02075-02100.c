/* GHIDRADEC_FUNCTION index=2075 start=0x40702aa */

void _km_input(undefined4 param_1)

{
  (**(code **)(DAT_40ae4c0 + byte_40B6841 * 0x30))(param_1,_cons);
  return;
}
/* GHIDRADEC_FUNCTION index=2076 start=0x40702da */

void _km_autorepeat(void)

{
  int iVar1;
  
  if ((unk_40B6904 & 2) != 0) {
    iVar1 = _kybd_process(&dword_40B68D4);
    if (((bRam040b683d & 4) != 0) && (iVar1 < 0x100)) {
      _callout_dispatch(0,_km_input,iVar1);
    }
    _timeout(_km_autorepeat,0,_hz / 0x14);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2077 start=0x4070358 */

void _reconpoll(void)

{
  if (_sound_active == 0) {
    _mon_send(0xc6,0x1fffff1);
  }
  _timeout(_reconpoll,0,_hz * 3);
  return;
}
/* GHIDRADEC_FUNCTION index=2078 start=0x4070392 */

void _kmintr_process(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  
  if ((unk_40B6904 & 2) != 0) {
    unk_40B6904 = unk_40B6904 & 0xfffd;
    _untimeout(_km_autorepeat,0);
  }
  iVar1 = _kybd_process(param_1);
  if (iVar1 != 0x100) {
    if (-1 < *(char *)((int)param_1 + 3)) {
      if ((unk_40B6904 & 0x100) != 0) {
        _alert_key = iVar1;
        return;
      }
      dword_40B68D4 = *param_1;
      unk_40B6904 = unk_40B6904 | 2;
      iVar2 = _hz;
      if (_hz < 0) {
        iVar2 = _hz + 1;
      }
      _timeout(_km_autorepeat,0,iVar2 >> 1);
    }
    if (((bRam040b683d & 4) != 0) && (iVar1 < 0x100)) {
      _callout_dispatch(0,_km_input,iVar1);
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2079 start=0x4070448 */

void _kmputc(undefined4 param_1,int param_2)

{
  if ((unk_40B6904 & 8) != 0) {
    if ((unk_40B6904 & 1) == 0) {
      _kminit();
    }
    if (param_2 == 10) {
      _kmpaint(0xd);
    }
    _kmpaint(param_2);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2080 start=0x4070490 */

int _kmgetc(void)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  
  iVar1 = _slot_id;
  puVar3 = (uint *)(_slot_id + 0x200e000);
loc_40704B4:
  do {
    iVar2 = _adb_check_keyboard(&_km);
    if (iVar2 == 0) {
      if ((*puVar3 & 0x400000) == 0) goto loc_40704B4;
      _km = *(undefined4 *)(iVar1 + 0x200e008);
    }
    iVar2 = _kybd_process(&_km);
    if (iVar2 < 0x100) {
      if (iVar2 == 0xd) {
        iVar2 = 10;
      }
      _cnputc(iVar2);
      return iVar2;
    }
  } while( true );
}
/* GHIDRADEC_FUNCTION index=2081 start=0x407050a */

int _kmgetc_silent(void)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  
  iVar1 = _slot_id;
  puVar3 = (uint *)(_slot_id + 0x200e000);
loc_407052E:
  do {
    iVar2 = _adb_check_keyboard(&_km);
    if (iVar2 == 0) {
      if ((*puVar3 & 0x400000) == 0) goto loc_407052E;
      _km = *(undefined4 *)(iVar1 + 0x200e008);
    }
    iVar2 = _kybd_process(&_km);
    if (iVar2 < 0x100) {
      if (iVar2 == 0xd) {
        iVar2 = 10;
      }
      return iVar2;
    }
  } while( true );
}
/* GHIDRADEC_FUNCTION index=2082 start=0x407057c */

int _kmtrygetc(void)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  
  iVar2 = _slot_id;
  puVar3 = (uint *)(_slot_id + 0x200e000);
  iVar1 = _adb_check_keyboard(&_km);
  if (iVar1 == 0) {
    if ((*puVar3 & 0x400000) == 0) {
      return -1;
    }
    _km = *(undefined4 *)(iVar2 + 0x200e008);
  }
  iVar1 = _kybd_process(&_km);
  iVar2 = -1;
  if (iVar1 < 0x100) {
    iVar2 = iVar1;
  }
  return iVar2;
}
/* GHIDRADEC_FUNCTION index=2083 start=0x4070664 */

word _kybd_process(uint *param_1)

{
  byte bVar1;
  int iVar2;
  word wVar3;
  int iVar4;
  word wVar5;
  
  bVar1 = *(byte *)((int)param_1 + 2);
  if (((char)bVar1 < '\0') && ((*param_1 & 0xfffffff) >> 0x18 == 0)) {
    iVar2 = -((int)((uint)(byte)*param_1 << 0x18) >> 0x1f);
    iVar4 = 0;
    if ((bVar1 & 1) != 0) {
      iVar4 = 0xa2;
    }
    wVar5 = *(word *)(_ascii + (iVar4 + (-(int)-((bVar1 & 6) != 0) | ((byte)*param_1 & 0x7f) * 2)) *
                               2);
    wVar3 = 0;
    if ((bVar1 & 0x60) != 0) {
      wVar3 = 0x80;
    }
    switch(wVar5) {
    case :
    case :
    case :
    case :
      sub_40705D8(*param_1,iVar2);
      break;
    :
      wVar5 = wVar3 | wVar5;
      break;
    case :
    case :
      break;
    }
    wVar3 = 0x100;
    if (iVar2 == 0) {
      wVar3 = wVar5;
    }
  }
  else {
    wVar3 = 0x100;
  }
  return wVar3;
}
/* GHIDRADEC_FUNCTION index=2084 start=0x407072c */

undefined4 _km_send(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = _slot_id;
  iVar3 = 100000;
  _mon_send(param_1,param_2);
  do {
    if ((*(byte *)(iVar1 + 0x200e001) & 0x40) != 0) break;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  uVar2 = 0x40000000;
  if (iVar3 != 0) {
    uVar2 = 0;
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=2085 start=0x407077c */

void _km_reset(void)

{
  *(byte *)(_slot_id + 0x200e002) = *(byte *)(_slot_id + 0x200e002) | 1;
  _mon_send(0xc6,0x1000a825);
  _mon_send(0,0);
  _delay(10000);
  return;
}
/* GHIDRADEC_FUNCTION index=2086 start=0x40707ca */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _km_drawrect(word *param_1)

{
  word wVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  uint uVar5;
  byte bVar6;
  undefined *puVar7;
  undefined2 *puVar8;
  undefined4 *puVar9;
  int iVar10;
  byte *pbVar11;
  undefined *puVar12;
  undefined2 *puVar13;
  undefined4 *puVar14;
  byte *pbVar15;
  byte *pbVar16;
  byte *pbVar17;
  
  iVar10 = dword_40B6944 + -0x460;
  if (iVar10 < 0) {
    iVar10 = dword_40B6944 + -0x45f;
  }
  *param_1 = (sword)(iVar10 >> 1) + *param_1;
  iVar10 = _unk_40B694C + -0x340;
  if (iVar10 < 0) {
    iVar10 = _unk_40B694C + -0x33f;
  }
  param_1[1] = (sword)(iVar10 >> 1) + param_1[1];
  *param_1 = *param_1 & 0xfffc;
  wVar1 = param_1[2] + 3;
  param_1[2] = wVar1 & 0xfffc;
  if ((int)((uint)*param_1 + (wVar1 & 0xfffc)) <= dword_40B6944) {
    if ((int)((uint)param_1[1] + (uint)param_1[3]) <= _unk_40B694C) {
      iVar10 = dword_40B6948 * (uint)param_1[1] + (uint)*param_1;
      iVar2 = (uint)(wVar1 >> 2) * (uint)param_1[3];
      if (iVar2 != 0) {
        pbVar3 = (byte *)_kalloc(iVar2);
        iVar4 = _copyinmsg(*(undefined4 *)(param_1 + 4),pbVar3,iVar2);
        if (iVar4 == 0) {
          if (_km_coni == 2) {
            puVar8 = (undefined2 *)(iVar10 * 2 + dword_40B6980);
            iVar10 = 0;
            pbVar16 = pbVar3;
            if (param_1[3] != 0) {
              do {
                iVar4 = 0;
                puVar13 = puVar8;
                pbVar17 = pbVar16;
                if (param_1[2] != 0) {
                  do {
                    pbVar16 = pbVar17 + 1;
                    bVar6 = *pbVar17;
                    *puVar13 = *(undefined2 *)((int)&dword_40B6954 + (uint)(bVar6 >> 6) * 4 + 2);
                    puVar13[1] = *(undefined2 *)
                                  ((int)&dword_40B6954 + ((bVar6 & 0x3f) >> 4) * 4 + 2);
                    puVar13[2] = *(undefined2 *)((int)&dword_40B6954 + (bVar6 & 0xc) + 2);
                    puVar13[3] = *(undefined2 *)((int)&dword_40B6954 + (bVar6 & 3) * 4 + 2);
                    iVar4 = iVar4 + 4;
                    puVar13 = puVar13 + 4;
                    pbVar17 = pbVar16;
                  } while (iVar4 < (int)(uint)param_1[2]);
                }
                puVar8 = (undefined2 *)(dword_40B6940 + (int)puVar8);
                iVar10 = iVar10 + 1;
              } while (iVar10 < (int)(uint)param_1[3]);
            }
          }
          else if (_km_coni < 3) {
            if (_km_coni == 1) {
              puVar9 = (undefined4 *)(iVar10 * 4 + dword_40B6980);
              iVar10 = 0;
              pbVar16 = pbVar3;
              if (param_1[3] != 0) {
                do {
                  iVar4 = 0;
                  puVar14 = puVar9;
                  pbVar17 = pbVar16;
                  if (param_1[2] != 0) {
                    do {
                      pbVar16 = pbVar17 + 1;
                      bVar6 = *pbVar17;
                      *puVar14 = (&dword_40B6954)[bVar6 >> 6];
                      puVar14[1] = (&dword_40B6954)[(bVar6 & 0x3f) >> 4];
                      puVar14[2] = *(undefined4 *)((int)&dword_40B6954 + (bVar6 & 0xc));
                      puVar14[3] = (&dword_40B6954)[bVar6 & 3];
                      iVar4 = iVar4 + 4;
                      puVar14 = puVar14 + 4;
                      pbVar17 = pbVar16;
                    } while (iVar4 < (int)(uint)param_1[2]);
                  }
                  puVar9 = (undefined4 *)(dword_40B6940 + (int)puVar9);
                  iVar10 = iVar10 + 1;
                } while (iVar10 < (int)(uint)param_1[3]);
              }
            }
          }
          else if (_km_coni == 4) {
            puVar7 = (undefined *)(iVar10 + dword_40B6980);
            iVar10 = 0;
            pbVar16 = pbVar3;
            if (param_1[3] != 0) {
              do {
                iVar4 = 0;
                puVar12 = puVar7;
                pbVar17 = pbVar16;
                if (param_1[2] != 0) {
                  do {
                    pbVar16 = pbVar17 + 1;
                    bVar6 = *pbVar17;
                    *puVar12 = *(undefined *)((int)&dword_40B6954 + (uint)(bVar6 >> 6) * 4 + 3);
                    puVar12[1] = *(undefined *)((int)&dword_40B6954 + ((bVar6 & 0x3f) >> 4) * 4 + 3)
                    ;
                    puVar12[2] = *(undefined *)((int)&dword_40B6954 + (bVar6 & 0xc) + 3);
                    puVar12[3] = *(undefined *)((int)&dword_40B6954 + (bVar6 & 3) * 4 + 3);
                    iVar4 = iVar4 + 4;
                    puVar12 = puVar12 + 4;
                    pbVar17 = pbVar16;
                  } while (iVar4 < (int)(uint)param_1[2]);
                }
                puVar7 = puVar7 + dword_40B6940;
                iVar10 = iVar10 + 1;
              } while (iVar10 < (int)(uint)param_1[3]);
            }
          }
          else if (_km_coni == 0x10) {
            pbVar17 = (byte *)((iVar10 >> 2) + dword_40B6980);
            iVar10 = 0;
            pbVar16 = pbVar3;
            if (param_1[3] != 0) {
              do {
                iVar4 = 0;
                pbVar11 = pbVar17;
                pbVar15 = pbVar16;
                if (param_1[2] != 0) {
                  do {
                    pbVar16 = pbVar15 + 1;
                    bVar6 = 0;
                    uVar5 = 0;
                    do {
                      bVar6 = (byte)(((&dword_40B6954)[(int)(uint)*pbVar15 >> (uVar5 & 0x3f) & 3] &
                                     3) << (uVar5 & 0x3f)) | bVar6;
                      uVar5 = uVar5 + 2;
                    } while ((int)uVar5 < 8);
                    *pbVar11 = bVar6;
                    iVar4 = iVar4 + 4;
                    pbVar11 = pbVar11 + 1;
                    pbVar15 = pbVar16;
                  } while (iVar4 < (int)(uint)param_1[2]);
                }
                pbVar17 = pbVar17 + dword_40B6940;
                iVar10 = iVar10 + 1;
              } while (iVar10 < (int)(uint)param_1[3]);
            }
          }
          _kfree(pbVar3,iVar2);
          return 0;
        }
        _kfree(pbVar3,iVar2);
      }
    }
  }
  return 0x16;
}
/* GHIDRADEC_FUNCTION index=2087 start=0x4070aa4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _km_eraserect(word *param_1)

{
  undefined4 uVar1;
  word wVar2;
  int iVar3;
  uint uVar4;
  undefined *puVar5;
  undefined4 *puVar6;
  undefined *puVar7;
  undefined4 *puVar8;
  int iVar9;
  
  uVar1 = (&dword_40B6954)[*(uint *)(param_1 + 4) & 3];
  iVar9 = dword_40B6944 + -0x460;
  if (iVar9 < 0) {
    iVar9 = dword_40B6944 + -0x45f;
  }
  *param_1 = (sword)(iVar9 >> 1) + *param_1;
  iVar9 = _unk_40B694C + -0x340;
  if (iVar9 < 0) {
    iVar9 = _unk_40B694C + -0x33f;
  }
  param_1[1] = (sword)(iVar9 >> 1) + param_1[1];
  *param_1 = *param_1 & 0xfffc;
  wVar2 = param_1[2] + 3 & 0xfffc;
  param_1[2] = wVar2;
  if ((int)((uint)*param_1 + (uint)wVar2) <= dword_40B6944) {
    uVar4 = (uint)param_1[3];
    if ((int)(uVar4 + param_1[1]) <= _unk_40B694C) {
      iVar9 = (uint)*param_1 + dword_40B6948 * (uint)param_1[1];
      if (_km_coni == 0x10) {
        puVar5 = (undefined *)((iVar9 >> 2) + dword_40B6980);
        iVar9 = 0;
        if (uVar4 != 0) {
          do {
            iVar3 = 0;
            puVar7 = puVar5;
            if (param_1[2] != 0) {
              do {
                *puVar7 = (char)uVar1;
                iVar3 = iVar3 + 4;
                puVar7 = puVar7 + 1;
              } while (iVar3 < (int)(uint)param_1[2]);
            }
            puVar5 = puVar5 + dword_40B6940;
            iVar9 = iVar9 + 1;
          } while (iVar9 < (int)(uint)param_1[3]);
        }
      }
      else {
        puVar6 = (undefined4 *)(iVar9 + dword_40B6980);
        iVar9 = 0;
        if (uVar4 != 0) {
          do {
            iVar3 = 0;
            puVar8 = puVar6;
            if (param_1[2] != 0) {
              do {
                *puVar8 = uVar1;
                iVar3 = _km_coni + iVar3;
                puVar8 = puVar8 + 1;
              } while (iVar3 < (int)(uint)param_1[2]);
            }
            puVar6 = (undefined4 *)(dword_40B6940 + (int)puVar6);
            iVar9 = iVar9 + 1;
          } while (iVar9 < (int)(uint)param_1[3]);
        }
      }
      return 0;
    }
  }
  return 0x16;
}
/* GHIDRADEC_FUNCTION index=2088 start=0x4070bce */

void _km_clear_win(void)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  _km_begin_access();
  iVar3 = word_40B68DC * 0xc;
  if (iVar3 < ((int)word_40B68E4 + (int)word_40B68DC) * 0xc) {
    do {
      iVar4 = (int)word_40B68DE;
      puVar1 = (undefined4 *)
               ((uint)((word_40B68D8 + iVar4) * 0x20) / _km_coni +
               dword_40B6980 + dword_40B6940 * iVar3);
      for (iVar2 = (word_40B68D8 + iVar4) * 8; iVar2 < (word_40B68E0 + iVar4) * 8;
          iVar2 = _km_coni + iVar2) {
        *puVar1 = dword_40B68F4;
        iVar4 = (int)word_40B68DE;
        puVar1 = puVar1 + 1;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < ((int)word_40B68E4 + (int)word_40B68DC) * 0xc);
  }
  _km_end_access();
  return;
}
/* GHIDRADEC_FUNCTION index=2089 start=0x4070c88 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _km_clear_screen(void)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  puVar3 = dword_40B6980;
  _km_begin_access();
  uVar1 = (uint)(_unk_40B694C * dword_40B6940) >> 2;
  iVar2 = 0;
  if (uVar1 != 0) {
    do {
      *puVar3 = dword_40B695C;
      iVar2 = iVar2 + 1;
      puVar3 = puVar3 + 1;
    } while (iVar2 < (int)uVar1);
  }
  _km_end_access();
  return;
}
/* GHIDRADEC_FUNCTION index=2090 start=0x4070ccc */

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
/* GHIDRADEC_FUNCTION index=2091 start=0x4071486 */

void _km_flip_cursor(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  int iVar6;
  
  if (-1 < word_40B68D8) {
    _km_begin_access();
    iVar1 = dword_40B6980 + (uint)(((int)word_40B68D8 + (int)word_40B68DE) * 0x20) / _km_coni;
    iVar4 = (int)word_40B68DC;
    iVar2 = dword_40B6940 * 0xc;
    iVar6 = 0;
    do {
      if (word_40B68DA < 0) {
        iVar3 = (int)word_40B68DA;
      }
      else {
        iVar3 = word_40B68DA * 0xc;
      }
      puVar5 = (uint *)(dword_40B6940 * (iVar6 + iVar3) + iVar2 * iVar4 + iVar1);
      if (_km_coni == 0x10) {
        *(word *)puVar5 = ~*(word *)puVar5;
      }
      else {
        iVar3 = 0;
        do {
          *puVar5 = ~*puVar5;
          iVar3 = _km_coni + iVar3;
          puVar5 = puVar5 + 1;
        } while (iVar3 < 8);
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < 0xc);
    _km_end_access();
    if ((byte_40B6953 & 2) != 0) {
      pushInvalidateCaches(1);
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2092 start=0x407153c */

void _km_clear_eol(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  
  _km_begin_access();
  iVar3 = (int)word_40B68E0;
  if (param_1 == 0) {
    iVar3 = iVar3 - word_40B68D8;
  }
  iVar4 = 0;
  do {
    iVar1 = (int)word_40B68DE;
    if (param_1 == 0) {
      iVar1 = word_40B68D8 + iVar1;
    }
    puVar2 = (undefined4 *)
             ((uint)(iVar1 << 5) / _km_coni +
             dword_40B6940 * (iVar4 + ((int)word_40B68DA + (int)word_40B68DC) * 0xc) + dword_40B6980
             );
    if (_km_coni == 0x10) {
      iVar1 = 0;
      if (0 < iVar3) {
        do {
          *(undefined2 *)puVar2 = dword_40B68F4._2_2_;
          iVar1 = iVar1 + 1;
          puVar2 = (undefined4 *)((int)puVar2 + 2);
        } while (iVar1 < iVar3);
      }
    }
    else {
      iVar1 = 0;
      if (0 < (iVar3 << 3) / (int)_km_coni) {
        do {
          *puVar2 = dword_40B68F4;
          iVar1 = iVar1 + 1;
          puVar2 = puVar2 + 1;
        } while (iVar1 < (iVar3 << 3) / (int)_km_coni);
      }
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 < 0xc);
  _km_end_access();
  return;
}
/* GHIDRADEC_FUNCTION index=2093 start=0x4071624 */

void _alert(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
           undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
           undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12)

{
  undefined uStack_104;
  undefined uStack_103;
  undefined uStack_102;
  
  if ((unk_40B6904 & 0x20) != 0) {
    _alert_done();
  }
  if ((_cons_tp == _cons) && ((unk_40B6904 & 8) != 0)) {
    if (word_40B6938 != 0) {
      word_40B6938 = word_40B6938 + 1;
    }
  }
  else {
    _alert_lock_screen(1);
    _kmpopup(param_3,1,param_1,param_2,1);
    word_40B6938 = word_40B6938 + 1;
  }
  _alert_key = 0;
  unk_40B6904 = unk_40B6904 | 0x120;
  uStack_104 = 0x25;
  uStack_103 = 0x4c;
  uStack_102 = 0;
  _strcat(&uStack_104,param_4);
  _printf(&uStack_104,param_5,param_6,param_7,param_8,param_9,param_10,param_11,param_12);
  return;
}
/* GHIDRADEC_FUNCTION index=2094 start=0x4071704 */

void _alert_done(void)

{
  sword sVar1;
  word wVar2;
  bool bVar3;
  
  _alert_key = 0;
  wVar2 = unk_40B6904 & 0xfeff;
  if ((unk_40B6904 & 0x20) != 0) {
    unk_40B6904 = unk_40B6904 & 0xfedf;
    wVar2 = unk_40B6904;
    if ((word_40B6938 != 0) &&
       (sVar1 = word_40B6938 + -1, bVar3 = word_40B6938 == 1, word_40B6938 = sVar1, bVar3)) {
      _kmrestore();
      _alert_lock_screen(0);
      wVar2 = unk_40B6904;
    }
  }
  unk_40B6904 = wVar2;
  return;
}
/* GHIDRADEC_FUNCTION index=2095 start=0x4071754 */

void _alert_lock_screen(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (_eventsOpen != 0) {
    if (param_1 == 0) {
      *(undefined4 *)(_evg + 0x14) = 0;
    }
    else {
loc_40717E0:
      while (*(int *)(_evg + 0x14) == 1) {
        iVar4 = *(int *)(*(int *)(_processor_ptr + 0x128) + 0x104);
        iVar1 = *(int *)(*(int *)(_processor_ptr + 0x128) + 0x100);
        iVar2 = *(int *)(_active_threads + 0x54);
        iVar3 = *(int *)(_active_threads + 0x5c);
        if (((*(byte *)(_active_threads + 0x4b) & 2) != 0) || (0 < *(int *)(_processor_ptr + 0x104))
           ) goto loc_40717DA;
        if ((iVar3 != 2) && ((iVar3 < 3 && (iVar3 == 1)))) goto loc_40717CE;
        if (((iVar4 != 0) && (iVar2 <= iVar1)) &&
           ((iVar2 < iVar1 || (*(int *)(_processor_ptr + 0x120) == 0)))) goto loc_40717DA;
      }
      *(undefined4 *)(_evg + 0x14) = 1;
    }
    if ((_eventTask != 0) && (iVar4 = *(int *)(_eventTask + 0x18), iVar4 != _eventTask + 0x18)) {
      do {
        if (param_1 == 0) {
          _thread_resume(iVar4);
        }
        else {
          _thread_suspend(iVar4);
        }
        iVar4 = *(int *)(iVar4 + 0x10);
      } while (iVar4 != _eventTask + 0x18);
    }
  }
  return;
loc_40717CE:
  if ((*(int *)(_processor_ptr + 0x120) == 0) && ((0 < iVar4 && (iVar2 <= iVar1)))) {
loc_40717DA:
    _thread_block();
  }
  goto loc_40717E0;
}
/* GHIDRADEC_FUNCTION index=2096 start=0x4071854 */

void _km_power_down(void)

{
  uint uVar1;
  int iVar2;
  
  if ((unk_40B6904 & 8) != 0) {
    _printf(aReallyPowerOff);
    do {
      iVar2 = _kmtrygetc();
    } while (iVar2 == -1);
    if (iVar2 != 0x79) {
      uVar1 = *_intrstat;
      while ((uVar1 & 4) != 0) {
        _rtc_intr();
        uVar1 = *_intrstat;
      }
      *_intrmask = *_intrmask | 4;
      _intr_mask = _intr_mask | 4;
      return;
    }
    _printf(aShutDownInProg);
  }
  _force_power_down = 1;
  _vidStopAnimation();
  _vidSuspendAnimation();
  _reboot_mach(0x90000);
  return;
}
/* GHIDRADEC_FUNCTION index=2097 start=0x40718f4 */

void _km_switch_to_vm(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = _mon_global;
  if ((dword_40B1BC6 == 0) && ((byte_40B6953 & 1) != 0)) {
    dword_40B1BC6 = 1;
    iVar3 = 0;
    iVar4 = 0;
    do {
      if (*(int *)((int)&unk_40B6978 + iVar4) != 0) {
        uVar2 = _map_addr(*(undefined4 *)((int)&unk_40B6970 + iVar4),
                          *(int *)((int)&unk_40B6978 + iVar4));
        *(undefined4 *)((int)&dword_40B6974 + iVar4) = uVar2;
      }
      iVar4 = iVar4 + 0xc;
      iVar3 = iVar3 + 1;
    } while (iVar3 < 6);
    if (0x2b < *(sword *)(iVar1 + 0x30c)) {
      *(undefined4 *)(iVar1 + 0x35c) = dword_40B6974;
      *(undefined4 *)(iVar1 + 0x368) = dword_40B6980;
      *(int *)(iVar1 + 0x374) = dword_40B698C;
      *(undefined4 *)(iVar1 + 0x380) = dword_40B6998;
      *(undefined4 *)(iVar1 + 0x38c) = dword_40B69A4;
      *(undefined4 *)(iVar1 + 0x398) = dword_40B69B0;
    }
    if (dword_40B6990 == 0) {
      _kmem_alloc_wired(_kernel_map,&dword_40B698C,(0x6a0 / _km_coni) * 0xd2);
      if (dword_40B698C != 0) {
        dword_40B6990 = (0x6a0 / _km_coni) * 0xd2;
        word_40B68E2 = 0x32;
        word_40B68E6 = 0xf;
        dword_40B68EC = dword_40B698C;
        unk_40B6904 = unk_40B6904 | 0x10;
      }
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2098 start=0x4071aa4 */

void _km_select_console(void)

{
  int iVar1;
  
  iVar1 = _mon_global;
  if (_slot_id == 0) {
    _nbic_bus_enable();
  }
  if (0x2b < *(sword *)(iVar1 + 0x30c)) {
    if ((*(char *)(iVar1 + 0x34c) != _slot_id) &&
       (iVar1 = _km_try_slot((int)*(char *)(iVar1 + 0x34c),(int)*(char *)(iVar1 + 0x34d)),
       iVar1 == 1)) {
      return;
    }
  }
  _bzero(&_km_coni,0x80);
  iVar1 = _vidProbeForFB();
  if (iVar1 != -1) {
    byte_40B6964 = (undefined)_slot_id;
    byte_40B6965 = (undefined)iVar1;
    _vidGetConsoleInfo(&_km_coni);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2099 start=0x4071b34 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _km_try_slot(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint3 uVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  
  _bzero(&_km_coni,0x80);
  uVar2 = param_1 << 0x18;
  if ((*(uint *)(uVar2 | 0xf0fffff0) & 0xc0000000) == 0xc0000000) {
    byte_40B6964 = (undefined)param_1;
    byte_40B6965 = (undefined)param_2;
    if ((*(uint *)(uVar2 | 0xf0ffffe0) & 0xff000000) == 0xa5000000) {
      byte_40B6966 = *(char *)(uVar2 | 0xf0ffffd8);
      uVar3 = (uint3)(((uint)*(byte *)(uVar2 | 0xf0ffffb8) << 0x18) >> 8);
      unk_40B6970 = CONCAT31((uint3)*(byte *)(uVar2 | 0xf0ffffc8) |
                             (uint3)(((uint)*(byte *)(uVar2 | 0xf0ffffc0) << 0x10) >> 8) | uVar3,
                             *(undefined *)(uVar2 | 0xf0ffffd0));
      if (uVar3 != 0xf00000) {
        uVar2 = param_1 << 0x1c;
      }
      dword_40B6974 = unk_40B6970 | uVar2;
      if (uVar3 == 0xf00000) {
        iVar7 = 0x18;
      }
      else {
        iVar7 = 0x1c;
      }
      unk_40B6970 = param_1 << iVar7 | unk_40B6970;
      unk_40B6978._0_4_ = sub_4071A12(0);
      unk_40B6978._0_4_ = byte_40B6966 * 4 * unk_40B6978._0_4_;
      iVar7 = sub_4071A12(1);
      if ((param_2 < iVar7) && (-1 < param_2)) {
        param_2 = param_2 * 5;
        dword_40B6968 = sub_4071A12(param_2 + 4);
        dword_40B696C = sub_4071A12(param_2 + 5);
        iVar4 = sub_4071A12(param_2 + 6);
        _km_coni = sub_4071A12(iVar4);
        dword_40B6940 = sub_4071A12(iVar4 + 1);
        dword_40B6944 = sub_4071A12(iVar4 + 2);
        dword_40B6948 = sub_4071A12(iVar4 + 3);
        _unk_40B694C = sub_4071A12(iVar4 + 4);
        _unk_40B6950 = sub_4071A12(iVar4 + 5);
        dword_40B6954 = sub_4071A12(iVar4 + 6);
        dword_40B6958 = sub_4071A12(iVar4 + 7);
        dword_40B695C = sub_4071A12(iVar4 + 8);
        iVar7 = iVar4 + 10;
        dword_40B6960 = sub_4071A12(iVar4 + 9);
        iVar4 = 1;
        iVar8 = 0xc;
        do {
          iVar1 = iVar7 + 1;
          uVar5 = sub_4071A12(iVar7);
          uVar2 = param_1 << 0x1c;
          if ((uVar5 & 0xff000000) == 0xf0000000) {
            uVar2 = param_1 << 0x18;
          }
          *(uint *)((int)&unk_40B6970 + iVar8) = uVar2 | uVar5;
          uVar2 = param_1 << 0x1c;
          if ((uVar5 & 0xff000000) == 0xf0000000) {
            uVar2 = param_1 << 0x18;
          }
          *(uint *)((int)&dword_40B6974 + iVar8) = uVar2 | uVar5;
          iVar7 = iVar7 + 2;
          uVar6 = sub_4071A12(iVar1);
          *(undefined4 *)((int)&unk_40B6978 + iVar8) = uVar6;
          iVar8 = iVar8 + 0xc;
          iVar4 = iVar4 + 1;
        } while (iVar4 < 6);
        _unk_40B6950 = _unk_40B6950 | 1;
        return 1;
      }
    }
  }
  return 0;
}

