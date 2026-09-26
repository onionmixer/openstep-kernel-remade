
void sub_4028A8C(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  sub_40287C4(*param_1);
  _clntkudp_freecred(param_1);
  *param_1 = 0;
  puVar1 = &_chtable;
  while( true ) {
    if (&_chtable + _MAXCLIENTS * 3 <= puVar1) {
      (**(code **)(param_1[1] + 0x10))(param_1);
      return;
    }
    if (param_1 == (undefined4 *)puVar1[2]) break;
    puVar1 = puVar1 + 3;
  }
  puVar1[1] = 0;
  return;
}
