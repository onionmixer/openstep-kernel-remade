
void _reconpoll(void)

{
  if (_sound_active == 0) {
    _mon_send(0xc6,0x1fffff1);
  }
  _timeout(_reconpoll,0,_hz * 3);
  return;
}
