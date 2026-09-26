
void sub_401CD2C(undefined4 param_1)

{
  undefined4 *puVar1;
  
  for (puVar1 = dword_40B3454; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)puVar1[2]) {
    (*(code *)*puVar1)(puVar1[1],param_1);
  }
  return;
}
