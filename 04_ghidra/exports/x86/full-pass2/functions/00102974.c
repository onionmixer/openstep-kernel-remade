/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00102974 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _main(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  size_t sVar6;
  uint uVar7;
  int iVar8;
  char *pcVar9;
  thread_act_t local_10;
  undefined1 local_c [4];
  undefined1 local_8 [4];
  
  _pqinit();
  iVar8 = _kernel_proc;
  *(int *)(_kernel_task + 0x3c) = _kernel_proc;
  *(undefined2 *)(iVar8 + 0x30) = 0;
  _pidhash_enter(iVar8);
  *(task_t *)(iVar8 + 0x68) = _kernel_task;
  uVar4 = _splhigh();
  _splx(uVar4);
  _calloutInitialize();
  _switch_unix_context(_active_threads);
  *(undefined1 *)(iVar8 + 0x13) = 3;
  *(byte *)(iVar8 + 0x28) = *(byte *)(iVar8 + 0x28) | 3;
  *(undefined1 *)(iVar8 + 0x15) = 0;
  *(undefined4 *)(iVar8 + 0x70) = 0;
  *(undefined4 *)(iVar8 + 0x74) = 0;
  *(undefined4 *)(iVar8 + 0x78) = 0;
  *_active_u = iVar8;
  iVar5 = _crget();
  _active_u[7] = iVar5;
  *(undefined2 *)((int)_active_u + 0x16e) = _cmask;
  _active_u[0x56] = -1;
  uVar7 = 0;
  iVar5 = 0;
  do {
    piVar3 = _active_u;
    *(undefined4 *)(iVar5 + 0x268 + (int)_active_u) = 0x7fffffff;
    *(undefined4 *)(iVar5 + 0x264 + (int)piVar3) = 0x7fffffff;
    piVar3 = _active_u;
    iVar2 = DAT_001da00c;
    iVar5 = iVar5 + 8;
    uVar7 = uVar7 + 1;
  } while (uVar7 < 6);
  _active_u[0x9f] = _vm_initial_limit_stack;
  piVar3[0xa0] = iVar2;
  piVar3 = _active_u;
  iVar5 = DAT_001da014;
  _active_u[0x9d] = _vm_initial_limit_data;
  piVar3[0x9e] = iVar5;
  piVar3 = _active_u;
  iVar5 = DAT_001da01c;
  _active_u[0xa1] = _vm_initial_limit_core;
  piVar3[0xa2] = iVar5;
  iVar5 = 0;
  do {
    (&_pgrphash)[iVar5] = (undefined *)0x0;
    (&_posix_proc_hash)[iVar5] = 0;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 0x40);
  iVar5 = _new_posix_proc(0);
  _px = iVar5;
  *(undefined **)(iVar5 + 0x10) = &_pgrp0;
  *(undefined4 *)(iVar5 + 0xc) = 0;
  *(undefined2 *)(iVar5 + 4) = *(undefined2 *)(_active_u[7] + 6);
  *(undefined2 *)(iVar5 + 6) = *(undefined2 *)(_active_u[7] + 2);
  *(undefined2 *)(iVar5 + 8) = *(undefined2 *)(_active_u[7] + 4);
  *(undefined4 *)(iVar5 + 0x14) = 0;
  *(byte *)(iVar5 + 0x18) = *(byte *)(iVar5 + 0x18) & 0xfe;
  *(byte *)(_px + 0x18) = *(byte *)(_px + 0x18) & 0xfd;
  _pgrphash = &_pgrp0;
  _DAT_001e8e34 = iVar8;
  _DAT_001e8e38 = &_session0;
  __pgrp0 = 0;
  _DAT_001e8e40 = 0;
  __session0 = 1;
  _DAT_001e9064 = iVar8;
  _DAT_001e9068 = 0;
  _DAT_001e906c = 0;
  _gc_init();
  _kernel_pageable_map = _kmem_suballoc(_kernel_map,local_8,local_c,0x80000,1);
  _ns_hardclock_init();
  _mfs_init();
  _lock_init(_active_u + 8,1);
  *(short *)_active_u[7] = *(short *)_active_u[7] + 1;
  _rootcred = _active_u[7];
  iVar8 = 1;
  do {
    *(undefined2 *)(_active_u[7] + 10 + iVar8 * 2) = 0xffff;
    iVar8 = iVar8 + 1;
  } while (iVar8 < 0x10);
  _mbinit();
  _cinit();
  uVar4 = _splnet();
  _ifinit();
  _domaininit();
  _splx(uVar4);
  _bhinit();
  _dnlc_init();
  _active_u[0x59] = 0;
  _active_u[0x58] = 0;
  iVar8 = 0;
  iVar5 = 0;
  do {
    if (*(int *)((int)&_machine_slot + iVar5) != 0) {
      _thread_create(_kernel_task,&local_10);
      _thread_bind(local_10,(&_processor_ptr)[iVar8]);
      _thread_start(local_10,_idle_thread);
      _thread_doswapin(local_10);
      _thread_resume(local_10);
    }
    iVar5 = iVar5 + 0x20;
    iVar8 = iVar8 + 1;
  } while (iVar8 < 1);
  _binit();
  _recompute_priorities();
  _lightning_bolt(0,0);
  _kernel_thread(_kernel_task,_reaper_thread,0);
  _kernel_thread(_kernel_task,_swapin_thread,0);
  _kernel_thread(_kernel_task,_sched_thread,0);
  _kernel_thread(_kernel_task,_netisr_thread,0);
  __objcInit();
  _objc_setClassHandler(FUN_0010307c);
  _kmEnableAnimation();
  _autoconf();
  _setconf();
  _loattach();
  *(undefined1 *)(DAT_001e875c + 0x68) = 0;
  _vfs_mountroot();
  *(undefined1 *)(_active_u + 0x98) = 0xf;
  _file_init();
  local_10 = _newproc(0);
  *(undefined4 *)(*(int *)(local_10 + 0xc) + 0x4c) = 0;
  _init_proc = _pfind(1);
  _ux_handler_init();
  _port_reference(_ux_exception_port);
  _task_set_special_port(*(task_t *)(local_10 + 0xc),3,_ux_exception_port);
  _thread_start(local_10,_init_task);
  _thread_resume(local_10);
  _power_init();
  _pageoutThread = _kernel_thread(_kernel_task,_vm_pageout,0);
  _vol_start_thread();
  _pnotify_start();
  *(byte *)(*_active_u + 0x28) = *(byte *)(*_active_u + 0x28) | 3;
  uVar7 = 0xffffffff;
  pcVar9 = s_kernel_idle_001da020;
  do {
    if (uVar7 == 0) break;
    uVar7 = uVar7 - 1;
    cVar1 = *pcVar9;
    pcVar9 = pcVar9 + 1;
  } while (cVar1 != '\0');
  sVar6 = 0x11;
  if (~uVar7 - 1 < 0x11) {
    sVar6 = ~uVar7;
  }
  _bcopy(s_kernel_idle_001da020,_active_u + 2,sVar6);
  _thread_terminate(_active_threads);
  _thread_halt_self();
  return;
}

