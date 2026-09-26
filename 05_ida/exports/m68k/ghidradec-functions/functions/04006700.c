
void _switch_unix_context(int param_1)

{
  dword_40B57D4 = *(undefined4 *)(param_1 + 0x80);
  _active_u = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x30);
  return;
}
