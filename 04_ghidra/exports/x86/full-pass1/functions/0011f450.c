/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011f450 */

undefined4 _looutput(undefined4 param_1,undefined4 param_2,short *param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (*param_3 == 2) {
    _inet_queue(param_1,param_2);
    iVar2 = _if_opackets(param_1);
    _if_opackets_set(param_1,iVar2 + 1);
    iVar2 = _if_ipackets(param_1);
    _if_ipackets_set(param_1,iVar2 + 1);
    uVar1 = 0;
  }
  else {
    _nb_free(param_2);
    uVar1 = 0x2f;
  }
  return uVar1;
}

