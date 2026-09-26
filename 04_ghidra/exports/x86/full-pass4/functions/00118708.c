/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00118708 */

/* WARNING: Type propagation algorithm not settling */

int _unp_bind(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int local_48 [2];
  undefined2 local_40;
  
  iVar2 = param_2 + *(int *)(param_2 + 4);
  if ((param_1[1] == 0) && (*(short *)(param_2 + 8) != 0x70)) {
    *(undefined1 *)(*(short *)(param_2 + 8) + iVar2) = 0;
    _vattr_null(local_48 + 1);
    local_48[1] = 6;
    local_40 = 0x1ff;
    iVar2 = _vn_create(iVar2 + 2,1,local_48 + 1,1,0,local_48);
    if (iVar2 == 0) {
      *(undefined4 *)(local_48[0] + 0x20) = *param_1;
      param_1[1] = local_48[0];
      uVar1 = _m_copy(param_2,0,1000000000);
      param_1[6] = uVar1;
      iVar2 = 0;
    }
    else if (iVar2 == 0x11) {
      iVar2 = 0x30;
    }
  }
  else {
    iVar2 = 0x16;
  }
  return iVar2;
}

