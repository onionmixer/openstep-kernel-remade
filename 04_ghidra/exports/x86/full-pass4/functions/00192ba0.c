/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00192ba0 */

void __i386_backtrace(uint *param_1,int param_2)

{
  uint *puVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < param_2) {
    do {
      if ((uint *)0x40000000 < param_1) {
LAB_00192c08:
        _safe_prf(s_invalid_frame_pointer__x_001e2880,*param_1);
        return;
      }
      _safe_prf(s_frame__x_called_by__x_001e2857,param_1,param_1[1]);
      _safe_prf(s_args__x__x__x__x_001e286e,param_1[2],param_1[3],param_1[4],param_1[5]);
      puVar1 = (uint *)*param_1;
      if ((puVar1 < param_1) || (0x10000 < (int)puVar1 - (int)param_1 >> 3)) goto LAB_00192c08;
      iVar2 = iVar2 + 1;
      param_1 = puVar1;
    } while (iVar2 < param_2);
  }
  return;
}

