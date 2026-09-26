/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00159f88 */

kern_return_t _thread_set_special_port(thread_act_t thr_act,int which_port,mach_port_t special_port)

{
  int *piVar1;
  int iVar2;
  mach_port_t mVar3;
  kern_return_t kVar4;
  mach_port_t *pmVar5;
  
  if (thr_act == 0) goto LAB_00159f97;
  if (which_port == 2) {
    pmVar5 = (mach_port_t *)(thr_act + 0xb8);
LAB_00159fd2:
    piVar1 = (int *)(thr_act + 0xa8);
    do {
      do {
      } while (*piVar1 != 0);
      LOCK();
      iVar2 = *piVar1;
      *piVar1 = 1;
      UNLOCK();
    } while (iVar2 == 1);
    if (*(int *)(thr_act + 0xac) == 0) {
      LOCK();
      *(undefined4 *)(thr_act + 0xa8) = 0;
      UNLOCK();
      kVar4 = 5;
    }
    else {
      mVar3 = *pmVar5;
      *pmVar5 = special_port;
      LOCK();
      *(undefined4 *)(thr_act + 0xa8) = 0;
      UNLOCK();
      if ((mVar3 != 0) && (mVar3 != 0xffffffff)) {
        _ipc_port_release_send(mVar3);
      }
      kVar4 = 0;
    }
  }
  else {
    if (which_port < 3) {
      if (which_port == 1) {
        pmVar5 = (mach_port_t *)(thr_act + 0xb0);
        goto LAB_00159fd2;
      }
    }
    else if (which_port == 3) {
      pmVar5 = (mach_port_t *)(thr_act + 0xb4);
      goto LAB_00159fd2;
    }
LAB_00159f97:
    kVar4 = 4;
  }
  return kVar4;
}

