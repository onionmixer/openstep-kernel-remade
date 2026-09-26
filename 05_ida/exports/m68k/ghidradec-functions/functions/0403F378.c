
undefined4 _ipc_mqueue_send(int *param_1,uint param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int *piVar7;
  
  piVar1 = (int *)param_1[7];
  if (piVar1[2] == _ipc_space_kernel) {
    iVar6 = _ipc_kobject_server(param_1);
    if (iVar6 != 0) {
      _ipc_mqueue_send(iVar6,0x10000,0,0);
    }
    return 0;
  }
  do {
    iVar6 = _active_threads;
    if (-1 < piVar1[1]) {
      iVar6 = *piVar1;
      *piVar1 = iVar6 + -1;
      if (iVar6 == 1) {
        _zfree((&_ipc_object_zones)[*(word *)(piVar1 + 1) & 0x7fff],piVar1);
      }
      param_1[7] = 0;
loc_403F3FC:
      _ipc_kmsg_destroy(param_1);
      return 0;
    }
    if ((((uint)piVar1[0xd] < (uint)piVar1[0xe]) || ((param_2 & 0x10000) != 0)) ||
       (*(char *)((int)param_1 + 0x17) == '\x12')) {
      if ((*(byte *)(param_1 + 5) & 0x40) == 0) {
        piVar1[0xd] = piVar1[0xd] + 1;
        if (piVar1[0xb] == 0) {
          piVar7 = piVar1 + 0xf;
        }
        else {
          piVar7 = (int *)(piVar1[0xb] + 0xc);
        }
        piVar5 = piVar7 + 1;
        while( true ) {
          iVar6 = *piVar5;
          if (iVar6 == 0) {
            iVar6 = *piVar7;
            if (iVar6 != 0) {
              puVar2 = *(undefined4 **)(iVar6 + 4);
              *param_1 = iVar6;
              param_1[1] = (int)puVar2;
              *(int **)(iVar6 + 4) = param_1;
              *puVar2 = param_1;
              return 0;
            }
            *piVar7 = (int)param_1;
            *param_1 = (int)param_1;
            param_1[1] = (int)param_1;
            return 0;
          }
          iVar3 = *(int *)(iVar6 + 0x8c);
          if (iVar6 == iVar3) {
            *piVar5 = 0;
          }
          else {
            iVar4 = *(int *)(iVar6 + 0x90);
            *piVar5 = iVar3;
            *(int *)(iVar3 + 0x90) = iVar4;
            *(int *)(iVar4 + 0x8c) = iVar3;
            *(int *)(iVar6 + 0x8c) = iVar6;
            *(int *)(iVar6 + 0x90) = iVar6;
          }
          if ((uint)param_1[6] <= *(uint *)(iVar6 + 0x98)) break;
          *(undefined4 *)(iVar6 + 0x94) = 0x10004004;
          *(int *)(iVar6 + 0x98) = param_1[6];
          _thread_go(iVar6);
        }
        *(undefined4 *)(iVar6 + 0x94) = 0;
        *(int **)(iVar6 + 0x98) = param_1;
        *(int *)(iVar6 + 0x9c) = piVar1[0xc];
        piVar1[0xc] = piVar1[0xc] + 1;
        if ((param_2 & 0x20000) == 0) {
          _thread_go(iVar6);
          return 0;
        }
        _thread_go_and_switch(param_4,iVar6);
        return 0;
      }
      goto loc_403F3FC;
    }
    if ((param_2 & 0x10) == 0) {
      _thread_will_wait(_active_threads);
    }
    else {
      if (param_3 == 0) {
        return 0x10000004;
      }
      _thread_will_wait_with_timeout(_active_threads,param_3);
    }
    _ipc_thread_enqueue(piVar1 + 0x11,iVar6);
    *(undefined4 *)(iVar6 + 0x94) = 0x10000001;
    _thread_block_with_continuation(0);
    if (*(int *)(iVar6 + 0x94) != 0) {
      _ipc_thread_rmqueue(piVar1 + 0x11,iVar6);
      iVar6 = *(int *)(iVar6 + 0x40);
      if (iVar6 == 1) {
        param_3 = 0;
      }
      else if ((0 < iVar6) && (iVar6 < 4)) {
        return 0x10000007;
      }
    }
  } while( true );
}
