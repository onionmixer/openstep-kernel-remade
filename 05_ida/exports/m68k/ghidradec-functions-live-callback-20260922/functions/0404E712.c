
void _ns_time_to_timeval(uint param_1,undefined4 param_2,undefined4 *param_3)

{
  int *piVar1;
  qword qVar2;
  
  piVar1 = param_3 + 1;
  qVar2 = CONCAT44(param_1 % 1000000000,param_2);
  *piVar1 = (int)(qVar2 % 1000000000);
  *param_3 = (int)(qVar2 / 1000000000);
  *piVar1 = *piVar1 / 1000;
  return;
}

