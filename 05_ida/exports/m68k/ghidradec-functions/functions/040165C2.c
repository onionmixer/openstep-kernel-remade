
void _unp_gc(void)

{
  uint uVar1;
  int iVar2;
  sword sVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  if (_unp_gcing != 0) {
    return;
  }
  _unp_gcing = 1;
loc_40165DC:
  _unp_defer = 0;
  puVar4 = _file_list;
  puVar5 = _file_list;
  if ((undefined4 **)_file_list != &_file_list) {
    do {
      puVar4[2] = puVar4[2] & 0xffffffcf;
      puVar4 = (undefined4 *)*puVar4;
      puVar5 = _file_list;
    } while ((undefined4 **)puVar4 != &_file_list);
  }
joined_r0x04016608:
  while ((undefined4 **)puVar5 == &_file_list) {
    puVar5 = _file_list;
    if (_unp_defer == 0) {
      _unp_defer = 0;
      puVar4 = _file_list;
      while ((undefined4 **)puVar4 != &_file_list) {
        sVar3 = *(sword *)((int)puVar4 + 0xe);
        puVar5 = puVar4;
        if ((sVar3 == *(sword *)(puVar4 + 4)) && ((*(byte *)((int)puVar4 + 0xb) & 0x10) == 0)) {
          while (puVar5 = _file_list, _file_list = puVar5, sVar3 != 0) {
            _unp_discard(puVar4);
            sVar3 = *(sword *)(puVar4 + 4);
          }
        }
        puVar4 = (undefined4 *)*puVar5;
      }
      _unp_gcing = 0;
      return;
    }
  }
  if (*(sword *)((int)puVar5 + 0xe) != 0) {
    uVar1 = puVar5[2];
    if ((uVar1 & 0x20) == 0) {
      if (((uVar1 & 0x10) != 0) || (*(sword *)((int)puVar5 + 0xe) == *(sword *)(puVar5 + 4)))
      goto loc_4016690;
      puVar5[2] = uVar1 | 0x10;
    }
    else {
      puVar5[2] = uVar1 & 0xffffffdf;
      _unp_defer = _unp_defer + -1;
    }
    if ((((*(sword *)(puVar5 + 3) == 2) && (iVar2 = *(int *)((int)puVar5 + 0x16), iVar2 != 0)) &&
        (*(undefined **)(*(int *)(iVar2 + 0xc) + 2) == _unixdomain)) &&
       ((*(byte *)(*(int *)(iVar2 + 0xc) + 9) & 0x10) != 0)) {
      if ((*(byte *)(iVar2 + 0x37) & 1) != 0) goto loc_401666e;
      _unp_scan(*(undefined4 *)(iVar2 + 0x2e),_unp_mark);
    }
  }
loc_4016690:
  puVar5 = (undefined4 *)*puVar5;
  goto joined_r0x04016608;
loc_401666e:
  _sbwait(iVar2 + 0x22);
  goto loc_40165DC;
}
