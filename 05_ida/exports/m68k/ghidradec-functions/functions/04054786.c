
void sub_4054786(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = dword_40B4DD8;
  iVar1 = dword_40B4DD0 + dword_40B4DD4;
  _thread_wakeup_prim(&dword_40B4DD0,1,0);
  if (iVar2 < iVar1) {
    _thread_wakeup_prim(&dword_40B4DD8,1,0);
  }
  return;
}
