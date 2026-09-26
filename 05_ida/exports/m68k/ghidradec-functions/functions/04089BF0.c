
void _vidResumeAnimation(void)

{
  if ((dword_40B2282 != -1) && (byte_40B228A != '\0')) {
    (*(&off_40B22B4)[dword_40B2282 * 0xb])();
    byte_40B228A = '\0';
  }
  return;
}
