
undefined4 _thread_getstatus(int param_1,int param_2,undefined4 *param_3,uint *param_4)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  if (param_2 == 1) {
    if (0x11 < *param_4) {
      if (*(int *)(*(int *)(param_1 + 0x24) + 0x4c) == 0) {
        puVar1 = (undefined4 *)_thread_user_state(param_1);
      }
      else {
        puVar1 = *(undefined4 **)(*(int *)(param_1 + 0x24) + 0x48);
      }
      iVar2 = 0;
      puVar3 = puVar1;
      puVar4 = param_3;
      do {
        *puVar4 = *puVar3;
        param_3[iVar2 + 8] = puVar1[iVar2 + 8];
        iVar2 = iVar2 + 1;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      } while (iVar2 < 8);
      *(undefined2 *)((int)param_3 + 0x42) = *(undefined2 *)(puVar1 + 0x10);
      param_3[0x11] = *(undefined4 *)((int)puVar1 + 0x42);
      *param_4 = 0x12;
      return 0;
    }
  }
  else if (param_2 < 2) {
    if ((param_2 == 0) && (5 < *param_4)) {
      *param_3 = 1;
      param_3[1] = 0x12;
      param_3[2] = 2;
      param_3[3] = 0x1c;
      param_3[4] = 3;
      param_3[5] = 1;
      *param_4 = 6;
      return 0;
    }
  }
  else if (param_2 == 2) {
    if (0x1b < *param_4) {
      iVar2 = *(int *)(param_1 + 0x24);
      _bcopy(iVar2 + 0x134,param_3,0x60);
      param_3[0x18] = *(undefined4 *)(iVar2 + 0x194);
      param_3[0x19] = *(undefined4 *)(iVar2 + 0x198);
      param_3[0x1a] = *(undefined4 *)(iVar2 + 0x19c);
      param_3[0x1b] = 0;
      *param_4 = 0x1c;
      return 0;
    }
  }
  else if ((param_2 == 3) && (*param_4 != 0)) {
    *param_3 = *(undefined4 *)(*(int *)(param_1 + 0x24) + 0x50);
    *param_4 = 1;
    return 0;
  }
  return 4;
}

