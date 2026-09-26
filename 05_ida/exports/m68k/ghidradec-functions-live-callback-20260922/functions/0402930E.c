
void sub_402930E(int *param_1,int param_2)

{
  int *piVar1;
  
  piVar1 = _rpfreelist;
  if (*param_1 != 0) {
    return;
  }
  if (_rpfreelist == (int *)0x0) {
    *param_1 = (int)param_1;
    param_1[1] = (int)param_1;
  }
  else {
    *param_1 = (int)_rpfreelist;
    param_1[1] = piVar1[1];
    *(int **)piVar1[1] = param_1;
    piVar1[1] = (int)param_1;
    if (param_2 == 0) goto loc_402934C;
  }
  _rpfreelist = param_1;
loc_402934C:
  _rnfree = _rnfree + 1;
  return;
}

