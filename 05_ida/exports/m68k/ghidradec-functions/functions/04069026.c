
undefined _process_device_mods(byte param_1)

{
  undefined uVar1;
  byte bVar2;
  int iVar3;
  
  iVar3 = 0;
  bVar2 = 1;
  do {
    uVar1 = 0;
    if ((bVar2 & (_deviceMods ^ param_1)) != 0) {
      _deviceMods = bVar2 ^ _deviceMods;
      uVar1 = _DoKbdEvent(*(undefined *)((int)&aQrwtusv + iVar3),-(int)-((bVar2 & _deviceMods) != 0)
                          ,_deviceMods);
    }
    iVar3 = iVar3 + 1;
    bVar2 = bVar2 << 1;
  } while (iVar3 < 7);
  return uVar1;
}
