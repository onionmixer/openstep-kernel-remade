/* GHIDRADEC_FUNCTION index=1400 start=0x404b11e */

void _init_timeout_element(int param_1)

{
  *(undefined4 *)(param_1 + 8) = 0x404b0f0;
  *(int *)(param_1 + 0x10) = param_1;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  return;
}
/* GHIDRADEC_FUNCTION index=1401 start=0x404b13a */

char _set_timeout(int param_1,undefined4 param_2)

{
  char cVar1;
  undefined8 uVar2;
  
  cVar1 = '\0';
  uVar2 = _ticks_to_ns_time(param_2);
  uVar2 = _calloutDeadlineFromInterval(uVar2);
  _calloutEntryDispatchDelayed(param_1,uVar2);
  *(undefined4 *)(param_1 + 0x2c) = 1;
  return cVar1 << 4;
}
/* GHIDRADEC_FUNCTION index=1402 start=0x404b184 */

bool _reset_timeout(int param_1)

{
  bool bVar1;
  
  bVar1 = *(int *)(param_1 + 0x2c) != 0;
  if (bVar1) {
    _calloutEntryRemove(param_1);
    *(undefined4 *)(param_1 + 0x2c) = 0;
  }
  return bVar1;
}
/* GHIDRADEC_FUNCTION index=1403 start=0x404b1c6 */

void _init_timeout(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=1404 start=0x404b1ce */

undefined4 _host_get_time(int param_1,int *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = _mtime;
  if (param_1 == 0) {
    uVar2 = 0x16;
  }
  else {
    do {
      *param_2 = *piVar1;
      param_2[1] = piVar1[1];
    } while (*param_2 != piVar1[2]);
    uVar2 = 0;
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=1405 start=0x404b1fc */
//Error decompiling function: _host_set_time @ 0x404b1fc
//Unable to parse XML: 


<doc><function/><function><comment color="comment">
//Decompiler native message:  Low-level Error: <returnsym> tag must include a valid storage address
</comment></function></doc>
/* GHIDRADEC_FUNCTION index=1406 start=0x404b25e */

undefined4 _host_adjust_time(int param_1,int param_2,int param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  
  if (param_1 == 0) {
    uVar3 = 0x16;
  }
  else {
    uVar4 = param_3 + param_2 * 1000000;
    iVar2 = (int)_timedelta / 1000000;
    iVar1 = (int)_timedelta % 1000000;
    if (_timedelta == 0) {
      if (_bigadj < uVar4) {
        _tickdelta = _tickadj * 10;
      }
      else {
        _tickdelta = _tickadj;
      }
    }
    if (uVar4 % _tickdelta != 0) {
      uVar4 = _tickdelta * (uVar4 / _tickdelta);
    }
    _timedelta = uVar4;
    *param_4 = iVar2;
    param_4[1] = iVar1;
    uVar3 = 0;
  }
  return uVar3;
}
/* GHIDRADEC_FUNCTION index=1407 start=0x404b31e */

byte _mach_clock_bootstrap(void)

{
  code cVar1;
  code *pcVar2;
  int iVar3;
  char cVar4;
  bool bVar5;
  
  iVar3 = _kmem_alloc_wired(_kernel_map,&_mtime,_page_size);
  if (iVar3 != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aMappableTimeIn);
  }
  _bzero(_mtime,_page_size);
  cVar4 = '\0';
  _get_calendar_time_value(_time);
  pcVar2 = _mtime;
  bVar5 = _mtime == (code *)0x0;
  cVar1 = (code)0x0;
  if (!bVar5) {
    *(code *)((int)_mtime + 8) = _time;
    *(undefined4 *)((int)pcVar2 + 4) = dword_40AF7F0;
    cVar1 = _time;
    *pcVar2 = _time;
    bVar5 = cVar1 == (code)0x0;
  }
  return cVar4 << 4 | ((int)cVar1 < 0) << 3 | bVar5 << 2;
}
/* GHIDRADEC_FUNCTION index=1408 start=0x404b3a6 */

void _compute_mach_factor(void)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  undefined4 *puVar9;
  
  puVar9 = _all_psets;
  if ((undefined4 **)_all_psets != &_all_psets) {
    do {
      iVar4 = puVar9[0x47];
      if (0 < iVar4) {
        iVar2 = puVar9[0x41];
        for (puVar1 = (undefined4 *)puVar9[0x45]; puVar1 != puVar9 + 0x45;
            puVar1 = (undefined4 *)puVar1[0x4c]) {
          iVar2 = puVar1[0x41] + iVar2;
        }
        iVar2 = (iVar4 - puVar9[0x44]) + iVar2;
        if (puVar9 == (undefined4 *)_default_pset) {
          iVar2 = iVar2 + -1;
        }
        if (iVar4 < iVar2) {
          iVar3 = (iVar4 * 1000) / (iVar2 + 1);
          iVar4 = (iVar2 << 7) / iVar4;
        }
        else {
          iVar3 = (iVar4 - iVar2) * 1000;
          iVar4 = 0x80;
        }
        puVar9[0x58] = (iVar3 + puVar9[0x58] * 4) / 5;
        puVar9[0x59] = (iVar2 * 1000 + puVar9[0x59] * 4) / 5;
        if (puVar9 == (undefined4 *)_default_pset) {
          piVar5 = (int *)_avenrun;
          piVar7 = (int *)_mach_factor;
          piVar8 = (int *)unk_40AF820;
          do {
            *piVar7 = (iVar3 * (1000 - *piVar8) + *piVar8 * *piVar7) / 1000;
            piVar6 = piVar5 + 1;
            *piVar5 = (iVar2 * 1000 * (1000 - *piVar8) + *piVar8 * *piVar5) / 1000;
            piVar5 = piVar6;
            piVar7 = piVar7 + 1;
            piVar8 = piVar8 + 1;
          } while ((int)piVar6 < 0x40af811);
        }
        puVar9[0x5a] = iVar4 + puVar9[0x5a] >> 1;
      }
      puVar1 = puVar9 + 0x50;
      puVar9 = (undefined4 *)*puVar1;
    } while ((undefined4 **)*puVar1 != &_all_psets);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1409 start=0x404b526 */

void _getlastaddr(void)

{
  uint uVar1;
  undefined *puVar2;
  uint uVar3;
  
  uVar1 = 0;
  puVar2 = stru_400001C;
  uVar3 = 0;
  do {
    if ((*(int *)puVar2 == 1) &&
       (uVar1 < (uint)(*(int *)((int)puVar2 + 0x1c) + *(int *)((int)puVar2 + 0x18)))) {
      uVar1 = *(int *)((int)puVar2 + 0x1c) + *(int *)((int)puVar2 + 0x18);
    }
    puVar2 = (undefined *)(*(int *)((int)puVar2 + 4) + (int)puVar2);
    uVar3 = uVar3 + 1;
  } while (uVar3 < 5);
  return;
}
/* GHIDRADEC_FUNCTION index=1410 start=0x404b56e */

void _getmachheaders(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_malloc(8);
  *puVar1 = 0x4000000;
  puVar1[1] = 0;
  return;
}
/* GHIDRADEC_FUNCTION index=1411 start=0x404b58c */

undefined4
_getsectdatafromheader(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = _getsectbynamefromheader(param_1,param_2,param_3);
  if (iVar1 == 0) {
    *param_4 = 0;
    uVar2 = 0;
  }
  else {
    *param_4 = *(undefined4 *)(iVar1 + 0x24);
    uVar2 = *(undefined4 *)(iVar1 + 0x20);
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=1412 start=0x404b5c4 */

int * _getsectbynamefromheader(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  int *piVar5;
  
  piVar5 = (int *)(param_1 + 0x1c);
  uVar3 = 0;
  if (*(int *)(param_1 + 0x10) != 0) {
    do {
      if ((*piVar5 == 1) &&
         ((iVar1 = _strncmp(piVar5 + 2,param_2,0x10), iVar1 == 0 || (*(int *)(param_1 + 0xc) == 1)))
         ) {
        piVar4 = piVar5 + 0xe;
        uVar2 = 0;
        if (piVar5[0xc] != 0) {
          do {
            iVar1 = _strncmp(piVar4,param_3,0x10);
            if ((iVar1 == 0) && (iVar1 = _strncmp(piVar4 + 4,param_2,0x10), iVar1 == 0)) {
              return piVar4;
            }
            piVar4 = piVar4 + 0x11;
            uVar2 = uVar2 + 1;
          } while (uVar2 < (uint)piVar5[0xc]);
        }
      }
      piVar5 = (int *)(piVar5[1] + (int)piVar5);
      uVar3 = uVar3 + 1;
    } while (uVar3 < *(uint *)(param_1 + 0x10));
  }
  return (int *)0x0;
}
/* GHIDRADEC_FUNCTION index=1413 start=0x404b66a */

int * _getsegbynamefromheader(int param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  
  piVar3 = (int *)(param_1 + 0x1c);
  uVar2 = 0;
  if (*(int *)(param_1 + 0x10) != 0) {
    do {
      if ((*piVar3 == 1) && (iVar1 = _strncmp(piVar3 + 2,param_2,0x10), iVar1 == 0)) {
        return piVar3;
      }
      piVar3 = (int *)(piVar3[1] + (int)piVar3);
      uVar2 = uVar2 + 1;
    } while (uVar2 < *(uint *)(param_1 + 0x10));
  }
  return (int *)0x0;
}
/* GHIDRADEC_FUNCTION index=1414 start=0x404b6c0 */

void _firstseg(void)

{
  _firstsegfromheader(0x4000000);
  return;
}
/* GHIDRADEC_FUNCTION index=1415 start=0x404b6d4 */

int * _firstsegfromheader(int param_1)

{
  uint uVar1;
  int *piVar2;
  
  piVar2 = (int *)(param_1 + 0x1c);
  uVar1 = 0;
  if (*(uint *)(param_1 + 0x10) != 0) {
    do {
      if (*piVar2 == 1) {
        return piVar2;
      }
      piVar2 = (int *)(piVar2[1] + (int)piVar2);
      uVar1 = uVar1 + 1;
    } while (uVar1 < *(uint *)(param_1 + 0x10));
  }
  return (int *)0x0;
}
/* GHIDRADEC_FUNCTION index=1416 start=0x404b70a */

int _nextseg(int param_1)

{
  int iVar1;
  
  iVar1 = _nextsegfromheader(0x4000000,param_1);
  if ((iVar1 == 0) && (_fvm_seg != param_1)) {
    iVar1 = _fvm_seg;
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=1417 start=0x404b73a */

int * _nextsegfromheader(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = param_1 + 0x1c;
  uVar1 = 0;
  if (*(uint *)(param_1 + 0x10) != 0) {
    do {
      if (param_2 == iVar2) break;
      iVar2 = *(int *)(iVar2 + 4) + iVar2;
      uVar1 = uVar1 + 1;
    } while (uVar1 < *(uint *)(param_1 + 0x10));
  }
  if (*(uint *)(param_1 + 0x10) != uVar1) {
    piVar3 = (int *)(*(int *)(iVar2 + 4) + iVar2);
    for (; uVar1 < *(uint *)(param_1 + 0x10); uVar1 = uVar1 + 1) {
      if (*piVar3 == 1) {
        return piVar3;
      }
      piVar3 = (int *)(piVar3[1] + (int)piVar3);
    }
  }
  return (int *)0x0;
}
/* GHIDRADEC_FUNCTION index=1418 start=0x404b79a */

int _getsegbyname(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = _getsegbynamefromheader(0x4000000,param_1);
  if (iVar1 == 0) {
    iVar2 = _strcmp(param_1,_fvm_seg + 8);
    if (iVar2 == 0) {
      iVar1 = _fvm_seg;
    }
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=1419 start=0x404b7e4 */

void _getsectbyname(undefined4 param_1,undefined4 param_2)

{
  _getsectbynamefromheader(0x4000000,param_1,param_2);
  return;
}
/* GHIDRADEC_FUNCTION index=1420 start=0x404b800 */

int _firstsect(int param_1)

{
  if ((param_1 == 0) || (*(int *)(param_1 + 0x30) == 0)) {
    param_1 = 0;
  }
  else {
    param_1 = param_1 + 0x38;
  }
  return param_1;
}
/* GHIDRADEC_FUNCTION index=1421 start=0x404b81e */

int _nextsect(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = _firstsect(param_1);
  if ((uint)((param_2 - iVar1) * -0xf0f0f0f >> 2) < *(int *)(param_1 + 0x30) - 1U) {
    param_2 = param_2 + 0x44;
  }
  else {
    param_2 = 0;
  }
  return param_2;
}
/* GHIDRADEC_FUNCTION index=1422 start=0x404b89a */

int _getfakefvmseg(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = _getsegbyname(&aUser);
  iVar2 = sub_404B864(0x4000000);
  if (iVar1 == 0) {
    if (iVar2 == 0) {
      iVar1 = 0;
    }
    else {
      _fvm_seg = DAT_40af82c;
      dword_40AF844 = *(undefined4 *)(iVar2 + 0xc);
      dword_40AF848 = sub_404B924(dword_40AF844);
      iVar1 = _strcpy(unk_40AF864,*(undefined4 *)(iVar2 + 8));
      dword_40AF884 = dword_40AF844;
      dword_40AF888 = dword_40AF848;
    }
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=1423 start=0x404b970 */

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
/* GHIDRADEC_FUNCTION index=1424 start=0x404ba90 */

undefined _fatfile_getarch(int *param_1,int param_2,int *param_3)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined uVar5;
  int *piVar6;
  int *piVar7;
  int iVar8;
  int iStack_8;
  
  uVar2 = _vnode_pager_setup(param_1,0,1);
  iVar8 = *(int *)(param_2 + 4);
  uVar1 = iVar8 * 0x14 + 8;
  if ((*(uint *)(*param_1 + 0x14) < uVar1) || (uVar1 = ~_page_mask & _page_mask + uVar1, uVar1 == 0)
     ) {
    uVar5 = 2;
  }
  else {
    iStack_8 = 0;
    iVar3 = _vm_allocate_with_pager(_kernel_map,&iStack_8,uVar1,1,uVar2,0);
    if (iVar3 == 0) {
      piVar7 = (int *)0x0;
      iVar3 = 0;
      piVar6 = (int *)(iStack_8 + 8);
      while (0 < iVar8) {
        iVar8 = iVar8 + -1;
        if ((*piVar6 == dword_40B5DCC) && (iVar4 = _grade_cpu_subtype(piVar6[1]), iVar3 < iVar4)) {
          iVar3 = iVar4;
          piVar7 = piVar6;
        }
        piVar6 = piVar6 + 5;
      }
      if (piVar7 != (int *)0x0) {
        *param_3 = *piVar7;
        param_3[1] = piVar7[1];
        param_3[2] = piVar7[2];
        param_3[3] = piVar7[3];
        param_3[4] = piVar7[4];
      }
      uVar5 = piVar7 == (int *)0x0;
      _vm_map_remove(_kernel_map,iStack_8,iStack_8 + uVar1);
    }
    else {
      uVar5 = 5;
    }
  }
  return uVar5;
}

