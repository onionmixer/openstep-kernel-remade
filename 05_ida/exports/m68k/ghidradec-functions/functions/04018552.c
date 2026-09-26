
void sub_4018552(int param_1,int param_2)

{
  if (*(int *)(param_1 + 0x40) != 0) {
    sub_4018584(param_1);
  }
  *(sword *)(param_2 + 6) = *(sword *)(param_2 + 6) + 1;
  *(int *)(param_1 + 0x40) = param_2;
  return;
}
