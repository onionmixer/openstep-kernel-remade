
void _kmputc(undefined4 param_1,int param_2)

{
  if ((unk_40B6904 & 8) != 0) {
    if ((unk_40B6904 & 1) == 0) {
      _kminit();
    }
    if (param_2 == 10) {
      _kmpaint(0xd);
    }
    _kmpaint(param_2);
  }
  return;
}

