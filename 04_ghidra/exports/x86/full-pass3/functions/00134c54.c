/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00134c54 */

undefined4 _xdr_statfs(XDR *param_1,int *param_2)

{
  boolean_t bVar1;
  
  bVar1 = _xdr_union(param_1,param_2,(char *)(param_2 + 1),(xdr_discrim *)&_statfs_discrim,_xdr_void
                    );
  if (bVar1 == 0) {
    return 0;
  }
  return 1;
}

