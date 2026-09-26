
void _tty_ld_remove(int param_1)

{
  int iVar1;
  
  if ((-1 < param_1) && (param_1 < _nldisp)) {
    iVar1 = param_1 * 0x30;
    (&_linesw)[param_1 * 0xc] = _nodev;
    *(code **)(unk_40AE4B0 + iVar1) = _nodev;
    *(code **)(unk_40AE4B0 + iVar1 + 4) = _nodev;
    *(code **)(unk_40AE4B0 + iVar1 + 8) = _nodev;
    *(code **)(unk_40AE4B0 + iVar1 + 0xc) = _nodev;
    *(code **)(unk_40AE4B0 + iVar1 + 0x10) = _nodev;
    *(code **)(unk_40AE4B0 + iVar1 + 0x14) = _nodev;
    *(code **)(unk_40AE4B0 + iVar1 + 0x1c) = _nodev;
    *(code **)(unk_40AE4B0 + iVar1 + 0x20) = _nodev;
    *(code **)(unk_40AE4B0 + iVar1 + 0x24) = _nodev;
  }
  return;
}

