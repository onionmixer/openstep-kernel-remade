/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001bd97c */

void _put_dl_un(uint *param_1,uint *param_2)

{
  uint *puVar1;
  uint uVar2;
  
  puVar1 = param_1 + 0x685;
  do {
    uVar2 = *param_1;
    *param_2 = uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
    param_2 = param_2 + 1;
    param_1 = param_1 + 1;
  } while ((int)param_1 <= (int)puVar1);
  return;
}

