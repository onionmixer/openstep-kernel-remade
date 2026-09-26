
uint _snd_device_get_volume(void)

{
  return 0x2bU - _vol_r | (0x2b - _vol_l) * 0x100;
}
