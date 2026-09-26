
void _dspq_reset_lmsg(void)

{
  undefined4 *puVar1;
  
  if ((undefined4 **)dword_40C6E46 != &dword_40C6E46) {
    do {
      puVar1 = dword_40C6E46;
      dword_40C6E46 = (undefined4 *)dword_40C6E46[6];
      if ((undefined4 **)dword_40C6E46 == &dword_40C6E46) {
        dword_40C6E4A = &dword_40C6E46;
      }
      else {
        dword_40C6E46[7] = &dword_40C6E46;
      }
      _dspq_free_msg(puVar1);
    } while ((undefined4 **)dword_40C6E46 != &dword_40C6E46);
  }
  if ((undefined4 **)dword_40B5090 != &dword_40B5090) {
    do {
      puVar1 = dword_40B5090;
      dword_40B5090 = (undefined4 *)dword_40B5090[6];
      if ((undefined4 **)dword_40B5090 == &dword_40B5090) {
        dword_40B5094 = &dword_40B5090;
      }
      else {
        dword_40B5090[7] = &dword_40B5090;
      }
      _kfree(puVar1,0xa6);
    } while ((undefined4 **)dword_40B5090 != &dword_40B5090);
  }
  if ((undefined4 **)dword_40B5098 != &dword_40B5098) {
    _dspq_free_msg(0);
  }
  return;
}
