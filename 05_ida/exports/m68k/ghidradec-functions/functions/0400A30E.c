
void _setthetime(int *param_1)

{
  int iVar1;
  int aiStack_c [2];
  
  iVar1 = _suser();
  if (iVar1 != 0) {
    _getthetime(aiStack_c);
    _boottime = (*param_1 - aiStack_c[0]) + _boottime;
    dword_40B67D4 = 0;
    _host_set_time(dword_40B67DC,*param_1,param_1[1]);
  }
  return;
}
