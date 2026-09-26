
void _symlink(void)

{
  undefined4 *puVar1;
  undefined uVar2;
  int iStack_5a;
  undefined auStack_56 [4];
  undefined4 uStack_52;
  undefined auStack_4a [4];
  undefined4 uStack_46;
  undefined auStack_3e [4];
  undefined2 uStack_3a;
  
  puVar1 = *(undefined4 **)(dword_40B57D4 + 0x24);
  uVar2 = _pn_get(puVar1[1],0,auStack_56);
  *(undefined *)(dword_40B57D4 + 100) = uVar2;
  if (*(char *)(dword_40B57D4 + 100) == '\0') {
    uVar2 = _lookuppn(auStack_56,0,&iStack_5a,0);
    *(undefined *)(dword_40B57D4 + 100) = uVar2;
    if (*(char *)(dword_40B57D4 + 100) == '\0') {
      if ((*(byte *)(*(int *)(iStack_5a + 0x24) + 0xf) & 1) == 0) {
        uVar2 = _pn_get(*puVar1,0,auStack_4a);
        *(undefined *)(dword_40B57D4 + 100) = uVar2;
        _vattr_null(auStack_3e);
        uStack_3a = 0x1ff;
        if (*(char *)(dword_40B57D4 + 100) == '\0') {
          uVar2 = (**(code **)(*(int *)(iStack_5a + 0x1c) + 0x40))
                            (iStack_5a,uStack_52,auStack_3e,uStack_46,
                             *(undefined4 *)(_active_u + 0x1a));
          *(undefined *)(dword_40B57D4 + 100) = uVar2;
          _pn_free(auStack_4a);
        }
      }
      else {
        *(undefined *)(dword_40B57D4 + 100) = 0x1e;
      }
      _pn_free(auStack_56);
      _vn_rele(iStack_5a);
    }
    else {
      _pn_free(auStack_56);
    }
  }
  return;
}

