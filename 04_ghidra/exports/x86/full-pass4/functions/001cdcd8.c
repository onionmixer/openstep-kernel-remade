/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001cdcd8 */

int __objc_create_zone(void)

{
  if (DAT_001e55b4 == 0) {
    DAT_001e55b4 = _NXCreateZone(0x2000,0x2000,1);
    _NXNameZone(DAT_001e55b4,"ObjC");
  }
  return DAT_001e55b4;
}

