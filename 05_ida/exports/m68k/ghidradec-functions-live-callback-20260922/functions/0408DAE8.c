
undefined4 _if_busalloc(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_2 == 0) {
    iVar1 = _enbuf_get();
    *(int *)(param_1 + 0x1c) = iVar1;
    if (iVar1 == 0) {
      return 0;
    }
  }
  else {
    uVar2 = _nb_map(param_2);
    *(undefined4 *)(param_1 + 0x1c) = uVar2;
    _nb_free_wrapper(param_2);
  }
  uVar2 = _pmap_resident_extract(*(undefined4 *)(_mb_map + 0x20),*(undefined4 *)(param_1 + 0x1c));
  *(undefined4 *)(param_1 + 4) = uVar2;
  return 1;
}

