/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0019ba18 */

void FUN_0019ba18(int param_1)

{
  int iVar1;
  int iVar2;
  short sVar3;
  int iVar4;
  byte *pbVar5;
  uint *puVar6;
  uint uVar7;
  byte local_1c;
  short *local_c;
  
  iVar2 = *(int *)(param_1 + 0x90) + *(int *)(param_1 + 0xa4) * 0xc;
  iVar1 = iVar2 + 0xc;
  iVar4 = *(int *)(param_1 + 0xa8) * 8 + *(int *)(param_1 + 0x8c);
  do {
    if (iVar1 <= iVar2) {
      return;
    }
    uVar7 = *(uint *)(param_1 + 0x1c);
    if (uVar7 < 4) {
      if (uVar7 < 2) {
        if (uVar7 != 1) goto LAB_0019bbb8;
        pbVar5 = (byte *)(iVar4 + iVar2 * *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x18));
        uVar7 = 0;
        do {
          if ((uint)*pbVar5 == (*(uint *)(param_1 + 0xb0) & 0xffff)) {
            *pbVar5 = *(byte *)(param_1 + 0xb4);
          }
          else {
            local_1c = (byte)*(uint *)(param_1 + 0xb0);
            *pbVar5 = local_1c;
          }
          pbVar5 = pbVar5 + 1;
          uVar7 = uVar7 + 1;
        } while (uVar7 < 8);
      }
      else {
        if (uVar7 < 4) {
          if (uVar7 < 2) {
            if (uVar7 != 1) goto LAB_0019bb2c;
            local_c = (short *)(iVar2 * *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x18) + iVar4)
            ;
          }
          else {
            local_c = (short *)(iVar2 * *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x18) +
                               iVar4 * 2);
          }
        }
        else {
          if (uVar7 != 4) {
LAB_0019bb2c:
                    /* WARNING: Subroutine does not return */
            _panic(s_FBConsole_PixelAddress__bogus_bi_001e4704);
          }
          local_c = (short *)(iVar2 * *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x18) +
                             iVar4 * 4);
        }
        uVar7 = 0;
        do {
          sVar3 = (short)*(undefined4 *)(param_1 + 0xb0);
          if (*local_c == sVar3) {
            *local_c = *(short *)(param_1 + 0xb4);
          }
          else {
            *local_c = sVar3;
          }
          local_c = local_c + 1;
          uVar7 = uVar7 + 1;
        } while (uVar7 < 8);
      }
    }
    else {
      if (uVar7 != 4) {
LAB_0019bbb8:
                    /* WARNING: Subroutine does not return */
        _panic(s_FBConsole_FlipCursor__bogus_bits_001e4752);
      }
      puVar6 = (uint *)(iVar2 * *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x18) + iVar4 * 4);
      uVar7 = 0;
      do {
        if ((*puVar6 & 0xffffff) == (*(uint *)(param_1 + 0xb0) & 0xffffff)) {
          *puVar6 = *(uint *)(param_1 + 0xb4);
        }
        else {
          *puVar6 = *(uint *)(param_1 + 0xb0);
        }
        puVar6 = puVar6 + 1;
        uVar7 = uVar7 + 1;
      } while (uVar7 < 8);
    }
    iVar2 = iVar2 + 1;
  } while( true );
}

