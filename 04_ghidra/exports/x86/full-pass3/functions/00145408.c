/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00145408 */

undefined4 FUN_00145408(int param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  byte *pbVar3;
  undefined4 uVar4;
  uint uVar5;
  
  iVar1 = *(int *)(param_1 + 0x30);
  if (param_2 < 0xc) {
    iVar2 = *(int *)(iVar1 + 0x50);
    if (*(uint *)(iVar1 + 0x6c) <
        (uint)(param_2 + 1 << ((byte)*(undefined4 *)(iVar2 + 0x50) & 0x1f))) {
      uVar5 = ((~*(uint *)(iVar2 + 0x48) & *(uint *)(iVar1 + 0x6c)) + *(int *)(iVar2 + 0x34)) - 1 &
              *(uint *)(iVar2 + 0x4c);
      goto LAB_00145448;
    }
  }
  uVar5 = *(uint *)(*(int *)(iVar1 + 0x50) + 0x30);
LAB_00145448:
  iVar2 = _bmap(iVar1,param_2,1,0,0);
  iVar2 = iVar2 << ((byte)*(undefined4 *)(*(int *)(iVar1 + 0x50) + 100) & 0x1f);
  if (iVar2 < 0) {
    pbVar3 = (byte *)_geteblk(uVar5);
    _blkclr(*(undefined4 *)(pbVar3 + 0x20),*(undefined4 *)(pbVar3 + 0x14));
    pbVar3[0x28] = 0;
    pbVar3[0x29] = 0;
    pbVar3[0x2a] = 0;
    pbVar3[0x2b] = 0;
  }
  else if (param_2 == *(int *)(iVar1 + 0x58) + 1) {
    pbVar3 = (byte *)_breada(*(undefined4 *)(iVar1 + 0x40),iVar2,uVar5,_rablock,_rasize);
  }
  else {
    pbVar3 = (byte *)_bread(*(undefined4 *)(iVar1 + 0x40),iVar2,uVar5);
  }
  *(int *)(iVar1 + 0x58) = param_2;
  *(byte *)(iVar1 + 0x44) = *(byte *)(iVar1 + 0x44) | 4;
  _microtime(&_iuniqtime);
  if ((*(byte *)(iVar1 + 0x44) & 4) != 0) {
    *(undefined4 *)(iVar1 + 0x74) = _iuniqtime;
  }
  if ((*(byte *)(iVar1 + 0x44) & 2) != 0) {
    *(undefined4 *)(iVar1 + 0x7c) = _iuniqtime;
  }
  if ((*(byte *)(iVar1 + 0x44) & 0x40) != 0) {
    *(undefined4 *)(iVar1 + 0x4c) = 0;
    *(undefined4 *)(iVar1 + 0x84) = _iuniqtime;
  }
  if ((*pbVar3 & 4) == 0) {
    *param_3 = pbVar3;
    uVar4 = 0;
  }
  else {
    _brelse(pbVar3);
    uVar4 = 5;
  }
  return uVar4;
}

