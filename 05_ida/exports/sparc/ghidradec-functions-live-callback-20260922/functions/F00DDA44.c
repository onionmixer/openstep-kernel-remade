
/* WARNING: Removing unreachable block (ram,0xf00dded8) */
/* WARNING: Removing unreachable block (ram,0xf00ddebc) */
/* WARNING: Removing unreachable block (ram,0xf00dde90) */
/* WARNING: Removing unreachable block (ram,0xf00dde6c) */
/* WARNING: Removing unreachable block (ram,0xf00dde20) */
/* WARNING: Removing unreachable block (ram,0xf00dddf0) */
/* WARNING: Removing unreachable block (ram,0xf00ddde0) */
/* WARNING: Removing unreachable block (ram,0xf00dddb0) */
/* WARNING: Removing unreachable block (ram,0xf00ddd94) */
/* WARNING: Removing unreachable block (ram,0xf00ddd78) */
/* WARNING: Removing unreachable block (ram,0xf00ddd3c) */
/* WARNING: Removing unreachable block (ram,0xf00ddd2c) */
/* WARNING: Removing unreachable block (ram,0xf00ddd10) */
/* WARNING: Removing unreachable block (ram,0xf00ddcec) */
/* WARNING: Removing unreachable block (ram,0xf00ddccc) */
/* WARNING: Removing unreachable block (ram,0xf00ddca4) */
/* WARNING: Removing unreachable block (ram,0xf00ddc84) */
/* WARNING: Removing unreachable block (ram,0xf00ddc30) */
/* WARNING: Removing unreachable block (ram,0xf00ddbcc) */
/* WARNING: Removing unreachable block (ram,0xf00ddb9c) */
/* WARNING: Removing unreachable block (ram,0xf00ddb80) */
/* WARNING: Removing unreachable block (ram,0xf00ddb64) */
/* WARNING: Removing unreachable block (ram,0xf00ddb34) */
/* WARNING: Removing unreachable block (ram,0xf00ddb24) */
/* WARNING: Removing unreachable block (ram,0xf00ddaec) */
/* WARNING: Removing unreachable block (ram,0xf00ddad0) */
/* WARNING: Removing unreachable block (ram,0xf00ddac8) */
/* WARNING: Removing unreachable block (ram,0xf00ddad8) */
/* WARNING: Removing unreachable block (ram,0xf00ddb10) */
/* WARNING: Removing unreachable block (ram,0xf00ddb2c) */
/* WARNING: Removing unreachable block (ram,0xf00ddb48) */
/* WARNING: Removing unreachable block (ram,0xf00ddb78) */
/* WARNING: Removing unreachable block (ram,0xf00ddb88) */
/* WARNING: Removing unreachable block (ram,0xf00ddbb8) */
/* WARNING: Removing unreachable block (ram,0xf00ddc18) */
/* WARNING: Removing unreachable block (ram,0xf00ddc7c) */
/* WARNING: Removing unreachable block (ram,0xf00ddc8c) */
/* WARNING: Removing unreachable block (ram,0xf00ddcc4) */
/* WARNING: Removing unreachable block (ram,0xf00ddcd4) */
/* WARNING: Removing unreachable block (ram,0xf00ddd08) */
/* WARNING: Removing unreachable block (ram,0xf00ddd18) */
/* WARNING: Removing unreachable block (ram,0xf00ddd34) */
/* WARNING: Removing unreachable block (ram,0xf00ddd50) */
/* WARNING: Removing unreachable block (ram,0xf00ddd8c) */
/* WARNING: Removing unreachable block (ram,0xf00ddd9c) */
/* WARNING: Removing unreachable block (ram,0xf00dddcc) */
/* WARNING: Removing unreachable block (ram,0xf00ddde8) */
/* WARNING: Removing unreachable block (ram,0xf00dde04) */
/* WARNING: Removing unreachable block (ram,0xf00dde34) */
/* WARNING: Removing unreachable block (ram,0xf00dde84) */
/* WARNING: Removing unreachable block (ram,0xf00ddea8) */
/* WARNING: Removing unreachable block (ram,0xf00ddecc) */
/* WARNING: Removing unreachable block (ram,0xf00ddee4) */
/* WARNING: Removing unreachable block (ram,0xf00dda54) */

undefined8 sub_F00DDA44(int param_1,int param_2)

{
  undefined (*pauVar1) [15];
  undefined (*pauVar2) [14];
  undefined8 *puVar3;
  int iVar4;
  uint uVar5;
  undefined *puVar6;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar7;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  puVar3 = paIoaudio;
  _objc_msgSend(paIoaudio,paInstance_0);
  *(undefined *)(param_2 + 3) = 1;
  *(undefined4 *)(param_2 + 4) = 0x18;
  *(undefined4 *)(param_2 + 8) = 0;
  *(undefined4 *)(param_2 + 0xc) = 0;
  *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(param_2 + 0x14) = 0;
  if (*(int *)(param_1 + 0x14) == 0) {
    if (puVar3 == (undefined8 *)0x0) {
      uVar7 = 1;
    }
    else {
      if (dword_F012EF4C == 0) {
        iVar4 = dword_F01330E0;
        _kern_serv_port_death_proc(dword_F01330E0,_audio_port_gone);
        _task_self();
        _port_allocate_EXTERNAL();
        if (iVar4 != 0) {
          _IOLog(aAudioPortAlloc);
        }
        _outPort = *(int *)((int)register0x00000038 + -0xc);
        iVar4 = dword_F01330E0;
        _kern_serv_port_serv(dword_F01330E0,_outPort,_audioMessages,_outPort);
        puVar6 = (undefined *)0xf00fc400;
        if (iVar4 != 0) {
          puVar6 = aAudioCreateaud;
          _IOLog(aAudioCreateaud,iVar4);
        }
        _task_self();
        _port_allocate_EXTERNAL();
        if (puVar6 != (undefined *)0x0) {
          _IOLog(aAudioPortAlloc);
        }
        _inPort = *(int *)((int)register0x00000038 + -0xc);
        iVar4 = dword_F01330E0;
        _kern_serv_port_serv(dword_F01330E0,_inPort,_audioMessages,_inPort);
        puVar6 = (undefined *)0xf00fc400;
        if (iVar4 != 0) {
          puVar6 = aAudioCreateaud;
          _IOLog(aAudioCreateaud,iVar4);
        }
        _task_self();
        _port_allocate_EXTERNAL();
        if (puVar6 != (undefined *)0x0) {
          _IOLog(aAudioPortAlloc);
        }
        _sndPort = *(int *)((int)register0x00000038 + -0xc);
        iVar4 = dword_F01330E0;
        _kern_serv_port_serv(dword_F01330E0,_sndPort,_audioMessages,_sndPort);
        if (iVar4 != 0) {
          _IOLog(aAudioCreateaud,iVar4);
        }
        dword_F012EF4C = 1;
        *(undefined *)(param_2 + 3) = 0;
      }
      else {
        *(undefined *)(param_2 + 3) = 0;
      }
      *(undefined4 *)(param_2 + 4) = 0x28;
      *(undefined4 *)(param_2 + 0x14) = 1;
      *(undefined *)(param_2 + 0x18) = 6;
      *(undefined *)(param_2 + 0x19) = 0x20;
      uVar5 = *(uint *)(param_2 + 0x18) & 0xffff0008 | 0x38;
      *(uint *)(param_2 + 0x18) = uVar5;
      _IOHostPrivSelf();
      if (uVar5 == 0) {
        _IOLog(aAudioCannotGet);
        uVar7 = 1;
      }
      else {
        if (*(uint *)(param_1 + 0x1c) == uVar5) {
          if (*(int *)(param_1 + 0x24) != 0) {
            if (_inPort != 0) {
              iVar4 = dword_F01330E0;
              _kern_serv_port_gone();
              _task_self();
              _port_deallocate_EXTERNAL();
              if (iVar4 != 0) {
                _IOLog(aAudioPortDeall);
              }
            }
            if (_outPort != 0) {
              iVar4 = dword_F01330E0;
              _kern_serv_port_gone();
              _task_self();
              _port_deallocate_EXTERNAL();
              if (iVar4 != 0) {
                _IOLog(aAudioPortDeall);
              }
            }
            puVar6 = (undefined *)&DAT_f0133000;
            if (_sndPort != 0) {
              iVar4 = dword_F01330E0;
              _kern_serv_port_gone();
              _task_self();
              _port_deallocate_EXTERNAL();
              puVar6 = (undefined *)0xf00fc000;
              if (iVar4 != 0) {
                puVar6 = aAudioPortDeall;
                _IOLog();
              }
            }
            _task_self();
            _port_allocate_EXTERNAL();
            if ((undefined4 *)puVar6 != (undefined4 *)0x0) {
              _IOLog(aAudioPortAlloc);
            }
            _outPort = *(int *)((int)register0x00000038 + -0xc);
            iVar4 = dword_F01330E0;
            _kern_serv_port_serv(dword_F01330E0,_outPort,_audioMessages,_outPort);
            puVar6 = (undefined *)0xf00fc400;
            if (iVar4 != 0) {
              puVar6 = aAudioCreateaud;
              _IOLog(aAudioCreateaud,iVar4);
            }
            _task_self();
            _port_allocate_EXTERNAL();
            if (puVar6 != (undefined *)0x0) {
              _IOLog(aAudioPortAlloc);
            }
            _inPort = *(int *)((int)register0x00000038 + -0xc);
            iVar4 = dword_F01330E0;
            _kern_serv_port_serv(dword_F01330E0,_inPort,_audioMessages,_inPort);
            puVar6 = (undefined *)0xf00fc400;
            if (iVar4 != 0) {
              puVar6 = aAudioCreateaud;
              _IOLog(aAudioCreateaud,iVar4);
            }
            _task_self();
            _port_allocate_EXTERNAL();
            if (puVar6 != (undefined *)0x0) {
              _IOLog(aAudioPortAlloc);
            }
            _sndPort = *(int *)((int)register0x00000038 + -0xc);
            iVar4 = dword_F01330E0;
            _kern_serv_port_serv(dword_F01330E0,_sndPort,_audioMessages,_sndPort);
            if (iVar4 != 0) {
              _IOLog(aAudioCreateaud,iVar4);
            }
          }
          *(int *)(param_2 + 0x1c) = _inPort;
          iVar4 = _sndPort;
          *(int *)(param_2 + 0x20) = _outPort;
          *(int *)(param_2 + 0x24) = iVar4;
        }
        else {
          *(undefined4 *)(param_2 + 0x1c) = 0;
          *(undefined4 *)(param_2 + 0x20) = 0;
          *(undefined4 *)(param_2 + 0x24) = 0;
        }
        pauVar1 = paOutputchannel;
        _objc_msgSend(puVar3,paOutputchannel);
        _objc_msgSend();
        _objc_msgSend(puVar3,pauVar1);
        _objc_msgSend();
        pauVar2 = paInputchannel;
        _objc_msgSend(puVar3,paInputchannel);
        _objc_msgSend();
        _objc_msgSend(puVar3,pauVar2);
        _objc_msgSend();
        uVar7 = 1;
      }
    }
  }
  else {
    uVar7 = 0;
  }
  return CONCAT44(param_2,uVar7);
}

