
void _write(void)

{
  undefined4 uStack_22;
  undefined4 uStack_1e;
  undefined4 *puStack_1a;
  undefined4 uStack_16;
  
  puStack_1a = &uStack_22;
  uStack_16 = 1;
  uStack_22 = *(undefined4 *)(*(int *)(dword_40B57D4 + 0x24) + 4);
  uStack_1e = *(undefined4 *)(*(int *)(dword_40B57D4 + 0x24) + 8);
  _rwuio(&puStack_1a,1);
  return;
}
