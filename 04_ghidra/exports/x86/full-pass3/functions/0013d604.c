/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0013d604 */

int _mapsearch(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint local_18;
  
  if (param_3 == 0) {
    param_3 = *(int *)(param_2 + 0x2c);
    if (param_3 < 0) {
      param_3 = param_3 + 7;
    }
  }
  else {
    param_3 = param_3 % *(int *)(param_1 + 0xbc);
    if (param_3 < 0) {
      param_3 = param_3 + 7;
    }
  }
  local_18 = param_3 >> 3;
  iVar1 = *(int *)(param_1 + 0xbc) + 7;
  if (iVar1 < 0) {
    iVar1 = *(int *)(param_1 + 0xbc) + 0xe;
  }
  iVar6 = (iVar1 >> 3) - local_18;
  iVar1 = _scanc(iVar6,param_2 + 0x3d8 + local_18,
                 *(undefined4 *)(&_fragtbl + *(int *)(param_1 + 0x38) * 4),
                 1 << ((char)param_4 + -1 + (char)*(int *)(param_1 + 0x38) % '\b' & 0x1fU));
  if (iVar1 == 0) {
    iVar6 = local_18 + 1;
    local_18 = 0;
    iVar1 = _scanc(iVar6,param_2 + 0x3d8,*(undefined4 *)(&_fragtbl + *(int *)(param_1 + 0x38) * 4),
                   1 << ((char)param_4 + -1 + (char)*(int *)(param_1 + 0x38) % '\b' & 0x1fU));
    if (iVar1 == 0) {
      _printf(s_start____d__len____d__fs____s_001ddd8d,0,iVar6,param_1 + 0xd4);
                    /* WARNING: Subroutine does not return */
      _panic(s_alloccg__map_corrupted_001dddac);
    }
  }
  iVar6 = ((local_18 + iVar6) - iVar1) * 8;
  *(int *)(param_2 + 0x2c) = iVar6;
  iVar1 = iVar6 + 8;
  do {
    if (iVar1 <= iVar6) {
      _printf(s_bno____d__fs____s_001dddc3,iVar6,param_1 + 0xd4);
                    /* WARNING: Subroutine does not return */
      _panic(s_alloccg__block_not_in_map_001dddd6);
    }
    iVar2 = iVar6;
    if (iVar6 < 0) {
      iVar2 = iVar6 + 7;
    }
    local_18 = *(uint *)(&_around + param_4 * 4);
    uVar4 = *(uint *)(&_inside + param_4 * 4);
    iVar5 = 0;
    uVar3 = *(int *)(param_1 + 0x38) - param_4;
    if (uVar3 < 0x80000000) {
      do {
        if ((((int)(uint)*(byte *)((iVar2 >> 3) + 0x3d8 + param_2) >>
              ((char)iVar6 + (char)(iVar2 >> 3) * -8 & 0x1fU) &
             0xff >> (8U - (char)*(int *)(param_1 + 0x38) & 0x1f)) << 1 & local_18) == uVar4) {
          return iVar5 + iVar6;
        }
        local_18 = local_18 << 1;
        uVar4 = uVar4 * 2;
        iVar5 = iVar5 + 1;
      } while (iVar5 <= (int)uVar3);
    }
    iVar6 = iVar6 + *(int *)(param_1 + 0x38);
  } while( true );
}

