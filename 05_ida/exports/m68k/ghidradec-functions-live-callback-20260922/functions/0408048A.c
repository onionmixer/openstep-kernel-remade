
undefined4 _snd_device_attach(void)

{
  dword_40B507C = _slot_id + 0x200e000;
  _mon_csr_and(0xffffff7f);
  _mon_csr_or(0x20);
  _mon_csr_and(0xfffffff7);
  _mon_csr_or(2);
  _mon_send(3,0);
  _mon_send(7,0);
  _mon_send(0xc4,0xff);
  _install_scanned_intr(0x835,_snd_dev_intr,0);
  return 0;
}

