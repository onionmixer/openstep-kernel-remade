
undefined4 sub_404E458(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  sqword sVar8;
  
  sVar8 = _clock_value(1);
  uVar3 = (uint)((qword)sVar8 >> 0x20);
  uVar5 = (uint)sVar8;
  do {
    if (_ns_calltodo == (undefined4 *)0x0) {
loc_404E510:
      puVar4 = (uint *)_timer_attributes(0);
      goto loc_404E518;
    }
    do {
      puVar2 = _ns_calltodo;
      if (uVar3 <= (uint)_ns_calltodo[1] &&
          (uVar5 <= (uint)_ns_calltodo[2] || _ns_calltodo[1] != uVar3)) break;
      if ((code *)_ns_calltodo[4] == _m68k_hardclock) {
        _hardclock_ps = param_3;
        _hardclock_pc = param_2;
      }
      _callout_dispatch(_ns_calltodo[5],_ns_calltodo[4],_ns_calltodo[3]);
      _ns_calltodo = (undefined4 *)*puVar2;
      *puVar2 = _ns_callfree;
      _ns_callfree = puVar2;
    } while (_ns_calltodo != (undefined4 *)0x0);
    if (_ns_calltodo == (undefined4 *)0x0) goto loc_404E510;
    uVar6 = _ns_calltodo[1];
    uVar1 = _ns_calltodo[2];
  } while ((uVar6 <= uVar3 && (uVar5 >= uVar1 || uVar3 != uVar6)) &&
           sVar8 != CONCAT44((uVar5 < uVar1) + uVar6,uVar1));
  uVar7 = uVar1 - uVar5;
  uVar6 = uVar6 - ((uVar1 < uVar5) + uVar3);
  puVar4 = (uint *)_timer_attributes(0);
  if (*puVar4 < uVar6 || puVar4[1] < uVar7 && *puVar4 == uVar6) {
    puVar4 = (uint *)_timer_attributes(0);
loc_404E518:
    uVar6 = *puVar4;
    uVar7 = puVar4[1];
  }
  __set_timer(0,uVar6,uVar7);
  return 0;
}

