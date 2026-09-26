
undefined4 _sgclose(byte param_1)

{
  int iVar1;
  int *piVar2;
  char *pcVar3;
  undefined4 uVar4;
  
  iVar1 = (uint)param_1 * 0x42;
  piVar2 = (int *)(_sg_sgd + iVar1);
  if ((param_1 < 4) && (_sg_sgd[iVar1 + 0x16] != '\0')) {
    _sg_sgd[iVar1 + 0x16] = 0;
    iVar1 = *piVar2;
    if (*(byte *)(iVar1 + 0x1c) != 0xff) {
      pcVar3 = (char *)(*(int *)(iVar1 + 0x18) + (uint)*(byte *)(iVar1 + 0x1c) * 8 + 0x18 +
                       (uint)*(byte *)(iVar1 + 0x1d));
      *pcVar3 = *pcVar3 + -1;
      *(undefined *)(*piVar2 + 0x1c) = 0xff;
      *(undefined *)(*piVar2 + 0x1d) = 0xff;
    }
    _scsi_ndevices = _scsi_ndevices + -1;
    uVar4 = 0;
  }
  else {
    uVar4 = 6;
  }
  return uVar4;
}

