/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012b664 */

void _udp_ctlinput(uint param_1,undefined4 param_2,byte *param_3)

{
  undefined2 uVar1;
  undefined4 uVar2;
  undefined2 uVar3;
  
  if ((param_1 == 1) || ((param_1 < 0x16 && ((&_inetctlerrmap)[param_1] != '\0')))) {
    if (param_3 == (byte *)0x0) {
      uVar3 = 0;
      uVar1 = 0;
      uVar2 = _zeroin_addr;
    }
    else {
      uVar3 = *(undefined2 *)(param_3 + (*param_3 & 0xf) * 4);
      uVar1 = *(undefined2 *)(param_3 + (*param_3 & 0xf) * 4 + 2);
      uVar2 = *(undefined4 *)(param_3 + 0xc);
    }
    _in_pcbnotify(&_udb,param_2,uVar1,uVar2,uVar3,param_1,_udp_notify);
  }
  return;
}

