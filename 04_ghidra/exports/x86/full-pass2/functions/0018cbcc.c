/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018cbcc */

void _ldt_init(void)

{
  undefined *puVar1;
  
  puVar1 = _ldt;
  *(undefined2 *)(_ldt + 10) = 0;
  puVar1[0xc] = 0;
  puVar1[0xf] = 0;
  puVar1[0xd] = 0xfa;
  puVar1[0xe] = puVar1[0xe] | 0xc0;
  *(undefined2 *)(puVar1 + 8) = 0xffff;
  puVar1[0xe] = puVar1[0xe] & 0xf0 | 0xb;
  puVar1 = _ldt;
  *(undefined2 *)(_ldt + 0x12) = 0;
  puVar1[0x14] = 0;
  puVar1[0x17] = 0;
  puVar1[0x15] = 0xf2;
  puVar1[0x16] = puVar1[0x16] | 0xc0;
  *(undefined2 *)(puVar1 + 0x10) = 0xffff;
  puVar1[0x16] = puVar1[0x16] | 0xf;
  return;
}

