
/* WARNING: Removing unreachable block (ram,0xf000cdb0) */
/* WARNING: Removing unreachable block (ram,0xf000cd98) */
/* WARNING: Removing unreachable block (ram,0xf000cd60) */
/* WARNING: Removing unreachable block (ram,0xf000cd28) */
/* WARNING: Removing unreachable block (ram,0xf000ccfc) */
/* WARNING: Removing unreachable block (ram,0xf000cc48) */
/* WARNING: Removing unreachable block (ram,0xf000cc18) */
/* WARNING: Removing unreachable block (ram,0xf000cbe4) */
/* WARNING: Removing unreachable block (ram,0xf000cb70) */
/* WARNING: Removing unreachable block (ram,0xf000cb4c) */
/* WARNING: Removing unreachable block (ram,0xf000cae8) */
/* WARNING: Removing unreachable block (ram,0xf000ca74) */
/* WARNING: Removing unreachable block (ram,0xf000ca24) */
/* WARNING: Removing unreachable block (ram,0xf000c954) */
/* WARNING: Removing unreachable block (ram,0xf000c93c) */
/* WARNING: Removing unreachable block (ram,0xf000c8f0) */
/* WARNING: Removing unreachable block (ram,0xf000c8a0) */
/* WARNING: Removing unreachable block (ram,0xf000c7f0) */
/* WARNING: Removing unreachable block (ram,0xf000c7b8) */
/* WARNING: Removing unreachable block (ram,0xf000c838) */
/* WARNING: Removing unreachable block (ram,0xf000c778) */
/* WARNING: Removing unreachable block (ram,0xf000c848) */
/* WARNING: Removing unreachable block (ram,0xf000c7c0) */
/* WARNING: Removing unreachable block (ram,0xf000c854) */
/* WARNING: Removing unreachable block (ram,0xf000c8e0) */
/* WARNING: Removing unreachable block (ram,0xf000c924) */
/* WARNING: Removing unreachable block (ram,0xf000c94c) */
/* WARNING: Removing unreachable block (ram,0xf000ca04) */
/* WARNING: Removing unreachable block (ram,0xf000ca60) */
/* WARNING: Removing unreachable block (ram,0xf000ca90) */
/* WARNING: Removing unreachable block (ram,0xf000cb34) */
/* WARNING: Removing unreachable block (ram,0xf000cb58) */
/* WARNING: Removing unreachable block (ram,0xf000cb98) */
/* WARNING: Removing unreachable block (ram,0xf000cc10) */
/* WARNING: Removing unreachable block (ram,0xf000cc38) */
/* WARNING: Removing unreachable block (ram,0xf000ccec) */
/* WARNING: Removing unreachable block (ram,0xf000cd04) */
/* WARNING: Removing unreachable block (ram,0xf000cd30) */
/* WARNING: Removing unreachable block (ram,0xf000cd80) */
/* WARNING: Removing unreachable block (ram,0xf000cda0) */
/* WARNING: Removing unreachable block (ram,0xf000cdd0) */
/* WARNING: Removing unreachable block (ram,0xf000c744) */

undefined8 _do_exit(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  undefined4 unaff_l0;
  int *piVar7;
  undefined4 unaff_l1;
  int *piVar8;
  int *piVar9;
  undefined4 unaff_l3;
  int iVar10;
  undefined4 unaff_l4;
  int *piVar11;
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
  undefined auStackX_0 [92];
  
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
  iVar1 = (int)*(sword *)(param_1 + 0x30);
  _get_posix_proc();
  if (_active_threads != *(int *)(param_1 + 0x78)) {
    do {
      do {
      } while (*(int *)(param_1 + 0x70) != 0);
      piVar11 = (int *)(param_1 + 0x70);
      _simple_lock_try();
    } while (piVar11 == (int *)0x0);
    iVar2 = *(int *)(param_1 + 0x74);
    do {
      if (iVar2 == 0) {
        if (*(int *)(param_1 + 0x78) == 0) {
          *(int *)(param_1 + 0x78) = _active_threads;
          *(undefined4 *)(param_1 + 0x70) = 0;
          _task_hold(*(undefined4 *)(_active_threads + 0xc));
          _task_dowait(*(undefined4 *)(_active_threads + 0xc),0);
          break;
        }
        iVar2 = *(int *)(param_1 + 0x78);
      }
      else {
        iVar2 = *(int *)(param_1 + 0x78);
      }
      *(undefined4 *)(param_1 + 0x70) = 0;
      if (iVar2 != 0) {
        if (_active_threads == iVar2) goto locret_F000CDD8;
        _thread_hold();
      }
      _thread_block();
      if ((*(uint *)(_active_threads + 0x18c) & 3) != 0) goto locret_F000CDD8;
      do {
        do {
        } while (*(int *)(param_1 + 0x70) != 0);
        piVar11 = (int *)(param_1 + 0x70);
        _simple_lock_try();
      } while (piVar11 == (int *)0x0);
      iVar2 = *(int *)(param_1 + 0x74);
    } while( true );
  }
  piVar11 = *(int **)(param_1 + 0x68);
  _task_halt(piVar11);
  iVar10 = piVar11[0xe];
  *(uint *)(param_1 + 0x28) = *(uint *)(param_1 + 0x28) & 0xffffffaf | 0x400;
  *(undefined4 *)(param_1 + 0x20) = 0xffffffff;
  *(undefined4 *)(iVar10 + 0xac) = 1;
  iVar2 = iVar10 + 0x7c;
  while (iVar10 <= iVar2 + -4) {
    *(undefined4 *)(iVar2 + 0x2c) = 1;
    iVar2 = iVar2 + -4;
  }
  _untimeout(_realitexpire,param_1);
  iVar2 = 0;
  if (-1 < *(int *)(iVar10 + 0x154)) {
    iVar5 = *(int *)(iVar10 + 0x14c);
    do {
      iVar5 = *(int *)(iVar5 + iVar2 * 4);
      if (iVar5 == 0) {
loc_F000C8F8:
        iVar5 = *(int *)(iVar10 + 0x150);
      }
      else {
        if (iVar5 != -0x10000) {
          _vno_lockrelease(iVar5);
          *(undefined4 *)(*(int *)(iVar10 + 0x14c) + iVar2 * 4) = 0;
          _closef(iVar5);
          goto loc_F000C8F8;
        }
        iVar5 = *(int *)(iVar10 + 0x150);
      }
      *(undefined *)(iVar5 + iVar2) = 0;
      iVar2 = iVar2 + 1;
      if (*(int *)(iVar10 + 0x154) < iVar2) goto loc_f000c914;
      iVar5 = *(int *)(iVar10 + 0x14c);
    } while( true );
  }
  iVar2 = *(int *)(iVar10 + 0x15c);
loc_F000C918:
  if (iVar2 == 0) {
    iVar2 = *(int *)(iVar10 + 0x160);
  }
  else {
    _vn_rele();
    iVar2 = *(int *)(iVar10 + 0x160);
  }
  if (iVar2 != 0) {
    _vn_rele();
  }
  *(undefined4 *)(iVar10 + 0x268) = 0x7fffffff;
  _acct();
  _crfree(*(undefined4 *)(iVar10 + 0x1c));
  iVar2 = *(int *)(param_1 + 8);
  **(int **)(param_1 + 0xc) = iVar2;
  if (iVar2 != 0) {
    *(undefined4 *)(*(int *)(param_1 + 8) + 0xc) = *(undefined4 *)(param_1 + 0xc);
  }
  *(int *)(param_1 + 8) = _zombproc;
  if (_zombproc != 0) {
    *(int *)(_zombproc + 0xc) = param_1 + 8;
  }
  *(int **)(param_1 + 0xc) = &_zombproc;
  _zombproc = param_1;
  *(undefined *)(param_1 + 0x13) = 5;
  iVar5 = (*(word *)(param_1 + 0x30) & 0x3f) * 4;
  iVar2 = *(int *)(_pidhash + iVar5);
  if (param_1 == *(int *)(_pidhash + iVar5)) {
    *(undefined4 *)(_pidhash + iVar5) = *(undefined4 *)(param_1 + 0x40);
loc_F000CA0C:
    if (*(sword *)(param_1 + 0x30) == 1) {
      _printf(aInitExitedWith,(int)param_2 >> 8);
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    *(sword *)(param_1 + 0x34) = (sword)param_2;
  }
  else {
    do {
      iVar5 = iVar2;
      if (iVar5 == 0) {
        _panic(&aExit);
        goto loc_F000CA0C;
      }
      iVar2 = *(int *)(iVar5 + 0x40);
    } while (*(int *)(iVar5 + 0x40) != param_1);
    *(undefined4 *)(iVar5 + 0x40) = *(undefined4 *)(param_1 + 0x40);
    *(sword *)(param_1 + 0x34) = (sword)param_2;
  }
  piVar8 = (int *)(iVar10 + 0x16c);
  *(undefined4 *)(iVar10 + 0x16c) = 0;
  *(undefined4 *)(iVar10 + 0x170) = 0;
  piVar9 = (int *)(iVar10 + 0x174);
  *(undefined4 *)(iVar10 + 0x174) = 0;
  *(undefined4 *)(iVar10 + 0x178) = 0;
  param_2 = piVar11 + 7;
  do {
    do {
    } while (*piVar11 != 0);
    piVar3 = piVar11;
    _simple_lock_try();
  } while (piVar3 == (int *)0x0);
  piVar7 = (int *)*param_2;
  _splusclock();
  for (; param_2 != piVar7; piVar7 = (int *)piVar7[4]) {
    _thread_read_times(piVar7,(undefined *)((int)register0x00000038 + -0x18),
                       (undefined *)((int)register0x00000038 + -0x10));
    *piVar8 = *piVar8 + *(int *)((int)register0x00000038 + -0x18);
    *(int *)(iVar10 + 0x170) = *(int *)(iVar10 + 0x170) + *(int *)((int)register0x00000038 + -0x14);
    *piVar9 = *piVar9 + *(int *)((int)register0x00000038 + -0x10);
    *(int *)(iVar10 + 0x178) = *(int *)(iVar10 + 0x178) + *(int *)((int)register0x00000038 + -0xc);
  }
  _splx(piVar3);
  *piVar8 = *piVar8 + piVar11[0x15];
  *(int *)(iVar10 + 0x170) = *(int *)(iVar10 + 0x170) + piVar11[0x16];
  *piVar9 = *piVar9 + piVar11[0x17];
  *(int *)(iVar10 + 0x178) = *(int *)(iVar10 + 0x178) + piVar11[0x18];
  *piVar11 = 0;
  uVar4 = 0x48;
  _kalloc();
  *(undefined4 *)(param_1 + 0x38) = uVar4;
  _memcpy();
  _ruadd(*(undefined4 *)(param_1 + 0x38),iVar10 + 0x1b4);
  if (*(int *)(param_1 + 0x48) != 0) {
    _wakeup(_init_proc);
  }
  iVar2 = *(int *)(param_1 + 0x80);
  if (iVar2 != 0) {
    *(undefined4 *)(iVar2 + 0x7c) = 0;
    *(uint *)(iVar2 + 0x28) = *(uint *)(iVar2 + 0x28) & 0xffffffef;
    _psignal(iVar2,9);
    *(undefined4 *)(param_1 + 0x80) = 0;
  }
  if ((*(uint *)(param_1 + 0x14) & 0x4000) == 0) {
    iVar1 = *(int *)(param_1 + 0x48);
  }
  else {
    iVar1 = *(int *)(*(int *)(iVar1 + 0x10) + 8);
    if (*(int *)(iVar1 + 4) == param_1) {
      iVar2 = *(int *)(iVar1 + 8);
      if (iVar2 == 0) {
        *(undefined4 *)(iVar1 + 4) = 0;
      }
      else {
        _ttynty();
        if (*(int *)(iVar2 + 8) == iVar1) {
          if (*(int *)(iVar2 + 0xc) != 0) {
            _pgsignal(*(int *)(iVar2 + 0xc),1,1);
          }
          _ttywait(*(undefined4 *)(iVar1 + 8));
          *(undefined4 *)(iVar1 + 4) = 0;
        }
        else {
          *(undefined4 *)(iVar1 + 4) = 0;
        }
      }
      uVar6 = *(uint *)(param_1 + 0x14);
    }
    else {
      uVar6 = *(uint *)(param_1 + 0x14);
    }
    if ((uVar6 & 0x4000) == 0) {
      iVar1 = *(int *)(param_1 + 0x48);
    }
    else {
      iVar1 = (int)*(sword *)(param_1 + 0x30);
      _get_posix_proc();
      _fixjobc(param_1,*(undefined4 *)(iVar1 + 0x10),0);
      iVar1 = *(int *)(param_1 + 0x48);
    }
  }
  if (iVar1 != 0) {
    iVar2 = *(int *)(iVar1 + 0x4c);
    do {
      if (iVar2 != 0) {
        *(undefined4 *)(iVar2 + 0x50) = 0;
      }
      if (*(int *)(_init_proc + 0x48) != 0) {
        *(int *)(*(int *)(_init_proc + 0x48) + 0x50) = iVar1;
      }
      iVar10 = _init_proc;
      *(undefined4 *)(iVar1 + 0x4c) = *(undefined4 *)(_init_proc + 0x48);
      *(undefined4 *)(iVar1 + 0x50) = 0;
      *(int *)(iVar10 + 0x48) = iVar1;
      *(int *)(iVar1 + 0x44) = iVar10;
      *(undefined2 *)(iVar1 + 0x32) = 1;
      if ((*(uint *)(iVar1 + 0x28) & 0x10) == 0) {
        if ((*(int *)(iVar1 + 0x68) != 0) && (0 < *(int *)(*(int *)(iVar1 + 0x68) + 0x44))) {
          _psignal(iVar1,1);
          uVar4 = 0x13;
          goto loc_F000CCFC;
        }
      }
      else {
        *(uint *)(iVar1 + 0x28) = *(uint *)(iVar1 + 0x28) & 0xffffffef;
        *(undefined4 *)(iVar1 + 0x7c) = 0;
        uVar4 = 9;
loc_F000CCFC:
        _psignal(iVar1,uVar4);
      }
      _spgrp(iVar1);
      if (iVar2 == 0) goto loc_f000cd18;
      iVar1 = iVar2;
      iVar2 = *(int *)(iVar2 + 0x4c);
    } while( true );
  }
  iVar1 = *(int *)(param_1 + 0x7c);
loc_F000CD1C:
  *(undefined4 *)(param_1 + 0x48) = 0;
  if (iVar1 != 0) {
    _psignal(iVar1,0x14);
    _wakeup(*(undefined4 *)(param_1 + 0x7c));
    *(undefined4 *)(*(int *)(param_1 + 0x7c) + 0x80) = 0;
  }
  if (*(int *)(_active_u + 0x244) != 0) {
    *(undefined4 *)(_active_u + 600) = 0;
    _simple_lock_free(*(undefined4 *)(_active_u + 0x244));
  }
  iVar1 = *(int *)(_active_u + 0x248);
  if (iVar1 == 0) {
    uVar4 = *(undefined4 *)(param_1 + 0x44);
  }
  else {
    for (iVar2 = *(int *)(iVar1 + 4); _kfree(iVar1,0x18), iVar2 != 0; iVar2 = *(int *)(iVar2 + 4)) {
      iVar1 = iVar2;
    }
    uVar4 = *(undefined4 *)(param_1 + 0x44);
  }
  _psignal(uVar4,0x14);
  _wakeup(*(undefined4 *)(param_1 + 0x44));
  *(undefined4 *)(param_1 + 0x68) = 0;
  *(undefined4 *)(param_1 + 0x6c) = 0;
  _task_terminate(piVar11);
  if (*(int **)(_active_threads + 0xc) == piVar11) {
    _thread_halt_self();
  }
locret_F000CDD8:
  return CONCAT44(param_2,param_1);
loc_f000c914:
  iVar2 = *(int *)(iVar10 + 0x15c);
  goto loc_F000C918;
loc_f000cd18:
  iVar1 = *(int *)(param_1 + 0x7c);
  goto loc_F000CD1C;
}

