/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010ad3c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _inittodr(uint param_1)

{
  uint uVar1;
  int iVar2;
  int local_14 [2];
  uint local_c;
  undefined4 local_8;
  
  if ((param_1 < 0x1ff46b80) || ((int)param_1 < 0)) {
    _printf(s_WARNING__preposterous_time_in_fi_001daad6);
    goto LAB_0010ae97;
  }
  _microtime(&local_c);
  _boottime = local_c;
  _DAT_001e97ac = 0;
  uVar1 = local_c - param_1;
  if ((int)uVar1 < 0) {
    uVar1 = -uVar1;
  }
  if ((uVar1 < 0x2a300) && ((int)param_1 < (int)local_c)) {
    _DAT_001e97ac = 0;
    return;
  }
  if (local_c < 0x1e13380) {
    _printf(s_WARNING__clock_not_set_properly_001dab00);
    local_c = param_1;
    local_8 = 0;
    iVar2 = _suser();
    if (iVar2 != 0) {
      _getthetime(local_14);
      _boottime = _boottime + (local_c - local_14[0]);
LAB_0010ae5b:
      _DAT_001e97ac = 0;
      _host_set_time(DAT_001e97b4,local_c,local_8);
    }
  }
  else {
    if (uVar1 < 0x76a701) {
      _printf(s_WARNING__clock_lost__d_days_001dab4e,uVar1 / 0x15180);
      goto LAB_0010ae97;
    }
    _printf(s_WARNING__preposterous_time_in_Re_001dab20);
    local_c = param_1;
    local_8 = 0;
    iVar2 = _suser();
    if (iVar2 != 0) {
      _getthetime(local_14);
      _boottime = _boottime + (local_c - local_14[0]);
      goto LAB_0010ae5b;
    }
  }
  _boottime = local_c;
  _DAT_001e97ac = local_8;
LAB_0010ae97:
  _printf(s____CHECK_AND_RESET_THE_DATE__001dab6a);
  return;
}

