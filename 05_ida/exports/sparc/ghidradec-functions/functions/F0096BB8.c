
void _spltty(void)

{
  int in_TL;
  
  if ((*(uint *)((uint)(in_TL == 1) * 0x7000 + (uint)(in_TL == 2) * 0x7004 +
                 (uint)(in_TL == 3) * 0x7008 + (uint)(in_TL == 4) * 0x700c) & 0xf00) < 0x900) {
    return;
  }
  return;
}
