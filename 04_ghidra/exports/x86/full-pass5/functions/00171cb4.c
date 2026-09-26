/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00171cb4 */

void FUN_00171cb4(void)

{
  int iVar1;
  int iVar2;
  undefined1 local_8c [4];
  undefined4 local_88;
  undefined4 local_80;
  int local_7c;
  undefined1 local_34 [40];
  undefined4 local_c;
  undefined4 local_8;
  
  iVar2 = *(int *)(_active_threads + 0xc);
  *(undefined4 *)(iVar2 + 0x50) = 1;
  DAT_001e7284 = _task_self();
  do {
  } while (DAT_001e7280 != 0);
  LOCK();
  DAT_001e7280 = 1;
  UNLOCK();
  iVar1 = _port_set_allocate_EXTERNAL(DAT_001e7284,&local_8);
  if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(s_ux_handler__port_set_allocate_fa_001e082c);
  }
  iVar1 = _port_allocate_EXTERNAL(DAT_001e7284,&local_c);
  if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(s_ux_handler__port_allocate_failed_001e0851);
  }
  iVar1 = _port_set_add_EXTERNAL(DAT_001e7284,local_8,local_c);
  if (iVar1 == 0) {
    iVar2 = _object_copyin(iVar2,local_c,6,0,&_ux_exception_port);
    if (iVar2 != 0) {
      _thread_wakeup_prim(&_ux_exception_port,0,0);
      LOCK();
      DAT_001e7280 = 0;
      UNLOCK();
      _task_name(s_ux_except_001e08c6);
      do {
        while( true ) {
          local_80 = local_8;
          local_88 = 0x58;
          iVar1 = _msg_receive(local_8c,0,0);
          iVar2 = local_7c;
          if (iVar1 != 0) break;
          iVar1 = _exc_server(local_8c,local_34);
          if (iVar1 != 0) {
            _msg_send(local_34,0,0);
          }
          if (iVar2 != 0) {
            _port_deallocate_EXTERNAL(DAT_001e7284,iVar2);
          }
        }
      } while (iVar1 == -0xcc);
                    /* WARNING: Subroutine does not return */
      _panic(s_exception_handler_001e08d0);
    }
                    /* WARNING: Subroutine does not return */
    _panic(s_ux_handler__object_copyin_ux_exc_001e0892);
  }
                    /* WARNING: Subroutine does not return */
  _panic(s_ux_handler__port_set_add_failed_001e0872);
}

