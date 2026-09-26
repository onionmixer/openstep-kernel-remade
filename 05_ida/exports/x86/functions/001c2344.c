/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c2344. */
char *__cdecl -[IOPCMCIATuple data](IOPCMCIATuple *self, SEL a2)
{
  void *v2; // ebx
  int v3; // eax
  id v4; // eax
  void *v6; // [esp-Ch] [ebp-10h]
  size_t v7; // [esp-8h] [ebp-Ch]

  v2 = self->_private; /*0x1c234b*/
  if ( !*((_DWORD *)v2 + 3) ) /*0x1c234e*/
  {
    v3 = IOMalloc(*((_DWORD *)v2 + 2)); /*0x1c2358*/
    *((_DWORD *)v2 + 3) = v3; /*0x1c235d*/
    v7 = *((_DWORD *)v2 + 2); /*0x1c2363*/
    v6 = (void *)v3; /*0x1c2364*/
    v4 = objc_msgSend(*(id *)v2, sel_data); /*0x1c236f*/
    bcopy(v4, v6, v7); /*0x1c2378*/
  }
  return *((char **)v2 + 3); /*0x1c2380*/
}
