
uint * _bread(undefined4 param_1,undefined4 param_2,int param_3)

{
  uint *puVar1;
  
  _bstats = _bstats + 1;
  if (param_3 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aBreadSize0);
  }
  puVar1 = (uint *)_getblk(param_1,param_2,param_3);
  if ((*puVar1 & 2) == 0) {
    *puVar1 = *puVar1 | 1;
    if ((int)puVar1[6] < (int)puVar1[5]) {
                    /* WARNING: Subroutine does not return */
      _panic(&aBread);
    }
    (**(code **)(*(int *)(puVar1[0x10] + 0x1c) + 0x54))(puVar1);
    *(int *)(_active_u + 0x192) = *(int *)(_active_u + 0x192) + 1;
    _biowait(puVar1);
  }
  else {
    dword_40B6B50 = dword_40B6B50 + 1;
  }
  return puVar1;
}

