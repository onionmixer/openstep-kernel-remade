/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0014a764 */

undefined4 _ipc_mqueue_send(int *param_1,uint param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int *piVar8;
  
  piVar3 = (int *)param_1[7];
  do {
    do {
    } while (*piVar3 != 0);
    LOCK();
    iVar6 = *piVar3;
    *piVar3 = 1;
    UNLOCK();
  } while (iVar6 == 1);
  if (piVar3[3] == _ipc_space_kernel) {
    LOCK();
    *piVar3 = 0;
    UNLOCK();
    iVar6 = _ipc_kobject_server(param_1);
    if (iVar6 != 0) {
      _ipc_mqueue_send(iVar6,0x10000,0,0);
    }
    uVar7 = 0;
  }
  else {
    do {
      while( true ) {
        do {
          iVar6 = _active_threads;
          if (-1 < piVar3[2]) {
            iVar6 = piVar3[1];
            piVar3[1] = iVar6 + -1;
            LOCK();
            *piVar3 = 0;
            UNLOCK();
            if (iVar6 == 1) {
              _zfree((&_ipc_object_zones)[*(ushort *)((int)piVar3 + 10) & 0x7fff],piVar3);
            }
            param_1[7] = 0;
            _ipc_kmsg_destroy(param_1);
            return 0;
          }
          if ((((uint)piVar3[0xe] < (uint)piVar3[0xf]) || ((param_2 & 0x10000) != 0)) ||
             ((char)param_1[5] == '\x12')) {
            if ((*(byte *)((int)param_1 + 0x17) & 0x40) != 0) {
              LOCK();
              *piVar3 = 0;
              UNLOCK();
              _ipc_kmsg_destroy(param_1);
              return 0;
            }
            piVar3[0xe] = piVar3[0xe] + 1;
            if (piVar3[0xc] == 0) {
              piVar8 = piVar3 + 0x10;
            }
            else {
              piVar8 = (int *)(piVar3[0xc] + 0x10);
            }
            do {
              do {
              } while (*piVar8 != 0);
              LOCK();
              iVar6 = *piVar8;
              *piVar8 = 1;
              UNLOCK();
            } while (iVar6 == 1);
            piVar1 = piVar8 + 2;
            LOCK();
            *piVar3 = 0;
            UNLOCK();
            while( true ) {
              iVar6 = *piVar1;
              if (iVar6 == 0) {
                iVar6 = piVar8[1];
                if (iVar6 == 0) {
                  piVar8[1] = (int)param_1;
                  *param_1 = (int)param_1;
                  param_1[1] = (int)param_1;
                }
                else {
                  puVar4 = *(undefined4 **)(iVar6 + 4);
                  *param_1 = iVar6;
                  param_1[1] = (int)puVar4;
                  *(int **)(iVar6 + 4) = param_1;
                  *puVar4 = param_1;
                }
                LOCK();
                *piVar8 = 0;
                UNLOCK();
                return 0;
              }
              iVar2 = *(int *)(iVar6 + 0x90);
              if (iVar2 == iVar6) {
                *piVar1 = 0;
              }
              else {
                iVar5 = *(int *)(iVar6 + 0x94);
                *piVar1 = iVar2;
                *(int *)(iVar2 + 0x94) = iVar5;
                *(int *)(iVar5 + 0x90) = iVar2;
                *(int *)(iVar6 + 0x90) = iVar6;
                *(int *)(iVar6 + 0x94) = iVar6;
              }
              if ((uint)param_1[6] <= *(uint *)(iVar6 + 0x9c)) break;
              *(undefined4 *)(iVar6 + 0x98) = 0x10004004;
              *(int *)(iVar6 + 0x9c) = param_1[6];
              _thread_go(iVar6);
            }
            *(undefined4 *)(iVar6 + 0x98) = 0;
            *(int **)(iVar6 + 0x9c) = param_1;
            *(int *)(iVar6 + 0xa0) = piVar3[0xd];
            piVar3[0xd] = piVar3[0xd] + 1;
            LOCK();
            *piVar8 = 0;
            UNLOCK();
            if ((param_2 & 0x20000) == 0) {
              _thread_go(iVar6);
              return 0;
            }
            _thread_go_and_switch(param_4,iVar6);
            return 0;
          }
          if ((param_2 & 0x10) == 0) {
            _thread_will_wait(_active_threads);
          }
          else {
            if (param_3 == 0) {
              LOCK();
              *piVar3 = 0;
              UNLOCK();
              return 0x10000004;
            }
            _thread_will_wait_with_timeout(_active_threads,param_3);
          }
          _ipc_thread_enqueue(piVar3 + 0x13,iVar6);
          *(undefined4 *)(iVar6 + 0x98) = 0x10000001;
          LOCK();
          *piVar3 = 0;
          UNLOCK();
          _thread_block_with_continuation(0);
          do {
            do {
            } while (*piVar3 != 0);
            LOCK();
            iVar2 = *piVar3;
            *piVar3 = 1;
            UNLOCK();
          } while (iVar2 == 1);
        } while (*(int *)(iVar6 + 0x98) == 0);
        _ipc_thread_rmqueue(piVar3 + 0x13,iVar6);
        iVar6 = *(int *)(iVar6 + 0x44);
        if (iVar6 != 1) break;
        param_3 = 0;
      }
    } while ((iVar6 < 1) || (3 < iVar6));
    LOCK();
    *piVar3 = 0;
    UNLOCK();
    uVar7 = 0x10000007;
  }
  return uVar7;
}

