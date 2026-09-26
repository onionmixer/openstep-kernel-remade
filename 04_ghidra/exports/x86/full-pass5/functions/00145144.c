/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00145144 */

int FUN_00145144(int param_1,undefined4 param_2,undefined4 *param_3,char *param_4)

{
  byte *pbVar1;
  char cVar2;
  ushort uVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  int local_8;
  
  local_8 = 0;
  *param_3 = 5;
  *(undefined2 *)(param_3 + 0xe) = 0;
  iVar4 = _direnter(*(undefined4 *)(param_1 + 0x30),param_2,0,0,0,param_3,&local_8);
  if (iVar4 == 0) {
    uVar5 = 0xffffffff;
    pcVar6 = param_4;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar2 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar2 != '\0');
    uVar5 = ~uVar5 - 1;
    if ((uVar5 < 0x3c) && (_dosymlink != 0)) {
      _bcopy(param_4,(void *)(local_8 + 0x8c),uVar5);
      *(byte *)(local_8 + 200) = *(byte *)(local_8 + 200) | 1;
      *(uint *)(*(int *)(local_8 + 0xc) + 0x14) = uVar5;
      *(uint *)(local_8 + 0x6c) = uVar5;
      *(byte *)(local_8 + 0x44) = *(byte *)(local_8 + 0x44) | 0x42;
    }
    else {
      iVar4 = _rdwri(1,local_8,param_4,uVar5,0,1,0);
    }
  }
  else if (iVar4 != 0x11) goto LAB_00145209;
  _iput(local_8);
LAB_00145209:
  uVar3 = *(ushort *)(*(int *)(param_1 + 0x30) + 0x44);
  if ((uVar3 & 0x46) != 0) {
    *(ushort *)(*(int *)(param_1 + 0x30) + 0x44) = uVar3 | 8;
    _microtime(&_iuniqtime);
    if ((*(byte *)(*(int *)(param_1 + 0x30) + 0x44) & 4) != 0) {
      *(undefined4 *)(*(int *)(param_1 + 0x30) + 0x74) = _iuniqtime;
    }
    if ((*(byte *)(*(int *)(param_1 + 0x30) + 0x44) & 2) != 0) {
      *(undefined4 *)(*(int *)(param_1 + 0x30) + 0x7c) = _iuniqtime;
    }
    if ((*(byte *)(*(int *)(param_1 + 0x30) + 0x44) & 0x40) != 0) {
      *(undefined4 *)(*(int *)(param_1 + 0x30) + 0x4c) = 0;
      *(undefined4 *)(*(int *)(param_1 + 0x30) + 0x84) = _iuniqtime;
    }
    pbVar1 = (byte *)(*(int *)(param_1 + 0x30) + 0x44);
    *pbVar1 = *pbVar1 & 0xb9;
  }
  return iVar4;
}

