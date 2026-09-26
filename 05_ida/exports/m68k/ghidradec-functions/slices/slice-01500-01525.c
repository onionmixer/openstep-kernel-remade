/* GHIDRADEC_FUNCTION index=1500 start=0x404ecb6 */

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
/* GHIDRADEC_FUNCTION index=1501 start=0x404eea6 */

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
/* GHIDRADEC_FUNCTION index=1502 start=0x404ef42 */

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
/* GHIDRADEC_FUNCTION index=1503 start=0x404efe8 */

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
/* GHIDRADEC_FUNCTION index=1504 start=0x404f050 */

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
/* GHIDRADEC_FUNCTION index=1505 start=0x404f0b8 */

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
/* GHIDRADEC_FUNCTION index=1506 start=0x404f106 */

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
/* GHIDRADEC_FUNCTION index=1507 start=0x404f158 */

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
/* GHIDRADEC_FUNCTION index=1508 start=0x404f19e */

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
/* GHIDRADEC_FUNCTION index=1509 start=0x404f1ea */

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
/* GHIDRADEC_FUNCTION index=1510 start=0x404f230 */

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
/* GHIDRADEC_FUNCTION index=1511 start=0x404f2b0 */

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
/* GHIDRADEC_FUNCTION index=1512 start=0x404f2e4 */

void _pset_reference(int param_1)

{
  *(int *)(param_1 + 0x13c) = *(int *)(param_1 + 0x13c) + 1;
  return;
}
/* GHIDRADEC_FUNCTION index=1513 start=0x404f2f4 */

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
/* GHIDRADEC_FUNCTION index=1514 start=0x404f386 */

undefined4 _processor_start(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 4;
  if (param_1 != 0) {
    uVar1 = 5;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1515 start=0x404f398 */

undefined4 _processor_exit(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 4;
  if (param_1 != 0) {
    uVar1 = 5;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1516 start=0x404f3aa */

undefined4 _processor_control(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 4;
  if (param_1 != 0) {
    uVar1 = 5;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1517 start=0x404f3bc */

void _quantum_set(void)

{
  dword_40B67A4 = _min_quantum;
  return;
}
/* GHIDRADEC_FUNCTION index=1518 start=0x404f3ce */

undefined4 _processor_set_create(void)

{
  return 5;
}
/* GHIDRADEC_FUNCTION index=1519 start=0x404f3d8 */

undefined4 _processor_set_destroy(void)

{
  return 5;
}
/* GHIDRADEC_FUNCTION index=1520 start=0x404f3e2 */

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
/* GHIDRADEC_FUNCTION index=1521 start=0x404f412 */

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
/* GHIDRADEC_FUNCTION index=1522 start=0x404f496 */

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
/* GHIDRADEC_FUNCTION index=1523 start=0x404f4f2 */

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
/* GHIDRADEC_FUNCTION index=1524 start=0x404f520 */

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

