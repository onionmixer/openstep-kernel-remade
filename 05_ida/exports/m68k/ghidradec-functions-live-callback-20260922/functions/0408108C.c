
void _dsp_dev_reset(void)

{
  if (dword_40C6E72 != 0) {
    dword_40C6E6A = 0;
    dword_40C6E6E = 0;
    _dspq_free_msg(dword_40C6E72);
  }
  dword_40C6E76 = 0;
  word_40C6E7A = 0;
  dword_40C6E84 = dword_40C6E84 | 0x20000;
  _dsp_dev_new_proto(0);
  _dspq_reset_lmsg();
  sub_40826E6(1);
  _install_scanned_intr(0xe40,sub_40818B4,0);
  return;
}

