
void _m68k_dbginit(void)

{
  int iVar1;
  
  iVar1 = _get_vbr();
  dword_40B5620 = *(undefined4 *)(iVar1 + 0xbc);
  *(code **)(iVar1 + 0xbc) = __dbg_trap;
  _dbg_kresume();
  _adb_watchdog(0);
  _dbg_process(_dbg_connect_pkt);
  _adb_watchdog(1);
  return;
}

