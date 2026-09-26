
/* WARNING: Removing unreachable block (ram,0xf0069ba4) */
/* WARNING: Removing unreachable block (ram,0xf0069b40) */
/* WARNING: Removing unreachable block (ram,0xf0069b9c) */
/* WARNING: Removing unreachable block (ram,0xf0069b50) */

undefined8 _host_set_time(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = 0x16;
  if (param_1 != 0) {
    _spl6();
    puVar1 = _mtime;
    _time = *param_2;
    DAT_f010fbec = param_2[1];
    if (_mtime != (undefined4 *)0x0) {
      _mtime[2] = _time;
      puVar1[1] = DAT_f010fbec;
      *puVar1 = _time;
    }
    _set_calendar_time_value(&_time);
    _spln(param_1);
    uVar2 = 0;
  }
  return CONCAT44(param_2,uVar2);
}

