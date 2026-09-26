/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016b338 */

void _zone_init(void)

{
  _zone_map = _kmem_suballoc(_kernel_map,&_zone_min,&_zone_max,_zone_map_size,0);
  return;
}

