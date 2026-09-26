
void _run_queue_enqueue(int param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = param_2[0x15];
  if (0x1f < uVar2) {
    _printf(aRunQueueEnqueu,uVar2);
    uVar2 = 0x1f;
  }
  iVar1 = param_1 + uVar2 * 8;
  *param_2 = iVar1;
  param_2[1] = *(int *)(iVar1 + 4);
  *(int **)param_2[1] = param_2;
  *(int **)(iVar1 + 4) = param_2;
  if ((*(uint *)(param_1 + 0x100) < uVar2) || (*(int *)(param_1 + 0x104) == 0)) {
    *(uint *)(param_1 + 0x100) = uVar2;
  }
  *(int *)(param_1 + 0x104) = *(int *)(param_1 + 0x104) + 1;
  param_2[2] = param_1;
  return;
}
