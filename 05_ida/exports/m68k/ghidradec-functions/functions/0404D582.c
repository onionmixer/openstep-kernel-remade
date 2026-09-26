
void _vmp_get(int param_1)

{
  if (*(char *)(param_1 + 0x34) < '\0') {
    _vm_info_dequeue(param_1);
  }
  *(sword *)(param_1 + 6) = *(sword *)(param_1 + 6) + 1;
  _lock_write(param_1 + 0x18);
  return;
}
