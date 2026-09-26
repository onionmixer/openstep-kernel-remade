
undefined4
_ipc_mqueue_receive(int *param_1,uint param_2,uint param_3,int param_4,int param_5,int param_6,
                   uint *param_7,undefined4 *param_8)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  
  iVar5 = _active_threads;
  if (param_5 != 0) goto loc_403F7F2;
  do {
    piVar6 = (int *)*param_1;
    if (piVar6 != (int *)0x0) {
      if (param_3 < (uint)piVar6[6]) {
        *param_7 = piVar6[6];
        return 0x10004004;
      }
      piVar1 = (int *)*piVar6;
      if (piVar6 == piVar1) {
        *param_1 = 0;
      }
      else {
        piVar2 = (int *)piVar6[1];
        *param_1 = (int)piVar1;
        piVar1[1] = (int)piVar2;
        *piVar2 = (int)piVar1;
      }
      iVar5 = piVar6[7];
      uVar4 = *(undefined4 *)(iVar5 + 0x30);
      *(int *)(iVar5 + 0x30) = *(int *)(iVar5 + 0x30) + 1;
loc_403F880:
      if (piVar6[3] != 0) {
        _ipc_marequest_destroy(piVar6[3]);
        piVar6[3] = 0;
      }
      if (*(int *)(iVar5 + 4) < 0) {
        iVar3 = *(int *)(iVar5 + 0x34);
        *(int *)(iVar5 + 0x34) = iVar3 + -1;
        iVar7 = *(int *)(iVar5 + 0x44);
        if ((iVar7 != 0) && (iVar3 - 1U < *(uint *)(iVar5 + 0x38))) {
          _ipc_thread_rmqueue((int *)(iVar5 + 0x44),iVar7);
          *(undefined4 *)(iVar7 + 0x94) = 0;
          _thread_go(iVar7);
        }
      }
      *param_7 = (uint)piVar6;
      *param_8 = uVar4;
      return 0;
    }
    if ((param_2 & 0x100) == 0) {
      _thread_will_wait(iVar5);
    }
    else {
      if (param_4 == 0) {
        return 0x10004003;
      }
      _thread_will_wait_with_timeout(iVar5,param_4);
    }
    iVar7 = param_1[1];
    if (iVar7 == 0) {
      param_1[1] = iVar5;
    }
    else {
      iVar3 = *(int *)(iVar7 + 0x90);
      *(int *)(iVar5 + 0x8c) = iVar7;
      *(int *)(iVar5 + 0x90) = iVar3;
      *(int *)(iVar7 + 0x90) = iVar5;
      *(int *)(iVar3 + 0x8c) = iVar5;
    }
    *(undefined4 *)(iVar5 + 0x94) = 0x10004001;
    *(uint *)(iVar5 + 0x98) = param_3;
    iVar7 = param_6;
    if (param_6 == 0) {
      iVar7 = 0;
    }
    _thread_block_with_continuation(iVar7);
loc_403F7F2:
    iVar7 = *(int *)(iVar5 + 0x94);
    if (iVar7 == 0) {
      piVar6 = *(int **)(iVar5 + 0x98);
      uVar4 = *(undefined4 *)(iVar5 + 0x9c);
      iVar5 = piVar6[7];
      goto loc_403F880;
    }
    if (iVar7 == 0x10004004) {
      *param_7 = *(uint *)(iVar5 + 0x98);
loc_403F832:
      return *(undefined4 *)(iVar5 + 0x94);
    }
    if (0x10004004 < iVar7) {
      if ((iVar7 == 0x10004006) || (iVar7 == 0x10004009)) goto loc_403F832;
loc_403F86E:
                    /* WARNING: Subroutine does not return */
      _panic(aIpcMqueueRecei);
    }
    if (iVar7 != 0x10004001) goto loc_403F86E;
    _ipc_thread_rmqueue(param_1 + 1,iVar5);
    iVar7 = *(int *)(iVar5 + 0x40);
    if (iVar7 == 1) {
      param_4 = 0;
    }
    else if ((0 < iVar7) && (iVar7 < 4)) {
      return 0x10004005;
    }
  } while( true );
}

