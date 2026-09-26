
int _copen(undefined4 param_1,uint param_2,word param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iStack_8;
  
  iVar2 = _falloc();
  if (iVar2 == 0) {
    iVar3 = (int)*(char *)(dword_40B57D4 + 100);
  }
  else {
    iVar1 = *(int *)(dword_40B57D4 + 0x5c);
    iVar3 = _vn_open(param_1,0,param_2,param_3 & ~*(word *)(_active_u + 0x59) & 0xfff,&iStack_8);
    if (iVar3 == 0) {
      *(uint *)(iVar2 + 8) = param_2 & 0xa000004b;
      if (((*(byte *)(*_active_u + 0x16) & 0x40) != 0) && (*(int *)(iStack_8 + 0x28) == 1)) {
        *(uint *)(iVar2 + 8) = param_2 & 0xa000004b | 0x40001000;
      }
      *(undefined2 *)(iVar2 + 0xc) = 1;
      *(int *)(iVar2 + 0x16) = iStack_8;
      *(undefined **)(iVar2 + 0x12) = _vnodefops;
      if (*(int *)(iStack_8 + 0x28) == 8) {
        *(uint *)(iVar2 + 8) = param_2 & 4 | *(uint *)(iVar2 + 8);
      }
      *(int *)(*(int *)((int)_active_u + 0x146) + iVar1 * 4) = iVar2;
    }
    else {
      *(undefined4 *)(*(int *)((int)_active_u + 0x146) + iVar1 * 4) = 0;
      _crfree(*(undefined4 *)(iVar2 + 0x1e));
      *(undefined2 *)(iVar2 + 0xe) = 0;
      _free_file(iVar2);
    }
  }
  return iVar3;
}

