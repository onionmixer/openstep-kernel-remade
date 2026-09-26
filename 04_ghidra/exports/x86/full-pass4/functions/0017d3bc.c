/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017d3bc */

int _vnode_pageout(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  int local_10;
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x14) + 0x28);
  do {
  } while (_vstruct_lock != 0);
  LOCK();
  UNLOCK();
  *(short *)(iVar1 + 0xe) = *(short *)(iVar1 + 0xe) + 1;
  LOCK();
  _vstruct_lock = 0;
  UNLOCK();
  piVar5 = *(int **)(iVar1 + 0x14);
  uVar4 = *(int *)(param_1 + 0x18) + *(int *)(*(int *)(param_1 + 0x14) + 0x2c);
  local_10 = _page_size;
  if ((*(byte *)(iVar1 + 0xc) & 1) == 0) {
    uVar2 = *(uint *)(*piVar5 + 0x14);
    if (uVar2 < _page_size + uVar4) {
      if (uVar2 < uVar4) {
        local_10 = 0;
      }
      else {
        local_10 = uVar2 - uVar4;
      }
    }
    if ((*(byte *)(iVar1 + 0xc) & 1) == 0) goto LAB_0017d4b4;
  }
  iVar3 = FUN_0017cd58(iVar1,uVar4,0,&local_8);
  if (iVar3 == 5) {
    do {
    } while (_vstruct_lock != 0);
    LOCK();
    UNLOCK();
    *(short *)(iVar1 + 0xe) = *(short *)(iVar1 + 0xe) + -1;
    LOCK();
    UNLOCK();
    _vstruct_lock = 0;
    return 2;
  }
  uVar4 = (local_8 >> 8) << ((byte)_page_shift & 0x1f);
  piVar5 = *(int **)(*(int *)(&DAT_001e7294 + (local_8 & 0xff) * 4) + 8);
  if (*(uint *)(*piVar5 + 0x14) < local_10 + uVar4) {
    *(uint *)(*piVar5 + 0x14) = local_10 + uVar4;
  }
LAB_0017d4b4:
  if (local_10 == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = (**(code **)(piVar5[7] + 0x78))(piVar5,*(undefined4 *)(param_1 + 0x24),local_10,uVar4);
  }
  if (iVar3 == 0) {
    *(byte *)(param_1 + 0x1e) = *(byte *)(param_1 + 0x1e) | 0x20;
    _pmap_clear_modify(*(undefined4 *)(param_1 + 0x24));
  }
  else {
    _printf(s_vnode_pageout__failed__001e0e8a);
  }
  do {
  } while (_vstruct_lock != 0);
  LOCK();
  UNLOCK();
  *(short *)(iVar1 + 0xe) = *(short *)(iVar1 + 0xe) + -1;
  LOCK();
  UNLOCK();
  _vstruct_lock = 0;
  return iVar3;
}

