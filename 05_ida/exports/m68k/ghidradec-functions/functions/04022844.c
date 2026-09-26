
void _rip_input(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4) + param_1;
  unk_40AEB52 = (word)*(byte *)(iVar1 + 9);
  unk_40AEB34._0_4_ = *(undefined4 *)(iVar1 + 0x10);
  unk_40AEB44._0_4_ = *(undefined4 *)(iVar1 + 0xc);
  _raw_input(param_1,&_ripproto,&_ripsrc,&_ripdst);
  return;
}
