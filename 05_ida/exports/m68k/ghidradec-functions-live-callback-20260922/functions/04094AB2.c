
undefined4
_machine_exception(int param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
                  undefined4 *param_5)

{
  undefined4 uVar1;
  
  if (param_1 == 3) {
    uVar1 = 8;
loc_4094AEA:
    *param_4 = uVar1;
    *param_5 = param_2;
    uVar1 = 1;
  }
  else {
    if (param_1 < 4) {
      if (param_1 == 2) {
        uVar1 = 4;
        goto loc_4094AEA;
      }
    }
    else if (param_1 == 4) {
      uVar1 = 7;
      goto loc_4094AEA;
    }
    uVar1 = 0;
  }
  return uVar1;
}

