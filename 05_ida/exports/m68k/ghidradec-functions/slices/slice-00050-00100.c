/* GHIDRADEC_FUNCTION index=50 start=0x4001f12 */

void trap6(void)

{
  undefined4 in_D0;
  
  *(undefined4 *)(*(int *)(_active_threads + 0x24) + 0x50) = in_D0;
  return;
}
/* GHIDRADEC_FUNCTION index=51 start=0x4001f22 */

void addrerr(undefined8 param_1)

{
  undefined *puVar1;
  undefined auStack_40 [8];
  
  param_1._2_4_ = param_1._2_4_ >> 0x1c;
  if (((param_1._2_4_ != 2) && (param_1._2_4_ != 10)) && (param_1._2_4_ != 0xb)) {
                    /* WARNING: Subroutine does not return */
    _panic(aAddrerrBadExce);
  }
  puVar1 = auStack_40;
  if (((undefined *)0x4001318 < auStack_40) &&
     ((_stack_pointers < auStack_40 || (auStack_40 <= _stack_pointers + -0xff4)))) {
    puVar1 = _stack_pointers;
  }
  *(undefined **)(puVar1 + -4) = auStack_40;
  *(undefined4 *)(puVar1 + -0x14) = 0xc;
  func_0x0400217c();
  return;
}
/* GHIDRADEC_FUNCTION index=52 start=0x4001f96 */

//Decompiler native message:  Low-level Error: Cannot properly adjust input varnodes
//Decompiling function: buserr @ 0x4001f96
/* GHIDRADEC_FUNCTION index=53 start=0x400221e */

void fpsp_done(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=54 start=0x4002220 */

void fpsp_frame_err(void)

{
                    /* WARNING: Subroutine does not return */
  _panic(aFpspFrameForma);
}
/* GHIDRADEC_FUNCTION index=55 start=0x4002232 */

void trace(void)

{
  std_trap();
  return;
}
/* GHIDRADEC_FUNCTION index=56 start=0x4002238 */

void _cache_push(void)

{
  if (_cpu_type != '\0') {
    pushInvalidateCaches(3);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=57 start=0x4002262 */

void _mon_exit(void)

{
  int iVar1;
  word in_stack_00000000;
  
  if ((in_stack_00000000 & 0x2000) == 0) {
    iVar1 = _suser();
    if (iVar1 == 0) {
      return;
    }
  }
                    /* WARNING: Could not recover jumptable at 0x04002282. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_reboot_vector)();
  return;
}
/* GHIDRADEC_FUNCTION index=58 start=0x4002284 */

void _rpause(void)

{
  int *piVar1;
  int iVar2;
  byte bVar3;
  
  piVar1 = *(int **)(dword_40B57D4 + 0x24);
  if ((*piVar1 != 0x1c) || (piVar1[1] != 0x7fffffff)) goto loc_40022E4;
  bVar3 = *(byte *)(_active_u + 0x254);
  iVar2 = piVar1[2];
  if (iVar2 == 1) {
    *(byte *)(_active_u + 0x254) = bVar3 & 0xf7;
loc_40022F2:
    if ((bVar3 & 8) == 0) {
      *(undefined4 *)(dword_40B57D4 + 0x5c) = 0;
    }
    else {
      *(undefined4 *)(dword_40B57D4 + 0x5c) = 0x7fffffff;
    }
  }
  else {
    if (iVar2 < 2) {
      if (iVar2 == 0) goto loc_40022F2;
    }
    else if (iVar2 == 2) {
      *(byte *)(_active_u + 0x254) = bVar3 | 8;
      goto loc_40022F2;
    }
loc_40022E4:
    *(undefined *)(dword_40B57D4 + 100) = 0x16;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=59 start=0x4002314 */

void _table(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int *piVar11;
  int *piVar12;
  undefined4 *puVar13;
  undefined *puVar14;
  undefined auStack_b2 [4];
  undefined2 uStack_ae;
  int iStack_ac;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  char acStack_98 [8];
  int iStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  int iStack_80;
  int iStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined auStack_64 [16];
  int iStack_54;
  int iStack_50;
  int iStack_4c;
  int iStack_48;
  int iStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined auStack_38 [16];
  undefined uStack_28;
  int aiStack_24 [3];
  undefined4 uStack_18;
  int aiStack_14 [4];
  
  piVar1 = *(int **)(dword_40B57D4 + 0x24);
  iVar9 = 0;
  iVar10 = 0;
  if (piVar1[3] < 0) {
    iVar10 = _machine_table_setokay(*piVar1);
    if (((iVar10 == 0) || (iVar10 < 1)) || (iVar10 != 1)) {
      *(undefined *)(dword_40B57D4 + 100) = 0x16;
      return;
    }
    iVar10 = 1;
    piVar1[3] = -piVar1[3];
  }
  *(undefined4 *)(dword_40B57D4 + 0x5c) = 0;
  if ((*piVar1 == 1) &&
     ((((int)*(sword *)(*_active_u + 0x30) != piVar1[1] && (piVar1[1] != 0)) || (piVar1[3] != 1))))
  {
loc_4002848:
    if (*(int *)(dword_40B57D4 + 0x5c) == 0) {
      *(undefined *)(dword_40B57D4 + 100) = 0x16;
    }
  }
  else {
    while (0 < piVar1[3]) {
      piVar7 = (int *)0x0;
      uVar8 = 0;
      iVar5 = _machine_table(*piVar1,piVar1[1],piVar1[2],piVar1[3],piVar1[4],iVar10);
      if (iVar5 != 0) {
        if ((0 < iVar5) && (iVar5 == 1)) goto loc_40028CE;
        goto loc_4002848;
      }
      switch(*piVar1) {
      case :
        if (*(int *)((int)_active_u + 0x15e) == 0) {
          uStack_ae = 0xffff;
          piVar12 = (int *)&uStack_ae;
        }
        else {
          piVar12 = (int *)((int)_active_u + 0x162);
        }
        uVar6 = 2;
        break;
      case :
        iVar5 = _pfind(piVar1[1]);
        if ((iVar5 == 0) || (*(int *)(*(int *)(iVar5 + 0x66) + 0x20) < 1)) {
loc_400235A:
          *(undefined *)(dword_40B57D4 + 100) = 3;
          return;
        }
        uVar2 = *(undefined4 *)(*(int *)(iVar5 + 0x66) + 0x18);
        _thread_reference(uVar2);
        piVar7 = (int *)_kmem_alloc_wait(_kernel_pageable_map,~_page_mask & _page_mask + 0x7f0);
        _fake_u(piVar7,uVar2);
        _thread_deallocate(uVar2);
        uVar6 = 0x7f0;
        uVar8 = (~_page_mask & _page_mask + 0x7f0) + (int)piVar7;
        piVar12 = piVar7;
        break;
      case :
        if ((piVar1[1] == 0) && (piVar1[3] == 1)) {
          puVar14 = _avenrun;
          goto loc_4002700;
        }
      :
        goto loc_4002848;
      case :
        iVar5 = _table_fsparam(piVar1[1],aiStack_14);
        if (iVar5 == 0) goto loc_4002848;
        uVar6 = 0x10;
        piVar12 = aiStack_14;
        break;
      case :
        iVar5 = _pfind(piVar1[1]);
        if (iVar5 == 0) goto loc_400235A;
        uVar2 = *(undefined4 *)(*(int *)(iVar5 + 0x66) + 8);
        uVar6 = piVar1[4];
        if ((uVar6 == 0) || (iVar5 = *(int *)(iVar5 + 0x82), iVar5 == 0)) goto loc_4002848;
        _vm_map_reference(uVar2);
        piVar7 = (int *)_kmem_alloc_wait(_kernel_pageable_map,~_page_mask & _page_mask + uVar6);
        uVar4 = ~_page_mask;
        uVar8 = uVar4 & (int)piVar7 + _page_mask + uVar6;
        iVar5 = _vm_map_copy(_kernel_pageable_map,uVar2,piVar7,uVar4 & uVar6 + _page_mask,
                             uVar4 & iVar5 - uVar6,0,0);
        if (iVar5 != 0) {
          _kmem_free_wakeup(_kernel_pageable_map,piVar7,~_page_mask & _page_mask + uVar6);
          _vm_map_deallocate(uVar2);
          goto loc_4002848;
        }
        _vm_map_deallocate(uVar2);
        piVar12 = (int *)(uVar8 - uVar6);
        piVar11 = (int *)(uVar8 - 0xc);
        iVar5 = *piVar11;
        while ((iVar5 != 0 && (piVar12 != piVar11))) {
          piVar11 = piVar11 + -1;
          iVar5 = *piVar11;
        }
        _bzero(piVar12,(int)piVar11 - (int)piVar12);
        break;
      case :
        if (piVar1[1] < 0) {
          piVar1[1] = -piVar1[1];
        }
        iVar5 = _pfind(piVar1[1]);
        if (iVar5 == 0) goto loc_400235A;
        if (*(char *)(iVar5 + 0x13) == '\0') {
          _bzero(&iStack_54,0x30);
          uStack_40 = 0;
        }
        else {
          iStack_54 = (int)*(sword *)(iVar5 + 0x2c);
          iStack_50 = (int)*(sword *)(iVar5 + 0x30);
          iStack_4c = (int)*(sword *)(iVar5 + 0x32);
          iStack_48 = (int)*(sword *)(iVar5 + 0x2e);
          uStack_3c = *(undefined4 *)(iVar5 + 0x28);
          if (*(int *)(iVar5 + 0x66) == 0) {
            uStack_40 = 3;
          }
          else {
            iVar3 = *(int *)(*(int *)(iVar5 + 0x66) + 0x30);
            if (*(int *)(iVar3 + 0x15e) == 0) {
              iStack_44 = -1;
            }
            else {
              iStack_44 = (int)*(sword *)(iVar3 + 0x162);
            }
            _bcopy(iVar3 + 8,auStack_38,0x10);
            uStack_28 = 0;
            uStack_40 = 1;
            if ((*(byte *)(iVar5 + 0x2a) & 4) != 0) {
              uStack_40 = 2;
            }
          }
        }
        uVar6 = 0x30;
        piVar12 = &iStack_54;
        break;
      case :
        if ((piVar1[1] != 0) || (piVar1[3] != 1)) goto loc_4002848;
        puVar14 = _mach_factor;
loc_4002700:
        _bcopy(puVar14,aiStack_24,0xc);
        uStack_18 = 1000;
        uVar6 = 0x10;
        piVar12 = aiStack_24;
        break;
      case :
        if ((piVar1[1] != 0) || (piVar1[3] != 1)) goto loc_4002848;
        iStack_7c = _cnt;
        uStack_78 = dword_40B565C;
        uStack_74 = dword_40B5658;
        uStack_70 = dword_40B5654;
        uStack_6c = _hz;
        uStack_68 = 0;
        _bcopy(_cp_time,auStack_64,0x10);
        uVar6 = 0x28;
        piVar12 = &iStack_7c;
        break;
      case :
        if ((piVar1[1] != 0) || (piVar1[3] != 1)) goto loc_4002848;
        iStack_90 = _tk_nin;
        uStack_8c = _tk_nout;
        uStack_88 = _dk_busy;
        uStack_84 = _dk_ndrive;
        iStack_80 = 0;
        for (puVar13 = _ifnet; puVar13 != (undefined4 *)0x0;
            puVar13 = *(undefined4 **)((int)puVar13 + 0x5a)) {
          iStack_80 = iStack_80 + 1;
        }
        uVar6 = 0x14;
        piVar12 = &iStack_90;
        break;
      case :
        iVar5 = piVar1[1];
        puVar13 = _ifnet;
        if (_ifnet == (undefined4 *)0x0) goto loc_4002848;
        do {
          if (iVar5 == 0) break;
          puVar13 = *(undefined4 **)((int)puVar13 + 0x5a);
          iVar5 = iVar5 + -1;
        } while (puVar13 != (undefined4 *)0x0);
        if (puVar13 == (undefined4 *)0x0) goto loc_4002848;
        iStack_ac = *(int *)((int)puVar13 + 0x42);
        uStack_a8 = *(undefined4 *)((int)puVar13 + 0x46);
        uStack_a4 = *(undefined4 *)((int)puVar13 + 0x4a);
        uStack_a0 = *(undefined4 *)((int)puVar13 + 0x4e);
        uStack_9c = *(undefined4 *)((int)puVar13 + 0x52);
        _strncpy(acStack_98,*puVar13,6);
        iVar5 = _strlen(acStack_98);
        acStack_98[iVar5] = *(char *)((int)puVar13 + 9) + '0';
        acStack_98[iVar5 + 1] = '\0';
        uVar6 = 0x1c;
        piVar12 = &iStack_ac;
      }
      if ((uint)piVar1[4] < uVar6) {
        uVar6 = piVar1[4];
      }
      if (uVar6 != 0) {
        if (iVar10 == 0) {
          iVar9 = _copyoutmsg(piVar12,piVar1[2],uVar6);
        }
        else {
          iVar9 = _copyinmsg(piVar1[2],auStack_b2,uVar6);
          if (iVar9 == 0) {
            _bcopy(auStack_b2,piVar12,uVar6);
          }
        }
      }
      if (piVar7 != (int *)0x0) {
        _kmem_free_wakeup(_kernel_pageable_map,piVar7,uVar8 - (int)piVar7);
      }
      if (iVar9 != 0) {
        *(char *)(dword_40B57D4 + 100) = (char)iVar9;
        return;
      }
loc_40028CE:
      piVar1[2] = piVar1[4] + piVar1[2];
      piVar1[3] = piVar1[3] + -1;
      piVar1[1] = piVar1[1] + 1;
      *(int *)(dword_40B57D4 + 0x5c) = *(int *)(dword_40B57D4 + 0x5c) + 1;
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=60 start=0x40028fa */

undefined4 _table_fsparam(void)

{
  int iVar1;
  
  for (iVar1 = _mounttab; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x1c)) {
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=61 start=0x4002916 */

void _task_name(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = _strlen(param_1);
  iVar2 = 0x11;
  if (uVar1 < 0x11) {
    iVar2 = uVar1 + 1;
  }
  _bcopy(param_1,_active_u + 8,iVar2);
  return;
}
/* GHIDRADEC_FUNCTION index=62 start=0x4002958 */

void _main(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int iStack_10;
  undefined auStack_c [4];
  undefined auStack_8 [4];
  
  _pqinit();
  iVar5 = _kernel_proc;
  *(int *)(_kernel_task + 0x34) = _kernel_proc;
  *(undefined2 *)(iVar5 + 0x30) = 0;
  _pidhash_enter(iVar5);
  *(int *)(iVar5 + 0x66) = _kernel_task;
  _calloutInitialize();
  _switch_unix_context(_active_threads);
  *(undefined *)(iVar5 + 0x13) = 3;
  *(uint *)(iVar5 + 0x28) = *(uint *)(iVar5 + 0x28) | 3;
  *(undefined *)(iVar5 + 0x15) = 0;
  *(undefined4 *)(iVar5 + 0x72) = 0;
  *(undefined4 *)(iVar5 + 0x76) = 0;
  *_active_u = iVar5;
  uVar2 = _crget();
  *(undefined4 *)((int)_active_u + 0x1a) = uVar2;
  *(undefined2 *)(_active_u + 0x59) = word_40ADB3A;
  *(undefined4 *)((int)_active_u + 0x14e) = 0xffffffff;
  uVar4 = 0;
  do {
    piVar1 = _active_u;
    *(undefined4 *)((int)_active_u + uVar4 * 8 + 0x25a) = 0x7fffffff;
    *(undefined4 *)((int)piVar1 + uVar4 * 8 + 0x256) = 0x7fffffff;
    piVar1 = _active_u;
    uVar2 = dword_40ADB40;
    uVar4 = uVar4 + 1;
  } while (uVar4 < 6);
  *(undefined4 *)((int)_active_u + 0x26e) = _vm_initial_limit_stack;
  *(undefined4 *)((int)piVar1 + 0x272) = uVar2;
  piVar1 = _active_u;
  uVar2 = dword_40ADB48;
  *(undefined4 *)((int)_active_u + 0x266) = _vm_initial_limit_data;
  *(undefined4 *)((int)piVar1 + 0x26a) = uVar2;
  piVar1 = _active_u;
  uVar2 = dword_40ADB50;
  *(undefined4 *)((int)_active_u + 0x276) = _vm_initial_limit_core;
  *(undefined4 *)((int)piVar1 + 0x27a) = uVar2;
  puVar6 = (undefined4 *)_posix_proc_hash;
  puVar8 = &_pgrphash;
  do {
    *puVar8 = 0;
    puVar7 = puVar6 + 1;
    *puVar6 = 0;
    puVar6 = puVar7;
    puVar8 = puVar8 + 1;
  } while ((int)puVar7 < 0x40b6001);
  iVar3 = _new_posix_proc(0);
  _px = iVar3;
  *(undefined4 **)(iVar3 + 0xe) = &_pgrp0;
  *(undefined4 *)(iVar3 + 10) = 0;
  *(undefined2 *)(iVar3 + 4) = *(undefined2 *)(*(int *)((int)_active_u + 0x1a) + 6);
  *(undefined2 *)(iVar3 + 6) = *(undefined2 *)(*(int *)((int)_active_u + 0x1a) + 2);
  *(undefined2 *)(iVar3 + 8) = *(undefined2 *)(*(int *)((int)_active_u + 0x1a) + 4);
  *(undefined4 *)(iVar3 + 0x12) = 0;
  *(byte *)(iVar3 + 0x16) = *(byte *)(iVar3 + 0x16) & 0x7f;
  *(byte *)(_px + 0x16) = *(byte *)(_px + 0x16) & 0xbf;
  _pgrphash = &_pgrp0;
  unk_40B5DF4 = iVar5;
  dword_40B5DF8 = &_session0;
  _pgrp0 = 0;
  dword_40B5E00 = 0;
  _session0 = 1;
  dword_40B6018 = iVar5;
  dword_40B601C = 0;
  word_40B6020 = 0;
  _gc_init();
  _kernel_pageable_map = _kmem_suballoc(_kernel_map,auStack_8,auStack_c,0x80000,1);
  _ns_timer_init();
  _ns_hardclock_init();
  _mfs_init();
  _lock_init((int)_active_u + 0x1e,1);
  **(sword **)((int)_active_u + 0x1a) = **(sword **)((int)_active_u + 0x1a) + 1;
  _rootcred = *(undefined4 *)((int)_active_u + 0x1a);
  iVar5 = 1;
  do {
    *(undefined2 *)(*(int *)((int)_active_u + 0x1a) + 10 + iVar5 * 2) = 0xffff;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 0x10);
  _mbinit();
  _cinit();
  _ifinit();
  _domaininit();
  _bhinit();
  _dnlc_init();
  *(undefined4 *)((int)_active_u + 0x15a) = 0;
  *(undefined4 *)((int)_active_u + 0x156) = 0;
  iVar5 = 0;
  do {
    if ((&_machine_slot)[iVar5 * 8] != 0) {
      _thread_create(_kernel_task,&iStack_10);
      _thread_bind(iStack_10,(&_processor_ptr)[iVar5]);
      _thread_start(iStack_10,_idle_thread);
      _thread_doswapin(iStack_10);
      _thread_resume(iStack_10);
    }
    iVar5 = iVar5 + 1;
  } while (iVar5 < 1);
  _binit();
  _recompute_priorities();
  _lightning_bolt(0,0);
  _kernel_thread(_kernel_task,_reaper_thread,0);
  _kernel_thread(_kernel_task,_swapin_thread,0);
  _kernel_thread(_kernel_task,_sched_thread,0);
  _kernel_thread(_kernel_task,_netisr_thread,0);
  _loattach();
  *(undefined *)(dword_40B57D4 + 100) = 0;
  _vfs_mountroot();
  *(undefined *)(_active_u + 0x95) = 0xf;
  _softint_thread = _kernel_thread(_kernel_task,_softint_th,0);
  _file_init();
  iStack_10 = _newproc(0);
  *(undefined4 *)(*(int *)(iStack_10 + 0xc) + 0x44) = 0;
  _init_proc = _pfind(1);
  _ux_handler_init();
  _port_reference(_ux_exception_port);
  _task_set_special_port(*(undefined4 *)(iStack_10 + 0xc),3,_ux_exception_port);
  _thread_start(iStack_10,_init_task);
  _thread_resume(iStack_10);
  _power_init();
  _pageoutThread = _kernel_thread(_kernel_task,_vm_pageout,0);
  _vol_start_thread();
  _pnotify_start();
  *(uint *)(*_active_u + 0x28) = *(uint *)(*_active_u + 0x28) | 3;
  _task_name(aKernelIdle);
  _thread_terminate(_active_threads);
  _thread_halt_self();
  return;
}
/* GHIDRADEC_FUNCTION index=63 start=0x4002dc8 */

void _init_task(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  _task_name(&aInit);
  puVar1 = dword_40B57D4;
  if (*(int *)(*(int *)(_active_threads + 0x24) + 0x4c) == 0) {
    uVar2 = _thread_user_state(_active_threads);
  }
  else {
    uVar2 = *(undefined4 *)(*(int *)(_active_threads + 0x24) + 0x48);
  }
  *puVar1 = uVar2;
  _load_init_program();
  _thread_exception_return();
  return;
}
/* GHIDRADEC_FUNCTION index=64 start=0x4002e1c */

void _lightning_bolt(undefined4 param_1,int param_2)

{
  undefined8 uVar1;
  
  _thread_wakeup_prim(&_lbolt,0,0);
  if (param_2 == 0) {
    param_2 = _calloutEntryAllocate(_lightning_bolt,0);
  }
  uVar1 = _calloutDeadlineFromInterval(0,1000000000);
  _calloutEntryDispatchDelayed(param_2,uVar1);
  return;
}
/* GHIDRADEC_FUNCTION index=65 start=0x4002e76 */

void _bhinit(void)

{
  int iVar1;
  undefined *puVar2;
  
  puVar2 = _bufhash;
  iVar1 = 0;
  do {
    *(undefined **)(puVar2 + 8) = puVar2;
    *(undefined **)(puVar2 + 4) = puVar2;
    iVar1 = iVar1 + 1;
    puVar2 = puVar2 + 0xc;
  } while (iVar1 < 0x10);
  return;
}
/* GHIDRADEC_FUNCTION index=66 start=0x4002e9a */

void _binit(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  
  puVar6 = &_bfreelist;
  do {
    puVar6[4] = puVar6;
    puVar6[3] = puVar6;
    puVar6[2] = puVar6;
    puVar6[1] = puVar6;
    *puVar6 = 0x40000;
    puVar6 = puVar6 + 0x11;
  } while (puVar6 < &_buf);
  iVar5 = _bufpages % _nbuf;
  iVar4 = _bufpages / _nbuf;
  iVar2 = 0;
  if (0 < _nbuf) {
    iVar3 = 0;
    iVar7 = 0;
    do {
      puVar6 = (undefined4 *)(iVar7 + _buf);
      *(undefined2 *)((int)puVar6 + 0x1e) = 0xffff;
      puVar6[5] = 0;
      puVar6[8] = iVar3 + _buffers;
      iVar1 = iVar4;
      if (iVar2 < iVar5) {
        iVar1 = iVar4 + 1;
      }
      puVar6[6] = _page_size * iVar1;
      puVar6[0xf] = 0;
      if (puVar6[6] == 0) {
        puVar6[1] = dword_40B58A8;
        puVar6[2] = &DAT_40b58a4;
        dword_40B58A8[2] = puVar6;
        dword_40B58A8 = puVar6;
      }
      else {
        puVar6[1] = dword_40B5864;
        puVar6[2] = &unk_40B5860;
        dword_40B5864[2] = puVar6;
        dword_40B5864 = puVar6;
      }
      puVar6[0x10] = 0;
      *puVar6 = 0x10008;
      _brelse(puVar6);
      iVar3 = iVar3 + 0x2000;
      iVar7 = iVar7 + 0x44;
      iVar2 = iVar2 + 1;
    } while (iVar2 < _nbuf);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=67 start=0x4002fa2 */

void _cinit(void)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  uint *puVar4;
  
  iVar2 = _nclist * 0x40;
  iVar1 = _cfree + -0x40;
  puVar4 = (uint *)(_cfree + 0x3fU & 0xffffffc0);
  while (puVar3 = puVar4, puVar3 < (uint)(iVar1 + iVar2)) {
    *puVar3 = (uint)_cfreelist;
    _cfreecount = _cfreecount + 0x34;
    _cfreelist = puVar3;
    puVar4 = puVar3 + 0x10;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=68 start=0x4002fec */

void _sysacct(void)

{
  int *piVar1;
  int iVar2;
  undefined uVar3;
  int iStack_8;
  
  piVar1 = *(int **)(dword_40B57D4 + 0x24);
  iVar2 = _suser();
  if (iVar2 != 0) {
    if (_savacctp != 0) {
      _acctp = _savacctp;
      _savacctp = 0;
    }
    iVar2 = _acctp;
    if (*piVar1 == 0) {
      iStack_8 = _acctp;
      if (_acctp != 0) {
        _acctp = 0;
        _vn_rele(iVar2);
      }
    }
    else {
      uVar3 = _lookupname(*piVar1,0,1,0,&iStack_8);
      *(undefined *)(dword_40B57D4 + 100) = uVar3;
      iVar2 = _acctp;
      if (*(char *)(dword_40B57D4 + 100) == '\0') {
        if (*(int *)(iStack_8 + 0x28) == 1) {
          if ((*(byte *)(*(int *)(iStack_8 + 0x24) + 0xf) & 1) == 0) {
            if (_acctp == 0) {
              _acctp = iStack_8;
            }
            else {
              _acctp = iStack_8;
              _vn_rele(iVar2);
            }
            if (_acctcred != 0) {
              _crfree(_acctcred);
            }
            _acctcred = _crdup(*(undefined4 *)(_active_u + 0x1a));
            return;
          }
          *(undefined *)(dword_40B57D4 + 100) = 0x1e;
        }
        else {
          *(undefined *)(dword_40B57D4 + 100) = 0xd;
        }
        _vn_rele(iStack_8);
      }
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=69 start=0x40030f0 */

void _acct(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined uVar6;
  uint uVar7;
  undefined4 **ppuVar8;
  undefined4 *puStack_78;
  int iStack_4c;
  int iStack_48;
  undefined4 auStack_44 [2];
  int iStack_3c;
  int iStack_34;
  
  if (_savacctp != 0) {
    puStack_78 = auStack_44;
    (**(code **)(*(int *)(*(int *)(_savacctp + 0x24) + 4) + 0xc))(*(int *)(_savacctp + 0x24));
    if ((iStack_3c * _acctresume) / 100 < iStack_34) {
      _acctp = _savacctp;
      _savacctp = 0;
      puStack_78 = (undefined4 *)aAccountingResu;
      _printf();
    }
  }
  iVar5 = _acctp;
  if (_acctp != 0) {
    *(sword *)(_acctp + 6) = *(sword *)(_acctp + 6) + 1;
    puStack_78 = auStack_44;
    (**(code **)(*(int *)(*(int *)(iVar5 + 0x24) + 4) + 0xc))(*(int *)(iVar5 + 0x24));
    if ((iStack_3c * _acctsuspend) / 100 < iStack_34) {
      uVar7 = 0;
      do {
        _acctbuf[uVar7] = *(undefined *)(_active_u + 8 + uVar7);
        iVar4 = _active_u;
        uVar7 = uVar7 + 1;
      } while (uVar7 < 10);
      puVar2 = (undefined4 *)(_active_u + 0x166);
      puStack_78 = *(undefined4 **)(_active_u + 0x16a);
      DAT_40b603a._0_2_ = _compress(*puVar2);
      DAT_40b603a._2_2_ = _compress(*(undefined4 *)(iVar4 + 0x16e),*(undefined4 *)(iVar4 + 0x172));
      _microtime(&iStack_4c);
      _timevalsub(&iStack_4c,_active_u + 0x232);
      DAT_40b603a._4_2_ = _compress(iStack_4c,iStack_48);
      DAT_40b603a._6_4_ = *(undefined4 *)(_active_u + 0x232);
      DAT_40b603a._10_2_ = *(undefined2 *)(*(int *)(_active_u + 0x1a) + 6);
      DAT_40b603a._12_2_ = *(undefined2 *)(*(int *)(_active_u + 0x1a) + 8);
      iStack_4c = *(int *)(iVar4 + 0x16e);
      iStack_48 = *(int *)(iVar4 + 0x172);
      puStack_78 = puVar2;
      _timevaladd(&iStack_4c);
      iVar3 = iStack_48 / _tick + _hz * iStack_4c;
      if (iVar3 == 0) {
        DAT_40b603a._14_2_ = 0;
      }
      else {
        DAT_40b603a._14_2_ =
             (undefined2)
             ((*(int *)(iVar4 + 0x182) + *(int *)(iVar4 + 0x17e) + *(int *)(iVar4 + 0x17a)) / iVar3)
        ;
      }
      puStack_78 = (undefined4 *)0x0;
      DAT_40b603a._16_2_ = _compress(*(int *)(iVar4 + 0x196) + *(int *)(iVar4 + 0x192));
      if (*(int *)(_active_u + 0x15e) == 0) {
        DAT_40b603a._18_2_ = 0xffff;
      }
      else {
        DAT_40b603a._18_2_ = *(undefined2 *)(_active_u + 0x162);
      }
      DAT_40b603a[0x14] = *(undefined *)(_active_u + 0x23b);
      uVar1 = *(undefined4 *)(_active_u + 0x1a);
      *(undefined4 *)(_active_u + 0x1a) = _acctcred;
      puStack_78 = (undefined4 *)0x0;
      uVar6 = _vn_rdwr(1,iVar5,_acctbuf,0x20,0,1,3);
      *(undefined *)(dword_40B57D4 + 100) = uVar6;
      *(undefined4 *)(_active_u + 0x1a) = uVar1;
      ppuVar8 = (undefined4 **)&stack0xffffff8c;
    }
    else {
      _savacctp = _acctp;
      _acctp = 0;
      ppuVar8 = &puStack_78;
      puStack_78 = (undefined4 *)aAccountingSusp;
      _printf();
    }
    *(int *)((int)ppuVar8 + -4) = iVar5;
    *(undefined4 *)((int)ppuVar8 + -8) = 0x4003360;
    _vn_rele();
  }
  return;
}
/* GHIDRADEC_FUNCTION index=70 start=0x400336a */

int _compress(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = 0;
  uVar3 = 0;
  uVar1 = param_1 * 0x40;
  if (param_2 != 0) {
    uVar1 = param_2 / 0x3d09 + uVar1;
  }
  for (; 0x1fff < (int)uVar1; uVar1 = (int)uVar1 >> 3) {
    iVar2 = iVar2 + 1;
    uVar3 = uVar1 & 4;
  }
  if ((uVar3 != 0) && (uVar1 = uVar1 + 1, 0x1fff < (int)uVar1)) {
    uVar1 = (int)uVar1 >> 3;
    iVar2 = iVar2 + 1;
  }
  return uVar1 + iVar2 * 0x2000;
}
/* GHIDRADEC_FUNCTION index=71 start=0x40033d2 */

void _hardclock(undefined4 param_1,uint param_2)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined8 uVar6;
  int aiStack_20 [2];
  int aiStack_18 [2];
  uint uStack_10;
  int iStack_c;
  
  iVar3 = _active_threads;
  uVar6 = _clock_value(1);
  iStack_c = (uint)uVar6 - _last_hardclock._4_4_;
  uVar5 = (int)((qword)uVar6 >> 0x20) -
          ((uint)((uint)uVar6 < _last_hardclock._4_4_) + _last_hardclock._0_4_);
  uStack_10 = uVar5 / 1000;
  uVar4 = (undefined4)(CONCAT44(uVar5 % 1000,iStack_c) / 1000);
  _last_hardclock = uVar6;
  if ((param_2 & 0x2000) == 0) {
    if ((*_active_u != 0) && (_active_u[0x94] != 0)) {
      pbVar1 = (byte *)(*_active_u + 0x29);
      *pbVar1 = *pbVar1 | 0x20;
      _need_ast = _need_ast | 0x20;
      if (_need_ast != 0) {
        pbVar1 = (byte *)(*(int *)(_active_threads + 0x24) + 0x54);
        *pbVar1 = *pbVar1 | 0x10;
      }
    }
    if ((*(int *)((int)_active_u + 0x20e) != 0) || (*(int *)((int)_active_u + 0x212) != 0)) {
      iVar2 = _itimerdecr((int)_active_u + 0x206,uVar4);
      if (iVar2 == 0) {
        _psignal(*_active_u,0x1a);
      }
    }
  }
  if ((*_active_u != 0) && (-1 < *(char *)(iVar3 + 0x4b))) {
    if (*(int *)((int)_active_u + 0x256) != 0x7fffffff) {
      _thread_read_times(iVar3,aiStack_18,aiStack_20);
      if (*(int *)((int)_active_u + 0x256) < aiStack_18[0] + aiStack_20[0] + 1) {
        _psignal(*_active_u,0x18);
        if (*(int *)((int)_active_u + 0x256) < *(int *)((int)_active_u + 0x25a)) {
          *(int *)((int)_active_u + 0x256) = *(int *)((int)_active_u + 0x256) + 5;
        }
      }
    }
    if ((*(int *)((int)_active_u + 0x21e) != 0) || (*(int *)((int)_active_u + 0x222) != 0)) {
      iVar3 = _itimerdecr((int)_active_u + 0x216,uVar4);
      if (iVar3 == 0) {
        _psignal(*_active_u,0x1b);
      }
    }
  }
  _gatherstats(param_1,param_2);
  return;
}
/* GHIDRADEC_FUNCTION index=72 start=0x4003574 */

void _gatherstats(undefined4 param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined *puVar4;
  
  if ((param_2 & 0x2000) == 0) {
    iVar3 = 0;
    if ('\0' < *(char *)(*_active_u + 0x15)) {
      iVar3 = 1;
    }
  }
  else {
    iVar3 = 2;
    if ((*(char *)(_active_threads + 0x4b) < '\0') && ((param_2 & 0x700) == 0)) {
      iVar3 = 3;
    }
  }
  *(int *)(_cp_time + iVar3 * 4) = *(int *)(_cp_time + iVar3 * 4) + 1;
  uVar1 = _dk_busy;
  uVar2 = 0;
  puVar4 = _dk_time;
  do {
    if ((uVar1 & 1 << (uVar2 & 0x1f)) != 0) {
      *(int *)puVar4 = *(int *)puVar4 + 1;
    }
    puVar4 = (undefined *)((int)puVar4 + 4);
    uVar2 = uVar2 + 1;
  } while ((int)uVar2 < 4);
  return;
}
/* GHIDRADEC_FUNCTION index=73 start=0x40035e0 */

void _timeout(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined8 uVar1;
  
  uVar1 = _ticks_to_ns_time(param_3,0);
  _ns_timeout(param_1,param_2,uVar1);
  return;
}
/* GHIDRADEC_FUNCTION index=74 start=0x4003618 */

void _untimeout(undefined4 param_1,undefined4 param_2)

{
  _ns_untimeout(param_1,param_2);
  return;
}
/* GHIDRADEC_FUNCTION index=75 start=0x400362e */

int _hzto(int *param_1)

{
  int iVar1;
  int iStack_c;
  int iStack_8;
  
  _getthetime(&iStack_c);
  iStack_c = *param_1 - iStack_c;
  if (iStack_c < 0x20c0b4) {
    iVar1 = ((param_1[1] - iStack_8) / 1000 + iStack_c * 1000) / (_tick / 1000);
  }
  else {
    iVar1 = 0x7fffffff;
    if (iStack_c <= 0x7fffffff / _hz) {
      iVar1 = _hz * iStack_c;
    }
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=76 start=0x40036cc */

void _ticks_to_timeval(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = param_1 % _hz;
  *param_2 = param_1 / _hz;
  param_2[1] = _tick * iVar1;
  return;
}
/* GHIDRADEC_FUNCTION index=77 start=0x40036f2 */

void _profil(void)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = _active_u;
  puVar1 = *(undefined4 **)(dword_40B57D4 + 0x24);
  piVar3 = (int *)(_active_u + 0x23c);
  *(undefined4 *)(_active_u + 0x244) = *puVar1;
  *(undefined4 *)(iVar4 + 0x248) = puVar1[1];
  *(undefined4 *)(iVar4 + 0x24c) = puVar1[2];
  *(undefined4 *)(iVar4 + 0x250) = puVar1[3];
  if (*piVar3 == 0) {
    iVar5 = _simple_lock_alloc();
    *piVar3 = iVar5;
  }
  iVar5 = *(int *)(iVar4 + 0x240);
  while (iVar5 != 0) {
    iVar2 = *(int *)(iVar5 + 4);
    _kfree(iVar5,0x18);
    iVar5 = iVar2;
  }
  *(undefined4 *)(iVar4 + 0x240) = 0;
  return;
}
/* GHIDRADEC_FUNCTION index=78 start=0x400375e */

void _add_profil(void)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = _active_u;
  puVar1 = *(undefined4 **)(dword_40B57D4 + 0x24);
  if (*(int *)(_active_u + 0x250) != 0) {
    iVar3 = _kalloc(0x18);
    *(undefined4 *)(iVar3 + 8) = *puVar1;
    *(undefined4 *)(iVar3 + 0xc) = puVar1[1];
    *(undefined4 *)(iVar3 + 0x10) = puVar1[2];
    *(undefined4 *)(iVar3 + 0x14) = puVar1[3];
    *(undefined4 *)(iVar3 + 4) = *(undefined4 *)(iVar2 + 0x240);
    *(int *)(iVar2 + 0x240) = iVar3;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=79 start=0x40037b4 */

int _core(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined uVar7;
  int iVar5;
  int iVar6;
  int iVar8;
  uint uVar9;
  int iVar10;
  undefined4 *puVar11;
  int *piVar12;
  undefined *puVar13;
  int iStack_ee;
  undefined auStack_da [4];
  undefined auStack_d6 [4];
  undefined auStack_d2 [4];
  undefined auStack_ce [4];
  uint uStack_ca;
  uint uStack_c6;
  int iStack_c2;
  int iStack_be;
  undefined4 *puStack_ba;
  uint uStack_b6;
  int iStack_b2;
  int aiStack_ae [20];
  undefined auStack_5e [32];
  undefined4 uStack_3e;
  undefined2 uStack_3a;
  sword sStack_2c;
  undefined4 uStack_2a;
  
  if ((*(byte *)(*_active_u + 0x28) & 2) == 0) {
    *(undefined2 *)(*(int *)((int)_active_u + 0x1a) + 2) =
         *(undefined2 *)(*(int *)((int)_active_u + 0x1a) + 6);
    *(undefined2 *)(*_active_u + 0x2c) = *(undefined2 *)(*(int *)((int)_active_u + 0x1a) + 6);
    *(undefined2 *)(*(int *)((int)_active_u + 0x1a) + 4) =
         *(undefined2 *)(*(int *)((int)_active_u + 0x1a) + 8);
    *(undefined *)(_active_u + 0x95) = 0;
    iVar8 = *(int *)(_active_threads + 0xc);
    iVar1 = *(int *)(iVar8 + 8);
    if (*(uint *)(iVar1 + 0x24) < *(uint *)((int)_active_u + 0x276)) {
      _task_halt(iVar8);
      *(undefined *)(dword_40B57D4 + 100) = 0;
      _vattr_null(&uStack_3e);
      uStack_3e = 1;
      uStack_3a = 0x1a4;
      _sprintf(auStack_5e,aCoresCoreD,(int)*(sword *)(*_active_u + 0x30));
      uVar7 = _vn_create(auStack_5e,1,&uStack_3e,0,0x80,&iStack_b2,
                         *(undefined4 *)((int)_active_u + 0x1a));
      *(undefined *)(dword_40B57D4 + 100) = uVar7;
      if (*(char *)(dword_40B57D4 + 100) != '\0') {
        *(undefined *)(dword_40B57D4 + 100) = 0;
        _vattr_null(&uStack_3e);
        uStack_3e = 1;
        uStack_3a = 0x1a4;
        uVar7 = _vn_create(&aCore,1,&uStack_3e,0,0x80,&iStack_b2,
                           *(undefined4 *)((int)_active_u + 0x1a));
        *(undefined *)(dword_40B57D4 + 100) = uVar7;
        if (*(char *)(dword_40B57D4 + 100) != '\0') {
          return 0;
        }
      }
      if (sStack_2c == 1) {
        _vattr_null(&uStack_3e);
        uStack_2a = 0;
        (**(code **)(*(int *)(iStack_b2 + 0x1c) + 0x18))
                  (iStack_b2,&uStack_3e,*(undefined4 *)((int)_active_u + 0x1a));
        *(word *)((int)_active_u + 0x23a) = *(word *)((int)_active_u + 0x23a) | 8;
        iVar10 = *(int *)(iVar8 + 0x20);
        iVar2 = *(int *)(iVar1 + 0x18);
        uStack_b6 = 0x14;
        iVar5 = _thread_getstatus(_active_threads,0,aiStack_ae,&uStack_b6);
        if (iVar5 != 0) {
                    /* WARNING: Subroutine does not return */
          _panic(aCoreFlavorList);
        }
        uStack_b6 = uStack_b6 >> 1;
        iStack_ee = 0;
        uVar9 = 0;
        if (uStack_b6 != 0) {
          do {
            iStack_ee = iStack_ee + 8 + aiStack_ae[uVar9 * 2 + 1] * 4;
            uVar9 = uVar9 + 1;
          } while (uVar9 < uStack_b6);
        }
        iVar5 = iVar10 * iStack_ee + (iVar10 + iVar2 * 7) * 8;
        iVar4 = iVar5 + 0x1c;
        _kmem_alloc_wired(_kernel_map,&puStack_ba,iVar4);
        *puStack_ba = 0xfeedface;
        puStack_ba[1] = dword_40B5DCC;
        puStack_ba[2] = dword_40B5DD0;
        puStack_ba[3] = 4;
        puStack_ba[4] = iVar10 + iVar2;
        puStack_ba[5] = iVar5;
        iVar5 = 0x1c;
        uVar9 = ~_page_mask & _page_mask + iVar4;
        iStack_be = 0;
        while ((0 < iVar2 &&
               (iVar6 = _vm_region(iVar1,&iStack_be,&iStack_c2,&uStack_c6,&uStack_ca,auStack_ce,
                                   auStack_d2,auStack_d6,auStack_da), iVar6 != 3))) {
          puVar11 = (undefined4 *)(iVar5 + (int)puStack_ba);
          *puVar11 = 1;
          puVar11[1] = 0x38;
          puVar11[6] = iStack_be;
          puVar11[7] = iStack_c2;
          puVar11[8] = uVar9;
          puVar11[9] = iStack_c2;
          puVar11[10] = uStack_ca;
          puVar11[0xb] = uStack_c6;
          puVar11[0xc] = 0;
          if ((uStack_c6 & 1) == 0) {
            _vm_protect(iVar1,iStack_be,iStack_c2,0,uStack_c6 | 1);
          }
          if ((uStack_ca & 1) != 0) {
            _vn_rdwr(1,iStack_b2,iStack_be,iStack_c2,uVar9,0,1,0);
          }
          iVar5 = iVar5 + 0x38;
          uVar9 = iStack_c2 + uVar9;
          iStack_be = iStack_c2 + iStack_be;
          iVar2 = iVar2 + -1;
        }
        iVar8 = *(int *)(iVar8 + 0x18);
        if (0 < iVar10) {
          do {
            *(undefined4 *)(iVar5 + (int)puStack_ba) = 4;
            ((undefined4 *)(iVar5 + (int)puStack_ba))[1] = iStack_ee + 8;
            iVar5 = iVar5 + 8;
            uVar9 = 0;
            piVar12 = aiStack_ae;
            puVar13 = &stack0xfffffffc;
            if (uStack_b6 != 0) {
              do {
                uVar3 = *(undefined4 *)(puVar13 + -0xa6);
                *(undefined4 *)(iVar5 + (int)puStack_ba) = *(undefined4 *)(puVar13 + -0xaa);
                *(undefined4 *)(iVar5 + 4 + (int)puStack_ba) = uVar3;
                _thread_getstatus(iVar8,*piVar12,iVar5 + 8 + (int)puStack_ba,piVar12 + 1);
                iVar5 = iVar5 + 8 + aiStack_ae[uVar9 * 2 + 1] * 4;
                uVar9 = uVar9 + 1;
                piVar12 = piVar12 + 2;
                puVar13 = puVar13 + 8;
              } while (uVar9 < uStack_b6);
            }
            iVar8 = *(int *)(iVar8 + 0x10);
            iVar10 = iVar10 + -1;
          } while (0 < iVar10);
        }
        iVar8 = _vn_rdwr(1,iStack_b2,puStack_ba,iVar4,0,1,1,0);
        _kmem_free(_kernel_map,puStack_ba,iVar4);
      }
      else {
        iVar8 = 0xe;
      }
      _vn_rele(iStack_b2);
      *(char *)(dword_40B57D4 + 100) = (char)iVar8;
      return -(int)-(iVar8 == 0);
    }
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=80 start=0x4003c0a */

void _getdtablesize(void)

{
  *(undefined4 *)(dword_40B57D4 + 0x5c) = 0x100;
  return;
}
/* GHIDRADEC_FUNCTION index=81 start=0x4003c20 */

void _getdopt(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=82 start=0x4003c28 */

void _setdopt(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=83 start=0x4003c30 */

int _dup(void)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  
  puVar2 = *(uint **)(dword_40B57D4 + 0x24);
  uVar1 = *puVar2;
  if ((uVar1 & 0xffffffc0) != 0) {
    *puVar2 = uVar1 & 0x3f;
    iVar4 = _dup2();
    return iVar4;
  }
  iVar4 = 0;
  if (((uVar1 < *(uint *)(_active_u + 0x152)) &&
      (iVar3 = *(int *)(*(int *)(_active_u + 0x146) + uVar1 * 4), iVar3 != 0)) &&
     (iVar3 != -0x10000)) {
    iVar4 = _ufalloc(0);
    if (iVar4 < 0) {
      return iVar4;
    }
    if (iVar3 == *(int *)(*(int *)(_active_u + 0x146) + *puVar2 * 4)) {
      iVar4 = _dupit(iVar4,iVar3,(int)*(char *)(*puVar2 + *(int *)(_active_u + 0x14a)));
      return iVar4;
    }
    *(undefined4 *)(*(int *)(_active_u + 0x146) + iVar4 * 4) = 0;
  }
  *(undefined *)(dword_40B57D4 + 100) = 9;
  return iVar4;
}
/* GHIDRADEC_FUNCTION index=84 start=0x4003cc8 */

void _dup2(void)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  
  puVar1 = *(uint **)(dword_40B57D4 + 0x24);
  if (((*puVar1 < *(uint *)(_active_u + 0x152)) &&
      (iVar2 = *(int *)(*(int *)(_active_u + 0x146) + *puVar1 * 4), iVar2 != 0)) &&
     (iVar2 != -0x10000)) {
    if (0xff < puVar1[1]) {
      *(undefined *)(dword_40B57D4 + 100) = 9;
      return;
    }
    *(uint *)(dword_40B57D4 + 0x5c) = puVar1[1];
    if (puVar1[1] == *puVar1) {
      return;
    }
    _expand_fdlist(*(undefined4 *)(*(int *)(_active_threads + 0xc) + 0x30),puVar1[1]);
    if ((iVar2 == *(int *)(*(int *)(_active_u + 0x146) + *puVar1 * 4)) &&
       (iVar3 = *(int *)(*(int *)(_active_u + 0x146) + puVar1[1] * 4), iVar3 != -0x10000)) {
      if (iVar3 != 0) {
        _vno_lockrelease(iVar3);
        if ((*(byte *)(puVar1[1] + *(int *)(_active_u + 0x14a)) & 2) != 0) {
          _munmapfd(puVar1[1]);
        }
        _closef(*(undefined4 *)(*(int *)(_active_u + 0x146) + puVar1[1] * 4));
        *(undefined *)(dword_40B57D4 + 100) = 0;
      }
      if (iVar2 == *(int *)(*(int *)(_active_u + 0x146) + *puVar1 * 4)) {
        _dupit(puVar1[1],iVar2,(int)*(char *)(*puVar1 + *(int *)(_active_u + 0x14a)));
        return;
      }
    }
  }
  *(undefined *)(dword_40B57D4 + 100) = 9;
  return;
}
/* GHIDRADEC_FUNCTION index=85 start=0x4003df2 */

void _dupit(int param_1,int param_2,byte param_3)

{
  _expand_fdlist(*(undefined4 *)(*(int *)(_active_threads + 0xc) + 0x30),param_1);
  *(int *)(*(int *)(_active_u + 0x146) + param_1 * 4) = param_2;
  *(byte *)(param_1 + *(int *)(_active_u + 0x14a)) = param_3 & 0xfe;
  *(sword *)(param_2 + 0xe) = *(sword *)(param_2 + 0xe) + 1;
  if (*(int *)(_active_u + 0x14e) < param_1) {
    *(int *)(_active_u + 0x14e) = param_1;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=86 start=0x4003e5a */

void _fcntl(void)

{
  uint *puVar1;
  int iVar2;
  byte bVar3;
  int iVar4;
  char cVar5;
  undefined uVar6;
  uint uVar7;
  uint *puVar8;
  undefined4 uVar9;
  uint uStack_1a;
  sword asStack_16 [2];
  int iStack_12;
  int iStack_e;
  
  puVar1 = *(uint **)(dword_40B57D4 + 0x24);
  uVar7 = *puVar1;
  if (((*(uint *)((int)_active_u + 0x152) <= uVar7) ||
      (iVar2 = *(int *)(*(int *)((int)_active_u + 0x146) + uVar7 * 4), iVar2 == 0)) ||
     (iVar2 == -0x10000)) goto loc_40040CC;
  puVar8 = (uint *)(uVar7 + *(int *)((int)_active_u + 0x14a));
  switch(puVar1[1]) {
  case :
    if (0xff < puVar1[2]) goto loc_4004112;
    iVar4 = _ufalloc(puVar1[2]);
    if (iVar4 < 0) {
      return;
    }
    if (iVar2 == *(int *)(*(int *)((int)_active_u + 0x146) + *puVar1 * 4)) {
      _dupit(iVar4,iVar2,(int)(char)(*(byte *)puVar8 & 0xfe));
      return;
    }
    *(undefined4 *)(*(int *)((int)_active_u + 0x146) + iVar4 * 4) = 0;
    goto loc_40040CC;
  case :
    *(uint *)(dword_40B57D4 + 0x5c) = *(byte *)puVar8 & 1;
    break;
  case :
    *puVar8 = *puVar8 & 0xfeffffff | (*(byte *)((int)puVar1 + 0xb) & 1) << 0x18;
    break;
  case :
    *(int *)(dword_40B57D4 + 0x5c) = *(int *)(iVar2 + 8) + -1;
    break;
  case :
    if ((*(byte *)(*_active_u + 0x16) & 0x40) == 0) {
      uVar7 = *(uint *)(iVar2 + 8) & 0x21b3;
    }
    else {
      uVar7 = *(uint *)(iVar2 + 8) & 0x400031b3;
    }
    uVar7 = puVar1[2] + 1 & 0xffffde4c | uVar7;
    uStack_1a = (uVar7 & 7) >> 2;
    uVar6 = _fioctl(iVar2,0x8004667e,&uStack_1a);
    *(undefined *)(dword_40B57D4 + 100) = uVar6;
    if (*(char *)(dword_40B57D4 + 100) == '\0') {
      uStack_1a = (uVar7 & 0x7f) >> 6;
      uVar6 = _fioctl(iVar2,0x8004667d,&uStack_1a);
      *(undefined *)(dword_40B57D4 + 100) = uVar6;
      if (*(char *)(dword_40B57D4 + 100) == '\0') {
        *(uint *)(iVar2 + 8) = uVar7;
      }
      else {
        uStack_1a = (*(uint *)(iVar2 + 0xb) & 0x7ffffff) >> 0x1a;
        _fioctl(iVar2,0x8004667e,&uStack_1a);
      }
    }
    break;
  case :
    uVar6 = _fgetown(iVar2,dword_40B57D4 + 0x5c);
    goto loc_40041A6;
  case :
    uVar6 = _fsetown(iVar2,puVar1[2]);
loc_40041A6:
    *(undefined *)(dword_40B57D4 + 100) = uVar6;
    break;
  case :
  case :
  case :
    if (*(sword *)(iVar2 + 0xc) == 1) {
      if (((*(byte *)(*_active_u + 0x16) & 0x40) == 0) ||
         (*(int *)(*(int *)(iVar2 + 0x16) + 0x28) != 1)) goto loc_4004112;
      cVar5 = _copyinmsg(puVar1[2],asStack_16,0x12);
      *(char *)(dword_40B57D4 + 100) = cVar5;
      if (cVar5 != '\0') {
        return;
      }
      if (asStack_16[0] == 2) {
        if (puVar1[1] != 7) {
          bVar3 = *(byte *)(iVar2 + 0xb) & 2;
joined_r0x040040ca:
          if (bVar3 == 0) goto loc_40040CC;
        }
      }
      else if (asStack_16[0] < 3) {
        if (asStack_16[0] != 1) goto loc_4004112;
        if (puVar1[1] != 7) {
          bVar3 = *(byte *)(iVar2 + 0xb) & 1;
          goto joined_r0x040040ca;
        }
      }
      else if (asStack_16[0] != 3) goto loc_4004112;
      cVar5 = _rewhence(asStack_16,iVar2,0);
      *(char *)(dword_40B57D4 + 100) = cVar5;
      if (cVar5 != '\0') {
        return;
      }
      if (iStack_e < 0) {
        iStack_12 = iStack_e + iStack_12;
        iStack_e = -iStack_e;
      }
      if (iStack_12 < 0) {
loc_4004112:
        *(undefined *)(dword_40B57D4 + 100) = 0x16;
        return;
      }
      if ((puVar1[1] != 7) && (asStack_16[0] != 3)) {
        *(byte *)puVar8 = *(byte *)puVar8 | 4;
        *(byte *)(*_active_u + 0x28) = *(byte *)(*_active_u + 0x28) | 0x20;
      }
      cVar5 = (**(code **)(*(int *)(*(int *)(iVar2 + 0x16) + 0x1c) + 0x60))
                        (*(int *)(iVar2 + 0x16),asStack_16,puVar1[1],*(undefined4 *)(iVar2 + 0x1e),
                         (int)*(sword *)(*_active_u + 0x30));
      *(char *)(dword_40B57D4 + 100) = cVar5;
      if (cVar5 != '\0') {
        return;
      }
      if (puVar1[1] != 7) {
        return;
      }
      if (asStack_16[0] == 3) {
        uVar9 = 2;
      }
      else {
        uVar9 = 0x12;
      }
      uVar6 = _copyoutmsg(asStack_16,puVar1[2],uVar9);
      goto loc_40041A6;
    }
loc_40040CC:
    *(undefined *)(dword_40B57D4 + 100) = 9;
    break;
  :
    *(undefined *)(dword_40B57D4 + 100) = 0x16;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=87 start=0x40041c2 */

void _fset(int param_1,uint param_2,int param_3)

{
  undefined4 uVar1;
  
  if (param_3 == 0) {
    *(uint *)(param_1 + 8) = ~param_2 & *(uint *)(param_1 + 8);
  }
  else {
    *(uint *)(param_1 + 8) = param_2 | *(uint *)(param_1 + 8);
  }
  uVar1 = 0x8004667d;
  if (param_2 == 4) {
    uVar1 = 0x8004667e;
  }
  _fioctl(param_1,uVar1,&param_3);
  return;
}
/* GHIDRADEC_FUNCTION index=88 start=0x400420c */

undefined4 _fgetown(int param_1,int *param_2)

{
  undefined4 uVar1;
  
  if (*(sword *)(param_1 + 0xc) == 2) {
    *param_2 = (int)*(sword *)(*(int *)(param_1 + 0x16) + 0x54);
    uVar1 = 0;
  }
  else {
    uVar1 = _fioctl(param_1,0x40047477,param_2);
    *param_2 = -*param_2;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=89 start=0x400424a */

undefined4 _fsetown(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if (*(sword *)(param_1 + 0xc) == 2) {
    *(undefined2 *)(*(int *)(param_1 + 0x16) + 0x54) = param_2._2_2_;
    uVar1 = 0;
  }
  else {
    if (param_2 < 1) {
      param_2 = -param_2;
    }
    else {
      iVar2 = _pfind(param_2);
      if (iVar2 == 0) {
        return 3;
      }
      param_2 = (int)*(sword *)(iVar2 + 0x2e);
    }
    uVar1 = _fioctl(param_1,0x80047476,&param_2);
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=90 start=0x40042ae */

void _fioctl(int param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)(*(int *)(param_1 + 0x12) + 4))(param_1,param_2,param_3);
  return;
}
/* GHIDRADEC_FUNCTION index=91 start=0x40042ce */

void _close(void)

{
  uint uVar1;
  int iVar2;
  byte *pbVar3;
  
  uVar1 = **(uint **)(dword_40B57D4 + 0x24);
  if (((uVar1 < *(uint *)((int)_active_u + 0x152)) &&
      (iVar2 = *(int *)(*(int *)((int)_active_u + 0x146) + uVar1 * 4), iVar2 != 0)) &&
     (iVar2 != -0x10000)) {
    _vno_lockrelease(iVar2);
    pbVar3 = (byte *)(uVar1 + *(int *)((int)_active_u + 0x14a));
    if ((*pbVar3 & 2) != 0) {
      _munmapfd(uVar1);
    }
    *(undefined4 *)(*(int *)((int)_active_u + 0x146) + uVar1 * 4) = 0;
    while( true ) {
      if ((*(int *)((int)_active_u + 0x14e) < 0) ||
         (*(int *)(*(int *)((int)_active_u + 0x146) + *(int *)((int)_active_u + 0x14e) * 4) != 0))
      break;
      *(int *)((int)_active_u + 0x14e) = *(int *)((int)_active_u + 0x14e) + -1;
    }
    *pbVar3 = 0;
    _closef(iVar2);
    if ((((*(byte *)(*_active_u + 0x16) & 0x40) != 0) && (*(char *)(dword_40B57D4 + 100) == '\x1c'))
       && ((*(byte *)(iVar2 + 10) & 0x10) != 0)) {
      *(undefined *)(dword_40B57D4 + 100) = 0;
    }
  }
  else {
    *(undefined *)(dword_40B57D4 + 100) = 9;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=92 start=0x40043a0 */

void _fstat(void)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  undefined uVar4;
  undefined auStack_40 [60];
  
  puVar2 = *(uint **)(dword_40B57D4 + 0x24);
  uVar1 = *puVar2;
  if (((uVar1 < *(uint *)(_active_u + 0x152)) &&
      (iVar3 = *(int *)(*(int *)(_active_u + 0x146) + uVar1 * 4), iVar3 != 0)) &&
     (iVar3 != -0x10000)) {
    if (*(sword *)(iVar3 + 0xc) == 1) {
      uVar4 = _vno_stat(*(undefined4 *)(iVar3 + 0x16),auStack_40);
    }
    else {
      if (*(sword *)(iVar3 + 0xc) != 2) {
                    /* WARNING: Subroutine does not return */
        _panic(&aFstat);
      }
      uVar4 = _soo_stat(*(undefined4 *)(iVar3 + 0x16),auStack_40);
    }
    *(undefined *)(dword_40B57D4 + 100) = uVar4;
    if (*(char *)(dword_40B57D4 + 100) == '\0') {
      uVar4 = _copyoutmsg(auStack_40,puVar2[1],0x3c);
      *(undefined *)(dword_40B57D4 + 100) = uVar4;
    }
  }
  else {
    *(undefined *)(dword_40B57D4 + 100) = 9;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=93 start=0x400445c */

int _ufalloc(int param_1)

{
  while( true ) {
    if (0xff < param_1) {
      *(undefined *)(dword_40B57D4 + 100) = 0x18;
      return -1;
    }
    _expand_fdlist(*(undefined4 *)(*(int *)(_active_threads + 0xc) + 0x30),param_1);
    if (*(int *)(*(int *)(_active_u + 0x146) + param_1 * 4) == 0) break;
    param_1 = param_1 + 1;
  }
  *(int *)(dword_40B57D4 + 0x5c) = param_1;
  *(undefined *)(param_1 + *(int *)(_active_u + 0x14a)) = 0;
  if (*(int *)(_active_u + 0x14e) < param_1) {
    *(int *)(_active_u + 0x14e) = param_1;
  }
  *(undefined4 *)(*(int *)(_active_u + 0x146) + param_1 * 4) = 0xffff0000;
  return param_1;
}
/* GHIDRADEC_FUNCTION index=94 start=0x40044f4 */

int _ufavail(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = 0;
  do {
    if ((iVar2 < *(int *)(_active_u + 0x152)) &&
       (*(int *)(*(int *)(_active_u + 0x146) + iVar2 * 4) == 0)) {
      iVar1 = iVar1 + 1;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x100);
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=95 start=0x400452a */

void _file_init(void)

{
  dword_40B59C8 = &_file_list;
  _file_list = &_file_list;
  _file_zone = _zinit(0x22,_max_file * 0x22,0,0,aFileStructs);
  return;
}
/* GHIDRADEC_FUNCTION index=96 start=0x4004566 */

undefined4 * _falloc(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = _ufalloc(0);
  if (iVar1 < 0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = (undefined4 *)_zalloc(_file_zone);
    *dword_40B59C8 = puVar2;
    puVar2[1] = dword_40B59C8;
    *puVar2 = &_file_list;
    dword_40B59C8 = puVar2;
    *(undefined2 *)((int)puVar2 + 0xe) = 1;
    *(undefined4 *)((int)puVar2 + 0x16) = 0;
    *(undefined4 *)((int)puVar2 + 0x1a) = 0;
    *(undefined4 *)((int)puVar2 + 0x12) = 0;
    **(sword **)(_active_u + 0x1a) = **(sword **)(_active_u + 0x1a) + 1;
    *(undefined4 *)((int)puVar2 + 0x1e) = *(undefined4 *)(_active_u + 0x1a);
  }
  return puVar2;
}
/* GHIDRADEC_FUNCTION index=97 start=0x40045da */

int _getf(uint param_1)

{
  int iVar1;
  
  if ((param_1 < *(uint *)(_active_u + 0x152)) &&
     (iVar1 = *(int *)(*(int *)(_active_u + 0x146) + param_1 * 4), iVar1 != 0)) {
    if (iVar1 == -0x10000) {
      *(undefined *)(dword_40B57D4 + 100) = 9;
    }
  }
  else {
    *(undefined *)(dword_40B57D4 + 100) = 9;
    iVar1 = 0;
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=98 start=0x4004620 */

void _closef(int param_1)

{
  sword sVar1;
  
  if (param_1 != 0) {
    sVar1 = *(sword *)(param_1 + 0xe);
    if (sVar1 < 2) {
      if (sVar1 != 1) {
                    /* WARNING: Subroutine does not return */
        _panic(aFpNotOne);
      }
      if (*(int *)(param_1 + 0x12) != 0) {
        (**(code **)(*(int *)(param_1 + 0x12) + 0xc))(param_1);
      }
      _crfree(*(undefined4 *)(param_1 + 0x1e));
      if (*(sword *)(param_1 + 0xe) != 1) {
                    /* WARNING: Subroutine does not return */
        _panic(aFpNotOne2);
      }
      *(undefined2 *)(param_1 + 0xe) = 0;
      _free_file(param_1);
    }
    else {
      *(sword *)(param_1 + 0xe) = sVar1 + -1;
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=99 start=0x400469c */

void _free_file(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar1 = (undefined4 *)*param_1;
  puVar2 = (undefined4 *)param_1[1];
  puVar3 = puVar2;
  if (puVar1 != &_file_list) {
    puVar1[1] = puVar2;
    puVar3 = dword_40B59C8;
  }
  dword_40B59C8 = puVar3;
  *puVar2 = puVar1;
  _zfree(_file_zone,param_1);
  return;
}

