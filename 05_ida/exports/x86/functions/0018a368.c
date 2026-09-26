/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18a368. */
int fp_noextension()
{
  if ( (cpu_config & 3) == 0 ) /*0x18a372*/
    exception(4, (exception_data_t)7, 0); /*0x18a37a*/
  return sub_18A4A8(); /*0x18a389*/
}
