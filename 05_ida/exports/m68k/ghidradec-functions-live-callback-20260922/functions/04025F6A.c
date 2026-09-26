
void _igmp_fasttimo(void)

{
  int iVar1;
  int iVar2;
  undefined auStack_c [8];
  
  if (dword_40AEC04 != 0) {
    dword_40AEC04 = 0;
    iVar2 = sub_4025F4C(auStack_c);
    while (iVar2 != 0) {
      iVar1 = *(int *)(iVar2 + 0x10);
      if (iVar1 != 0) {
        *(int *)(iVar2 + 0x10) = iVar1 + -1;
        if (iVar1 == 1) {
          _igmp_sendreport(iVar2);
        }
        else {
          dword_40AEC04 = 1;
        }
      }
      iVar2 = sub_4025F16(auStack_c);
    }
  }
  return;
}

