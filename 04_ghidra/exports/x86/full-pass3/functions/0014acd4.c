/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0014acd4 */

undefined4
_ipc_mqueue_receive(int *param_1,uint param_2,uint param_3,int param_4,int param_5,int param_6,
                   uint *param_7,int *param_8)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  uint *local_10;
  int local_8;
  
  iVar2 = _active_threads;
  puVar1 = (uint *)(param_1 + 1);
  if (param_5 != 0) goto LAB_0014adec;
  do {
    local_10 = (uint *)*puVar1;
    if (local_10 != (uint *)0x0) {
      if (param_3 < local_10[6]) {
        *param_7 = local_10[6];
        LOCK();
        *param_1 = 0;
        UNLOCK();
        return 0x10004004;
      }
      uVar3 = *local_10;
      if ((uint *)uVar3 == local_10) {
        *puVar1 = 0;
      }
      else {
        puVar4 = (uint *)local_10[1];
        *puVar1 = uVar3;
        *(uint **)(uVar3 + 4) = puVar4;
        *puVar4 = uVar3;
      }
      piVar6 = (int *)local_10[7];
      local_8 = piVar6[0xd];
      piVar6[0xd] = piVar6[0xd] + 1;
LAB_0014aeb8:
      LOCK();
      *param_1 = 0;
      UNLOCK();
      if (local_10[3] != 0) {
        _ipc_marequest_destroy(local_10[3]);
        local_10[3] = 0;
      }
      do {
        do {
        } while (*piVar6 != 0);
        LOCK();
        iVar2 = *piVar6;
        *piVar6 = 1;
        UNLOCK();
      } while (iVar2 == 1);
      if (piVar6[2] < 0) {
        iVar2 = piVar6[0xe];
        piVar6[0xe] = iVar2 + -1;
        iVar7 = piVar6[0x13];
        if ((iVar7 != 0) && (iVar2 - 1U < (uint)piVar6[0xf])) {
          _ipc_thread_rmqueue(piVar6 + 0x13,iVar7);
          *(undefined4 *)(iVar7 + 0x98) = 0;
          _thread_go(iVar7);
        }
      }
      LOCK();
      *piVar6 = 0;
      UNLOCK();
      *param_7 = (uint)local_10;
      *param_8 = local_8;
      return 0;
    }
    if ((param_2 & 0x100) == 0) {
      _thread_will_wait(iVar2);
    }
    else {
      if (param_4 == 0) {
        LOCK();
        *param_1 = 0;
        UNLOCK();
        return 0x10004003;
      }
      _thread_will_wait_with_timeout(iVar2,param_4);
    }
    iVar7 = param_1[2];
    if (iVar7 == 0) {
      param_1[2] = iVar2;
    }
    else {
      iVar5 = *(int *)(iVar7 + 0x94);
      *(int *)(iVar2 + 0x90) = iVar7;
      *(int *)(iVar2 + 0x94) = iVar5;
      *(int *)(iVar7 + 0x94) = iVar2;
      *(int *)(iVar5 + 0x90) = iVar2;
    }
    *(undefined4 *)(iVar2 + 0x98) = 0x10004001;
    *(uint *)(iVar2 + 0x9c) = param_3;
    LOCK();
    *param_1 = 0;
    UNLOCK();
    iVar7 = param_6;
    if (param_6 == 0) {
      iVar7 = 0;
    }
    _thread_block_with_continuation(iVar7);
LAB_0014adec:
    do {
      do {
      } while (*param_1 != 0);
      LOCK();
      iVar7 = *param_1;
      *param_1 = 1;
      UNLOCK();
    } while (iVar7 == 1);
    iVar7 = *(int *)(iVar2 + 0x98);
    if (iVar7 == 0) {
      local_10 = *(uint **)(iVar2 + 0x9c);
      local_8 = *(int *)(iVar2 + 0xa0);
      piVar6 = (int *)local_10[7];
      goto LAB_0014aeb8;
    }
    if (iVar7 == 0x10004004) {
      *param_7 = *(uint *)(iVar2 + 0x9c);
LAB_0014ae53:
      LOCK();
      *param_1 = 0;
      UNLOCK();
      return *(undefined4 *)(iVar2 + 0x98);
    }
    if (0x10004004 < iVar7) {
      if ((iVar7 == 0x10004006) || (iVar7 == 0x10004009)) goto LAB_0014ae53;
LAB_0014aea4:
                    /* WARNING: Subroutine does not return */
      _panic(s_ipc_mqueue_receive__strange_ith__001de72e);
    }
    if (iVar7 != 0x10004001) goto LAB_0014aea4;
    _ipc_thread_rmqueue(param_1 + 2,iVar2);
    iVar7 = *(int *)(iVar2 + 0x44);
    if (iVar7 == 1) {
      param_4 = 0;
    }
    else if ((0 < iVar7) && (iVar7 < 4)) {
      LOCK();
      *param_1 = 0;
      UNLOCK();
      return 0x10004005;
    }
  } while( true );
}

