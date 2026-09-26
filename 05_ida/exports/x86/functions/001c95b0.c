/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c95b0. */
id __cdecl +[List newCount:](id a1, SEL a2, unsigned int a3)
{
  int v3; // eax
  id v4; // eax
  SEL v6; // [esp-8h] [ebp-Ch]

  v3 = NXDefaultMallocZone(sel_initCount_, a3); /*0x1c95c2*/
  v4 = objc_msgSend(a1, sel_allocFromZone_, v3); /*0x1c95d0*/
  return objc_msgSend(v4, v6); /*0x1c95de*/
}
