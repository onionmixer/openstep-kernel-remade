
int _mclget(int param_1)

{
  undefined4 *puVar1;
  
  if (_mclfree == (undefined4 *)0x0) {
    _m_clalloc(1,1,0);
  }
  puVar1 = _mclfree;
  if (_mclfree != (undefined4 *)0x0) {
    _mclrefcnt[(int)_mclfree - _mbutl >> 10] = _mclrefcnt[(int)_mclfree - _mbutl >> 10] + '\x01';
    dword_40B61BC = dword_40B61BC + -1;
    _mclfree = (undefined4 *)*_mclfree;
    *(undefined2 *)(param_1 + 8) = 0x400;
    *(int *)(param_1 + 4) = (int)puVar1 - param_1;
    *(undefined2 *)(param_1 + 0xc) = 1;
  }
  return -(int)-(puVar1 != (undefined4 *)0x0);
}

