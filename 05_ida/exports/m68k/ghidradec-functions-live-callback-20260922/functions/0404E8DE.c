
void _get_calendar_time_value(undefined4 *param_1)

{
  int *piVar1;
  qword qVar2;
  undefined8 uVar3;
  
  uVar3 = _clock_value(0);
  piVar1 = param_1 + 1;
  qVar2 = CONCAT44((uint)((qword)uVar3 >> 0x20) % 1000000000,(int)uVar3);
  *piVar1 = (int)(qVar2 % 1000000000);
  *param_1 = (int)(qVar2 / 1000000000);
  *piVar1 = *piVar1 / 1000;
  return;
}

