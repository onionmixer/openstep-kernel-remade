
void _bdwrite(int param_1)

{
  if ((*(byte *)(param_1 + 2) & 2) == 0) {
    *(int *)(_active_u + 0x196) = *(int *)(_active_u + 0x196) + 1;
  }
  *(word *)(param_1 + 2) = *(word *)(param_1 + 2) | 0x202;
  _brelse(param_1);
  return;
}

