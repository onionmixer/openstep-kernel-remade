/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00160a20 */

void _us_abstimeout(undefined4 param_1,undefined4 param_2,int *param_3)

{
  longlong lVar1;
  uint uVar2;
  
  lVar1 = (longlong)*param_3 * 1000000 + (longlong)param_3[1];
  lVar1 = lVar1 + CONCAT44((int)((ulonglong)lVar1 >> 0x20) * 4 | (uint)lVar1 >> 0x1e,(uint)lVar1 * 4
                          );
  lVar1 = lVar1 + CONCAT44((int)((ulonglong)lVar1 >> 0x20) * 4 | (uint)lVar1 >> 0x1e,(uint)lVar1 * 4
                          );
  lVar1 = lVar1 + CONCAT44((int)((ulonglong)lVar1 >> 0x20) * 4 | (uint)lVar1 >> 0x1e,(uint)lVar1 * 4
                          );
  uVar2 = (uint)lVar1;
  _calloutDispatchDelayed
            (param_1,param_2,uVar2 * 8,(int)((ulonglong)lVar1 >> 0x20) * 8 | uVar2 >> 0x1d);
  return;
}

