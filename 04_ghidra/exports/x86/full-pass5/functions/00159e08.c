/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00159e08 */

kern_return_t _task_set_special_port(task_t task,int which_port,mach_port_t special_port)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  kern_return_t kVar4;
  mach_port_t *pmVar5;
  mach_port_t mVar6;
  
  if (task == 0) {
LAB_00159e1a:
    kVar4 = 4;
  }
  else {
    if (which_port == 2) {
      iVar3 = *(int *)(task + 0x88);
      piVar1 = (int *)(iVar3 + 8);
      do {
        do {
        } while (*piVar1 != 0);
        LOCK();
        iVar2 = *piVar1;
        *piVar1 = 1;
        UNLOCK();
      } while (iVar2 == 1);
      if (*(int *)(iVar3 + 0xc) == 0) {
        LOCK();
        *(undefined4 *)(iVar3 + 8) = 0;
        UNLOCK();
        return 5;
      }
      mVar6 = *(mach_port_t *)(iVar3 + 0x44);
      *(mach_port_t *)(iVar3 + 0x44) = special_port;
      LOCK();
      *(undefined4 *)(iVar3 + 8) = 0;
      UNLOCK();
    }
    else {
      if (which_port < 3) {
        if (which_port != 1) goto LAB_00159e1a;
        pmVar5 = (mach_port_t *)(task + 0x6c);
      }
      else if (which_port == 3) {
        pmVar5 = (mach_port_t *)(task + 0x70);
      }
      else {
        if (which_port != 4) goto LAB_00159e1a;
        pmVar5 = (mach_port_t *)(task + 0x74);
      }
      piVar1 = (int *)(task + 100);
      do {
        do {
        } while (*piVar1 != 0);
        LOCK();
        iVar3 = *piVar1;
        *piVar1 = 1;
        UNLOCK();
      } while (iVar3 == 1);
      if (*(int *)(task + 0x68) == 0) {
        LOCK();
        *(undefined4 *)(task + 100) = 0;
        UNLOCK();
        return 5;
      }
      mVar6 = *pmVar5;
      *pmVar5 = special_port;
      LOCK();
      *(undefined4 *)(task + 100) = 0;
      UNLOCK();
    }
    if ((mVar6 != 0) && (mVar6 != 0xffffffff)) {
      _ipc_port_release_send(mVar6);
    }
    kVar4 = 0;
  }
  return kVar4;
}

