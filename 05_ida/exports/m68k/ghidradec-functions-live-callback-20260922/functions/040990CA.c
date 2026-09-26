
void _md_shutdown_devices(undefined4 param_1,uint param_2)

{
  if ((_machine_type == '\0') || (_machine_type == '\x02')) {
    _od_update();
    if (((param_2 & 0x80000) != 0) && (_kernel_task != 0)) {
      _od_eject();
    }
  }
  return;
}

