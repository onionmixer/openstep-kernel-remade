
int _spgrp(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar1 = param_1;
  do {
    do {
      iVar3 = iVar1;
      *(uint *)(iVar3 + 0x18) = *(uint *)(iVar3 + 0x18) & 0xffcdffff;
      iVar2 = iVar2 + 1;
      iVar1 = *(int *)(iVar3 + 0x46);
    } while (*(int *)(iVar3 + 0x46) != 0);
    while( true ) {
      if (param_1 == iVar3) {
        return iVar2;
      }
      iVar1 = *(int *)(iVar3 + 0x4a);
      if (*(int *)(iVar3 + 0x4a) != 0) break;
      iVar3 = *(int *)(iVar3 + 0x42);
    }
  } while( true );
}
