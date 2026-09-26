
void _do_exit(int param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  word wVar9;
  int iVar10;
  sword sVar11;
  int iVar12;
  int iStack_14;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  
  iVar6 = _get_posix_proc((int)*(sword *)(param_1 + 0x30));
  if (*(int *)(param_1 + 0x76) != _active_threads) {
    if ((*(int *)(param_1 + 0x72) != 0) || (*(int *)(param_1 + 0x76) != 0)) {
      do {
        if (*(int *)(param_1 + 0x76) == 0) goto loc_400554E;
        while( true ) {
          if (_active_threads == *(int *)(param_1 + 0x76)) {
            return;
          }
          _thread_hold(_active_threads);
loc_400554E:
          _thread_block();
          if ((*(uint *)(_active_threads + 0x177) & 0x3ffffff) >> 0x18 != 0) {
            return;
          }
          if (*(int *)(param_1 + 0x72) != 0) break;
          if (*(int *)(param_1 + 0x76) == 0) goto loc_4005572;
        }
      } while( true );
    }
loc_4005572:
    *(int *)(param_1 + 0x76) = _active_threads;
    _task_hold(*(undefined4 *)(_active_threads + 0xc));
    _task_dowait(*(undefined4 *)(_active_threads + 0xc),0);
  }
  iVar2 = *(int *)(param_1 + 0x66);
  _task_halt(iVar2);
  iVar8 = *(int *)(iVar2 + 0x30);
  *(uint *)(param_1 + 0x28) = *(uint *)(param_1 + 0x28) & 0xffffffaf | 0x400;
  *(undefined4 *)(param_1 + 0x20) = 0xffffffff;
  iVar10 = 0x1f;
  do {
    do {
      *(undefined4 *)(iVar8 + 0x2a + iVar10 * 4) = 1;
      wVar9 = (word)((uint)iVar10 >> 0x10);
      sVar11 = (sword)iVar10 + -1;
      iVar10 = CONCAT22(wVar9,sVar11);
    } while (sVar11 != -1);
    iVar10 = (uint)wVar9 * 0x10000 + -1;
  } while (wVar9 != 0);
  _untimeout(_realitexpire,param_1);
  iVar10 = 0;
  if (*(uint *)(iVar8 + 0x14e) < 0x80000000) {
    do {
      iVar12 = *(int *)(*(int *)(iVar8 + 0x146) + iVar10 * 4);
      if ((iVar12 != 0) && (iVar12 != -0x10000)) {
        _vno_lockrelease(iVar12);
        *(undefined4 *)(*(int *)(iVar8 + 0x146) + iVar10 * 4) = 0;
        _closef(iVar12);
      }
      *(undefined *)(*(int *)(iVar8 + 0x14a) + iVar10) = 0;
      iVar10 = iVar10 + 1;
    } while (iVar10 <= *(int *)(iVar8 + 0x14e));
  }
  if (*(int *)(iVar8 + 0x156) != 0) {
    _vn_rele(*(int *)(iVar8 + 0x156));
  }
  if (*(int *)(iVar8 + 0x15a) != 0) {
    _vn_rele(*(int *)(iVar8 + 0x15a));
  }
  *(undefined4 *)(iVar8 + 0x25e) = 0x7fffffff;
  _acct();
  _crfree(*(undefined4 *)(iVar8 + 0x1a));
  if ((_machine_type == '\0') || (_machine_type == '\x02')) {
    _od_unlock_check((int)*(sword *)(param_1 + 0x30));
  }
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
  *(undefined *)(param_1 + 0x13) = 5;
  uVar5 = *(word *)(param_1 + 0x30) & 0x3f;
  iVar10 = *(int *)(_pidhash + uVar5 * 4);
  if (*(int *)(_pidhash + uVar5 * 4) == param_1) {
    *(undefined4 *)(_pidhash + uVar5 * 4) = *(undefined4 *)(param_1 + 0x3e);
    if (*(sword *)(param_1 + 0x30) == 1) {
      _printf(aInitExitedWith,param_2 >> 8);
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
  }
  else {
    do {
      iVar12 = iVar10;
      if (iVar12 == 0) {
                    /* WARNING: Subroutine does not return */
        _panic(&aExit);
      }
      iVar10 = *(int *)(iVar12 + 0x3e);
    } while (param_1 != *(int *)(iVar12 + 0x3e));
    *(undefined4 *)(iVar12 + 0x3e) = *(undefined4 *)(param_1 + 0x3e);
  }
  *(sword *)(param_1 + 0x34) = (sword)param_2;
  piVar3 = (int *)(iVar8 + 0x166);
  *piVar3 = 0;
  *(undefined4 *)(iVar8 + 0x16a) = 0;
  piVar4 = (int *)(iVar8 + 0x16e);
  *piVar4 = 0;
  *(undefined4 *)(iVar8 + 0x172) = 0;
  for (puVar1 = *(undefined4 **)(iVar2 + 0x18); puVar1 != (undefined4 *)(iVar2 + 0x18);
      puVar1 = (undefined4 *)puVar1[4]) {
    _thread_read_times(puVar1,&iStack_c,&iStack_14);
    *piVar3 = iStack_c + *piVar3;
    *(int *)(iVar8 + 0x16a) = iStack_8 + *(int *)(iVar8 + 0x16a);
    *piVar4 = iStack_14 + *piVar4;
    *(int *)(iVar8 + 0x172) = iStack_10 + *(int *)(iVar8 + 0x172);
  }
  *piVar3 = *(int *)(iVar2 + 0x4c) + *piVar3;
  *(int *)(iVar8 + 0x16a) = *(int *)(iVar2 + 0x50) + *(int *)(iVar8 + 0x16a);
  *piVar4 = *(int *)(iVar2 + 0x54) + *piVar4;
  *(int *)(iVar8 + 0x172) = *(int *)(iVar2 + 0x58) + *(int *)(iVar8 + 0x172);
  uVar7 = _kalloc(0x48);
  *(undefined4 *)(param_1 + 0x36) = uVar7;
  _bcopy(_active_u + 0x166,uVar7,0x48);
  _ruadd(*(undefined4 *)(param_1 + 0x36),iVar8 + 0x1ae);
  if (*(int *)(param_1 + 0x46) != 0) {
    _wakeup(_init_proc);
  }
  iVar8 = *(int *)(param_1 + 0x7e);
  if (iVar8 != 0) {
    *(undefined4 *)(iVar8 + 0x7a) = 0;
    *(uint *)(iVar8 + 0x28) = *(uint *)(iVar8 + 0x28) & 0xffffffef;
    _psignal(iVar8,9);
    *(undefined4 *)(param_1 + 0x7e) = 0;
  }
  if ((*(byte *)(param_1 + 0x16) & 0x40) != 0) {
    iVar6 = *(int *)(*(int *)(iVar6 + 0xe) + 8);
    if (param_1 == *(int *)(iVar6 + 4)) {
      if ((*(int *)(iVar6 + 8) != 0) &&
         (iVar8 = _ttynty(*(int *)(iVar6 + 8)), iVar6 == *(int *)(iVar8 + 8))) {
        if (*(int *)(iVar8 + 0xc) != 0) {
          _pgsignal(*(int *)(iVar8 + 0xc),1,1);
        }
        _ttywait(*(undefined4 *)(iVar6 + 8));
      }
      *(undefined4 *)(iVar6 + 4) = 0;
    }
    if ((*(byte *)(param_1 + 0x16) & 0x40) != 0) {
      iVar6 = _get_posix_proc((int)*(sword *)(param_1 + 0x30),0);
      _fixjobc(param_1,*(undefined4 *)(iVar6 + 0xe));
    }
  }
  iVar6 = *(int *)(param_1 + 0x46);
  while (iVar6 != 0) {
    iVar8 = *(int *)(iVar6 + 0x4a);
    if (iVar8 != 0) {
      *(undefined4 *)(iVar8 + 0x4e) = 0;
    }
    if (*(int *)(_init_proc + 0x46) != 0) {
      *(int *)(*(int *)(_init_proc + 0x46) + 0x4e) = iVar6;
    }
    iVar10 = _init_proc;
    *(undefined4 *)(iVar6 + 0x4a) = *(undefined4 *)(_init_proc + 0x46);
    *(undefined4 *)(iVar6 + 0x4e) = 0;
    *(int *)(iVar10 + 0x46) = iVar6;
    *(int *)(iVar6 + 0x42) = iVar10;
    *(undefined2 *)(iVar6 + 0x32) = 1;
    if ((*(uint *)(iVar6 + 0x28) & 0x10) == 0) {
      if ((*(int *)(iVar6 + 0x66) != 0) && (0 < *(int *)(*(int *)(iVar6 + 0x66) + 0x3c))) {
        _psignal(iVar6,1);
        _psignal(iVar6,0x13);
      }
    }
    else {
      *(uint *)(iVar6 + 0x28) = *(uint *)(iVar6 + 0x28) & 0xffffffef;
      *(undefined4 *)(iVar6 + 0x7a) = 0;
      _psignal(iVar6,9);
    }
    _spgrp(iVar6);
    iVar6 = iVar8;
  }
  *(undefined4 *)(param_1 + 0x46) = 0;
  if (*(int *)(param_1 + 0x7a) != 0) {
    _psignal(*(int *)(param_1 + 0x7a),0x14);
    _wakeup(*(undefined4 *)(param_1 + 0x7a));
    *(undefined4 *)(*(int *)(param_1 + 0x7a) + 0x7e) = 0;
  }
  if (*(int *)(_active_u + 0x23c) != 0) {
    *(undefined4 *)(_active_u + 0x250) = 0;
    _simple_lock_free(*(undefined4 *)(_active_u + 0x23c));
  }
  iVar6 = *(int *)(_active_u + 0x240);
  while (iVar6 != 0) {
    iVar8 = *(int *)(iVar6 + 4);
    _kfree(iVar6,0x18);
    iVar6 = iVar8;
  }
  _psignal(*(undefined4 *)(param_1 + 0x42),0x14);
  _wakeup(*(undefined4 *)(param_1 + 0x42));
  *(undefined4 *)(param_1 + 0x66) = 0;
  *(undefined4 *)(param_1 + 0x6a) = 0;
  _task_terminate(iVar2);
  if (iVar2 == *(int *)(_active_threads + 0xc)) {
    _thread_halt_self();
  }
  return;
}

