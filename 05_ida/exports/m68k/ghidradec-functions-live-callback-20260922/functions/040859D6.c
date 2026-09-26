
void _snd_server_loop(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  dword_40C6EB8 = *(int *)(_active_threads + 0xc);
  *(undefined4 *)(dword_40C6EB8 + 0x48) = 1;
  dword_40C6EC0 = *(undefined4 *)(dword_40C6EB8 + 0x7c);
  dword_40C6EC4 = _task_self();
  dword_40C6EBC = *(undefined4 *)(*(int *)(_active_threads + 0xc) + 8);
  dword_40C6E98 = &dword_40C6E94;
  dword_40C6E94 = &dword_40C6E94;
  dword_40C6E90 = &dword_40C6E8C;
  dword_40C6E8C = &dword_40C6E8C;
  iVar2 = _port_set_allocate(dword_40C6EC0,&dword_40C6EA8);
  if (iVar2 != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aSoundCanTAlloc_0);
  }
  iVar2 = _port_allocate(dword_40C6EC0,&uStack_8);
  if (iVar2 != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aSoundCanTAlloc_1);
  }
  iVar2 = _object_copyin(dword_40C6EB8,uStack_8,6,0,&uStack_c);
  if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aSoundObjectCop);
  }
  iVar2 = _task_set_special_port(dword_40C6EB8,2,uStack_c);
  if (iVar2 != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aSoundTaskSetSp);
  }
  iVar2 = _port_set_add(dword_40C6EC0,dword_40C6EA8,uStack_8);
  if (iVar2 != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aSoundPortSetAd);
  }
  uStack_c = _ipc_port_copy_send(dword_40B67DC);
  _object_copyout(dword_40C6EB8,uStack_c,6,&dword_40C6EC8);
  iVar2 = _port_allocate(dword_40C6EC0,&dword_40C6EB4);
  if (iVar2 == 0) {
    iVar2 = _port_set_add(dword_40C6EC0,dword_40C6EA8,dword_40C6EB4);
    if (iVar2 == 0) {
      _thread_wakeup_prim(&dword_40C6EC4,0,0);
      _task_name(aSoundDevice);
      _snd_device_init(0);
      _dsp_dev_init();
      _dsp_dev_reset_hard();
      _snd_stream_init();
      iVar2 = _snd_rcv_alloc_msg_frame();
      uVar1 = *(undefined4 *)(iVar2 + 4);
      do {
        while( true ) {
          while( true ) {
            *(undefined4 *)(iVar2 + 0xc) = dword_40C6EA8;
            *(undefined4 *)(iVar2 + 4) = uVar1;
            iVar3 = _msg_receive(iVar2,0,0);
            if (iVar3 == 0) break;
            if (iVar3 != -0xcf) {
              _printf(aSoundReceiveFa,iVar3);
            }
          }
          if (*(int *)(iVar2 + 0xc) != dword_40C6EB4) break;
          iVar3 = sub_4085E66(iVar2);
loc_4085C52:
          if (iVar3 != 0) {
            _snd_reply_illegal_msg
                      (0,*(undefined4 *)(iVar2 + 0x10),*(undefined4 *)(iVar2 + 0x14),iVar3);
          }
        }
        if (*(int *)(iVar2 + 0xc) == 0x10013) {
          iVar3 = _snd_dsp_cmd_port_msg(iVar2);
          goto loc_4085C52;
        }
        iVar3 = _task_notify();
        if (iVar3 != *(int *)(iVar2 + 0xc)) {
          iVar3 = sub_408667A(iVar2);
          goto loc_4085C52;
        }
        if (*(int *)(iVar2 + 0x14) == 0x41) {
          sub_40870BA(*(undefined4 *)(iVar2 + 0x1c));
        }
        else {
          _printf(aSoundWierdNoti,*(int *)(iVar2 + 0x14),*(undefined4 *)(iVar2 + 0x1c));
        }
      } while( true );
    }
  }
                    /* WARNING: Subroutine does not return */
  _panic(aSoundCanTAlloc_2);
}

