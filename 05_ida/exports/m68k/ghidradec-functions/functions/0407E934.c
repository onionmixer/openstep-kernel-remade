
void sub_407E934(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  int *piVar11;
  undefined4 *puVar12;
  undefined *puVar13;
  undefined *puVar14;
  uint uStack_24;
  int *piStack_20;
  int iStack_1c;
  int iStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  uint uStack_c;
  int iStack_8;
  
  iVar3 = sub_407E802(0x11);
  dword_40B5022 = iVar3;
  sub_407E900(iVar3,7);
  *(uint *)(iVar3 + 8) = *(uint *)(iVar3 + 8) | 2;
  puVar4 = (undefined4 *)_kalloc(0x40);
  iVar5 = 0;
  do {
    puVar12 = puVar4;
    *dword_40B5042 = puVar12;
    puVar12[1] = dword_40B5042;
    *puVar12 = &unk_40B503E;
    iVar5 = iVar5 + 1;
    puVar4 = puVar12 + 4;
    dword_40B5042 = puVar12;
    puVar12 = unk_40B502E;
  } while (iVar5 < 4);
  do {
    while (puVar4 = unk_40B5036, (undefined4 **)puVar12 != &unk_40B502E) {
      piVar11 = (int *)puVar12[2];
      puVar4 = (undefined4 *)*puVar12;
      puVar1 = (undefined4 *)puVar12[1];
      puVar2 = puVar1;
      if ((undefined4 **)puVar4 != &unk_40B502E) {
        puVar4[1] = puVar1;
        puVar2 = dword_40B5032;
      }
      dword_40B5032 = puVar2;
      puVar2 = puVar4;
      if ((undefined4 **)puVar1 != &unk_40B502E) {
        *puVar1 = puVar4;
        puVar2 = unk_40B502E;
      }
      unk_40B502E = puVar2;
      if ((*(byte *)((int)piVar11 + 10) & 2) != 0) {
        iVar5 = *piVar11;
        piVar6 = (int *)_disksort_first(piVar11 + 0x18);
        piVar11[2] = piVar11[2] & 0xfffffdf7U | 1;
        *(undefined2 *)(piVar6 + 7) = 6;
        if (piVar11 + 6 == piVar6) {
          iVar7 = *(int *)(piVar11[0x17] + 0x14);
        }
        else {
          iVar7 = piVar6[5];
        }
        *(undefined *)(iVar5 + 0x10) = 0;
        sub_407DD74(iVar5,iVar7,4,0x10);
      }
      _kfree(puVar12,0x14);
      puVar12 = puVar4;
    }
    while (puVar12 = puVar4, (undefined4 **)puVar12 != &unk_40B5036) {
      piVar11 = (int *)**(int **)puVar12[3];
      puVar4 = (undefined4 *)*puVar12;
      if ((*(int **)puVar12[3])[1] == 0) {
        puVar1 = (undefined4 *)puVar12[1];
        puVar2 = puVar1;
        if ((undefined4 **)puVar4 != &unk_40B5036) {
          puVar4[1] = puVar1;
          puVar2 = dword_40B503A;
        }
        dword_40B503A = puVar2;
        puVar2 = puVar4;
        if ((undefined4 **)puVar1 != &unk_40B5036) {
          *puVar1 = puVar4;
          puVar2 = unk_40B5036;
        }
        unk_40B5036 = puVar2;
        if (((piVar11 != (int *)0x0) && (*(char *)((int)piVar11 + 0xb) < '\0')) && (*piVar11 != 0))
        {
          if (*(sword *)(piVar11 + 3) != 0) {
            _update((int)(sword)((sword)piVar11[1] << 3 | (sword)dword_40B5026 << 8),0xfffffff8);
          }
          sub_407CD5C(piVar11);
          if ((*(sword *)(piVar11 + 3) == 0) && ((*(byte *)((int)piVar11 + 0xb) & 0x40) == 0)) {
            sub_407F330(piVar11);
          }
        }
        piVar11 = (int *)puVar12[3];
        iVar5 = *piVar11;
        *(undefined *)(iVar5 + 0x10) = 4;
        *(int **)(iVar5 + 4) = piVar11;
        sub_407F13E(piVar11,0);
        *dword_40B5042 = puVar12;
        puVar12[1] = dword_40B5042;
        *puVar12 = &unk_40B503E;
        dword_40B5042 = puVar12;
      }
    }
    _lock_write(&unk_40B504A);
    iVar5 = 0;
    if (0 < dword_40B2084) {
      piStack_20 = (int *)unk_40B4FDE;
      puVar14 = _sd_sdd;
      do {
        if (*(int *)puVar14 == 0) {
          uStack_24 = (uint)*_eventc_h;
          uStack_c = CONCAT31((uint3)*_eventc_m | (uint3)((uStack_24 << 0x10) >> 8),*_eventc_l) &
                     0xfffff;
          if ((((uStack_c ^ *_event_middle) & 0x80000) != 0) &&
             (*_event_middle = *_event_middle + 0x80000, (*_event_middle & 0xfff80000) == 0)) {
            *_event_high = *_event_high + 1;
          }
          iStack_8 = *_event_high;
          uStack_c = *_event_middle | uStack_c;
          uStack_14 = *(undefined4 *)((int)puVar14 + 0xb6);
          uStack_10 = *(undefined4 *)((int)puVar14 + 0xba);
          _ts_add(&uStack_14,3000000);
          iVar7 = _ts_greater(&uStack_14,&uStack_c);
          if (iVar7 == 0) {
            byte_40C5E44 = *(undefined *)(*(int *)((int)puVar14 + 8) + 0x1c);
            byte_40C5E45 = *(undefined *)(*(int *)((int)puVar14 + 8) + 0x1d);
            _bcopy(*(undefined4 *)((int)puVar14 + 0xb2),dword_40C6478,0x42);
            dword_40B5056._0_2_ = *(undefined2 *)(*(int *)(*(int *)((int)puVar14 + 8) + 0x10) + 4);
            dword_40B5056._2_2_ = *(undefined2 *)(*(int *)(*(int *)((int)puVar14 + 8) + 0x10) + 6);
            iVar7 = sub_407CCEE(iVar3,0);
            if (iVar7 == 0) {
              if ((*(uint *)((int)puVar14 + 0xc) & 2) != 0) {
                *(uint *)((int)puVar14 + 0xc) = *(uint *)((int)puVar14 + 0xc) & 0xfffffffd;
                if (-1 < *(int *)((int)puVar14 + 0xbe)) {
                  _vol_panel_remove(*(int *)((int)puVar14 + 0xbe));
                  *(undefined4 *)((int)puVar14 + 0xbe) = 0xffffffff;
                }
              }
            }
            else if ((*(byte *)((int)puVar14 + 0xf) & 2) == 0) {
              sub_407C894(iVar3,0);
              iVar7 = *(int *)((int)puVar14 + 4);
              if (iVar7 == 0) {
                iVar10 = 0;
                puVar13 = unk_40B4FDE;
                do {
                  iVar7 = *(int *)puVar13;
                  if ((((iVar7 != 0) && (*(char *)(iVar7 + 0xb) < '\0')) &&
                      (iVar8 = sub_407EFCE(iVar3,iVar7), iVar8 == 0)) &&
                     ((*(byte *)(iVar7 + 0xb) & 2) == 0)) goto loc_407EE6C;
                  puVar13 = (undefined *)((int)puVar13 + 4);
                  iVar10 = iVar10 + 1;
                } while (iVar10 < 0x10);
                iVar7 = *piStack_20;
                if ((char)*(uint *)(iVar7 + 8) < '\0') {
                  if (dword_40B2084 < 0x10) {
                    piVar11 = (int *)(unk_40B4FDE + dword_40B2084 * 4);
                    iVar7 = dword_40B2084;
                    do {
                      if (*piVar11 == 0) {
                        uVar9 = sub_407E802(iVar7);
                        *(undefined4 *)(unk_40B4FDE + iVar7 * 4) = uVar9;
                        sub_407F042(iVar3,uVar9);
                        sub_407F0A8(uVar9,puVar14);
                        sub_407F250(uVar9);
                        goto loc_407EEF4;
                      }
                      piVar11 = piVar11 + 1;
                      iVar7 = iVar7 + 1;
                    } while (iVar7 < 0x10);
                  }
                  _printf(aSdVolCheckNoFr);
                  sub_407CD5C(iVar3);
                  sub_407E900(iVar3,7);
                  *(uint *)(iVar3 + 8) = *(uint *)(iVar3 + 8) | 2;
                }
                else {
                  *(uint *)(iVar7 + 8) = *(uint *)(iVar7 + 8) | 0x80;
                  sub_407F042(iVar3,iVar7);
                  sub_407F0A8(iVar7,puVar14);
                  sub_407F250(iVar7);
                }
              }
              else if ((*(byte *)(iVar7 + 0xb) & 0x40) == 0) {
                iVar10 = sub_407EFCE(iVar3,iVar7);
                if (iVar10 == 0) {
loc_407EE6C:
                  sub_407F0A8(iVar7,puVar14);
                }
                else {
                  sub_407CD5C(iVar3);
                  sub_407E900(iVar3,7);
                  *(uint *)(iVar3 + 8) = *(uint *)(iVar3 + 8) | 2;
loc_407EDD0:
                  if ((*(byte *)(iVar7 + 0xb) & 8) != 0) {
                    _vol_panel_remove(*(undefined4 *)(iVar7 + 0x12));
                    sub_407F13E(iVar7,1);
                  }
                }
              }
              else {
                iVar10 = 0;
                do {
                  if (((*(int *)(unk_40B4FDE + iVar10 * 4) != 0) && (iVar10 != *(int *)(iVar7 + 4)))
                     && (iVar8 = sub_407EFCE(iVar3,*(int *)(unk_40B4FDE + iVar10 * 4)), iVar8 == 0))
                  {
                    sub_407CD5C(iVar3);
                    sub_407E900(iVar3,7);
                    *(uint *)(iVar3 + 8) = *(uint *)(iVar3 + 8) | 2;
                    goto loc_407EDD0;
                  }
                  iVar10 = iVar10 + 1;
                } while (iVar10 < 0x10);
                sub_407F042(iVar3,iVar7);
                sub_407F0A8(iVar7,puVar14);
              }
            }
            else if (*(int *)((int)puVar14 + 0xbe) < 0) {
              _vol_panel_request(0,6,1,0,2,(int)((int)puVar14 + -0x40c5e78) * 0x5f02a3a1 >> 1,0,
                                 &unk_40A62E7,&unk_40A62E7,0,(int)puVar14 + 0xbe);
            }
          }
        }
loc_407EEF4:
        piStack_20 = piStack_20 + 1;
        puVar14 = (undefined *)((int)puVar14 + 0xc2);
        iVar5 = iVar5 + 1;
      } while (iVar5 < dword_40B2084);
    }
    _lock_done(&unk_40B504A);
    if (dword_40B207C < 1000000) {
      iStack_1c = 0;
      iStack_18 = dword_40B207C;
    }
    else {
      iStack_1c = dword_40B207C / 1000000;
      iStack_18 = dword_40B207C % 1000000;
    }
    dword_40B5046 = 0;
    _us_timeout(&loc_407EFAE,0,&iStack_1c,0);
    while (puVar12 = unk_40B502E, dword_40B5046 == 0) {
      _assert_wait(&dword_40B5046,0);
      _thread_block();
    }
  } while( true );
}
