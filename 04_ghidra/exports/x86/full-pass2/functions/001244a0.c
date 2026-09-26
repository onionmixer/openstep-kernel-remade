/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001244a0 */

undefined1 * FUN_001244a0(undefined4 param_1,int param_2,void *param_3)

{
  ushort uVar1;
  undefined1 *puVar2;
  
  puVar2 = (undefined1 *)_kalloc(0x148);
  _bzero(puVar2,0x148);
  *puVar2 = 0x45;
  uVar1 = _ip_id;
  _ip_id = _ip_id + 1;
  *(ushort *)(puVar2 + 4) = uVar1 >> 8 | uVar1 << 8;
  puVar2[8] = 0xff;
  puVar2[9] = 0x11;
  *(undefined4 *)(puVar2 + 0xc) = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)(puVar2 + 0x10) = 0xffffffff;
  *(undefined2 *)(puVar2 + 0x14) = 0x4400;
  *(undefined2 *)(puVar2 + 0x16) = 0x4300;
  *(undefined2 *)(puVar2 + 0x1a) = 0;
  puVar2[0x1c] = 1;
  puVar2[0x1d] = 1;
  puVar2[0x1e] = 6;
  *(undefined4 *)(puVar2 + 0x28) = 0;
  _bcopy(param_3,puVar2 + 0x38,6);
  _bcopy(&DAT_001dbab0,puVar2 + 0x108,4);
  puVar2[0x10c] = 1;
  puVar2[0x10e] = 0;
  *(undefined2 *)(puVar2 + 0x18) = 0x3401;
  *(undefined2 *)(puVar2 + 2) = 0x4801;
  *(undefined2 *)(puVar2 + 10) = 0;
  return puVar2;
}

