/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a4248. */
void __cdecl -[IODevice unregisterDevice](IODevice *self, SEL a2)
{
  int *v2; // ebx
  int *v3; // ecx
  int *v4; // eax
  int *v5; // edx
  int *v6; // edx

  objc_msgSend(dword_1E8674, sel_lock); /*0x1a425f*/
  v2 = sub_1A3E08((int)self); /*0x1a426a*/
  if ( v2 )
  {
    IOLog("Unregistering Device: %s\n");
    v3 = (int *)v2[2]; /*0x1a4284*/
    v4 = (int *)v2[3]; /*0x1a4287*/
    v5 = &dword_1E866C; /*0x1a428a*/
    if ( v3 != &dword_1E866C ) /*0x1a4295*/
      v5 = v3 + 2; /*0x1a4297*/
    v5[1] = (int)v4; /*0x1a429a*/
    v6 = &dword_1E866C; /*0x1a429d*/
    if ( v4 != &dword_1E866C ) /*0x1a42a7*/
      v6 = v4 + 2; /*0x1a42a9*/
    *v6 = (int)v3; /*0x1a42ac*/
    IOFree((int)v2, 16); /*0x1a42b1*/
  }
  objc_msgSend(dword_1E8674, sel_unlock); /*0x1a42c7*/
}
