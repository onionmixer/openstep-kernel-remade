/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012cd18 */

int _findexivp(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  ushort *local_8;
  
  *(short *)(param_3 + 6) = *(short *)(param_3 + 6) + 1;
  iVar3 = param_3;
  if (param_2 != 0) {
    *(short *)(param_2 + 6) = *(short *)(param_2 + 6) + 1;
  }
  do {
    iVar1 = (**(code **)(*(int *)(iVar3 + 0x1c) + 100))(iVar3,&local_8);
    if (iVar1 != 0) {
LAB_0012cdd4:
      _vn_rele(iVar3);
      if (param_2 != 0) {
        _vn_rele(param_2);
      }
      return iVar1;
    }
    iVar2 = _findexport(*(int *)(iVar3 + 0x24) + 0x14,local_8);
    *param_1 = iVar2;
    _kfree(local_8,*local_8 + 2);
    if (*param_1 != 0) goto LAB_0012cdd4;
    if ((*(byte *)(iVar3 + 4) & 1) != 0) {
      iVar1 = 0x16;
      goto LAB_0012cdd4;
    }
    if (param_2 == 0) {
      iVar1 = (**(code **)(*(int *)(iVar3 + 0x1c) + 0x20))
                        (iVar3,&DAT_001dbf5c,&param_2,*(undefined4 *)(_active_u + 0x1c),0,0);
      if (iVar1 != 0) goto LAB_0012cdd4;
    }
    _vn_rele(iVar3);
    iVar3 = param_2;
    param_2 = 0;
  } while( true );
}

