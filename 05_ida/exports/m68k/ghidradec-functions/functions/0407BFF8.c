
undefined4 _scsi_dstart(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  iVar1 = param_1[6];
  puVar2 = *(undefined4 **)(*(int *)(iVar1 + 0x10) + 0x1c);
  *puVar2 = param_1;
  param_1[1] = (int)puVar2;
  *param_1 = *(int *)(iVar1 + 0x10) + 0x18;
  *(int **)(*(int *)(iVar1 + 0x10) + 0x1c) = param_1;
  *(byte *)(param_1 + 9) = *(byte *)(param_1 + 9) | 0x20;
  if (*(char *)(iVar1 + 0x5a) == '\0') {
    uVar3 = sub_407C04A(iVar1);
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}
