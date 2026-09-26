
void sub_40287C4(int *param_1)

{
  undefined *puVar1;
  
  if ((*param_1 < 2) && (-1 < *param_1)) {
    for (puVar1 = _unixauthtab; puVar1 < _unixauthtab + _MAXCLIENTS * 6;
        puVar1 = (undefined *)((int)puVar1 + 6)) {
      if (param_1 == *(int **)((int)puVar1 + 2)) {
        *(undefined2 *)puVar1 = 0;
        return;
      }
    }
    (**(code **)(param_1[8] + 0x10))(param_1);
  }
  else {
    _printf(aAuthfreeUnknow,*param_1);
  }
  return;
}
