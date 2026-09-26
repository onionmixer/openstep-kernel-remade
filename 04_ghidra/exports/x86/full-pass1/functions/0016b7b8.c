/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016b7b8 */

int * _zget(int *param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  if (param_1 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    _panic(s_zalloc__null_zone_001dfd63);
  }
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
  piVar2 = (int *)param_1[4];
  if (piVar2 != (int *)0x0) {
    param_1[2] = param_1[2] + 1;
    param_1[4] = *piVar2;
    if ((int *)param_1[3] == piVar2) {
      param_1[3] = 0;
    }
  }
  if ((*(byte *)(param_1 + 0xb) & 1) == 0) {
    LOCK();
    *param_1 = 0;
    UNLOCK();
    _splx(param_1[1]);
  }
  else {
    _lock_done(param_1 + 0xc);
  }
  return piVar2;
}

