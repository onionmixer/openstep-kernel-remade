/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015bf58 */

undefined4 _host_adjust_time(int param_1,int param_2,int param_3,int *param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  if (param_1 == 0) {
    uVar1 = 0x16;
  }
  else {
    uVar4 = param_2 * 1000000 + param_3;
    uVar1 = _splhigh();
    iVar2 = (int)_timedelta / 1000000;
    iVar3 = (int)_timedelta % 1000000;
    if (_timedelta == 0) {
      if (_bigadj < uVar4) {
        _tickdelta = _tickadj * 10;
      }
      else {
        _tickdelta = _tickadj;
      }
    }
    if (uVar4 % _tickdelta != 0) {
      uVar4 = (uVar4 / _tickdelta) * _tickdelta;
    }
    _timedelta = uVar4;
    _splx(uVar1);
    *param_4 = iVar2;
    param_4[1] = iVar3;
    uVar1 = 0;
  }
  return uVar1;
}

