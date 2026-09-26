
void _evinit(void)

{
  _nbic_bus_enable();
  _km_send(0xc5,0xef000000);
  _km_send(0xc5,0);
  _mon_send(0xc6,0x1fffff1);
  _install_scanned_intr(0x23b,sub_40682E2,0);
  _install_scanned_intr(0x1f70,_call_nmi,0);
  if (_dma_chip != 0x139) {
    _install_scanned_intr(0x1e71,_call_nmi,0);
  }
  _install_scanned_intr(0x33a,_evintr,0);
  return;
}

