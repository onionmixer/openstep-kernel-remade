
uint _uwritec(int *param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  
  if (0 < *(int *)((int)param_1 + 0x12)) {
    do {
      if (param_1[1] < 1) {
                    /* WARNING: Subroutine does not return */
        _panic(&aUwritec);
      }
      piVar1 = (int *)*param_1;
      if (piVar1[1] != 0) {
        iVar2 = param_1[3];
        if (iVar2 == 1) {
          uVar3 = (uint)*(byte *)*piVar1;
        }
        else if (iVar2 < 2) {
          if (iVar2 != 0) {
loc_4009C04:
                    /* WARNING: Subroutine does not return */
            _panic(aUwritecBogusUi);
          }
          uVar3 = _fubyte(*piVar1);
        }
        else {
          if (iVar2 != 2) goto loc_4009C04;
          uVar3 = _fuibyte(*piVar1);
        }
        if ((int)uVar3 < 0) {
          return 0xffffffff;
        }
        *piVar1 = *piVar1 + 1;
        piVar1[1] = piVar1[1] + -1;
        *(int *)((int)param_1 + 0x12) = *(int *)((int)param_1 + 0x12) + -1;
        param_1[2] = param_1[2] + 1;
        return uVar3 & 0xff;
      }
      *param_1 = (int)(piVar1 + 2);
      iVar2 = param_1[1];
      param_1[1] = iVar2 + -1;
    } while (iVar2 != 1);
  }
  return 0xffffffff;
}

