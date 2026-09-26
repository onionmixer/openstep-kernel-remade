
void sub_407FAE2(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  
  piVar4 = param_1 + 2;
  if (piVar4 == (int *)*piVar4) {
                    /* WARNING: Subroutine does not return */
    _panic(aSgdoneNoBufOnS);
  }
  *(undefined *)((int)param_1 + 0x15) = 0;
  iVar1 = *piVar4;
  piVar2 = *(int **)(iVar1 + 0x4a);
  piVar3 = *(int **)(iVar1 + 0x4e);
  if (piVar2 == piVar4) {
    param_1[3] = (int)piVar3;
  }
  else {
    *(int **)((int)piVar2 + 0x4e) = piVar3;
  }
  if (piVar3 == param_1 + 2) {
    *piVar3 = (int)piVar2;
  }
  else {
    *(int **)((int)piVar3 + 0x4a) = piVar2;
  }
  *(int *)(iVar1 + 0x3c) = *(int *)(iVar1 + 0x14) - param_2;
  *(int *)(iVar1 + 0x1c) = param_3;
  if (param_3 == 2) {
    *(undefined *)(iVar1 + 0x20) = 2;
  }
  else {
    *(undefined *)(iVar1 + 0x20) = *(undefined *)(*param_1 + 0x4e);
  }
  if (param_1 + 2 == (int *)param_1[2]) {
    *(byte *)(iVar1 + 0x48) = *(byte *)(iVar1 + 0x48) | 1;
    _wakeup(iVar1);
  }
  else {
    _scsi_dstart(*param_1);
  }
  return;
}

