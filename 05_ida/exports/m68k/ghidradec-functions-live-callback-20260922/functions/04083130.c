
uint _dspq_execute(void)

{
  undefined4 uVar1;
  int *piVar2;
  char *pcVar3;
  sword *psVar4;
  undefined4 *puVar5;
  sword sVar6;
  undefined uVar7;
  undefined uVar8;
  byte *pbVar9;
  byte bVar10;
  char cVar11;
  uint3 uVar12;
  uint3 uVar13;
  uint uVar14;
  int *piVar15;
  uint3 *puVar16;
  uint uVar17;
  int iVar18;
  uint unaff_D4;
  int *piVar19;
  int iVar20;
  uint3 *puVar21;
  uint *puVar22;
  bool bVar23;
  code *pcVar24;
  
  bVar23 = false;
  uVar17 = _curipl();
  uVar14 = dword_40B21C8;
  if (uVar17 != dword_40B21C8) {
    dword_40B21C8 = _curipl();
    if (_cpu_type == '\0') {
      uVar17 = *(uint *)(_slot_id_bmap + 0x2008000);
    }
    else {
      uVar17 = unaff_D4 & 0xff | (uint)*(byte *)(_slot_id_bmap + 0x2008000) << 0x18 |
               (uint)*(byte *)(_slot_id_bmap + 0x2008001) << 0x10 |
               (uint)*(byte *)(_slot_id_bmap + 0x2008002) << 8;
    }
    if ((dword_40C6E72 != 0) && ((dword_40C6E6A & uVar17) == dword_40C6E6E)) {
      _callout_dispatch(4,sub_4083CCA,dword_40C6E72);
      dword_40C6E72 = 0;
    }
    if ((int **)dword_40C6E46 != &dword_40C6E46) {
      do {
        iVar18 = _dspq_check();
        piVar15 = dword_40C6E46;
        if (iVar18 == 0) break;
        piVar2 = (int *)dword_40C6E46[6];
        piVar19 = piVar2;
        if ((int **)piVar2 != &dword_40C6E46) {
          piVar2[7] = (int)&dword_40C6E46;
          piVar19 = dword_40C6E4A;
        }
        dword_40C6E4A = piVar19;
        switch(*dword_40C6E46) {
        case :
          if (dword_40C6E46[3] != 0) {
            if (_cpu_type == '\0') {
              iVar18 = *(int *)(_slot_id_bmap + 0x2008000);
            }
            else {
              iVar18 = (uint)(uint3)((uint3)(((uint)*(byte *)(_slot_id_bmap + 0x2008000) << 0x18) >>
                                            8) |
                                     (uint3)(((uint)*(byte *)(_slot_id_bmap + 0x2008001) << 0x10) >>
                                            8) | (uint3)*(byte *)(_slot_id_bmap + 0x2008002)) << 8;
            }
            piVar19 = dword_40C6E46 + 5;
            dword_40C6E46 = piVar2;
            *piVar19 = iVar18;
            pcVar24 = _snd_reply_dsp_cond_true;
            piVar19 = piVar15;
            goto loc_40838DC;
          }
          break;
        case :
          iVar18 = dword_40C6E46[2] - (dword_40C6E46[3] - dword_40C6E46[1]);
          dword_40C6E46 = piVar2;
          for (; 0 < iVar18; iVar18 = iVar18 + -1) {
            pcVar3 = (char *)piVar15[3];
            piVar15[3] = (int)(pcVar3 + 1);
            cVar11 = *pcVar3;
            iVar20 = 0x32;
            bVar10 = *(byte *)(_slot_id_bmap + 0x2008002);
            while ((bVar10 & 2) == 0) {
              _delay(2);
              iVar20 = iVar20 + -1;
              if (iVar20 == 0) goto loc_4083360;
              bVar10 = *(byte *)(_slot_id_bmap + 0x2008002);
            }
            if (iVar20 != 0) {
              if (_cpu_type == '\0') {
                *(int *)(_slot_id_bmap + 0x2008004) = (int)cVar11;
              }
              else {
                *(char *)(_slot_id_bmap + 0x2008005) = (char)cVar11 >> 7;
                *(char *)(_slot_id_bmap + 0x2008006) = cVar11 >> 7;
                *(char *)(_slot_id_bmap + 0x2008007) = cVar11;
              }
            }
loc_4083360:
            if (iVar20 == 0) break;
          }
          piVar2 = dword_40C6E46;
          if (iVar18 != 0) {
            piVar15[3] = piVar15[3] + -1;
loc_40835B6:
            *(byte *)(_slot_id_bmap + 0x2008000) = *(byte *)(_slot_id_bmap + 0x2008000) | 2;
loc_408395E:
            bVar10 = *(byte *)((int)piVar15 + 0x21);
            if (bVar10 != 2) {
              if (bVar10 < 3) {
                *(byte *)((int)piVar15 + 0x21) = bVar10 | 4;
              }
              else if (bVar10 != 3) goto loc_408398E;
              *(undefined *)((int)piVar15 + 0x21) = 5;
            }
            *(undefined *)((int)piVar15 + 0x21) = 4;
loc_408398E:
            bVar23 = dword_40C6E46 < &dword_40C6E46;
            if ((int **)dword_40C6E46 == &dword_40C6E46) {
              dword_40C6E4A = piVar15;
            }
            else {
              dword_40C6E46[7] = (int)piVar15;
            }
            piVar15[6] = (int)dword_40C6E46;
            piVar15[7] = (int)&dword_40C6E46;
            dword_40B21C8 = uVar14;
            dword_40C6E46 = piVar15;
            return (uint)(byte)(bVar23 << 4 | ((int)piVar15 < 0) << 3 | (piVar15 == (int *)0x0) << 2
                               );
          }
          break;
        case :
          uVar17 = (uint)(dword_40C6E46[2] - (dword_40C6E46[3] - dword_40C6E46[1])) >> 1;
          dword_40C6E46 = piVar2;
          if (uVar17 != 0) {
            do {
              psVar4 = (sword *)piVar15[3];
              piVar15[3] = (int)(psVar4 + 1);
              sVar6 = *psVar4;
              iVar18 = 0x32;
              bVar10 = *(byte *)(_slot_id_bmap + 0x2008002);
              while ((bVar10 & 2) == 0) {
                _delay(2);
                iVar18 = iVar18 + -1;
                if (iVar18 == 0) goto loc_408341C;
                bVar10 = *(byte *)(_slot_id_bmap + 0x2008002);
              }
              if (iVar18 != 0) {
                if (_cpu_type == '\0') {
                  *(int *)(_slot_id_bmap + 0x2008004) = (int)sVar6;
                }
                else {
                  cVar11 = (char)((word)sVar6 >> 8);
                  *(char *)(_slot_id_bmap + 0x2008005) = cVar11 >> 7;
                  *(char *)(_slot_id_bmap + 0x2008006) = cVar11;
                  *(char *)(_slot_id_bmap + 0x2008007) = (char)sVar6;
                }
              }
loc_408341C:
            } while ((iVar18 != 0) && (uVar17 = uVar17 - 1, 0 < (int)uVar17));
          }
          piVar2 = dword_40C6E46;
          if (uVar17 != 0) {
            piVar15[3] = piVar15[3] + -2;
            goto loc_40835B6;
          }
          break;
        case :
          iVar18 = dword_40C6E46[2] - (dword_40C6E46[3] - dword_40C6E46[1]);
          puVar16 = (uint3 *)dword_40C6E46[3];
          dword_40C6E46 = piVar2;
          if (0 < iVar18) {
            do {
              puVar21 = puVar16;
              uVar7 = *(undefined *)puVar21;
              uVar8 = *(undefined *)((int)puVar21 + 1);
              uVar13 = *puVar21;
              uVar12 = *puVar21;
              iVar20 = 0x32;
              bVar10 = *(byte *)(_slot_id_bmap + 0x2008002);
              while ((bVar10 & 2) == 0) {
                _delay(2);
                iVar20 = iVar20 + -1;
                if (iVar20 == 0) goto loc_40834E4;
                bVar10 = *(byte *)(_slot_id_bmap + 0x2008002);
              }
              if (iVar20 != 0) {
                if (_cpu_type == '\0') {
                  *(uint *)(_slot_id_bmap + 0x2008004) = (uint)uVar12;
                }
                else {
                  *(undefined *)(_slot_id_bmap + 0x2008005) = uVar7;
                  *(undefined *)(_slot_id_bmap + 0x2008006) = uVar8;
                  *(char *)(_slot_id_bmap + 0x2008007) = (char)uVar13;
                }
              }
loc_40834E4:
            } while ((iVar20 != 0) &&
                    (iVar18 = iVar18 + -3, puVar16 = (uint3 *)((int)puVar21 + 3), 0 < iVar18));
            piVar2 = dword_40C6E46;
            if (0 < iVar18) {
              piVar15[3] = (int)((int)puVar21 + 2);
              goto loc_40835B6;
            }
          }
          break;
        case :
          uVar17 = (uint)(dword_40C6E46[2] - (dword_40C6E46[3] - dword_40C6E46[1])) >> 2;
          dword_40C6E46 = piVar2;
          if (uVar17 != 0) {
            do {
              puVar5 = (undefined4 *)piVar15[3];
              piVar15[3] = (int)(puVar5 + 1);
              uVar1 = *puVar5;
              iVar18 = 0x32;
              bVar10 = *(byte *)(_slot_id_bmap + 0x2008002);
              while ((bVar10 & 2) == 0) {
                _delay(2);
                iVar18 = iVar18 + -1;
                if (iVar18 == 0) goto loc_40835A0;
                bVar10 = *(byte *)(_slot_id_bmap + 0x2008002);
              }
              if (iVar18 != 0) {
                if (_cpu_type == '\0') {
                  *(undefined4 *)(_slot_id_bmap + 0x2008004) = uVar1;
                }
                else {
                  *(char *)(_slot_id_bmap + 0x2008005) = (char)((uint)uVar1 >> 0x10);
                  *(char *)(_slot_id_bmap + 0x2008006) = (char)((uint)uVar1 >> 8);
                  *(char *)(_slot_id_bmap + 0x2008007) = (char)uVar1;
                }
              }
loc_40835A0:
            } while ((iVar18 != 0) && (uVar17 = uVar17 - 1, 0 < (int)uVar17));
          }
          piVar2 = dword_40C6E46;
          if (uVar17 != 0) {
            piVar15[3] = piVar15[3] + -4;
            goto loc_40835B6;
          }
          break;
        case :
        case :
          word_40C6E40._1_1_ = *(byte *)((int)dword_40C6E46 + 0xe);
          iVar18 = (&unk_40C6DF4)[(byte)word_40C6E40];
          word_40C6E40._0_1_ = 0;
          dword_40C6E42 = dword_40C6E46[1];
          piVar19 = dword_40C6E46 + 2;
          dword_40C6E46 = piVar2;
          *(undefined2 *)(iVar18 + 0x4e) = *(undefined2 *)piVar19;
          *(undefined2 *)(iVar18 + 0x50) = *(undefined2 *)((int)piVar15 + 10);
          *(undefined *)(iVar18 + 0x52) = *(undefined *)(piVar15 + 3);
          *(undefined *)(iVar18 + 0x53) = *(undefined *)((int)piVar15 + 0xd);
          if (*piVar15 == 5) {
            dword_40C6E76 = 4;
          }
          else {
            word_40C6E7A = 1;
          }
          piVar2 = dword_40C6E46;
          if ((int *)(iVar18 + 0x3e) != *(int **)(iVar18 + 0x3e)) {
            *(byte *)(_slot_id_bmap + 0x2008000) = *(byte *)(_slot_id_bmap + 0x2008000) | 2;
            piVar2 = dword_40C6E46;
          }
          break;
        case :
          pbVar9 = (byte *)((int)dword_40C6E46 + 7);
          dword_40C6E46 = piVar2;
          *(byte *)(_slot_id_bmap + 0x2008001) = *pbVar9 | 0x80;
          piVar2 = dword_40C6E46;
          break;
        case :
          uVar17 = dword_40C6E46[2] |
                   ~dword_40C6E46[1] &
                   ((uint)*(byte *)(_slot_id_bmap + 0x2008000) << 0x18 |
                   (uint)*(byte *)(_slot_id_bmap + 0x2008001) << 0x10);
          dword_40C6E46 = piVar2;
          *(char *)(_slot_id_bmap + 0x2008000) = (char)(uVar17 >> 0x18);
          *(char *)(_slot_id_bmap + 0x2008001) = (char)(uVar17 >> 0x10);
          cVar11 = *(char *)(_slot_id_bmap + 0x2008000);
          while (piVar2 = dword_40C6E46, cVar11 < '\0') {
            _delay(1);
            cVar11 = *(char *)(_slot_id_bmap + 0x2008000);
          }
          break;
        case :
          pcVar24 = sub_4083CCA;
          dword_40C6E46 = piVar2;
          goto loc_4083918;
        case :
          dword_40C6E46 = piVar2;
          _dsp_dev_reset_chip();
          _delay(2);
          if (((dword_40C6E84 & 0x2c00) != 0) ||
             (piVar2 = dword_40C6E46, (dword_40C6E84 & 0x100) == 0)) {
            *(undefined *)(_slot_id_bmap + 0x2008000) = 1;
            piVar2 = dword_40C6E46;
          }
          break;
        case :
          if (_cpu_type == '\0') {
            piVar19 = *(int **)(_slot_id_bmap + 0x2008000);
          }
          else {
            piVar19 = (int *)CONCAT31((uint3)(((uint)*(byte *)(_slot_id_bmap + 0x2008000) << 0x18)
                                             >> 8) |
                                      (uint3)(((uint)*(byte *)(_slot_id_bmap + 0x2008001) << 0x10)
                                             >> 8) | (uint3)*(byte *)(_slot_id_bmap + 0x2008002),
                                      *(undefined *)(_slot_id_bmap + 0x2008003));
          }
          pcVar24 = _snd_reply_dsp_regs;
          dword_40C6E46 = piVar2;
loc_40838DC:
          _callout_dispatch(4,pcVar24,piVar19);
          piVar2 = dword_40C6E46;
          break;
        case :
          dword_40C6E76 = dword_40C6E46[1];
          break;
        case :
        case :
        case :
        case :
          iVar18 = *dword_40C6E46;
          if (iVar18 == 0xd) {
            uVar17 = 1;
          }
          else if (iVar18 == 0xe) {
            uVar17 = 2;
          }
          else {
            uVar17 = 4;
            if (iVar18 == 0xf) {
              uVar17 = 3;
            }
          }
          puVar22 = (uint *)dword_40C6E46[3];
          iVar18 = dword_40C6E46[2] - ((int)puVar22 - dword_40C6E46[1]);
          dword_40C6E46 = piVar2;
          for (; 0 < iVar18; iVar18 = iVar18 - uVar17) {
            iVar20 = 0x19;
            bVar10 = *(byte *)(_slot_id_bmap + 0x2008002);
            while ((bVar10 & 1) == 0) {
              _delay(1);
              iVar20 = iVar20 + -1;
              if (iVar20 == 0) goto loc_408372A;
              bVar10 = *(byte *)(_slot_id_bmap + 0x2008002);
            }
            if (iVar20 != 0) {
              if (_cpu_type == '\0') {
                if (uVar17 == 2) {
                  *(sword *)puVar22 = (sword)*(undefined4 *)(_slot_id_bmap + 0x2008004);
                }
                else {
                  if (uVar17 < 3) {
                    if (uVar17 == 1) {
                      *(undefined *)puVar22 = *(undefined *)(_slot_id_bmap + 0x2008007);
                      goto loc_408372A;
                    }
                  }
                  else if (uVar17 == 3) goto loc_40836F2;
                  *puVar22 = *(uint *)(_slot_id_bmap + 0x2008004) & 0xffffff;
                }
              }
              else if (uVar17 == 2) {
                *(undefined2 *)puVar22 = *(undefined2 *)(_slot_id_bmap + 0x2008006);
              }
              else if (uVar17 < 3) {
                if (uVar17 == 1) {
                  *(undefined *)puVar22 = *(undefined *)(_slot_id_bmap + 0x2008007);
                }
                else {
loc_408366C:
                  *puVar22 = CONCAT31((uint3)*(byte *)(_slot_id_bmap + 0x2008006) |
                                      (uint3)(((uint)*(byte *)(_slot_id_bmap + 0x2008005) << 0x10)
                                             >> 8),*(undefined *)(_slot_id_bmap + 0x2008007));
                }
              }
              else {
                if (uVar17 != 3) goto loc_408366C;
loc_40836F2:
                *(undefined *)puVar22 = *(undefined *)(_slot_id_bmap + 0x2008005);
                *(undefined *)((int)puVar22 + 1) = *(undefined *)(_slot_id_bmap + 0x2008006);
                *(undefined *)((int)puVar22 + 2) = *(undefined *)(_slot_id_bmap + 0x2008007);
              }
            }
loc_408372A:
            if (iVar20 == 0) break;
            puVar22 = (uint *)(uVar17 + (int)puVar22);
          }
          piVar15[3] = (int)puVar22;
          if (iVar18 != 0) goto loc_408395E;
          bVar23 = true;
          piVar2 = dword_40C6E46;
          break;
        case :
          piVar19 = dword_40C6E46 + 1;
          dword_40C6E46 = piVar2;
          _dsp_dev_new_proto(*piVar19);
          piVar2 = dword_40C6E46;
        }
        dword_40C6E46 = piVar2;
        if (bVar23) {
          if (piVar15[4] == 0) {
            bVar23 = false;
            goto loc_4083938;
          }
          iVar18 = _curipl();
          if (iVar18 == 0) {
            sub_4083A7A(piVar15);
          }
          else {
            pcVar24 = sub_4083A7A;
loc_4083918:
            _callout_dispatch(4,pcVar24,piVar15);
          }
        }
        else {
loc_4083938:
          _dspq_free_msg(piVar15);
        }
      } while ((int **)dword_40C6E46 != &dword_40C6E46);
    }
    if ((((int **)dword_40C6E46 == &dword_40C6E46) || (*(byte *)((int)dword_40C6E46 + 0x21) < 2)) ||
       ((dword_40C6E46[8] & 0x4ff00U) == 0)) {
      uVar17 = dword_40C6E84;
      if ((((dword_40C6E84 & 0x10000) != 0) && (dword_40C6DFC != 0)) &&
         (dword_40C6DFC + 0x3e != *(int *)(dword_40C6DFC + 0x3e))) {
        iVar18 = 0x28;
        do {
          if ((*(byte *)(_slot_id_bmap + 0x2008002) & 2) != 0) break;
          _delay(1);
          iVar18 = iVar18 + -1;
        } while (iVar18 != 0);
        uVar17 = (uint)*(byte *)(_slot_id_bmap + 0x2008002);
        if ((*(byte *)(_slot_id_bmap + 0x2008002) & 2) != 0) {
          uVar17 = sub_4084026(dword_40C6DFC);
        }
      }
    }
    else {
      uVar17 = (uint)(byte)((*(byte *)((int)dword_40C6E46 + 0x21) == 0) << 4);
    }
  }
  dword_40B21C8 = uVar14;
  return uVar17;
}

