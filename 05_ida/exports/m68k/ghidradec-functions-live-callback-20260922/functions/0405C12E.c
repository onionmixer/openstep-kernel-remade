
void sub_405C12E(void)

{
  int iVar1;
  int iVar2;
  undefined auStack_8c [4];
  undefined4 uStack_88;
  undefined4 uStack_80;
  int iStack_7c;
  undefined auStack_34 [40];
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  iVar2 = *(int *)(_active_threads + 0xc);
  *(undefined4 *)(iVar2 + 0x48) = 1;
  dword_40B4DF0 = _task_self();
  iVar1 = _port_set_allocate_EXTERNAL(dword_40B4DF0,&uStack_8);
  if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aUxHandlerPortS);
  }
  iVar1 = _port_allocate_EXTERNAL(dword_40B4DF0,&uStack_c);
  if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aUxHandlerPortA);
  }
  iVar1 = _port_set_add_EXTERNAL(dword_40B4DF0,uStack_8,uStack_c);
  if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aUxHandlerPortS_0);
  }
  iVar2 = _object_copyin(iVar2,uStack_c,6,0,&_ux_exception_port);
  if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aUxHandlerObjec);
  }
  _thread_wakeup_prim(&_ux_exception_port,0,0);
  _task_name(aUxExcept);
  do {
    while( true ) {
      uStack_80 = uStack_8;
      uStack_88 = 0x58;
      iVar1 = _msg_receive(auStack_8c,0,0);
      iVar2 = iStack_7c;
      if (iVar1 != 0) break;
      iVar1 = _exc_server(auStack_8c,auStack_34);
      if (iVar1 != 0) {
        _msg_send(auStack_34,0,0);
      }
      if (iVar2 != 0) {
        _port_deallocate_EXTERNAL(dword_40B4DF0,iVar2);
      }
    }
  } while (iVar1 == -0xcc);
                    /* WARNING: Subroutine does not return */
  _panic(aExceptionHandl);
}

