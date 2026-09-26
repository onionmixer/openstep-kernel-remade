/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001654b8 */

kern_return_t _thread_switch(mach_port_name_t thread_name,int option,mach_msg_timeout_t option_time)

{
  int *piVar1;
  thread_act_t thread;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *local_8;
  
  thread = _active_threads;
  if (option == 1) {
    _thread_depress_priority(_active_threads,option_time);
  }
  else if (option < 2) {
    if (option != 0) {
      return 4;
    }
  }
  else {
    if (option != 2) {
      return 4;
    }
    _thread_will_wait_with_timeout(_active_threads,option_time);
  }
  if (thread_name != 0) {
    iVar2 = _ipc_object_translate
                      (*(undefined4 *)(*(int *)(thread + 0xc) + 0x88),thread_name,0,&local_8);
    if (iVar2 == 0) {
      if (((int)local_8[2] < 0) && ((short)local_8[2] == 1)) {
        iVar2 = local_8[5];
        uVar3 = _splsched();
        piVar1 = (int *)(iVar2 + 0x20);
        do {
          do {
          } while (*piVar1 != 0);
          LOCK();
          iVar4 = *piVar1;
          *piVar1 = 1;
          UNLOCK();
        } while (iVar4 == 1);
        if ((*(int *)(iVar2 + 0x180) == *(int *)(thread + 0x180)) &&
           (iVar4 = _rem_runq(iVar2), iVar4 != 0)) {
          LOCK();
          *(undefined4 *)(iVar2 + 0x20) = 0;
          UNLOCK();
          _splx(uVar3);
          LOCK();
          *local_8 = 0;
          iVar4 = _processor_ptr;
          UNLOCK();
          if (*(int *)(iVar2 + 0x60) == 2) {
            *(undefined4 *)(_processor_ptr + 0x120) = *(undefined4 *)(iVar2 + 0x5c);
            *(undefined4 *)(iVar4 + 0x124) = 1;
          }
          _thread_run(_thread_switch_continue,iVar2);
          goto LAB_001655f5;
        }
        LOCK();
        *(undefined4 *)(iVar2 + 0x20) = 0;
        UNLOCK();
        _splx(uVar3);
      }
      LOCK();
      *local_8 = 0;
      UNLOCK();
    }
    else if (iVar2 == 0xf) {
      return 4;
    }
  }
  _thread_block_with_continuation(_thread_switch_continue);
LAB_001655f5:
  if (-1 < *(int *)(thread + 100)) {
    _thread_depress_abort(thread);
  }
  return 0;
}

