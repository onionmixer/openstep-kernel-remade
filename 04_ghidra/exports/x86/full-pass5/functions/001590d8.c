/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001590d8 */

void _thread_go_and_switch(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int *piVar4;
  int iStack_18;
  int iStack_14;
  
  iStack_14 = 0x1590e9;
  uVar3 = _splsched();
  piVar4 = (int *)(param_2 + 0x20);
  do {
    do {
    } while (*piVar4 != 0);
    LOCK();
    iVar1 = *piVar4;
    *piVar4 = 1;
    UNLOCK();
  } while (iVar1 == 1);
  if (*(int *)(param_2 + 0x144) != 0) {
    iStack_14 = param_2 + 0x118;
    iStack_18 = 0x159119;
    _reset_timeout();
  }
  uVar2 = *(uint *)(param_2 + 0x4c);
  switch(uVar2 & 0xf) {
  case 1:
  case 9:
  case 0xb:
    *(uint *)(param_2 + 0x4c) = uVar2 & 0xfffffffe | 4;
    *(undefined4 *)(param_2 + 0x44) = 0;
    if ((*(int *)(*(int *)(param_2 + 0x180) + 0x114) < 1) &&
       (*(int *)(_active_threads + 0x180) == *(int *)(param_2 + 0x180))) {
      LOCK();
      *(undefined4 *)(param_2 + 0x20) = 0;
      UNLOCK();
      iStack_14 = param_2;
      piVar4 = &iStack_18;
      iStack_18 = param_1;
      _thread_run();
      goto LAB_001591e4;
    }
    iStack_14 = 1;
    iStack_18 = param_2;
    _thread_setrun();
    break;
  case 3:
  case 5:
  case 7:
  case 0xd:
  case 0xf:
    *(uint *)(param_2 + 0x4c) = uVar2 & 0xfffffffe;
    *(undefined4 *)(param_2 + 0x44) = 0;
  }
  LOCK();
  *(undefined4 *)(param_2 + 0x20) = 0;
  UNLOCK();
  piVar4 = (int *)&stack0xfffffff0;
  if (param_1 != 0) {
    iStack_14 = 0x1591db;
    _spl0();
    iStack_14 = param_1;
    iStack_18 = 0x1591e1;
    _call_continuation();
    piVar4 = (int *)&stack0xfffffff0;
  }
LAB_001591e4:
  *(undefined4 *)((int)piVar4 + -4) = uVar3;
  *(undefined4 *)((int)piVar4 + -8) = 0x1591ea;
  _splx();
  return;
}

