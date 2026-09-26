
void _configure(void)

{
  _nbic_configure();
  _intr_mask = _intr_mask | 0x38003;
  *_intrmask = *_intrmask | 0x18003;
  sub_4065C02(_bus_cinit,_bus_dinit);
  _setconf();
  _swapconf();
  return;
}
