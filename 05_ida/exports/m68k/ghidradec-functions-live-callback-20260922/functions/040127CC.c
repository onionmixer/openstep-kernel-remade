
void _mcldup(int param_1,int param_2,int param_3)

{
  int *piVar1;
  
  if (*(sword *)(param_1 + 0xc) == 1) {
    param_1 = *(int *)(param_1 + 4) + param_1;
    *(int *)(param_2 + 4) = param_1 - param_2;
    *(undefined2 *)(param_2 + 0xc) = 1;
    _mclrefcnt[param_1 - _mbutl >> 10] = _mclrefcnt[param_1 - _mbutl >> 10] + '\x01';
  }
  else {
    if (*(sword *)(param_1 + 0xc) != 2) {
                    /* WARNING: Subroutine does not return */
      _panic(&aMcldup);
    }
    piVar1 = (int *)_kalloc(*(sword *)(param_2 + 8) + 4);
    *piVar1 = *(sword *)(param_2 + 8) + 4;
    _bcopy(param_3 + *(int *)(param_1 + 4) + param_1,piVar1 + 1,(int)*(sword *)(param_2 + 8));
    *(int *)(param_2 + 4) = (int)piVar1 + (-param_3 - (param_2 + -4));
    *(undefined2 *)(param_2 + 0xc) = 2;
    *(undefined4 *)(param_2 + 0xe) = 0x40127b6;
    *(int **)(param_2 + 0x12) = piVar1;
    *(undefined4 *)(param_2 + 0x16) = 0;
  }
  return;
}

