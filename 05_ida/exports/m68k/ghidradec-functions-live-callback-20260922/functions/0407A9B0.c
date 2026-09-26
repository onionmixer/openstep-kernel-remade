
void _od_eject(void)

{
  int iVar1;
  undefined *puVar2;
  uint auStack_24 [8];
  
  _nvram_check(auStack_24);
  puVar2 = _od_drive;
  do {
    if (((*(word *)((int)puVar2 + 0x18) & 0x5000) == 0x5000) &&
       ((iVar1 = (*(int *)((int)puVar2 + 8) + -0x40c3ec8) * -0x2593f69b >> 1, iVar1 != 0 ||
        ((auStack_24[0] & 0x4003c01) != 0x1800)))) {
      iVar1 = iVar1 << 3;
      _od_sync(iVar1);
      _od_cmd(iVar1,0xf6,0,0,0,0,0,0,0,0);
    }
    puVar2 = (undefined *)((int)puVar2 + 0x20);
  } while (puVar2 < &_od_empty);
  return;
}

