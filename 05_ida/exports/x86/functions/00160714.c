/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x160714. */
int sched_usec_elapsed()
{
  unsigned __int64 v1; // rtt
  __int64 v2; // [esp+Ch] [ebp-14h]

  v2 = clock_value(1); /*0x160724*/
  if ( !qword_1E5E44 ) /*0x160731*/
    qword_1E5E44 = v2; /*0x16073f*/
  LODWORD(v1) = v2 - qword_1E5E44; /*0x160775*/
  HIDWORD(v1) = ((unsigned __int64)(v2 - qword_1E5E44) >> 32) % 0x3E8; /*0x160775*/
  qword_1E5E44 = v2; /*0x160782*/
  return v1 / 0x3E8; /*0x16078e*/
}
