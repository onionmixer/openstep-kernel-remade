/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0014c198 */

int _ipc_object_copyout_compat(uint param_1,int *param_2,int param_3,undefined4 *param_4)

{
  int *piVar1;
  int iVar2;
  uint local_10;
  uint *local_c;
  undefined4 local_8;
  
  piVar1 = (int *)(param_1 + 8);
  do {
    do {
    } while (*piVar1 != 0);
    LOCK();
    iVar2 = *piVar1;
    *piVar1 = 1;
    UNLOCK();
  } while (iVar2 == 1);
LAB_0014c1c0:
  do {
    if (*(int *)(param_1 + 0xc) == 0) {
      LOCK();
      *(undefined4 *)(param_1 + 8) = 0;
      UNLOCK();
      return 0x10;
    }
    if ((param_3 != 0x12) &&
       (iVar2 = _ipc_right_reverse(param_1,param_2,&local_8,&local_c), iVar2 != 0)) {
LAB_0014c2e3:
      iVar2 = _ipc_right_copyout(param_1,local_8,local_c,param_3,1,param_2);
      LOCK();
      *(undefined4 *)(param_1 + 8) = 0;
      UNLOCK();
      if (iVar2 != 0) {
        return iVar2;
      }
      *param_4 = local_8;
      return 0;
    }
    iVar2 = _ipc_entry_get(param_1,&local_8,&local_c);
    if (iVar2 == 0) {
      do {
        do {
        } while (*param_2 != 0);
        LOCK();
        iVar2 = *param_2;
        *param_2 = 1;
        UNLOCK();
      } while (iVar2 == 1);
      if (-1 < param_2[2]) {
        LOCK();
        *param_2 = 0;
        UNLOCK();
        _ipc_entry_dealloc(param_1,local_8,local_c);
        LOCK();
        *(undefined4 *)(param_1 + 8) = 0;
        UNLOCK();
        return 0x14;
      }
      iVar2 = _ipc_port_dnrequest(param_2,local_8,param_1 | 1,&local_10);
      if (iVar2 == 0) {
        _ipc_space_reference(param_1);
        local_c[1] = (uint)param_2;
        local_c[2] = local_10;
        *local_c = *local_c | 0x400000;
        goto LAB_0014c2e3;
      }
      _ipc_entry_dealloc(param_1,local_8,local_c);
      piVar1 = (int *)(param_1 + 8);
      LOCK();
      *(undefined4 *)(param_1 + 8) = 0;
      UNLOCK();
      iVar2 = _ipc_port_dngrow(param_2);
      if (iVar2 != 0) {
        return iVar2;
      }
      do {
        do {
        } while (*piVar1 != 0);
        LOCK();
        iVar2 = *piVar1;
        *piVar1 = 1;
        UNLOCK();
      } while (iVar2 == 1);
      goto LAB_0014c1c0;
    }
    iVar2 = _ipc_entry_grow_table(param_1);
    if (iVar2 != 0) {
      return iVar2;
    }
  } while( true );
}

