
void _lock_sleepable(int param_1,byte param_2)

{
  *(uint *)(param_1 + 6) = *(uint *)(param_1 + 6) & 0xefffffff | (param_2 & 1) << 0x1c;
  return;
}
