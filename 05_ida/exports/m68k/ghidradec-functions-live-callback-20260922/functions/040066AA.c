
void _uarea_init(int param_1)

{
  *(int *)(*(int *)(param_1 + 0x80) + 0x24) = *(int *)(param_1 + 0x80) + 4;
  return;
}

