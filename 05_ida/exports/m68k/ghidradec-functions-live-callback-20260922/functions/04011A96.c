
undefined4 _syselect(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (*(int *)(_active_u + 0x15e) == 0) {
    *(undefined *)(dword_40B57D4 + 100) = 6;
    uVar1 = 0;
  }
  else {
    uVar1 = (*(code *)(&DAT_40b0adc)[(uint)(*(word *)(_active_u + 0x162) >> 8) * 0xb])
                      ((int)(sword)*(word *)(_active_u + 0x162),param_2);
  }
  return uVar1;
}

