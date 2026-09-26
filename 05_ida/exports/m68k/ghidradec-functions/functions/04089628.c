
int sub_4089628(int *param_1,char *param_2,int param_3)

{
  undefined4 *puVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *param_1;
  if (param_3 == 1) {
    param_1[0x1a] = 0x32;
  }
  else {
    param_1[0x1a] = 0;
  }
  puVar1 = *(undefined4 **)((int)param_1 + 0x82);
  if (puVar1 == (undefined4 *)((int)param_1 + 0x7e)) {
    *puVar1 = param_2;
  }
  else {
    *(char **)((int)puVar1 + 0x4a) = param_2;
  }
  *(undefined4 **)(param_2 + 0x4e) = puVar1;
  *(int *)(param_2 + 0x4a) = (int)param_1 + 0x7e;
  *(char **)((int)param_1 + 0x82) = param_2;
  iVar4 = 0;
  if (param_3 == 0) {
    param_2[0x48] = param_2[0x48] & 0xfe;
  }
  else {
    *(word *)((int)param_1 + 0x66) = *(word *)((int)param_1 + 0x66) | 1;
  }
  if ((*(byte *)(iVar3 + 0x24) & 0x20) == 0) {
    iVar4 = _scsi_dstart(iVar3);
  }
  if (iVar4 == 0) {
    if (param_3 == 0) {
      bVar2 = param_2[0x48];
      while ((bVar2 & 1) == 0) {
        _sleep(param_2,0x14);
        bVar2 = param_2[0x48];
      }
    }
    else {
      iVar3 = 0;
      *(word *)((int)param_1 + 0x66) = *(word *)((int)param_1 + 0x66) | 1;
      do {
        iVar3 = iVar3 + 1;
        if (iVar3 < 0x3e9) {
          _delay(1000);
        }
        else {
          _scsi_timeout(*(undefined4 *)(*param_1 + 0x18));
          iVar3 = 0;
        }
      } while ((*(byte *)((int)param_1 + 0x67) & 1) != 0);
    }
    if ((*(int *)(param_2 + 0x1c) != 0) && (param_3 != 0)) {
      iVar4 = 5;
    }
  }
  else {
    *(word *)((int)param_1 + 0x66) = *(word *)((int)param_1 + 0x66) & 0xfffe;
  }
  puVar1 = (undefined4 *)param_1[4];
  *(undefined4 *)(param_2 + 0x22) = *puVar1;
  *(undefined4 *)(param_2 + 0x26) = puVar1[1];
  *(undefined4 *)(param_2 + 0x2a) = puVar1[2];
  *(undefined4 *)(param_2 + 0x2e) = puVar1[3];
  *(undefined4 *)(param_2 + 0x32) = puVar1[4];
  *(undefined4 *)(param_2 + 0x36) = puVar1[5];
  *(undefined2 *)(param_2 + 0x3a) = *(undefined2 *)(puVar1 + 6);
  if (((iVar4 == 0) && (*(int *)(param_2 + 0x1c) == 0)) && (*param_2 == '\n')) {
    *(word *)((int)param_1 + 0x66) = *(word *)((int)param_1 + 0x66) | 8;
  }
  else {
    *(word *)((int)param_1 + 0x66) = *(word *)((int)param_1 + 0x66) & 0xfff7;
  }
  return iVar4;
}
