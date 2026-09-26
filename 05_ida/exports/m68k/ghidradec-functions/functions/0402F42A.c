
undefined4 * sub_402F42A(int param_1,int param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = (undefined4 *)0x0;
  for (puVar2 = dword_40B3596;
      (puVar2 != (undefined4 *)0x0 && ((param_1 != puVar2[1] || (param_2 != puVar2[2]))));
      puVar2 = (undefined4 *)*puVar2) {
    puVar1 = puVar2;
  }
  *param_3 = puVar1;
  return puVar2;
}
