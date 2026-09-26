/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00190b5c */

void _pmap_change_wiring(int *param_1,uint param_2,int param_3)

{
  undefined4 uVar1;
  uint *puVar2;
  int iVar3;
  byte *pbVar4;
  
  uVar1 = _splvm();
  puVar2 = (uint *)((param_2 >> 0x16) * 4 + *param_1);
  if (((*puVar2 & 1) != 0) && (iVar3 = (*puVar2 & 0xfffff000) + (param_2 >> 10 & 0xffc), iVar3 != 0)
     ) {
    if (param_3 == 0) {
      if ((*(byte *)(iVar3 + 1) & 2) != 0) {
        FUN_001910e4(param_1,param_2);
      }
    }
    else if ((*(byte *)(iVar3 + 1) & 2) == 0) {
      FUN_0019108c(param_1,param_2);
    }
    if (0 < _ptes_per_vm_page) {
      pbVar4 = (byte *)(iVar3 + 1);
      iVar3 = _ptes_per_vm_page;
      do {
        iVar3 = iVar3 + -1;
        *pbVar4 = *pbVar4 & 0xfd | ((byte)param_3 & 1) * '\x02';
        pbVar4 = pbVar4 + 4;
      } while (0 < iVar3);
    }
    _splx(uVar1);
    return;
  }
                    /* WARNING: Subroutine does not return */
  _panic(s_pmap_change_wiring_001e25a6);
}

