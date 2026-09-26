
void sub_4053F9C(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined8 uVar7;
  
  uVar7 = _clock_value(1);
  uVar6 = (uint)((qword)uVar7 >> 0x20);
  uVar4 = (uint)uVar7;
  if (*(uint *)(param_1 + 0x14) < uVar6 ||
      *(uint *)(param_1 + 0x18) < uVar4 && *(uint *)(param_1 + 0x14) == uVar6) {
    uVar6 = 0;
    uVar5 = 0;
  }
  else {
    puVar3 = (uint *)_timer_attributes(0);
    uVar1 = *puVar3;
    uVar2 = puVar3[1];
    uVar5 = *(uint *)(param_1 + 0x18) - uVar4;
    uVar6 = *(int *)(param_1 + 0x14) - ((*(uint *)(param_1 + 0x18) < uVar4) + uVar6);
    if ((uVar1 <= uVar6 && (uVar5 >= uVar2 || uVar6 != uVar1)) &&
        (uVar6 != (uVar5 < uVar2) + uVar1 || uVar5 != uVar2)) {
      uVar6 = uVar1;
      uVar5 = uVar2;
    }
  }
  _set_timer(0,uVar6,uVar5);
  return;
}
