
void _enqueue_head(int *param_1,int *param_2)

{
  *param_2 = *param_1;
  param_2[1] = (int)param_1;
  *(int **)(*param_2 + 4) = param_2;
  *param_1 = (int)param_2;
  return;
}

