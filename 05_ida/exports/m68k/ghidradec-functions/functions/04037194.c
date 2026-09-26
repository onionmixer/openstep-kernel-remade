
void _disksort_enter_head(int param_1,int param_2)

{
  sub_4036D3E(param_1);
  if (*(char *)(param_1 + 0xc) < '\0') {
    (*dword_40C1088)(param_1,param_2);
  }
  else {
    *(undefined4 *)(param_2 + 0x3c) = 0x1f;
    sub_4036F96(param_1,param_2);
  }
  return;
}
