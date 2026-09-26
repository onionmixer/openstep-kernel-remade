
void _fp_configure(void)

{
  if ((_boothowto._2_1_ & 0x20) != 0) {
    return;
  }
  _cpu_config = _cpu_config & 0xfc | 2;
  return;
}

