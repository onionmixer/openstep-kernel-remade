
void _scsi_attach(int param_1)

{
  _scsi_ndevices = _scsi_ndevices + 1;
  (**(code **)(*(int *)(param_1 + 0x14) + 0xe))(param_1);
  if (dword_40B4FCA == 0) {
    dword_40B4FCE = _hz;
    if (_hz < 0) {
      dword_40B4FCE = _hz + 1;
    }
    dword_40B4FCE = dword_40B4FCE >> 1;
    dword_40B4FCA = 1;
    sub_407C2F4();
  }
  return;
}

