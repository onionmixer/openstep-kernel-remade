
void sub_402A990(int param_1,undefined4 param_2)

{
  undefined *puVar1;
  
  puVar1 = (undefined *)sub_402A934(*(undefined *)(param_1 + 4),param_2);
  *puVar1 = 0x2e;
  puVar1 = (undefined *)sub_402A934(*(undefined *)(param_1 + 5),puVar1 + 1);
  *puVar1 = 0x2e;
  puVar1 = (undefined *)sub_402A934(*(undefined *)(param_1 + 6),puVar1 + 1);
  *puVar1 = 0x2e;
  puVar1 = (undefined *)sub_402A934(*(undefined *)(param_1 + 7),puVar1 + 1);
  *puVar1 = 0;
  return;
}

