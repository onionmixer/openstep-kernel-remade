
void _vidclose(void)

{
  _ev_unregister_screen(dword_40B5184);
  dword_40B5184 = 0;
  return;
}
