/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0013477c */

undefined4 _xdr_getrddirres(XDR *param_1,int param_2)

{
  boolean_t bVar1;
  uint *puVar2;
  uint uVar3;
  uint local_c;
  boolean_t local_8;
  
  local_c = 0xffffffff;
  bVar1 = _xdr_enum(param_1,(int *)(param_2 + 4));
  if (bVar1 != 0) {
    if (*(int *)(param_2 + 4) != 0) {
      return 1;
    }
    uVar3 = *(uint *)(param_2 + 0xc);
    puVar2 = *(uint **)(param_2 + 0x14);
    while (bVar1 = _xdr_bool(param_1,&local_8), bVar1 != 0) {
      if (local_8 == 0) {
        bVar1 = _xdr_bool(param_1,(boolean_t *)(param_2 + 0x10));
        if (bVar1 == 0) {
          return 0;
        }
        *(int *)(param_2 + 0xc) = (int)puVar2 - *(int *)(param_2 + 0x14);
        *(uint *)(param_2 + 8) = local_c;
        return 1;
      }
      if ((int)uVar3 < 6) {
        return 0;
      }
      bVar1 = _xdr_u_long(param_1,puVar2);
      if (bVar1 == 0) {
        return 0;
      }
      bVar1 = _xdr_u_short(param_1,(ushort *)((int)puVar2 + 6));
      if (bVar1 == 0) {
        return 0;
      }
      if (uVar3 < (*(ushort *)((int)puVar2 + 6) + 0xc & 0xfffffffc)) {
        return 0;
      }
      bVar1 = _xdr_opaque(param_1,(char *)(puVar2 + 2),(uint)*(ushort *)((int)puVar2 + 6));
      if (bVar1 == 0) {
        return 0;
      }
      bVar1 = _xdr_u_long(param_1,&local_c);
      if (bVar1 == 0) {
        return 0;
      }
      *(ushort *)(puVar2 + 1) = *(short *)((int)puVar2 + 6) + 0xcU & 0xfffc;
      *(undefined1 *)(*(ushort *)((int)puVar2 + 6) + 8 + (int)puVar2) = 0;
      uVar3 = uVar3 - (ushort)puVar2[1];
      if ((int)uVar3 < 0) {
        return 0;
      }
      puVar2 = (uint *)((int)puVar2 + (uint)(ushort)puVar2[1]);
    }
  }
  return 0;
}

