
undefined4 * sub_4028224(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  if (_rfssize == 0) {
    iVar3 = 0;
    puVar2 = &_nfs_portmon;
    do {
      puVar1 = (undefined4 *)(_rfsdisptab + iVar3);
      if (puVar1 < puVar2) {
        do {
          if (_rfssize < (int)puVar1[2]) {
            _rfssize = puVar1[2];
          }
          if (_rfssize < (int)puVar1[4]) {
            _rfssize = puVar1[4];
          }
          puVar1 = puVar1 + 6;
        } while (puVar1 < (undefined4 *)((int)&_nfs_portmon + iVar3));
      }
      iVar3 = iVar3 + 0x1b0;
      puVar2 = puVar2 + 0x6c;
    } while ((int)puVar2 < 0x40aedd5);
  }
  if (_rfsfreesp == (undefined4 *)0x0) {
    iVar3 = _kalloc(_rfssize + 4);
    puVar2 = (undefined4 *)(iVar3 + 4);
  }
  else {
    puVar2 = _rfsfreesp;
    _rfsfreesp = (undefined4 *)*_rfsfreesp;
  }
  return puVar2;
}
