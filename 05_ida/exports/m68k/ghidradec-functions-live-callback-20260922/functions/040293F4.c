
int sub_40293F4(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  sword sVar3;
  int iVar4;
  
  iVar2 = *(int *)(_rtable +
                  ((byte)(*(byte *)(param_1 + 0x1b) ^
                         *(byte *)(param_1 + 0x1a) ^
                         *(byte *)(param_1 + 0x19) ^
                         *(byte *)(param_1 + 0x18) ^
                         *(byte *)(param_1 + 0x17) ^
                         *(byte *)(param_1 + 0x16) ^
                         *(byte *)(param_1 + 0x15) ^
                         *(byte *)(param_1 + 0x14) ^
                         *(byte *)(param_1 + 0x11) ^
                         *(byte *)(param_1 + 0x10) ^
                         *(byte *)(param_1 + 0xf) ^
                         *(byte *)(param_1 + 0xe) ^
                         *(byte *)(param_1 + 0xd) ^
                         *(byte *)(param_1 + 0xc) ^
                         *(byte *)(param_1 + 0xb) ^ *(byte *)(param_1 + 10)) & 0x3f) * 4);
  while( true ) {
    if (iVar2 == 0) {
      return 0;
    }
    iVar4 = _bcmp(iVar2 + 0x3e,param_1,0x20);
    if ((iVar4 == 0) && (param_2 == *(int *)(iVar2 + 0x30))) break;
    iVar2 = *(int *)(iVar2 + 8);
  }
  sVar3 = *(sword *)(iVar2 + 0x12);
  *(sword *)(iVar2 + 0x12) = sVar3 + 1;
  if (sVar3 == 0) {
    sub_402935A(iVar2);
    piVar1 = (int *)(*(int *)(*(int *)(iVar2 + 0x30) + 0x126) + 0x16);
    *piVar1 = *piVar1 + 1;
    _rreactive = _rreactive + 1;
  }
  else {
    _ractive = _ractive + 1;
  }
  sub_402935A(iVar2);
  return iVar2;
}

