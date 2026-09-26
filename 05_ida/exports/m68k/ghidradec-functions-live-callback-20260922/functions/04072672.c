
void _nbic_configure(void)

{
  int iVar1;
  
  iVar1 = _nbic_bus_enable();
  if (iVar1 != 0) {
    iVar1 = _probe_rl(0xf0fffff0);
    if (iVar1 != 0) {
      _nbic_present = 1;
      _printf(aNbicPresent);
      if ((_machine_type == '\0') || (_machine_type == '\x02')) {
        uRam02020004 = 0x80000000;
        uRam02020000 = 0x8000000;
      }
    }
  }
  return;
}

