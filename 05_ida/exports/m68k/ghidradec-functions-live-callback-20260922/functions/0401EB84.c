
undefined4 _localetheraddr(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (dword_40AE940 == 0) {
    dword_40AE940 = 1;
    if (param_1 == (undefined4 *)0x0) {
      dword_40AE940 = 1;
      return 0;
    }
    dword_40B3458 = *param_1;
    word_40B345C = *(undefined2 *)(param_1 + 1);
    uVar1 = _ether_sprintf(&dword_40B3458);
    _printf(aEthernetAddres,uVar1);
  }
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = dword_40B3458;
    *(undefined2 *)(param_2 + 1) = word_40B345C;
  }
  return 1;
}

