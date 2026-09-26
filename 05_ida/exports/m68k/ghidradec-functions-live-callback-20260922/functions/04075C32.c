
int _od_fsm(int param_1,int param_2,undefined4 param_3)

{
  undefined *puVar1;
  int *piVar2;
  undefined *puVar3;
  int iVar4;
  bool bVar5;
  char cVar9;
  undefined4 uVar6;
  uint *puVar7;
  byte bVar10;
  int iVar8;
  word wVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  sword sVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  char *pcVar22;
  undefined uStack_1d;
  int iStack_1c;
  
  puVar1 = *(undefined **)(param_2 + 8);
  iVar4 = (&_odcinfo)[(param_1 + -0x40c3b88) * 0x451ab30b >> 2];
  piVar2 = *(int **)(puVar1 + 0xae);
  puVar3 = *(undefined **)(param_1 + 0x210);
  bVar5 = false;
  iVar8 = piVar2[0x19];
  iVar20 = (int)*(sword *)((int)piVar2 + 0x76) - (int)*(sword *)(piVar2 + 0x1e);
  *(char *)(param_1 + 0x267) = (char)param_3;
  *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) & 0x9fffffff;
  if (-1 < *(char *)(param_2 + 0x1e)) {
    *(undefined *)(param_2 + 0x1e) = 0;
  }
  if (*piVar2 == 0x4e655854) {
    iVar17 = piVar2[0x19] >> 1;
  }
  else {
    iVar17 = 1;
  }
  iVar18 = (int)*(sword *)(piVar2 + 0x1e) / iVar17;
  switch(param_3) {
  case :
    *(undefined *)(param_1 + 0x269) = 1;
    iVar12 = *(int *)(*(int *)(puVar1 + 0xb6) + 0x2c) / *(int *)(*(int *)(puVar1 + 0xb6) + 0x28);
    if (*(int *)(param_1 + 0x23c) <= iVar12) {
      iVar12 = *(int *)(param_1 + 0x23c);
    }
    *(int *)(param_1 + 0x244) = iVar12;
    if ((*piVar2 != 0x4e655854) &&
       ((((*(char *)(param_1 + 0x25e) != '\0' || (*(char *)(param_1 + 0x25f) != '\0')) &&
         ((*(char *)(param_1 + 0x25e) != '\x01' || (*(char *)(param_1 + 599) != '\x04')))) ||
        ((*(uint *)(param_1 + 0x220) & 0x800) != 0)))) {
      *(undefined4 *)(param_1 + 0x244) = 1;
    }
    if ((*(uint *)(param_1 + 0x220) & 0xc0000) == 0) {
      iVar16 = *(int *)(param_1 + 0x230) % iVar20;
      iVar12 = (int)*(sword *)((int)piVar2 + 0x7a);
      if ((iVar16 < iVar12) || (iVar16 = *(sword *)(piVar2 + 0x1e) + iVar16, iVar16 < iVar12)) {
        iVar21 = -iVar16;
      }
      else {
        iVar21 = *(sword *)((int)piVar2 + 0x76) - iVar16;
      }
      iVar12 = iVar12 + iVar21;
      if (*(int *)(param_1 + 0x244) < iVar12) {
        iVar12 = *(int *)(param_1 + 0x244);
      }
      *(int *)(param_1 + 0x244) = iVar12;
      *(int *)(param_1 + 0x238) =
           (int)*(sword *)(piVar2 + 0x1c) +
           iVar16 + (int)*(sword *)((int)piVar2 + 0x76) * (*(int *)(param_1 + 0x230) / iVar20);
    }
    else {
      *(undefined4 *)(param_1 + 0x238) = *(undefined4 *)(param_1 + 0x230);
    }
    do {
      *(int *)(param_1 + 0x238) = *(int *)(puVar1 + 0xbe) + *(int *)(param_1 + 0x238);
      *(char *)(param_1 + 0x264) = (char)(*(int *)(param_1 + 0x238) % piVar2[0x19]);
      iVar20 = (int)*(char *)(param_1 + 0x264) % iVar17;
      *(sword *)(param_1 + 0x22c) = (sword)(*(int *)(param_1 + 0x238) / piVar2[0x19]);
      if (*piVar2 == 0x4e655854) {
        uVar14 = ((int)*(sword *)(param_1 + 0x22c) - *(int *)(puVar1 + 0xbe) / piVar2[0x19]) * 2;
        if (iVar8 >> 1 <= (int)*(char *)(param_1 + 0x264)) {
          uVar14 = uVar14 | 1;
        }
      }
      else {
        uVar14 = *(int *)(param_1 + 0x238) - *(int *)(puVar1 + 0xbe);
      }
      iVar12 = uVar14 + (iVar17 + *(int *)(param_1 + 0x244) + -1 + iVar20) / iVar17;
      *(char *)(param_1 + 0x25c) = (char)*(undefined2 *)(param_1 + 0x248);
      if (((*(uint *)(param_1 + 0x220) & 0x40000) != 0) ||
         (((*(uint *)(param_1 + 0x220) & 0x80000) != 0 && ((char)puVar1[0xd9] < '\0')))) {
        bVar5 = true;
        if (((*(char *)(param_1 + 0x25c) != '\x01') && (*(char *)(param_1 + 0x25c) != '\x04')) ||
           (((*(uint *)(param_1 + 0x220) & 0x40000) != 0 || (iVar12 <= (int)uVar14))))
        goto loc_4076424;
        goto loc_4075EE6;
      }
      bVar5 = false;
      iVar16 = 0;
      if (iVar12 <= (int)uVar14) goto loc_4076424;
      iStack_1c = 0;
      while( true ) {
        *(sword *)(param_1 + 0x250) = (sword)((int)uVar14 >> 4);
        *(byte *)(param_1 + 0x252) = ((byte)uVar14 & 0xf) << 1;
        iVar21 = *(int *)(puVar1 + 0xc6);
        uVar13 = *(int *)(iVar21 + *(sword *)(param_1 + 0x250) * 4) >>
                 ((int)*(char *)(param_1 + 0x252) & 0x3fU) & 3;
        if (uVar13 == 1) break;
        if (uVar13 < 2) {
          if (uVar13 != 0) goto loc_4076414;
          if ((iVar16 != 0) && ((*piVar2 == 0x4e655854 || (*(sword *)(param_1 + 0x248) == 2))))
          goto loc_407609A;
          if (*(sword *)(param_1 + 0x248) != 2) {
            if ((*piVar2 != 0x4e655854) && (*(sword *)(param_1 + 0x248) != 0xf5)) {
              if (*(sword *)(param_1 + 0x248) == 4) {
                uVar13 = *(uint *)(*(int *)(puVar1 + 0xc6) + *(sword *)(param_1 + 0x250) * 4);
                if (3 << ((int)*(char *)(param_1 + 0x252) & 0x3fU) !=
                    (3 << ((int)*(char *)(param_1 + 0x252) & 0x3fU) & uVar13)) {
                  *(word *)(puVar1 + 0xd8) = *(word *)(puVar1 + 0xd8) | 0x1000;
                  if (_od_update_time == 0) {
                    _od_update_time = 1;
                  }
                  uVar13 = ~(3 << ((int)*(char *)(param_1 + 0x252) & 0x3fU)) & uVar13;
                  sVar15 = *(sword *)(param_1 + 0x250);
                  iVar21 = *(int *)(puVar1 + 0xc6);
                  cVar9 = *(char *)(param_1 + 0x252);
                  iVar19 = 3;
loc_40761D8:
                  *(uint *)(iVar21 + sVar15 * 4) = iVar19 << ((int)cVar9 & 0x3fU) | uVar13;
                }
              }
              else {
                uVar13 = *(uint *)(*(int *)(puVar1 + 0xc6) + *(sword *)(param_1 + 0x250) * 4);
                if (2 << ((int)*(char *)(param_1 + 0x252) & 0x3fU) !=
                    (3 << ((int)*(char *)(param_1 + 0x252) & 0x3fU) & uVar13)) {
                  *(word *)(puVar1 + 0xd8) = *(word *)(puVar1 + 0xd8) | 0x1000;
                  if (_od_update_time == 0) {
                    _od_update_time = 1;
                  }
                  uVar13 = ~(3 << ((int)*(char *)(param_1 + 0x252) & 0x3fU)) & uVar13;
                  sVar15 = *(sword *)(param_1 + 0x250);
                  iVar21 = *(int *)(puVar1 + 0xc6);
                  cVar9 = *(char *)(param_1 + 0x252);
                  iVar19 = 2;
                  goto loc_40761D8;
                }
              }
loc_407640C:
              bVar5 = true;
              goto loc_4076414;
            }
            *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) | 0x40000;
            *(undefined4 *)(param_1 + 0x214) = *(undefined4 *)(param_1 + 0x224);
            uVar6 = _pmap_kernel();
            *(undefined4 *)(param_1 + 0x218) = uVar6;
            *(undefined2 *)(param_1 + 0x248) = 1;
            *(undefined *)(param_1 + 0x25d) = 0;
            *(int *)(param_1 + 0x234) =
                 (*(int *)(param_1 + 0x238) - *(int *)(puVar1 + 0xbe)) - iVar20;
            iVar8 = 0xf;
            goto loc_4076DD4;
          }
          iVar8 = 0;
          if (iVar12 <= (int)uVar14) goto loc_40763D2;
          goto loc_40760BE;
        }
        if (uVar13 == 2) {
          if (*(sword *)(param_1 + 0x248) != 0xf5) goto loc_407640C;
          goto loc_4076D42;
        }
        if (uVar13 == 3) {
          if (*(sword *)(param_1 + 0x248) == 1) {
            uVar13 = *(uint *)(iVar21 + *(sword *)(param_1 + 0x250) * 4);
            if (2 << ((int)*(char *)(param_1 + 0x252) & 0x3fU) !=
                (3 << ((int)*(char *)(param_1 + 0x252) & 0x3fU) & uVar13)) {
              *(word *)(puVar1 + 0xd8) = *(word *)(puVar1 + 0xd8) | 0x1000;
              if (_od_update_time == 0) {
                _od_update_time = 1;
              }
              *(uint *)(*(int *)(puVar1 + 0xc6) + *(sword *)(param_1 + 0x250) * 4) =
                   2 << ((int)*(char *)(param_1 + 0x252) & 0x3fU) |
                   ~(3 << ((int)*(char *)(param_1 + 0x252) & 0x3fU)) & uVar13;
            }
            if (iVar16 == 0) {
              uStack_1d = (undefined)iVar20;
              *(undefined *)(param_1 + 0x265) = uStack_1d;
            }
            if (((iVar17 != 1) && (iVar12 - 1U == uVar14)) &&
               (*(char *)(param_1 + 0x266) =
                     (char)iVar17 - (char)((iVar20 + *(int *)(param_1 + 0x244)) % iVar17),
               iVar17 == *(char *)(param_1 + 0x266))) {
              *(undefined *)(param_1 + 0x266) = 0;
            }
            goto loc_4076414;
          }
          if (*(sword *)(param_1 + 0x248) != 2) {
            if ((*(sword *)(param_1 + 0x248) != 0xf5) && (*(sword *)(param_1 + 0x248) != 4))
            goto loc_4076414;
            goto loc_4076D42;
          }
          if (iVar16 == 0) {
            iVar8 = 0;
            while (((int)uVar14 < iVar12 &&
                   ((*(int *)(iVar21 + ((int)uVar14 >> 4) * 4) >> (uVar14 & 0xf) * 2 & 3U) == 3))) {
              iVar8 = iVar8 + 1;
              uVar14 = uVar14 + 1;
            }
            goto loc_40763D2;
          }
          iStack_1c = iVar17 * iVar16;
          goto loc_407609A;
        }
loc_4076414:
        iStack_1c = iVar17 + iStack_1c;
        iVar16 = iVar16 + 1;
        uVar14 = uVar14 + 1;
        if (iVar12 <= (int)uVar14) goto loc_4076424;
      }
      if (*(sword *)(param_1 + 0x248) == 0xf5) goto loc_4076D42;
      if (iVar16 != 0) {
        iStack_1c = iVar17 * iVar16;
loc_407609A:
        *(int *)(param_1 + 0x244) = iStack_1c - iVar20;
        goto loc_4076424;
      }
      iVar12 = _od_locate_alt(param_1,param_2,puVar1,
                              (*(int *)(param_1 + 0x238) - *(int *)(puVar1 + 0xbe)) - iVar20,
                              *(undefined4 *)(param_1 + 0x238));
      if (iVar12 == -1) goto loc_4076DE0;
      iVar16 = iVar12 % iVar18;
      sVar15 = *(sword *)(piVar2 + 0x1d);
      if (iVar12 / iVar18 < (int)sVar15) {
        iVar21 = (int)*(sword *)((int)piVar2 + 0x7a) +
                 (iVar12 / iVar18) * (int)*(sword *)((int)piVar2 + 0x76) +
                 (int)*(sword *)(piVar2 + 0x1c);
      }
      else {
        iVar21 = (int)sVar15 * (int)*(sword *)((int)piVar2 + 0x76) + (int)*(sword *)(piVar2 + 0x1c);
        iVar16 = iVar12 - sVar15 * iVar18;
      }
      *(int *)(param_1 + 0x238) = iVar17 * iVar16 + iVar21;
      *(int *)(param_1 + 0x238) = iVar20 + *(int *)(param_1 + 0x238);
      iVar20 = iVar17 - iVar20;
      if (*(int *)(param_1 + 0x244) < iVar20) {
        iVar20 = *(int *)(param_1 + 0x244);
      }
      *(int *)(param_1 + 0x244) = iVar20;
    } while( true );
  case :
    _od_drive_cmd(param_1,param_2,(int)(*(sword *)(param_1 + 0x22e) >> 0xc) | 0xa000,9);
    *(word *)(param_1 + 600) = *(word *)(param_1 + 0x22e) & 0xfff;
    *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) | 0x60000000;
    *(undefined *)(param_1 + 0x268) = _od_next_state[*(byte *)(param_1 + 0x25c)];
  :
loc_4076E5A:
    *puVar3 = (char)((word)*(undefined2 *)(param_1 + 0x22c) >> 8);
    puVar3[1] = (char)*(undefined2 *)(param_1 + 0x22c);
    if ((*piVar2 != 0x4e655854) &&
       ((*(char *)(param_1 + 0x265) != '\0' || (*(char *)(param_1 + 0x266) != '\0')))) {
                    /* WARNING: Subroutine does not return */
      _panic(aOdBeforeAfter);
    }
    if (*(char *)(param_1 + 0x265) == '\0') {
      bVar10 = *(byte *)(param_1 + 0x264);
    }
    else {
      bVar10 = *(char *)(param_1 + 0x264) - *(char *)(param_1 + 0x265);
    }
    puVar3[2] = bVar10 | 0x10;
    puVar3[3] = *(char *)(param_1 + 0x266) +
                (char)*(undefined4 *)(param_1 + 0x244) + *(char *)(param_1 + 0x265);
    iVar8 = _od_issue_cmd(param_1,param_2);
    if (-1 < iVar8) {
      return iVar8;
    }
    break;
  case :
    if ((*(sword *)(param_1 + 0x248) != 4) && (*(sword *)(param_1 + 0x248) != 0xf5)) {
      *(undefined *)(param_1 + 0x25c) = 1;
loc_4076814:
      *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) | 0x20000000;
      *(undefined *)(param_1 + 0x268) = _od_next_state[*(byte *)(param_1 + 0x25c)];
      *(undefined *)(param_1 + 0x269) = 0x12;
      goto loc_4076424;
    }
    goto loc_4076D42;
  case :
    if (((*(uint *)(param_1 + 0x220) & 0x40000) != 0) || (_od_noverify == 0)) {
      *(undefined *)(param_1 + 0x25c) = 8;
      goto loc_4076814;
    }
  case :
    goto loc_4076D42;
  case :
    break;
  case :
loc_4076CEC:
    *(word *)(param_2 + 0x18) = *(word *)(param_2 + 0x18) & 0x3bff;
    if ((*(word *)(puVar1 + 0xd8) & 0x800) != 0) {
      *(word *)(puVar1 + 0xd8) = *(word *)(puVar1 + 0xd8) & 0xf7ff;
      _wakeup(puVar1 + 0xd8);
    }
    *(word *)(puVar1 + 0xd8) = *(word *)(puVar1 + 0xd8) & 0xcfff;
    *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) & 0xff7fbfff;
    if ((*(uint *)(param_1 + 0x220) & 0x400) == 0) goto loc_4076D42;
    *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) & 0xfffffbff;
    break;
  case :
    *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) & 0xff7fffff;
    cVar9 = *(char *)(param_1 + 0x26b);
    goto loc_4076DCC;
  case :
    *(undefined2 *)(param_1 + 0x24a) = *(undefined2 *)(puVar3 + 8);
    if ((*(word *)(param_1 + 0x24a) & 1) != 0) {
      _od_status(param_1,param_2,puVar3,0x2800,6);
      *(undefined *)(param_1 + 0x268) = 10;
      return 1;
    }
    goto loc_4076B0C;
  case :
    *(undefined2 *)(param_1 + 0x24c) = *(undefined2 *)(puVar3 + 8);
    if ((*(word *)(param_1 + 0x24c) & 1) != 0) {
      _od_status(param_1,param_2,puVar3,0x2a00,6);
      *(undefined *)(param_1 + 0x268) = 0xb;
      return 1;
    }
    goto loc_4076B0C;
  case :
    *(undefined2 *)(param_1 + 0x24e) = *(undefined2 *)(puVar3 + 8);
loc_4076B0C:
    if (((*(uint *)(param_1 + 0x220) & 0x4000) == 0) && (*(sword *)(param_1 + 0x24e) != 0)) {
      uVar14 = 0xf;
      pcVar22 = (char *)&unk_40B1DB0;
      do {
        if ((((uint)*(word *)(param_1 + 0x24e) & 1 << (uVar14 & 0x1f)) != 0) && (*pcVar22 != '\0'))
        {
          *(char *)(param_1 + 599) = (char)uVar14 + '%';
          *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) | 0x4000;
          break;
        }
        pcVar22 = pcVar22 + -8;
        wVar11 = (word)(uVar14 >> 0x10);
        sVar15 = (sword)uVar14 + -1;
        uVar14 = CONCAT22(wVar11,sVar15);
      } while ((sVar15 != -1) || (uVar14 = (uint)wVar11 * 0x10000 - 1, wVar11 != 0));
    }
    if (((*(uint *)(param_1 + 0x220) & 0x4000) == 0) && ((*(word *)(param_1 + 0x24c) & 0xfffe) != 0)
       ) {
      uVar14 = 0xf;
      pcVar22 = (char *)&unk_40B1D30;
      do {
        if ((((uint)*(word *)(param_1 + 0x24c) & 1 << (uVar14 & 0x1f)) != 0) && (*pcVar22 != '\0'))
        {
          *(char *)(param_1 + 599) = (char)uVar14 + '\x15';
          *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) | 0x4000;
          break;
        }
        pcVar22 = pcVar22 + -8;
        uVar14 = uVar14 - 1;
      } while (0 < (int)uVar14);
    }
    if (((*(uint *)(param_1 + 0x220) & 0x4000) == 0) && ((*(word *)(param_1 + 0x24a) & 0xfffe) != 0)
       ) {
      uVar14 = 0xf;
      pcVar22 = (char *)&unk_40B1CB8;
      do {
        if ((((uint)*(word *)(param_1 + 0x24a) & 1 << (uVar14 & 0x1f)) != 0) && (*pcVar22 != '\0'))
        {
          *(char *)(param_1 + 599) = (char)uVar14 + '\x06';
          *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) | 0x4000;
          break;
        }
        pcVar22 = pcVar22 + -8;
        uVar14 = uVar14 - 1;
      } while (0 < (int)uVar14);
    }
    do {
      iVar8 = _od_drive_cmd(param_1,param_2,0x5000,6);
    } while (iVar8 == -1);
    *(undefined *)(param_1 + 0x268) = 0xc;
    return 1;
  case :
    *(undefined *)(param_1 + 0x267) = *(undefined *)(param_1 + 0x26d);
    *(undefined *)(param_1 + 0x268) = *(undefined *)(param_1 + 0x26e);
    *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) & 0xfbffffff;
    puVar3[5] = puVar3[5] | 2;
    return -1;
  case :
    uVar14 = _od_status(param_1,param_2,puVar3,0x2000,9);
    if ((uVar14 & 0x200) != 0) {
      _od_drive_cmd(param_1,param_2,0x5300,6);
      *(undefined *)(param_1 + 0x268) = 0xe;
      return 1;
    }
  case :
    _od_idle_time = 0;
    if ((*(uint *)(param_1 + 0x220) & 0x1000000) != 0) {
      *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) & 0xfefdffff;
      return 0;
    }
loc_4076D42:
    *(undefined *)(param_1 + 0x266) = 0;
    *(undefined *)(param_1 + 0x265) = *(undefined *)(param_1 + 0x266);
    *(int *)(param_1 + 0x23c) = *(int *)(param_1 + 0x23c) - *(int *)(param_1 + 0x244);
    *(int *)(param_1 + 0x214) = piVar2[0x17] * *(int *)(param_1 + 0x244) + *(int *)(param_1 + 0x214)
    ;
    *(int *)(param_1 + 0x230) = *(int *)(param_1 + 0x244) + *(int *)(param_1 + 0x230);
    if (0 < *(int *)(param_1 + 0x23c)) {
      iVar8 = 1;
loc_4076DD4:
      iVar8 = _od_fsm(param_1,param_2,iVar8);
      return iVar8;
    }
    if (((*(uint *)(param_1 + 0x220) & 0x800) != 0) &&
       (*(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) & 0xfffff7ff,
       *(int *)(param_1 + 0x240) != 0)) {
      *(undefined *)(param_1 + 0x25e) = 0;
      *(undefined2 *)(param_1 + 0x248) = 1;
      *(undefined4 *)(param_1 + 0x23c) = *(undefined4 *)(param_1 + 0x240);
      iVar8 = 1;
      goto loc_4076DD4;
    }
    if ((*(uint *)(param_1 + 0x220) & 0x40000) != 0) {
      cVar9 = *(char *)(param_1 + 0x26a);
loc_4076DCC:
      iVar8 = (int)cVar9;
      goto loc_4076DD4;
    }
    goto loc_4076E4C;
  case :
    if ((*(uint *)(param_1 + 0x220) & 0x4000) == 0) {
      *(undefined4 *)(param_1 + 0x230) = *(undefined4 *)(param_1 + 0x234);
      if (*piVar2 == 0x4e655854) {
        *(int *)(param_1 + 0x23c) = iVar8 >> 1;
      }
      else {
        *(undefined4 *)(param_1 + 0x23c) = 1;
      }
      *(char *)(param_1 + 0x25d) = *(char *)(param_1 + 0x25d) + '\x01';
      if (_od_test_passes < *(char *)(param_1 + 0x25d)) {
        *(undefined2 *)(param_1 + 0x248) = 4;
        *(undefined *)(param_1 + 0x26a) = 0x11;
        iVar8 = 1;
      }
      else {
        uVar14 = 0;
        if ((uint)(piVar2[0x17] * *(int *)(param_1 + 0x23c)) >> 2 != 0) {
          do {
            *(undefined4 *)(*(int *)(param_1 + 0x224) + uVar14 * 4) =
                 (&unk_40B1FB8)[*(char *)(param_1 + 0x25d)];
            uVar14 = uVar14 + 1;
          } while (uVar14 < (uint)(piVar2[0x17] * *(int *)(param_1 + 0x23c)) >> 2);
        }
        *(undefined *)(param_1 + 0x26a) = 0xf;
        iVar8 = 1;
      }
    }
    else {
      iVar8 = 0x10;
    }
    goto loc_4076DD4;
  case :
    goto loc_40769A6;
  case :
    if (((*(uint *)(param_1 + 0x220) & 0x4000) == 0) &&
       (uVar14 = *(uint *)(*(int *)(puVar1 + 0xc6) + *(sword *)(param_1 + 0x250) * 4),
       3 << ((int)*(char *)(param_1 + 0x252) & 0x3fU) !=
       (3 << ((int)*(char *)(param_1 + 0x252) & 0x3fU) & uVar14))) {
      *(word *)(puVar1 + 0xd8) = *(word *)(puVar1 + 0xd8) | 0x1000;
      if (_od_update_time == 0) {
        _od_update_time = 1;
      }
      *(uint *)(*(int *)(puVar1 + 0xc6) + *(sword *)(param_1 + 0x250) * 4) =
           3 << ((int)*(char *)(param_1 + 0x252) & 0x3fU) |
           ~(3 << ((int)*(char *)(param_1 + 0x252) & 0x3fU)) & uVar14;
    }
loc_40769A6:
    if (((*(uint *)(param_1 + 0x220) & 0x4000) == 0) ||
       (iVar8 = _od_remap(param_1,param_2,puVar1,*(undefined4 *)(param_1 + 0x238)), iVar8 != 0)) {
      *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) & 0xfffbbfff;
      uVar6 = _disksort_first(*(undefined4 *)(iVar4 + 0x18));
      iVar8 = _od_setup(param_1,param_2,uVar6);
      return iVar8;
    }
    *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) & 0xfffbffff;
    break;
  case :
    *(undefined *)(param_1 + 0x25c) = 1;
    *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) | 0x20000000;
    *(undefined *)(param_1 + 0x268) = _od_next_state[*(byte *)(param_1 + 0x25c)];
    *(undefined *)(param_1 + 0x269) = 0x12;
    bVar5 = true;
    if (*piVar2 != 0x4e655854) {
      *(undefined4 *)(param_1 + 0x244) = 1;
    }
    goto loc_4076424;
  case :
    _od_status(param_1,param_2,puVar3,0x2000,9);
    _od_drive_cmd(param_1,param_2,0x5000,9);
    iVar8 = _od_drive_cmd(param_1,param_2,0x5300,6);
    *(undefined *)(param_1 + 0x268) = 0x14;
    return iVar8;
  case :
    *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) & 0xff7fbfff;
    *(undefined *)(param_2 + 0x1d) = 0xff;
    *(undefined2 *)(param_2 + 0x1a) = 0xffff;
    *(word *)(param_2 + 0x18) = *(word *)(param_2 + 0x18) & 0xdfff;
    iVar8 = (int)*(char *)(param_1 + 0x26c);
    goto loc_4076DD4;
  }
loc_4076DE6:
  puVar7 = (uint *)_disksort_first(*(undefined4 *)(iVar4 + 0x18));
  _od_perror(param_1,param_2,8,puVar7[9],*(undefined4 *)(param_1 + 0x238));
  *puVar7 = *puVar7 | 4;
  if ((*(uint *)(param_1 + 0x220) & 0x1000) != 0) {
    puVar3[0xd] = (char)_od_frmr;
    *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) & 0xffffefff;
  }
  if ((uint *)(puVar1 + 0x6a) == puVar7) {
    *(sword *)(puVar1 + 0x86) = (sword)*(char *)(param_1 + 599);
  }
loc_4076E4C:
  iVar8 = sub_4075AC0(iVar4);
  return iVar8;
loc_4075EE6:
  do {
    *(sword *)(param_1 + 0x250) = (sword)((int)uVar14 >> 4);
    *(byte *)(param_1 + 0x252) = ((byte)uVar14 & 0xf) << 1;
    iVar8 = *(int *)(puVar1 + 0xc6);
    if ((*(int *)(iVar8 + *(sword *)(param_1 + 0x250) * 4) >>
         ((int)*(char *)(param_1 + 0x252) & 0x3fU) & 3U) != 1) {
      if (*(sword *)(param_1 + 0x248) == 4) {
        uVar13 = *(uint *)(iVar8 + *(sword *)(param_1 + 0x250) * 4);
        if (3 << ((int)*(char *)(param_1 + 0x252) & 0x3fU) !=
            (3 << ((int)*(char *)(param_1 + 0x252) & 0x3fU) & uVar13)) {
          *(word *)(puVar1 + 0xd8) = *(word *)(puVar1 + 0xd8) | 0x1000;
          if (_od_update_time == 0) {
            _od_update_time = 1;
          }
          uVar13 = ~(3 << ((int)*(char *)(param_1 + 0x252) & 0x3fU)) & uVar13;
          sVar15 = *(sword *)(param_1 + 0x250);
          iVar8 = *(int *)(puVar1 + 0xc6);
          cVar9 = *(char *)(param_1 + 0x252);
          iVar20 = 3;
loc_4075FEE:
          *(uint *)(iVar8 + sVar15 * 4) = iVar20 << ((int)cVar9 & 0x3fU) | uVar13;
        }
      }
      else {
        uVar13 = *(uint *)(iVar8 + *(sword *)(param_1 + 0x250) * 4);
        if (2 << ((int)*(char *)(param_1 + 0x252) & 0x3fU) !=
            (3 << ((int)*(char *)(param_1 + 0x252) & 0x3fU) & uVar13)) {
          *(word *)(puVar1 + 0xd8) = *(word *)(puVar1 + 0xd8) | 0x1000;
          if (_od_update_time == 0) {
            _od_update_time = 1;
          }
          uVar13 = ~(3 << ((int)*(char *)(param_1 + 0x252) & 0x3fU)) & uVar13;
          sVar15 = *(sword *)(param_1 + 0x250);
          iVar8 = *(int *)(puVar1 + 0xc6);
          cVar9 = *(char *)(param_1 + 0x252);
          iVar20 = 2;
          goto loc_4075FEE;
        }
      }
    }
    uVar14 = uVar14 + 1;
  } while ((int)uVar14 < iVar12);
loc_4076424:
  if ((*(char *)(param_1 + 0x25c) == '\x01') && (bVar5)) {
    *(undefined *)(param_1 + 0x25c) = 4;
  }
  bVar10 = *(byte *)(param_1 + 0x25c);
  if (bVar10 == 0xf1) {
    wVar11 = *(word *)(puVar1 + 0xd8);
    if ((wVar11 & 0x1000) == 0) {
      if ((wVar11 & 0x2000) != 0) {
        if ((_rootdev._0_1_ == _od_blk_major) && (puVar1 == _od_vol)) {
          _od_runout_time = (sword)_hz * 0x14;
        }
loc_4076652:
        *(word *)(param_2 + 0x18) = *(word *)(param_2 + 0x18) | 0x400;
        *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) | 0x800000;
        *(undefined2 *)(param_1 + 600) = 0x5600;
        *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) | 0x40000000;
        iVar8 = _od_issue_cmd(param_1,param_2);
        *(undefined *)(param_1 + 0x268) = 7;
        return iVar8;
      }
      goto loc_4076CEC;
    }
    *(word *)(puVar1 + 0xd8) = wVar11 | 0x800;
    _od_update_time = -1;
    _kernel_thread_noblock(_kernel_task,_od_update_thread);
    goto loc_4076D42;
  }
  if (bVar10 < 0xf2) {
    if (bVar10 == 4) {
loc_40764CE:
      *(undefined2 *)(param_1 + 0x262) = 0x4400;
    }
    else if (bVar10 < 5) {
      if (bVar10 == 1) {
        *(undefined2 *)(param_1 + 0x262) = 0x4300;
      }
      else {
        if (bVar10 != 2) goto loc_40766CA;
        *(undefined2 *)(param_1 + 0x262) = 0x4100;
      }
    }
    else {
      if (bVar10 != 8) {
        if (bVar10 == 0xf0) {
          iVar8 = _od_status(param_1,param_2,puVar3,0x2000,9);
          if (iVar8 != -1) {
            *(undefined2 *)(param_1 + 600) = 0x5000;
            *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) | 0x40000000;
            iVar8 = _od_issue_cmd(param_1,param_2);
            if (-1 < iVar8) {
              *(undefined *)(param_1 + 0x268) = 0xd;
              return iVar8;
            }
          }
          goto loc_4076DE6;
        }
        goto loc_40766CA;
      }
      *(undefined2 *)(param_1 + 0x262) = 0x4200;
    }
    if ((*(byte *)(param_2 + 0x18) & 0x20) == 0) {
      *(undefined2 *)(param_1 + 600) = 0x5900;
      *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) | 0x40000000;
      *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) & 0xdfffffff;
      *(undefined *)(param_1 + 0x268) = *(undefined *)(param_1 + 0x267);
      *(word *)(param_2 + 0x18) = *(word *)(param_2 + 0x18) | 0x2000;
    }
    else {
      *(sword *)(param_1 + 0x22e) = *(sword *)(param_1 + 0x22c) - (sword)_od_land;
      *(undefined2 *)(param_1 + 600) = *(undefined2 *)(param_1 + 0x262);
      *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) | 0x40000000;
      *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) & 0xdfffffff;
      *(undefined *)(param_1 + 0x268) = 2;
      *(undefined2 *)(param_2 + 0x1a) = *(undefined2 *)(param_1 + 0x262);
      iVar8 = (int)*(sword *)(*(int *)(param_2 + 0x14) + 0xc);
      if (-1 < iVar8) {
        *(int *)(_dk_seek + iVar8 * 4) = *(int *)(_dk_seek + iVar8 * 4) + 1;
      }
      *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) & 0x7fffffff;
    }
    goto loc_4076E5A;
  }
  if (bVar10 == 0xf4) {
    iVar8 = _od_reset(param_1,param_2,puVar3);
    return iVar8;
  }
  if (bVar10 < 0xf5) {
    if (bVar10 == 0xf2) {
      _od_drive_cmd(param_1,param_2,
                    CONCAT22((sword)(*(int *)(param_1 + 0x230) >> 0x1c),
                             (sword)(*(int *)(param_1 + 0x230) >> 0xc)) | 0xa000,9);
      *(char *)(param_2 + 0x1d) = (char)(*(int *)(param_1 + 0x230) >> 0xc);
      if ((*(byte *)(param_2 + 0x18) & 0x20) == 0) {
        _od_drive_cmd(param_1,param_2,0x5900,9);
        *(word *)(param_2 + 0x18) = *(word *)(param_2 + 0x18) | 0x2000;
      }
      _od_drive_cmd(param_1,param_2,0x2200,10);
      _delay(0x28);
      puVar3[7] = 0;
      puVar3[7] = 0x20;
      do {
      } while ((puVar3[4] & 1) == 0);
      *(word *)(param_1 + 600) = (word)*(undefined4 *)(param_1 + 0x230) & 0xfff;
loc_4076694:
      *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) | 0x40000000;
      iVar8 = _od_issue_cmd(param_1,param_2);
      *(undefined *)(param_1 + 0x268) = 5;
      return iVar8;
    }
    if (bVar10 == 0xf3) {
      *(undefined2 *)(param_1 + 600) = 0x5a00;
      goto loc_4076694;
    }
  }
  else {
    if (bVar10 == 0xf5) {
      *(undefined *)(param_1 + 0x25c) = 4;
      goto loc_40764CE;
    }
    if (bVar10 == 0xf6) goto loc_4076652;
  }
loc_40766CA:
  *(undefined *)(param_1 + 599) = 0xb;
  *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) | 0x4000;
  goto loc_4076DE6;
loc_4076DE0:
  *(undefined *)(param_1 + 599) = 0x36;
  goto loc_4076DE6;
  while( true ) {
    iVar8 = iVar8 + 1;
    uVar14 = uVar14 + 1;
    if (iVar12 <= (int)uVar14) break;
loc_40760BE:
    if ((*(int *)(*(int *)(puVar1 + 0xc6) + ((int)uVar14 >> 4) * 4) >> (uVar14 & 0xf) * 2 & 3U) != 0
       ) break;
  }
loc_40763D2:
  _od_zero_fill(param_1,puVar1,iVar8);
  goto loc_4076D42;
}

