/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00168a18 */

kern_return_t _thread_wire(host_priv_t host_priv,thread_act_t thread,boolean_t wired)

{
  int *piVar1;
  int iVar2;
  kern_return_t kVar3;
  undefined4 uVar4;
  
  if (((host_priv == 0) || (thread == 0)) || (_active_threads != thread)) {
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
    if (wired == 0) {
      *(undefined4 *)(thread + 0x78) = 0;
      *(undefined4 *)(thread + 0x30) = 0;
    }
    else {
      *(undefined4 *)(thread + 0x78) = 1;
      if (_active_threads != thread) {
                    /* WARNING: Subroutine does not return */
        _panic(s_stack_privilege_001dfbcc);
      }
      if (*(int *)(thread + 0x30) == 0) {
        *(undefined4 *)(thread + 0x30) = _active_stacks;
      }
    }
    LOCK();
    *(undefined4 *)(thread + 0x20) = 0;
    UNLOCK();
    _splx(uVar4);
    kVar3 = 0;
  }
  return kVar3;
}

