/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016d20c */

void _notify_server_loop(void)

{
  task_t task;
  int iVar1;
  kern_return_t kVar2;
  int iVar3;
  
  *(undefined4 *)(*(int *)(_active_threads + 0xc) + 0x50) = 1;
  task = *(task_t *)(_active_threads + 0xc);
  iVar1 = _port_allocate(*(undefined4 *)(task + 0x88),&DAT_001e726c);
  if (iVar1 != 0) {
    FUN_0016d3c8(iVar1,s_port_allocate_001dff3c);
  }
  _get_kern_port(task,DAT_001e726c,&DAT_001e7270);
  kVar2 = _task_set_special_port(task,2,DAT_001e7270);
  if (kVar2 != 0) {
    FUN_0016d3c8(kVar2,s_task_set_special_port_001dff4a);
  }
  iVar1 = _port_allocate(*(undefined4 *)(task + 0x88),&_pn_register_port);
  if (iVar1 != 0) {
    FUN_0016d3c8(iVar1,s_port_allocate_001dff60);
  }
  _get_kern_port(task,_pn_register_port,&_pn_register_port_k);
  iVar1 = _port_set_allocate(*(undefined4 *)(task + 0x88),&DAT_001e7274);
  if (iVar1 != 0) {
    FUN_0016d3c8(iVar1,s_port_set_allocate_001dff6e);
  }
  iVar1 = _port_set_add(*(undefined4 *)(task + 0x88),DAT_001e7274,DAT_001e726c);
  if (iVar1 != 0) {
    FUN_0016d3c8(iVar1,s_port_set_add_001dff80);
  }
  iVar1 = _port_set_add(*(undefined4 *)(task + 0x88),DAT_001e7274,_pn_register_port);
  if (iVar1 != 0) {
    FUN_0016d3c8(iVar1,s_port_set_add_001dff8d);
  }
  iVar1 = _kalloc(0x2000);
  DAT_001e727c = &DAT_001e7278;
  DAT_001e7278 = &DAT_001e7278;
  do {
    while( true ) {
      while( true ) {
        *(undefined4 *)(iVar1 + 0xc) = DAT_001e7274;
        *(undefined4 *)(iVar1 + 4) = 0x2000;
        iVar3 = _msg_receive(iVar1,0,0);
        if (iVar3 == 0) break;
        _printf(s_notify_server_loop__msg_receive_e_001dff9a,iVar3);
      }
      if (_pn_register_port != *(int *)(iVar1 + 0xc)) break;
      FUN_0016d3ec(iVar1);
    }
    if (DAT_001e726c == *(int *)(iVar1 + 0xc)) {
      FUN_0016d454(iVar1);
    }
    else {
      _printf(s_notify_server_loop__BOGUS_msg_lo_001dffc6);
    }
  } while( true );
}

