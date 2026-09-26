
void _ttylclose(int param_1)

{
  _ttywflush(param_1);
  *(undefined *)(param_1 + 0x45) = 0;
  return;
}
