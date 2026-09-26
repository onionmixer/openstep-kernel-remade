/* GHIDRADEC_FUNCTION index=465 start=0x401654e */

undefined4 _unp_internalize(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  int *piVar5;
  
  uVar3 = (uint)(int)*(sword *)(param_1 + 8) >> 2;
  iVar2 = 0;
  puVar4 = (undefined4 *)(*(int *)(param_1 + 4) + param_1);
  if (uVar3 != 0) {
    do {
      iVar1 = _getf(*puVar4);
      if (iVar1 == 0) {
        return 9;
      }
      iVar2 = iVar2 + 1;
      puVar4 = puVar4 + 1;
    } while (iVar2 < (int)uVar3);
  }
  iVar2 = 0;
  piVar5 = (int *)(*(int *)(param_1 + 4) + param_1);
  if (uVar3 != 0) {
    do {
      iVar1 = _getf(*piVar5);
      *piVar5 = iVar1;
      *(sword *)(iVar1 + 0xe) = *(sword *)(iVar1 + 0xe) + 1;
      *(sword *)(iVar1 + 0x10) = *(sword *)(iVar1 + 0x10) + 1;
      _unp_rights = _unp_rights + 1;
      iVar2 = iVar2 + 1;
      piVar5 = piVar5 + 1;
    } while (iVar2 < (int)uVar3);
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=466 start=0x40165c2 */

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
/* GHIDRADEC_FUNCTION index=467 start=0x40166fc */

void _unp_dispose(int param_1)

{
  if (param_1 != 0) {
    _unp_scan(param_1,_unp_discard);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=468 start=0x4016718 */

void _unp_scan(undefined4 *param_1,code *param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  do {
    puVar3 = param_1;
    if (param_1 == (undefined4 *)0x0) {
      return;
    }
    for (; puVar3 != (undefined4 *)0x0; puVar3 = (undefined4 *)*puVar3) {
      if ((*(sword *)((int)puVar3 + 10) == 0xc) && (*(sword *)(puVar3 + 2) != 0)) {
        uVar2 = (uint)(int)*(sword *)(puVar3 + 2) >> 2;
        iVar1 = 0;
        puVar3 = (undefined4 *)(puVar3[1] + (int)puVar3);
        if (uVar2 != 0) {
          do {
            (*param_2)(*puVar3);
            iVar1 = iVar1 + 1;
            puVar3 = puVar3 + 1;
          } while (iVar1 < (int)uVar2);
        }
        break;
      }
    }
    param_1 = (undefined4 *)param_1[0x1f];
  } while( true );
}
/* GHIDRADEC_FUNCTION index=469 start=0x4016778 */

void _unp_mark(int param_1)

{
  if ((*(byte *)(param_1 + 0xb) & 0x10) == 0) {
    _unp_defer = _unp_defer + 1;
    *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) | 0x30;
  }
  return;
}

