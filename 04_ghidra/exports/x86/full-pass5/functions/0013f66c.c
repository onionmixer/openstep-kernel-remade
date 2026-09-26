/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0013f66c */

int FUN_0013f66c(int param_1,uint param_2)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  byte *pbVar6;
  undefined4 uVar7;
  char *pcVar8;
  int local_c;
  int local_8;
  
  local_c = 0;
  while ((DAT_001ddf38 & 1) != 0) {
    DAT_001ddf38 = DAT_001ddf38 | 2;
    _sleep(0x1ddf38);
  }
  DAT_001ddf38 = 1;
  uVar4 = param_2;
  if (*(int *)(param_1 + 0x48) == *(int *)(param_2 + 0x48)) {
    local_c = 0x16;
  }
  else if (*(int *)(param_2 + 0x48) != 2) {
    do {
      pbVar6 = (byte *)0x0;
      if ((((*(ushort *)(uVar4 + 100) & 0xf000) != 0x4000) || (*(short *)(uVar4 + 0x66) == 0)) ||
         (uVar5 = *(uint *)(uVar4 + 0x6c), uVar5 < 0x18)) {
        pcVar8 = s_bad_size__unlinked_or_not_dir_001ddf39;
        uVar7 = *(undefined4 *)(uVar4 + 0x48);
LAB_0013f7db:
        _printf(s__s__bad_dir_ino__d_at_offset__d__001ddf13,*(int *)(uVar4 + 0x50) + 0xd4,uVar7,0,
                pcVar8);
        local_c = 0x14;
        goto LAB_0013f87f;
      }
      iVar2 = *(int *)(uVar4 + 0x50);
      if (uVar5 < (uint)(1 << ((byte)*(undefined4 *)(iVar2 + 0x50) & 0x1f))) {
        uVar5 = ((~*(uint *)(iVar2 + 0x48) & uVar5) + *(int *)(iVar2 + 0x34)) - 1 &
                *(uint *)(iVar2 + 0x4c);
      }
      else {
        uVar5 = *(uint *)(iVar2 + 0x30);
      }
      iVar3 = _bmap(uVar4,0,1);
      iVar3 = iVar3 << ((byte)*(undefined4 *)(iVar2 + 100) & 0x1f);
      if (iVar3 < 0) {
        FUN_0013f5ac(uVar4,s_nonexixtent_directory_block_001ddee9,0);
        *(undefined1 *)(DAT_001e875c + 0x68) = 2;
      }
      if (*(char *)(DAT_001e875c + 0x68) != '\0') {
        pbVar6 = (byte *)0x0;
        break;
      }
      pbVar6 = (byte *)_bread(*(undefined4 *)(uVar4 + 0x40),iVar3,uVar5);
      if ((*pbVar6 & 4) == 0) {
        _byte_swap_dir_block_in(*(undefined4 *)(pbVar6 + 0x20),*(undefined4 *)(pbVar6 + 0x14));
        local_8 = *(int *)(pbVar6 + 0x20);
      }
      else {
        _brelse(pbVar6);
        pbVar6 = (byte *)0x0;
      }
      if (pbVar6 == (byte *)0x0) break;
      if ((*(short *)(local_8 + 0x12) != 2) || (*(short *)(local_8 + 0x14) != 0x2e2e)) {
        pcVar8 = s_mangled____entry_001ddf57;
        uVar7 = *(undefined4 *)(uVar4 + 0x48);
        goto LAB_0013f7db;
      }
      iVar2 = *(int *)(local_8 + 0xc);
      if (*(int *)(param_1 + 0x48) == iVar2) {
        local_c = 0x16;
        goto LAB_0013f87f;
      }
      if (iVar2 == 2) goto LAB_0013f87f;
      _byte_swap_dir_block_out(pbVar6);
      _brelse(pbVar6);
      pbVar6 = (byte *)0x0;
      if (param_2 == uVar4) {
        uVar1 = *(ushort *)(param_2 + 0x44);
        *(ushort *)(param_2 + 0x44) = uVar1 & 0xfffe;
        if ((uVar1 & 0x10) != 0) {
          *(ushort *)(param_2 + 0x44) = uVar1 & 0xffee;
          _wakeup(param_2);
        }
      }
      else {
        _iput(uVar4);
      }
      uVar4 = _iget((int)*(short *)(uVar4 + 0x46),*(undefined4 *)(uVar4 + 0x50),iVar2);
    } while (uVar4 != 0);
    local_c = (int)*(char *)(DAT_001e875c + 0x68);
LAB_0013f87f:
    if (pbVar6 != (byte *)0x0) {
      _byte_swap_dir_block_out(pbVar6);
      _brelse(pbVar6);
    }
  }
  if ((DAT_001ddf38 & 2) != 0) {
    _wakeup(&DAT_001ddf38);
  }
  DAT_001ddf38 = 0;
  if ((uVar4 != 0) && (param_2 != uVar4)) {
    _iput(uVar4);
    while ((*(ushort *)(param_2 + 0x44) & 1) != 0) {
      *(ushort *)(param_2 + 0x44) = *(ushort *)(param_2 + 0x44) | 0x10;
      _sleep(param_2);
    }
    *(byte *)(param_2 + 0x44) = *(byte *)(param_2 + 0x44) | 1;
    if ((local_c == 0) && (*(short *)(param_2 + 0x66) == 0)) {
      local_c = 2;
    }
  }
  return local_c;
}

