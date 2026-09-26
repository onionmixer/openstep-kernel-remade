
undefined4 _nb_shrink_bot(int param_1,sword param_2)

{
  *(sword *)(param_1 + 8) = *(sword *)(param_1 + 8) - param_2;
  return 0;
}
