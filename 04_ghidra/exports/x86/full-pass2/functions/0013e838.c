/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0013e838 */

int FUN_0013e838(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
                int param_6,int param_7)

{
  short sVar1;
  int iVar2;
  bool bVar3;
  
  if ((*(int *)(param_3 + 0x30) == *(int *)(param_6 + 0x30)) &&
     (*(int *)(param_2 + 0x30) == *(int *)(param_6 + 0x30))) {
    if (*(int *)(param_2 + 0x48) == *(int *)(param_6 + 0x48)) {
      iVar2 = -1;
    }
    else {
      iVar2 = _iaccess(param_3,0x80);
      if (iVar2 == 0) {
        if (((((*(byte *)(param_3 + 0x65) & 2) == 0) ||
             (sVar1 = *(short *)(*(int *)(_active_u + 0x1c) + 2), sVar1 == 0)) ||
            (*(short *)(param_3 + 0x68) == sVar1)) || (*(short *)(param_6 + 0x68) == sVar1)) {
          bVar3 = (*(ushort *)(param_2 + 100) & 0xf000) == 0x4000;
          if ((*(ushort *)(param_6 + 100) & 0xf000) == 0x4000) {
            if (!bVar3) {
              return 0x15;
            }
            iVar2 = FUN_0013f5e4(param_6,*(undefined4 *)(param_3 + 0x48));
            if ((iVar2 == 0) || (2 < *(short *)(param_6 + 0x66))) {
              return 0x42;
            }
          }
          else if (bVar3) {
            return 0x14;
          }
          _dnlc_remove(param_3 + 0xc,param_4);
          **(undefined4 **)(param_7 + 0x10) = *(undefined4 *)(param_2 + 0x48);
          _dnlc_enter(param_3 + 0xc,param_4,param_2 + 0xc,0);
          _byte_swap_dir_block_out(*(undefined4 *)(param_7 + 0xc));
          _bwrite(*(undefined4 *)(param_7 + 0xc));
          *(undefined4 *)(param_7 + 0xc) = 0;
          if (*(char *)(DAT_001e875c + 0x68) == '\0') {
            *(byte *)(param_3 + 0x44) = *(byte *)(param_3 + 0x44) | 0x42;
            *(short *)(param_6 + 0x66) = *(short *)(param_6 + 0x66) + -1;
            *(byte *)(param_6 + 0x44) = *(byte *)(param_6 + 0x44) | 0x40;
            if (bVar3) {
              sVar1 = *(short *)(param_6 + 0x66);
              *(short *)(param_6 + 0x66) = sVar1 + -1;
              if (sVar1 != 1) {
                    /* WARNING: Subroutine does not return */
                _panic(s_direnter__target_directory_link_c_001dde1d);
              }
              _itrunc(param_6,0);
              *(short *)(param_3 + 0x66) = *(short *)(param_3 + 0x66) + -1;
              *(byte *)(param_3 + 0x44) = *(byte *)(param_3 + 0x44) | 0x40;
              if ((param_1 != param_3) &&
                 (iVar2 = FUN_0013e9f8(param_2,param_1,param_3), iVar2 != 0)) {
                return iVar2;
              }
            }
            iVar2 = 0;
          }
          else {
            iVar2 = (int)*(char *)(DAT_001e875c + 0x68);
          }
        }
        else {
          iVar2 = 1;
        }
      }
    }
  }
  else {
    iVar2 = 0x12;
  }
  return iVar2;
}

