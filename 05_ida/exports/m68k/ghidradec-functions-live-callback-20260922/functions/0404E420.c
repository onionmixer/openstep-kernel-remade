
void _ns_hardclock_init(void)

{
  dword_40C2448 = 1000000000 / _hz;
  _ns_per_tick = (int)-(dword_40C2448 < 0);
  _hardclock_init(_ns_per_tick,dword_40C2448);
  return;
}

