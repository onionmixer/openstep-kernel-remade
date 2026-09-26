
void __class_removeProtocols(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if (*(undefined4 **)(param_1 + 0x24) == param_2) {
    *(undefined4 *)(param_1 + 0x24) = *param_2;
  }
  else {
    puVar1 = (undefined4 *)**(undefined4 **)(param_1 + 0x24);
    puVar3 = *(undefined4 **)(param_1 + 0x24);
    while (puVar2 = puVar1, puVar2 != (undefined4 *)0x0) {
      if (puVar2 == param_2) {
        *puVar3 = *puVar2;
        puVar1 = (undefined4 *)0x0;
      }
      else {
        puVar1 = (undefined4 *)*puVar2;
        puVar3 = puVar2;
      }
    }
  }
  return;
}
