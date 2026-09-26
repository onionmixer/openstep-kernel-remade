
undefined8 _callout_remove(int param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined *puVar6;
  undefined *puVar7;
  char in_XF;
  
  iVar3 = 0;
  puVar7 = _softint_tail;
  puVar6 = _softint_head;
  do {
    piVar2 = *(int **)puVar6;
    piVar5 = *(int **)puVar6;
    while (piVar1 = piVar2, piVar1 != (int *)0x0) {
      if ((param_1 == piVar1[1]) && (param_2 == piVar1[2])) {
        if (piVar1 == *(int **)puVar6) {
          *(int *)puVar6 = *piVar1;
          piVar5 = (int *)0x0;
        }
        else {
          *piVar5 = *piVar1;
        }
        if (piVar1 == *(int **)puVar7) {
          *(int **)puVar7 = piVar5;
        }
        *piVar1 = (int)_softint_free;
        uVar4 = 1;
        _softint_free = piVar1;
        goto loc_4094034;
      }
      piVar5 = piVar1;
      piVar2 = (int *)*piVar1;
    }
    puVar7 = (undefined *)((int)puVar7 + 4);
    puVar6 = (undefined *)((int)puVar6 + 4);
    iVar3 = iVar3 + 1;
    if (5 < iVar3) {
      uVar4 = 0;
loc_4094034:
      return CONCAT44(uVar4,(int)(sword)(word)(byte)(in_XF << 4 | (param_2 < 0) << 3 |
                                                    (param_2 == 0) << 2));
    }
  } while( true );
}

