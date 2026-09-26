/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0014aa34 */

undefined4 _ipc_mqueue_send_interrupt(int *param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int *piVar7;
  int *local_8;
  
  piVar2 = (int *)param_1[7];
  LOCK();
  iVar1 = *piVar2;
  *piVar2 = 1;
  UNLOCK();
  if (iVar1 == 1) {
    uVar6 = 0x800;
  }
  else if (piVar2[2] < 0) {
    if (piVar2[0xc] == 0) {
      local_8 = piVar2 + 0x10;
    }
    else {
      local_8 = (int *)(piVar2[0xc] + 0x10);
    }
    LOCK();
    iVar1 = *local_8;
    *local_8 = 1;
    UNLOCK();
    if (iVar1 == 1) {
      LOCK();
      *piVar2 = 0;
      UNLOCK();
      uVar6 = 0x800;
    }
    else {
      piVar7 = local_8 + 2;
      piVar2[0xe] = piVar2[0xe] + 1;
      LOCK();
      *piVar2 = 0;
      UNLOCK();
      while (iVar1 = *piVar7, iVar1 != 0) {
        iVar4 = *(int *)(iVar1 + 0x90);
        if (iVar4 == iVar1) {
          *piVar7 = 0;
        }
        else {
          iVar5 = *(int *)(iVar1 + 0x94);
          *piVar7 = iVar4;
          *(int *)(iVar4 + 0x94) = iVar5;
          *(int *)(iVar5 + 0x90) = iVar4;
          *(int *)(iVar1 + 0x90) = iVar1;
          *(int *)(iVar1 + 0x94) = iVar1;
        }
        if ((uint)param_1[6] <= *(uint *)(iVar1 + 0x9c)) {
          *(undefined4 *)(iVar1 + 0x98) = 0;
          *(int **)(iVar1 + 0x9c) = param_1;
          *(int *)(iVar1 + 0xa0) = piVar2[0xd];
          piVar2[0xd] = piVar2[0xd] + 1;
          LOCK();
          *local_8 = 0;
          UNLOCK();
          _thread_go(iVar1);
          goto LAB_0014ab85;
        }
        *(undefined4 *)(iVar1 + 0x98) = 0x10004004;
        *(int *)(iVar1 + 0x9c) = param_1[6];
        _thread_go(iVar1);
      }
      iVar1 = local_8[1];
      if (iVar1 == 0) {
        local_8[1] = (int)param_1;
        *param_1 = (int)param_1;
        param_1[1] = (int)param_1;
      }
      else {
        puVar3 = *(undefined4 **)(iVar1 + 4);
        *param_1 = iVar1;
        param_1[1] = (int)puVar3;
        *(int **)(iVar1 + 4) = param_1;
        *puVar3 = param_1;
      }
      LOCK();
      *local_8 = 0;
      UNLOCK();
LAB_0014ab85:
      uVar6 = 0;
    }
  }
  else {
    LOCK();
    *piVar2 = 0;
    UNLOCK();
    uVar6 = 0x10000003;
  }
  return uVar6;
}

