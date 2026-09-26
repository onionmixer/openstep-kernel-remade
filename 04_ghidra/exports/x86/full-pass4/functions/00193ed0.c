/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00193ed0 */

undefined4 _kernacc(uint param_1,int param_2,int param_3)

{
  byte *pbVar1;
  uint uVar2;
  
  uVar2 = param_1 & ~_page_mask;
  while( true ) {
    if (param_1 + param_2 <= uVar2) {
      return 1;
    }
    pbVar1 = (byte *)_pmap_pt_entry(_kernel_pmap,uVar2);
    if (((pbVar1 == (byte *)0x0) || ((*pbVar1 & 1) == 0)) ||
       ((param_3 == 0 && ((*pbVar1 & 6) == 0)))) break;
    uVar2 = uVar2 + _page_size;
  }
  return 0;
}

