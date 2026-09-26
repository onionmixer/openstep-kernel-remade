
undefined4 _ureadc(undefined4 param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  
  while( true ) {
    if (param_2[1] == 0) {
                    /* WARNING: Subroutine does not return */
      _panic(&aUreadc);
    }
    piVar1 = (int *)*param_2;
    if ((0 < piVar1[1]) && (0 < *(int *)((int)param_2 + 0x12))) break;
    param_2[1] = param_2[1] + -1;
    *param_2 = *param_2 + 8;
  }
  iVar2 = param_2[3];
  if (iVar2 == 1) {
    *(char *)*piVar1 = (char)param_1;
  }
  else {
    if (iVar2 < 2) {
      if (iVar2 != 0) goto loc_4009B68;
      iVar2 = _subyte(*piVar1,param_1);
    }
    else {
      if (iVar2 != 2) goto loc_4009B68;
      iVar2 = _suibyte(*piVar1,param_1);
    }
    if (iVar2 < 0) {
      return 0xe;
    }
  }
loc_4009B68:
  *piVar1 = *piVar1 + 1;
  piVar1[1] = piVar1[1] + -1;
  *(int *)((int)param_2 + 0x12) = *(int *)((int)param_2 + 0x12) + -1;
  param_2[2] = param_2[2] + 1;
  return 0;
}
