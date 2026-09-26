
void sub_4089042(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  int *piVar4;
  
  piVar4 = (int *)((int)param_1 + 0x7e);
  if (piVar4 == (int *)*piVar4) {
                    /* WARNING: Subroutine does not return */
    _panic(aStdoneNoBufOnS);
  }
  *(undefined *)((int)param_1 + 0x7d) = 0;
  iVar1 = *piVar4;
  piVar2 = *(int **)(iVar1 + 0x4a);
  puVar3 = *(undefined4 **)(iVar1 + 0x4e);
  if (piVar2 == piVar4) {
    *(undefined4 **)((int)param_1 + 0x82) = puVar3;
  }
  else {
    *(undefined4 **)((int)piVar2 + 0x4e) = puVar3;
  }
  if (puVar3 == (undefined4 *)((int)param_1 + 0x7e)) {
    *puVar3 = piVar2;
  }
  else {
    *(int **)((int)puVar3 + 0x4a) = piVar2;
  }
  *(int *)(iVar1 + 0x3c) = *(int *)(iVar1 + 0x14) - param_2;
  *(int *)(iVar1 + 0x1c) = param_3;
  if (param_3 == 2) {
    *(undefined *)(iVar1 + 0x20) = 2;
  }
  else {
    *(undefined *)(iVar1 + 0x20) = *(undefined *)(*param_1 + 0x4e);
  }
  if ((int *)((int)param_1 + 0x7e) != *(int **)((int)param_1 + 0x7e)) {
    _scsi_dstart(*param_1);
  }
  if ((*(word *)((int)param_1 + 0x66) & 1) == 0) {
    *(byte *)(iVar1 + 0x48) = *(byte *)(iVar1 + 0x48) | 1;
    _wakeup(iVar1);
  }
  else {
    *(word *)((int)param_1 + 0x66) = *(word *)((int)param_1 + 0x66) & 0xfffe;
  }
  return;
}
