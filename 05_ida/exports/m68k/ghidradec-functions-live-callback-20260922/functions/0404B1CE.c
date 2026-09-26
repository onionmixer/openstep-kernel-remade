
undefined4 _host_get_time(int param_1,int *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = _mtime;
  if (param_1 == 0) {
    uVar2 = 0x16;
  }
  else {
    do {
      *param_2 = *piVar1;
      param_2[1] = piVar1[1];
    } while (*param_2 != piVar1[2]);
    uVar2 = 0;
  }
  return uVar2;
}

