
int sub_4039F30(undefined4 param_1,byte *param_2)

{
  int iVar1;
  int iStack_8;
  
  iVar1 = _lookupname(param_1,0,1,0,&iStack_8);
  if (iVar1 == 0) {
    if (*(int *)(iStack_8 + 0x28) == 3) {
      *(undefined2 *)param_2 = *(undefined2 *)(iStack_8 + 0x2c);
      _vn_rele(iStack_8);
      iVar1 = 6;
      if ((int)(uint)*param_2 < _nblkdev) {
        iVar1 = 0;
      }
    }
    else {
      _vn_rele(iStack_8);
      iVar1 = 0xf;
    }
  }
  else if (*(char *)(dword_40B57D4 + 100) == '\x02') {
    iVar1 = 0x13;
  }
  return iVar1;
}

