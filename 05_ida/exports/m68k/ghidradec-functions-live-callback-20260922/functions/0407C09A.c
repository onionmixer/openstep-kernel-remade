
void _scsi_cintr(undefined4 *param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  undefined4 *puVar4;
  
  piVar2 = *(int **)(param_1[4] + 0x18);
  if (*(char *)((int)param_1 + 0x5a) == '\x01') {
    *(undefined *)((int)param_1 + 0x5a) = 0;
  }
  else {
    *(undefined *)((int)param_1 + 0x5a) = 0;
    switch(*(undefined *)((int)piVar2 + 0x4f)) {
    case :
      break;
    :
                    /* WARNING: Subroutine does not return */
      _panic(aScsiCintrBadSd);
    case :
    case :
    case :
    case :
    case :
    case :
    case :
      iVar1 = *piVar2;
      piVar3 = (int *)piVar2[1];
      if (iVar1 == param_1[4] + 0x18) {
        *(int **)(param_1[4] + 0x1c) = piVar3;
      }
      else {
        *(int **)(iVar1 + 4) = piVar3;
      }
      *piVar3 = iVar1;
      *(byte *)(piVar2 + 9) = *(byte *)(piVar2 + 9) & 0xdf;
      (**(code **)(piVar2[5] + 0x16))(piVar2);
      break;
    case :
      iVar1 = *piVar2;
      piVar3 = (int *)piVar2[1];
      if (iVar1 == param_1[4] + 0x18) {
        *(int **)(param_1[4] + 0x1c) = piVar3;
      }
      else {
        *(int **)(iVar1 + 4) = piVar3;
      }
      *piVar3 = iVar1;
      puVar4 = (undefined4 *)param_1[1];
      if (puVar4 == param_1) {
        *param_1 = piVar2;
      }
      else {
        puVar4[2] = piVar2;
      }
      piVar2[3] = (int)puVar4;
      piVar2[2] = (int)param_1;
      param_1[1] = piVar2;
      *(char *)(param_1 + 0x18) = *(char *)(param_1 + 0x18) + '\x01';
    }
    if (((int *)(param_1[4] + 0x18) != *(int **)(param_1[4] + 0x18)) &&
       (*(char *)((int)param_1 + 0x5a) == '\0')) {
      sub_407C04A(param_1);
    }
  }
  return;
}

