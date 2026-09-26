
void _vidInterruptDisable(void)

{
  if (dword_40B2282 != -1) {
    dword_40B2286 = 0;
    dword_40B5188 = 0;
  }
  return;
}

