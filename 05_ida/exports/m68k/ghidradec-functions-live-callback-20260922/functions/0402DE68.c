
void _clntkudp_freecred(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  _crfree(*(undefined4 *)(iVar1 + 0x74));
  *(undefined4 *)(iVar1 + 0x74) = 0xefefefef;
  return;
}

