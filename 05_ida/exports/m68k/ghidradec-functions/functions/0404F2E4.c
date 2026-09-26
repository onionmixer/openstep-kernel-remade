
void _pset_reference(int param_1)

{
  *(int *)(param_1 + 0x13c) = *(int *)(param_1 + 0x13c) + 1;
  return;
}
