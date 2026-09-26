
undefined4 * _falloc(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = _ufalloc(0);
  if (iVar1 < 0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = (undefined4 *)_zalloc(_file_zone);
    *dword_40B59C8 = puVar2;
    puVar2[1] = dword_40B59C8;
    *puVar2 = &_file_list;
    dword_40B59C8 = puVar2;
    *(undefined2 *)((int)puVar2 + 0xe) = 1;
    *(undefined4 *)((int)puVar2 + 0x16) = 0;
    *(undefined4 *)((int)puVar2 + 0x1a) = 0;
    *(undefined4 *)((int)puVar2 + 0x12) = 0;
    **(sword **)(_active_u + 0x1a) = **(sword **)(_active_u + 0x1a) + 1;
    *(undefined4 *)((int)puVar2 + 0x1e) = *(undefined4 *)(_active_u + 0x1a);
  }
  return puVar2;
}
