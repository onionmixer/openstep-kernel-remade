
int _iflush(sword param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  if (_inode_list != (int *)0x0) {
    piVar2 = _inode_list;
    do {
      if (param_1 == *(sword *)(piVar2 + 0x11)) {
        if ((*(byte *)((int)piVar2 + 0x42) & 1) == 0) {
          *(int *)(*piVar2 + 4) = piVar2[1];
          *(int *)piVar2[1] = *piVar2;
          *piVar2 = (int)piVar2;
          piVar2[1] = (int)piVar2;
        }
        else {
          iVar1 = -1;
        }
      }
      else if (((((*(byte *)((int)piVar2 + 0x42) & 1) != 0) &&
                ((*(word *)((int)piVar2 + 0x62) & 0xf000) == 0x6000)) &&
               ((int)param_1 == *(int *)((int)piVar2 + 0x8a))) && (-1 < iVar1)) {
        iVar1 = iVar1 + 1;
      }
      piVar2 = (int *)piVar2[2];
    } while (piVar2 != (int *)0x0);
  }
  return iVar1;
}

