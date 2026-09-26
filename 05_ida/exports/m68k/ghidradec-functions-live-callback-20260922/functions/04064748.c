
void _adb_force_NMI(void)

{
  if (_dma_chip != 0x139) {
    _adb_watchdog(0);
    *(uint *)(_slot_id + 0x2200020) = *(uint *)(_slot_id + 0x2200020) | 1;
    _delay(8000);
    _adb_watchdog(1);
  }
  return;
}

