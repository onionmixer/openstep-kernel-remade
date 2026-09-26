/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00169f44 */

void FUN_00169f44(void)

{
  uint uVar1;
  bool bVar2;
  int ****ppppiVar3;
  undefined4 uVar4;
  uint *puVar5;
  int ***pppiVar6;
  int ***pppiVar7;
  uint uVar8;
  uint uVar9;
  undefined8 uVar10;
  int ***local_c;
  int ***local_8;
  
  uVar10 = _clock_value(1);
  pppiVar6 = (int ***)((ulonglong)uVar10 >> 0x20);
  local_c = (int ***)&local_c;
  local_8 = local_c;
  uVar4 = _splsched();
  do {
  } while (DAT_001e7244 != 0);
  LOCK();
  DAT_001e7244 = 1;
  UNLOCK();
  if ((int *****)DAT_001e7258 != &DAT_001e7258) {
    do {
      ppppiVar3 = DAT_001e7258;
      if ((pppiVar6 < DAT_001e7258[6]) ||
         ((pppiVar6 == DAT_001e7258[6] && ((int ***)uVar10 < DAT_001e7258[5])))) break;
      (*DAT_001e7258)[1] = (int **)DAT_001e7258[1];
      *ppppiVar3[1] = (int **)*ppppiVar3;
      ppppiVar3[7] = (int ***)0x0;
      *ppppiVar3 = (int ***)&local_c;
      ppppiVar3[1] = local_8;
      *ppppiVar3[1] = (int **)ppppiVar3;
      local_8 = (int ***)ppppiVar3;
    } while ((int *****)DAT_001e7258 != &DAT_001e7258);
    ppppiVar3 = DAT_001e7258;
    if ((int *****)DAT_001e7258 != &DAT_001e7258) {
      uVar10 = _clock_value(1);
      pppiVar7 = (int ***)((ulonglong)uVar10 >> 0x20);
      pppiVar6 = (int ***)uVar10;
      if ((ppppiVar3[6] < pppiVar7) || ((pppiVar7 == ppppiVar3[6] && (ppppiVar3[5] < pppiVar6)))) {
        uVar9 = 0;
        uVar8 = 0;
      }
      else {
        puVar5 = (uint *)_timer_attributes(0);
        uVar1 = puVar5[1];
        uVar8 = (int)ppppiVar3[5] - (int)pppiVar6;
        uVar9 = (int)ppppiVar3[6] + (-(uint)(ppppiVar3[5] < pppiVar6) - (int)pppiVar7);
        if ((uVar1 < uVar9) || ((uVar1 == uVar9 && (*puVar5 < uVar8)))) {
          uVar9 = uVar1;
          uVar8 = *puVar5;
        }
      }
      _set_timer(0,uVar8,uVar9);
    }
  }
  while (pppiVar6 = local_c, ppppiVar3 = (int ****)local_c, &local_c != (int ****)local_c) {
    (*local_c)[1] = (int *)&local_c;
    ppppiVar3 = (int ****)*local_c;
    if ((int ****)local_c == (int ****)0x0) break;
    *local_c = (int **)&DAT_001e7250;
    local_c = (int ***)ppppiVar3;
    pppiVar6[1] = (int **)DAT_001e7254;
    *pppiVar6[1] = (int *)pppiVar6;
    DAT_001e7254 = (int ****)pppiVar6;
    DAT_001e7260 = DAT_001e7260 + 1;
    pppiVar6[7] = (int **)0x1;
    bVar2 = DAT_001e7268 < DAT_001e7264 + DAT_001e7260;
    LOCK();
    DAT_001e7244 = 0;
    UNLOCK();
    _thread_wakeup_prim(&DAT_001e7260,1,0);
    if (bVar2) {
      _thread_wakeup_prim(&DAT_001e7268,1,0);
    }
    do {
    } while (DAT_001e7244 != 0);
    LOCK();
    UNLOCK();
  }
  local_c = (int ***)ppppiVar3;
  LOCK();
  DAT_001e7244 = 0;
  UNLOCK();
  _splx(uVar4);
  return;
}

