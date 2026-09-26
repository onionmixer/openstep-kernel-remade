/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0019bd3c */

void FUN_0019bd3c(int param_1,char param_2)

{
  undefined1 uVar1;
  byte bVar2;
  undefined2 uVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined1 *puVar6;
  undefined4 *puVar7;
  undefined2 *puVar8;
  int iVar9;
  int iVar10;
  byte *local_c;
  
  FUN_0019bbe0(param_1);
  if ('\x1f' < param_2) {
    local_c = (byte *)(s_Prima_di_spegnere_il_computer__a_001e406e + param_2 * 0xc + 0xe);
    iVar9 = *(int *)(param_1 + 0x8c) + *(int *)(param_1 + 0xa8) * 8;
    iVar10 = *(int *)(param_1 + 0x90) + *(int *)(param_1 + 0xa4) * 0xc;
    uVar4 = *(uint *)(param_1 + 0x1c);
    if (uVar4 < 4) {
      if (uVar4 < 2) {
        if (uVar4 == 1) {
          uVar1 = *(undefined1 *)(param_1 + 0xb4);
          puVar6 = (undefined1 *)
                   (iVar10 * *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x18) + iVar9);
          iVar10 = 0xc;
          do {
            bVar2 = *local_c;
            local_c = local_c + 1;
            if ((char)bVar2 < '\0') {
              *puVar6 = uVar1;
            }
            if ((bVar2 & 0x40) != 0) {
              puVar6[1] = uVar1;
            }
            if ((bVar2 & 0x20) != 0) {
              puVar6[2] = uVar1;
            }
            if ((bVar2 & 0x10) != 0) {
              puVar6[3] = uVar1;
            }
            if ((bVar2 & 8) != 0) {
              puVar6[4] = uVar1;
            }
            if ((bVar2 & 4) != 0) {
              puVar6[5] = uVar1;
            }
            if ((bVar2 & 2) != 0) {
              puVar6[6] = uVar1;
            }
            if ((bVar2 & 1) != 0) {
              puVar6[7] = uVar1;
            }
            puVar6 = puVar6 + *(int *)(param_1 + 0x10);
            iVar10 = iVar10 + -1;
          } while (iVar10 != 0);
        }
      }
      else {
        uVar3 = *(undefined2 *)(param_1 + 0xb4);
        if (uVar4 < 4) {
          if (uVar4 < 2) {
            if (uVar4 != 1) goto LAB_0019be90;
            puVar8 = (undefined2 *)
                     (iVar9 + iVar10 * *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x18));
          }
          else {
            puVar8 = (undefined2 *)
                     (iVar10 * *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x18) + iVar9 * 2);
          }
        }
        else {
          if (uVar4 != 4) {
LAB_0019be90:
                    /* WARNING: Subroutine does not return */
            _panic(s_FBConsole_PixelAddress__bogus_bi_001e4704);
          }
          puVar8 = (undefined2 *)
                   (iVar10 * *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x18) + iVar9 * 4);
        }
        iVar10 = 0xc;
        do {
          bVar2 = *local_c;
          local_c = local_c + 1;
          if ((char)bVar2 < '\0') {
            *puVar8 = uVar3;
          }
          if ((bVar2 & 0x40) != 0) {
            puVar8[1] = uVar3;
          }
          if ((bVar2 & 0x20) != 0) {
            puVar8[2] = uVar3;
          }
          if ((bVar2 & 0x10) != 0) {
            puVar8[3] = uVar3;
          }
          if ((bVar2 & 8) != 0) {
            puVar8[4] = uVar3;
          }
          if ((bVar2 & 4) != 0) {
            puVar8[5] = uVar3;
          }
          if ((bVar2 & 2) != 0) {
            puVar8[6] = uVar3;
          }
          if ((bVar2 & 1) != 0) {
            puVar8[7] = uVar3;
          }
          puVar8 = (undefined2 *)((int)puVar8 + *(int *)(param_1 + 0x10));
          iVar10 = iVar10 + -1;
        } while (iVar10 != 0);
      }
    }
    else if (uVar4 == 4) {
      uVar5 = *(undefined4 *)(param_1 + 0xb4);
      puVar7 = (undefined4 *)
               (iVar10 * *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x18) + iVar9 * 4);
      iVar10 = 0xc;
      do {
        bVar2 = *local_c;
        local_c = local_c + 1;
        if ((char)bVar2 < '\0') {
          *puVar7 = uVar5;
        }
        if ((bVar2 & 0x40) != 0) {
          puVar7[1] = uVar5;
        }
        if ((bVar2 & 0x20) != 0) {
          puVar7[2] = uVar5;
        }
        if ((bVar2 & 0x10) != 0) {
          puVar7[3] = uVar5;
        }
        if ((bVar2 & 8) != 0) {
          puVar7[4] = uVar5;
        }
        if ((bVar2 & 4) != 0) {
          puVar7[5] = uVar5;
        }
        if ((bVar2 & 2) != 0) {
          puVar7[6] = uVar5;
        }
        if ((bVar2 & 1) != 0) {
          puVar7[7] = uVar5;
        }
        puVar7 = (undefined4 *)((int)puVar7 + *(int *)(param_1 + 0x10));
        iVar10 = iVar10 + -1;
      } while (iVar10 != 0);
    }
    *(int *)(param_1 + 0xa8) = *(int *)(param_1 + 0xa8) + 1;
  }
  return;
}

