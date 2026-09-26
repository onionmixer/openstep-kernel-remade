/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16bad0. */
__int32 zone_reclaim()
{
  do /*0x16baed*/
  {
    while ( zget_space_lock ) /*0x16badb*/
      ; /*0x16bad9*/
  }
  while ( _InterlockedExchange(&zget_space_lock, 1) == 1 ); /*0x16baed*/
  return zone_free_space_reclaim(); /*0x16baf6*/
}
