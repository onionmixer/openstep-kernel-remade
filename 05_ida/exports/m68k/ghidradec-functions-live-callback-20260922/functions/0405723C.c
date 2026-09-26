
void _notify_server_loop(void)

{
  int iVar1;
  int iVar2;
  
  *(undefined4 *)(*(int *)(_active_threads + 0xc) + 0x48) = 1;
  iVar2 = *(int *)(_active_threads + 0xc);
  iVar1 = _port_allocate(*(undefined4 *)(iVar2 + 0x7c),&dword_40B4DDC);
  if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    sub_4057404(iVar1,aPortAllocate);
  }
  _get_kern_port(iVar2,dword_40B4DDC,&dword_40B4DE0);
  iVar1 = _task_set_special_port(iVar2,2,dword_40B4DE0);
  if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    sub_4057404(iVar1,aTaskSetSpecial);
  }
  iVar1 = _port_allocate(*(undefined4 *)(iVar2 + 0x7c),&_pn_register_port);
  if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    sub_4057404(iVar1,aPortAllocate);
  }
  _get_kern_port(iVar2,_pn_register_port,&_pn_register_port_k);
  iVar1 = _port_set_allocate(*(undefined4 *)(iVar2 + 0x7c),&dword_40B4DE4);
  if (iVar1 == 0) {
    iVar1 = _port_set_add(*(undefined4 *)(iVar2 + 0x7c),dword_40B4DE4,dword_40B4DDC);
    if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
      sub_4057404(iVar1,aPortSetAdd);
    }
    iVar2 = _port_set_add(*(undefined4 *)(iVar2 + 0x7c),dword_40B4DE4,_pn_register_port);
    if (iVar2 == 0) {
      iVar2 = _kalloc(0x2000);
      dword_40B4DEC = &dword_40B4DE8;
      dword_40B4DE8 = &dword_40B4DE8;
      do {
        while( true ) {
          while( true ) {
            *(undefined4 *)(iVar2 + 0xc) = dword_40B4DE4;
            *(undefined4 *)(iVar2 + 4) = 0x2000;
            iVar1 = _msg_receive(iVar2,0,0);
            if (iVar1 == 0) break;
            _printf(aNotifyServerLo,iVar1);
          }
          if (*(int *)(iVar2 + 0xc) != _pn_register_port) break;
          sub_405742C(iVar2);
        }
        if (*(int *)(iVar2 + 0xc) == dword_40B4DDC) {
          sub_4057498(iVar2);
        }
        else {
          _printf(aNotifyServerLo_0);
        }
      } while( true );
    }
                    /* WARNING: Subroutine does not return */
    sub_4057404(iVar2,aPortSetAdd);
  }
                    /* WARNING: Subroutine does not return */
  sub_4057404(iVar1,aPortSetAllocat);
}

