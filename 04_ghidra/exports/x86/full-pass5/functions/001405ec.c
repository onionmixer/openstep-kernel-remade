/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001405ec */

void * _new_inode(void)

{
  byte *pbVar1;
  void *pvVar2;
  
  pvVar2 = (void *)_zalloc(_inode_zone);
  if (pvVar2 == (void *)0x0) {
    pvVar2 = (void *)0x0;
  }
  else {
    _bzero(pvVar2,0xe8);
    *(void **)pvVar2 = pvVar2;
    *(void **)((int)pvVar2 + 4) = pvVar2;
    *(undefined4 *)((int)pvVar2 + 0x5c) = 0;
    *(undefined4 *)((int)pvVar2 + 0x60) = 0;
    *(void **)((int)pvVar2 + 0x3c) = pvVar2;
    *(undefined ***)((int)pvVar2 + 0x28) = &_ufs_vnodeops;
    *(undefined4 *)((int)pvVar2 + 0xc) = 0;
    _vm_info_init((int)pvVar2 + 0xc);
    pbVar1 = (byte *)(*(int *)((int)pvVar2 + 0xc) + 0x38);
    *pbVar1 = *pbVar1 & 0xfb;
    *(void **)((int)pvVar2 + 8) = _inode_list;
    _inode_list = pvVar2;
  }
  return pvVar2;
}

