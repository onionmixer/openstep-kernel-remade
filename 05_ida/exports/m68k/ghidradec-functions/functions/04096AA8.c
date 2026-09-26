
undefined4 _thread_setstatus(int param_1,int param_2,undefined4 *param_3,uint param_4)

{
  word wVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  if (param_2 == 2) {
    if (0x1b < param_4) {
      iVar2 = *(int *)(param_1 + 0x24);
      _bcopy(param_3,iVar2 + 0x134,0x60);
      *(undefined4 *)(iVar2 + 0x194) = param_3[0x18];
      *(undefined4 *)(iVar2 + 0x198) = param_3[0x19];
      *(undefined4 *)(iVar2 + 0x19c) = param_3[0x1a];
      return 0;
    }
  }
  else if (param_2 < 3) {
    if ((param_2 == 1) && (0x11 < param_4)) {
      if (*(int *)(*(int *)(param_1 + 0xc) + 0x44) == 0) {
        if (*(int *)(*(int *)(param_1 + 0x24) + 0x4c) == 0) {
          puVar3 = (undefined4 *)_thread_user_state(param_1);
        }
        else {
          puVar3 = *(undefined4 **)(*(int *)(param_1 + 0x24) + 0x48);
        }
        iVar2 = 0;
        puVar4 = param_3;
        puVar5 = puVar3;
        do {
          *puVar5 = *puVar4;
          puVar3[iVar2 + 8] = param_3[iVar2 + 8];
          iVar2 = iVar2 + 1;
          puVar4 = puVar4 + 1;
          puVar5 = puVar5 + 1;
        } while (iVar2 < 8);
        *(undefined2 *)(puVar3 + 0x10) = *(undefined2 *)((int)param_3 + 0x42);
        *(undefined4 *)((int)puVar3 + 0x42) = param_3[0x11];
        wVar1 = *(word *)(puVar3 + 0x10);
        *(word *)(puVar3 + 0x10) = wVar1 & 0xc0ff;
        *(word *)(puVar3 + 0x10) = wVar1 & 0xc0ff;
        if ((wVar1 & 0xc000) == 0xc000) {
          *(word *)(puVar3 + 0x10) = wVar1 & 0x80ff;
        }
      }
      else {
        puVar3 = *(undefined4 **)(param_1 + 0x24);
        iVar2 = 0;
        puVar4 = param_3;
        puVar5 = puVar3;
        do {
          *puVar5 = *puVar4;
          puVar3[iVar2 + 8] = param_3[iVar2 + 8];
          iVar2 = iVar2 + 1;
          puVar4 = puVar4 + 1;
          puVar5 = puVar5 + 1;
        } while (iVar2 < 8);
        _thread_start(param_1,param_3[0x11]);
      }
      return 0;
    }
  }
  else if ((param_2 == 3) && (param_4 != 0)) {
    *(undefined4 *)(*(int *)(param_1 + 0x24) + 0x50) = *param_3;
    return 0;
  }
  return 4;
}
