
void _process_kbd_event(int param_1)

{
  byte bVar1;
  byte bVar2;
  
  bVar1 = *(byte *)(param_1 + 2) & 0x7f;
  bVar2 = *(byte *)(param_1 + 2) & 0x7f;
  if ((-1 < *(char *)(param_1 + 3)) && (bVar2 != _deviceMods)) {
    _process_device_mods(bVar1);
  }
  if (*(char *)(param_1 + 2) < '\0') {
    _DoKbdEvent(*(byte *)(param_1 + 3) & 0x7f,*(byte *)(param_1 + 3) >> 7 ^ 1,bVar1);
  }
  if ((*(char *)(param_1 + 3) < '\0') && (bVar2 != _deviceMods)) {
    _process_device_mods(bVar1);
  }
  _deviceMods = bVar2;
  return;
}

