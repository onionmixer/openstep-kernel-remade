
void _adb_watchdog(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(_slot_id + 0x2208018);
  if (param_1 == 1) {
    dword_40B4E8E = dword_40B4E8E + -1;
  }
  if (dword_40B4E8E < 0) {
    dword_40B4E8E = 0;
  }
  if ((_dma_chip != 0x139) && (dword_40B4E8E == 0)) {
    *(undefined4 *)(_slot_id + 0x2208020) = 0x10;
    if (param_1 == 1) {
      if (dword_40B0834 != 0) {
        *puVar1 = 3;
      }
    }
    else {
      *puVar1 = 0;
    }
  }
  if (param_1 == 0) {
    dword_40B4E8E = dword_40B4E8E + 1;
  }
  return;
}

