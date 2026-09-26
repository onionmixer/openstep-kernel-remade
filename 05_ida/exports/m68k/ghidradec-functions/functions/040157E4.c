
void _pipe(void)

{
  int iVar1;
  undefined uVar4;
  int iVar2;
  int iVar3;
  char cVar5;
  int iStack_c;
  int iStack_8;
  
  uVar4 = _socreate(1,&iStack_8,1,0);
  *(undefined *)(dword_40B57D4 + 100) = uVar4;
  if (*(char *)(dword_40B57D4 + 100) == '\0') {
    uVar4 = _socreate(1,&iStack_c,1,0);
    *(undefined *)(dword_40B57D4 + 100) = uVar4;
    if (*(char *)(dword_40B57D4 + 100) == '\0') {
      iVar2 = _falloc();
      if (iVar2 != 0) {
        iVar1 = *(int *)(dword_40B57D4 + 0x5c);
        *(undefined4 *)(iVar2 + 8) = 1;
        if ((*(byte *)(*_active_u + 0x16) & 0x40) != 0) {
          *(undefined4 *)(iVar2 + 8) = 0x2001;
        }
        *(undefined2 *)(iVar2 + 0xc) = 2;
        *(undefined **)(iVar2 + 0x12) = _socketops;
        *(int *)(iVar2 + 0x16) = iStack_8;
        *(int *)(*(int *)((int)_active_u + 0x146) + *(int *)(dword_40B57D4 + 0x5c) * 4) = iVar2;
        iVar3 = _falloc();
        if (iVar3 != 0) {
          *(undefined4 *)(iVar3 + 8) = 2;
          if ((*(byte *)(*_active_u + 0x16) & 0x40) != 0) {
            *(undefined4 *)(iVar3 + 8) = 0x2002;
          }
          *(undefined2 *)(iVar3 + 0xc) = 2;
          *(undefined **)(iVar3 + 0x12) = _socketops;
          *(int *)(iVar3 + 0x16) = iStack_c;
          *(int *)(*(int *)((int)_active_u + 0x146) + *(int *)(dword_40B57D4 + 0x5c) * 4) = iVar3;
          *(undefined4 *)(dword_40B57D4 + 0x60) = *(undefined4 *)(dword_40B57D4 + 0x5c);
          *(int *)(dword_40B57D4 + 0x5c) = iVar1;
          cVar5 = _unp_connect2(iStack_c,iStack_8);
          *(char *)(dword_40B57D4 + 100) = cVar5;
          if (cVar5 == '\0') {
            *(word *)(iStack_c + 6) = *(word *)(iStack_c + 6) | 0x20;
            *(word *)(iStack_8 + 6) = *(word *)(iStack_8 + 6) | 0x10;
            return;
          }
          *(undefined2 *)(iVar3 + 0xe) = 0;
          *(undefined4 *)(*(int *)((int)_active_u + 0x146) + *(int *)(dword_40B57D4 + 0x60) * 4) = 0
          ;
        }
        *(undefined2 *)(iVar2 + 0xe) = 0;
        *(undefined4 *)(*(int *)((int)_active_u + 0x146) + iVar1 * 4) = 0;
      }
      _soclose(iStack_c);
    }
    _soclose(iStack_8);
  }
  return;
}
