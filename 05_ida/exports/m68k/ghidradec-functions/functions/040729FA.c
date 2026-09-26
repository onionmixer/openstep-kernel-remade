
void _np_serial_timeout(int param_1)

{
  *(byte *)(param_1 + 0x104) = *(byte *)(param_1 + 0x104) | 1;
  _thread_wakeup_prim(param_1 + 0x11b,0,0);
  return;
}
