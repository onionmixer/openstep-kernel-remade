/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c96fc. */
char __cdecl -[List isEqual:](List *self, SEL a2, id a3)
{
  id v3; // eax
  char result; // al
  unsigned int numElements; // edx

  v3 = -[Object class](self, sel_class); /*0x1c9710*/
  if ( !(unsigned __int8)objc_msgSend(a3, sel_isKindOf_, v3) ) /*0x1c971e*/
    return 0; /*0x1c9727*/
  result = 0; /*0x1c972c*/
  numElements = self->numElements; /*0x1c972e*/
  if ( *((_DWORD *)a3 + 2) == numElements ) /*0x1c9734*/
    return memcmp(self->dataPtr, *((const void **)a3 + 1), 4 * numElements) == 0; /*0x1c974a*/
  return result; /*0x1c9752*/
}
