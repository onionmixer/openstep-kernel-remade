
void _vidSuspendAnimation(void)

{
  if ((dword_40B2282 != -1) && (byte_40B228A == '\0')) {
    (*(&off_40B22B0)[dword_40B2282 * 0xb])();
    byte_40B228A = '\x01';
  }
  return;
}

