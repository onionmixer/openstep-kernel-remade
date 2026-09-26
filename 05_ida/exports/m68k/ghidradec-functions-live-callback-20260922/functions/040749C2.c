
undefined4 _np_attach(int param_1)

{
  int iVar1;
  
  iVar1 = *(sword *)(param_1 + 4) * 0x14c;
  *(byte *)(*(int *)(param_1 + 0x12) + 2) = *(byte *)(*(int *)(param_1 + 0x12) + 2) & 0xfd;
  *(undefined4 *)(_np_softc + iVar1 + 0x126) = 0;
  *(undefined4 *)(_np_softc + iVar1 + 0x106) = 0;
  *(undefined4 *)(_np_softc + iVar1 + 0x122) = 0;
  *(undefined4 *)(_np_softc + iVar1 + 0x11e) = *(undefined4 *)(_np_softc + iVar1 + 0x122);
  _lock_init(iVar1 + 0x40c3b2e,1);
  _lock_init(iVar1 + 0x40c3b36,1);
  *(code **)(_np_softc + iVar1 + 0x14) = _np_dma_intr;
  *(undefined **)(_np_softc + iVar1 + 0x18) = _np_softc + iVar1;
  *(undefined4 *)(_np_softc + iVar1 + 0x1c) = 1;
  *(undefined4 *)(_np_softc + iVar1 + 0x30) = 1;
  *(int *)(_np_softc + iVar1 + 0x20) = _slot_id + 0x2000090;
  _bzero(iVar1 + 0x40c3a6c,0xa0);
  _dma_init(iVar1 + 0x40c3a28,0x1865);
  return 0;
}

