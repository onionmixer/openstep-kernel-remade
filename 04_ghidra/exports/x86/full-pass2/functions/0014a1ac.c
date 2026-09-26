/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0014a1ac */

undefined4 _ipc_marequest_create(uint param_1,undefined4 *param_2,int param_3,int *param_4)

{
  int *piVar1;
  uint *puVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint *local_c;
  uint local_8;
  
  puVar2 = (uint *)_zalloc(_ipc_marequest_zone);
  if (puVar2 == (uint *)0x0) {
    uVar3 = 0x1000000e;
  }
  else {
    piVar1 = (int *)(param_1 + 8);
    do {
      do {
      } while (*piVar1 != 0);
      LOCK();
      iVar4 = *piVar1;
      *piVar1 = 1;
      UNLOCK();
    } while (iVar4 == 1);
    if (*(int *)(param_1 + 0xc) == 0) {
      LOCK();
      *(undefined4 *)(param_1 + 8) = 0;
      UNLOCK();
      _zfree(_ipc_marequest_zone,puVar2);
      uVar3 = 0x1000000b;
    }
    else {
      iVar4 = _ipc_right_reverse(param_1,param_2,&local_8,&local_c);
      if (iVar4 == 0) {
        if (param_3 == 0) {
          uVar6 = 0;
        }
        else {
          uVar6 = _ipc_port_lookup_notify(param_1,param_3);
          if (uVar6 == 0) {
            LOCK();
            *(undefined4 *)(param_1 + 8) = 0;
            UNLOCK();
            _zfree(_ipc_marequest_zone,puVar2);
            return 0x1000000b;
          }
        }
        _ipc_space_reference(param_1);
        *puVar2 = param_1;
        puVar2[1] = 0;
        puVar2[2] = uVar6;
      }
      else {
        LOCK();
        *param_2 = 0;
        UNLOCK();
        uVar6 = *local_c;
        if ((uVar6 & 0x200000) != 0) {
          LOCK();
          *(undefined4 *)(param_1 + 8) = 0;
          UNLOCK();
          _zfree(_ipc_marequest_zone,puVar2);
          return 0x10000006;
        }
        if (param_3 == 0) {
          uVar5 = 0;
        }
        else {
          uVar5 = _ipc_port_lookup_notify(param_1,param_3);
          if (uVar5 == 0) {
            LOCK();
            *(undefined4 *)(param_1 + 8) = 0;
            UNLOCK();
            _zfree(_ipc_marequest_zone,puVar2);
            return 0x1000000b;
          }
        }
        *local_c = uVar6 | 0x200000;
        _ipc_space_reference(param_1);
        *puVar2 = param_1;
        puVar2[1] = local_8;
        puVar2[2] = uVar5;
        piVar1 = (int *)(_ipc_marequest_table +
                        ((param_1 >> 4) + (local_8 >> 8) + (local_8 & 0xff) & _ipc_marequest_mask) *
                        8);
        do {
          do {
          } while (*piVar1 != 0);
          LOCK();
          iVar4 = *piVar1;
          *piVar1 = 1;
          UNLOCK();
        } while (iVar4 == 1);
        puVar2[3] = piVar1[1];
        piVar1[1] = (int)puVar2;
        LOCK();
        *piVar1 = 0;
        UNLOCK();
      }
      LOCK();
      *(undefined4 *)(param_1 + 8) = 0;
      UNLOCK();
      *param_4 = (int)puVar2;
      uVar3 = 0;
    }
  }
  return uVar3;
}

