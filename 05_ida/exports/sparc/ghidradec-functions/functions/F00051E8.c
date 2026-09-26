
void _set_auxioreg(byte param_1,int param_2)

{
  if (param_2 == 0) {
    bRamfeff0000 = bRamfeff0000 & ~param_1;
  }
  else {
    bRamfeff0000 = bRamfeff0000 | param_1;
  }
  bRamfeff0000 = bRamfeff0000 | 0xc0;
  return;
}
