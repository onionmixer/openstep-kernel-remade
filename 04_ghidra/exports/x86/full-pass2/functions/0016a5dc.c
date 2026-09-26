/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016a5dc */

void _zcram(int *param_1,int *param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  
  if (param_2 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    _panic(s_zcram___memory_at_zero_001dfcfe);
  }
  uVar2 = param_1[7];
  if ((*(byte *)(param_1 + 0xb) & 1) == 0) {
    iVar4 = _splhigh();
    do {
      do {
      } while (*param_1 != 0);
      LOCK();
      iVar1 = *param_1;
      *param_1 = 1;
      UNLOCK();
    } while (iVar1 == 1);
    param_1[1] = iVar4;
  }
  else {
    _lock_write(param_1 + 0xc);
  }
  do {
    if (param_3 < uVar2) {
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
    piVar3 = (int *)param_1[3];
    if ((piVar3 == (int *)0x0) || (param_2 <= piVar3)) {
      piVar3 = param_1 + 4;
    }
    do {
      piVar5 = piVar3;
      piVar3 = (int *)*piVar5;
      if (piVar3 == (int *)0x0) break;
    } while (piVar3 < param_2);
    *param_2 = (int)piVar3;
    *piVar5 = (int)param_2;
    param_1[3] = (int)param_2;
    param_1[2] = param_1[2];
    param_3 = param_3 - uVar2;
    param_2 = (int *)((int)param_2 + uVar2);
    param_1[5] = param_1[5] + uVar2;
  } while( true );
}

