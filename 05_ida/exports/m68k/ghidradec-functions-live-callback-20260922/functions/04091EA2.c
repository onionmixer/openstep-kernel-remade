
void _hardclock_init(void)

{
  sqword sVar1;
  
  sVar1 = _clock_value(1);
  sVar1 = sVar1 + CONCAT44(_ns_per_tick,dword_40C2448);
  dword_40B55B8 = (undefined4)sVar1;
  dword_40B55B4 = (undefined4)((qword)sVar1 >> 0x20);
  _ns_abstimeout(_m68k_hardclock,0,sVar1,1);
  return;
}

