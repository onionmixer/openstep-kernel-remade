
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _kmpopup(char *param_1,int param_2,int param_3,int param_4,int param_5)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  word wVar7;
  uint uVar6;
  sword sVar10;
  uint uVar8;
  int iVar9;
  sword sVar12;
  uint uVar11;
  undefined2 uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  int iVar17;
  uint *puVar18;
  uint *puVar19;
  undefined *puVar20;
  undefined2 *puVar21;
  uint *puVar22;
  undefined *puVar23;
  uint *puVar24;
  int iVar25;
  
  iVar17 = _mon_global;
  *(word *)(unk_40B6908 + word_40B6906 * 2) = unk_40B6904;
  *(undefined **)(unk_40B6918 + word_40B6906 * 4) = _cons_tp;
  wVar7 = *(word *)(unk_40B6908 + word_40B6906 * 2);
  if ((*(byte *)(iVar17 + 4) & 8) != 0) {
    wVar7 = wVar7 | 0x400;
  }
  *(word *)(unk_40B6908 + word_40B6906 * 2) = wVar7;
  word_40B6906 = word_40B6906 + 1;
  if ((*(byte *)(iVar17 + 4) & 8) != 0) {
    _vidSuspendAnimation();
  }
  sVar10 = (sword)param_3;
  sVar12 = (sword)param_4;
  word_40B68E0 = sVar10;
  word_40B68E4 = sVar12;
  if (((_eventsOpen == 0) && (param_5 == 0)) && ((*(byte *)(&word_40B6906 + word_40B6906) & 4) == 0)
     ) {
    if (param_3 == 0) {
      word_40B68E0 = 100;
    }
    if (param_4 == 0) {
      word_40B68E4 = 0x30;
    }
    dword_40B68E8 = (uint *)0x0;
    goto loc_406F8E8;
  }
  if ((unk_40B6904 & 0x10) == 0) {
    if (param_3 == 0) {
      word_40B68E0 = 0x32;
    }
    if (param_4 == 0) {
      word_40B68E4 = 0xf;
    }
    iVar17 = (word_40B68E4 * 0xc + 0x1e) * ((uint)((word_40B68E0 + 3) * 0x20) / _km_coni);
    if (iVar17 - dword_40B6990 != 0 && dword_40B6990 <= iVar17) {
      if ((_mb_map != 0) &&
         (dword_40B68E8 = (uint *)_kmem_mb_alloc(_mb_map,iVar17), dword_40B68E8 != (uint *)0x0)) {
        word_40B68E2 = word_40B68E0;
        word_40B68E6 = word_40B68E4;
        unk_40B6904 = unk_40B6904 | 0x10;
        dword_40B68EC = dword_40B68E8;
        goto loc_406F8E8;
      }
      if (dword_40B6990 < iVar17) {
        if (dword_40B6990 * 3 < iVar17) {
          word_40B68E0 = (sword)((word_40B68E0 * 3) / 5);
        }
        word_40B68E4 = (sword)(dword_40B6990 /
                              (int)(((uint)((word_40B68E0 + 3) * 0x20) / _km_coni) * 0xc));
      }
    }
    dword_40B68E8 = dword_40B698C;
    goto loc_406F8E8;
  }
  if (dword_40B68E8 == (uint *)0x0) {
    dword_40B68E8 = dword_40B68EC;
  }
  word_40B68E0 = word_40B68E2;
  if (param_3 == 0) {
    if (0x4f < word_40B68E2) goto loc_406F7A8;
  }
  else if (param_3 <= word_40B68E2) {
loc_406F7A8:
    word_40B68E0 = 0x50;
    if (param_3 != 0) {
      word_40B68E0 = sVar10;
    }
  }
  word_40B68E4 = word_40B68E6;
  if (param_4 == 0) {
    if (word_40B68E6 < 0x28) goto loc_406F8E8;
  }
  else if (word_40B68E6 < param_4) goto loc_406F8E8;
  word_40B68E4 = 0x28;
  if (param_4 != 0) {
    word_40B68E4 = sVar12;
  }
loc_406F8E8:
  uVar5 = dword_40B6960;
  uVar4 = dword_40B695C;
  uVar3 = dword_40B6958;
  uVar6 = dword_40B6954;
  iVar17 = dword_40B6944 + word_40B68E0 * -8;
  if (iVar17 < 0) {
    iVar17 = iVar17 + 0xf;
  }
  word_40B68DE = (sword)(iVar17 >> 4);
  word_40B68DC = (sword)((_unk_40B694C + 0x1a + word_40B68E4 * -0xc) / 0x18);
  unk_40B6904 = unk_40B6904 | 8;
  _cons_tp = _cons;
  uVar16 = dword_40B6954;
  if (param_2 == 1) {
    uVar16 = dword_40B6958;
  }
  dword_40B1BBE = 0;
  _km_begin_access();
  if (param_2 == 2) {
    _km_clear_screen();
  }
  iVar17 = dword_40B6980 + (uint)((int)word_40B68DE << 5) / _km_coni;
  uVar2 = _km_coni * 2;
  iVar25 = 0;
  puVar24 = dword_40B68E8;
  do {
    if (word_40B68E4 * 0xc + 0x1a <= iVar25) {
      dword_40B68F4 = uVar5;
      dword_40B68F0 = uVar6;
      sVar10 = word_40B68E0 / 2;
      uVar6 = _strlen(param_1);
      word_40B68D8 = sVar10 - (sword)(uVar6 >> 1);
      word_40B68DA = 0xffef;
      iVar17 = 0;
      cVar1 = *param_1;
      while (cVar1 != '\0') {
        _kmpaint((int)cVar1);
        iVar17 = iVar17 + 1;
        cVar1 = param_1[iVar17];
      }
      _km_flip_cursor();
      dword_40B68F4 = uVar16;
      dword_40B68F0 = uVar5;
      word_40B68DA = 0;
      word_40B68D8 = 0;
      unk_40B6904 = unk_40B6904 & 0xfdff;
      return 0;
    }
    uVar14 = dword_40B6960;
    if ((((iVar25 == 0) || (iVar25 == 0x16)) || (word_40B68E4 * 0xc + 0x19 == iVar25)) ||
       ((uVar8 = uVar3, uVar11 = uVar5, uVar15 = uVar4, 0x12 < iVar25 - 2U &&
        ((uVar14 = uVar3, iVar25 == 1 ||
         (uVar8 = uVar16, uVar11 = uVar16, uVar15 = uVar16, uVar14 = uVar4, iVar25 == 0x15)))))) {
      uVar8 = uVar14;
      uVar11 = uVar14;
      uVar15 = uVar14;
    }
    puVar18 = (uint *)(dword_40B6940 * (iVar25 + -0x18 + word_40B68DC * 0xc) +
                      (iVar17 - 0x60 / uVar2));
    uVar13 = (undefined2)uVar11;
    if (_km_coni == 2) {
      _adb_watchdog(0);
      puVar21 = (undefined2 *)((int)puVar18 + 0xe);
      if (puVar24 == (uint *)0x0) {
        *puVar21 = dword_40B6960._2_2_;
        *(sword *)(puVar18 + 4) = (sword)uVar8;
        puVar21 = (undefined2 *)((int)puVar18 + 0x12);
        for (iVar9 = 9; iVar9 < word_40B68E0 * 8 + 0xf; iVar9 = iVar9 + 1) {
          *puVar21 = uVar13;
          puVar21 = puVar21 + 1;
        }
        *puVar21 = (sword)uVar15;
        puVar21[1] = dword_40B6960._2_2_;
      }
      else {
        *(undefined2 *)puVar24 = *puVar21;
        *puVar21 = dword_40B6960._2_2_;
        *(undefined2 *)((int)puVar24 + 2) = *(undefined2 *)(puVar18 + 4);
        *(sword *)(puVar18 + 4) = (sword)uVar8;
        puVar21 = (undefined2 *)((int)puVar18 + 0x12);
        puVar18 = puVar24 + 1;
        for (iVar9 = 9; iVar9 < word_40B68E0 * 8 + 0xf; iVar9 = iVar9 + 1) {
          *(undefined2 *)puVar18 = *puVar21;
          *puVar21 = uVar13;
          puVar21 = puVar21 + 1;
          puVar18 = (uint *)((int)puVar18 + 2);
        }
        *(undefined2 *)puVar18 = *puVar21;
        *puVar21 = (sword)uVar15;
        puVar24 = puVar18 + 1;
        *(undefined2 *)((int)puVar18 + 2) = puVar21[1];
        puVar21[1] = dword_40B6960._2_2_;
      }
loc_406FD50:
      _adb_watchdog(1);
    }
    else if ((int)_km_coni < 3) {
      if (_km_coni == 1) {
        _adb_watchdog(0);
        puVar22 = puVar18 + 7;
        if (puVar24 == (uint *)0x0) {
          *puVar22 = dword_40B6960;
          puVar18[8] = uVar8;
          puVar18 = puVar18 + 9;
          for (iVar9 = 9; iVar9 < word_40B68E0 * 8 + 0xf; iVar9 = iVar9 + 1) {
            *puVar18 = uVar11;
            puVar18 = puVar18 + 1;
          }
          *puVar18 = uVar15;
          puVar18[1] = dword_40B6960;
        }
        else {
          *puVar24 = *puVar22;
          *puVar22 = dword_40B6960;
          puVar24[1] = puVar18[8];
          puVar18[8] = uVar8;
          puVar18 = puVar18 + 9;
          puVar22 = puVar24 + 2;
          for (iVar9 = 9; iVar9 < word_40B68E0 * 8 + 0xf; iVar9 = iVar9 + 1) {
            *puVar22 = *puVar18;
            *puVar18 = uVar11;
            puVar18 = puVar18 + 1;
            puVar22 = puVar22 + 1;
          }
          *puVar22 = *puVar18;
          *puVar18 = uVar15;
          puVar24 = puVar22 + 2;
          puVar22[1] = puVar18[1];
          puVar18[1] = dword_40B6960;
        }
        goto loc_406FD50;
      }
    }
    else if (_km_coni == 4) {
      puVar20 = (undefined *)((int)puVar18 + 7);
      if (puVar24 == (uint *)0x0) {
        *puVar20 = (undefined)dword_40B6960;
        *(char *)(puVar18 + 2) = (char)uVar8;
        puVar20 = (undefined *)((int)puVar18 + 9);
        for (iVar9 = 9; iVar9 < word_40B68E0 * 8 + 0xf; iVar9 = iVar9 + 1) {
          *puVar20 = (char)uVar11;
          puVar20 = puVar20 + 1;
        }
        *puVar20 = (char)uVar15;
        puVar20[1] = (undefined)dword_40B6960;
      }
      else {
        *(undefined *)puVar24 = *puVar20;
        *puVar20 = (undefined)dword_40B6960;
        *(undefined *)((int)puVar24 + 1) = *(undefined *)(puVar18 + 2);
        *(char *)(puVar18 + 2) = (char)uVar8;
        puVar20 = (undefined *)((int)puVar18 + 9);
        puVar23 = (undefined *)((int)puVar24 + 2);
        for (iVar9 = 9; iVar9 < word_40B68E0 * 8 + 0xf; iVar9 = iVar9 + 1) {
          *puVar23 = *puVar20;
          *puVar20 = (char)uVar11;
          puVar20 = puVar20 + 1;
          puVar23 = puVar23 + 1;
        }
        *puVar23 = *puVar20;
        *puVar20 = (char)uVar15;
        puVar24 = (uint *)(puVar23 + 2);
        puVar23[1] = puVar20[1];
        puVar20[1] = (undefined)dword_40B6960;
      }
    }
    else if (_km_coni == 0x10) {
      puVar22 = puVar24;
      if (puVar24 != (uint *)0x0) {
        puVar22 = puVar24 + 1;
        *puVar24 = *puVar18;
      }
      puVar19 = puVar18 + 1;
      *puVar18 = uVar8 & 0x30000 |
                 CONCAT22((word)(dword_40B6960 >> 0x10) & 0xc | (word)(*puVar18 >> 0x10) & 0xfff0,
                          uVar13);
      iVar9 = 1;
      puVar24 = puVar19;
      puVar18 = puVar22;
      if (1 < word_40B68E0 + 3 >> 1) {
        do {
          puVar22 = puVar18;
          if (puVar18 != (uint *)0x0) {
            puVar22 = puVar18 + 1;
            *puVar18 = *puVar24;
          }
          puVar19 = puVar24 + 1;
          *puVar24 = uVar11;
          iVar9 = iVar9 + 1;
          puVar24 = puVar19;
          puVar18 = puVar22;
        } while (iVar9 < word_40B68E0 + 3 >> 1);
      }
      puVar24 = puVar22;
      if (puVar22 != (uint *)0x0) {
        puVar24 = puVar22 + 1;
        *puVar22 = *puVar19;
      }
      *puVar19 = uVar15 & 0xc0000000 | dword_40B6960 & 0x30000000 | *puVar19 & 0xfffffff;
    }
    iVar25 = iVar25 + 1;
  } while( true );
}
