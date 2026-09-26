
void _dsp_dev_init(void)

{
  dword_40C6D18 = _slot_id + 0x20000d0;
  dword_40C6D28 = 5;
  dword_40C6D10 = 0;
  dword_40C6E84 = 0;
  dword_40C6E7C = 0;
  dword_40C6E80 = 0;
  dword_40C6E5E = 0;
  _dspq_init_lmsg();
  sub_40826E6(0);
  return;
}

