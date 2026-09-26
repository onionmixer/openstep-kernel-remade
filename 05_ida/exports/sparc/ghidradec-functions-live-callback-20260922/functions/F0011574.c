
/* WARNING: Removing unreachable block (ram,0xf001198c) */
/* WARNING: Removing unreachable block (ram,0xf001195c) */
/* WARNING: Removing unreachable block (ram,0xf0011940) */
/* WARNING: Removing unreachable block (ram,0xf001191c) */
/* WARNING: Removing unreachable block (ram,0xf00118a8) */
/* WARNING: Removing unreachable block (ram,0xf001185c) */
/* WARNING: Removing unreachable block (ram,0xf00117b0) */
/* WARNING: Removing unreachable block (ram,0xf0011764) */
/* WARNING: Removing unreachable block (ram,0xf0011728) */
/* WARNING: Removing unreachable block (ram,0xf0011700) */
/* WARNING: Removing unreachable block (ram,0xf0011734) */
/* WARNING: Removing unreachable block (ram,0xf0011774) */
/* WARNING: Removing unreachable block (ram,0xf0011968) */
/* WARNING: Removing unreachable block (ram,0xf00118a0) */
/* WARNING: Removing unreachable block (ram,0xf00118fc) */
/* WARNING: Removing unreachable block (ram,0xf0011938) */
/* WARNING: Removing unreachable block (ram,0xf0011954) */
/* WARNING: Removing unreachable block (ram,0xf0011984) */
/* WARNING: Removing unreachable block (ram,0xf00119a0) */
/* WARNING: Removing unreachable block (ram,0xf00116c4) */

undefined8 _psignal(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar6;
  uint uVar7;
  undefined4 unaff_l3;
  uint uVar8;
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
  if (0x20 < param_2) goto locret_F00119A8;
  iVar6 = *(int *)(param_1 + 0x68);
  uVar7 = 1 << ((char)param_2 - 1U & 0x1f);
  if ((iVar6 == 0) || (*(int *)(iVar6 + 0x50) != 0)) goto locret_F00119A8;
  uVar2 = *(uint *)(param_1 + 0x28);
  uVar8 = 0;
  if ((uVar2 & 0x10) == 0) {
    uVar2 = *(uint *)(param_1 + 0x14);
    if (((uVar2 & 0x4000) == 0) || (uVar7 != 0x40000)) {
      if ((*(uint *)(param_1 + 0x20) & uVar7) != 0) goto locret_F00119A8;
      uVar2 = *(uint *)(param_1 + 0x14);
    }
    if (((uVar2 & 0x4000) == 0) || (uVar7 != 0x40000)) {
      uVar2 = *(uint *)(param_1 + 0x1c);
      uVar8 = 3;
      if ((uVar2 & uVar7) != 0) goto loc_F0011628;
      uVar2 = *(uint *)(param_1 + 0x24);
    }
    else {
      uVar2 = *(uint *)(param_1 + 0x24);
    }
    uVar2 = -(uint)((uVar2 & uVar7) != 0);
    uVar8 = uVar2 & 2;
  }
loc_F0011628:
  if (param_2 != 0) {
    uVar2 = *(uint *)(param_1 + 0x18) | uVar7;
    *(uint *)(param_1 + 0x18) = uVar2;
    if (7 < param_2 - 0xf) goto def_F0011658;
    uVar2 = *(uint *)((param_2 - 0xf) * 4 + -0xffee9a0);
    switch(param_2) {
    case :
      uVar2 = *(uint *)(param_1 + 0x28);
      if (((uVar2 & 0x10) == 0) && (uVar8 == 0)) goto loc_F001169C;
      goto loc_F00116BC;
    case :
    case :
      goto def_F0011658;
    :
      uVar2 = *(uint *)(param_1 + 0x18);
      uVar4 = 0x40000;
      break;
    case :
loc_F001169C:
      uVar2 = *(uint *)(param_1 + 0x18);
      uVar4 = 0x330000;
    }
    uVar2 = uVar2 & ~uVar4;
    *(uint *)(param_1 + 0x18) = uVar2;
  }
def_F0011658:
loc_F00116BC:
  if (uVar8 == 3) goto locret_F00119A8;
  _splusclock();
  iVar1 = _active_threads;
  iVar5 = _active_threads;
  if (iVar6 != *(int *)(_active_threads + 0xc)) {
    do {
      do {
      } while (*(int *)(iVar6 + 0x28) != 0);
      piVar3 = (int *)(iVar6 + 0x28);
      _simple_lock_try();
    } while (piVar3 == (int *)0x0);
    iVar5 = *(int *)(iVar6 + 0x1c);
    if (iVar6 + 0x1c == iVar5) {
      *(undefined4 *)(iVar6 + 0x28) = 0;
      _splx(uVar2);
      goto locret_F00119A8;
    }
    _thread_reference(iVar5);
    *(undefined4 *)(iVar6 + 0x28) = 0;
  }
  if (param_2 == 9) {
    if ('\0' < *(char *)(param_1 + 0x15)) {
      *(undefined *)(param_1 + 0x15) = 0;
      _thread_max_priority(iVar5,*(undefined4 *)(iVar5 + 400),10);
      _thread_priority(iVar5,10,0);
    }
    uVar4 = *(uint *)(param_1 + 0x28);
  }
  else {
    uVar4 = *(uint *)(param_1 + 0x28);
  }
  if ((uVar4 & 0x10) == 0) {
    if (uVar8 != 0) {
      if (param_2 != 0x13) goto loc_F0011980;
      _task_resume(iVar6);
      *(undefined *)(param_1 + 0x13) = 3;
def_F00117E0:
      goto loc_F0011980;
    }
    switch(param_2) {
    case :
      while (0 < *(int *)(iVar6 + 0x44)) {
        _task_resume(iVar6);
      }
      *(undefined *)(param_1 + 0x13) = 3;
      while (0 < *(int *)(iVar5 + 0x8c)) {
        _thread_resume(iVar5);
      }
      _clear_wait(iVar5,3,0);
      _splx(uVar2);
      if (iVar5 != iVar1) {
        _mach_msg_abort_rpc(iVar5);
        _thread_deallocate(iVar5);
      }
      goto locret_F00119A8;
    :
      goto def_F00117E0;
    case :
    case :
    case :
    case :
      uVar8 = *(uint *)(param_1 + 0x18);
loc_F00118F0:
      *(uint *)(param_1 + 0x18) = uVar8 & ~uVar7;
      break;
    case :
    case :
    case :
    case :
      if (param_2 == 0x11) {
        uVar8 = *(uint *)(iVar5 + 0x4c);
      }
      else {
        if (*(int *)(param_1 + 0x44) == _init_proc) {
          _psignal(param_1,9);
          uVar8 = *(uint *)(param_1 + 0x18);
          goto loc_F00118F0;
        }
        uVar8 = *(uint *)(iVar5 + 0x4c);
      }
      if ((uVar8 & 4) == 0) {
        *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) & ~uVar7;
        if (*(int *)(iVar6 + 0x44) == 0) {
          *(uint *)(param_1 + 0x3c) = param_2;
          _psignal(*(undefined4 *)(param_1 + 0x44),0x14);
          _stop(param_1);
        }
      }
      else if ((param_1 == *_active_u) && (*(char *)(param_1 + 0x13) != '\x05')) {
        _need_ast = _need_ast | 0x20;
      }
      break;
    case :
      _task_resume(iVar6);
      *(undefined *)(param_1 + 0x13) = 3;
    }
  }
  else {
    if (*(char *)(param_1 + 0x13) == '\x06') goto loc_F001198C;
loc_F0011980:
    _clear_wait(iVar5,2,1);
  }
loc_F001198C:
  _splx(uVar2);
  if (iVar5 != iVar1) {
    _thread_deallocate_interrupt(iVar5);
  }
locret_F00119A8:
  return CONCAT44(param_2,param_1);
}

