/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012c3fc */

int _nfs_getattr_otw(int param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = (int *)_kalloc(0x48);
  iVar3 = _rfscall(*(undefined4 *)(*(int *)(param_1 + 0x24) + 0x128),1,_xdr_fhandle,
                   *(int *)(param_1 + 0x30) + 0x40,_xdr_attrstat,piVar2,param_3);
  if (iVar3 == 0) {
    iVar3 = *piVar2;
    if (iVar3 == 0) {
      _nattr_to_vattr(param_1,piVar2 + 1,param_2);
      uVar1 = *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x24) + 0x128) + 0x28);
      *(uint *)(param_2 + 0xc) = CONCAT22((short)((uint)uVar1 >> 0x10),CONCAT11(0xff,(char)uVar1));
    }
    else if (iVar3 == 0x46) {
      _btrash(param_1);
      _vnode_uncache(param_1);
      _mfs_invalidate(param_1);
      *(undefined4 *)(*(int *)(param_1 + 0x30) + 0xc0) = 0;
      _dnlc_purge_vp(param_1);
      _binvalfree(param_1);
    }
  }
  _kfree(piVar2,0x48);
  return iVar3;
}

