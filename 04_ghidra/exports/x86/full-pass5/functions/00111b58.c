/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00111b58 */

int * _ttynty(int param_1)

{
  undefined4 uVar1;
  int *piVar2;
  int *piVar3;
  
  uVar1 = _spltty();
  if (param_1 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(s_ttynty_0__001dafdb);
  }
  piVar2 = (int *)&DAT_001e56c4;
  piVar3 = DAT_001e56c4;
  if (DAT_001e56c4 != (int *)0x0) {
    do {
      if (*piVar3 == param_1) break;
      piVar2 = piVar3 + 1;
      piVar3 = (int *)piVar3[1];
    } while (piVar3 != (int *)0x0);
    if (piVar3 != (int *)0x0) {
      *piVar2 = piVar3[1];
      goto LAB_00111bd3;
    }
  }
  piVar3 = (int *)_kalloc(0x18);
  *piVar3 = param_1;
  piVar3[4] = 0x1c251a1c;
  *(undefined1 *)(piVar3 + 5) = 0x5c;
  *(undefined1 *)((int)piVar3 + 0x15) = 1;
  *(undefined1 *)((int)piVar3 + 0x16) = 0;
  piVar3[2] = 0;
  piVar3[3] = 0;
LAB_00111bd3:
  piVar3[1] = (int)DAT_001e56c4;
  DAT_001e56c4 = piVar3;
  _splx(uVar1);
  return piVar3;
}

