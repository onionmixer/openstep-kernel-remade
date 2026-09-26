
void _bytecopy(undefined *param_1,undefined *param_2,sword param_3)

{
  param_3 = param_3 + -1;
  do {
    *param_2 = *param_1;
    param_3 = param_3 + -1;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
  } while (param_3 != -1);
  return;
}

