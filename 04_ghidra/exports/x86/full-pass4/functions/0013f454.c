/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0013f454 */

byte * _blkatoff(int param_1,uint param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  byte *pbVar3;
  byte bVar4;
  uint uVar5;
  uint local_8;
  
  iVar1 = *(int *)(param_1 + 0x50);
  bVar4 = (byte)*(undefined4 *)(iVar1 + 0x50);
  uVar5 = param_2 >> (bVar4 & 0x1f);
  if (((int)uVar5 < 0xc) && (*(uint *)(param_1 + 0x6c) < uVar5 + 1 << (bVar4 & 0x1f))) {
    local_8 = ((~*(uint *)(iVar1 + 0x48) & *(uint *)(param_1 + 0x6c)) + *(int *)(iVar1 + 0x34)) - 1
              & *(uint *)(iVar1 + 0x4c);
  }
  else {
    local_8 = *(uint *)(iVar1 + 0x30);
  }
  iVar2 = _bmap(param_1,uVar5,1);
  iVar2 = iVar2 << ((byte)*(undefined4 *)(iVar1 + 100) & 0x1f);
  if (iVar2 < 0) {
    FUN_0013f5ac(param_1,s_nonexixtent_directory_block_001ddee9,param_2);
    *(undefined1 *)(DAT_001e875c + 0x68) = 2;
  }
  if (*(char *)(DAT_001e875c + 0x68) == '\0') {
    pbVar3 = (byte *)_bread(*(undefined4 *)(param_1 + 0x40),iVar2,local_8);
    if ((*pbVar3 & 4) == 0) {
      _byte_swap_dir_block_in(*(undefined4 *)(pbVar3 + 0x20),*(undefined4 *)(pbVar3 + 0x14));
      if (param_3 != (int *)0x0) {
        *param_3 = (~*(uint *)(iVar1 + 0x48) & param_2) + *(int *)(pbVar3 + 0x20);
      }
    }
    else {
      _brelse(pbVar3);
      pbVar3 = (byte *)0x0;
    }
  }
  else {
    pbVar3 = (byte *)0x0;
  }
  return pbVar3;
}

