
undefined4 _ipc_mqueue_send_interrupt(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  undefined4 uVar7;
  int *piVar8;
  
  iVar2 = param_1[7];
  if (*(int *)(iVar2 + 4) < 0) {
    if (*(int *)(iVar2 + 0x2c) == 0) {
      piVar8 = (int *)(iVar2 + 0x3c);
    }
    else {
      piVar8 = (int *)(*(int *)(iVar2 + 0x2c) + 0xc);
    }
    piVar6 = piVar8 + 1;
    *(int *)(iVar2 + 0x34) = *(int *)(iVar2 + 0x34) + 1;
    while (iVar1 = *piVar6, iVar1 != 0) {
      iVar4 = *(int *)(iVar1 + 0x8c);
      if (iVar1 == iVar4) {
        *piVar6 = 0;
      }
      else {
        iVar5 = *(int *)(iVar1 + 0x90);
        *piVar6 = iVar4;
        *(int *)(iVar4 + 0x90) = iVar5;
        *(int *)(iVar5 + 0x8c) = iVar4;
        *(int *)(iVar1 + 0x8c) = iVar1;
        *(int *)(iVar1 + 0x90) = iVar1;
      }
      if ((uint)param_1[6] <= *(uint *)(iVar1 + 0x98)) {
        *(undefined4 *)(iVar1 + 0x94) = 0;
        *(int **)(iVar1 + 0x98) = param_1;
        *(undefined4 *)(iVar1 + 0x9c) = *(undefined4 *)(iVar2 + 0x30);
        *(int *)(iVar2 + 0x30) = *(int *)(iVar2 + 0x30) + 1;
        _thread_go(iVar1);
        goto loc_403F65C;
      }
      *(undefined4 *)(iVar1 + 0x94) = 0x10004004;
      *(int *)(iVar1 + 0x98) = param_1[6];
      _thread_go(iVar1);
    }
    iVar2 = *piVar8;
    if (iVar2 == 0) {
      *piVar8 = (int)param_1;
      *param_1 = (int)param_1;
      param_1[1] = (int)param_1;
    }
    else {
      puVar3 = *(undefined4 **)(iVar2 + 4);
      *param_1 = iVar2;
      param_1[1] = (int)puVar3;
      *(int **)(iVar2 + 4) = param_1;
      *puVar3 = param_1;
    }
loc_403F65C:
    uVar7 = 0;
  }
  else {
    uVar7 = 0x10000003;
  }
  return uVar7;
}

