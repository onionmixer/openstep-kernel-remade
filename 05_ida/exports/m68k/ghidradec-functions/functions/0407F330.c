
void sub_407F330(int param_1)

{
  if (*(uint *)(param_1 + 4) < dword_40B2084) {
    *(word *)(param_1 + 10) = *(word *)(param_1 + 10) & 0xff7f;
  }
  else {
    sub_407E8B8(param_1);
  }
  return;
}
