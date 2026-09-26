
void __vm_map_clip_start(int param_1,int *param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)__vm_map_entry_create(param_1);
  *piVar2 = *param_2;
  piVar2[1] = param_2[1];
  piVar2[2] = param_2[2];
  piVar2[3] = param_2[3];
  piVar2[4] = param_2[4];
  piVar2[5] = param_2[5];
  piVar2[6] = param_2[6];
  piVar2[7] = param_2[7];
  piVar2[8] = param_2[8];
  piVar2[9] = param_2[9];
  *(undefined2 *)(piVar2 + 10) = *(undefined2 *)(param_2 + 10);
  piVar2[3] = param_3;
  param_2[5] = (param_3 - param_2[2]) + param_2[5];
  param_2[2] = param_3;
  *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
  *piVar2 = *param_2;
  piVar2[1] = *(int *)(*param_2 + 4);
  iVar1 = *piVar2;
  *(int **)piVar2[1] = piVar2;
  *(int **)(iVar1 + 4) = piVar2;
  if ((*(byte *)(param_2 + 6) & 0xa0) == 0) {
    _vm_object_reference(piVar2[4]);
  }
  else {
    _vm_map_reference(piVar2[4]);
  }
  return;
}
