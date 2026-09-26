
undefined4 _logopen(void)

{
  int *piVar1;
  undefined4 uVar2;
  uint uVar3;
  
  if (_log_open == 0) {
    dword_40B67E8 = 0;
    dword_40B67EC = (int)*(sword *)(*_active_u + 0x2e);
    dword_40B67F0 = _calloutEntryAllocate(sub_400B228,0);
    piVar1 = _pmsgbuf;
    _log_open = 1;
    if (*_pmsgbuf != 0x63061) {
      *_pmsgbuf = 0x63061;
      piVar1[2] = 0;
      piVar1[1] = 0;
      uVar3 = 0;
      do {
        *(undefined *)((int)_pmsgbuf + uVar3 + 0xc) = 0;
        uVar3 = uVar3 + 1;
      } while (uVar3 < 0xff4);
    }
    uVar2 = 0;
  }
  else {
    uVar2 = 0x10;
  }
  return uVar2;
}

