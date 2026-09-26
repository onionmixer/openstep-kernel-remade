
void _dspq_init_lmsg(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  dword_40C6E4A = &dword_40C6E46;
  dword_40C6E46 = &dword_40C6E46;
  dword_40C6E4E = 0;
  dword_40B5094 = &dword_40B5090;
  dword_40B5090 = &dword_40B5090;
  dword_40B509C = &dword_40B5098;
  dword_40B5098 = &dword_40B5098;
  iVar3 = 0x14;
  do {
    puVar2 = (undefined4 *)_kalloc(0xa6);
    puVar1 = puVar2;
    if ((undefined4 **)dword_40B5094 != &dword_40B5090) {
      dword_40B5094[6] = puVar2;
      puVar1 = dword_40B5090;
    }
    dword_40B5090 = puVar1;
    puVar2[7] = dword_40B5094;
    puVar2[6] = &dword_40B5090;
    dword_40B5094 = puVar2;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}
