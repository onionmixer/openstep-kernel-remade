/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00142434 */

undefined4 FUN_00142434(int param_1)

{
  int iVar1;
  int local_c;
  undefined4 *local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x10) + 4);
  if (iVar1 != 0) {
    local_8 = (undefined4 *)(*(int *)(param_1 + 0x10) + 4);
    while (iVar1 = FUN_00142600(iVar1,param_1,1,&local_8,&local_c), iVar1 != 0) {
      FUN_0014282c(local_c);
      switch(iVar1) {
      case 1:
        *local_8 = *(undefined4 *)(local_c + 0x14);
        FUN_0014286c(local_c);
        return 0;
      case 2:
        if (*(int *)(local_c + 4) != *(int *)(param_1 + 4)) {
          FUN_001427b4(local_c,param_1);
          *(undefined4 *)(local_c + 0x14) = *(undefined4 *)(param_1 + 0x14);
          return 0;
        }
        *(int *)(local_c + 4) = *(int *)(param_1 + 8) + 1;
        return 0;
      case 3:
        *local_8 = *(undefined4 *)(local_c + 0x14);
        iVar1 = *(int *)(local_c + 0x14);
        FUN_0014286c(local_c);
        break;
      case 4:
        *(int *)(local_c + 8) = *(int *)(param_1 + 4) + -1;
        local_8 = (undefined4 *)(local_c + 0x14);
        iVar1 = *(int *)(local_c + 0x14);
        break;
      case 5:
        *(int *)(local_c + 4) = *(int *)(param_1 + 8) + 1;
      default:
        goto switchD_0014249a_default;
      }
    }
  }
switchD_0014249a_default:
  return 0;
}

