
void _DoAutoDim(void)

{
  if (_dimmedBrightness < _curBright) {
    _SetCurBrightness(_dimmedBrightness);
  }
  _autoDimmed = 1;
  return;
}

