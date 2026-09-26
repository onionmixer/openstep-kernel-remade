
undefined4 _longjmp(undefined4 *param_1)

{
  *(undefined4 *)param_1[0xc] = *param_1;
  return 1;
}

