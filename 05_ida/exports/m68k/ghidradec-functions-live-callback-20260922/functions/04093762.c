
void _mon_call(undefined4 param_1)

{
  _adb_watchdog(0);
  _boot_action = param_1;
  __m68k_trap(0xd);
  _adb_watchdog(1);
  return;
}

