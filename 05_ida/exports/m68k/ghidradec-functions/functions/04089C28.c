
void _vidSetBrightness(undefined4 param_1)

{
  if (dword_40B2282 != -1) {
    (*(code *)(&DAT_40b22a8)[dword_40B2282 * 0xb])(param_1);
  }
  return;
}
