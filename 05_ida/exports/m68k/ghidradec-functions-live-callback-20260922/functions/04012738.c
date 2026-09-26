
void _mclput(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if (*(sword *)(param_1 + 0xc) == 1) {
    puVar3 = (undefined4 *)(*(int *)(param_1 + 4) + param_1 & 0xfffffc00);
    iVar2 = (int)puVar3 - _mbutl >> 10;
    cVar1 = _mclrefcnt[iVar2];
    _mclrefcnt[iVar2] = cVar1 + -1;
    if (cVar1 == '\x01') {
      *puVar3 = _mclfree;
      dword_40B61BC = dword_40B61BC + 1;
      _mclfree = puVar3;
    }
  }
  else {
    if (*(sword *)(param_1 + 0xc) != 2) {
                    /* WARNING: Subroutine does not return */
      _panic(&aMclput);
    }
    (**(code **)(param_1 + 0xe))(*(undefined4 *)(param_1 + 0x12));
  }
  return;
}

