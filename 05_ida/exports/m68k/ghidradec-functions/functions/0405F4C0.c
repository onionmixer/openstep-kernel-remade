
void _vm_map_lookup_done(undefined4 param_1,int param_2)

{
  if (*(char *)(param_2 + 0x18) < '\0') {
    _lock_done(*(undefined4 *)(param_2 + 0x10));
  }
  _lock_done(param_1);
  return;
}
