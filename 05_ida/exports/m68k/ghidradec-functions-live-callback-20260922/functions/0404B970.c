
int _setup_main(void)

{
  int iVar1;
  
  _clock_timer_init();
  _rqinit();
  _sched_init();
  _vm_mem_init();
  _mach_clock_bootstrap();
  _init_timers();
  _init_timeout();
  _startup(_virtual_avail);
  dword_40C22D0 = 1;
  dword_40C22D8 = _mem_size + 0xfffffU & 0xfff00000;
  dword_40C22D4 = 0;
  _machine_info = 4;
  dword_40C22CC = 0;
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
  iVar1 = _first_thread;
  *(uint *)(_first_thread + 0x48) = *(uint *)(_first_thread + 0x48) | 4;
  _thread_resume(iVar1);
  _miniMonInit();
  return _first_thread;
}

