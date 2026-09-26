/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016bad0 */

void _zone_reclaim(void)

{
  do {
  } while (_zget_space_lock != 0);
  LOCK();
  _zget_space_lock = 1;
  UNLOCK();
  _zone_free_space_reclaim();
  return;
}

