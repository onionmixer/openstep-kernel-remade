/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0013baa0 */

byte * _realloccg(int param_1,int param_2,int param_3,uint param_4,uint param_5)

{
  int iVar1;
  byte *pbVar2;
  int iVar3;
  uint *puVar4;
  int iVar5;
  uint local_8;
  
  iVar3 = *(int *)(param_1 + 0x50);
  if ((((*(uint *)(iVar3 + 0x30) < param_4) || ((param_4 & ~*(uint *)(iVar3 + 0x4c)) != 0)) ||
      (*(uint *)(iVar3 + 0x30) < param_5)) || ((param_5 & ~*(uint *)(iVar3 + 0x4c)) != 0)) {
    _printf(s_dev___0x_x__bsize____d__osize_____001dda43,(int)*(short *)(param_1 + 0x46),
            *(undefined4 *)(iVar3 + 0x30),param_4,param_5,iVar3 + 0xd4);
                    /* WARNING: Subroutine does not return */
    _panic(s_realloccg__bad_size_001dda7c);
  }
  if ((*(short *)(*(int *)(_active_u + 0x1c) + 2) == 0) ||
     (iVar5 = (*(int *)(iVar3 + 0xc4) << ((byte)*(undefined4 *)(iVar3 + 0x60) & 0x1f)) +
              *(int *)(iVar3 + 0xcc),
     iVar1 = (*(int *)(iVar3 + 0x28) * *(int *)(iVar3 + 0x3c)) / 100,
     iVar5 != iVar1 && -1 < iVar5 - iVar1)) {
    if (param_2 == 0) {
      _printf(s_dev___0x_x__bsize____d__bprev_____001dda90,(int)*(short *)(param_1 + 0x46),
              *(undefined4 *)(iVar3 + 0x30),0,iVar3 + 0xd4);
                    /* WARNING: Subroutine does not return */
      _panic(s_realloccg__bad_bprev_001ddabd);
    }
    iVar1 = param_2 / *(int *)(iVar3 + 0xbc);
    iVar5 = _fragextend(param_1,iVar1,param_2,param_4,param_5);
    if (iVar5 != 0) {
      do {
        pbVar2 = (byte *)_bread(*(undefined4 *)(param_1 + 0x40),
                                iVar5 << ((byte)*(undefined4 *)(iVar3 + 100) & 0x1f),param_4);
        if ((*pbVar2 & 4) != 0) {
          _brelse(pbVar2);
          return (byte *)0x0;
        }
        iVar1 = _brealloc(pbVar2,param_5);
      } while (iVar1 == 0);
      *pbVar2 = *pbVar2 | 2;
      _bzero((void *)(param_4 + *(int *)(pbVar2 + 0x20)),param_5 - param_4);
      iVar3 = (**(code **)(*(int *)(param_1 + 0x28) + 0x80))(param_1 + 0xc);
      *(int *)(param_1 + 0xcc) = *(int *)(param_1 + 0xcc) + (int)(param_5 - param_4) / iVar3;
      *(byte *)(param_1 + 0x44) = *(byte *)(param_1 + 0x44) | 0x42;
      return pbVar2;
    }
    if (*(int *)(iVar3 + 0x24) <= param_3) {
      param_3 = 0;
    }
    if (*(int *)(iVar3 + 0x80) == 0) {
      local_8 = *(uint *)(iVar3 + 0x30);
      if (((*(int *)(iVar3 + 0x3c) + -2) * *(int *)(iVar3 + 0x28)) / 100 <= *(int *)(iVar3 + 0xcc))
      {
        _log(5,s__s__optimization_changed_from_TI_001ddaff,iVar3 + 0xd4);
        *(undefined4 *)(iVar3 + 0x80) = 1;
      }
    }
    else if (*(int *)(iVar3 + 0x80) == 1) {
      local_8 = param_5;
      if ((4 < *(int *)(iVar3 + 0x3c)) &&
         (*(int *)(iVar3 + 0xcc) <= (*(int *)(iVar3 + 0x3c) * *(int *)(iVar3 + 0x28)) / 200)) {
        _log(5,s__s__optimization_changed_from_SP_001ddad2,iVar3 + 0xd4);
        *(undefined4 *)(iVar3 + 0x80) = 0;
      }
    }
    else {
      *(undefined4 *)(iVar3 + 0x80) = 1;
      local_8 = param_5;
    }
    iVar1 = _hashalloc(param_1,iVar1,param_3,local_8,_alloccg);
    if (0 < iVar1) {
      puVar4 = (uint *)_bread(*(undefined4 *)(param_1 + 0x40),
                              param_2 << ((byte)*(undefined4 *)(iVar3 + 100) & 0x1f),param_4);
      if ((*puVar4 & 4) != 0) {
        _brelse(puVar4);
        return (byte *)0x0;
      }
      pbVar2 = (byte *)_getblk(*(undefined4 *)(param_1 + 0x40),
                               iVar1 << ((byte)*(undefined4 *)(iVar3 + 100) & 0x1f),param_5);
      _bcopy((void *)puVar4[8],*(void **)(pbVar2 + 0x20),param_4);
      _bzero((void *)(param_4 + *(int *)(pbVar2 + 0x20)),param_5 - param_4);
      if ((*puVar4 & 0x200) != 0) {
        *puVar4 = *puVar4 & 0xfffffdff;
        *(int *)(_active_u + 0x1a0) = *(int *)(_active_u + 0x1a0) + -1;
      }
      _brelse(puVar4);
      _free_block(param_1,param_2,param_4);
      if ((int)param_5 < (int)local_8) {
        _free_block(param_1,((int)param_5 >> ((byte)*(undefined4 *)(iVar3 + 0x54) & 0x1f)) + iVar1,
                    local_8 - param_5);
      }
      iVar3 = (**(code **)(*(int *)(param_1 + 0x28) + 0x80))(param_1 + 0xc);
      *(int *)(param_1 + 0xcc) = *(int *)(param_1 + 0xcc) + (int)(param_5 - param_4) / iVar3;
      *(byte *)(param_1 + 0x44) = *(byte *)(param_1 + 0x44) | 0x42;
      return pbVar2;
    }
  }
  if ((*(byte *)(iVar3 + 0xd3) & 1) == 0) {
    _fserr(iVar3,s_file_system_full_001dd9a0);
  }
  *(byte *)(iVar3 + 0xd3) = *(byte *)(iVar3 + 0xd3) | 1;
  if ((*(byte *)(_active_u + 0x260) & 8) == 0) {
    _uprintf(s__s___s_001dda0e,iVar3 + 0xd4,s_write_failed__file_system_is_ful_001dd9b1);
  }
  if (*(int *)(DAT_001e875c + 0x6c) == 0) {
    *(int *)(DAT_001e875c + 0x6c) = iVar3;
    *(undefined1 *)(DAT_001e875c + 0x70) = 1;
  }
  *(undefined1 *)(DAT_001e875c + 0x68) = 0x1c;
  return (byte *)0x0;
}

