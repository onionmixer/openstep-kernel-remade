/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x19621c. */
char __cdecl +[kmDevice probe:](id a1, SEL a2, id a3)
{
  id v3; // ebx
  int v4; // edx

  if ( !kmId || dword_1E7764 ) /*0x196230*/
    v3 = objc_msgSend(a1, sel_new); /*0x196248*/
  else
    v3 = kmId; /*0x196232*/
  v4 = 1; /*0x196252*/
  if ( MEMORY[0x1114C] ) /*0x196259*/
    v4 = 2; /*0x19625b*/
  if ( objc_msgSend(v3, sel_init_fb_mode_, 1, v4) ) /*0x19626b*/
    return 1; /*0x19629c*/
  IOLog(aKmdeviceContin); /*0x19627c*/
  objc_msgSend(v3, sel_free); /*0x196289*/
  kmId = nullptr; /*0x19628e*/
  return 0; /*0x1962a1*/
}
