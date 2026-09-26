/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0019bbe0 */

void FUN_0019bbe0(int param_1)

{
  int iVar1;
  uint uVar2;
  undefined1 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined2 *puVar8;
  
  iVar7 = *(int *)(param_1 + 0x90) + *(int *)(param_1 + 0xa4) * 0xc;
  iVar1 = iVar7 + 0xc;
  iVar5 = *(int *)(param_1 + 0xa8) * 8 + *(int *)(param_1 + 0x8c);
  do {
    if (iVar1 <= iVar7) {
      return;
    }
    uVar2 = *(uint *)(param_1 + 0x1c);
    if (uVar2 < 4) {
      if (uVar2 < 2) {
        if (uVar2 != 1) goto LAB_0019bd18;
        puVar3 = (undefined1 *)(iVar7 * *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x18) + iVar5)
        ;
        iVar6 = 7;
        do {
          *puVar3 = *(undefined1 *)(param_1 + 0xb0);
          puVar3 = puVar3 + 1;
          iVar6 = iVar6 + -1;
        } while (-1 < iVar6);
      }
      else {
        if (uVar2 < 4) {
          if (uVar2 < 2) {
            if (uVar2 != 1) goto LAB_0019bccc;
            puVar8 = (undefined2 *)
                     (iVar5 + iVar7 * *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x18));
          }
          else {
            puVar8 = (undefined2 *)
                     (iVar7 * *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x18) + iVar5 * 2);
          }
        }
        else {
          if (uVar2 != 4) {
LAB_0019bccc:
                    /* WARNING: Subroutine does not return */
            _panic(s_FBConsole_PixelAddress__bogus_bi_001e4704);
          }
          puVar8 = (undefined2 *)
                   (iVar7 * *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x18) + iVar5 * 4);
        }
        iVar6 = 7;
        do {
          *puVar8 = *(undefined2 *)(param_1 + 0xb0);
          puVar8 = puVar8 + 1;
          iVar6 = iVar6 + -1;
        } while (-1 < iVar6);
      }
    }
    else {
      if (uVar2 != 4) {
LAB_0019bd18:
                    /* WARNING: Subroutine does not return */
        _panic(s_FBConsole_Erase__bogus_bits_per_p_001e477d);
      }
      puVar4 = (undefined4 *)
               (iVar7 * *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x18) + iVar5 * 4);
      iVar6 = 7;
      do {
        *puVar4 = *(undefined4 *)(param_1 + 0xb0);
        puVar4 = puVar4 + 1;
        iVar6 = iVar6 + -1;
      } while (-1 < iVar6);
    }
    iVar7 = iVar7 + 1;
  } while( true );
}

