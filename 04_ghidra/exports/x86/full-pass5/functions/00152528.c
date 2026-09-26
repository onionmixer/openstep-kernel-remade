/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00152528 */

kern_return_t
_mach_port_kernel_object(ipc_space_t task,mach_port_name_t name,uint *object_type,uint *object_addr)

{
  int iVar1;
  int *piVar2;
  kern_return_t kVar3;
  int local_8;
  
  kVar3 = _ipc_right_lookup_write(task,name,&local_8);
  if (kVar3 == 0) {
    if ((*(byte *)(local_8 + 2) & 3) == 0) {
      LOCK();
      *(undefined4 *)(task + 8) = 0;
      UNLOCK();
    }
    else {
      piVar2 = *(int **)(local_8 + 4);
      do {
        do {
        } while (*piVar2 != 0);
        LOCK();
        iVar1 = *piVar2;
        *piVar2 = 1;
        UNLOCK();
      } while (iVar1 == 1);
      LOCK();
      *(undefined4 *)(task + 8) = 0;
      UNLOCK();
      if (piVar2[2] < 0) {
        *object_type = piVar2[2] & 0xffff;
        *object_addr = piVar2[5];
        LOCK();
        *piVar2 = 0;
        UNLOCK();
        return 0;
      }
      LOCK();
      *piVar2 = 0;
      UNLOCK();
    }
    kVar3 = 0x11;
  }
  return kVar3;
}

