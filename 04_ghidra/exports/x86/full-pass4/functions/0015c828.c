/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015c828 */

thread_act_t _setup_main(void)

{
  thread_act_t target_act;
  undefined4 uVar1;
  
  _clock_timer_init();
  _rqinit();
  _sched_init();
  _vm_mem_init();
  _mach_clock_bootstrap();
  _init_timers();
  _init_timeout();
  _startup(_virtual_avail);
  DAT_001f6348 = 1;
  DAT_001f6350 = _mem_size + 0xfffffU & 0xfff00000;
  DAT_001f634c = 0;
  _machine_info = 4;
  DAT_001f6344 = 0;
  _uzone_init();
  _ipc_bootstrap();
  _cpu_up(_master_cpu);
  _mach_net_init();
  _task_init();
  _thread_init();
  _swapper_init();
  _ipc_init();
  _vnode_pager_init();
  _thread_create(_kernel_task,&_first_thread);
  _thread_deallocate(_first_thread);
  _thread_start(_first_thread,_main);
  _thread_doswapin(_first_thread);
  target_act = _first_thread;
  *(byte *)(_first_thread + 0x4c) = *(byte *)(_first_thread + 0x4c) | 4;
  _thread_resume(target_act);
  uVar1 = _splvm();
  *(undefined4 *)(_kernel_pmap + 0x18) = 1;
  _splx(uVar1);
  _dev_server_init();
  _miniMonInit();
  return _first_thread;
}

