/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00105afc */

void _do_exit(int param_1,int param_2)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int *piVar9;
  char *unaff_EBX;
  int iVar10;
  uint uVar11;
  int *piVar12;
  undefined4 *puVar13;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  iVar3 = _get_posix_proc((int)*(short *)(param_1 + 0x30));
  if (_active_threads != *(int *)(param_1 + 0x78)) {
    piVar7 = (int *)(param_1 + 0x70);
    do {
      do {
      } while (*piVar7 != 0);
      LOCK();
      iVar6 = *piVar7;
      *piVar7 = 1;
      UNLOCK();
    } while (iVar6 == 1);
    while ((*(int *)(param_1 + 0x74) != 0 || (*(int *)(param_1 + 0x78) != 0))) {
      piVar7 = (int *)(param_1 + 0x70);
      LOCK();
      *(undefined4 *)(param_1 + 0x70) = 0;
      UNLOCK();
      if (*(int *)(param_1 + 0x78) != 0) {
        if (_active_threads == *(int *)(param_1 + 0x78)) {
          return;
        }
        _thread_hold(_active_threads);
      }
      _thread_block();
      if ((*(byte *)(_active_threads + 0x17c) & 3) != 0) {
        return;
      }
      do {
        do {
        } while (*piVar7 != 0);
        LOCK();
        iVar6 = *piVar7;
        *piVar7 = 1;
        UNLOCK();
      } while (iVar6 == 1);
    }
    *(int *)(param_1 + 0x78) = _active_threads;
    LOCK();
    *(undefined4 *)(param_1 + 0x70) = 0;
    UNLOCK();
    _task_hold(*(undefined4 *)(_active_threads + 0xc));
    _task_dowait(*(undefined4 *)(_active_threads + 0xc),0);
  }
  piVar7 = *(int **)(param_1 + 0x68);
  _task_halt(piVar7);
  iVar6 = piVar7[0xe];
  *(uint *)(param_1 + 0x28) = *(uint *)(param_1 + 0x28) & 0xffffffaf | 0x400;
  *(undefined4 *)(param_1 + 0x20) = 0xffffffff;
  iVar10 = 0x1f;
  do {
    *(undefined4 *)(iVar6 + 0x30 + iVar10 * 4) = 1;
    iVar10 = iVar10 + -1;
  } while (-1 < iVar10);
  _untimeout(_realitexpire,param_1);
  iVar10 = 0;
  if (-1 < *(int *)(iVar6 + 0x158)) {
    do {
      iVar8 = *(int *)(*(int *)(iVar6 + 0x150) + iVar10 * 4);
      if ((iVar8 != 0) && (iVar8 != -0x10000)) {
        _vno_lockrelease(iVar8);
        *(undefined4 *)(*(int *)(iVar6 + 0x150) + iVar10 * 4) = 0;
        _closef(iVar8);
      }
      *(undefined1 *)(iVar10 + *(int *)(iVar6 + 0x154)) = 0;
      iVar10 = iVar10 + 1;
    } while (iVar10 <= *(int *)(iVar6 + 0x158));
  }
  if (*(int *)(iVar6 + 0x160) != 0) {
    _vn_rele(*(int *)(iVar6 + 0x160));
  }
  if (*(int *)(iVar6 + 0x164) != 0) {
    _vn_rele(*(int *)(iVar6 + 0x164));
  }
  *(undefined4 *)(iVar6 + 0x26c) = 0x7fffffff;
  _acct(unaff_EBX);
  _crfree(*(undefined4 *)(iVar6 + 0x1c));
  iVar10 = *(int *)(param_1 + 8);
  **(int **)(param_1 + 0xc) = iVar10;
  if (iVar10 != 0) {
    *(undefined4 *)(*(int *)(param_1 + 8) + 0xc) = *(undefined4 *)(param_1 + 0xc);
  }
  *(int *)(param_1 + 8) = _zombproc;
  if (_zombproc != 0) {
    *(int *)(_zombproc + 0xc) = param_1 + 8;
  }
  *(int **)(param_1 + 0xc) = &_zombproc;
  _zombproc = param_1;
  *(undefined1 *)(param_1 + 0x13) = 5;
  uVar11 = *(ushort *)(param_1 + 0x30) & 0x3f;
  iVar10 = *(int *)(&_pidhash + uVar11 * 4);
  if (param_1 == *(int *)(&_pidhash + uVar11 * 4)) {
    *(undefined4 *)(&_pidhash + uVar11 * 4) = *(undefined4 *)(param_1 + 0x40);
    if (*(short *)(param_1 + 0x30) == 1) {
      _printf(s_init_exited_with__d_001da84c,param_2 >> 8);
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
  }
  else {
    do {
      iVar8 = iVar10;
      if (iVar8 == 0) {
                    /* WARNING: Subroutine does not return */
        _panic(&DAT_001da847);
      }
      iVar10 = *(int *)(iVar8 + 0x40);
    } while (param_1 != *(int *)(iVar8 + 0x40));
    *(undefined4 *)(iVar8 + 0x40) = *(undefined4 *)(param_1 + 0x40);
  }
  *(undefined2 *)(param_1 + 0x34) = (undefined2)param_2;
  piVar12 = (int *)(iVar6 + 0x170);
  *(undefined4 *)(iVar6 + 0x170) = 0;
  *(undefined4 *)(iVar6 + 0x174) = 0;
  piVar9 = (int *)(iVar6 + 0x178);
  *(undefined4 *)(iVar6 + 0x178) = 0;
  *(undefined4 *)(iVar6 + 0x17c) = 0;
  do {
    do {
    } while (*piVar7 != 0);
    LOCK();
    iVar10 = *piVar7;
    *piVar7 = 1;
    UNLOCK();
  } while (iVar10 == 1);
  piVar1 = (int *)piVar7[7];
  uVar4 = _splsched();
  for (; piVar7 + 7 != piVar1; piVar1 = (int *)piVar1[4]) {
    _thread_read_times(piVar1,&local_c,&local_14);
    *piVar12 = *piVar12 + local_c;
    *(int *)(iVar6 + 0x174) = *(int *)(iVar6 + 0x174) + local_8;
    *piVar9 = *piVar9 + local_14;
    *(int *)(iVar6 + 0x17c) = *(int *)(iVar6 + 0x17c) + local_10;
  }
  _splx(uVar4);
  *piVar12 = *piVar12 + piVar7[0x15];
  *(int *)(iVar6 + 0x174) = *(int *)(iVar6 + 0x174) + piVar7[0x16];
  *piVar9 = *piVar9 + piVar7[0x17];
  *(int *)(iVar6 + 0x17c) = *(int *)(iVar6 + 0x17c) + piVar7[0x18];
  LOCK();
  *piVar7 = 0;
  UNLOCK();
  puVar5 = (undefined4 *)_kalloc(0x48);
  *(undefined4 **)(param_1 + 0x38) = puVar5;
  puVar13 = (undefined4 *)(_active_u + 0x170);
  for (iVar10 = 0x12; iVar10 != 0; iVar10 = iVar10 + -1) {
    *puVar5 = *puVar13;
    puVar13 = puVar13 + 1;
    puVar5 = puVar5 + 1;
  }
  _ruadd(*(undefined4 *)(param_1 + 0x38),iVar6 + 0x1b8);
  if (*(int *)(param_1 + 0x48) != 0) {
    _wakeup(_init_proc);
  }
  uVar11 = *(uint *)(param_1 + 0x80);
  if (uVar11 != 0) {
    *(undefined4 *)(uVar11 + 0x7c) = 0;
    *(uint *)(uVar11 + 0x28) = *(uint *)(uVar11 + 0x28) & 0xffffffef;
    _psignal(uVar11,(char *)0x9);
    *(undefined4 *)(param_1 + 0x80) = 0;
  }
  if ((*(byte *)(param_1 + 0x16) & 2) != 0) {
    iVar3 = *(int *)(*(int *)(iVar3 + 0x10) + 8);
    if (*(int *)(iVar3 + 4) == param_1) {
      if ((*(int *)(iVar3 + 8) != 0) &&
         (iVar6 = _ttynty(*(int *)(iVar3 + 8)), *(int *)(iVar6 + 8) == iVar3)) {
        if (*(int *)(iVar6 + 0xc) != 0) {
          _pgsignal(*(int *)(iVar6 + 0xc),1,1);
        }
        _ttywait(*(undefined4 *)(iVar3 + 8));
      }
      *(undefined4 *)(iVar3 + 4) = 0;
    }
    if ((*(byte *)(param_1 + 0x16) & 2) != 0) {
      iVar3 = _get_posix_proc((int)*(short *)(param_1 + 0x30),0);
      _fixjobc(param_1,*(undefined4 *)(iVar3 + 0x10));
    }
  }
  uVar11 = *(uint *)(param_1 + 0x48);
  while (uVar11 != 0) {
    uVar2 = *(uint *)(uVar11 + 0x4c);
    if (uVar2 != 0) {
      *(undefined4 *)(uVar2 + 0x50) = 0;
    }
    if (*(int *)(_init_proc + 0x48) != 0) {
      *(uint *)(*(int *)(_init_proc + 0x48) + 0x50) = uVar11;
    }
    iVar3 = _init_proc;
    *(undefined4 *)(uVar11 + 0x4c) = *(undefined4 *)(_init_proc + 0x48);
    *(undefined4 *)(uVar11 + 0x50) = 0;
    *(uint *)(iVar3 + 0x48) = uVar11;
    *(int *)(uVar11 + 0x44) = iVar3;
    *(undefined2 *)(uVar11 + 0x32) = 1;
    if ((*(uint *)(uVar11 + 0x28) & 0x10) == 0) {
      if ((*(int *)(uVar11 + 0x68) != 0) && (0 < *(int *)(*(int *)(uVar11 + 0x68) + 0x44))) {
        _psignal(uVar11,(char *)0x1);
        _psignal(uVar11,(char *)0x13);
      }
    }
    else {
      *(uint *)(uVar11 + 0x28) = *(uint *)(uVar11 + 0x28) & 0xffffffef;
      *(undefined4 *)(uVar11 + 0x7c) = 0;
      _psignal(uVar11,(char *)0x9);
    }
    _spgrp(uVar11);
    uVar11 = uVar2;
  }
  *(undefined4 *)(param_1 + 0x48) = 0;
  if (*(uint *)(param_1 + 0x7c) != 0) {
    _psignal(*(uint *)(param_1 + 0x7c),(char *)0x14);
    _wakeup(*(undefined4 *)(param_1 + 0x7c));
    *(undefined4 *)(*(int *)(param_1 + 0x7c) + 0x80) = 0;
  }
  if (*(int *)(_active_u + 0x248) != 0) {
    *(undefined4 *)(_active_u + 0x25c) = 0;
    _simple_lock_free(*(undefined4 *)(_active_u + 0x248));
  }
  iVar3 = *(int *)(_active_u + 0x24c);
  while (iVar3 != 0) {
    iVar6 = *(int *)(iVar3 + 4);
    _kfree(iVar3,0x18);
    iVar3 = iVar6;
  }
  _psignal(*(uint *)(param_1 + 0x44),(char *)0x14);
  _wakeup(*(undefined4 *)(param_1 + 0x44));
  *(undefined4 *)(param_1 + 0x68) = 0;
  *(undefined4 *)(param_1 + 0x6c) = 0;
  _task_terminate((task_t)piVar7);
  if (*(int **)(_active_threads + 0xc) == piVar7) {
    _thread_halt_self();
  }
  return;
}

