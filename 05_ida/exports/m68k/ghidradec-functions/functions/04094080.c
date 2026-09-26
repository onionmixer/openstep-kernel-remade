
void _softint_run(int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int unaff_D2;
  int *piVar6;
  code *unaff_D3;
  int *piVar7;
  int *piVar8;
  
  if (_nmi_big != 0) {
    _nmi_big = 0;
    _callout_dispatch(4,_km_big,0);
  }
  switch(param_1) {
  case :
  case :
    *_scr2 = ~((param_1 + 1) * 0x1000000) & *_scr2;
  case :
  case :
    piVar7 = (int *)(_softint_head + param_1 * 4);
    while( true ) {
      piVar6 = (int *)*piVar7;
      if (piVar6 != (int *)0x0) {
        unaff_D3 = (code *)piVar6[1];
        unaff_D2 = piVar6[2];
        *piVar7 = *piVar6;
        *piVar6 = (int)_softint_free;
        _softint_free = piVar6;
        if (*piVar7 == 0) {
          *(undefined4 *)(_softint_tail + param_1 * 4) = 0;
        }
      }
      if (piVar6 == (int *)0x0) break;
      (*unaff_D3)(unaff_D2);
    }
    break;
  case :
    piVar8 = (int *)(_softint_head + param_1 * 4);
    puVar2 = (undefined4 *)(_softint_tail + param_1 * 4);
    piVar6 = (int *)*piVar8;
    piVar7 = (int *)*puVar2;
    *puVar2 = 0;
    *piVar8 = 0;
    piVar1 = piVar6;
    piVar4 = (int *)0x0;
    while (piVar3 = piVar1, piVar3 != (int *)0x0) {
      iVar5 = (*(code *)piVar3[1])(piVar3[2]);
      if (iVar5 == 0) {
        if (piVar4 == (int *)0x0) {
          piVar6 = (int *)*piVar3;
          if (piVar6 == (int *)0x0) {
            piVar7 = (int *)0x0;
          }
        }
        else {
          *piVar4 = *piVar3;
          if (piVar3 == piVar7) {
            piVar7 = piVar4;
          }
        }
        piVar1 = (int *)*piVar3;
        *piVar3 = (int)_softint_free;
        _softint_free = piVar3;
      }
      else {
        piVar1 = (int *)*piVar3;
        piVar4 = piVar3;
      }
    }
    if (*piVar8 == 0) {
      *piVar8 = (int)piVar6;
      *puVar2 = piVar7;
    }
    else {
      *piVar7 = *piVar8;
      *piVar8 = (int)piVar6;
    }
  }
  return;
}
