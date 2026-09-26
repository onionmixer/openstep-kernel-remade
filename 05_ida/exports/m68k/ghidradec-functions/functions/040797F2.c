
void _od_spiral(void)

{
  word *pwVar1;
  undefined *puVar2;
  undefined *puVar3;
  
  puVar2 = _od_drive;
  puVar3 = unk_40C3E36;
  pwVar1 = &word_40C3E30;
  do {
    if ((*puVar3 == -1) && ((*(byte *)(*(int *)((int)puVar2 + 8) + 0xd8) & 0x20) != 0)) {
      _od_cmd((*(int *)((int)puVar2 + 8) + -0x40c3ec8) * 0x69b02594 & 0xfffffff8,0xf3,0,0,0,0,0,0,0,
              0);
      *pwVar1 = *pwVar1 & 0xdfff;
      *puVar3 = '\0';
    }
    puVar3 = puVar3 + 0x20;
    pwVar1 = pwVar1 + 0x10;
    puVar2 = (undefined *)((int)puVar2 + 0x20);
  } while (puVar2 < &_od_empty);
  _thread_terminate(_active_threads);
  _thread_halt_self();
  return;
}
