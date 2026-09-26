/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001ba850 */

int FUN_001ba850(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  int local_10;
  int local_c;
  int local_8;
  
  piVar1 = *(int **)(param_1 + 0x8c);
  do {
    if ((int *)(param_1 + 0x8c) == piVar1) {
      iVar2 = 0;
LAB_001ba8a1:
      *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + iVar2;
      _objc_msgSend(*(undefined4 *)(param_1 + 4),PTR_s_incrementClipCount__001f9700,local_10);
      if (*(char *)(param_1 + 0x94) != '\0') {
        _audio_add_peak(*(undefined4 *)(param_1 + 0x9c),local_8,param_1 + 0xa4,
                        *(undefined4 *)(param_1 + 0x98));
        _audio_add_peak(*(undefined4 *)(param_1 + 0xa0),local_c,param_1 + 0xa4,
                        *(undefined4 *)(param_1 + 0x98));
      }
      return param_1;
    }
    if (*piVar1 == param_4) {
      iVar2 = piVar1[1];
      piVar1[1] = 0;
      local_8 = piVar1[2];
      local_c = piVar1[3];
      local_10 = piVar1[4];
      goto LAB_001ba8a1;
    }
    piVar1 = (int *)piVar1[5];
  } while( true );
}

