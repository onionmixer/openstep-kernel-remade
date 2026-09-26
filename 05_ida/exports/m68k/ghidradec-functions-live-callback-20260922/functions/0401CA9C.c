
undefined4 _nb_grow_bot(int param_1,sword param_2)

{
  *(sword *)(param_1 + 8) = param_2 + *(sword *)(param_1 + 8);
  return 0;
}

