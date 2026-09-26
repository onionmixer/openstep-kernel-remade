
undefined4 _np_startdata(undefined4 *param_1)

{
  int *piVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  
  uVar3 = *param_1;
  uVar2 = *(uint *)((int)param_1 + 0x126);
  if (uVar2 == 3) {
    _np_cleargpout(param_1,0x30);
    iVar4 = param_1[0x3f];
    _np_send(uVar3,199,(int)**(char **)(iVar4 + 4));
    if (_dma_chip == 0x139) {
      piVar1 = (int *)(iVar4 + 4);
      *piVar1 = *piVar1 + 4;
    }
    _dma_start(param_1 + 1,param_1[0x3f],0);
    _lpr_csr_or(0x20);
    _lpr_csr_or(0x80);
    _lpr_csr_or(0x20);
    if (_dma_chip != 0x139) {
      iVar4 = 0;
      do {
        _lpr_csr_or(1);
        _delay(1);
        iVar4 = iVar4 + 1;
      } while (iVar4 < 4);
    }
    _np_setstate(param_1,4);
    if (*(char *)((int)param_1 + 0x142) == '\0') {
      uVar5 = 0x3f;
    }
    else {
      uVar5 = 0x2f;
    }
    _np_send(uVar3,uVar5,0);
    uVar3 = _timeout(_np_printing_timeout,param_1,_hz * 0xf);
  }
  else {
    uVar3 = CONCAT22((sword)(uVar2 >> 0x10),
                     (word)(byte)((3 < uVar2) << 4 | ((int)(3 - uVar2) < 0) << 3 |
                                  SBORROW4(3,uVar2) << 1 | 3 < uVar2));
  }
  return uVar3;
}
