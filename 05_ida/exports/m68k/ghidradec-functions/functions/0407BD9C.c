
void _scsi_init(void)

{
  if (dword_40B4FDA == 0) {
    dword_40B4FD6 = &dword_40B4FD2;
    dword_40B4FD2 = &dword_40B4FD2;
    dword_40B4FDA = 1;
  }
  return;
}
