
undefined4 _md_do_shutdown(undefined4 param_1,uint param_2,int param_3)

{
  undefined2 extraout_D0u;
  undefined2 extraout_D0u_00;
  undefined2 extraout_D0u_01;
  undefined2 uVar1;
  undefined3 *puVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  byte bVar7;
  
  if ((param_2 & 0x10000) != 0) {
                    /* WARNING: Subroutine does not return */
    _rtc_power_down();
  }
  cVar3 = '\0';
  cVar4 = '\0';
  cVar6 = '\0';
  bVar7 = 0;
  cVar5 = (param_2 & 8) == 0;
  if ((bool)cVar5) {
    _printf(aRebootingMach);
    if ((param_2 & 0x100000) == 0) {
      puVar2 = (undefined3 *)0x0;
      if ((param_2 & 2) != 0) {
        puVar2 = &aS_5;
      }
      cVar4 = '\0';
      cVar5 = puVar2 == (undefined3 *)0x0;
      cVar6 = '\0';
      bVar7 = 0;
      _mon_boot(puVar2);
      uVar1 = extraout_D0u_01;
    }
    else {
      cVar4 = param_3 < 0;
      cVar5 = param_3 == 0;
      cVar6 = '\0';
      bVar7 = 0;
      _mon_call(param_3);
      uVar1 = extraout_D0u_00;
    }
  }
  else {
    _printf(aHalting);
    _mon_call(&aH);
    uVar1 = extraout_D0u;
  }
  return CONCAT22(uVar1,(word)(byte)(cVar3 << 4 | cVar4 << 3 | cVar5 << 2 | cVar6 << 1 | bVar7));
}

