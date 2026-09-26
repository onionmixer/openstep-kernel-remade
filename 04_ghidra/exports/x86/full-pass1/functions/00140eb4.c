/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00140eb4 */

void _iupdat(int param_1,int param_2)

{
  ushort uVar1;
  uint uVar2;
  byte *pbVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 0x50);
  if (((*(byte *)(param_1 + 0x44) & 0x4e) != 0) && (*(char *)(iVar4 + 0xd2) == '\0')) {
    uVar2 = *(uint *)(param_1 + 0x48) / *(uint *)(iVar4 + 0xb8);
    pbVar3 = (byte *)_bread(*(undefined4 *)(param_1 + 0x40),
                            *(int *)(iVar4 + 0xbc) * uVar2 +
                            (uVar2 & ~*(uint *)(iVar4 + 0x1c)) * *(int *)(iVar4 + 0x18) +
                            *(int *)(iVar4 + 0x10) +
                            ((int)(((ulonglong)*(uint *)(param_1 + 0x48) %
                                   (ulonglong)*(uint *)(iVar4 + 0xb8)) /
                                  (ulonglong)*(uint *)(iVar4 + 0x78)) <<
                            ((byte)*(undefined4 *)(iVar4 + 0x60) & 0x1f)) <<
                            ((byte)*(undefined4 *)(iVar4 + 100) & 0x1f),
                            *(undefined4 *)(iVar4 + 0x30));
    if ((*pbVar3 & 4) == 0) {
      if ((*(byte *)(param_1 + 0x44) & 0x46) != 0) {
        _microtime(&_iuniqtime);
        if ((*(byte *)(param_1 + 0x44) & 4) != 0) {
          *(undefined4 *)(param_1 + 0x74) = _iuniqtime;
        }
        if ((*(byte *)(param_1 + 0x44) & 2) != 0) {
          *(undefined4 *)(param_1 + 0x7c) = _iuniqtime;
        }
        if ((*(byte *)(param_1 + 0x44) & 0x40) != 0) {
          *(undefined4 *)(param_1 + 0x4c) = 0;
          *(undefined4 *)(param_1 + 0x84) = _iuniqtime;
        }
      }
      uVar1 = *(ushort *)(param_1 + 0x44);
      *(ushort *)(param_1 + 0x44) = uVar1 & 0xffb1;
      iVar4 = (*(uint *)(param_1 + 0x48) % *(uint *)(iVar4 + 0x78)) * 0x80 + *(int *)(pbVar3 + 0x20)
      ;
      *(ushort *)(param_1 + 0x44) = uVar1 & 0xfdb1;
      _byte_swap_inode_out(param_1,iVar4);
      if (*(short *)(*(int *)(param_1 + 0x30) + 0x124) != 0) {
        *(ushort *)(iVar4 + 4) =
             (ushort)(byte)(*(short *)(param_1 + 0xe4) >> 0xf) |
             (short)(char)((ushort)*(short *)(param_1 + 0xe4) >> 8) & 0xff00U;
        *(ushort *)(iVar4 + 6) =
             (ushort)(byte)(*(short *)(param_1 + 0xe6) >> 0xf) |
             (short)(char)((ushort)*(short *)(param_1 + 0xe6) >> 8) & 0xff00U;
      }
      if (param_2 == 0) {
        _bdwrite(pbVar3);
      }
      else {
        _bwrite(pbVar3);
      }
    }
    else {
      _brelse(pbVar3);
    }
  }
  return;
}

