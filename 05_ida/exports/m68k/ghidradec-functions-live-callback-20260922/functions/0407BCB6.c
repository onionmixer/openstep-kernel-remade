
void sub_407BCB6(int param_1,int param_2)

{
  int iVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  
  iVar3 = *(sword *)(*(int *)(param_1 + 0x10) + 4) * 0x250;
  piVar4 = (int *)(_sc_s5c + iVar3);
  iVar1 = *(int *)(*(int *)(*piVar4 + 0x10) + 8);
  *(undefined *)(iVar1 + 0x20) = 0x20;
  _dma_abort(iVar3 + 0x40c5944);
  *(uint *)(_sc_s5c + iVar3 + 0x30) = *(uint *)(_sc_s5c + iVar3 + 0x30) & 0xffffbfff;
  if (_sc_s5c[iVar3 + 0x21e] == '\x06') {
    _busdone(*(undefined4 *)(*piVar4 + 0x10));
  }
  cVar2 = _sc_s5c[iVar3 + 0x21e];
  if (cVar2 != '\0') {
    *(undefined *)(iVar1 + 3) = 3;
    _delay(500000);
    _sc_s5c[iVar3 + 0x21e] = 0;
  }
  _sfa_abort(*(undefined4 *)(_sc_s5c + iVar3 + 0x238),iVar3 + 0x40c5b7c,1);
  iVar1 = *(int *)(_sc_s5c + iVar3 + 0x226);
  if (iVar1 != 0) {
    if (param_2 == 0) {
      *(undefined *)(iVar1 + 0x4f) = 7;
    }
    else {
      *(undefined *)(iVar1 + 0x4f) = 5;
    }
    *(undefined4 *)(_sc_s5c + iVar3 + 0x226) = 0;
    if (cVar2 != '\0') {
      _scsi_cintr(param_1);
    }
  }
  *(undefined *)(*piVar4 + 0x60) = 0;
  _scsi_restart(*piVar4);
  return;
}

