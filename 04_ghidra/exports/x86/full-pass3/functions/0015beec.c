/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015beec */

undefined4 _host_set_time(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    uVar2 = 0x16;
  }
  else {
    uVar2 = _splhigh();
    puVar1 = _mtime;
    _time = param_2;
    DAT_001dee3c = param_3;
    if (_mtime != (undefined4 *)0x0) {
      _mtime[2] = param_2;
      puVar1[1] = DAT_001dee3c;
      *puVar1 = _time;
    }
    _set_calendar_time_value(&_time);
    _splx(uVar2);
    uVar2 = 0;
  }
  return uVar2;
}

