
void _process_adb_event(int param_1)

{
  _DoKbdEvent(*(byte *)(param_1 + 3) & 0x7f,*(byte *)(param_1 + 3) >> 7 ^ 1,
              *(byte *)(param_1 + 2) & 0x7f);
  return;
}
