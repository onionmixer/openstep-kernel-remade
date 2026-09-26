
void sub_402B03A(undefined4 param_1)

{
  uint uVar1;
  undefined4 auStack_24 [8];
  
  _bcopy(param_1,auStack_24,0x20);
  uVar1 = 0;
  do {
    _printf(&aX,auStack_24[uVar1]);
    uVar1 = uVar1 + 1;
  } while (uVar1 < 8);
  return;
}

