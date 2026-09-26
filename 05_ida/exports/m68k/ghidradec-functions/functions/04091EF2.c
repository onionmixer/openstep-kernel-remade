
void _m68k_hardclock(void)

{
  uint uVar1;
  bool bVar2;
  sqword sVar3;
  
  _clock_interrupt(_tick,((word)((word)_hardclock_ps ^ 0x2000) & 0x3fff) >> 0xd,
                   -(int)-((_hardclock_ps & 0x700) == 0));
  _hardclock(_hardclock_pc,_hardclock_ps);
  bVar2 = CARRY4(dword_40C2448,dword_40B55B8);
  dword_40B55B8 = dword_40C2448 + dword_40B55B8;
  dword_40B55B4 = _ns_per_tick + dword_40B55B4 + (uint)bVar2;
  while( true ) {
    sVar3 = _clock_value(1);
    uVar1 = (uint)((qword)sVar3 >> 0x20);
    bVar2 = (uint)sVar3 < dword_40B55B8;
    if ((uVar1 < dword_40B55B4 || bVar2 && uVar1 == dword_40B55B4) ||
        sVar3 == CONCAT44(bVar2 + dword_40B55B4,dword_40B55B8)) break;
    bVar2 = CARRY4(dword_40C2448,dword_40B55B8);
    dword_40B55B8 = dword_40C2448 + dword_40B55B8;
    dword_40B55B4 = _ns_per_tick + dword_40B55B4 + (uint)bVar2;
  }
  _ns_abstimeout(_m68k_hardclock,0,dword_40B55B4,dword_40B55B8,1);
  return;
}
