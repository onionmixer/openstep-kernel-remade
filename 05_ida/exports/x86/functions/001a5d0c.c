/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a5d0c. */
const char *__cdecl -[IODisk stringFromReturn:](IODisk *self, SEL a2, int a3)
{
  char *v3; // eax
  objc_super v5; // [esp+0h] [ebp-8h] BYREF

  v3 = (char *)&unk_1E50C4; /*0x1a5d15*/
  if ( off_1E50C8 ) /*0x1a5d21*/
  {
    while ( *(_DWORD *)v3 != a3 ) /*0x1a5d26*/
    {
      v3 += 8; /*0x1a5d28*/
      if ( !*((_DWORD *)v3 + 1) ) /*0x1a5d2b*/
        goto LABEL_4; /*0x1a5d2f*/
    }
    return *((const char **)v3 + 1); /*0x1a5d58*/
  }
  else
  {
LABEL_4:
    v5.receiver = self; /*0x1a5d31*/
    v5.super_class = (Class)stru_1FA104.super_class; /*0x1a5d45*/
    return -[IODevice stringFromReturn:](&v5, sel_stringFromReturn_, a3); /*0x1a5d4c*/
  }
}
