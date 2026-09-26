
void _send(void)

{
  undefined4 *puVar1;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 *puStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  puVar1 = *(undefined4 **)(dword_40B57D4 + 0x24);
  uStack_1c = 0;
  uStack_18 = 0;
  puStack_14 = &uStack_24;
  uStack_10 = 1;
  uStack_24 = puVar1[1];
  uStack_20 = puVar1[2];
  uStack_c = 0;
  uStack_8 = 0;
  _sendit(*puVar1,&uStack_1c,puVar1[3]);
  return;
}
