
void sub_402935A(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    if (param_1 == piVar1) {
      _rpfreelist = (int *)0x0;
    }
    else {
      if (param_1 == _rpfreelist) {
        _rpfreelist = piVar1;
      }
      *(int *)param_1[1] = *param_1;
      *(int *)(*param_1 + 4) = param_1[1];
    }
    param_1[1] = 0;
    *param_1 = 0;
    _rnfree = _rnfree + -1;
  }
  return;
}
