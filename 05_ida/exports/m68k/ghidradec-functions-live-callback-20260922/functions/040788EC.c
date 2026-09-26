
int _od_read_label(undefined4 param_1,int param_2,int param_3)

{
  uint uVar1;
  undefined2 uVar2;
  word wVar3;
  int iVar4;
  bool bVar5;
  undefined4 uVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint *puVar11;
  undefined4 uVar12;
  int iVar13;
  sword sVar14;
  int iVar15;
  undefined *puVar16;
  int *unaff_A3;
  undefined *puVar17;
  undefined *puVar18;
  undefined auStack_32 [7];
  char acStack_2b [39];
  
  uVar12 = _od_readlabel;
  bVar5 = false;
  if (_od_empty < 1) {
    puVar17 = _od_vol;
    do {
      if (-1 < *(sword *)(puVar17 + 0xd8)) break;
      puVar17 = puVar17 + 0xda;
    } while (puVar17 < (undefined *)0x40c592e);
    if (puVar17 == (undefined *)0x40c592e) {
                    /* WARNING: Subroutine does not return */
      _panic(aOdOutOfVols);
    }
  }
  else {
    puVar17 = DAT_40c3dee + _od_empty * 0xda;
  }
  _disksort_free(puVar17);
  _bzero(puVar17,0xda);
  _disksort_init(puVar17);
  *(undefined2 *)(puVar17 + 0xd8) = 0x8020;
  *(sword *)(puVar17 + 0xd2) = (sword)(param_2 + -0x40c3e18 >> 5);
  *(undefined **)(param_2 + 8) = puVar17;
  uVar6 = _od_errmsg_filter;
  iVar13 = ((int)(puVar17 + -0x40c3ec8) * -0x2593f69b >> 1) << 3;
  if (_inhibit_label_errs != 0) {
    _od_errmsg_filter = 9;
  }
  iVar4 = *(char *)(param_2 + 0x1c) * 0x30;
  *(undefined **)(puVar17 + 0xb6) = _od_drive_info + iVar4;
  iVar10 = *(char *)(param_2 + 0x1c) * 6;
  *(int **)(puVar17 + 0xba) = (int *)((int)&_od_more_info + iVar10);
  iVar15 = 0;
  do {
    piVar7 = _od_label;
    iVar9 = *(int *)(DAT_40b1f72 + iVar15 * 4 + iVar4);
    puVar16 = puVar17;
    if (iVar9 != -1) {
      *(int **)(puVar17 + 0xae) = _od_label;
      if (piVar7 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
        _panic(aOdNoLabelAlloc);
      }
      _bzero(piVar7,0x1c48);
      *(int *)(puVar17 + 0xbe) =
           *(int *)((int)&_od_more_info + iVar10) *
           (int)*(sword *)((int)&_od_more_info + iVar10 + 4);
      piVar7[0x17] = *(int *)(DAT_40b1f72 + iVar4 + 0x10);
      piVar7[0x19] = (int)*(sword *)((int)&_od_more_info + iVar10 + 4);
      piVar7[0x18] = 1;
      *(word *)(puVar17 + 0xd8) = *(word *)(puVar17 + 0xd8) | 0x2000;
      if ((*(byte *)(param_2 + 0x18) & 0x40) == 0) {
        _od_spinup = 1;
        iVar8 = _od_cmd(iVar13,0xf0,0,0,0,acStack_2b,0,0,0,0);
        if (iVar8 == 5) {
          if ((byte)(acStack_2b[0] - 0x3aU) < 2) {
            *(word *)(puVar17 + 0xd8) = *(word *)(puVar17 + 0xd8) & 0xdfff;
            if (param_3 != 0) {
              *(word *)(param_2 + 0x18) = *(word *)(param_2 + 0x18) | 0x1000;
            }
            goto loc_4078DFE;
          }
          if ((acStack_2b[0] == '\x14') || (acStack_2b[0] == '\b')) {
            *(word *)(puVar17 + 0xd8) = *(word *)(puVar17 + 0xd8) & 0xdfff;
            *(word *)(param_2 + 0x18) = *(word *)(param_2 + 0x18) | 0x1000;
            goto loc_4078DFE;
          }
        }
        if (iVar8 != 0) {
          *(word *)(puVar17 + 0xd8) = *(word *)(puVar17 + 0xd8) & 0xdfff;
          *(word *)(param_2 + 0x18) = *(word *)(param_2 + 0x18) | 0x1000;
          goto loc_4078E00;
        }
      }
      *(word *)(param_2 + 0x18) = *(word *)(param_2 + 0x18) | 0x5000;
      iVar8 = _od_cmd(iVar13,2,iVar9,uVar12,0x1c48,acStack_2b,0,0,0,0);
      unaff_A3 = piVar7;
      if (iVar8 == 0) {
        iVar8 = _od_validate_label(uVar12,iVar9);
        if (iVar8 == 0) {
          _bcopy(uVar12,piVar7,0x1c48);
          if ((*piVar7 != 0x4e655854) && (1 < *piVar7 + 0x9b93a9ceU)) {
            iVar8 = 0x16;
            goto loc_4078E00;
          }
          if ((int)*(sword *)((int)&_od_more_info + iVar10 + 4) == piVar7[0x19]) {
            *(undefined4 *)(puVar17 + 0xb2) = _od_bad_block;
            if (((*piVar7 == 0x4e655854) || (*piVar7 == 0x646c5632)) ||
               (iVar8 = _od_cmd(iVar13,2,iVar9 + 4,_od_bad_block,0x3000,0,0,0,0,0), iVar8 == 0)) {
              iVar8 = piVar7[0x19] * piVar7[0x18] * piVar7[0x1a];
              *(int *)(puVar17 + 0xc2) = iVar8;
              if (*piVar7 == 0x4e655854) {
                iVar8 = iVar8 / piVar7[0x19] >> 1;
              }
              else {
                iVar8 = iVar8 >> 2;
              }
              *(int *)(puVar17 + 0xca) = iVar8;
              *(undefined4 *)(puVar17 + 0xc6) = _od_bitmap;
              iVar9 = _od_cmd(iVar13,2,piVar7[0x19] + iVar9,_od_bitmap,
                              *(undefined4 *)(puVar17 + 0xca),0,0,0,0,0);
              if (iVar9 == 0) {
                iVar10 = (int)*(sword *)(*(int *)(param_2 + 0x14) + 0xc);
                if (-1 < iVar10) {
                  *(int *)(_dk_bps + iVar10 * 4) =
                       (piVar7[0x1b] * piVar7[0x19] * piVar7[0x17]) / 0x3c;
                }
                if (param_3 == 0) {
                  if (*piVar7 == 0x4e655854) {
                    uVar12 = 1;
                  }
                  else {
                    uVar12 = 3;
                    if (*piVar7 == 0x646c5632) {
                      uVar12 = 2;
                    }
                  }
                  _printf(aDiskLabelSLabe,piVar7 + 3,uVar12);
                  _od_canon_label(param_1,param_2,puVar17);
                }
                puVar16 = _od_vol;
                goto loc_4078CE4;
              }
            }
          }
        }
      }
      else if (_dma_recover_rl != 0) {
        _od_cmd(iVar13,2,0,uVar12,0x400,acStack_2b,0,0,0,0);
      }
    }
    iVar15 = iVar15 + 1;
  } while (iVar15 < 4);
  if ((*(byte *)(param_2 + 0x18) & 0x40) == 0) goto loc_4078DFE;
  *(word *)(puVar17 + 0xd8) = *(word *)(puVar17 + 0xd8) | 0x2000;
  iVar10 = unaff_A3[0x19] * unaff_A3[0x18] * unaff_A3[0x1a];
  *(int *)(puVar17 + 0xc2) = iVar10;
  if (*unaff_A3 == 0x4e655854) {
    iVar10 = iVar10 / unaff_A3[0x19] >> 1;
  }
  else {
    iVar10 = iVar10 >> 2;
  }
  *(int *)(puVar17 + 0xca) = iVar10;
  *(undefined4 *)(puVar17 + 0xb2) = _od_bad_block;
  _bzero(_od_bad_block,0x3000);
  *(undefined4 *)(puVar17 + 0xc6) = _od_bitmap;
  _bzero(_od_bitmap,*(undefined4 *)(puVar17 + 0xca));
  iVar10 = _rtc_get();
  unaff_A3[10] = iVar10;
  unaff_A3[9] = -0x80000000;
  *unaff_A3 = 0x646c5633;
  iVar10 = _od_write_label(puVar17,0);
  if (iVar10 == 0) {
    *(word *)(puVar17 + 0xd8) = *(word *)(puVar17 + 0xd8) | 0x4000;
    goto loc_407901E;
  }
loc_4078DDE:
  iVar8 = 5;
  puVar16 = puVar17;
  goto loc_4078E00;
  while (puVar16 = puVar16 + 0xda, puVar16 < (undefined *)0x40c592e) {
loc_4078CE4:
    if (((puVar16[0xd8] & 0x40) != 0) && (*(int *)(*(int *)(puVar16 + 0xae) + 0x28) == piVar7[10]))
    {
      *(undefined2 *)(puVar17 + 0xd8) = 0;
      *(sword *)(puVar16 + 0xd2) = (sword)(param_2 + -0x40c3e18 >> 5);
      *(undefined **)(param_2 + 8) = puVar16;
      *(word *)(puVar16 + 0xd8) = *(word *)(puVar16 + 0xd8) | 0x2000;
      iVar13 = ((int)(puVar16 + -0x40c3ec8) * -0x2593f69b >> 1) << 3;
      bVar5 = true;
      goto loc_407901E;
    }
  }
  iVar15 = _rtc_get();
  iVar10 = piVar7[10];
  piVar7[10] = iVar15;
  *(word *)(puVar17 + 0xd8) = *(word *)(puVar17 + 0xd8) | 0x6000;
  iVar15 = _od_write_label(puVar17,0);
  puVar16 = puVar17;
  if (iVar15 != 0) {
    if (iVar15 != 0x13) goto loc_4078DDE;
    piVar7[10] = iVar10;
    *(word *)(puVar17 + 0xd8) = *(word *)(puVar17 + 0xd8) | 4;
  }
loc_407901E:
  iVar8 = 0;
  if (_od_empty < 1) {
    if ((_od_specific == (undefined *)0x0) ||
       ((*(int *)(puVar16 + 0xae) != 0 && (puVar16 == _od_specific)))) {
      if (!bVar5) {
        iVar13 = (int)(puVar16 + -0x40c3ec8) * -0x2593f69b >> 1;
        _sprintf(auStack_32,&aOdD,iVar13);
        uVar12 = 1;
        if ((puVar16[0xd9] & 4) != 0) {
          uVar12 = 3;
        }
        wVar3 = (sword)iVar13 << 3;
        _vol_notify_dev((int)(sword)(wVar3 | (sword)_od_blk_major << 8),
                        (int)(sword)(wVar3 | (sword)_od_raw_major << 8),&unk_40A62E7,
                        CARRY4(*(uint *)(*(int *)(puVar16 + 0xae) + 0x24),
                               *(uint *)(*(int *)(puVar16 + 0xae) + 0x24)),auStack_32,uVar12);
      }
      goto loc_40792AA;
    }
    uVar2 = *(undefined2 *)(puVar16 + 0xd2);
    _od_cmd(iVar13,0xf6,0,0,0,0,0,0,0,0);
    if (((_rootdev >> 8 != _od_blk_major) ||
        ((unk_40C3FA0[(sword)(word)(((uint)_rootdev << 0x18) >> 0x1b) * 0xda] & 0x20) != 0)) &&
       (_panel_req_port != 0)) {
      _vol_panel_remove(_od_vol_tag);
      _vol_panel_disk_label
                (_od_panel_abort,*(int *)(_od_specific + 0xae) + 0xc,1,uVar2,_od_specific,1,
                 &_od_vol_tag);
      goto loc_4079218;
    }
    iVar15 = 0;
    iVar10 = *(int *)(_od_specific + 0xae);
    puVar18 = aWrongDiskPleas_1;
    puVar17 = _od_specific;
  }
  else {
    if (!bVar5) {
      _od_empty = 0;
      _wakeup(&_od_empty);
loc_40792AA:
      if (_od_alert_present == 0) {
        _alert_done();
      }
      else {
        _vol_panel_remove(_od_vol_tag);
        _od_alert_abort = 0;
        _od_alert_present = 0;
      }
      _od_spinup = 0;
      if (_od_requested == 1) {
        _od_specific = (undefined *)0x0;
        _od_requested = 2;
        _wakeup(&_od_requested);
      }
      iVar13 = _hz;
      if (_hz < 0) {
        iVar13 = _hz + 1;
      }
      _od_runout_time = (undefined2)(iVar13 >> 1);
      _od_runout = 0;
      if ((!bVar5) && ((puVar16[0xd8] & 0x40) != 0)) {
        _od_label = (int *)0x0;
        _wakeup(&_od_label);
      }
      sVar14 = (sword)_od_blk_major;
      for (iVar13 = _mounttab; iVar13 != 0; iVar13 = *(int *)(iVar13 + 0x1c)) {
        if ((((word)(*(word *)(iVar13 + 4) & 0xfff8) ==
              (word)((sword)((int)(puVar16 + -0x40c3ec8) * -0x2593f69b >> 1) << 3 | sVar14 << 8)) &&
            (*(int *)(iVar13 + 10) != 0)) &&
           ((*(word *)(iVar13 + 4) != 0xffff &&
            (iVar10 = *(int *)(*(int *)(iVar13 + 10) + 0x20),
            (*(uint *)(iVar10 + 0xd0) & 0xffff00) == 0x10000)))) {
          *(undefined *)(iVar10 + 0xd1) = 2;
          *(undefined *)(iVar10 + 0xd0) = 1;
        }
      }
      *(word *)(param_2 + 0x18) = *(word *)(param_2 + 0x18) | 0x8000;
      *(word *)(puVar16 + 0xd8) = *(word *)(puVar16 + 0xd8) & 0xffbf;
      _od_drive_start(puVar16);
      _od_ctrl_start(*(undefined4 *)(&DAT_40c3e28 + (uint)*(word *)(puVar16 + 0xd2) * 4));
      goto loc_4078FB0;
    }
    uVar2 = *(undefined2 *)(puVar16 + 0xd2);
    _od_cmd(iVar13,0xf6,0,0,0,0,0,0,0,0);
    if (((_rootdev >> 8 != _od_blk_major) ||
        ((unk_40C3FA0[(sword)(word)(((uint)_rootdev << 0x18) >> 0x1b) * 0xda] & 0x20) != 0)) &&
       (_panel_req_port != 0)) {
      iVar10 = _od_empty * 0xda;
      _vol_panel_remove(_od_vol_tag);
      _vol_panel_disk_num(_od_panel_abort,_od_empty + -1,1,uVar2,DAT_40c3dee + iVar10,1,&_od_vol_tag
                         );
loc_4079218:
      _od_alert_present = 1;
      goto loc_4078DFE;
    }
    iVar15 = _od_empty + -1;
    iVar10 = *(int *)(puVar16 + 0xae);
    puVar18 = aWrongDiskThatW;
    puVar17 = puVar16;
  }
  _od_alert(aInsertDisk,puVar18,iVar10 + 0xc,(int)(puVar17 + -0x40c3ec8) * -0x2593f69b >> 1,iVar15,0
            ,0,0,0,0);
loc_4078DFE:
  iVar8 = 2;
loc_4078E00:
  if (((puVar16 == _od_vol) && (param_3 == 0)) &&
     ((iVar10 = _strcmp(&_boot_dev,&aOd), iVar10 == 0 &&
      (((unk_40B6904 & 8) == 0 && ((byte_40B606F & 1) == 0)))))) {
    _mon_boot(0);
  }
  if ((*(word *)(puVar16 + 0xd8) & 0x10) != 0) {
    *(word *)(puVar16 + 0xd8) = *(word *)(puVar16 + 0xd8) & 0xffef;
    _wakeup(puVar16 + 0xd8);
  }
  _od_cmd(iVar13,0xf6,0,0,0,0,0,0,0,0);
  if (((param_3 != 0) && ((0 < _od_empty || (_od_specific != (undefined *)0x0)))) &&
     ((_alert_key == 0x6e || ((_od_alert_abort != 0 || ((*(byte *)(param_2 + 0x18) & 0x40) != 0)))))
     ) {
    if (_od_empty < 1) {
      if (_od_specific != (undefined *)0x0) {
        while (puVar11 = (uint *)_disksort_first(_od_specific), puVar11 != (uint *)0x0) {
          *(undefined2 *)(puVar11 + 7) = 6;
          uVar1 = *puVar11;
          *puVar11 = uVar1 | 4;
          if ((uVar1 & 2) == 0) {
            _biodone(puVar11);
          }
          _disksort_remove(_od_specific,puVar11);
        }
        *(undefined2 *)(_od_specific + 0xd8) = 0x8008;
        _od_ctrl_start(*(undefined4 *)(param_2 + 0x10));
      }
    }
    else {
      _od_empty = -1;
      _wakeup(&_od_empty);
    }
    if (_od_alert_present == 0) {
      _alert_done();
    }
    else {
      _vol_panel_remove(_od_vol_tag);
      _od_alert_abort = 0;
      _od_alert_present = 0;
    }
    if (_od_requested == 1) {
      _od_specific = (undefined *)0x0;
      _od_requested = 2;
      _wakeup(&_od_requested);
    }
  }
  if (!bVar5) {
    *(undefined2 *)(puVar16 + 0xd8) = 0;
  }
  _od_spinup = 0;
loc_4078FB0:
  if ((*(word *)(puVar16 + 0xd8) & 0x10) != 0) {
    *(word *)(puVar16 + 0xd8) = *(word *)(puVar16 + 0xd8) & 0xffef;
    _wakeup(puVar16 + 0xd8);
  }
  *(word *)(puVar16 + 0xd8) = *(word *)(puVar16 + 0xd8) & 0xffdf;
  _od_errmsg_filter = uVar6;
  return iVar8;
}

