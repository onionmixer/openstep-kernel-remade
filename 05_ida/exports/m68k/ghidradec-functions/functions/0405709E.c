
void sub_405709E(int *param_1)

{
  _kfree(*param_1,~_page_mask & _page_mask + (param_1[2] - *param_1));
  param_1[1] = 0;
  param_1[2] = 0;
  *param_1 = 0;
  return;
}
