/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001592ac */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _thread_handoff(int param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = _splsched();
  piVar1 = (int *)(param_3 + 0x20);
  do {
    do {
    } while (*piVar1 != 0);
    LOCK();
    iVar2 = *piVar1;
    *piVar1 = 1;
    UNLOCK();
  } while (iVar2 == 1);
  if ((*(int *)(param_1 + 0x30) == _active_stacks) || (*(int *)(param_3 + 0x4c) != 0x101)) {
    LOCK();
    *(undefined4 *)(param_3 + 0x20) = 0;
    UNLOCK();
    _splx(uVar3);
    __c_thread_handoff_misses = __c_thread_handoff_misses + 1;
    return 0;
  }
  if (*(int *)(param_3 + 0x144) != 0) {
    _reset_timeout(param_3 + 0x118);
  }
  *(undefined4 *)(param_3 + 0x4c) = 4;
  LOCK();
  *(undefined4 *)(param_3 + 0x20) = 0;
  UNLOCK();
  _need_ast = _need_ast & 0xbffffffc | *(uint *)(param_3 + 0x17c);
  _switch_unix_context(param_3);
  _stack_handoff(param_1,param_3);
  piVar1 = (int *)(param_1 + 0x20);
  do {
    do {
    } while (*piVar1 != 0);
    LOCK();
    iVar2 = *piVar1;
    *piVar1 = 1;
    UNLOCK();
  } while (iVar2 == 1);
  *(undefined4 *)(param_1 + 0x34) = param_2;
  if (*(int *)(param_1 + 0x4c) == 4) {
    *(undefined4 *)(param_1 + 0x4c) = 0x101;
  }
  else {
    if (*(int *)(param_1 + 0x4c) != 6) {
                    /* WARNING: Subroutine does not return */
      _panic(s_thread_handoff_001decb5);
    }
    *(undefined4 *)(param_1 + 0x4c) = 0x103;
    if (*(int *)(param_1 + 0x48) != 0) {
      *(undefined4 *)(param_1 + 0x48) = 0;
      LOCK();
      *(undefined4 *)(param_1 + 0x20) = 0;
      UNLOCK();
      _thread_wakeup_prim(param_1 + 0x48,0,0);
      goto LAB_001593c6;
    }
  }
  LOCK();
  *(undefined4 *)(param_1 + 0x20) = 0;
  UNLOCK();
LAB_001593c6:
  _splx(uVar3);
  __c_thread_handoff_hits = __c_thread_handoff_hits + 1;
  return 1;
}

