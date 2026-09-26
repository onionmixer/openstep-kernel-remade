/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0013f5e4 */

undefined4 FUN_0013f5e4(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int local_20;
  int local_1c;
  ushort local_18;
  ushort local_16;
  char local_14;
  char local_13;
  
  uVar2 = 0;
  if (*(int *)(param_1 + 0x6c) != 0) {
    do {
      iVar1 = _rdwri(0,param_1,&local_1c,0xc,uVar2,1,&local_20);
      if ((((iVar1 != 0) || (local_20 != 0)) || (local_18 == 0)) ||
         ((local_1c != 0 &&
          (((2 < local_16 || (local_14 != '.')) ||
           ((local_16 != 1 && ((local_13 != '.' || (param_2 != local_1c)))))))))) {
        return 0;
      }
      uVar2 = uVar2 + local_18;
    } while (uVar2 < *(uint *)(param_1 + 0x6c));
  }
  return 1;
}

