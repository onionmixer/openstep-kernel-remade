
undefined4 * _vnode_pager_create(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_zalloc(_vstruct_zone);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    _bzero(puVar1,0x18);
    *puVar1 = 0;
    *(undefined2 *)((int)puVar1 + 0xe) = 1;
    *(undefined4 **)*param_1 = puVar1;
    puVar1[5] = param_1;
    *(byte *)(puVar1 + 3) = *(byte *)(puVar1 + 3) & 0x7f;
    *(sword *)((int)param_1 + 6) = *(sword *)((int)param_1 + 6) + 1;
    _vnode_pager_vput(puVar1);
  }
  return puVar1;
}
