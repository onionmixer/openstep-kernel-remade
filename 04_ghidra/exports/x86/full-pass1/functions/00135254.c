/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00135254 */

undefined4 _xdr_authkern(XDR *param_1)

{
  boolean_t bVar1;
  short *psVar2;
  uint local_5c;
  int local_58;
  int local_54;
  char *local_50;
  uint local_4c [2];
  char *local_44 [16];
  
  psVar2 = (short *)(*(int *)(_active_u + 0x1c) + 10);
  local_54 = (int)*(short *)(*(int *)(_active_u + 0x1c) + 2);
  local_58 = (int)*(short *)(*(int *)(_active_u + 0x1c) + 4);
  local_50 = &_hostname;
  if (param_1->x_op == XDR_ENCODE) {
    local_5c = 0;
    do {
      if (*psVar2 == -1) break;
      local_44[local_5c] = (char *)(int)*psVar2;
      psVar2 = psVar2 + 1;
      local_5c = local_5c + 1;
    } while ((int)local_5c < 0x10);
    _getthetime(local_4c);
    bVar1 = _xdr_u_long(param_1,local_4c);
    if ((((bVar1 != 0) && (bVar1 = _xdr_string(param_1,&local_50,0xff), bVar1 != 0)) &&
        (bVar1 = _xdr_int(param_1,&local_54), bVar1 != 0)) &&
       ((bVar1 = _xdr_int(param_1,&local_58), bVar1 != 0 &&
        (bVar1 = _xdr_array(param_1,local_44,&local_5c,0x10,4,_xdr_int), bVar1 != 0)))) {
      return 1;
    }
  }
  return 0;
}

