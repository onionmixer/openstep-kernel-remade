
void _km_reset(void)

{
  *(byte *)(_slot_id + 0x200e002) = *(byte *)(_slot_id + 0x200e002) | 1;
  _mon_send(0xc6,0x1000a825);
  _mon_send(0,0);
  _delay(10000);
  return;
}

