
void sub_4038D12(int param_1,int param_2)

{
  int iVar1;
  
  if (param_2 != 0) {
    iVar1 = *(int *)(param_1 + 0x18);
    if (iVar1 == 0) {
      *(int *)(param_1 + 0x18) = param_2;
    }
    else {
      for (; *(int *)(iVar1 + 0x18) != 0; iVar1 = *(int *)(iVar1 + 0x18)) {
      }
      *(int *)(iVar1 + 0x18) = param_2;
    }
  }
  return;
}
