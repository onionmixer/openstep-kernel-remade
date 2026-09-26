
void sub_4096F96(int param_1,uint param_2)

{
  _bzero(param_1,0x1c);
  *(uint *)(param_1 + 8) = param_2;
  *(uint *)(param_1 + 0x18) = _page_size / param_2;
  return;
}
