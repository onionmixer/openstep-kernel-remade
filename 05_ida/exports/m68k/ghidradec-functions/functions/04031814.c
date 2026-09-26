
int _makespecvp(sword param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  while( true ) {
    iVar1 = sub_4031ADE((int)param_1,0,param_2);
    if (iVar1 == 0) break;
    if ((*(word *)(iVar1 + 0x3e) & 1) == 0) goto loc_40318C0;
    *(word *)(iVar1 + 0x3e) = *(word *)(iVar1 + 0x3e) | 0x10;
    _sleep(iVar1,10);
  }
  iVar1 = _kalloc(0x66);
  _bzero(iVar1,0x66);
  *(undefined **)(iVar1 + 0x20) = _spec_vnodeops;
  *(int *)(iVar1 + 0x2c) = param_2;
  if (param_2 == 3) {
    uVar2 = _bdevvp((int)param_1);
    *(undefined4 *)(iVar1 + 0x3a) = uVar2;
  }
  *(undefined4 *)(iVar1 + 0x36) = 0;
  *(sword *)(iVar1 + 0x40) = param_1;
  *(sword *)(iVar1 + 0x30) = param_1;
  *(undefined2 *)(iVar1 + 10) = 1;
  *(int *)(iVar1 + 0x32) = iVar1;
  *(undefined4 *)(iVar1 + 0x28) = 0;
  sub_40318CE(iVar1);
loc_40318C0:
  return iVar1 + 4;
}
