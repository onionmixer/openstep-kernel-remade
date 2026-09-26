
void _mon_reset(void)

{
  if (dword_40B1BCA == 0) {
    uRam0200e000 = 0x200;
    dword_40B1BCA = 1;
  }
  return;
}

