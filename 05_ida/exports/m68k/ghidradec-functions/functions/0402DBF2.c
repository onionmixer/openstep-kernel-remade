
void _clntkudp_interruptable(int param_1,int param_2)

{
  word *pwVar1;
  
  if (param_2 == 0) {
    pwVar1 = (word *)(*(int *)(param_1 + 8) + 2);
    *pwVar1 = *pwVar1 & 0xf7ff;
  }
  else {
    pwVar1 = (word *)(*(int *)(param_1 + 8) + 2);
    *pwVar1 = *pwVar1 | 0x800;
  }
  return;
}
