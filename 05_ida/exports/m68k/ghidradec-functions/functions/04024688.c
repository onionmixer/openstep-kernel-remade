
undefined4 * _tcp_template(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  
  iVar1 = *(int *)(param_1 + 0x20);
  puVar3 = *(undefined4 **)(param_1 + 0x1c);
  if (puVar3 == (undefined4 *)0x0) {
    iVar2 = _m_get(0,2);
    if (iVar2 == 0) {
      return (undefined4 *)0x0;
    }
    *(undefined4 *)(iVar2 + 4) = 0x54;
    *(undefined2 *)(iVar2 + 8) = 0x28;
    puVar3 = (undefined4 *)(*(int *)(iVar2 + 4) + iVar2);
  }
  puVar3[1] = 0;
  *puVar3 = 0;
  *(undefined *)(puVar3 + 2) = 0;
  *(undefined *)((int)puVar3 + 9) = 6;
  *(undefined2 *)((int)puVar3 + 10) = 0x14;
  puVar3[3] = *(undefined4 *)(iVar1 + 0x12);
  puVar3[4] = *(undefined4 *)(iVar1 + 0xc);
  *(undefined2 *)(puVar3 + 5) = *(undefined2 *)(iVar1 + 0x16);
  *(undefined2 *)((int)puVar3 + 0x16) = *(undefined2 *)(iVar1 + 0x10);
  puVar3[6] = 0;
  puVar3[7] = 0;
  *(undefined *)(puVar3 + 8) = 0x50;
  *(undefined *)((int)puVar3 + 0x21) = 0;
  *(undefined2 *)((int)puVar3 + 0x22) = 0;
  *(undefined2 *)(puVar3 + 9) = 0;
  *(undefined2 *)((int)puVar3 + 0x26) = 0;
  return puVar3;
}
