/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015a104 */

kern_return_t
_mach_ports_lookup(task_t target_task,mach_port_array_t *init_port_set,
                  mach_msg_type_number_t *init_port_setCnt)

{
  int *piVar1;
  kern_return_t kVar2;
  mach_port_array_t pmVar3;
  mach_port_t mVar4;
  int iVar5;
  
  if (target_task == 0) {
    kVar2 = 4;
  }
  else {
    pmVar3 = (mach_port_array_t)_kalloc(0x10);
    if (pmVar3 == (mach_port_array_t)0x0) {
      kVar2 = 6;
    }
    else {
      piVar1 = (int *)(target_task + 100);
      do {
        do {
        } while (*piVar1 != 0);
        LOCK();
        iVar5 = *piVar1;
        *piVar1 = 1;
        UNLOCK();
      } while (iVar5 == 1);
      if (*(int *)(target_task + 0x68) == 0) {
        LOCK();
        *(undefined4 *)(target_task + 100) = 0;
        UNLOCK();
        _kfree(pmVar3,0x10);
        kVar2 = 4;
      }
      else {
        iVar5 = 0;
        do {
          mVar4 = _ipc_port_copy_send(*(undefined4 *)(target_task + 0x78 + iVar5 * 4));
          pmVar3[iVar5] = mVar4;
          iVar5 = iVar5 + 1;
        } while (iVar5 < 4);
        LOCK();
        *(undefined4 *)(target_task + 100) = 0;
        UNLOCK();
        *init_port_set = pmVar3;
        *init_port_setCnt = 4;
        kVar2 = 0;
      }
    }
  }
  return kVar2;
}

