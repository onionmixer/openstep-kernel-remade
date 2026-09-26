/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0013c958 */

int _alloccgblk(int param_1,int param_2,uint param_3)

{
  short *psVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int local_8;
  
  if (param_3 == 0) {
    param_3 = *(int *)(param_2 + 0x28);
  }
  else {
    param_3 = (int)(param_3 & -*(int *)(param_1 + 0x38)) % *(int *)(param_1 + 0xbc);
    iVar7 = _isblock(param_1,param_2 + 0x3d8,
                     (int)param_3 >> ((byte)*(undefined4 *)(param_1 + 0x60) & 0x1f));
    local_8 = param_3;
    if (iVar7 != 0) goto LAB_0013cb61;
    iVar7 = *(int *)(param_1 + 0x7c);
    iVar9 = *(int *)(param_1 + 0xac);
    iVar6 = (int)(param_3 * iVar7) / iVar9;
    if (*(int *)(param_2 + 0x54 + iVar6 * 4) != 0) {
      if (*(int *)(param_1 + 0x358) == 0) {
        param_3 = (iVar7 + -1 + iVar9 * iVar6) / iVar7;
      }
      else {
        iVar3 = param_2 + 0xd4 + iVar6 * 0x10;
        iVar9 = ((((int)(param_3 * iVar7) % iVar9) % *(int *)(param_1 + 0xa8)) * 8) /
                *(int *)(param_1 + 0xa8);
        for (iVar7 = iVar9; (iVar7 < 8 && (*(short *)(iVar3 + iVar7 * 2) < 1)); iVar7 = iVar7 + 1) {
        }
        if ((iVar7 == 8) && (iVar7 = 0, 0 < iVar9)) {
          do {
            if (0 < *(short *)(iVar3 + iVar7 * 2)) goto LAB_0013ca68;
            iVar7 = iVar7 + 1;
          } while (iVar7 < iVar9);
        }
        if (0 < *(short *)(iVar3 + iVar7 * 2)) {
LAB_0013ca68:
          iVar10 = iVar6 % *(int *)(param_1 + 0x358);
          iVar3 = *(int *)(param_1 + 0xac);
          uVar4 = *(undefined4 *)(param_1 + 0x60);
          iVar5 = *(int *)(param_1 + 0x7c);
          iVar9 = param_1 + 0x35c + iVar10 * 0x10;
          if (*(short *)(iVar9 + iVar7 * 2) == -1) {
            _printf(s_pos____d__i____d__fs____s_001ddb7e,iVar10,iVar7,param_1 + 0xd4);
                    /* WARNING: Subroutine does not return */
            _panic(s_alloccgblk__cyl_groups_corrupted_001ddb99);
          }
          iVar7 = (int)*(short *)(iVar9 + iVar7 * 2);
          while( true ) {
            local_8 = ((iVar6 - iVar10) * iVar3) / (iVar5 << ((byte)uVar4 & 0x1f)) + iVar7;
            iVar9 = _isblock(param_1,param_2 + 0x3d8,local_8);
            if (iVar9 != 0) break;
            uVar8 = (uint)*(byte *)(iVar7 + 0x560 + param_1);
            if ((uVar8 == 0) || (0x1a9cU - iVar7 < uVar8)) {
              _printf(s_pos____d__i____d__fs____s_001ddbba,iVar10,iVar7,param_1 + 0xd4);
                    /* WARNING: Subroutine does not return */
              _panic(s_alloccgblk__can_t_find_blk_in_cy_001ddbd5);
            }
            iVar7 = iVar7 + uVar8;
          }
          local_8 = local_8 << ((byte)*(undefined4 *)(param_1 + 0x60) & 0x1f);
          goto LAB_0013cb61;
        }
      }
    }
  }
  local_8 = _mapsearch(param_1,param_2,param_3,*(undefined4 *)(param_1 + 0x38));
  if (local_8 < 0) {
    return 0;
  }
  *(int *)(param_2 + 0x28) = local_8;
LAB_0013cb61:
  _clrblock(param_1,param_2 + 0x3d8,local_8 >> ((byte)*(undefined4 *)(param_1 + 0x60) & 0x1f));
  *(int *)(param_2 + 0x1c) = *(int *)(param_2 + 0x1c) + -1;
  *(int *)(param_1 + 0xc4) = *(int *)(param_1 + 0xc4) + -1;
  piVar2 = (int *)(*(int *)(param_1 + 0x2d8 +
                           ((int)*(uint *)(param_2 + 0xc) >>
                           ((byte)*(undefined4 *)(param_1 + 0x70) & 0x1f)) * 4) + 4 +
                  (*(uint *)(param_2 + 0xc) & ~*(uint *)(param_1 + 0x6c)) * 0x10);
  *piVar2 = *piVar2 + -1;
  iVar9 = local_8 * *(int *)(param_1 + 0x7c);
  iVar7 = iVar9 / *(int *)(param_1 + 0xac);
  psVar1 = (short *)(param_2 + 0xd4 + iVar7 * 0x10 +
                    (((iVar9 % *(int *)(param_1 + 0xac)) % *(int *)(param_1 + 0xa8) << 3) /
                    *(int *)(param_1 + 0xa8)) * 2);
  *psVar1 = *psVar1 + -1;
  piVar2 = (int *)(param_2 + 0x54 + iVar7 * 4);
  *piVar2 = *piVar2 + -1;
  *(char *)(param_1 + 0xd0) = *(char *)(param_1 + 0xd0) + '\x01';
  return *(int *)(param_2 + 0xc) * *(int *)(param_1 + 0xbc) + local_8;
}

