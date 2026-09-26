
undefined4 _inferior(int param_1)

{
  while( true ) {
    if (*_active_u == param_1) {
      return 1;
    }
    if (*(sword *)(param_1 + 0x32) == 0) break;
    param_1 = *(int *)(param_1 + 0x42);
  }
  return 0;
}
