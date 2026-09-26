
void _snd_device_set_volume(uint param_1)

{
  _vol_l = 0x2b - ((param_1 & 0xffff) >> 8);
  _vol_r = 0x2b - (param_1 & 0xff);
  sub_40800CC();
  sub_4080388();
  return;
}

