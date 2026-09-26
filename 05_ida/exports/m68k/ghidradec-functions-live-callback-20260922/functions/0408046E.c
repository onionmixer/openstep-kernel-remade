
int _snd_device_probe(int param_1,int param_2)

{
  if (param_2 == 0) {
    param_1 = _slot_id + param_1;
  }
  else {
    param_1 = 0;
  }
  return param_1;
}

