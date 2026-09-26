
int _fc_probe(int param_1,int param_2)

{
  int iVar1;
  char *pcVar2;
  word wVar3;
  int iVar4;
  int iVar5;
  sword sVar6;
  byte bVar7;
  undefined4 *puVar8;
  int *piVar9;
  
  iVar4 = param_2 * 0x262;
  piVar9 = (int *)((int)&_fd_controller + iVar4);
  iVar5 = param_2 * 0x1e;
  param_1 = _slot_id_bmap + param_1;
  *piVar9 = param_1;
  *(undefined4 *)(DAT_40c3770 + iVar4) = (&_fc_bcp)[param_2];
  iVar1 = iVar4 + 0x40c3778;
  *(int *)(DAT_40c3770 + iVar4 + 0xc) = iVar1;
  *(int *)iVar1 = iVar1;
  iVar1 = (int)&unk_40C39C2 + iVar4;
  *(int *)(unk_40C39C6 + iVar4) = iVar1;
  *(int *)iVar1 = iVar1;
  *(undefined4 *)(DAT_40c3770 + iVar4 + 0x14) = 0;
  DAT_40c3770[iVar4 + 0x20] = 3;
  iVar1 = *piVar9;
  *(undefined *)(iVar1 + 8) = 0;
  (&byte_40C3791)[iVar4] = *(undefined *)(iVar1 + 8);
  *(undefined4 *)(unk_40C39C6 + iVar4 + 4) = 0;
  *(undefined **)(DAT_40c3792 + iVar4 + 0x214) = _sf_access_head + iVar5;
  *(undefined4 *)(DAT_40c3792 + iVar4 + 0x228) = 4;
  if (piVar9 == &_fd_controller) {
    iVar1 = iVar5 + 0x40c39f2;
    *(int *)(_sf_access_head + iVar5 + 10) = iVar1;
    *(int *)iVar1 = iVar1;
    _sf_access_head[iVar5 + 4] = 0;
    *(undefined4 *)(_sf_access_head + iVar5 + 0xe) = 0;
    *(undefined4 *)(_sf_access_head + iVar5 + 0x12) = 0;
    *(undefined4 *)(_sf_access_head + iVar5 + 0x16) = 0;
    *(undefined4 *)(_sf_access_head + iVar5 + 0x1a) = 0;
    dword_40C3764 = &_disk_eject_q;
    _disk_eject_q = &_disk_eject_q;
    iVar5 = 9;
    puVar8 = &unk_40C375C;
    do {
      do {
        *puVar8 = 0;
        puVar8 = puVar8 + -1;
        wVar3 = (word)((uint)iVar5 >> 0x10);
        sVar6 = (sword)iVar5 + -1;
        iVar5 = CONCAT22(wVar3,sVar6);
      } while (sVar6 != -1);
      iVar5 = (uint)wVar3 * 0x10000 + -1;
    } while (wVar3 != 0);
    _lock_init(&_fd_open_lock,1);
    dword_40C39D8 = &_vol_abort_q;
    _vol_abort_q = &_vol_abort_q;
  }
  _fd_polling_mode = 1;
  iVar5 = sub_406D476(piVar9,60000000);
  if (iVar5 == 0) {
    _fd_polling_mode = 0;
    iVar5 = _probe_rb(param_1);
    if ((iVar5 != 0) && (iVar5 = _probe_rb(param_1 + 1), iVar5 != 0)) {
      pcVar2 = (char *)(param_1 + 2);
      iVar5 = _probe_rb(pcVar2);
      if (((iVar5 != 0) &&
          (((iVar5 = _probe_rb(param_1 + 4), iVar5 != 0 &&
            (iVar5 = _probe_rb(param_1 + 5), iVar5 != 0)) &&
           (iVar5 = _probe_rb(param_1 + 7), iVar5 != 0)))) && (*pcVar2 = '\x04', *pcVar2 == '\x04'))
      {
        bVar7 = 0;
        do {
          *(byte *)(param_1 + 2) = bVar7 | 4;
          if ((bVar7 | 4) != *(byte *)(param_1 + 2)) goto loc_406C70A;
          bVar7 = bVar7 + 1;
        } while (bVar7 < 4);
        _fd_polling_mode = 1;
        iVar5 = _fc_82077_reset(piVar9,0);
        if (iVar5 == 0) {
          _fd_polling_mode = 0;
          *(undefined4 *)(DAT_40c3792 + iVar4 + 0x10) = 0x406d3e2;
          *(int **)(DAT_40c3792 + iVar4 + 0x14) = piVar9;
          *(undefined4 *)(DAT_40c3792 + iVar4 + 0x18) = 1;
          *(undefined4 *)(DAT_40c3792 + iVar4 + 0x2c) = 0;
          *(int *)(DAT_40c3792 + iVar4 + 0x1c) = _slot_id + 0x2000010;
          _dma_init(DAT_40c3792 + iVar4,0x1a63);
          *(uint *)(DAT_40c3770 + iVar4 + 0x14) = *(uint *)(DAT_40c3770 + iVar4 + 0x14) | 0x20000;
          *(int *)(DAT_40c3792 + iVar4 + 0x210) = _slot_id_bmap + 0x2014020;
          _sfa_relinquish(*(undefined4 *)(DAT_40c3792 + iVar4 + 0x214),iVar4 + 0x40c39aa,2);
          if (_fc_thread_timer_started != 0) {
            return param_1;
          }
          _timeout(_fc_thread_timer,0,_hz);
          _fc_thread_timer_started = 1;
          return param_1;
        }
        _fd_polling_mode = 0;
      }
    }
loc_406C70A:
    _sfa_relinquish(*(undefined4 *)(DAT_40c3792 + iVar4 + 0x214),iVar4 + 0x40c39aa,2);
  }
  else {
    _fd_polling_mode = 0;
  }
  return 0;
}

