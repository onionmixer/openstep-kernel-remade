/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00159d2c */

kern_return_t _task_get_special_port(task_t task,int which_port,mach_port_t *special_port)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  mach_port_t mVar4;
  undefined4 *puVar5;
  
  if (task == 0) {
    return 4;
  }
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
    mVar4 = _ipc_port_copy_send(*(undefined4 *)(iVar3 + 0x44));
    LOCK();
    *(undefined4 *)(iVar3 + 8) = 0;
    UNLOCK();
  }
  else {
    if (which_port < 3) {
      if (which_port != 1) {
        return 4;
      }
      puVar5 = (undefined4 *)(task + 0x6c);
    }
    else if (which_port == 3) {
      puVar5 = (undefined4 *)(task + 0x70);
    }
    else {
      if (which_port != 4) {
        return 4;
      }
      puVar5 = (undefined4 *)(task + 0x74);
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
    mVar4 = _ipc_port_copy_send(*puVar5);
    LOCK();
    *(undefined4 *)(task + 100) = 0;
    UNLOCK();
  }
  *special_port = mVar4;
  return 0;
}

