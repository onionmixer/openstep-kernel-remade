
void _dbg_from_ether(int param_1)

{
  if ((dword_40C9474 != 0) && (*(int *)(param_1 + 0x2e) == 0x11)) {
    _dbg_connect_pkt = param_1;
    dword_40B562C = 1;
    __m68k_trap(0xf);
  }
  return;
}

