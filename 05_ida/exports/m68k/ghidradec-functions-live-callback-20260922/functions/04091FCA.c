
byte _clock_timer_init(void)

{
  char cVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  _startrtclock();
  dword_40B55AC = 0;
  dword_40B55B0 = 0;
  uVar2 = _rtc_get();
  _time = SUB84((qword)uVar2 >> 0x20,0);
  dword_40AF7F0 = (undefined4)uVar2;
  uVar2 = _timeval_to_ns_time(_time);
  uVar3 = _clock_value(1);
  dword_40B55B0 = (uint)uVar2 - (uint)uVar3;
  dword_40B55AC =
       (int)((qword)uVar2 >> 0x20) -
       ((uint)((uint)uVar2 < (uint)uVar3) + (int)((qword)uVar3 >> 0x20));
  cVar1 = _dma_chip < 0x139;
  if (_dma_chip == 0x139) {
    *_scr2 = *_scr2 & 0xffff7fff;
  }
  _install_scanned_intr(0x1d60,sub_4091E18,0);
  *_timer_csr = 0;
  *_timer_low = 0xff;
  *_timer_high = 0xff;
  *_timer_low = 0xff;
  *_timer_csr = 0xc0;
  *_timer_low = 0xff;
  *_timer_high = 0xff;
  return cVar1 << 4 | 8;
}

