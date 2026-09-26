
void _thread_init(void)

{
  _thread_zone = _zinit(0x184,0x30800,0x6100,0,&aThreads);
  dword_40C29E8 = 0;
  dword_40C2A00 = 2;
  dword_40C2A04 = 0;
  dword_40C2A08 = 0;
  dword_40C2A0C = 0;
  dword_40C2A18 = 0;
  dword_40C2A20 = 0;
  dword_40C2A24 = 0;
  dword_40C2A28 = 0x102;
  dword_40C2A10 = _thread_bootstrap_return;
  dword_40C2A14 = 0;
  dword_40C2A30 = 0x12;
  dword_40C2A38 = 0;
  dword_40C2A3C = 1;
  dword_40C2A40 = 0xffffffff;
  dword_40C2A44 = 0;
  dword_40C2A48 = 0;
  dword_40C2A50 = 0;
  dword_40C2A54 = 0;
  dword_40C2A58 = 0;
  dword_40C2A5C = 0;
  dword_40C2A64 = 0xffffffff;
  dword_40C2A68 = 1;
  _timer_init(unk_40C2AB8);
  _timer_init(unk_40C2AC8);
  dword_40C2AD8 = 0;
  dword_40C2ADC = 0;
  dword_40C2AE0 = 0;
  dword_40C2AE4 = 0;
  dword_40C2AE8 = 0;
  dword_40C2AEC = 0;
  dword_40C2B50 = 0;
  dword_40C2B54 = 0;
  dword_40C2B5C = 0;
  dword_40C2B60 = 0;
  _initKernelStacks();
  dword_40B67C4 = &_reaper_queue;
  _reaper_queue = &_reaper_queue;
  _pcb_module_init();
  return;
}

