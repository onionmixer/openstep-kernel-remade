
void _snd_device_set_parms(uint param_1)

{
  if ((param_1 & 2) == 0) {
    _gpflags = _gpflags | 0x10;
  }
  else {
    _gpflags = _gpflags & 0xffffffef;
  }
  if ((param_1 & 1) == 0) {
    _gpflags = _gpflags & 0xfffffff7;
  }
  else {
    _gpflags = _gpflags | 8;
  }
  if (_gpflags != byte_40C6CED) {
    sub_40800CC();
    sub_4080388();
  }
  return;
}

