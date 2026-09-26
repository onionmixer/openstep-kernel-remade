
uint _process_mouse_event(int param_1)

{
  byte bVar1;
  uint uVar2;
  
  if (_buttonsTied == 0) {
    if (_mouseHandedness != 0) {
      bVar1 = *(byte *)(param_1 + 3);
      *(byte *)(param_1 + 3) = *(byte *)(param_1 + 2) & 1 | bVar1 & 0xfe;
      *(byte *)(param_1 + 2) = bVar1 & 1 | *(byte *)(param_1 + 2) & 0xfe;
    }
  }
  else {
    if ((*(byte *)(param_1 + 2) & 1) == 0) {
      *(byte *)(param_1 + 3) = *(byte *)(param_1 + 3) & 0xfe;
    }
    *(byte *)(param_1 + 2) = *(byte *)(param_1 + 2) | 1;
  }
  if ((~(uint)*(byte *)(param_1 + 3) & 1) != (*(uint *)(_evg + 8) & 7) >> 2) {
    if ((*(byte *)(param_1 + 3) & 1) == 0) {
      _lastPressure = 0xff;
      _LLEventPost(1,*(undefined4 *)(_evg + 0x18),0);
      uVar2 = *(uint *)(_evg + 8) | 4;
    }
    else {
      _lastPressure = 0;
      _LLEventPost(2,*(undefined4 *)(_evg + 0x18),0);
      uVar2 = *(uint *)(_evg + 8) & 0xfffffffb;
    }
    *(uint *)(_evg + 8) = uVar2;
    *(byte *)(_evg + 0x33) =
         *(byte *)(_evg + 0x33) & 0xfd | (byte)(((*(byte *)(_evg + 0x33) & 7) >> 2) << 1);
    if ((*(byte *)(_evg + 0x33) & 2) == 0) {
      uVar2 = *(uint *)(_evg + 0xc) & 0xfffffeff;
    }
    else {
      uVar2 = *(uint *)(_evg + 0xc) | 0x100;
    }
    *(uint *)(_evg + 0xc) = uVar2;
  }
  uVar2 = ~(uint)*(byte *)(param_1 + 2) & 1;
  if (uVar2 != (*(uint *)(_evg + 8) & 1)) {
    if ((*(byte *)(param_1 + 2) & 1) == 0) {
      _LLEventPost(3,*(undefined4 *)(_evg + 0x18),0);
      uVar2 = *(uint *)(_evg + 8) | 1;
    }
    else {
      _LLEventPost(4,*(undefined4 *)(_evg + 0x18),0);
      uVar2 = *(uint *)(_evg + 8) & 0xfffffffe;
    }
    *(uint *)(_evg + 8) = uVar2;
  }
  *(undefined4 *)(_evg + 0x14) = 1;
  uVar2 = CONCAT22((sword)(uVar2 >> 0x10),*(word *)(param_1 + 2)) & 0xfffffefe;
  if ((*(word *)(param_1 + 2) & 0xfefe) != 0) {
    uVar2 = *(uint *)(param_1 + 3) >> 0x19;
    if ((uVar2 & 0x40) != 0) {
      uVar2 = uVar2 | 0xffffff80;
    }
    _mouseDelX = _mouseDelX - uVar2;
    uVar2 = *(uint *)(param_1 + 2) >> 0x19;
    if ((uVar2 & 0x40) != 0) {
      uVar2 = uVar2 | 0xffffff80;
    }
    _mouseDelY = _mouseDelY - uVar2;
  }
  *(undefined4 *)(_evg + 0x14) = 0;
  return uVar2;
}
