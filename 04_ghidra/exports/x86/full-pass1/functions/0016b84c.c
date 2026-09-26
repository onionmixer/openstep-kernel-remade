/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016b84c */

void _zfree(int *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  
  if ((*(byte *)(param_1 + 0xb) & 1) == 0) {
    iVar3 = _splhigh();
    do {
      do {
      } while (*param_1 != 0);
      LOCK();
      iVar1 = *param_1;
      *param_1 = 1;
      UNLOCK();
    } while (iVar1 == 1);
    param_1[1] = iVar3;
  }
  else {
    _lock_write(param_1 + 0xc);
  }
  if (_zone_check != 0) {
    for (piVar2 = (int *)param_1[4]; piVar2 != (int *)0x0; piVar2 = (int *)*piVar2) {
      if (piVar2 == param_2) {
                    /* WARNING: Subroutine does not return */
        _panic(s_zfree_001dfd7c);
      }
    }
  }
  piVar2 = (int *)param_1[3];
  if ((piVar2 == (int *)0x0) || (param_2 <= piVar2)) {
    piVar2 = param_1 + 4;
  }
  do {
    piVar4 = piVar2;
    piVar2 = (int *)*piVar4;
    if (piVar2 == (int *)0x0) break;
  } while (piVar2 < param_2);
  *param_2 = (int)piVar2;
  *piVar4 = (int)param_2;
  param_1[3] = (int)param_2;
  param_1[2] = param_1[2] + -1;
  if ((*(byte *)(param_1 + 0xb) & 1) == 0) {
    LOCK();
    *param_1 = 0;
    UNLOCK();
    _splx(param_1[1]);
  }
  else {
    _lock_done(param_1 + 0xc);
  }
  return;
}

