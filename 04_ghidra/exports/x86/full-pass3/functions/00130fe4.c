/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00130fe4 */

int FUN_00130fe4(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int local_1c;
  uint local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar1 = *(int *)(param_1 + 0x128);
  iVar3 = _rfscall(iVar1,0x11,_xdr_fhandle,*(int *)(*(int *)(iVar1 + 0x10) + 0x30) + 0x40,
                   _xdr_statfs,&local_1c,*(undefined4 *)(_active_u + 0x1c));
  if ((iVar3 == 0) && (iVar3 = local_1c, local_1c == 0)) {
    uVar2 = *(uint *)(iVar1 + 0x20);
    if (uVar2 == 0) {
      *(uint *)(iVar1 + 0x20) = local_18;
    }
    else {
      if (uVar2 < local_18) {
        local_18 = uVar2;
      }
      *(uint *)(iVar1 + 0x20) = local_18;
    }
    *(undefined4 *)(param_2 + 4) = local_14;
    *(undefined4 *)(param_2 + 8) = local_10;
    *(undefined4 *)(param_2 + 0xc) = local_c;
    *(undefined4 *)(param_2 + 0x10) = local_8;
    *(undefined4 *)(param_2 + 0x14) = 0xffffffff;
    *(undefined4 *)(param_2 + 0x18) = 0xffffffff;
    _bcopy((void *)(param_1 + 0x14),(void *)(param_2 + 0x1c),8);
  }
  return iVar3;
}

