
void _fake_u(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  iVar1 = *(int *)(*(int *)(param_2 + 0xc) + 0x30);
  iVar2 = *(int *)(param_2 + 0x80);
  _bcopy(iVar1 + 8,param_1 + 8,0x11);
  _bcopy(iVar2 + 4,param_1 + 0x1a,0x20);
  *(undefined4 *)(param_1 + 0x7c) = *(undefined4 *)(iVar1 + 0x1a);
  _bcopy(iVar1 + 0x2a,param_1 + 0x98,0x84);
  *(undefined4 *)(param_1 + 0x1ac) = *(undefined4 *)(iVar2 + 0x6c);
  *(undefined4 *)(param_1 + 0x6c4) = *(undefined4 *)(iVar1 + 0x15e);
  *(undefined2 *)(param_1 + 0x6c8) = *(undefined2 *)(iVar1 + 0x162);
  _bcopy(iVar1 + 0x166,(undefined4 *)(param_1 + 0x6cc),0x48);
  _thread_read_times(param_2,&uStack_c,&uStack_14);
  *(undefined4 *)(param_1 + 0x6d4) = uStack_14;
  *(undefined4 *)(param_1 + 0x6d8) = uStack_10;
  *(undefined4 *)(param_1 + 0x6cc) = uStack_c;
  *(undefined4 *)(param_1 + 0x6d0) = uStack_8;
  _bcopy(iVar1 + 0x1ae,param_1 + 0x714,0x48);
  return;
}
