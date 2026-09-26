
/* WARNING: Removing unreachable block (ram,0xf006a628) */
/* WARNING: Removing unreachable block (ram,0xf006a618) */
/* WARNING: Removing unreachable block (ram,0xf006a5f8) */
/* WARNING: Removing unreachable block (ram,0xf006a5dc) */
/* WARNING: Removing unreachable block (ram,0xf006a5c4) */
/* WARNING: Removing unreachable block (ram,0xf006a5ac) */
/* WARNING: Removing unreachable block (ram,0xf006a59c) */
/* WARNING: Removing unreachable block (ram,0xf006a58c) */
/* WARNING: Removing unreachable block (ram,0xf006a578) */
/* WARNING: Removing unreachable block (ram,0xf006a52c) */
/* WARNING: Removing unreachable block (ram,0xf006a518) */
/* WARNING: Removing unreachable block (ram,0xf006a508) */
/* WARNING: Removing unreachable block (ram,0xf006a4f8) */
/* WARNING: Removing unreachable block (ram,0xf006a500) */
/* WARNING: Removing unreachable block (ram,0xf006a510) */
/* WARNING: Removing unreachable block (ram,0xf006a520) */
/* WARNING: Removing unreachable block (ram,0xf006a570) */
/* WARNING: Removing unreachable block (ram,0xf006a584) */
/* WARNING: Removing unreachable block (ram,0xf006a594) */
/* WARNING: Removing unreachable block (ram,0xf006a5a4) */
/* WARNING: Removing unreachable block (ram,0xf006a5b4) */
/* WARNING: Removing unreachable block (ram,0xf006a5cc) */
/* WARNING: Removing unreachable block (ram,0xf006a5e4) */
/* WARNING: Removing unreachable block (ram,0xf006a600) */
/* WARNING: Removing unreachable block (ram,0xf006a620) */
/* WARNING: Removing unreachable block (ram,0xf006a630) */
/* WARNING: Removing unreachable block (ram,0xf006a4f0) */

undefined8 _setup_main(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
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
  _clock_timer_init();
  _rqinit();
  _sched_init();
  _vm_mem_init();
  _mach_clock_bootstrap();
  _init_timers();
  _init_timeout();
  _startup(_virtual_avail);
  dword_F013C048 = 1;
  DAT_f013c04c = 0;
  _machine_info = 4;
  DAT_f013c044 = 0;
  dword_F013C050 = _mem_size + 0xfffffU & 0xfff00000;
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
  _thread_deallocate(_first_thread._0_4_);
  _thread_start(_first_thread._0_4_,_main);
  _thread_doswapin(_first_thread._0_4_);
  iVar1 = _first_thread._0_4_;
  *(uint *)(_first_thread._0_4_ + 0x4c) = *(uint *)(_first_thread._0_4_ + 0x4c) | 4;
  _thread_resume();
  _splvm();
  _pmap_activate(_kernel_pmap,_first_thread._0_4_,0);
  _splx(iVar1);
  _dev_server_init();
  _miniMonInit();
  return CONCAT44(param_2,_first_thread._0_4_);
}

