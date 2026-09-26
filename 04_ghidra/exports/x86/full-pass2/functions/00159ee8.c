/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00159ee8 */

kern_return_t
_thread_get_special_port(thread_act_t thr_act,int which_port,mach_port_t *special_port)

{
  int *piVar1;
  int iVar2;
  kern_return_t kVar3;
  mach_port_t mVar4;
  undefined4 *puVar5;
  
  if (thr_act == 0) goto LAB_00159efa;
  if (which_port == 2) {
    puVar5 = (undefined4 *)(thr_act + 0xb8);
LAB_00159f32:
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
      kVar3 = 5;
    }
    else {
      mVar4 = _ipc_port_copy_send(*puVar5);
      LOCK();
      *(undefined4 *)(thr_act + 0xa8) = 0;
      UNLOCK();
      *special_port = mVar4;
      kVar3 = 0;
    }
  }
  else {
    if (which_port < 3) {
      if (which_port == 1) {
        puVar5 = (undefined4 *)(thr_act + 0xb0);
        goto LAB_00159f32;
      }
    }
    else if (which_port == 3) {
      puVar5 = (undefined4 *)(thr_act + 0xb4);
      goto LAB_00159f32;
    }
LAB_00159efa:
    kVar3 = 4;
  }
  return kVar3;
}

