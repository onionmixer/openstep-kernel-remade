
int _firstsect(int param_1)

{
  if ((param_1 == 0) || (*(int *)(param_1 + 0x30) == 0)) {
    param_1 = 0;
  }
  else {
    param_1 = param_1 + 0x38;
  }
  return param_1;
}
