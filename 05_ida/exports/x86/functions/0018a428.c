/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18a428. */
void sub_18A428()
{
  int v0; // ecx
  int *v1; // eax
  char v3; // bl

  v0 = dword_1E75F8; /*0x18a42c*/
  if ( dword_1E75F8 ) /*0x18a434*/
  {
    v1 = *(int **)(*(_DWORD *)(dword_1E75F8 + 40) + 236); /*0x18a439*/
    _EDX = 0; /*0x18a43f*/
    if ( v1 ) /*0x18a443*/
      _EDX = *v1; /*0x18a445*/
    if ( _EDX && (v3 = *(_BYTE *)(_EDX + 1304), (v3 & 1) != 0) ) /*0x18a454*/
    {
      if ( (cpu_config & 3) == 2 ) /*0x18a460*/
      {
        __asm /*0x18a462*/
        {
          clts
          fnsave byte ptr [edx+4ACh]
        }
      }
      *(_BYTE *)(_EDX + 1304) = v3 | 2; /*0x18a46e*/
    }
    else
    {
      if ( (cpu_config & 3) == 2 ) /*0x18a482*/
      {
        _EAX = *(_DWORD *)(dword_1E75F8 + 40) + 124; /*0x18a487*/
        __asm /*0x18a48a*/
        {
          clts
          fnsave byte ptr [eax]
        }
      }
      *(_BYTE *)(*(_DWORD *)(v0 + 40) + 240) |= 2u; /*0x18a492*/
    }
    sub_18A7E4(); /*0x18a499*/
  }
}
