
void _ttydevstart(int param_1)

{
  if (*(code **)(param_1 + 0x24) != (code *)0x0) {
    (**(code **)(param_1 + 0x24))(param_1);
  }
  return;
}

