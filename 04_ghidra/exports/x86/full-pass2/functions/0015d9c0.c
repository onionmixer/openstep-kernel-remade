/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015d9c0 */

undefined4 _netipc_ignore(undefined4 param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  undefined4 local_c;
  int *local_8;
  
  local_c = 5;
  if (param_2 == 0) {
    local_c = 4;
  }
  else {
    local_8 = &_listeners;
    piVar6 = &DAT_001f6404;
    do {
      uVar3 = _splnet();
      do {
        do {
        } while (*local_8 != 0);
        LOCK();
        iVar1 = *local_8;
        *local_8 = 1;
        UNLOCK();
      } while (iVar1 == 1);
      piVar2 = (int *)*piVar6;
      piVar4 = (int *)*piVar6;
      while (piVar5 = piVar2, piVar5 != (int *)0x0) {
        if (piVar5[4] == param_2) {
          local_c = 0;
          if ((int *)*piVar6 == piVar5) {
            *piVar6 = *piVar5;
            _zfree(_listener_zone,piVar5);
            piVar4 = (int *)*piVar6;
            if (piVar4 == (int *)0x0) break;
          }
          else {
            *piVar4 = *piVar5;
            _zfree(_listener_zone,piVar5);
          }
          _ipc_object_release(param_2);
          piVar5 = piVar4;
        }
        piVar4 = piVar5;
        piVar2 = (int *)*piVar5;
      }
      LOCK();
      *local_8 = 0;
      UNLOCK();
      _splx(uVar3);
      piVar6 = piVar6 + 2;
      local_8 = local_8 + 2;
    } while (local_8 < &_mach_net_kmsg_zone);
  }
  return local_c;
}

