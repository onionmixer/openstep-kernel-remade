
void _PCcallMonitor(int param_1,undefined2 *param_2)

{
  int *piVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  
  piVar1 = *(int **)(*(int *)(param_1 + 0x28) + 0xec);
  iVar3 = 0;
  if (piVar1 != (int *)0x0) {
    iVar3 = *piVar1;
  }
  if (*(uint *)(iVar3 + 0x84) < 8) {
    iVar4 = iVar3 + 0x88 + *(uint *)(iVar3 + 0x84) * 0x84;
  }
  else {
    iVar4 = 0;
  }
  *(undefined4 *)(iVar3 + 0x80) = 0;
  if (*(int *)(iVar4 + 0x6c) != 0) {
    *(byte *)(iVar3 + 0x80) = *(byte *)(iVar3 + 0x80) | 4;
  }
  if ((*(byte *)(param_2 + 0x21) & 2) == 0) {
    *(byte *)(iVar3 + 0x80) = *(byte *)(iVar3 + 0x80) | 1;
    *(undefined2 *)(iVar3 + 0x70) = param_2[6];
    *(undefined2 *)(iVar3 + 0x74) = param_2[4];
    *(undefined2 *)(iVar3 + 0x78) = param_2[2];
    uVar2 = *param_2;
  }
  else {
    *(byte *)(iVar3 + 0x80) = *(byte *)(iVar3 + 0x80) & 0xfe;
    *(undefined2 *)(iVar3 + 0x70) = param_2[0x28];
    *(undefined2 *)(iVar3 + 0x74) = param_2[0x26];
    *(undefined2 *)(iVar3 + 0x78) = param_2[0x2a];
    uVar2 = param_2[0x2c];
  }
  *(undefined2 *)(iVar3 + 0x7c) = uVar2;
  *(undefined4 *)(iVar3 + 100) = *(undefined4 *)(param_2 + 0x20);
  if (*(int *)(iVar4 + 0x68) == 0) {
    *(uint *)(iVar3 + 100) = *(uint *)(iVar3 + 100) & 0xfffffdff;
  }
  else {
    *(uint *)(iVar3 + 100) = *(uint *)(iVar3 + 100) | 0x200;
  }
  *(uint *)(iVar3 + 100) = *(uint *)(iVar3 + 100) | *(ushort *)(iVar4 + 0x70) & 0x7000;
  *(undefined2 *)(iVar3 + 0x6c) = param_2[0x1e];
  *(undefined4 *)(iVar3 + 0x68) = *(undefined4 *)(param_2 + 0x1c);
  *(undefined2 *)(iVar3 + 0x60) = param_2[0x24];
  *(undefined4 *)(iVar3 + 0x5c) = *(undefined4 *)(param_2 + 0x22);
  *(undefined4 *)(iVar3 + 0x58) = *(undefined4 *)(param_2 + 0xc);
  *(undefined4 *)(iVar3 + 0x54) = *(undefined4 *)(param_2 + 10);
  *(undefined4 *)(iVar3 + 0x50) = *(undefined4 *)(param_2 + 8);
  *(undefined4 *)(iVar3 + 0x4c) = *(undefined4 *)(param_2 + 0x12);
  *(undefined4 *)(iVar3 + 0x48) = *(undefined4 *)(param_2 + 0x14);
  *(undefined4 *)(iVar3 + 0x44) = *(undefined4 *)(param_2 + 0x10);
  *(undefined4 *)(iVar3 + 0x40) = *(undefined4 *)(param_2 + 0x16);
  *(undefined4 *)(iVar4 + 0x48) = 0;
  _PCdeliverTimers(iVar4);
  param_2[6] = 0x6b;
  param_2[4] = 0x6b;
  param_2[2] = 0;
  *param_2 = 0;
  param_2[0x1e] = 99;
  *(undefined4 *)(param_2 + 0x1c) = *(undefined4 *)(iVar3 + 0x28);
  param_2[0x24] = 0x6b;
  *(undefined4 *)(param_2 + 0x22) = *(undefined4 *)(iVar4 + 0x24);
  *(undefined4 *)(param_2 + 0xc) = 0;
  *(uint *)(param_2 + 0x20) = *(uint *)(param_2 + 0x20) & 0xfffdfaff;
  _thread_exception_return();
  return;
}

