
void _UndoAutoDim(void)

{
  _SetCurBrightness(_curBright);
  _autoDimTime = _autoDimPeriod + *(int *)(_evg + 0x10);
  _autoDimmed = 0;
  return;
}

