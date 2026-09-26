
undefined4 * _svckudp_create(undefined4 param_1,undefined2 param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  
  puVar1 = (undefined4 *)_kalloc(0x32);
  uVar2 = _kalloc(0x2260);
  *(undefined4 *)((int)puVar1 + 0x2a) = uVar2;
  iVar3 = _kalloc(0x1cc);
  _bzero(iVar3,0x1cc);
  *(undefined4 *)((int)puVar1 + 10) = 0;
  *(int *)((int)puVar1 + 0x2e) = iVar3;
  *(int *)((int)puVar1 + 0x22) = iVar3 + 0x3c;
  *(undefined **)((int)puVar1 + 6) = _svckudp_op;
  *(undefined2 *)(puVar1 + 1) = param_2;
  *puVar1 = param_1;
  _xprt_register(puVar1);
  return puVar1;
}

