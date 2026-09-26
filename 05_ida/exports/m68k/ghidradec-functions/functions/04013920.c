
undefined4 _sosetopt(int param_1,int param_2,int param_3,int param_4)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar2 = param_4;
  uVar3 = 0;
  if (param_2 != 0xffff) {
    if ((*(int *)(param_1 + 0xc) != 0) &&
       (pcVar1 = *(code **)(*(int *)(param_1 + 0xc) + 0x16), pcVar1 != (code *)0x0)) {
      uVar3 = (*pcVar1)(1,param_1,param_2,param_3,&param_4);
      return uVar3;
    }
    goto loc_4013AA2;
  }
  if (param_3 == 0x20) {
loc_40139D6:
    if ((param_4 != 0) && (3 < *(word *)(param_4 + 8))) {
      if (*(int *)(param_4 + *(int *)(param_4 + 4)) == 0) {
        *(word *)(param_1 + 2) = ~(word)param_3 & *(word *)(param_1 + 2);
      }
      else {
        *(word *)(param_1 + 2) = (word)param_3 | *(word *)(param_1 + 2);
      }
      goto loc_4013AA4;
    }
  }
  else {
    if (param_3 < 0x21) {
      if (param_3 != 4) {
        if (param_3 < 5) {
          iVar4 = 1;
        }
        else {
          if (param_3 == 8) goto loc_40139D6;
          iVar4 = 0x10;
        }
        if (iVar4 != param_3) {
loc_4013AA2:
          uVar3 = 0x2a;
          goto loc_4013AA4;
        }
      }
      goto loc_40139D6;
    }
    if (param_3 == 0x100) goto loc_40139D6;
    if (param_3 < 0x101) {
      if (param_3 != 0x40) {
        if (param_3 != 0x80) goto loc_4013AA2;
        if ((param_4 == 0) || (*(sword *)(param_4 + 8) != 8)) goto loc_4013A0C;
        *(undefined2 *)(param_1 + 4) = *(undefined2 *)(param_4 + 6 + *(int *)(param_4 + 4));
      }
      goto loc_40139D6;
    }
    if ((0x1006 < param_3) || (param_3 < 0x1001)) goto loc_4013AA2;
    if ((param_4 != 0) && (3 < *(word *)(param_4 + 8))) {
      switch(param_3) {
      case :
      case :
        if (param_3 == 0x1001) {
          param_1 = param_1 + 0x38;
        }
        else {
          param_1 = param_1 + 0x22;
        }
        iVar4 = _sbreserve(param_1,*(undefined4 *)(param_4 + *(int *)(param_4 + 4)));
        if (iVar4 == 0) {
          uVar3 = 0x37;
        }
        break;
      case :
        *(undefined2 *)(param_1 + 0x40) = *(undefined2 *)(param_4 + 2 + *(int *)(param_4 + 4));
        break;
      case :
        *(undefined2 *)(param_1 + 0x2a) = *(undefined2 *)(param_4 + 2 + *(int *)(param_4 + 4));
        break;
      case :
        *(undefined2 *)(param_1 + 0x42) = *(undefined2 *)(param_4 + 2 + *(int *)(param_4 + 4));
        break;
      case :
        *(undefined2 *)(param_1 + 0x2c) = *(undefined2 *)(param_4 + 2 + *(int *)(param_4 + 4));
      }
      goto loc_4013AA4;
    }
  }
loc_4013A0C:
  uVar3 = 0x16;
loc_4013AA4:
  if (iVar2 != 0) {
    _m_free(iVar2);
  }
  return uVar3;
}
