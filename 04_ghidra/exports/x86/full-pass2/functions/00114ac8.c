/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00114ac8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _mcldup(int param_1,int param_2,int param_3)

{
  int *piVar1;
  
  if (*(short *)(param_1 + 0xc) == 1) {
    param_1 = param_1 + *(int *)(param_1 + 4);
    *(int *)(param_2 + 4) = param_1 - param_2;
    *(undefined2 *)(param_2 + 0xc) = 1;
    (&_mclrefcnt)[param_1 - __mbutl >> 10] = (&_mclrefcnt)[param_1 - __mbutl >> 10] + '\x01';
  }
  else {
    if (*(short *)(param_1 + 0xc) != 2) {
                    /* WARNING: Subroutine does not return */
      _panic(s_mcldup_001db220);
    }
    piVar1 = (int *)_kalloc(*(short *)(param_2 + 8) + 4);
    *piVar1 = *(short *)(param_2 + 8) + 4;
    _bcopy((void *)(param_1 + *(int *)(param_1 + 4) + param_3),piVar1 + 1,
           (int)*(short *)(param_2 + 8));
    *(int *)(param_2 + 4) = (int)piVar1 + (-param_3 - (param_2 + -4));
    *(undefined2 *)(param_2 + 0xc) = 2;
    *(code **)(param_2 + 0x10) = FUN_00114b78;
    *(int **)(param_2 + 0x14) = piVar1;
    *(undefined4 *)(param_2 + 0x18) = 0;
  }
  return;
}

