
bool _reset_timeout(int param_1)

{
  bool bVar1;
  
  bVar1 = *(int *)(param_1 + 0x2c) != 0;
  if (bVar1) {
    _calloutEntryRemove(param_1);
    *(undefined4 *)(param_1 + 0x2c) = 0;
  }
  return bVar1;
}

