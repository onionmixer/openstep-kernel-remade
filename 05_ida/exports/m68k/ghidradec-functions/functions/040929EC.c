
undefined4 _grade_cpu_subtype(int param_1)

{
  undefined4 uVar1;
  
  if ((param_1 == 1) || (param_1 == -1)) {
    uVar1 = 1;
  }
  else {
    uVar1 = 2;
    if (param_1 != dword_40B5DD0) {
      uVar1 = 0;
    }
  }
  return uVar1;
}
