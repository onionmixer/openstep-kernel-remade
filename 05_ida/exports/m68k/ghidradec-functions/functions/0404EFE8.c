
void _processor_init(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  *(undefined4 *)(param_1 + 0x100) = 0x1f;
  *(undefined4 *)(param_1 + 0x104) = 0;
  iVar1 = 0;
  iVar2 = param_1;
  do {
    *(int *)(iVar2 + 4) = iVar2;
    *(int *)iVar2 = iVar2;
    iVar2 = iVar2 + 8;
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x20);
  iVar1 = param_1 + 0x108;
  *(int *)(param_1 + 0x10c) = iVar1;
  *(int *)iVar1 = iVar1;
  *(undefined4 *)(param_1 + 0x110) = 0;
  *(undefined4 *)(param_1 + 0x114) = 0;
  *(undefined4 *)(param_1 + 0x118) = 0;
  *(undefined4 *)(param_1 + 0x11c) = 0;
  *(undefined4 *)(param_1 + 0x120) = 0;
  *(undefined4 *)(param_1 + 0x124) = 0;
  *(undefined4 *)(param_1 + 0x128) = 0;
  *(undefined4 *)(param_1 + 300) = 0;
  iVar1 = param_1 + 0x130;
  *(int *)(param_1 + 0x134) = iVar1;
  *(int *)iVar1 = iVar1;
  *(undefined4 *)(param_1 + 0x138) = 0;
  *(undefined4 *)(param_1 + 0x13c) = param_2;
  return;
}
