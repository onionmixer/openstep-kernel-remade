
undefined4 sub_408BC84(void)

{
  undefined4 uVar1;
  
  if ((_machine_type == '\0') && (_board_rev < 3)) {
    if (_board_rev == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  else {
    uVar1 = 2;
  }
  return uVar1;
}

