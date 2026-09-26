
void _init_timers(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined *puVar3;
  
  puVar3 = _kernel_timer;
  puVar1 = &_current_timer;
  do {
    _timer_init(puVar3);
    puVar2 = puVar1 + 1;
    *puVar1 = 0;
    puVar3 = puVar3 + 0x10;
    puVar1 = puVar2;
  } while ((int)puVar2 < 0x40c2b81);
  return;
}

