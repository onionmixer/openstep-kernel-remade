
int _zfree(int *param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  char in_XF;
  bool bVar4;
  
  bVar4 = *(char *)(param_1 + 10) < '\0';
  if (bVar4) {
    _lock_write((int)param_1 + 0x2a);
  }
  else {
    *param_1 = (int)(sword)(word)(byte)(in_XF << 4 | bVar4 << 3 |
                                       (*(char *)(param_1 + 10) == '\0') << 2);
  }
  if (_zone_check != 0) {
    for (piVar1 = (int *)param_1[3]; piVar1 != (int *)0x0; piVar1 = (int *)*piVar1) {
      if (param_2 == piVar1) {
                    /* WARNING: Subroutine does not return */
        _panic(&aZfree);
      }
    }
  }
  piVar1 = (int *)param_1[2];
  if ((piVar1 == (int *)0x0) || (param_2 <= piVar1)) {
    piVar1 = param_1 + 3;
  }
  do {
    piVar3 = piVar1;
    piVar1 = (int *)*piVar3;
    if (piVar1 == (int *)0x0) break;
  } while (piVar1 < param_2);
  *param_2 = (int)piVar1;
  *piVar3 = (int)param_2;
  param_1[2] = (int)param_2;
  param_1[1] = param_1[1] + -1;
  if (*(char *)(param_1 + 10) < '\0') {
    iVar2 = _lock_done((int)param_1 + 0x2a);
  }
  else {
    iVar2 = *param_1;
  }
  return iVar2;
}
