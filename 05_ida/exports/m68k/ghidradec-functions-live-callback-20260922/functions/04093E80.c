
uint _callout_dispatch(uint param_1,code *param_2,uint param_3)

{
  int *piVar1;
  undefined4 *puVar2;
  byte bVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  uint uVar6;
  char cVar7;
  char cVar8;
  char cVar9;
  char cVar10;
  byte bVar11;
  
  puVar4 = _softint_free;
  if (5 < param_1) {
    _printf(aCalloutDispatc,param_1,param_2,param_3);
                    /* WARNING: Subroutine does not return */
    _panic(aCalloutDispatc_0);
  }
  if (param_1 == 5) {
    uVar6 = (*param_2)(param_3);
  }
  else {
    piVar1 = (int *)(_softint_head + param_1 * 4);
    for (puVar2 = (undefined4 *)*piVar1; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2
        ) {
      if (param_2 == (code *)puVar2[1]) {
        uVar6 = puVar2[2];
        cVar10 = param_3 < uVar6;
        cVar9 = SBORROW4(param_3,uVar6);
        cVar7 = (int)(param_3 - uVar6) < 0;
        cVar8 = '\x01';
        bVar11 = cVar10;
        if (param_3 == uVar6) goto loc_4093FAA;
      }
    }
    if (_softint_free == (undefined4 *)0x0) {
                    /* WARNING: Subroutine does not return */
      _panic(aOutOfSoftints);
    }
    puVar2 = (undefined4 *)(_softint_tail + param_1 * 4);
    if (*piVar1 == 0) {
      puVar5 = (undefined4 *)*_softint_free;
      *puVar2 = _softint_free;
      _softint_free = puVar5;
      *piVar1 = (int)puVar4;
      if (param_1 == 2) {
        _vidInterruptEnable(_softint_run,2);
      }
    }
    else {
      puVar5 = (undefined4 *)*_softint_free;
      *(undefined4 **)*puVar2 = _softint_free;
      _softint_free = puVar5;
      *puVar2 = puVar4;
    }
    *puVar4 = 0;
    puVar4[1] = param_2;
    puVar4[2] = param_3;
    if (param_1 == 3) {
      cVar9 = '\0';
      bVar11 = 0;
      bVar3 = *(byte *)(_slot_id_bmap + 0x2008000) | 2;
      *(byte *)(_slot_id_bmap + 0x2008000) = bVar3;
      cVar7 = (int)((uint)bVar3 << 0x18) < 0;
      cVar8 = bVar3 == 0;
      cVar10 = '\0';
    }
    else if ((int)param_1 < 4) {
      cVar10 = 1 < param_1;
      cVar9 = SBORROW4(1,param_1);
      cVar7 = (int)(1 - param_1) < 0;
      cVar8 = param_1 == 1;
      bVar11 = cVar10;
      if ((int)param_1 < 2) {
        cVar9 = '\0';
        bVar11 = 0;
        cVar7 = (int)param_1 < 0;
        cVar8 = param_1 == 0;
        if (!(bool)cVar7) {
          cVar10 = (param_1 + 1 >> 8 & 1) != 0;
          uVar6 = (param_1 + 1) * 0x1000000 | *_scr2;
          *_scr2 = uVar6;
          cVar7 = (int)uVar6 < 0;
          cVar8 = uVar6 == 0;
          cVar9 = '\0';
          bVar11 = 0;
        }
      }
    }
    else {
      cVar10 = 4 < param_1;
      cVar9 = SBORROW4(4,param_1);
      cVar7 = (int)(4 - param_1) < 0;
      if (param_1 == 4) {
        cVar7 = '\0';
        cVar8 = '\x01';
        cVar9 = '\0';
        bVar11 = 0;
        _callout_dispatch(0,_thread_wakeup,_softint_thread);
      }
      else {
        cVar8 = '\0';
        bVar11 = cVar10;
      }
    }
loc_4093FAA:
    uVar6 = (uint)(byte)(cVar10 << 4 | cVar7 << 3 | cVar8 << 2 | cVar9 << 1 | bVar11);
  }
  return uVar6;
}

