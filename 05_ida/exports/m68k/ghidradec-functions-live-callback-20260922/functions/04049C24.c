
undefined4 _mach_ports_register(int param_1,int *param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int aiStack_14 [4];
  
  if ((param_1 != 0) && (param_3 < 5)) {
    uVar2 = 0;
    piVar4 = param_2;
    if (param_3 != 0) {
      do {
        aiStack_14[uVar2] = *piVar4;
        uVar2 = uVar2 + 1;
        piVar4 = piVar4 + 1;
      } while (uVar2 < param_3);
    }
    for (; (int)uVar2 < 4; uVar2 = uVar2 + 1) {
      aiStack_14[uVar2] = 0;
    }
    if (*(int *)(param_1 + 0x5c) != 0) {
      iVar3 = 0;
      do {
        iVar1 = *(int *)(param_1 + 0x6c + iVar3 * 4);
        *(int *)(param_1 + 0x6c + iVar3 * 4) = aiStack_14[iVar3];
        aiStack_14[iVar3] = iVar1;
        iVar3 = iVar3 + 1;
      } while (iVar3 < 4);
      iVar3 = 0;
      do {
        iVar1 = aiStack_14[iVar3];
        if ((iVar1 != 0) && (iVar1 != -1)) {
          _ipc_port_release_send(iVar1);
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < 4);
      if (param_3 != 0) {
        _kfree(param_2,param_3 << 2);
      }
      return 0;
    }
  }
  return 4;
}

