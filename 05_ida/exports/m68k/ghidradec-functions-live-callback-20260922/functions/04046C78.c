
undefined4 _convert_port_type(uint param_1)

{
  undefined4 uVar1;
  
  param_1 = param_1 & 0x1f0000;
  if (param_1 == 0x30000) {
loc_4046CC2:
    uVar1 = 7;
  }
  else {
    if (param_1 < 0x30001) {
      if (param_1 != 0x10000) {
        if (param_1 != 0x20000) goto loc_4046CCA;
        goto loc_4046CC2;
      }
    }
    else {
      if (param_1 == 0x80000) {
        return 9;
      }
      if (param_1 < 0x80001) {
        if (param_1 != 0x40000) {
loc_4046CCA:
                    /* WARNING: Subroutine does not return */
          _panic(aConvertPortTyp);
        }
      }
      else if (param_1 != 0x100000) goto loc_4046CCA;
    }
    uVar1 = 1;
  }
  return uVar1;
}

