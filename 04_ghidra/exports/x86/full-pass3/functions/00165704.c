/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00165704 */

kern_return_t _thread_depress_abort(thread_act_t thread)

{
  int *piVar1;
  int iVar2;
  kern_return_t kVar3;
  undefined4 uVar4;
  
  if (thread == 0) {
    kVar3 = 4;
  }
  else {
    uVar4 = _splsched();
    piVar1 = (int *)(thread + 0x20);
    do {
      do {
      } while (*piVar1 != 0);
      LOCK();
      iVar2 = *piVar1;
      *piVar1 = 1;
      UNLOCK();
    } while (iVar2 == 1);
    if (-1 < *(int *)(thread + 100)) {
      if (*(int *)(thread + 0x174) != 0) {
        _reset_timeout(thread + 0x148);
      }
      *(undefined4 *)(thread + 0x50) = *(undefined4 *)(thread + 100);
      *(undefined4 *)(thread + 100) = 0xffffffff;
      _compute_priority(thread,0);
    }
    LOCK();
    *(undefined4 *)(thread + 0x20) = 0;
    UNLOCK();
    _splx(uVar4);
    kVar3 = 0;
  }
  return kVar3;
}

