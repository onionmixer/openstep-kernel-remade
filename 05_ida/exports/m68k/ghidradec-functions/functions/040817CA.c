
void _dsp_dev_reset_hard(void)

{
  _dsp_dev_reset_chip();
  _dsp_dev_reset();
  return;
}
