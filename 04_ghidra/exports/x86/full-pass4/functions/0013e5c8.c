/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0013e5c8 */

int FUN_0013e5c8(int param_1,char *param_2,size_t param_3,int *param_4,int *param_5)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  uint uVar6;
  uint uVar7;
  uint local_14;
  int local_10;
  int local_c;
  
  local_10 = 0;
  local_c = 0;
  uVar7 = 0;
  iVar1 = (param_3 + 4 & 0xfffffffc) + 8;
  uVar2 = *(int *)(param_1 + 0x6c) + 0x3ffU & 0xfffffc00;
  local_14 = 0;
  uVar6 = 0;
  if (uVar2 != 0) {
    do {
      if ((~*(uint *)(*(int *)(param_1 + 0x50) + 0x48) & uVar6) == 0) {
        if (local_c != 0) {
          _byte_swap_dir_block_out(local_c);
          _brelse(local_c);
        }
        local_c = _blkatoff(param_1,uVar6,0);
        if (local_c == 0) {
          return (int)*(char *)(DAT_001e875c + 0x68);
        }
        uVar7 = 0;
      }
      if ((*param_4 == 0) && ((uVar7 & 0x3ff) == 0)) {
        param_4[1] = -1;
        local_10 = 0;
      }
      piVar5 = (int *)(*(int *)(local_c + 0x20) + uVar7);
      if (((short)piVar5[1] == 0) || (iVar3 = FUN_0013f52c(param_1,piVar5,uVar7,uVar6), iVar3 != 0))
      {
        uVar4 = 0x400 - (uVar7 & 0x3ff);
      }
      else {
        if (*param_4 != 2) {
          uVar4 = (uint)*(ushort *)(piVar5 + 1);
          if (*piVar5 != 0) {
            uVar4 = (uVar4 - 8) - (*(ushort *)((int)piVar5 + 6) + 4 & 0xfffffffc);
          }
          if (0 < (int)uVar4) {
            if ((int)uVar4 < iVar1) {
              if (*param_4 == 0) {
                local_10 = local_10 + uVar4;
                if (param_4[1] == -1) {
                  param_4[1] = uVar6;
                }
                if (iVar1 <= local_10) {
                  *param_4 = 1;
                  param_4[2] = (*(ushort *)(piVar5 + 1) + uVar6) - param_4[1];
                }
              }
            }
            else {
              *param_4 = 2;
              param_4[1] = uVar6;
              param_4[2] = (uint)*(ushort *)(piVar5 + 1);
            }
          }
        }
        if ((((*piVar5 != 0) && (param_3 == *(ushort *)((int)piVar5 + 6))) &&
            (*param_2 == (char)piVar5[2])) &&
           (iVar3 = _bcmp(param_2,piVar5 + 2,param_3), iVar3 == 0)) {
          *(uint *)(param_1 + 0x4c) = uVar6;
          if (*(int *)(param_1 + 0x48) == *piVar5) {
            *param_5 = param_1;
            *(short *)(param_1 + 0x12) = *(short *)(param_1 + 0x12) + 1;
          }
          else {
            iVar1 = _iget((int)*(short *)(param_1 + 0x46),*(undefined4 *)(param_1 + 0x50),*piVar5);
            *param_5 = iVar1;
            if (iVar1 == 0) {
              _byte_swap_dir_block_out(local_c);
              _brelse(local_c);
              return (int)*(char *)(DAT_001e875c + 0x68);
            }
          }
          *param_4 = 3;
          param_4[1] = uVar6;
          param_4[2] = uVar6 - local_14;
          param_4[3] = local_c;
          param_4[4] = (int)piVar5;
          return 0;
        }
        uVar4 = (uint)*(ushort *)(piVar5 + 1);
        local_14 = uVar6;
      }
      uVar6 = uVar6 + uVar4;
      uVar7 = uVar7 + uVar4;
    } while (uVar6 < uVar2);
  }
  if (local_c != 0) {
    _byte_swap_dir_block_out(local_c);
    _brelse(local_c);
  }
  if (*param_4 == 0) {
    param_4[1] = uVar2;
    param_4[2] = 0x400;
  }
  *param_5 = 0;
  return 0;
}

