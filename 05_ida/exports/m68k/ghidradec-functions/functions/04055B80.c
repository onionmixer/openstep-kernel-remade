
int * _zget(int *param_1)

{
  int *piVar1;
  char in_XF;
  bool bVar2;
  
  if (param_1 != (int *)0x0) {
    bVar2 = *(char *)(param_1 + 10) < '\0';
    if (bVar2) {
      _lock_write((int)param_1 + 0x2a);
    }
    else {
      *param_1 = (int)(sword)(word)(byte)(in_XF << 4 | bVar2 << 3 |
                                         (*(char *)(param_1 + 10) == '\0') << 2);
    }
    piVar1 = (int *)param_1[3];
    if (piVar1 != (int *)0x0) {
      param_1[1] = param_1[1] + 1;
      param_1[3] = *piVar1;
      if (piVar1 == (int *)param_1[2]) {
        param_1[2] = 0;
      }
    }
    if (*(char *)(param_1 + 10) < '\0') {
      _lock_done((int)param_1 + 0x2a);
    }
    return piVar1;
  }
                    /* WARNING: Subroutine does not return */
  _panic(aZallocNullZone);
}
