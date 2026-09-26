/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ae7e0. */
char __cdecl +[SCSIGeneric probe:](id a1, SEL a2, id a3)
{
  id v3; // esi
  int i; // ebx
  id v6; // eax

  v3 = objc_msgSend(a3, sel_directDevice); /*0x1ae7f9*/
  if ( objc_msgSend(v3, sel_unit) ) /*0x1ae803*/
    return 0; /*0x1ae80f*/
  for ( i = 0; i <= 3; ++i ) /*0x1ae814*/
  {
    v6 = objc_msgSend(a1, sel_alloc); /*0x1ae820*/
    sgIdMap[i] = (int)v6; /*0x1ae825*/
    objc_msgSend(v6, sel_sgInit_controller_, i, v3); /*0x1ae836*/
  }
  return 1; /*0x1ae84c*/
}
