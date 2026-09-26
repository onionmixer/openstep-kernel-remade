
undefined4
_ns_abstimeout(undefined4 param_1,undefined4 param_2,uint param_3,uint param_4,undefined4 param_5)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined2 extraout_D0u;
  undefined2 uVar4;
  undefined4 in_D0;
  uint uVar5;
  uint *puVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  char cVar10;
  char cVar11;
  char cVar12;
  char cVar13;
  byte bVar14;
  undefined8 uVar15;
  
  puVar3 = _ns_callfree;
  uVar4 = (undefined2)((uint)in_D0 >> 0x10);
  if (_ns_callfree == (undefined4 *)0x0) {
                    /* WARNING: Subroutine does not return */
    _panic(aNsAbstimeoutTa);
  }
  puVar1 = _ns_callfree + 5;
  _ns_callfree = (undefined4 *)*_ns_callfree;
  *puVar1 = param_5;
  puVar3[3] = param_2;
  puVar3[4] = param_1;
  puVar1 = &_ns_calltodo;
  for (puVar2 = _ns_calltodo; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {
    uVar8 = puVar2[1];
    uVar4 = (undefined2)(uVar8 - (((uint)puVar2[2] < param_4) + param_3) >> 0x10);
    if (param_3 <= uVar8 && ((uint)puVar2[2] >= param_4 || uVar8 != param_3)) break;
    puVar1 = puVar2;
  }
  *puVar1 = puVar3;
  *puVar3 = puVar2;
  puVar3[1] = param_3;
  puVar3[2] = param_4;
  cVar13 = puVar3 < _ns_calltodo;
  cVar12 = SBORROW4((int)puVar3,(int)_ns_calltodo);
  cVar10 = (int)puVar3 - (int)_ns_calltodo < 0;
  cVar11 = '\0';
  bVar14 = cVar13;
  if (puVar3 == _ns_calltodo) {
    uVar15 = _clock_value(1);
    uVar5 = (uint)((qword)uVar15 >> 0x20);
    uVar7 = (uint)uVar15;
    uVar8 = 0;
    uVar9 = 0;
    if (uVar5 < param_3 || uVar7 < param_4 && uVar5 == param_3) {
      uVar9 = param_4 - uVar7;
      uVar8 = param_3 - ((param_4 < uVar7) + uVar5);
    }
    puVar6 = (uint *)_timer_attributes(0);
    uVar5 = *puVar6;
    cVar13 = uVar5 < uVar8 || puVar6[1] < uVar9 && uVar5 == uVar8;
    if (uVar5 < uVar8 || puVar6[1] < uVar9 && uVar5 == uVar8) {
      puVar6 = (uint *)_timer_attributes(0);
      uVar8 = *puVar6;
      uVar9 = puVar6[1];
    }
    cVar10 = '\0';
    cVar11 = '\x01';
    cVar12 = '\0';
    bVar14 = 0;
    __set_timer(0,uVar8,uVar9);
    uVar4 = extraout_D0u;
  }
  return CONCAT22(uVar4,(word)(byte)(cVar13 << 4 | cVar10 << 3 | cVar11 << 2 | cVar12 << 1 | bVar14)
                 );
}

