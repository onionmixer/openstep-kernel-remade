
undefined4 _sgopen(byte param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (uint)param_1 * 0x42;
  if ((param_1 < 4) && (*(int *)(_sg_sgd + iVar1) != 0)) {
    if (_sg_sgd[iVar1 + 0x16] == '\0') {
      sub_407F682(*(int *)(_sg_sgd + iVar1));
      _sg_sgd[iVar1 + 0x16] = 1;
      _sg_sgd[iVar1 + 0x17] = 0;
      _scsi_ndevices = _scsi_ndevices + 1;
      uVar2 = 0;
    }
    else {
      uVar2 = 0x10;
    }
  }
  else {
    uVar2 = 6;
  }
  return uVar2;
}

