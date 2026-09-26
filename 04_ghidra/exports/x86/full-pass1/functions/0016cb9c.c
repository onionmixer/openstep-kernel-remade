/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016cb9c */

int _kern_serv_port_serv(int *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *param_1;
  if (*(int *)(iVar1 + 0x4ac) == param_2) {
    *(undefined4 *)(iVar1 + 0x4ac) = 0;
  }
  iVar3 = 0;
  iVar2 = 0;
  do {
    if (*(int *)(iVar2 + 0x18c + iVar1) == param_2) {
      *(undefined4 *)(iVar2 + 0x18c + iVar1) = 0;
    }
    iVar2 = iVar2 + 0x10;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x32);
  iVar3 = 0;
  iVar2 = 0;
  do {
    if (*(int *)(iVar2 + 0x18c + iVar1) == 0) break;
    iVar2 = iVar2 + 0x10;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x32);
  iVar2 = 6;
  if (iVar3 != 0x32) {
    iVar2 = _port_set_add_EXTERNAL(*(undefined4 *)(iVar1 + 8),*(undefined4 *)(iVar1 + 0x20),param_2)
    ;
    if (iVar2 == 0) {
      iVar3 = iVar3 * 0x10;
      *(int *)(iVar3 + 0x18c + iVar1) = param_2;
      *(undefined4 *)(iVar3 + 400 + iVar1) = param_3;
      *(undefined4 *)(iVar3 + 0x194 + iVar1) = param_4;
      *(undefined4 *)(iVar3 + 0x198 + iVar1) = 1;
      iVar2 = 0;
    }
  }
  return iVar2;
}

