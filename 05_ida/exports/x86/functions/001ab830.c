/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ab830. */
$D91DDCA3822F03E96939068EA8DE741A *__cdecl -[IOTokenRing nodeAddress](
        $D91DDCA3822F03E96939068EA8DE741A *__return_ptr retstr,
        IOTokenRing *self,
        SEL a3)
{
  int v3; // ebx

  *(_DWORD *)v3 = *(_DWORD *)&retstr[52].var0[4]; /*0x1ab83d*/
  *(_WORD *)(v3 + 4) = *(_WORD *)&retstr[53].var0[2]; /*0x1ab846*/
  return ($D91DDCA3822F03E96939068EA8DE741A *)v3; /*0x1ab84c*/
}
