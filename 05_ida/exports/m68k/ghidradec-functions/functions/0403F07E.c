
void _ipc_marequest_cancel(uint param_1,uint param_2)

{
  uint *puVar1;
  uint *puVar2;
  
  puVar2 = (uint *)(_ipc_marequest_table +
                   (_ipc_marequest_mask & (param_2 & 0xff) + (param_2 >> 8) + (param_1 >> 4)) * 4);
  while ((puVar1 = (uint *)*puVar2, puVar1 != (uint *)0x0 &&
         ((param_1 != *puVar1 || (param_2 != puVar1[1]))))) {
    puVar2 = puVar1 + 3;
  }
  *puVar2 = puVar1[3];
  puVar1[1] = 0;
  return;
}
