/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001226cc */

void _arpinput(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  ushort uVar1;
  ushort local_c;
  ushort local_a;
  
  if ((-1 < *(char *)(param_1 + 0xc)) && (7 < *(ushort *)(param_4 + 8))) {
    _bcopy((void *)(param_4 + *(int *)(param_4 + 4)),&local_c,8);
    uVar1 = local_a >> 8 | local_a << 8;
    if ((((ushort)(local_c >> 8 | local_c << 8) == 1) &&
        (((uint)DAT_001db968 + (uint)DAT_001db969) * 2 + 8 <= (uint)(int)*(short *)(param_4 + 8)))
       && ((uVar1 == 0x800 || (uVar1 == 0x1000)))) {
      _in_arpinput(param_1,param_2,param_3,param_4);
      return;
    }
  }
  _m_freem(param_4);
  return;
}

