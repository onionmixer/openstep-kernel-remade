/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00124e10 */

undefined4 _in_pcballoc(int param_1,int *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = (int *)_kalloc(0x40);
  if (piVar1 == (int *)0x0) {
    uVar2 = 0x37;
  }
  else {
    _bzero(piVar1,0x40);
    piVar1[2] = (int)param_2;
    piVar1[7] = param_1;
    *piVar1 = *param_2;
    piVar1[1] = (int)param_2;
    *(int **)(*param_2 + 4) = piVar1;
    *param_2 = (int)piVar1;
    *(int **)(param_1 + 8) = piVar1;
    uVar2 = 0;
  }
  return uVar2;
}

