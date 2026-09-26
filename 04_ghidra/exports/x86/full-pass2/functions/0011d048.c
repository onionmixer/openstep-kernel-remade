/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011d048 */

int _symlink(char *param_1,char *param_2)

{
  undefined4 *puVar1;
  undefined1 uVar2;
  int iVar3;
  int local_60;
  undefined1 local_5c [4];
  undefined4 local_58;
  undefined1 local_50 [4];
  undefined4 local_4c;
  undefined1 local_44 [4];
  undefined2 local_40;
  
  puVar1 = *(undefined4 **)(DAT_001e875c + 0x24);
  uVar2 = _pn_get(puVar1[1],0,local_5c);
  *(undefined1 *)(DAT_001e875c + 0x68) = uVar2;
  iVar3 = DAT_001e875c;
  if (*(char *)(DAT_001e875c + 0x68) == '\0') {
    uVar2 = _lookuppn(local_5c,0,&local_60,0);
    *(undefined1 *)(DAT_001e875c + 0x68) = uVar2;
    if (*(char *)(DAT_001e875c + 0x68) == '\0') {
      if ((*(byte *)(*(int *)(local_60 + 0x24) + 0xc) & 1) == 0) {
        uVar2 = _pn_get(*puVar1,0,local_50);
        *(undefined1 *)(DAT_001e875c + 0x68) = uVar2;
        _vattr_null(local_44);
        local_40 = 0x1ff;
        if (*(char *)(DAT_001e875c + 0x68) == '\0') {
          uVar2 = (**(code **)(*(int *)(local_60 + 0x1c) + 0x40))
                            (local_60,local_58,local_44,local_4c,*(undefined4 *)(_active_u + 0x1c));
          *(undefined1 *)(DAT_001e875c + 0x68) = uVar2;
          _pn_free(local_50);
        }
      }
      else {
        *(undefined1 *)(DAT_001e875c + 0x68) = 0x1e;
      }
      _pn_free(local_5c);
      iVar3 = _vn_rele(local_60);
    }
    else {
      iVar3 = _pn_free(local_5c);
    }
  }
  return iVar3;
}

