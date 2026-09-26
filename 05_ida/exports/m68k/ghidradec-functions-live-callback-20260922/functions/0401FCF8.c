
void _in_setsockaddr(int param_1,int param_2)

{
  undefined2 *puVar1;
  
  *(undefined2 *)(param_2 + 8) = 0x10;
  puVar1 = (undefined2 *)(*(int *)(param_2 + 4) + param_2);
  _bzero(puVar1,0x10);
  *puVar1 = 2;
  puVar1[1] = *(undefined2 *)(param_1 + 0x16);
  *(undefined4 *)(puVar1 + 2) = *(undefined4 *)(param_1 + 0x12);
  return;
}

