
void sub_4032B4C(int param_1,int param_2)

{
  if (param_2 == *(int *)(param_1 + 0x3e)) {
    dword_40B35CE = dword_40B35CE + 1;
    *(undefined4 *)(param_1 + 0x3e) = 0xffffffff;
  }
  if (param_2 == *(int *)(param_1 + 0x2c)) {
    dword_40B35D2 = dword_40B35D2 + 1;
    *(undefined4 *)(param_1 + 0x2c) = 0xffffffff;
    *(undefined *)(param_1 + 0x30) = 0;
  }
  return;
}
