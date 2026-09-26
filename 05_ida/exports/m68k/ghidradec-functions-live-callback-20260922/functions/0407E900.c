
void sub_407E900(int *param_1,int param_2)

{
  *param_1 = (int)(_sd_sdd + param_2 * 0xc2);
  *(int **)(_sd_sdd + param_2 * 0xc2) = param_1;
  param_1[2] = param_1[2] & 0xfffffffe;
  return;
}

