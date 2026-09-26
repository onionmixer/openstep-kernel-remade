
void _volume_check(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  undefined7 *puVar9;
  int iVar10;
  int *piVar11;
  int *piVar12;
  int iVar13;
  int iStack_1e;
  int iStack_1a;
  undefined4 uStack_16;
  undefined4 uStack_12;
  uint uStack_e;
  undefined4 uStack_a;
  byte abStack_6 [2];
  
  iVar5 = _fd_new_fv(9);
  _vol_check_alive = 1;
  unk_40C375C = iVar5;
  puVar3 = _vol_abort_q;
  do {
    while ((undefined4 **)puVar3 != &_vol_abort_q) {
      puVar1 = (undefined4 *)*puVar3;
      puVar2 = (undefined4 *)puVar3[1];
      puVar4 = puVar2;
      if ((undefined4 **)puVar1 != &_vol_abort_q) {
        puVar1[1] = puVar2;
        puVar4 = dword_40C39D8;
      }
      dword_40C39D8 = puVar4;
      *puVar2 = puVar1;
      iVar10 = puVar3[2];
      if ((*(uint *)(iVar10 + 0x124) & 8) != 0) {
        iVar6 = *(int *)(iVar10 + 8);
        *(uint *)(iVar10 + 0x124) = *(uint *)(iVar10 + 0x124) & 0xfffffff7 | 0x10;
        *(undefined4 *)(iVar5 + 4) = *(undefined4 *)(iVar10 + 8);
        (&DAT_40c370c)[iVar6 * 10] = 0;
        *(undefined4 *)(iVar10 + 8) = 1;
        _fd_basic_cmd(iVar5,0x81);
      }
      _kfree(puVar3,0x14);
      puVar3 = puVar1;
    }
    sub_406EF08();
    puVar9 = &_fd_drive;
    iVar10 = 0;
    piVar11 = &DAT_40c370c;
    do {
      if ((*(byte *)((int)puVar9 + 0x23) & 1) == 0) break;
      if (*(int *)((int)puVar9 + 0xc) == 0) {
        *(int *)(iVar5 + 4) = iVar10;
        iVar6 = _fd_get_status(iVar5,abStack_6);
        if ((iVar6 == 0) && ((abStack_6[0] & 0xc0) != 0)) {
          *(undefined4 *)(iVar5 + 0x176) = 0;
          *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)((int)puVar9 + 0x14);
          iVar6 = _fd_attach_com(iVar5);
          if (iVar6 == 0) {
            iVar6 = *piVar11;
            if (iVar6 == 0) {
              iVar6 = 0;
              piVar12 = (int *)_fd_volume_p;
              do {
                iVar13 = *piVar12;
                if ((iVar13 != 0) && (iVar7 = sub_406ECF4(iVar5,iVar13), iVar7 == 0)) {
                  *(undefined4 *)(iVar13 + 0x176) = *(undefined4 *)(iVar5 + 0x176);
                  sub_406EC7C(iVar13,puVar9,iVar5);
                  goto loc_406EAE4;
                }
                piVar12 = piVar12 + 1;
                iVar6 = iVar6 + 1;
              } while (iVar6 < 8);
              iVar6 = 0;
              piVar12 = (int *)_fd_volume_p;
              do {
                if (*piVar12 == 0) {
                  uVar8 = _fd_new_fv(iVar6);
                  *(undefined4 *)(_fd_volume_p + iVar6 * 4) = uVar8;
                  _fd_assign_dv(uVar8,iVar10);
                  sub_406EEB4(iVar5,uVar8);
                  _volume_notify(uVar8);
                  goto loc_406EAE4;
                }
                piVar12 = piVar12 + 1;
                iVar6 = iVar6 + 1;
              } while (iVar6 < 8);
              _printf(aFdVolumeCheckN);
              _fd_basic_cmd(iVar5,2);
            }
            else if ((*(byte *)(iVar6 + 0x127) & 4) == 0) {
              iVar13 = sub_406ECF4(iVar5,iVar6);
              if (iVar13 == 0) {
                *(undefined4 *)(*piVar11 + 0x176) = *(undefined4 *)(iVar5 + 0x176);
                sub_406EC7C(*piVar11,puVar9,iVar5);
              }
              else {
                _fd_basic_cmd(iVar5,2);
                if ((*(byte *)(iVar6 + 0x127) & 8) != 0) {
                  _vol_panel_remove(*(undefined4 *)(iVar6 + 0x138));
                  sub_406EFD6(iVar6,1);
                }
              }
            }
            else {
              iVar13 = 0;
              do {
                if ((*(int *)(_fd_volume_p + iVar13 * 4) != 0) &&
                   (iVar7 = sub_406ECF4(iVar5,*(int *)(_fd_volume_p + iVar13 * 4)), iVar7 == 0)) {
                  _fd_basic_cmd(iVar5,2);
                  if ((*(byte *)(iVar6 + 0x127) & 8) != 0) {
                    _vol_panel_remove(*(undefined4 *)(iVar6 + 0x138));
                    sub_406EFD6(iVar6,1);
                  }
                  goto loc_406EAE4;
                }
                iVar13 = iVar13 + 1;
              } while (iVar13 < 8);
              sub_406EEB4(iVar5,iVar6);
              sub_406EC7C(iVar6,puVar9,iVar5);
            }
          }
        }
      }
loc_406EAE4:
      iVar10 = iVar10 + 1;
      piVar11 = piVar11 + 10;
      puVar9 = puVar9 + 5;
    } while (iVar10 < 1);
    puVar9 = &_fd_drive;
    iVar10 = 0;
    do {
      if (((*(uint *)(puVar9 + 4) & 7) == 3) && (*(int *)((int)puVar9 + 0xc) != 0)) {
        uStack_e = CONCAT31((uint3)*_eventc_m | (uint3)(((uint)*_eventc_h << 0x10) >> 8),*_eventc_l)
                   & 0xfffff;
        if ((((uStack_e ^ *_event_middle) & 0x80000) != 0) &&
           (*_event_middle = *_event_middle + 0x80000, (*_event_middle & 0xfff80000) == 0)) {
          *_event_high = *_event_high + 1;
        }
        uStack_a = *_event_high;
        uStack_e = *_event_middle | uStack_e;
        uStack_16 = *(undefined4 *)(puVar9 + 3);
        uStack_12 = *(undefined4 *)((int)puVar9 + 0x1c);
        _ts_add(&uStack_16,2000000);
        iVar6 = _ts_greater(&uStack_e,&uStack_16);
        if (iVar6 != 0) {
          *(int *)(iVar5 + 4) = iVar10;
          _fd_basic_cmd(iVar5,4);
        }
      }
      iVar10 = iVar10 + 1;
      puVar9 = puVar9 + 5;
    } while (iVar10 < 1);
    if (_vol_check_delay < 1000000) {
      iStack_1e = 0;
      iStack_1a = _vol_check_delay;
    }
    else {
      iStack_1e = _vol_check_delay / 1000000;
      iStack_1a = _vol_check_delay % 1000000;
    }
    _vol_check_event = 0;
    _us_timeout(_vol_check_timeout,0,&iStack_1e,0);
    _fd_thread_block(&_vol_check_event,0xff,&_vol_check_lock);
    puVar3 = _vol_abort_q;
  } while( true );
}

