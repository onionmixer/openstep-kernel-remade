/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010349c */

void _hardclock(undefined4 param_1,uint param_2)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  int local_14 [2];
  int local_c [2];
  
  iVar3 = _active_threads;
  if ((param_2 & 3) == 3) {
    if ((*_active_u != 0) && (_active_u[0x97] != 0)) {
      puVar1 = (uint *)(*_active_u + 0x28);
      *puVar1 = *puVar1 | 0x200000;
      _need_ast = _need_ast | 0x20;
    }
    if ((_active_u[0x86] != 0) || (_active_u[0x87] != 0)) {
      iVar2 = _itimerdecr(_active_u + 0x84,_tick);
      if (iVar2 == 0) {
        _psignal(*_active_u,(char *)0x1a);
      }
    }
  }
  if ((*_active_u != 0) && (-1 < *(char *)(iVar3 + 0x4c))) {
    if (_active_u[0x99] != 0x7fffffff) {
      _thread_read_times(iVar3,local_c,local_14);
      if ((int)_active_u[0x99] < local_14[0] + local_c[0] + 1) {
        _psignal(*_active_u,(char *)0x18);
        if ((int)_active_u[0x99] < (int)_active_u[0x9a]) {
          _active_u[0x99] = _active_u[0x99] + 5;
        }
      }
    }
    if ((_active_u[0x8a] != 0) || (_active_u[0x8b] != 0)) {
      iVar3 = _itimerdecr(_active_u + 0x88,_tick);
      if (iVar3 == 0) {
        _psignal(*_active_u,(char *)0x1b);
      }
    }
  }
  _gatherstats(param_1,param_2);
  return;
}

