/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011ce68 */

int _mknod(char *param_1,mode_t param_2,dev_t param_3)

{
  undefined4 *puVar1;
  undefined1 uVar2;
  int iVar3;
  undefined4 local_48;
  undefined4 local_44;
  ushort local_40;
  undefined2 local_c;
  
  puVar1 = *(undefined4 **)(DAT_001e875c + 0x24);
  if ((puVar1[1] & 0xf000) == 0) {
    puVar1[1] = puVar1[1] | 0x8000;
  }
  if (((puVar1[1] & 0xf000) != 0x1000) && (iVar3 = _suser(), iVar3 == 0)) {
    return 0;
  }
  _vattr_null(&local_44);
  iVar3 = DAT_001e875c;
  local_44 = *(undefined4 *)(&_mftovt_tab + ((int)(puVar1[1] & 0xf000) >> 0xd) * 4);
  local_40 = *(ushort *)(puVar1 + 1) & 0xfff & ~*(ushort *)(_active_u + 0x16e);
  switch(local_44) {
  case 0:
    *(undefined1 *)(DAT_001e875c + 0x68) = 0x16;
    break;
  case 2:
    *(undefined1 *)(DAT_001e875c + 0x68) = 0x15;
    break;
  case 3:
  case 4:
  case 7:
  case 9:
    local_c = *(undefined2 *)(puVar1 + 2);
  default:
    uVar2 = _vn_create(*puVar1,0,&local_44,1,0,&local_48);
    *(undefined1 *)(DAT_001e875c + 0x68) = uVar2;
    iVar3 = DAT_001e875c;
    if (*(char *)(DAT_001e875c + 0x68) == '\0') {
      iVar3 = _vn_rele(local_48);
    }
  }
  return iVar3;
}

