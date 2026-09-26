/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00166a8c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _thread_init(void)

{
  _thread_zone = _zinit(0x18c,0x31800,0x6300,0,s_threads_001dfbdc);
  _DAT_001f6c08 = 0;
  _DAT_001f6c24 = 2;
  _DAT_001f6c28 = 0;
  _DAT_001f6c2c = 0;
  _DAT_001f6c30 = 0;
  _DAT_001f6c3c = 0;
  _DAT_001f6c44 = 0;
  _DAT_001f6c48 = 0;
  _DAT_001f6c4c = 0x102;
  _DAT_001f6c34 = _thread_bootstrap_return;
  _DAT_001f6c38 = 0;
  _DAT_001f6c54 = 0x12;
  _DAT_001f6c5c = 0;
  _DAT_001f6c60 = 1;
  _DAT_001f6c64 = 0xffffffff;
  _DAT_001f6c68 = 0;
  _DAT_001f6c6c = 0;
  _DAT_001f6c74 = 0;
  _DAT_001f6c78 = 0;
  _DAT_001f6c7c = 0;
  _DAT_001f6c80 = 0;
  _DAT_001f6c88 = 0xffffffff;
  _DAT_001f6c8c = 1;
  _timer_init(&DAT_001f6ce0);
  _timer_init(&DAT_001f6cf0);
  _DAT_001f6d00 = 0;
  _DAT_001f6d04 = 0;
  _DAT_001f6d08 = 0;
  _DAT_001f6d0c = 0;
  _DAT_001f6d10 = 0;
  _DAT_001f6d14 = 0;
  _DAT_001f6d78 = 0;
  _DAT_001f6d7c = 0;
  _DAT_001f6d84 = 0;
  _DAT_001f6d88 = 0;
  _initKernelStacks();
  DAT_001e979c = &_reaper_queue;
  _reaper_queue = &_reaper_queue;
  _reaper_lock = 0;
  _stack_usage_lock = 0;
  _pcb_module_init();
  return;
}

