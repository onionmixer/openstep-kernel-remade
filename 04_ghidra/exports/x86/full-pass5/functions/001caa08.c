/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001caa08 */

void FUN_001caa08(uint ****param_1,int param_2)

{
  uint ****ppppuVar1;
  uint ***pppuVar2;
  uint ****ppppuVar3;
  uint ****ppppuVar4;
  uint ***local_8;
  
  pppuVar2 = (uint ***)_current_thread_EXTERNAL();
  ppppuVar3 = (uint ****)&DAT_001e551c;
  do {
    if (ppppuVar3[4] == pppuVar2) goto LAB_001caa42;
    ppppuVar3 = (uint ****)ppppuVar3[5];
  } while (ppppuVar3 != (uint ****)0x0);
  ppppuVar3 = (uint ****)FUN_001ca960(pppuVar2);
LAB_001caa42:
  ppppuVar4 = (uint ****)*ppppuVar3;
  while (param_1 != ppppuVar4) {
    if (ppppuVar4 == (uint ****)0x0) {
      return;
    }
    if (((uint)ppppuVar4 & 1) == 0) {
      if (ppppuVar4 <= &local_8) {
        __NXLogError("Exception handlers were not properly removed.");
                    /* WARNING: Subroutine does not return */
        _abort();
      }
      ppppuVar4 = (uint ****)ppppuVar4[0x12];
    }
    else {
      ppppuVar4 = (uint ****)ppppuVar3[1][((int)((int)ppppuVar4 - 1U) / 2) * 3];
    }
  }
  if (ppppuVar4 != (uint ****)0x0) {
    ppppuVar4 = ppppuVar3;
    if (param_2 == 0) {
      __NXLogError("Exception handlers were not properly removed.");
    }
    do {
      ppppuVar1 = (uint ****)*ppppuVar4;
      if (((uint)ppppuVar1 & 1) == 0) {
        if (param_2 == 0) {
          *ppppuVar4 = ppppuVar1[0x12];
          local_8 = (uint ***)ppppuVar4;
        }
        else {
          local_8 = (uint ***)(ppppuVar1 + 0x12);
        }
      }
      else {
        local_8 = ppppuVar3[1] + ((int)((int)ppppuVar1 - 1U) / 2) * 3;
        if (param_2 == 0) {
          if (param_1 != ppppuVar1) {
            (*(code *)local_8[1])(local_8[2],1,0,0);
          }
          ppppuVar3[3] = (uint ***)(((int)local_8 - (int)ppppuVar3[1]) * -0x55555555 >> 2);
        }
        else if (param_1 != ppppuVar1) goto LAB_001cab3d;
        *ppppuVar4 = (uint ***)*local_8;
        local_8 = (uint ***)ppppuVar4;
      }
LAB_001cab3d:
      ppppuVar4 = (uint ****)local_8;
    } while (param_1 != ppppuVar1);
  }
  return;
}

