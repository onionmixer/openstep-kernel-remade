
void _space_deallocate(int param_1)

{
  if (param_1 != 0) {
    _ipc_space_release(param_1);
  }
  return;
}

