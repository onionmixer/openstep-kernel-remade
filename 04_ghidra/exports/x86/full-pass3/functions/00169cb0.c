/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00169cb0 */

void FUN_00169cb0(void)

{
  code *pcVar1;
  int iVar2;
  thread_act_t target_act;
  int *piVar3;
  int *piVar4;
  
  target_act = _active_threads;
  _splsched();
  do {
  } while (DAT_001e7244 != 0);
  LOCK();
  UNLOCK();
  while (0 < DAT_001e7260) {
    if ((int **)DAT_001e7250 == &DAT_001e7250) {
      piVar4 = (int *)0x0;
    }
    else {
      *(int ***)(*DAT_001e7250 + 4) = &DAT_001e7250;
      piVar4 = DAT_001e7250;
      DAT_001e7250 = (int *)*DAT_001e7250;
    }
    DAT_001e7260 = DAT_001e7260 + -1;
    pcVar1 = (code *)piVar4[2];
    iVar2 = piVar4[3];
    piVar4[7] = 0;
    piVar3 = piVar4;
    if (((int *)0x1e6a43 < piVar4) && (piVar4 < &DAT_001e7244)) {
      *piVar4 = (int)&DAT_001e7248;
      piVar4[1] = (int)DAT_001e724c;
      *(int **)piVar4[1] = piVar4;
      piVar3 = (int *)0x0;
      DAT_001e724c = piVar4;
    }
    DAT_001e7264 = DAT_001e7264 + 1;
    LOCK();
    DAT_001e7244 = 0;
    UNLOCK();
    _spl0();
    (*pcVar1)(iVar2,piVar3);
    _splsched();
    do {
    } while (DAT_001e7244 != 0);
    LOCK();
    UNLOCK();
    DAT_001e7264 = DAT_001e7264 + -1;
  }
  DAT_001e7244 = 1;
  if (DAT_001e7268 - DAT_001e7264 < 5) {
    _assert_wait(&DAT_001e7260,0);
    LOCK();
    DAT_001e7244 = 0;
    UNLOCK();
    _thread_block_with_continuation(FUN_00169cb0);
  }
  DAT_001e7268 = DAT_001e7268 + -1;
  LOCK();
  DAT_001e7244 = 0;
  UNLOCK();
  _spl0();
  _thread_terminate(target_act);
  _thread_halt_self();
  return;
}

