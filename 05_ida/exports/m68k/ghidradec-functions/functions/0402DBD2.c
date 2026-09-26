
void _clntkudp_once(int param_1,int param_2)

{
  uint *puVar1;
  
  puVar1 = *(uint **)(param_1 + 8);
  if (param_2 == 0) {
    *puVar1 = *puVar1 & 0xffffffdf;
  }
  else {
    *puVar1 = *puVar1 | 0x20;
  }
  return;
}
