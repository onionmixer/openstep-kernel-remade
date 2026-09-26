/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010ac34 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _setthetime(int *param_1)

{
  int iVar1;
  int local_c [2];
  
  iVar1 = _suser();
  if (iVar1 != 0) {
    _getthetime(local_c);
    _boottime = _boottime + (*param_1 - local_c[0]);
    _DAT_001e97ac = 0;
    _host_set_time(DAT_001e97b4,*param_1,param_1[1]);
  }
  return;
}

