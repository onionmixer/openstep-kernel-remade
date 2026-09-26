
void _ShowWaitCursor(void)

{
  *(undefined4 *)(_evg + 0x40) = 1;
  sub_406A9D4(1);
  _waitFrameTime = _waitFrameRate + 1;
  _waitSusTime = _waitSustain;
  return;
}
