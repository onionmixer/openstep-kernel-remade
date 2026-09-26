
void _sigreturn(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uStack_20;
  uint uStack_1c;
  uint uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined2 uStack_a;
  undefined4 uStack_8;
  
  uStack_20 = 0;
  puVar1 = (undefined4 *)*dword_40B57D4;
  iVar2 = _copyinmsg(puVar1[0xf] + 4,&uStack_20,4);
  if (iVar2 == 0) {
    iVar2 = _copyinmsg(uStack_20,&uStack_1c,0x18);
    if (iVar2 == 0) {
      *(undefined *)((int)dword_40B57D4 + 0x65) = 1;
      *(uint *)((int)_active_u + 0x142) = uStack_1c & 1;
      *(uint *)(*_active_u + 0x1c) = uStack_18 & 0xfffafeff;
      puVar1[0xf] = uStack_14;
      *(undefined4 *)((int)puVar1 + 0x42) = uStack_10;
      *(undefined2 *)(puVar1 + 0x10) = uStack_a;
      *puVar1 = uStack_8;
      *(word *)(puVar1 + 0x10) = *(word *)(puVar1 + 0x10) & 0xc0ff;
    }
  }
  return;
}
