/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010a448 */

undefined4 _ureadc(undefined4 param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  
  while( true ) {
    if (param_2[1] == 0) {
                    /* WARNING: Subroutine does not return */
      _panic(s_ureadc_001daa4e);
    }
    piVar1 = (int *)*param_2;
    if ((0 < piVar1[1]) && (0 < param_2[5])) break;
    param_2[1] = param_2[1] + -1;
    *param_2 = *param_2 + 8;
  }
  iVar2 = param_2[3];
  if (iVar2 == 1) {
    *(char *)*piVar1 = (char)param_1;
  }
  else {
    if (iVar2 < 2) {
      if (iVar2 != 0) goto LAB_0010a4c0;
      iVar2 = _subyte(*piVar1,param_1);
    }
    else {
      if (iVar2 != 2) goto LAB_0010a4c0;
      iVar2 = _suibyte(*piVar1,param_1);
    }
    if (iVar2 < 0) {
      return 0xe;
    }
  }
LAB_0010a4c0:
  *piVar1 = *piVar1 + 1;
  piVar1[1] = piVar1[1] + -1;
  param_2[5] = param_2[5] + -1;
  param_2[2] = param_2[2] + 1;
  return 0;
}

