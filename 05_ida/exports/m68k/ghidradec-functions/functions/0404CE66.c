
char _cpu_up(int param_1)

{
  int iVar1;
  char cVar2;
  
  iVar1 = (&_processor_ptr)[param_1];
  (&dword_40B5DD4)[param_1 * 8] = 1;
  cVar2 = 0xfffffffe < dword_40C22D4;
  dword_40C22D4 = dword_40C22D4 + 1;
  _pset_add_processor(_default_pset,iVar1);
  *(undefined4 *)(iVar1 + 0x110) = 1;
  return cVar2 << 4;
}
