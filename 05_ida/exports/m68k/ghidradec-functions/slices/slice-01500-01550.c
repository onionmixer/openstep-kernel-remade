/* GHIDRADEC_FUNCTION index=1500 start=0x404ec9a */

undefined4 _kern_PMRestoreDefaults(undefined4 *param_1)

{
  undefined4 uVar1;
  
  if (param_1 == &_realhost) {
    uVar1 = _PMRestoreDefaults();
  }
  else {
    uVar1 = 0x16;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1501 start=0x404ecb6 */

void _thread_quantum_update(int param_1,int param_2,int param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = _min_quantum;
  iVar4 = (&_processor_ptr)[param_1];
  dword_40B67A4 = _min_quantum;
  if (param_4 != 2) {
    param_3 = *(int *)(iVar4 + 0x11c) - param_3;
    *(int *)(iVar4 + 0x11c) = param_3;
    if (param_3 < 1) {
      if (*(int *)(param_2 + 0x6c) == _sched_tick) {
        if ((*(int *)(param_2 + 0x5c) != 2) && (*(int *)(param_2 + 0x60) < 0)) {
          if (*(int *)(param_2 + 0x104) == *(int *)(param_2 + 0xf0)) {
            iVar2 = *(int *)(param_2 + 0xe8) - *(int *)(param_2 + 0x100);
            *(int *)(param_2 + 0x100) = *(int *)(param_2 + 0xe8);
          }
          else {
            iVar2 = _timer_delta(param_2 + 0xe8,param_2 + 0x100);
          }
          if (*(int *)(param_2 + 0xfc) == *(int *)(param_2 + 0xe0)) {
            iVar3 = *(int *)(param_2 + 0xd8) - *(int *)(param_2 + 0xf8);
            *(int *)(param_2 + 0xf8) = *(int *)(param_2 + 0xd8);
          }
          else {
            iVar3 = _timer_delta(param_2 + 0xd8,param_2 + 0xf8);
          }
          *(int *)(param_2 + 0x108) = iVar3 + iVar2 + *(int *)(param_2 + 0x108);
          iVar2 = *(int *)(param_2 + 0x10c) +
                  *(int *)(*(int *)(param_2 + 0x178) + 0x168) * (iVar3 + iVar2);
          *(int *)(param_2 + 0x10c) = iVar2;
          *(int *)(param_2 + 0x68) = iVar2 + *(int *)(param_2 + 0x68);
          *(undefined4 *)(param_2 + 0x10c) = 0;
          _compute_my_priority(param_2);
        }
      }
      else {
        _update_priority(param_2);
      }
      *(undefined4 *)(iVar4 + 0x120) = 0;
      if (*(int *)(param_2 + 0x5c) == 2) {
        *(int *)(iVar4 + 0x11c) = *(int *)(param_2 + 0x58) + *(int *)(iVar4 + 0x11c);
      }
      else {
        *(int *)(iVar4 + 0x11c) = iVar5 + *(int *)(iVar4 + 0x11c);
      }
    }
    else if (*(int *)(param_2 + 0x6c) == _sched_tick) {
      if ((*(int *)(param_2 + 0x5c) != 2) && (*(int *)(param_2 + 0x60) < 0)) {
        if (*(int *)(param_2 + 0x104) == *(int *)(param_2 + 0xf0)) {
          iVar4 = *(int *)(param_2 + 0xe8) - *(int *)(param_2 + 0x100);
          *(int *)(param_2 + 0x100) = *(int *)(param_2 + 0xe8);
        }
        else {
          iVar4 = _timer_delta(param_2 + 0xe8,param_2 + 0x100);
        }
        if (*(int *)(param_2 + 0xfc) == *(int *)(param_2 + 0xe0)) {
          iVar5 = *(int *)(param_2 + 0xd8) - *(int *)(param_2 + 0xf8);
          *(int *)(param_2 + 0xf8) = *(int *)(param_2 + 0xd8);
        }
        else {
          iVar5 = _timer_delta(param_2 + 0xd8,param_2 + 0xf8);
        }
        *(int *)(param_2 + 0x108) = iVar5 + iVar4 + *(int *)(param_2 + 0x108);
        uVar1 = *(int *)(param_2 + 0x10c) +
                *(int *)(*(int *)(param_2 + 0x178) + 0x168) * (iVar5 + iVar4);
        *(uint *)(param_2 + 0x10c) = uVar1;
        if (0x7ffffff < uVar1) {
          *(int *)(param_2 + 0x68) = uVar1 + *(int *)(param_2 + 0x68);
          *(undefined4 *)(param_2 + 0x10c) = 0;
          _compute_my_priority(param_2);
        }
      }
    }
    else {
      _update_priority(param_2);
    }
    _ast_check();
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1502 start=0x404eea6 */

void _pset_sys_bootstrap(void)

{
  undefined *puVar1;
  int iVar2;
  undefined4 *puVar3;
  
  _pset_init(_default_pset);
  dword_40B6768 = 0;
  iVar2 = 0;
  puVar1 = _processor_array;
  puVar3 = &_processor_ptr;
  do {
    *puVar3 = puVar1;
    _processor_init(puVar1,iVar2);
    puVar1 = puVar1 + 0x140;
    iVar2 = iVar2 + 1;
    puVar3 = puVar3 + 1;
  } while (iVar2 < 1);
  _master_processor = (&_processor_ptr)[_master_cpu];
  _all_psets = _default_pset;
  dword_40B678C = &_all_psets;
  dword_40B6788 = &_all_psets;
  unk_40B6644 = _default_pset;
  _all_psets_count = 1;
  dword_40B6790 = 1;
  dword_40B6768 = 0;
  return;
}
/* GHIDRADEC_FUNCTION index=1503 start=0x404ef42 */

void _pset_init(int param_1)

{
  int iVar1;
  int iVar2;
  
  *(undefined4 *)(param_1 + 0x100) = 0x1f;
  *(undefined4 *)(param_1 + 0x104) = 0;
  iVar1 = 0;
  iVar2 = param_1;
  do {
    *(int *)(iVar2 + 4) = iVar2;
    *(int *)iVar2 = iVar2;
    iVar2 = iVar2 + 8;
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x20);
  iVar1 = param_1 + 0x108;
  *(int *)(param_1 + 0x10c) = iVar1;
  *(int *)iVar1 = iVar1;
  *(undefined4 *)(param_1 + 0x110) = 0;
  iVar1 = param_1 + 0x114;
  *(int *)(param_1 + 0x118) = iVar1;
  *(int *)iVar1 = iVar1;
  *(undefined4 *)(param_1 + 0x11c) = 0;
  *(undefined4 *)(param_1 + 0x120) = 1;
  iVar1 = param_1 + 0x124;
  *(int *)(param_1 + 0x128) = iVar1;
  *(int *)iVar1 = iVar1;
  *(undefined4 *)(param_1 + 300) = 0;
  iVar1 = param_1 + 0x130;
  *(int *)(param_1 + 0x134) = iVar1;
  *(int *)iVar1 = iVar1;
  *(undefined4 *)(param_1 + 0x138) = 0;
  *(undefined4 *)(param_1 + 0x13c) = 1;
  iVar1 = param_1 + 0x140;
  *(int *)(param_1 + 0x144) = iVar1;
  *(int *)iVar1 = iVar1;
  *(undefined4 *)(param_1 + 0x148) = 0;
  *(undefined4 *)(param_1 + 0x14c) = 0;
  *(undefined4 *)(param_1 + 0x150) = 0;
  *(undefined4 *)(param_1 + 0x154) = 0x12;
  *(undefined4 *)(param_1 + 0x158) = 1;
  *(undefined4 *)(param_1 + 0x15c) = _min_quantum;
  *(undefined4 *)(param_1 + 0x160) = 0;
  *(undefined4 *)(param_1 + 0x164) = 0;
  *(undefined4 *)(param_1 + 0x168) = 0x80;
  return;
}
/* GHIDRADEC_FUNCTION index=1504 start=0x404efe8 */

void _processor_init(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  *(undefined4 *)(param_1 + 0x100) = 0x1f;
  *(undefined4 *)(param_1 + 0x104) = 0;
  iVar1 = 0;
  iVar2 = param_1;
  do {
    *(int *)(iVar2 + 4) = iVar2;
    *(int *)iVar2 = iVar2;
    iVar2 = iVar2 + 8;
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x20);
  iVar1 = param_1 + 0x108;
  *(int *)(param_1 + 0x10c) = iVar1;
  *(int *)iVar1 = iVar1;
  *(undefined4 *)(param_1 + 0x110) = 0;
  *(undefined4 *)(param_1 + 0x114) = 0;
  *(undefined4 *)(param_1 + 0x118) = 0;
  *(undefined4 *)(param_1 + 0x11c) = 0;
  *(undefined4 *)(param_1 + 0x120) = 0;
  *(undefined4 *)(param_1 + 0x124) = 0;
  *(undefined4 *)(param_1 + 0x128) = 0;
  *(undefined4 *)(param_1 + 300) = 0;
  iVar1 = param_1 + 0x130;
  *(int *)(param_1 + 0x134) = iVar1;
  *(int *)iVar1 = iVar1;
  *(undefined4 *)(param_1 + 0x138) = 0;
  *(undefined4 *)(param_1 + 0x13c) = param_2;
  return;
}
/* GHIDRADEC_FUNCTION index=1505 start=0x404f050 */

void _pset_remove_processor(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 != *(int *)(param_2 + 0x128)) {
                    /* WARNING: Subroutine does not return */
    _panic(aPsetRemoveProc);
  }
  iVar1 = *(int *)(param_2 + 0x130);
  piVar2 = *(int **)(param_2 + 0x134);
  if (iVar1 == param_1 + 0x114) {
    *(int **)(param_1 + 0x118) = piVar2;
  }
  else {
    *(int **)(iVar1 + 0x134) = piVar2;
  }
  if (piVar2 == (int *)(param_1 + 0x114)) {
    *piVar2 = iVar1;
  }
  else {
    piVar2[0x4c] = iVar1;
  }
  *(undefined4 *)(param_2 + 0x128) = 0;
  *(int *)(param_1 + 0x11c) = *(int *)(param_1 + 0x11c) + -1;
  _quantum_set(param_1);
  return;
}
/* GHIDRADEC_FUNCTION index=1506 start=0x404f0b8 */

void _pset_add_processor(int param_1,int param_2)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x118);
  if (piVar1 == (int *)(param_1 + 0x114)) {
    *piVar1 = param_2;
  }
  else {
    piVar1[0x4c] = param_2;
  }
  *(int **)(param_2 + 0x134) = piVar1;
  *(int *)(param_2 + 0x130) = param_1 + 0x114;
  *(int *)(param_1 + 0x118) = param_2;
  *(int *)(param_2 + 0x128) = param_1;
  *(int *)(param_1 + 0x11c) = *(int *)(param_1 + 0x11c) + 1;
  _quantum_set(param_1);
  return;
}
/* GHIDRADEC_FUNCTION index=1507 start=0x404f106 */

void _pset_remove_task(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == *(int *)(param_2 + 0x24)) {
    iVar1 = *(int *)(param_2 + 0xc);
    piVar2 = *(int **)(param_2 + 0x10);
    if (iVar1 == param_1 + 0x124) {
      *(int **)(param_1 + 0x128) = piVar2;
    }
    else {
      *(int **)(iVar1 + 0x10) = piVar2;
    }
    if (piVar2 == (int *)(param_1 + 0x124)) {
      *piVar2 = iVar1;
    }
    else {
      piVar2[3] = iVar1;
    }
    *(undefined4 *)(param_2 + 0x24) = 0;
    *(int *)(param_1 + 300) = *(int *)(param_1 + 300) + -1;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1508 start=0x404f158 */

void _pset_add_task(int param_1,int param_2)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x128);
  if (piVar1 == (int *)(param_1 + 0x124)) {
    *piVar1 = param_2;
  }
  else {
    piVar1[3] = param_2;
  }
  *(int **)(param_2 + 0x10) = piVar1;
  *(int *)(param_2 + 0xc) = param_1 + 0x124;
  *(int *)(param_1 + 0x128) = param_2;
  *(int *)(param_2 + 0x24) = param_1;
  *(int *)(param_1 + 300) = *(int *)(param_1 + 300) + 1;
  return;
}
/* GHIDRADEC_FUNCTION index=1509 start=0x404f19e */

void _pset_remove_thread(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *(int *)(param_2 + 0x18);
  piVar2 = *(int **)(param_2 + 0x1c);
  if (iVar1 == param_1 + 0x130) {
    *(int **)(param_1 + 0x134) = piVar2;
  }
  else {
    *(int **)(iVar1 + 0x1c) = piVar2;
  }
  if (piVar2 == (int *)(param_1 + 0x130)) {
    *piVar2 = iVar1;
  }
  else {
    piVar2[6] = iVar1;
  }
  *(undefined4 *)(param_2 + 0x178) = 0;
  *(int *)(param_1 + 0x138) = *(int *)(param_1 + 0x138) + -1;
  return;
}
/* GHIDRADEC_FUNCTION index=1510 start=0x404f1ea */

void _pset_add_thread(int param_1,int param_2)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x134);
  if (piVar1 == (int *)(param_1 + 0x130)) {
    *piVar1 = param_2;
  }
  else {
    piVar1[6] = param_2;
  }
  *(int **)(param_2 + 0x1c) = piVar1;
  *(int *)(param_2 + 0x18) = param_1 + 0x130;
  *(int *)(param_1 + 0x134) = param_2;
  *(int *)(param_2 + 0x178) = param_1;
  *(int *)(param_1 + 0x138) = *(int *)(param_1 + 0x138) + 1;
  return;
}
/* GHIDRADEC_FUNCTION index=1511 start=0x404f230 */

void _thread_change_psets(int param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *(int *)(param_1 + 0x18);
  piVar2 = *(int **)(param_1 + 0x1c);
  if (iVar1 == param_2 + 0x130) {
    *(int **)(param_2 + 0x134) = piVar2;
  }
  else {
    *(int **)(iVar1 + 0x1c) = piVar2;
  }
  if (piVar2 == (int *)(param_2 + 0x130)) {
    *piVar2 = iVar1;
  }
  else {
    piVar2[6] = iVar1;
  }
  *(int *)(param_2 + 0x138) = *(int *)(param_2 + 0x138) + -1;
  piVar2 = *(int **)(param_3 + 0x134);
  if (piVar2 == (int *)(param_3 + 0x130)) {
    *piVar2 = param_1;
  }
  else {
    piVar2[6] = param_1;
  }
  *(int **)(param_1 + 0x1c) = piVar2;
  *(int *)(param_1 + 0x18) = param_3 + 0x130;
  *(int *)(param_3 + 0x134) = param_1;
  *(int *)(param_1 + 0x178) = param_3;
  *(int *)(param_3 + 0x138) = *(int *)(param_3 + 0x138) + 1;
  return;
}
/* GHIDRADEC_FUNCTION index=1512 start=0x404f2b0 */

void _pset_deallocate(int param_1)

{
  int iVar1;
  
  if (param_1 != 0) {
    iVar1 = *(int *)(param_1 + 0x13c);
    *(int *)(param_1 + 0x13c) = iVar1 + -1;
    if (iVar1 == 1 || iVar1 + -1 < 0) {
                    /* WARNING: Subroutine does not return */
      _panic(aPsetDeallocate);
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1513 start=0x404f2e4 */

void _pset_reference(int param_1)

{
  *(int *)(param_1 + 0x13c) = *(int *)(param_1 + 0x13c) + 1;
  return;
}
/* GHIDRADEC_FUNCTION index=1514 start=0x404f2f4 */

undefined4
_processor_info(int param_1,int param_2,undefined4 *param_3,undefined4 *param_4,uint *param_5)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    uVar2 = 4;
  }
  else if ((param_2 == 1) && (4 < *param_5)) {
    iVar1 = *(int *)(param_1 + 0x13c);
    *param_4 = (&dword_40B5DCC)[iVar1 * 8];
    param_4[1] = (&dword_40B5DD0)[iVar1 * 8];
    if ((*(int *)(param_1 + 0x110) == 5) || (*(int *)(param_1 + 0x110) == 0)) {
      param_4[2] = 0;
    }
    else {
      param_4[2] = 1;
    }
    param_4[3] = iVar1;
    if (param_1 == _master_processor) {
      param_4[4] = 1;
    }
    else {
      param_4[4] = 0;
    }
    *param_5 = 5;
    *param_3 = &_realhost;
    uVar2 = 0;
  }
  else {
    uVar2 = 5;
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=1515 start=0x404f386 */

undefined4 _processor_start(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 4;
  if (param_1 != 0) {
    uVar1 = 5;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1516 start=0x404f398 */

undefined4 _processor_exit(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 4;
  if (param_1 != 0) {
    uVar1 = 5;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1517 start=0x404f3aa */

undefined4 _processor_control(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 4;
  if (param_1 != 0) {
    uVar1 = 5;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1518 start=0x404f3bc */

void _quantum_set(void)

{
  dword_40B67A4 = _min_quantum;
  return;
}
/* GHIDRADEC_FUNCTION index=1519 start=0x404f3ce */

undefined4 _processor_set_create(void)

{
  return 5;
}
/* GHIDRADEC_FUNCTION index=1520 start=0x404f3d8 */

undefined4 _processor_set_destroy(void)

{
  return 5;
}
/* GHIDRADEC_FUNCTION index=1521 start=0x404f3e2 */

undefined4 _processor_get_assignment(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if ((*(int *)(param_1 + 0x110) == 5) || (*(int *)(param_1 + 0x110) == 0)) {
    uVar1 = 5;
  }
  else {
    *param_2 = *(undefined4 *)(param_1 + 0x128);
    _pset_reference(*param_2);
    uVar1 = 0;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1522 start=0x404f412 */

undefined4
_processor_set_info(int param_1,int param_2,undefined4 *param_3,undefined4 *param_4,uint *param_5)

{
  undefined4 uVar1;
  uint uVar2;
  
  if (param_1 == 0) {
loc_404F488:
    uVar1 = 4;
  }
  else {
    if (param_2 == 1) {
      if (*param_5 < 5) {
        return 5;
      }
      *param_4 = *(undefined4 *)(param_1 + 0x11c);
      param_4[1] = *(undefined4 *)(param_1 + 300);
      param_4[2] = *(undefined4 *)(param_1 + 0x138);
      param_4[4] = *(undefined4 *)(param_1 + 0x160);
      param_4[3] = *(undefined4 *)(param_1 + 0x164);
      uVar2 = 5;
    }
    else {
      if (param_2 != 2) {
        *param_3 = 0;
        goto loc_404F488;
      }
      if (*param_5 < 2) {
        return 5;
      }
      *param_4 = *(undefined4 *)(param_1 + 0x158);
      param_4[1] = *(undefined4 *)(param_1 + 0x154);
      uVar2 = 2;
    }
    *param_5 = uVar2;
    *param_3 = &_realhost;
    uVar1 = 0;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1523 start=0x404f496 */

undefined4 _processor_set_max_priority(int param_1,uint param_2,int param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if ((param_1 == 0) || (0x1f < param_2)) {
    uVar2 = 4;
  }
  else {
    *(uint *)(param_1 + 0x154) = param_2;
    if (param_3 != 0) {
      for (puVar1 = *(undefined4 **)(param_1 + 0x130); puVar1 != (undefined4 *)(param_1 + 0x130);
          puVar1 = (undefined4 *)puVar1[6]) {
        if ((int)puVar1[0x14] < (int)param_2) {
          _thread_max_priority(puVar1,param_1,param_2);
        }
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=1524 start=0x404f4f2 */

undefined4 _processor_set_policy_enable(int param_1,uint param_2)

{
  undefined4 uVar1;
  
  if ((param_1 == 0) || (3 < param_2 - 1)) {
    uVar1 = 4;
  }
  else {
    *(uint *)(param_1 + 0x158) = param_2 | *(uint *)(param_1 + 0x158);
    uVar1 = 0;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1525 start=0x404f520 */

undefined4 _processor_set_policy_disable(int param_1,uint param_2,int param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (((param_1 == 0) || (param_2 == 1)) || (3 < param_2 - 1)) {
    uVar2 = 4;
  }
  else {
    if (((param_2 & *(uint *)(param_1 + 0x158)) != 0) &&
       (*(uint *)(param_1 + 0x158) = ~param_2 & *(uint *)(param_1 + 0x158), param_3 != 0)) {
      for (puVar1 = *(undefined4 **)(param_1 + 0x130); puVar1 != (undefined4 *)(param_1 + 0x130);
          puVar1 = (undefined4 *)puVar1[6]) {
        if (param_2 == puVar1[0x17]) {
          _thread_policy(puVar1,1,0);
        }
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=1526 start=0x404f598 */

undefined4 _processor_set_things(int param_1,undefined4 *param_2,uint *param_3,int param_4)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int *piVar8;
  
  if (param_1 == 0) {
    uVar1 = 4;
  }
  else {
    piVar8 = (int *)0x0;
    uVar6 = 0;
    do {
      if (*(int *)(param_1 + 0x148) == 0) {
        return 5;
      }
      if (param_4 == 0) {
        uVar7 = *(uint *)(param_1 + 300);
      }
      else {
        uVar7 = *(uint *)(param_1 + 0x138);
      }
      uVar5 = uVar7 << 2;
      if (uVar5 <= uVar6) {
        if (param_4 == 0) {
          uVar4 = 0;
          iVar3 = *(int *)(param_1 + 0x124);
          piVar2 = piVar8;
          if (uVar7 != 0) {
            do {
              _task_reference(iVar3);
              *piVar2 = iVar3;
              uVar4 = uVar4 + 1;
              iVar3 = *(int *)(iVar3 + 0xc);
              piVar2 = piVar2 + 1;
            } while (uVar4 < uVar7);
          }
        }
        else if (param_4 == 1) {
          uVar4 = 0;
          iVar3 = *(int *)(param_1 + 0x130);
          piVar2 = piVar8;
          if (uVar7 != 0) {
            do {
              _thread_reference(iVar3);
              *piVar2 = iVar3;
              uVar4 = uVar4 + 1;
              iVar3 = *(int *)(iVar3 + 0x18);
              piVar2 = piVar2 + 1;
            } while (uVar4 < uVar7);
          }
        }
        if (uVar7 == 0) {
          *param_2 = 0;
          *param_3 = 0;
          if (uVar6 != 0) {
            _kfree(piVar8,uVar6);
          }
        }
        else {
          piVar2 = piVar8;
          if (uVar5 < uVar6) {
            piVar2 = (int *)_kalloc(uVar5);
            if (piVar2 == (int *)0x0) {
              if (param_4 == 0) {
                uVar5 = 0;
                piVar2 = piVar8;
                if (uVar7 != 0) {
                  do {
                    _task_deallocate(*piVar2);
                    uVar5 = uVar5 + 1;
                    piVar2 = piVar2 + 1;
                  } while (uVar5 < uVar7);
                }
              }
              else if ((param_4 == 1) && (uVar5 = 0, piVar2 = piVar8, uVar7 != 0)) {
                do {
                  _thread_deallocate(*piVar2);
                  uVar5 = uVar5 + 1;
                  piVar2 = piVar2 + 1;
                } while (uVar5 < uVar7);
              }
              _kfree(piVar8,uVar6);
              return 6;
            }
            _bcopy(piVar8,piVar2,uVar5);
            _kfree(piVar8,uVar6);
          }
          *param_2 = piVar2;
          *param_3 = uVar7;
          if (param_4 == 0) {
            uVar6 = 0;
            if (uVar7 != 0) {
              do {
                iVar3 = _convert_task_to_port(*piVar2);
                *piVar2 = iVar3;
                uVar6 = uVar6 + 1;
                piVar2 = piVar2 + 1;
              } while (uVar6 < uVar7);
            }
          }
          else if ((param_4 == 1) && (uVar6 = 0, uVar7 != 0)) {
            do {
              iVar3 = _convert_thread_to_port(*piVar2);
              *piVar2 = iVar3;
              uVar6 = uVar6 + 1;
              piVar2 = piVar2 + 1;
            } while (uVar6 < uVar7);
          }
        }
        return 0;
      }
      if (uVar6 != 0) {
        _kfree(piVar8,uVar6);
      }
      piVar8 = (int *)_kalloc(uVar5);
      uVar6 = uVar5;
    } while (piVar8 != (int *)0x0);
    uVar1 = 6;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1527 start=0x404f740 */

void _processor_set_tasks(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  _processor_set_things(param_1,param_2,param_3,0);
  return;
}
/* GHIDRADEC_FUNCTION index=1528 start=0x404f75c */

void _processor_set_threads(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  _processor_set_things(param_1,param_2,param_3,1);
  return;
}
/* GHIDRADEC_FUNCTION index=1529 start=0x404f77a */

void _enqueue_head(int *param_1,int *param_2)

{
  *param_2 = *param_1;
  param_2[1] = (int)param_1;
  *(int **)(*param_2 + 4) = param_2;
  *param_1 = (int)param_2;
  return;
}
/* GHIDRADEC_FUNCTION index=1530 start=0x404f79e */

void _enqueue_tail(int param_1,int *param_2)

{
  *param_2 = param_1;
  param_2[1] = *(int *)(param_1 + 4);
  *(int **)param_2[1] = param_2;
  *(int **)(param_1 + 4) = param_2;
  return;
}
/* GHIDRADEC_FUNCTION index=1531 start=0x404f7c6 */

int * _dequeue_head(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (param_1 == piVar1) {
    piVar1 = (int *)0x0;
  }
  else {
    *(int **)(*piVar1 + 4) = param_1;
    *param_1 = *piVar1;
  }
  return piVar1;
}
/* GHIDRADEC_FUNCTION index=1532 start=0x404f7ec */

int _dequeue_tail(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  if (param_1 == iVar1) {
    iVar1 = 0;
  }
  else {
    **(int **)(iVar1 + 4) = param_1;
    *(undefined4 *)(param_1 + 4) = *(undefined4 *)(iVar1 + 4);
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=1533 start=0x404f818 */

void _remqueue(undefined4 param_1,int *param_2)

{
  *(int *)(*param_2 + 4) = param_2[1];
  *(int *)param_2[1] = *param_2;
  return;
}
/* GHIDRADEC_FUNCTION index=1534 start=0x404f832 */

void _insque(int *param_1,int *param_2)

{
  *param_1 = *param_2;
  param_1[1] = (int)param_2;
  *(int **)(*param_2 + 4) = param_1;
  *param_2 = (int)param_1;
  return;
}
/* GHIDRADEC_FUNCTION index=1535 start=0x404f856 */

int * _remque(int *param_1)

{
  *(int *)(*param_1 + 4) = param_1[1];
  *(int *)param_1[1] = *param_1;
  return param_1;
}
/* GHIDRADEC_FUNCTION index=1536 start=0x404f872 */

undefined4 _kdp_packet(undefined4 param_1,uint *param_2,undefined4 param_3)

{
  uint uVar1;
  undefined4 uVar2;
  byte bStack_608;
  undefined uStack_607;
  word wStack_606;
  undefined4 uStack_604;
  
  uVar1 = *param_2;
  _bcopy(param_1,&bStack_608,0x604);
  if ((uVar1 < 8) || (uVar1 != wStack_606)) {
    _safe_prf(aKdpPacketBadLe,uVar1,wStack_606);
  }
  else if ((bStack_608 & 1) == 0) {
    uVar1 = (uint)(bStack_608 >> 1);
    if (uVar1 < 0xf) {
      uVar2 = (**(code **)(unk_40AF948 + uVar1 * 4))(&bStack_608,param_2,param_3);
      _bcopy(&bStack_608,param_1,*param_2);
      return uVar2;
    }
    _safe_prf(aKdpPacketBadRe,uVar1,(uint)wStack_606,uStack_607,uStack_604);
  }
  else {
    _safe_prf(aKdpPacketReply,bStack_608 >> 1,uStack_607);
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=1537 start=0x4050542 */

void _kdp_raise_exception(uint param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar1 = _kdp_intr_disbl();
  if (param_4 == 0) {
    _safe_prf(aKdpRaiseExcept);
  }
  if (param_1 != 6) {
    if ((6 < param_1) || (uVar2 = param_1, param_1 == 0)) {
      uVar2 = 0;
    }
    _safe_prf(aSExceptionXXX,*(undefined4 *)(unk_40AF984 + uVar2 * 4),param_1,param_2,param_3);
  }
  _kdp_flush_cache();
  dword_40C25A2 = param_4;
  if (dword_40B3FBA != 0) {
    _kdp_panic(aKdpRaiseExcept_0);
  }
  if (dword_40C259E == 0) {
    sub_405038C();
  }
  else {
    sub_405047C(param_1,param_2,param_3);
  }
  if (dword_40C259E != 0) {
    dword_40C25A6 = 1;
    sub_40502A6(param_4);
    if (dword_40C259E == 0) {
      _safe_prf(aRemoteDebugger);
    }
  }
  _kdp_flush_cache();
  _kdp_intr_enbl(uVar1);
  return;
}
/* GHIDRADEC_FUNCTION index=1538 start=0x405062c */

void _kdp_reset(void)

{
  word_40C25AA = 0;
  _kdp = 0;
  dword_40C259E = 0;
  dword_40C25A6 = 0;
  dword_40C259A = 0;
  byte_40C25AC = 0;
  return;
}
/* GHIDRADEC_FUNCTION index=1539 start=0x4050658 */

void _wait_queue_init(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = 0;
  puVar2 = &_wait_queue;
  do {
    puVar2[1] = puVar2;
    *puVar2 = puVar2;
    puVar2 = puVar2 + 2;
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x3b);
  return;
}
/* GHIDRADEC_FUNCTION index=1540 start=0x4050678 */

void _sched_init(void)

{
  unk_40C25E8 = _recompute_priorities;
  dword_40C25EC = 0;
  _init_timeout_element(_recompute_priorities_timer);
  _min_quantum = _hz / 10;
  _wait_queue_init();
  _pset_sys_bootstrap();
  dword_40C23A0 = &_action_queue;
  _action_queue = &_action_queue;
  _sched_tick = 0;
  _sched_usec = 0;
  _ast_init();
  return;
}
/* GHIDRADEC_FUNCTION index=1541 start=0x40506f2 */

void _thread_timeout(undefined4 param_1)

{
  _clear_wait(param_1,1,0);
  return;
}
/* GHIDRADEC_FUNCTION index=1542 start=0x405070a */

byte _thread_set_timeout(int param_1)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  byte bVar5;
  
  cVar1 = '\0';
  cVar2 = '\0';
  cVar4 = '\0';
  bVar5 = 0;
  cVar3 = (*(byte *)(_active_threads + 0x4b) & 1) == 0;
  if (!(bool)cVar3) {
    cVar2 = param_1 < 0;
    cVar3 = param_1 == 0;
    cVar4 = '\0';
    bVar5 = 0;
    _set_timeout(_active_threads + 0x110,param_1);
  }
  return cVar1 << 4 | cVar2 << 3 | cVar3 << 2 | cVar4 << 1 | bVar5;
}
/* GHIDRADEC_FUNCTION index=1543 start=0x4050742 */

void _thread_timeout_setup(int param_1)

{
  *(code **)(param_1 + 0x130) = _thread_timeout;
  *(int *)(param_1 + 0x134) = param_1;
  _init_timeout_element(param_1 + 0x110);
  *(code **)(param_1 + 0x160) = _thread_depress_timeout;
  *(int *)(param_1 + 0x164) = param_1;
  _init_timeout_element(param_1 + 0x140);
  return;
}
/* GHIDRADEC_FUNCTION index=1544 start=0x4050784 */

undefined4 _assert_wait(uint param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  
  puVar2 = _active_threads;
  if (_active_threads[0xe] != 0) {
    _printf(aAssertWaitAlre,_active_threads[0xe]);
                    /* WARNING: Subroutine does not return */
    _panic(aAssertWait);
  }
  uVar3 = 0;
  bVar5 = false;
  if (param_1 == 0) {
    if (param_2 != 0) {
      uVar4 = 1;
      goto loc_4050844;
    }
  }
  else {
    uVar4 = param_1;
    if ((int)param_1 < 0) {
      uVar4 = ~param_1;
    }
    uVar3 = ((int)uVar4 / 0x3b) * 0x3b;
    bVar5 = uVar4 < uVar3;
    iVar1 = (int)uVar4 % 0x3b;
    *_active_threads = &_wait_queue + iVar1 * 2;
    puVar2[1] = (&dword_40C2804)[iVar1 * 2];
    *(undefined4 **)puVar2[1] = puVar2;
    (&dword_40C2804)[iVar1 * 2] = puVar2;
    puVar2[0xe] = param_1;
    if (param_2 != 0) {
      uVar4 = 1;
      goto loc_4050844;
    }
  }
  uVar4 = 9;
loc_4050844:
  uVar4 = uVar4 | puVar2[0x12];
  puVar2[0x12] = uVar4;
  return CONCAT22((sword)(uVar3 >> 0x10),
                  (word)(byte)(bVar5 << 4 | ((int)uVar4 < 0) << 3 | (uVar4 == 0) << 2));
}
/* GHIDRADEC_FUNCTION index=1545 start=0x4050856 */

byte _clear_wait(int *param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  byte bVar7;
  
  if ((param_3 != 0) && ((*(byte *)((int)param_1 + 0x4b) & 8) != 0)) {
    return (param_3 < 0) << 3;
  }
  uVar2 = param_1[0xe];
  if (uVar2 != 0) {
    cVar6 = uVar2 < (uint)param_1[0xe];
    if (uVar2 == param_1[0xe]) {
      *(int *)(*param_1 + 4) = param_1[1];
      *(int *)param_1[1] = *param_1;
      param_1[0xe] = 0;
      uVar2 = 0;
    }
    cVar5 = '\0';
    cVar3 = (int)uVar2 < 0;
    cVar4 = '\0';
    bVar7 = 0;
    if (uVar2 != 0) goto loc_4050942;
  }
  uVar2 = param_1[0x12];
  if (param_1[0x4f] != 0) {
    _reset_timeout(param_1 + 0x44);
  }
  uVar1 = (uVar2 & 0xf) - 1;
  cVar6 = 0xe < uVar1;
  cVar5 = SBORROW4(0xe,uVar1);
  cVar3 = (int)(0xe - uVar1) < 0;
  cVar4 = uVar1 == 0xe;
  bVar7 = cVar6;
  switch(uVar1) {
  case :
  case :
  case :
    param_1[0x12] = uVar2 & 0xfffffffe | 4;
    param_1[0x10] = param_2;
    cVar3 = (int)param_1 < 0;
    cVar4 = param_1 == (int *)0x0;
    cVar5 = '\0';
    bVar7 = 0;
    _thread_setrun(param_1,1);
    break;
  case :
  case :
  case :
  case :
  case :
    param_1[0x12] = uVar2 & 0xfffffffe;
    param_1[0x10] = param_2;
    cVar3 = param_2 < 0;
    cVar4 = param_2 == 0;
    cVar5 = '\0';
    bVar7 = 0;
  }
loc_4050942:
  return cVar6 << 4 | cVar3 << 3 | cVar4 << 2 | cVar5 << 1 | bVar7;
}
/* GHIDRADEC_FUNCTION index=1546 start=0x4050950 */

undefined4 _thread_wakeup_prim(uint param_1,int param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined2 uVar6;
  uint uVar7;
  bool bVar8;
  bool bVar9;
  char cVar10;
  bool bVar11;
  
  uVar7 = param_1;
  if ((int)param_1 < 0) {
    uVar7 = ~param_1;
  }
  uVar3 = ((int)uVar7 / 0x3b) * 0x3b;
  puVar1 = &_wait_queue + ((int)uVar7 % 0x3b) * 2;
  uVar7 = uVar3 & 0xffff0000;
  uVar6 = (undefined2)(uVar3 >> 0x10);
  iVar4 = (int)*puVar1 - (int)puVar1;
  puVar5 = (undefined4 *)*puVar1;
  while( true ) {
    bVar9 = SBORROW4((int)puVar5,(int)puVar1);
    cVar10 = puVar5 < puVar1;
    bVar8 = true;
    bVar11 = (bool)cVar10;
    if (puVar5 == puVar1) break;
    puVar2 = (undefined4 *)*puVar5;
    if (param_1 == puVar5[0xe]) {
      puVar2[1] = puVar5[1];
      *(undefined4 *)puVar5[1] = *puVar5;
      puVar5[0xe] = 0;
      if (puVar5[0x4f] != 0) {
        _reset_timeout(puVar5 + 0x44);
      }
      uVar3 = puVar5[0x12];
      uVar7 = (uVar3 & 0xf) - 1;
      cVar10 = 0xe < uVar7;
      switch(uVar7) {
      case :
      case :
      case :
        puVar5[0x12] = uVar3 & 0xfffffffe | 4;
        puVar5[0x10] = param_3;
        uVar7 = _thread_setrun(puVar5,1);
        break;
      :
                    /* WARNING: Subroutine does not return */
        _panic(aThreadWakeup);
      case :
      case :
      case :
      case :
      case :
        puVar5[0x12] = uVar3 & 0xfffffffe;
        puVar5[0x10] = param_3;
      }
      uVar6 = (undefined2)(uVar7 >> 0x10);
      bVar9 = false;
      bVar11 = false;
      bVar8 = param_2 == 0;
      iVar4 = param_2;
      if (!bVar8) break;
    }
    uVar6 = (undefined2)(uVar7 >> 0x10);
    iVar4 = (int)puVar2 - (int)puVar1;
    puVar5 = puVar2;
  }
  return CONCAT22(uVar6,(word)(byte)(cVar10 << 4 | (iVar4 < 0) << 3 | bVar8 << 2 | bVar9 << 1 |
                                    bVar11));
}
/* GHIDRADEC_FUNCTION index=1547 start=0x4050aa6 */

void _thread_sleep(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  _assert_wait(param_1,param_3);
  _thread_block_with_continuation(0);
  return;
}
/* GHIDRADEC_FUNCTION index=1548 start=0x4050ac4 */

undefined8 _thread_bind(int param_1,int param_2)

{
  char in_XF;
  
  *(int *)(param_1 + 0x17c) = param_2;
  return CONCAT44((int)(sword)(word)(byte)(in_XF << 4 | (param_2 < 0) << 3 | (param_2 == 0) << 2),
                  CONCAT22((sword)((uint)param_2 >> 0x10),
                           (word)(byte)((param_2 < 0) << 3 | (param_2 == 0) << 2)));
}
/* GHIDRADEC_FUNCTION index=1549 start=0x4050ae4 */

int _thread_select(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  bool bVar5;
  
  *(undefined4 *)(param_1 + 0x120) = 1;
  piVar2 = (int *)_active_threads;
  if (0 < *(int *)(param_1 + 0x104)) {
    iVar1 = _choose_thread(param_1);
    *(undefined4 *)(param_1 + 0x11c) = _min_quantum;
    return iVar1;
  }
  if (dword_40B674C == 0) {
    if ((*(int *)(_active_threads + 0x48) == 4) &&
       ((*(int *)(_active_threads + 0x17c) == 0 || (param_1 == *(int *)(_active_threads + 0x17c)))))
    {
      if (*(int *)(_active_threads + 0x6c) != _sched_tick) {
        _update_priority(_active_threads);
      }
      goto loc_4050BB0;
    }
  }
  else {
    piVar4 = (int *)(_default_pset + dword_40B6748 * 8);
    piVar2 = (int *)*piVar4;
    if (piVar2 != piVar4) {
      if (piVar4 == piVar2) {
        piVar2 = (int *)0x0;
      }
      else {
        *(int **)(*piVar2 + 4) = piVar4;
        *piVar4 = *piVar2;
      }
      *(undefined4 *)((int)piVar2 + 8) = 0;
      iVar1 = dword_40B674C + -1;
      iVar3 = dword_40B674C + -1;
      bVar5 = dword_40B674C != 1;
      dword_40B674C = iVar1;
      if (((bVar5 && -1 < iVar3) && ((DAT_40b67a3 & 2) != 0)) && (piVar4 == (int *)*piVar4)) {
        do {
          dword_40B6748 = dword_40B6748 + -1;
          piVar4 = piVar4 + -2;
        } while (piVar4 == (int *)*piVar4);
      }
      goto loc_4050BB0;
    }
    dword_40B6748 = dword_40B6748 + -1;
  }
  piVar2 = (int *)_choose_pset_thread(param_1,_default_pset);
loc_4050BB0:
  if (*(int *)((int)piVar2 + 0x5c) == 2) {
    *(undefined4 *)(param_1 + 0x11c) = *(undefined4 *)((int)piVar2 + 0x58);
  }
  else {
    *(undefined4 *)(param_1 + 0x11c) = dword_40B67A4;
  }
  return (int)piVar2;
}

