
void _p4m35_set_sysctl(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = segment(0x20);
  *(undefined4 *)(iVar1 + 0x79f00000) = param_1;
  return;
}
