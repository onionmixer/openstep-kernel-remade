
undefined4 _nb_shrink_top(int param_1,int param_2)

{
  *(sword *)(param_1 + 8) = *(sword *)(param_1 + 8) - (sword)param_2;
  *(int *)(param_1 + 4) = param_2 + *(int *)(param_1 + 4);
  return 0;
}
