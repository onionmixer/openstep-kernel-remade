
void _soqinsque(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  *(int *)(param_2 + 0x10) = param_1;
  if (param_3 == 0) {
    *(sword *)(param_1 + 0x18) = *(sword *)(param_1 + 0x18) + 1;
    iVar1 = *(int *)(param_1 + 0x14);
    iVar2 = param_1;
    while (param_1 != iVar1) {
      iVar2 = *(int *)(iVar2 + 0x14);
      iVar1 = *(int *)(iVar2 + 0x14);
    }
    *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(iVar2 + 0x14);
    *(int *)(iVar2 + 0x14) = param_2;
  }
  else {
    *(sword *)(param_1 + 0x1e) = *(sword *)(param_1 + 0x1e) + 1;
    iVar1 = *(int *)(param_1 + 0x1a);
    iVar2 = param_1;
    while (param_1 != iVar1) {
      iVar2 = *(int *)(iVar2 + 0x1a);
      iVar1 = *(int *)(iVar2 + 0x1a);
    }
    *(undefined4 *)(param_2 + 0x1a) = *(undefined4 *)(iVar2 + 0x1a);
    *(int *)(iVar2 + 0x1a) = param_2;
  }
  return;
}

