
void _vidStopAnimation(void)

{
  *(byte *)(_mon_global + 4) = *(byte *)(_mon_global + 4) & 0xf7;
  if (dword_40B2286 != 0) {
    _vidResumeAnimation();
  }
  _delay(100000);
  return;
}

