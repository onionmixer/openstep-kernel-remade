
int * _ttynty(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  if (param_1 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aTtynty0);
  }
  piVar2 = (int *)&dword_40B3180;
  piVar1 = dword_40B3180;
  if (dword_40B3180 != (int *)0x0) {
    do {
      if (param_1 == *piVar1) break;
      piVar2 = piVar1 + 1;
      piVar1 = (int *)*piVar2;
    } while (piVar1 != (int *)0x0);
    if (piVar1 != (int *)0x0) {
      *piVar2 = piVar1[1];
      goto loc_4010116;
    }
  }
  piVar1 = (int *)_kalloc(0x18);
  *piVar1 = param_1;
  piVar1[4] = 0x1c251a1c;
  *(undefined *)(piVar1 + 5) = 0x5c;
  *(undefined *)((int)piVar1 + 0x15) = 1;
  *(undefined *)((int)piVar1 + 0x16) = 0;
  piVar1[2] = 0;
  piVar1[3] = 0;
loc_4010116:
  piVar1[1] = (int)dword_40B3180;
  dword_40B3180 = piVar1;
  return piVar1;
}
