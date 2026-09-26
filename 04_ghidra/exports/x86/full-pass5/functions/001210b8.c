/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001210b8 */

undefined4 _mbuf_read(undefined4 *param_1,void *param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    if (param_1 == (undefined4 *)0x0) {
      return 0xffffffff;
    }
    if ((uVar2 <= param_3) && (param_3 < (int)*(short *)(param_1 + 2) + uVar2)) {
      uVar1 = (int)*(short *)(param_1 + 2) - (param_3 - uVar2);
      if (param_4 < uVar1) {
        uVar1 = param_4;
      }
      _bcopy((void *)((int)param_1 + (param_3 - uVar2) + param_1[1]),param_2,uVar1);
      param_2 = (void *)((int)param_2 + uVar1);
      param_3 = param_3 + uVar1;
      param_4 = param_4 - uVar1;
      if (param_4 == 0) {
        return 0;
      }
    }
    uVar2 = uVar2 + (int)*(short *)(param_1 + 2);
    param_1 = (undefined4 *)*param_1;
  } while( true );
}

