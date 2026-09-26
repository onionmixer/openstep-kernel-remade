/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010d850 */

void _soo_rw(int param_1,int param_2,int param_3)

{
  code *pcVar1;
  
  if (((*(byte *)(*_active_u + 0x16) & 2) != 0) && ((*(uint *)(param_1 + 8) & 0x2000) != 0)) {
    *(short *)(param_3 + 0x10) = (short)*(uint *)(param_1 + 8);
  }
  pcVar1 = _sosend;
  if (param_2 == 0) {
    pcVar1 = _soreceive;
  }
  (*pcVar1)(*(undefined4 *)(param_1 + 0x18),0,param_3,0,0);
  return;
}

