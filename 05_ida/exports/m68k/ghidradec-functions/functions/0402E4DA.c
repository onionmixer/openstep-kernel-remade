
void _clntkudp_freeres(int param_1,code *param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(*(int *)(param_1 + 8) + 0x34);
  *puVar1 = 2;
  (*param_2)(puVar1,param_3);
  return;
}
