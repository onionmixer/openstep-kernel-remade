/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00148c20 */

undefined4 _ipc_kmsg_copyout_object(int param_1,int *param_2,int param_3,undefined4 *param_4)

{
  int *piVar1;
  int iVar2;
  int *local_8;
  
  if ((param_2 == (int *)0x0) || (param_2 == (int *)0xffffffff)) {
    *param_4 = param_2;
  }
  else {
    if (param_3 == 0x11) {
      piVar1 = (int *)(param_1 + 8);
      do {
        do {
        } while (*piVar1 != 0);
        LOCK();
        iVar2 = *piVar1;
        *piVar1 = 1;
        UNLOCK();
      } while (iVar2 == 1);
      if (*(int *)(param_1 + 0xc) != 0) {
        do {
          do {
          } while (*param_2 != 0);
          LOCK();
          iVar2 = *param_2;
          *param_2 = 1;
          UNLOCK();
        } while (iVar2 == 1);
        if ((param_2[2] < 0) &&
           (iVar2 = _ipc_hash_local_lookup(param_1,param_2,param_4,&local_8), iVar2 != 0)) {
          param_2[7] = param_2[7] + -1;
          param_2[1] = param_2[1] + -1;
          LOCK();
          *param_2 = 0;
          UNLOCK();
          if ((short)(*local_8 + 1) != -1) {
            *local_8 = *local_8 + 1;
          }
          LOCK();
          *(undefined4 *)(param_1 + 8) = 0;
          UNLOCK();
          return 0;
        }
        LOCK();
        *param_2 = 0;
        UNLOCK();
      }
      LOCK();
      *(undefined4 *)(param_1 + 8) = 0;
      UNLOCK();
    }
    iVar2 = _ipc_object_copyout(param_1,param_2,param_3,1,param_4);
    if (iVar2 != 0) {
      _ipc_object_destroy(param_2,param_3);
      if (iVar2 != 0x14) {
        *param_4 = 0;
        if (iVar2 != 6) {
          return 0x2000;
        }
        return 0x800;
      }
      *param_4 = 0xffffffff;
    }
  }
  return 0;
}

